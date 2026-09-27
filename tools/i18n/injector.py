# -*- coding: utf-8 -*-
"""GBA line-wrapping and source-code injector for the Heart & Soul Chinese patch.

This module is the write-back half of the translation pipeline.  It takes the
corpus produced by ``extractor`` / ``aligner`` / ``ai_translator`` and emits
pokeemerald-compatible text into the real source files.

Three responsibilities:

``wrap_chinese``
    GBA dialogue boxes fit ~16 full-width CJK glyphs per line, far fewer than
    the ~35 ASCII characters English was authored for.  A translation is
    re-flowed into the game's control-code layout: ``\\n`` after the first line
    of a paragraph, ``\\l`` after every subsequent non-final line, and ``\\p`` /
    ``$`` terminating the paragraph.  Paragraphs that contain no CJK at all are
    returned byte-identical -- English keeps its authored layout.

``inject_into_file``
    Replaces the ``.string "..."`` block belonging to a label (``.inc``) or the
    literal inside ``_("...")`` for an array (``.h``/``.c``), touching nothing
    else.  Idempotent: re-running on already-injected content is a no-op.

``build_plan`` / ``main``
    Selects which corpus entries may be injected and reports the rest.

Injection filter (MANDATORY)
----------------------------
``translated_corpus.json`` contains thousands of ``match_type == "dictionary"``
entries.  Those are **not** translations: they are the English sentence with
Chinese terms spliced in, e.g. ``"...always bring our 宝可梦.\\lHow about a
quick battle?$"``.  Injecting them would leave the ROM mixed-language, which is
strictly worse than leaving it English, so they are excluded here and the
exclusion is reported by ``--dry-run``.  Only genuine, complete translations
(``match_type`` of ``"exact"`` or ``"term"``) are ever written back.

Global rules honoured throughout: UTF-8 in and out, control codes and ``{...}``
placeholders are never corrupted, no 32-bit assumptions, and every operation is
deterministic so the injector can be re-run safely.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import sys
from collections import Counter
from dataclasses import dataclass, field
from typing import Dict, Iterable, List, Optional, Sequence, Tuple

# --------------------------------------------------------------------------
# Constants
# --------------------------------------------------------------------------

#: Full-width CJK glyphs that fit on one GBA dialogue line.
DEFAULT_MAX_CHARS = 16

#: Layout control codes.  ``\n`` and ``\l`` are pure layout and may be
#: re-flowed; ``\p`` is a page break and carries meaning; ``$`` terminates.
NEWLINE = "\\n"
SCROLL = "\\l"
PAGE_BREAK = "\\p"
TERMINATOR = "$"

#: ``match_type`` values that represent a genuine, complete translation of the
#: whole string.  ``"dictionary"`` is deliberately absent -- see the module
#: docstring.  A ``"term"`` entry only exists when the term covers the entire
#: string (e.g. ``"CANCEL$"`` -> ``"取消$"``).
INJECTABLE_MATCH_TYPES: Tuple[str, ...] = ("exact", "term")

_HERE = os.path.dirname(os.path.abspath(__file__))
_DATA_DIR = os.path.join(_HERE, "data")
ALIGNED_CORPUS_PATH = os.path.join(_DATA_DIR, "aligned_corpus.json")
TRANSLATED_CORPUS_PATH = os.path.join(_DATA_DIR, "translated_corpus.json")

#: Codepoint ranges treated as full-width CJK for wrapping purposes.  Latin-1
#: accents (``é`` in ``POKéMON``) are deliberately excluded so that English
#: text is never re-flowed.
CJK_RANGES: Tuple[Tuple[int, int], ...] = (
    (0x2E80, 0x2EFF),    # CJK Radicals Supplement
    (0x3000, 0x303F),    # CJK Symbols and Punctuation
    (0x3040, 0x30FF),    # Hiragana / Katakana
    (0x3100, 0x312F),    # Bopomofo
    (0x3190, 0x319F),
    (0x31C0, 0x31EF),
    (0x3200, 0x32FF),    # Enclosed CJK Letters and Months
    (0x3300, 0x33FF),    # CJK Compatibility
    (0x3400, 0x4DBF),    # CJK Unified Ideographs Extension A
    (0x4E00, 0x9FFF),    # CJK Unified Ideographs
    (0xF900, 0xFAFF),    # CJK Compatibility Ideographs
    (0xFE30, 0xFE4F),    # CJK Compatibility Forms
    (0xFF00, 0xFFEF),    # Halfwidth and Fullwidth Forms
    (0x20000, 0x3FFFF),  # CJK Unified Ideographs Extension B and beyond
)

# --------------------------------------------------------------------------
# Source-file patterns (kept byte-compatible with tools/i18n/extractor.py)
# --------------------------------------------------------------------------

_INC_LABEL_RE = re.compile(r"^([A-Za-z0-9_]+)::")
_INC_SINGLE_LABEL_RE = re.compile(r"^([A-Za-z0-9_]+):")
_INC_STRING_RE = re.compile(r'^\s*\.string\s+"(.*)"\s*$')
_INC_INDENT_RE = re.compile(r"^([ \t]*)")

_C_ARRAY_RE = re.compile(
    r'(?:static\s+)?(?:const\s+)?(?:u8|char)\s+([A-Za-z0-9_]+)\s*\[\]\s*=\s*_\(\s*"([^"]*)"\s*\);'
)


# --------------------------------------------------------------------------
# CJK detection
# --------------------------------------------------------------------------


def is_cjk_char(ch: str) -> bool:
    """True when ``ch`` is a full-width CJK glyph (ideograph, kana, punct...)."""
    code = ord(ch)
    for low, high in CJK_RANGES:
        if low <= code <= high:
            return True
    return False


def has_cjk(text: str) -> bool:
    """True when ``text`` contains at least one CJK character."""
    return any(is_cjk_char(ch) for ch in text)


# --------------------------------------------------------------------------
# 1. Chinese line wrapping
# --------------------------------------------------------------------------


def split_paragraphs(text: str) -> List[str]:
    """Split ``text`` on ``\\p``.  Page breaks are never merged or re-flowed."""
    return text.split(PAGE_BREAK)


def _tokenize(text: str) -> List[str]:
    """Split visible text into indivisible emission units.

    ``{...}`` control macros and any ``\\x`` escape are single units so they can
    never be torn across a line boundary.  ``\\n`` and ``\\l`` are layout only
    and are dropped here -- the wrapper re-emits them.  Every other character
    (including a CJK ideograph) is one unit.
    """
    tokens: List[str] = []
    i = 0
    n = len(text)
    while i < n:
        ch = text[i]
        if ch == "{":
            close = text.find("}", i)
            if close == -1:
                tokens.append(text[i:])
                break
            tokens.append(text[i:close + 1])
            i = close + 1
        elif ch == "\\" and i + 1 < n:
            if text[i + 1] in "nl":
                i += 2  # layout code: discarded, re-emitted by the wrapper
            else:
                tokens.append(text[i:i + 2])
                i += 2
        else:
            tokens.append(ch)
            i += 1
    return tokens


def _wrap_paragraph(paragraph: str, max_chars: int) -> str:
    """Re-flow one paragraph, or return it untouched when it is not Chinese."""
    if not has_cjk(paragraph):
        # English (or any non-CJK) text keeps its authored layout byte for byte.
        return paragraph

    lines: List[str] = []
    current: List[str] = []
    width = 0
    for token in _tokenize(paragraph):
        token_width = len(token)
        if current and width + token_width > max_chars:
            lines.append("".join(current))
            current = []
            width = 0
        current.append(token)
        width += token_width
    if current or not lines:
        lines.append("".join(current))

    out: List[str] = []
    for index, line in enumerate(lines):
        out.append(line)
        if index < len(lines) - 1:
            # First line ends with a newline; every later break scrolls.
            out.append(NEWLINE if index == 0 else SCROLL)
    return "".join(out)


def wrap_chinese(text: str, max_chars: int = DEFAULT_MAX_CHARS) -> str:
    """Re-flow a translation's line breaks to fit ``max_chars`` CJK chars per line.

    Paragraphs are split on ``\\p`` and re-wrapped independently: the first line
    is followed by ``\\n``, every subsequent non-final line by ``\\l``, and the
    final line of the paragraph by ``\\p`` (or ``$`` when the source ended with
    a terminator).  Control codes and ``{...}`` placeholders are emitted intact
    and never split across a boundary.  A paragraph with no CJK characters at
    all is returned unchanged, so English text is never re-flowed.

    The function is idempotent: wrapping an already-wrapped string yields the
    same string.
    """
    if max_chars <= 0:
        raise ValueError("max_chars must be positive, got %r" % (max_chars,))

    terminated = text.endswith(TERMINATOR)
    body = text[:-1] if terminated else text

    wrapped = [ _wrap_paragraph(paragraph, max_chars) for paragraph in split_paragraphs(body) ]
    result = PAGE_BREAK.join(wrapped)
    return result + TERMINATOR if terminated else result


# --------------------------------------------------------------------------
# Emission of .string / _("...") text
# --------------------------------------------------------------------------


def split_chunks(text: str) -> List[str]:
    """Split text into one chunk per control-code-terminated run.

    Each returned chunk ends with ``\\n``, ``\\l``, ``\\p`` or ``$`` (the last
    chunk may be unterminated if the source was).  Re-joining the chunks
    reproduces ``text`` exactly.
    """
    chunks: List[str] = []
    buf: List[str] = []
    i = 0
    n = len(text)
    while i < n:
        ch = text[i]
        if ch == "\\" and i + 1 < n:
            buf.append(text[i:i + 2])
            code = text[i + 1]
            i += 2
            if code in "nlp":
                chunks.append("".join(buf))
                buf = []
        elif ch == TERMINATOR:
            buf.append(ch)
            i += 1
            chunks.append("".join(buf))
            buf = []
        else:
            buf.append(ch)
            i += 1

    if buf:
        if chunks:
            chunks[-1] += "".join(buf)
        else:
            chunks.append("".join(buf))
    if not chunks:
        chunks = [""]
    return chunks


def emit_string_lines(text: str, indent: str = "\t") -> List[str]:
    """Render ``text`` as pokeemerald ``.string`` lines, one per code chunk."""
    if '"' in text or "\n" in text or "\r" in text:
        # The assembler would break on these; the corpus contains none.  Fail
        # loudly rather than writing corrupt source.
        raise ValueError("refusing to emit text containing a quote or raw newline: %r" % (text,))
    return ['%s.string "%s"' % (indent, chunk) for chunk in split_chunks(text)]


# --------------------------------------------------------------------------
# 3. Injection filter (MANDATORY)
# --------------------------------------------------------------------------


def is_injectable(entry: dict) -> bool:
    """True only for entries carrying a genuine, complete translation.

    ``match_type == "dictionary"`` entries are scaffold -- English with Chinese
    terms spliced in -- and must never reach the ROM.
    """
    if not isinstance(entry, dict):
        return False
    translation = entry.get("translation")
    if not translation or not isinstance(translation, str):
        return False
    return entry.get("match_type") in INJECTABLE_MATCH_TYPES


def filter_entries(entries: Iterable[dict]) -> List[dict]:
    """Keep only the entries safe to inject."""
    return [entry for entry in entries if is_injectable(entry)]


def load_corpus(path: str) -> List[dict]:
    """Load a corpus JSON file as a list of entry dicts."""
    with open(path, "r", encoding="utf-8") as handle:
        data = json.load(handle)
    if not isinstance(data, list):
        raise ValueError("corpus %s is not a JSON list" % (path,))
    return data


@dataclass
class InjectionPlan:
    """Which entries may be injected, grouped by target file."""

    by_file: Dict[str, List[dict]] = field(default_factory=dict)
    total: int = 0
    injectable: int = 0
    dropped_dictionary: int = 0
    dropped_untranslated: int = 0
    dropped_other: int = 0
    match_type_counts: Counter = field(default_factory=Counter)

    @property
    def dropped(self) -> int:
        return self.dropped_dictionary + self.dropped_untranslated + self.dropped_other


def build_plan(*corpora: Sequence[dict]) -> InjectionPlan:
    """Apply the injection filter and group the survivors by target file."""
    plan = InjectionPlan()
    for corpus in corpora:
        for entry in corpus:
            plan.total += 1
            match_type = entry.get("match_type")
            translation = entry.get("translation")
            if not translation:
                plan.dropped_untranslated += 1
            elif match_type == "dictionary":
                plan.dropped_dictionary += 1
            elif match_type in INJECTABLE_MATCH_TYPES:
                plan.injectable += 1
                plan.match_type_counts[match_type] += 1
                plan.by_file.setdefault(entry["file"], []).append(entry)
            else:
                plan.dropped_other += 1
    return plan


# --------------------------------------------------------------------------
# 2. Code injection
# --------------------------------------------------------------------------


@dataclass
class InjectionResult:
    """Outcome of injecting into a single file."""

    path: str
    changed: bool
    applied: int
    skipped: int
    before: str
    after: str


@dataclass
class _IncBlock:
    label: str
    index: int
    start: int
    end: int
    text: str


def _is_meaningful_string(text: str) -> bool:
    """Mirror of ``extractor.is_meaningful_string`` so block indices line up."""
    cleaned = text.replace(TERMINATOR, "").strip()
    if not cleaned:
        return False
    return any(ch.isalnum() for ch in cleaned)


def _parse_inc_blocks(lines: Sequence[str]) -> List[_IncBlock]:
    """Locate every ``.string`` group in an ``.inc`` file, indexed like the extractor."""
    blocks: List[_IncBlock] = []
    label: Optional[str] = None
    index = 0
    i = 0
    n = len(lines)
    while i < n:
        line = lines[i]
        label_match = _INC_LABEL_RE.match(line) or _INC_SINGLE_LABEL_RE.match(line)
        if label_match:
            label = label_match.group(1)
            index = 0
            i += 1
            continue

        string_match = _INC_STRING_RE.match(line)
        if string_match and label is not None:
            start = i
            parts: List[str] = []
            while i < n:
                inner = _INC_STRING_RE.match(lines[i])
                if not inner:
                    break
                parts.append(inner.group(1))
                i += 1
                if "".join(parts).endswith(TERMINATOR):
                    break
            text = "".join(parts)
            if _is_meaningful_string(text):
                blocks.append(_IncBlock(label, index, start, i, text))
                index += 1
            continue

        i += 1

    return blocks


def _detect_eol(content: str) -> str:
    """Return the carriage-return prefix the file uses, or "" for plain LF.

    Emitted lines are joined with "\\n", so a CRLF file needs a "\\r" appended
    to each new line or the result would mix line endings.
    """
    index = content.find("\n")
    if index > 0 and content[index - 1] == "\r":
        return "\r"
    return ""


def _inject_inc(content: str, updates: Sequence[dict]) -> Tuple[str, int, int]:
    lines = content.split("\n")
    blocks = _parse_inc_blocks(lines)
    eol = _detect_eol(content)

    wanted: Dict[Tuple[str, int], dict] = {}
    for update in updates:
        wanted[(update.get("label"), update.get("index"))] = update

    applied = 0
    for block in reversed(blocks):
        update = wanted.get((block.label, block.index))
        if update is None:
            continue
        text = wrap_chinese(update["translation"])
        indent_match = _INC_INDENT_RE.match(lines[block.start])
        indent = indent_match.group(1) if indent_match else "\t"
        emitted = [line + eol for line in emit_string_lines(text, indent or "\t")]
        lines[block.start:block.end] = emitted
        applied += 1

    return "\n".join(lines), applied, len(updates) - applied


def _inject_c(content: str, updates: Sequence[dict]) -> Tuple[str, int, int]:
    by_label: Dict[str, List[Tuple[int, re.Match]]] = {}
    for position, match in enumerate(_C_ARRAY_RE.finditer(content)):
        by_label.setdefault(match.group(1), []).append((position, match))

    edits: List[Tuple[int, int, str]] = []
    applied = 0
    for update in updates:
        candidates = by_label.get(update.get("label"))
        if not candidates:
            continue
        target = None
        for position, match in candidates:
            if position == update.get("index"):
                target = match
                break
        if target is None:
            target = candidates[0][1]
        edits.append((target.start(2), target.end(2), wrap_chinese(update["translation"])))
        applied += 1

    for start, end, replacement in sorted(edits, key=lambda item: item[0], reverse=True):
        content = content[:start] + replacement + content[end:]

    return content, applied, len(updates) - applied


def inject_into_file(
    path: str,
    updates: Sequence[dict],
    dry_run: bool = False,
) -> InjectionResult:
    """Write ``updates`` into ``path``, returning what changed.

    ``updates`` are corpus entries; only ``label``, ``index`` and ``translation``
    are used.  ``.inc`` files get their ``.string`` block rewritten; ``.h`` and
    ``.c`` files get the literal inside ``_("...")`` replaced.  Nothing outside
    the matched block is touched.  With ``dry_run`` the file is left alone and
    the prospective content is returned on the result.
    """
    with open(path, "r", encoding="utf-8", newline="") as handle:
        content = handle.read()

    extension = os.path.splitext(path)[1].lower()
    if extension == ".inc":
        updated, applied, skipped = _inject_inc(content, updates)
    elif extension in (".h", ".c"):
        updated, applied, skipped = _inject_c(content, updates)
    else:
        raise ValueError("unsupported file type for injection: %s" % (path,))

    changed = updated != content
    if changed and not dry_run:
        with open(path, "w", encoding="utf-8", newline="") as handle:
            handle.write(updated)

    return InjectionResult(
        path=path,
        changed=changed,
        applied=applied,
        skipped=skipped,
        before=content,
        after=updated,
    )


# --------------------------------------------------------------------------
# 4. CLI
# --------------------------------------------------------------------------


def _resolve(root: str, path: str) -> str:
    return os.path.normpath(os.path.join(root, path))


def _print_report(plan: InjectionPlan, results: Sequence[InjectionResult], dry_run: bool) -> None:
    print("Corpus entries: %d" % (plan.total,))
    breakdown = ", ".join("%s=%d" % (k, v) for k, v in sorted(plan.match_type_counts.items()))
    print("Injectable: %d%s" % (plan.injectable, " (%s)" % breakdown if breakdown else ""))
    print(
        "Filtered out: %d (dictionary=%d, untranslated=%d, other=%d)"
        % (
            plan.dropped,
            plan.dropped_dictionary,
            plan.dropped_untranslated,
            plan.dropped_other,
        )
    )
    if plan.dropped_dictionary:
        print(
            "  dictionary entries are English-with-Chinese-terms scaffold, not "
            "translations: excluded to avoid mixed-language ROM text."
        )

    changed = [result for result in results if result.changed]
    print(
        "%s: %d of %d"
        % ("Files that would change" if dry_run else "Files changed", len(changed), len(results))
    )
    for result in sorted(changed, key=lambda item: item.path):
        print(
            "  %s  %d string(s), %d line(s) differ"
            % (
                result.path.replace(os.sep, "/"),
                result.applied,
                sum(
                    1
                    for a, b in zip(result.before.split("\n"), result.after.split("\n"))
                    if a != b
                ),
            )
        )

    if dry_run:
        print("Dry run: no files written.")
    else:
        print("Wrote %d file(s)." % (len(changed),))


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(
        description="Inject Chinese translations into pokeemerald source files."
    )
    parser.add_argument("--aligned", default=ALIGNED_CORPUS_PATH,
                        help="aligned corpus JSON (exact/term matches).")
    parser.add_argument("--translated", default=TRANSLATED_CORPUS_PATH,
                        help="translated corpus JSON (dictionary scaffold is excluded).")
    parser.add_argument("--root", default=".", help="repository root the corpus paths are relative to.")
    parser.add_argument("--dry-run", action="store_true",
                        help="report the diff summary without writing any file.")
    args = parser.parse_args(argv)

    aligned = load_corpus(args.aligned)
    translated = load_corpus(args.translated)
    plan = build_plan(aligned, translated)

    results: List[InjectionResult] = []
    for corpus_path, entries in sorted(plan.by_file.items()):
        resolved = _resolve(args.root, corpus_path)
        if not os.path.exists(resolved):
            print("warning: missing target file, skipped: %s" % (resolved,), file=sys.stderr)
            continue
        results.append(inject_into_file(resolved, entries, dry_run=args.dry_run))

    _print_report(plan, results, args.dry_run)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
