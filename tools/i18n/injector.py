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

The write-back contract (MANDATORY)
-----------------------------------
A translation reaches ``data/`` only after every one of these holds; anything
else is *skipped and reported*, never guessed:

1. the entry carries a string ``source`` and a non-empty ``translation``;
2. :func:`tools.i18n.ai_translator.validate_translation` accepts the pair, so a
   hand-edited corpus entry with a dropped ``\\p``, a missing ``$`` or a lost
   ``{PLAYER}`` cannot be written (the same guard that produced the corpus runs
   again at the last moment before disk);
3. the ``(label, index)`` pair resolves to **exactly one** block -- two blocks
   with the same label on either side of an ``#if``/``#else`` are ambiguous and
   must not both receive the same text;
4. the block currently holds either the entry's ``source`` (fresh injection) or
   exactly the text this run would write (a re-run: idempotence);
5. the block neither spans nor abuts a ``#if``/``#ifdef``/``#ifndef``/
   ``#elif``/``#else``/``#endif`` line.  The extractor concatenates across those
   directives while this module's parser stops at them, so the two disagree
   about block boundaries; where they can disagree, nothing is written.

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

# Running this file as a script (``python tools/i18n/injector.py``) puts
# ``tools/i18n`` -- not the repository root -- on ``sys.path``, which would hide
# the ``tools.i18n`` package.  Put the repository root back before importing the
# sibling module, so both ``python -m ...`` and script mode import the *same*
# module object.
_REPO_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
if _REPO_ROOT not in sys.path:
    sys.path.insert(0, _REPO_ROOT)

from tools.i18n.ai_translator import (  # noqa: E402  (import after sys.path bootstrap)
    TranslationFormatError,
    validate_translation,
)
from tools.i18n.aligner import (  # noqa: E402  (import after sys.path bootstrap)
    validate_control_codes_preserved,
)

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

#: Preprocessor conditionals.  ``.string`` blocks wrapped in these cannot be
#: injected: the extractor concatenates across the directives (see
#: ``extract_strings_from_inc``) while :func:`_parse_inc_blocks` stops at them,
#: so ``(label, index)`` means different things to the two modules.
_PREPROC_RE = re.compile(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b")
_PREPROC_OPENERS = ("if", "ifdef", "ifndef")

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

    # ``rstrip()`` before the test, matching every other module in the pipeline
    # (``aligner.repair_terminator``, ``ai_translator._is_terminated``): a
    # terminator with dead whitespace behind it still terminates.  The trailing
    # whitespace is then dropped -- bytes after ``$`` are never rendered.
    stripped = text.rstrip()
    terminated = stripped.endswith(TERMINATOR)
    body = stripped[:-1] if terminated else text

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
    trailing_backslashes = len(text) - len(text.rstrip("\\"))
    if trailing_backslashes % 2:
        # A lone trailing ``\`` escapes the closing quote of the emitted
        # literal: ``.string "hello\"`` swallows the rest of the file.  An even
        # run escapes itself and is safe.
        raise ValueError(
            "refusing to emit text ending in an unescaped backslash: %r" % (text,)
        )
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
                target = entry.get("file")
                if not isinstance(target, str) or not target:
                    # A hand-edited corpus can lose the key; the plan must
                    # report it rather than die with KeyError.
                    plan.dropped_other += 1
                    continue
                plan.injectable += 1
                plan.match_type_counts[match_type] += 1
                plan.by_file.setdefault(target, []).append(entry)
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
    #: Line index of the label that owns the block (-1 when unknown).
    label_line: int = -1
    #: True when the block spans or abuts a preprocessor conditional.
    guarded: bool = False


def _is_meaningful_string(text: str) -> bool:
    """Mirror of ``extractor.is_meaningful_string`` so block indices line up."""
    cleaned = text.replace(TERMINATOR, "").strip()
    if not cleaned:
        return False
    return any(ch.isalnum() for ch in cleaned)


def _preprocessor_guarded_lines(lines: Sequence[str]) -> List[bool]:
    """Mark every line inside, or made of, a preprocessor conditional.

    The ``#if``/``#else``/``#endif`` lines themselves are marked, as is every
    line between a directive and its ``#endif``.  An unbalanced ``#else`` or
    ``#elif`` is treated as opening a region: on malformed input the answer must
    be "do not touch", never "probably fine".
    """
    guarded = [False] * len(lines)
    depth = 0
    for index, line in enumerate(lines):
        match = _PREPROC_RE.match(line)
        if match:
            guarded[index] = True
            kind = match.group(1)
            if kind in _PREPROC_OPENERS:
                depth += 1
            elif kind == "endif":
                if depth:
                    depth -= 1
            elif depth == 0:
                # ``#else`` / ``#elif`` without a matching ``#if``: malformed.
                depth = 1
            continue
        if depth:
            guarded[index] = True
    return guarded


def _is_guarded_block(guarded: Sequence[bool], label_line: int, start: int, end: int) -> bool:
    """True when ``[label_line - 1, end]`` touches a preprocessor conditional.

    ``end`` is the first line *after* the block, so the window covers the line
    before the label (a directive directly above it), the lines of the block
    itself, and the line directly after it -- "spans or abuts".
    """
    low = max(0, label_line - 1)
    high = min(len(guarded) - 1, end)
    if high < low:
        return False
    return any(guarded[index] for index in range(low, high + 1))


def _parse_inc_blocks(lines: Sequence[str]) -> List[_IncBlock]:
    """Locate every ``.string`` group in an ``.inc`` file, indexed like the extractor."""
    blocks: List[_IncBlock] = []
    guarded_lines = _preprocessor_guarded_lines(lines)
    label: Optional[str] = None
    label_line = -1
    index = 0
    i = 0
    n = len(lines)
    while i < n:
        line = lines[i]
        label_match = _INC_LABEL_RE.match(line) or _INC_SINGLE_LABEL_RE.match(line)
        if label_match:
            label = label_match.group(1)
            label_line = i
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
                blocks.append(
                    _IncBlock(
                        label,
                        index,
                        start,
                        i,
                        text,
                        label_line,
                        _is_guarded_block(guarded_lines, label_line, start, i),
                    )
                )
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


def _dedupe_updates(updates: Sequence[dict]) -> List[dict]:
    """One update per ``(label, index)``, later entries winning (as before)."""
    wanted: Dict[Tuple[object, object], dict] = {}
    for update in updates:
        wanted[(update.get("label"), update.get("index"))] = update
    return list(wanted.values())


def _report_skip(path: str, update: dict, reason: str) -> None:
    """Announce a skipped update on stderr, naming the entry and the reason."""
    location = "%s:%s:%s" % (path or "<file>", update.get("label"), update.get("index"))
    print("warning: skipped %s: %s" % (location, reason), file=sys.stderr)


#: ``\n`` and ``\l`` only.  ``wrap_chinese`` discards the authored layout and
#: re-emits its own breaks, so their *count* can never be compared between a
#: corpus entry and its source; everything the guard checks besides them --
#: ``{...}`` placeholders, ``\p`` page breaks, the ``$`` terminator -- survives
#: the re-flow and is verified here before anything reaches disk.
_LAYOUT_CODE_RE = re.compile(r"\\[nl]")


def _without_layout_codes(text: str) -> str:
    """Remove ``\\n`` / ``\\l`` so the guard compares only what the wrap keeps."""
    return _LAYOUT_CODE_RE.sub("", text)


def _guarded_translation(path: str, update: dict) -> Optional[str]:
    """Return the translation to write, or ``None`` if the entry must be skipped.

    This is the write-back boundary: the last point before ``wrap_chinese`` and
    ``emit_string_lines`` turn an entry into source code.  Everything the corpus
    claims is re-checked here, because the corpus is hand-editable data and a
    dropped ``\\p`` or a missing ``$`` would corrupt every string after it.
    """
    translation = update.get("translation")
    source = update.get("source")
    if not isinstance(translation, str) or not translation:
        _report_skip(path, update, "entry carries no translation")
        return None
    if not isinstance(source, str) or not source:
        # Without the source there is nothing to verify the block against.
        _report_skip(path, update, "entry carries no source string to verify against")
        return None
    try:
        validate_translation(_without_layout_codes(source), _without_layout_codes(translation))
    except TranslationFormatError as exc:
        _report_skip(path, update, "format guard rejected the translation (%s)" % exc.code)
        return None
    return translation


def _wrapped_or_skip(path: str, update: dict, translation: str) -> Optional[str]:
    """Wrap a translation and verify the result, reporting a skip on refusal.

    Two layers, both at the boundary: :func:`wrap_chinese` must not raise (a
    raw newline, a quote or a trailing lone backslash would produce a broken
    ``.string`` line), and the wrapped text must still carry the source's
    placeholders, page breaks and terminator.
    """
    try:
        wrapped = wrap_chinese(translation)
    except ValueError as exc:
        _report_skip(path, update, "refusing to emit the translation (%s)" % exc)
        return None
    if not validate_control_codes_preserved(update.get("source"), wrapped):
        _report_skip(
            path, update,
            "wrapped text no longer preserves the source's placeholders/page breaks/terminator",
        )
        return None
    return wrapped


def _inject_inc(content: str, updates: Sequence[dict], path: str = "") -> Tuple[str, int, int]:
    lines = content.split("\n")
    blocks = _parse_inc_blocks(lines)
    eol = _detect_eol(content)
    unique = _dedupe_updates(updates)

    by_key: Dict[Tuple[str, int], List[_IncBlock]] = {}
    for block in blocks:
        by_key.setdefault((block.label, block.index), []).append(block)

    applied = 0
    pending: List[Tuple[_IncBlock, List[str]]] = []
    for update in unique:
        translation = _guarded_translation(path, update)
        if translation is None:
            continue

        matches = by_key.get((update.get("label"), update.get("index")), [])
        if any(block.guarded for block in matches):
            # Two blocks on either side of an #if, or a block the extractor and
            # this parser read differently: writing the same text to all of them
            # is how both branches used to collapse into one translation.
            _report_skip(
                path, update,
                "block spans or abuts a #if/#else/#endif preprocessor block",
            )
            continue
        if len(matches) != 1:
            _report_skip(
                path, update,
                "expected exactly one matching .string block, found %d" % (len(matches),),
            )
            continue
        block = matches[0]

        wrapped = _wrapped_or_skip(path, update, translation)
        if wrapped is None:
            continue
        if block.text != update.get("source") and block.text != wrapped:
            # Neither the untranslated source nor this very translation: some
            # other string lives here.  A silent overwrite would corrupt it.
            _report_skip(
                path, update,
                "block does not match the corpus source (found %r)" % (block.text[:60],),
            )
            continue

        indent_match = _INC_INDENT_RE.match(lines[block.start])
        indent = indent_match.group(1) if indent_match else "\t"
        try:
            emitted = [line + eol for line in emit_string_lines(wrapped, indent or "\t")]
        except ValueError as exc:
            _report_skip(path, update, "refusing to emit the translation (%s)" % exc)
            continue
        pending.append((block, emitted))
        applied += 1

    # Back to front, so replacing a block with a different number of lines
    # cannot shift the line indices of the blocks still to be written.
    for block, emitted in sorted(pending, key=lambda item: item[0].start, reverse=True):
        lines[block.start:block.end] = emitted

    return "\n".join(lines), applied, len(unique) - applied


def _inject_c(content: str, updates: Sequence[dict], path: str = "") -> Tuple[str, int, int]:
    by_label: Dict[str, List[Tuple[int, re.Match]]] = {}
    for position, match in enumerate(_C_ARRAY_RE.finditer(content)):
        by_label.setdefault(match.group(1), []).append((position, match))

    unique = _dedupe_updates(updates)
    edits: List[Tuple[int, int, str]] = []
    applied = 0
    for update in unique:
        translation = _guarded_translation(path, update)
        if translation is None:
            continue

        label = update.get("label")
        index = update.get("index")
        candidates = [match for position, match in by_label.get(label, []) if position == index]
        if len(candidates) != 1:
            # Falling back to the first array with this label would overwrite an
            # unrelated string and report success; the .inc path skips here too.
            _report_skip(
                path, update,
                'expected exactly one _("...") array at this index, found %d'
                % (len(candidates),),
            )
            continue
        match = candidates[0]

        wrapped = _wrapped_or_skip(path, update, translation)
        if wrapped is None:
            continue
        if match.group(2) != update.get("source") and match.group(2) != wrapped:
            _report_skip(
                path, update,
                'array literal does not match the corpus source (found %r)'
                % (match.group(2)[:60],),
            )
            continue

        edits.append((match.start(2), match.end(2), wrapped))
        applied += 1

    for start, end, replacement in sorted(edits, key=lambda item: item[0], reverse=True):
        content = content[:start] + replacement + content[end:]

    return content, applied, len(unique) - applied


def inject_into_file(
    path: str,
    updates: Sequence[dict],
    dry_run: bool = False,
) -> InjectionResult:
    """Write ``updates`` into ``path``, returning what changed.

    ``updates`` are corpus entries; ``label``, ``index``, ``source`` and
    ``translation`` are used.  ``.inc`` files get their ``.string`` block
    rewritten; ``.h`` and ``.c`` files get the literal inside ``_("...")``
    replaced.  Nothing outside the matched block is touched.

    Every update is verified before it is written (see the module docstring):
    an entry whose source, index or translation cannot be trusted is *skipped*
    and reported on stderr, so ``result.applied + result.skipped`` always
    equals the number of distinct ``(label, index)`` pairs.  With ``dry_run``
    the file is left alone and the prospective content is returned on the
    result.
    """
    with open(path, "r", encoding="utf-8", newline="") as handle:
        content = handle.read()

    extension = os.path.splitext(path)[1].lower()
    if extension == ".inc":
        updated, applied, skipped = _inject_inc(content, updates, path)
    elif extension in (".h", ".c"):
        updated, applied, skipped = _inject_c(content, updates, path)
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
        "Strings injected: %d, skipped: %d"
        % (
            sum(result.applied for result in results),
            sum(result.skipped for result in results),
        )
    )
    if any(result.skipped for result in results):
        print("  skipped strings are reported above on stderr; nothing was written for them.")
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
