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
    text macro invocation belonging to a ``(label, index)`` (``.h``/``.c``),
    touching nothing else.  Idempotent: re-running on already-injected content
    is a no-op.

    On the C side every form ``extractor.extract_strings_from_c`` recognises is
    writable: ``NAME[] = _("...")``, adjacent literals concatenated across
    lines, ``COMPOUND_STRING``, ``ITEM_NAME`` / ``ITEM_PLURAL_NAME``, a
    ``#define X COMPOUND_STRING(...)`` body written with backslash
    continuations, and struct-field entries the extractor labels
    ``ITEM_STRANGE_BALL.description``.  The block's own prefix, separators and
    suffix are reused verbatim, and the splitter never emits more literals than
    the file already used, so a rewrite cannot introduce a line break -- which
    inside a ``#define`` would need a continuation the file does not have.

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
   ``#elif``/``#else``/``#endif`` line.  ``.inc``: the extractor concatenated
   across those directives while this module's parser stops at them, so the two
   could disagree about block boundaries.  C: a label an ``#if`` redefines gets
   its index from this tree's ordering, and a corpus joined from another tree
   (Step 2's Chinese fork) may order the branches the other way round.  Where
   either can disagree, nothing is written;
6. (C only) the label is not defined more than once in the file, for the same
   reason: a repeated label means the index, not the label, carries the
   identity, and the index is a property of one file's ordering;
7. (C only) only whitespace, continuations and comments sit between the block's
   literals.  ``"for "BINDING_TURNS" turns."`` is one string to the compiler but
   two literals to the extractor, so its ``source`` is missing the macro: the
   entry is refused rather than rewritten without it.

Injection filter (MANDATORY)
----------------------------
``translated_corpus.json`` contains thousands of ``match_type == "dictionary"``
entries.  Those are **not** translations: they are the English sentence with
Chinese terms spliced in, e.g. ``"...always bring our 宝可梦.\\lHow about a
quick battle?$"``.  Injecting them would leave the ROM mixed-language, which is
strictly worse than leaving it English, so they are excluded here and the
exclusion is reported by ``--dry-run``.  Only genuine, complete translations
(``match_type`` of ``"exact"``, ``"term"`` or ``"zh_fork"``) are ever written
back.

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
from tools.i18n.extractor import (  # noqa: E402  (import after sys.path bootstrap)
    _C_MACRO_RE,
    _close_paren,
    _default_c_category,
    _mask_comments,
    _splice_continuations,
    extract_strings_from_c,
    is_meaningful_string,
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
#: string (e.g. ``"CANCEL$"`` -> ``"取消$"``); ``"zh_fork"`` is the Chinese
#: expansion fork's translation of the very same ``(file, label, index)``, so
#: it is a complete translation by construction.
INJECTABLE_MATCH_TYPES: Tuple[str, ...] = ("exact", "term", "zh_fork", "curated_story")

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

#: Preprocessor conditionals.  A block that spans or abuts one of these is never
#: written: a conditional branch may be redefined in the other branch (the same
#: ``MOVE_HAIL.description`` in an ``#if`` and its ``#else``), and the index that
#: separates the two is an artefact of this tree's ordering -- another tree may
#: order the branches the other way round, and a corpus joined across trees
#: would then bind the wrong translation to the wrong branch.  Refusing costs a
#: handful of entries; guessing corrupts the game.  ``_PREPROC_RE`` matches the
#: directive itself, ``_preprocessor_guarded_lines`` the whole region it opens.
_PREPROC_RE = re.compile(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b")
_PREPROC_OPENERS = ("if", "ifdef", "ifndef")

#: C translation phase 2: a backslash-newline is deleted before anything else
#: sees the text.  Splitting, not :func:`re.sub`, so the offset of every
#: surviving character can be recorded as it is kept (see
#: :func:`_splice_with_index_map`).
_C_CONTINUATION_RE = re.compile(r"\\\r?\n")

#: What may sit between two literals of one macro invocation: whitespace, the
#: line continuations that join them, and comments.  Anything else -- an
#: identifier in particular -- is code the compiler splices into the string, so
#: the concatenated source and a rewritten block would both be wrong.
_C_GAP_LAYOUT_RE = re.compile(r"(?:[ \t\r\n\\]|//[^\n]*|/\*.*?\*/)*\Z", re.S)


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

    That is ``match_type`` of ``"exact"``, ``"term"`` or ``"zh_fork"``.
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


# --------------------------------------------------------------------------
# C sources: the forms the extractor recognises, written back
# --------------------------------------------------------------------------
#
# ``extractor`` owns the C parse: which macro invocations become corpus entries,
# what text they hold, and what ``(label, index)`` addresses each one.  A second
# parser here is exactly how ``(label, index)`` came to mean different strings
# to the two modules, so the injector reuses the extractor's scanner
# (``_C_MACRO_RE``, ``_close_paren``, the literal scanner, the concatenation
# rule and ``is_meaningful_string``) and adds only two things: *where* each
# entry sits in the file, and the layout needed to rewrite it in place.
#
# Everything the extractor recognises is covered by that one scanner -- adjacent
# literal concatenation, ``COMPOUND_STRING`` (including across lines),
# ``ITEM_NAME`` / ``ITEM_PLURAL_NAME``, ``#define X COMPOUND_STRING(...)`` bodies
# with backslash continuations, and struct-field forms the extractor labels
# ``ITEM_STRANGE_BALL.description``.  The label is never derived here; it is
# read back from ``extract_strings_from_c``, so the two can never drift.


def _splice_with_index_map(content: str) -> Tuple[str, List[int]]:
    """Apply C phase 2, keeping the offset each surviving character came from.

    ``extractor._splice_continuations`` deletes every backslash-newline, so its
    offsets cannot be used to edit the file on disk; ``index_map[i]`` is the
    offset in ``content`` of character ``i`` of the spliced text.  Comment
    masking (``extractor._mask_comments``) replaces characters one for one and
    therefore preserves those offsets.
    """
    spliced: List[str] = []
    index_map: List[int] = []
    position = 0
    length = len(content)
    while position < length:
        continuation = _C_CONTINUATION_RE.match(content, position)
        if continuation:
            position = continuation.end()
            continue
        spliced.append(content[position])
        index_map.append(position)
        position += 1
    return "".join(spliced), index_map


def _skip_literal(text: str, index: int, end: int) -> int:
    """Index just past the literal starting at ``index``, bounded by ``end``."""
    quote = text[index]
    position = index + 1
    while position < end:
        if text[position] == "\\":
            position += 2
            continue
        if text[position] == quote:
            return position + 1
        position += 1
    return end


def _literal_bodies(text: str, start: int, end: int) -> List[Tuple[int, int]]:
    """``(body_start, body_end)`` of every string literal in ``text[start:end]``.

    Mirrors ``extractor._string_literals`` (which is what produced the corpus
    text) but reports positions, so the pieces can be laid out again where the
    file already had them.
    """
    bodies: List[Tuple[int, int]] = []
    position = start
    while position < end:
        character = text[position]
        if character == "'":
            position = _skip_literal(text, position, end)
            continue
        if character == '"':
            body_start = position + 1
            position = _skip_literal(text, position, end)
            bodies.append((body_start, position - 1))
            continue
        position += 1
    return bodies


def _locate_c_macros(text: str) -> List[Tuple[int, int, int]]:
    """Locate every text macro invocation that becomes a corpus entry.

    ``(macro_start, open_paren, close_paren)`` in the order
    ``extractor.extract_strings_from_c`` emits its entries -- that 1:1 order is
    what lets a corpus entry be addressed without re-deriving a label here.
    The filter is the extractor's, restated: an unbalanced ``(``, a call with no
    string literal, and a string with no alphanumeric character are not entries.
    """
    located: List[Tuple[int, int, int]] = []
    for match in _C_MACRO_RE.finditer(text):
        open_paren = match.end() - 1
        close = _close_paren(text, open_paren)
        if close == -1:
            continue
        bodies = _literal_bodies(text, open_paren + 1, close - 1)
        if not bodies:
            continue
        if not is_meaningful_string("".join(text[start:end] for start, end in bodies)):
            continue
        located.append((match.start(), open_paren, close))
    return located


@dataclass
class _CLayout:
    """Where a macro's literals sit, so a rewrite can keep the same shape.

    ``prefix``/``gaps``/``suffix`` are the file's own text between the brackets
    and between the literals -- reusing them verbatim is what keeps a
    ``#define`` body's backslash continuations, a struct field's indentation and
    a one-line ``ITEM_NAME("...")`` byte-identical around the new text.

    There are always at least ``len(pieces) - 1`` gaps, and the splitter never
    emits more pieces than the file had, so a rewrite never needs a separator
    the file did not already contain.
    """

    prefix: str
    pieces: List[str]
    gaps: List[str]
    suffix: str

    def gap(self, index: int) -> str:
        """The separator that belongs before the ``index``-th following literal."""
        return self.gaps[index]


@dataclass
class _CBlock:
    """One text-macro invocation, addressed by the extractor's ``(label, index)``."""

    label: str
    index: int
    start: int
    end: int
    text: str
    layout: _CLayout
    #: Why this block must not be rewritten, or ``""`` when it may be.
    refusal: str = ""


def _parse_c_blocks(path: str, content: str, category: str) -> List[_CBlock]:
    """Locate every corpus-addressable text block in a C file.

    Labels and indices are not recomputed here: they are taken from
    :func:`extractor.extract_strings_from_c`, which owns that contract (per-label
    indices for engine text, the file-global macro ordinal for the legacy
    ``src/data/text`` roots).  The spans are zipped onto its entries in source
    order; if the two lists ever disagree the file is refused outright rather
    than edited with offsets that might belong to another string.
    """
    spliced, index_map = _splice_with_index_map(content)
    if spliced != _splice_continuations(content):  # pragma: no cover - invariant
        print(
            "warning: refusing to inject %s: continuation splice disagrees with "
            "the extractor's" % (path,),
            file=sys.stderr,
        )
        return []

    masked = _mask_comments(spliced)
    located = _locate_c_macros(masked)
    entries = extract_strings_from_c(path, content, category)
    if len(entries) != len(located):
        print(
            "warning: refusing to inject %s: located %d text macros but the "
            "extractor reports %d entries" % (path, len(located), len(entries)),
            file=sys.stderr,
        )
        return []

    lines = content.split("\n")
    directive_lines = [bool(_PREPROC_RE.match(line)) for line in lines]

    blocks: List[_CBlock] = []
    for entry, (macro_start, open_paren, close) in zip(entries, located):
        start = index_map[open_paren]
        end = index_map[close - 1]
        bodies = _literal_bodies(masked, open_paren + 1, close - 1)
        # ``(quote, one past the closing quote)`` in offsets of ``content``.
        spans = [
            (index_map[body_start - 1], index_map[body_end] + 1)
            for body_start, body_end in bodies
        ]

        layout = _CLayout(
            prefix=content[start:spans[0][0]],
            pieces=[content[first + 1:last - 1] for first, last in spans],
            gaps=[content[spans[i][1]:spans[i + 1][0]] for i in range(len(spans) - 1)],
            suffix=content[spans[-1][1]:end],
        )

        start_line = content.count("\n", 0, index_map[macro_start])
        end_line = content.count("\n", 0, end)
        refusal = ""
        if _is_guarded_block(directive_lines, start_line, start_line, end_line + 1):
            refusal = "block spans or abuts a #if/#else/#endif preprocessor block"
        elif not all(_C_GAP_LAYOUT_RE.match(gap) for gap in layout.gaps):
            # ``"for "BINDING_TURNS" turns."`` -- a macro is spliced between two
            # literals.  The extractor concatenates the literals only, so the
            # entry's ``source`` is not the string the ROM builds, and rewriting
            # the block would drop the macro from the compiled text.
            refusal = (
                "a macro or expression sits between this block's literals, so "
                "the extracted source is not the whole string"
            )
        blocks.append(_CBlock(entry.label, entry.index, start, end, entry.source, layout, refusal))

    return blocks


def _c_chunk_boundaries(text: str) -> List[int]:
    """Offsets just past every ``\\n``/``\\l``/``\\p``/``$`` in ``text``.

    These are the only places a C literal may be split: an escape pair and a
    multi-byte character are never torn.  Unlike :func:`split_chunks` a boundary
    is kept even when the text ends unterminated, so a translation with two
    lines but no ``$`` still splits into two literals.
    """
    boundaries: List[int] = []
    position = 0
    length = len(text)
    while position < length:
        character = text[position]
        if character == "\\" and position + 1 < length:
            code = text[position + 1]
            position += 2
            if code in "nlp" and position < length:
                boundaries.append(position)
            continue
        if character == TERMINATOR:
            position += 1
            if position < length:
                boundaries.append(position)
            continue
        position += 1
    return boundaries


def _split_at(text: str, boundaries: Sequence[int]) -> List[str]:
    """Cut ``text`` at ``boundaries``; the pieces re-join to ``text`` exactly."""
    pieces: List[str] = []
    previous = 0
    for boundary in boundaries:
        pieces.append(text[previous:boundary])
        previous = boundary
    pieces.append(text[previous:])
    return pieces


def _split_c_text(text: str, lengths: Sequence[int]) -> List[str]:
    """Split ``text`` into literals, never growing the file's block.

    The file already decided how many literals this string is written as -- one
    for ``ITEM_NAME("...")`` and a short ``_("...")``, three for the descriptions
    in ``items.h`` -- and that count is kept whenever the text has the line
    boundaries to reach it.  A translation that re-flows to fewer lines collapses
    (three literals become one holding two ``\\n``), which is what the upstream
    Chinese fork does too; a translation that re-flows to more lines is spread
    over the same literals rather than growing new ones.  Growing is what would
    need a synthesised separator, and inside a ``#define`` a synthesised line
    break without a backslash would end the macro.

    Boundaries are picked proportionally to the original pieces when a choice
    exists, which makes the split a fixed point: a second run sees pieces with
    exactly those proportions and picks the same boundaries again.
    """
    wanted = len(lengths)
    if wanted <= 1:
        return [text]

    boundaries = _c_chunk_boundaries(text)
    if not boundaries:
        return [text]
    if len(boundaries) < wanted - 1:
        # Fewer lines than the file used literals: one literal per line is the
        # closest the text can get to that shape, and it is stable -- the next
        # run sees exactly these pieces and no longer needs to choose.
        return _split_at(text, boundaries)

    total = sum(lengths)
    if total <= 0:  # pragma: no cover - a block with only empty literals
        return _split_at(text, boundaries)

    targets: List[int] = []
    cumulative = 0
    for length in lengths[:-1]:
        cumulative += length
        targets.append((len(text) * cumulative) // total)

    chosen: List[int] = []
    previous = -1
    for position, target in enumerate(targets):
        # Keep room for the picks still to come, so the selection stays strictly
        # increasing and produces exactly ``wanted`` pieces.
        remaining = wanted - 2 - position
        low = previous + 1
        high = len(boundaries) - 1 - remaining
        if low > high:  # pragma: no cover - guarded by the length check above
            return _split_at(text, boundaries)
        pick = min(range(low, high + 1), key=lambda index: (abs(boundaries[index] - target), index))
        chosen.append(boundaries[pick])
        previous = pick
    return _split_at(text, chosen)


def _c_literal(text: str) -> str:
    """Render ``text`` as one C string literal, or raise ``ValueError``."""
    if '"' in text or "\n" in text or "\r" in text:
        raise ValueError("refusing to emit text containing a quote or raw newline: %r" % (text,))
    if (len(text) - len(text.rstrip("\\"))) % 2:
        raise ValueError("refusing to emit text ending in an unescaped backslash: %r" % (text,))
    return '"%s"' % (text,)


def _render_c_block(block: _CBlock, text: str) -> str:
    """Lay ``text`` out inside ``block``'s brackets in the file's own style."""
    layout = block.layout
    pieces = _split_c_text(text, [len(piece) for piece in layout.pieces])
    parts = [layout.prefix]
    for index, piece in enumerate(pieces):
        if index:
            parts.append(layout.gap(index - 1))
        parts.append(_c_literal(piece))
    parts.append(layout.suffix)
    return "".join(parts)


def _inject_c(content: str, updates: Sequence[dict], path: str = "") -> Tuple[str, int, int]:
    category = _default_c_category(path)
    blocks = _parse_c_blocks(path, content, category)

    by_key: Dict[Tuple[str, int], List[_CBlock]] = {}
    for block in blocks:
        by_key.setdefault((block.label, block.index), []).append(block)
    # A repeated label means the index carries the identity, and the index is a
    # property of one file's ordering: it may be a table row (``sFavorLady``'s
    # six ``.request`` strings) or a branch of an ``#if`` (``ITEM_EXP_SHARE``).
    # In both cases another tree need not number them the same way, so none of
    # them are written.
    redefined = {label for label, count in Counter(block.label for block in blocks).items() if count > 1}

    unique = _dedupe_updates(updates)
    edits: List[Tuple[int, int, str]] = []
    applied = 0
    for update in unique:
        translation = _guarded_translation(path, update)
        if translation is None:
            continue

        matches = by_key.get((update.get("label"), update.get("index")), [])
        if len(matches) != 1:
            # Falling back to the first macro with this label would rewrite an
            # unrelated string and report success; never guess.
            _report_skip(
                path, update,
                "expected exactly one text macro at this (label, index), found %d"
                % (len(matches),),
            )
            continue
        block = matches[0]

        if block.refusal:
            _report_skip(path, update, block.refusal)
            continue
        if block.label in redefined:
            _report_skip(
                path, update,
                "label %r is defined more than once in this file, so its index is "
                "not a stable identity" % (block.label,),
            )
            continue

        wrapped = _wrapped_or_skip(path, update, translation)
        if wrapped is None:
            continue
        if block.text != update.get("source") and block.text != wrapped:
            _report_skip(
                path, update,
                "macro literal does not match the corpus source (found %r)"
                % (block.text[:60],),
            )
            continue

        try:
            rendered = _render_c_block(block, wrapped)
        except ValueError as exc:
            _report_skip(path, update, "refusing to emit the translation (%s)" % exc)
            continue

        edits.append((block.start, block.end, rendered))
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
    rewritten; ``.h`` and ``.c`` files get the invocation of a text macro
    (``_(...)``, ``COMPOUND_STRING(...)``, ``ITEM_NAME(...)``, ...) rewritten
    around its own literals.  Nothing outside the matched block is touched.

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
