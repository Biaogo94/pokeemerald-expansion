# -*- coding: utf-8 -*-
r"""Format guard and dictionary-driven translation processor for the Heart & Soul
Chinese localization pipeline.

Task 2 aligned what the base dictionary and the HGSS dialogue set could prove
(139 strings).  This stage processes the remainder: it substitutes the
base-dictionary terms it finds (POKéMON -> 宝可梦, ...) and writes
``data/translated_corpus.json``.

No external LLM is reachable from CI, so the fallback translator is deliberately
conservative and *honest rather than complete*:

* a string with **zero** dictionary hits keeps ``"translation": null`` -- it is
  visibly untranslated instead of silently wrong;
* every produced translation is passed through :func:`validate_translation`
  before it is written, and is dropped back to ``null`` if the guard rejects it;
* ambiguous dictionary keys -- keys that are also ordinary English words
  (``NO``, ``REST``, ``FLY`` ...) -- are not substituted in free text at all.
  ``base_dict.json`` already applies exactly this rule to whole-string matches
  (see its ``ambiguous_terms`` note, which rejects ``RETURN$`` because it means
  the menu's "back" and not the move); the same rule is even more necessary for
  free-text substitution, where the homograph can sit in the middle of a
  sentence.  See :data:`FREE_TEXT_UNSAFE_KEYS`.

Everything else stays ``null``, including the overwhelming majority of the
corpus: a dictionary fallback can name ``POKéMON`` but cannot translate a
sentence.  What this stage guarantees is that nothing it emits can corrupt a
string.

The guard: why it is load-bearing
---------------------------------
Control codes are not decoration.  A dropped ``$`` makes the string swallow the
next one, a dropped ``\p`` merges two text boxes, a dropped ``{STR_VAR_1}``
prints the literal placeholder on screen.  :func:`validate_translation`
therefore compares, and refuses on any difference:

* the ``{...}`` placeholder multiset (``{PLAYER}``, ``{RIVAL}``,
  ``{STR_VAR_1}``, ``{KUN}``, ``{COLOR ...}``, ...);
* the ``$`` terminator -- present if and only if the source has one, with a
  matching total count;
* the count of ``\n``, ``\l`` and ``\p``.  Their *positions* may move -- Chinese
  is far more compact, so re-wrapping is a legitimate translation -- but their
  volume may not change, or paragraph paging changes;
* non-emptiness of the text that remains once the controls are removed.

The error carries a stable, cross-platform ``code`` so the failure is
reportable without parsing prose.
"""

import argparse
import json
import os
import re
import sys
from collections import Counter
from dataclasses import dataclass
from typing import Dict, Iterable, List, Optional, Sequence, Tuple

# Running this file as a script (``python tools/i18n/ai_translator.py``) puts
# ``tools/i18n`` -- not the repository root -- on ``sys.path``, which would hide
# the ``tools.i18n`` package.  Put the repository root back before importing the
# sibling module, so both ``python -m ...`` and script mode import the *same*
# module object.
_REPO_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
if _REPO_ROOT not in sys.path:
    sys.path.insert(0, _REPO_ROOT)

from tools.i18n.aligner import (  # noqa: E402  (import after sys.path bootstrap)
    BASE_DICT_PATH,
    DATA_DIR,
    UNMATCHED_CORPUS_PATH,
    extract_placeholders,
    find_terms,
    flatten_terms,
    load_base_dict,
    normalize_skeleton,
    substitute_terms,
)

# --------------------------------------------------------------------------
# Paths
# --------------------------------------------------------------------------

TRANSLATED_CORPUS_PATH = os.path.join(DATA_DIR, "translated_corpus.json")

# --------------------------------------------------------------------------
# Control codes and placeholders
# --------------------------------------------------------------------------

TERMINATOR = "$"
PARAGRAPH_BREAK = "\\p"
NEWLINE = "\\n"
SCROLL = "\\l"

#: Codes whose *count* must be identical in source and translation.
CONTROL_CODES = (PARAGRAPH_BREAK, NEWLINE, SCROLL)

_PLACEHOLDER_RE = re.compile(r"\{[^{}]*\}")
_CONTROL_CODE_RE = re.compile(r"\\[npl]")

# --------------------------------------------------------------------------
# Stable error codes
# --------------------------------------------------------------------------

CODE_TYPE_ERROR = "TYPE_ERROR"
CODE_PLACEHOLDER_MISMATCH = "PLACEHOLDER_MISMATCH"
CODE_TERMINATOR_MISSING = "TERMINATOR_MISSING"
CODE_TERMINATOR_UNEXPECTED = "TERMINATOR_UNEXPECTED"
CODE_TERMINATOR_COUNT_MISMATCH = "TERMINATOR_COUNT_MISMATCH"
CODE_CONTROL_CODE_MISMATCH = "CONTROL_CODE_MISMATCH"
CODE_EMPTY_TRANSLATION = "EMPTY_TRANSLATION"
CODE_UNEXPECTED_TEXT = "UNEXPECTED_TEXT"

# --------------------------------------------------------------------------
# Processor vocabulary
# --------------------------------------------------------------------------

MATCH_DICTIONARY = "dictionary"
REASON_DICTIONARY = "DICTIONARY_SUBSTITUTION"
REASON_NO_TERM = "NO_DICTIONARY_TERM"
REASON_GUARD_REJECTED = "FORMAT_GUARD_REJECTED"

#: Confidence recorded for a partial, dictionary-only substitution.  Always
#: below the aligner's ``term`` confidence (0.9): the sentence is not translated,
#: only the terms inside it are.
DICTIONARY_CONFIDENCE = 0.5

#: Base-dictionary keys that are also ordinary English words and must therefore
#: never be substituted in free text.  ``NO`` (719 occurrences) fires on
#: "there's no time"; ``REST`` on "the rest of us"; ``FLY`` on "fly away".
#: ``base_dict.json`` already excludes such keys from whole-string alignment via
#: ``ambiguous_terms`` -- this is the same judgement applied to substitution,
#: where the context is weaker still.  Excluded keys are not lost: the string
#: simply stays ``null`` (visibly untranslated) instead of carrying a guess.
#: Extend deliberately; the list is audited by hand, never derived.
FREE_TEXT_UNSAFE_KEYS = frozenset(
    {
        "NO",
        "YES",
        "MOM",
        "OAK",
        "ELM",
        "DIG",
        "FLY",
        "CUT",
        "BAG",
        "EGG",
        "MEW",
        "REST",
        "SAVE",
        "MOVE",
        "MOVES",
        "ITEM",
        "ITEMS",
        "LEVEL",
        "ATTACK",
        "MONEY",
        "NATURE",
        "BERRY",
        "RETURN",
        "PROF",
        "PROF.",
    }
)


# --------------------------------------------------------------------------
# Format guard
# --------------------------------------------------------------------------


class TranslationFormatError(ValueError):
    """Raised when a translation would corrupt its source's controls.

    Attributes
    ----------
    code:
        Stable, cross-platform error code (see the ``CODE_*`` constants).
    source / translation:
        The offending pair, so a caller can log or repair without re-deriving
        them.
    """

    def __init__(
        self,
        code: str,
        message: str,
        source: Optional[str] = None,
        translation: Optional[str] = None,
    ):
        self.code = code
        self.source = source
        self.translation = translation
        detail = f"{code}: {message}"
        if isinstance(source, str):
            detail += f"\n  source      : {_preview(source)}"
        if isinstance(translation, str):
            detail += f"\n  translation : {_preview(translation)}"
        super().__init__(detail)


def _preview(text: str, limit: int = 60) -> str:
    """One-line, bounded rendering of ``text`` for an error message."""
    flat = text.replace("\r", " ").replace("\n", " ")
    if len(flat) > limit:
        return flat[:limit] + "..."
    return flat


def _strip_controls(text: str) -> str:
    """Remove ``\\n`` / ``\\l`` / ``\\p`` and ``$``, then trim whitespace."""
    return _CONTROL_CODE_RE.sub("", text).replace(TERMINATOR, "").strip()


def _is_terminated(text: str) -> bool:
    """True when ``text`` ends with the ``$`` string terminator."""
    return text.rstrip().endswith(TERMINATOR)


def validate_translation(source: str, translation: str) -> None:
    """Raise :class:`TranslationFormatError` if the translation corrupts the source.

    Checks, in order:

    1. both arguments are strings;
    2. the ``{...}`` placeholder multiset is identical -- none dropped, none
       invented, none collapsed;
    3. the ``$`` terminator is present if and only if the source has one, and
       the total ``$`` count matches (a second ``$`` truncates the string);
    4. ``\\n``, ``\\l`` and ``\\p`` counts match individually -- the positions
       may be re-flowed, the volume may not change;
    5. the text left after removing the controls is non-empty -- unless the
       source itself has no text, in which case the translation must not invent
       any.

    Returns ``None`` on success.  The function is pure and never mutates its
    arguments.
    """
    if not isinstance(source, str):
        raise TranslationFormatError(
            CODE_TYPE_ERROR, "source is not a string", source, translation
        )
    if not isinstance(translation, str):
        raise TranslationFormatError(
            CODE_TYPE_ERROR,
            "translation is not a string (got %s)" % type(translation).__name__,
            source,
            translation,
        )

    # 1. Placeholders: identical multiset, duplicates included.
    source_placeholders = Counter(extract_placeholders(source))
    translation_placeholders = Counter(extract_placeholders(translation))
    if source_placeholders != translation_placeholders:
        missing = sorted((source_placeholders - translation_placeholders).elements())
        extra = sorted((translation_placeholders - source_placeholders).elements())
        problems = []
        if missing:
            problems.append("dropped " + ", ".join(missing))
        if extra:
            problems.append("invented " + ", ".join(extra))
        raise TranslationFormatError(
            CODE_PLACEHOLDER_MISMATCH,
            "placeholder mismatch (%s)" % "; ".join(problems),
            source,
            translation,
        )

    # 2. Terminator.
    if _is_terminated(source) and not _is_terminated(translation):
        raise TranslationFormatError(
            CODE_TERMINATOR_MISSING,
            "source ends with %r but the translation does not" % TERMINATOR,
            source,
            translation,
        )
    if _is_terminated(translation) and not _is_terminated(source):
        raise TranslationFormatError(
            CODE_TERMINATOR_UNEXPECTED,
            "translation ends with %r but the source does not" % TERMINATOR,
            source,
            translation,
        )
    if source.count(TERMINATOR) != translation.count(TERMINATOR):
        raise TranslationFormatError(
            CODE_TERMINATOR_COUNT_MISMATCH,
            "terminator count %d -> %d"
            % (source.count(TERMINATOR), translation.count(TERMINATOR)),
            source,
            translation,
        )

    # 3. Line breaks and page breaks: same volume, free order.
    for code in CONTROL_CODES:
        source_count = source.count(code)
        translation_count = translation.count(code)
        if source_count != translation_count:
            raise TranslationFormatError(
                CODE_CONTROL_CODE_MISMATCH,
                "control %r count %d -> %d" % (code, source_count, translation_count),
                source,
                translation,
            )

    # 4. Non-emptiness.
    source_text = _strip_controls(source)
    translation_text = _strip_controls(translation)
    if source_text and not translation_text:
        raise TranslationFormatError(
            CODE_EMPTY_TRANSLATION,
            "translation carries no text once the controls are removed",
            source,
            translation,
        )
    if translation_text and not source_text:
        raise TranslationFormatError(
            CODE_UNEXPECTED_TEXT,
            "source carries no text, so the translation must not add any",
            source,
            translation,
        )


# --------------------------------------------------------------------------
# Term substitution outside placeholders
# --------------------------------------------------------------------------


def _segments(text: str) -> Iterable[Tuple[str, bool]]:
    """Yield ``(segment, is_placeholder)`` covering ``text`` exactly."""
    cursor = 0
    for match in _PLACEHOLDER_RE.finditer(text):
        if match.start() > cursor:
            yield text[cursor : match.start()], False
        yield match.group(0), True
        cursor = match.end()
    if cursor < len(text):
        yield text[cursor:], False


def substitute_terms_outside_placeholders(text: str, terms: Dict[str, str]) -> str:
    """Substitute base-dictionary terms in ``text``, skipping placeholders.

    A dictionary key has no business inside ``{COLOR ...}`` or ``{STR_VAR_1}``:
    a key such as ``RED`` would otherwise rewrite the placeholder's argument and
    silently change the rendered colour.  Only the prose segments are passed to
    :func:`tools.i18n.aligner.substitute_terms`, which keeps the match
    whole-word, case-insensitive and longest-first.
    """
    if not text or not terms:
        return text
    pieces: List[str] = []
    for segment, is_placeholder in _segments(text):
        pieces.append(segment if is_placeholder else substitute_terms(segment, terms))
    return "".join(pieces)


def find_terms_outside_placeholders(text: str, terms: Dict[str, str]) -> List[str]:
    """Dictionary keys that would be substituted in ``text``, in document order.

    Duplicates collapse to first occurrence; the result is the audit trail for
    what a substitution changed.
    """
    if not text or not terms:
        return []
    found: List[str] = []
    seen = set()
    for segment, is_placeholder in _segments(text):
        if is_placeholder:
            continue
        for key in _find_keys(segment, terms):
            if key not in seen:
                seen.add(key)
                found.append(key)
    return found


def _find_keys(segment: str, terms: Dict[str, str]) -> List[str]:
    """Keys from ``terms`` occurring in ``segment`` (whole-word, case-folded)."""
    return [key for key, _ in find_terms(segment, terms)]


# --------------------------------------------------------------------------
# Translation engine
# --------------------------------------------------------------------------


@dataclass
class TranslationStats:
    """Counters for one corpus pass."""

    total: int = 0
    translated: int = 0
    untranslated: int = 0
    guard_rejected: int = 0
    terms_used: int = 0

    def as_dict(self) -> dict:
        return {
            "total": self.total,
            "translated": self.translated,
            "untranslated": self.untranslated,
            "guard_rejected": self.guard_rejected,
            "terms_used": self.terms_used,
        }


class DictionaryTranslator:
    """Dictionary-only translator: substitutes known terms, invents nothing.

    :meth:`translate` returns ``(None, [])`` when the string carries no known
    term -- the caller must keep it ``null`` rather than fill it with a guess.
    """

    def __init__(
        self,
        base_dict: Optional[dict] = None,
        *,
        skip_keys: Optional[Iterable[str]] = None,
    ):
        self.base_dict = base_dict if base_dict is not None else {}

        excluded = {
            normalize_skeleton(key)
            for key in self.base_dict.get("ambiguous_terms", []) or []
            if isinstance(key, str)
        }
        excluded |= {normalize_skeleton(key) for key in FREE_TEXT_UNSAFE_KEYS}
        excluded |= {normalize_skeleton(key) for key in skip_keys or ()}

        self.terms: Dict[str, str] = {
            key: value
            for key, value in flatten_terms(self.base_dict).items()
            if normalize_skeleton(key) not in excluded
        }
        self.term_count = len(self.terms)
        self.excluded_count = len(flatten_terms(self.base_dict)) - self.term_count
        self._cache: Dict[str, Tuple[Optional[str], List[str]]] = {}

    @classmethod
    def from_file(cls, path: str = BASE_DICT_PATH, **kwargs) -> "DictionaryTranslator":
        return cls(load_base_dict(path), **kwargs)

    def translate(self, source: str) -> Tuple[Optional[str], List[str]]:
        """Return ``(translation, matched_keys)``; ``(None, [])`` when nothing hit."""
        if not source or not self.terms:
            return None, []
        cached = self._cache.get(source)
        if cached is not None:
            return cached
        translated = substitute_terms_outside_placeholders(source, self.terms)
        if translated == source:
            result: Tuple[Optional[str], List[str]] = (None, [])
        else:
            result = (translated, find_terms_outside_placeholders(source, self.terms))
        self._cache[source] = result
        return result


def translate_corpus(
    entries: Sequence[dict],
    base_dict: Optional[dict] = None,
    *,
    skip_keys: Optional[Iterable[str]] = None,
    translator: Optional[DictionaryTranslator] = None,
) -> Tuple[List[dict], TranslationStats]:
    """Translate a corpus of unmatched entries, returning ``(entries, stats)``.

    Every input field is preserved.  For each entry one of three outcomes is
    recorded:

    ``translation`` set
        at least one dictionary term was substituted and the result passed
        :func:`validate_translation`; ``match_type`` is ``"dictionary"``,
        ``reason`` is ``"DICTIONARY_SUBSTITUTION"`` and ``confidence`` is
        :data:`DICTIONARY_CONFIDENCE`;
    ``translation: null``, ``reason: "NO_DICTIONARY_TERM"``
        nothing in the string was known -- left visibly untranslated;
    ``translation: null``, ``reason: "FORMAT_GUARD_REJECTED"``
        a substitution was produced but the guard refused it (a corrupted
        placeholder, say).  It is dropped rather than repaired: a repair would
        itself be a guess.
    """
    if translator is None:
        translator = DictionaryTranslator(base_dict or {}, skip_keys=skip_keys)

    translated_entries: List[dict] = []
    stats = TranslationStats()
    terms_used = set()

    for entry in entries:
        out = dict(entry)
        source = entry.get("source") or ""
        stats.total += 1

        produced, matched = translator.translate(source)
        rejected = False
        if produced is not None:
            try:
                validate_translation(source, produced)
            except TranslationFormatError:
                # Dropped rather than repaired: a repair would itself be a guess.
                rejected = True

        if produced is None or rejected:
            out["translation"] = None
            out["match_type"] = None
            out["matched_key"] = None
            out["confidence"] = None
            out["matched_terms"] = []
            if rejected:
                out["reason"] = REASON_GUARD_REJECTED
                stats.guard_rejected += 1
            else:
                out["reason"] = REASON_NO_TERM
                stats.untranslated += 1
        else:
            out["translation"] = produced
            out["match_type"] = MATCH_DICTIONARY
            out["matched_key"] = matched[0] if matched else None
            out["matched_terms"] = list(matched)
            out["confidence"] = DICTIONARY_CONFIDENCE
            out["reason"] = REASON_DICTIONARY
            stats.translated += 1
            terms_used.update(matched)

        translated_entries.append(out)

    stats.terms_used = len(terms_used)
    return translated_entries, stats


# --------------------------------------------------------------------------
# CLI
# --------------------------------------------------------------------------


def _write_json(path: str, payload) -> None:
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    with open(path, "w", encoding="utf-8") as fp:
        json.dump(payload, fp, ensure_ascii=False, indent=2)


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(
        description=(
            "Substitute base-dictionary terms into the unmatched corpus and write "
            "the guarded result (untranslated strings stay null)."
        )
    )
    parser.add_argument("--input", default=UNMATCHED_CORPUS_PATH, help="Unmatched corpus JSON.")
    parser.add_argument(
        "--output", default=TRANSLATED_CORPUS_PATH, help="Translated corpus output JSON."
    )
    parser.add_argument("--base-dict", default=BASE_DICT_PATH, help="Base dictionary JSON.")
    args = parser.parse_args(argv)

    base_dict = load_base_dict(args.base_dict)
    with open(args.input, "r", encoding="utf-8") as fp:
        corpus = json.load(fp)

    translator = DictionaryTranslator(base_dict)
    translated, stats = translate_corpus(corpus, translator=translator)
    _write_json(args.output, translated)

    total = stats.total or 1
    print(f"dictionary terms      : {translator.term_count}")
    print(f"excluded homographs   : {translator.excluded_count} (ambiguous_terms + unsafe English)")
    print(f"corpus entries        : {stats.total}")
    print(f"translated            : {stats.translated} ({stats.translated * 100.0 / total:.2f}%)")
    print(f"    distinct terms    : {stats.terms_used}")
    print(f"left null             : {stats.untranslated} ({stats.untranslated * 100.0 / total:.2f}%)")
    print(f"guard rejected        : {stats.guard_rejected}")
    print(f"written               : {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
