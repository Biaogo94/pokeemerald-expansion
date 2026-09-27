# -*- coding: utf-8 -*-
r"""HGSS alignment engine for the Heart & Soul Chinese localization pipeline.

The aligner reuses already-known Chinese text instead of machine-translating
everything from scratch.  Two sources of known text are supported:

* ``base_dict.json`` -- curated official Simplified Chinese terminology
  (species, moves, items, abilities, game terms) plus a HGSS dialogue
  matching set (Professor Oak's introduction, Professor Elm's starter
  selection, ...).
* Skeleton matching -- line wrapping, ``\\n`` / ``\\l`` / ``\\p`` placement and
  whitespace differ constantly between the source script and the translation,
  so strings are compared through a *skeleton* with every control code and
  every whitespace character removed.

Global invariant enforced on every emitted translation
-----------------------------------------------------
No alignment is ever emitted that would corrupt a string:

* variable placeholders (``{PLAYER}``, ``{RIVAL}``, ``{STR_VAR_1}``, ``{KUN}``,
  ``{COLOR ...}``, ...) must match the source exactly -- none dropped, none
  invented;
* the ``$`` terminator and the ``\p`` page breaks must be preserved, or the
  string would swallow whatever follows it.

Line breaks (``\n``, ``\l``) are deliberately exempt: they are pure layout,
and re-flowing them is exactly what translating English into more compact
Chinese requires.  Pass ``strict_line_breaks=True`` to
:func:`validate_control_codes_preserved` to audit an exact layout match.

Only the ``$`` terminator is repaired automatically (:func:`repair_terminator`),
because a dictionary term such as ``精灵球`` is stored without it.
"""

import argparse
import json
import os
import re
from collections import Counter
from dataclasses import dataclass
from functools import lru_cache
from typing import Dict, List, Optional, Sequence, Tuple

# --------------------------------------------------------------------------
# Paths
# --------------------------------------------------------------------------

DATA_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "data")
BASE_DICT_PATH = os.path.join(DATA_DIR, "base_dict.json")
RAW_CORPUS_PATH = os.path.join(DATA_DIR, "raw_corpus.json")
ALIGNED_CORPUS_PATH = os.path.join(DATA_DIR, "aligned_corpus.json")
UNMATCHED_CORPUS_PATH = os.path.join(DATA_DIR, "unmatched_corpus.json")

# --------------------------------------------------------------------------
# Control codes
# --------------------------------------------------------------------------

TERMINATOR = "$"
PARAGRAPH_BREAK = "\\p"
NEWLINE = "\\n"
SCROLL = "\\l"

#: Every control code that must survive translation.
CONTROL_CODES = (PARAGRAPH_BREAK, NEWLINE, SCROLL, TERMINATOR)

#: Codes that merely break a line; ``\\n`` and ``\\l`` are interchangeable.
LINE_BREAKS = (NEWLINE, SCROLL)

#: Dictionary sub-objects that hold term -> translation mappings, in
#: precedence order (first definition of a key wins).
TERM_SECTIONS = ("species", "moves", "items", "abilities", "game_terms", "terms")

#: Key of the optional list of term keys that must never be auto-aligned.
AMBIGUOUS_TERMS_KEY = "ambiguous_terms"

_WHITESPACE_RE = re.compile(r"\s+")
_CONTROL_CODE_RE = re.compile(r"\\[npl]")
_PLACEHOLDER_RE = re.compile(r"\{[^{}]*\}")
_WORD_CHAR_CLASS = r"A-Za-z0-9"

# Match types, ordered by decreasing confidence.
MATCH_EXACT = "exact"
MATCH_DIALOGUE_SKELETON = "dialogue_skeleton"
MATCH_TERM = "term"

CONFIDENCE = {
    MATCH_EXACT: 1.0,
    MATCH_DIALOGUE_SKELETON: 0.99,
    MATCH_TERM: 0.9,
}


# --------------------------------------------------------------------------
# Skeleton normalization
# --------------------------------------------------------------------------


def normalize_skeleton(text: str) -> str:
    """Return the comparable skeleton of ``text``.

    Strips the control codes ``\\n``, ``\\l`` and ``\\p``, the ``$``
    terminator, and every whitespace character (spaces, tabs, real newlines),
    then case-folds the result.

    Punctuation *is* kept, so ``"POKéMON!"`` and ``"POKéMON"`` stay distinct.
    Variable placeholders are kept verbatim (case-folded) so that a match can
    never silently move or drop one.
    """
    if not text:
        return ""
    stripped = _CONTROL_CODE_RE.sub("", text)
    stripped = stripped.replace(TERMINATOR, "")
    stripped = _WHITESPACE_RE.sub("", stripped)
    return stripped.casefold()


def extract_placeholders(text: str) -> List[str]:
    """Return every ``{...}`` placeholder in ``text``, in order of appearance.

    Duplicates are preserved: ``"{PLAYER} {PLAYER}"`` yields two entries so
    that :func:`validate_placeholders_preserved` can catch a translation that
    only carries one of them.
    """
    if not text:
        return []
    return _PLACEHOLDER_RE.findall(text)


def validate_placeholders_preserved(source: str, translation: str) -> bool:
    """True when ``translation`` carries exactly the placeholders of ``source``.

    Both a missing and an extra placeholder fail: variables are substituted by
    the engine at runtime, so a translation can neither drop ``{RIVAL}`` nor
    invent one.
    """
    if translation is None:
        return False
    return Counter(extract_placeholders(source)) == Counter(extract_placeholders(translation))


def validate_control_codes_preserved(
    source: str, translation: str, *, strict_line_breaks: bool = False
) -> bool:
    """True when the translation is safe to drop into the ROM.

    Always required:

    * the placeholder multiset to be identical (see
      :func:`validate_placeholders_preserved`);
    * the same number of paragraph breaks (``\\p``);
    * the same number of string terminators (``$``).

    Line breaks (``\\n`` and ``\\l``) are **not** compared by default.  They
    are pure layout: the whole point of the skeleton is that the English
    script and the Chinese translation wrap their lines differently (Chinese
    is far more compact), so a re-flow is a legitimate translation, not a
    corruption.  What can never be lost is the ``$`` terminator (or the
    following string would be swallowed) and the ``\\p`` page break.

    Pass ``strict_line_breaks=True`` to demand the exact ``\\n`` / ``\\l``
    layout of the source as well; that mode is for auditing an already
    re-flowed translation, not for matching.
    """
    if translation is None:
        return False
    if not validate_placeholders_preserved(source, translation):
        return False
    if source.count(PARAGRAPH_BREAK) != translation.count(PARAGRAPH_BREAK):
        return False
    if source.count(TERMINATOR) != translation.count(TERMINATOR):
        return False
    if strict_line_breaks:
        for code in LINE_BREAKS:
            if source.count(code) != translation.count(code):
                return False
    return True


def repair_terminator(source: str, translation: str) -> str:
    """Append a missing ``$`` so the translation terminates like the source.

    Dictionary terms are stored without the terminator (``精灵球``), while a
    corpus string may be ``POKé BALL$``.  This is the only control code the
    aligner repairs automatically.
    """
    if not translation:
        return translation
    if source.rstrip().endswith(TERMINATOR) and not translation.rstrip().endswith(TERMINATOR):
        return translation.rstrip() + TERMINATOR
    return translation


# --------------------------------------------------------------------------
# Term substitution
# --------------------------------------------------------------------------


@lru_cache(maxsize=16)
def _compile_term_regex(items: Tuple[Tuple[str, str], ...]) -> re.Pattern:
    """Compile a whole-word, case-insensitive alternation over ``items``.

    Longest keys come first so that ``POKé BALL`` wins over ``POKé``.
    """
    ordered = sorted(items, key=lambda item: (-len(item[0]), item[0]))
    pattern = "|".join(re.escape(key) for key, _ in ordered)
    return re.compile(
        r"(?<![" + _WORD_CHAR_CLASS + r"])(" + pattern + r")(?![" + _WORD_CHAR_CLASS + r"])",
        re.IGNORECASE,
    )


def _mask_control_codes(text: str) -> str:
    """Blank out ``\\n`` / ``\\l`` / ``\\p`` with non-word filler.

    The trailing ``n`` of ``\\n`` is a word character, so a term sitting at the
    start of a line (``"...used\\nTACKLE!"``) would otherwise look like it is
    glued to a longer word and never match.  Each two-character code is
    replaced by two filler characters, keeping every offset identical so the
    match spans can still be applied to the original text.
    """
    return _CONTROL_CODE_RE.sub("\x00\x00", text)


def substitute_terms(text: str, terms: Dict[str, str]) -> str:
    """Replace every whole-word base-dictionary term found in ``text``.

    Used to build term hints for the translation stage and to spot strings
    fully covered by the dictionary.  Control codes and placeholders are never
    touched: only the matched term span is rewritten.  Words that merely
    contain a term (``POTIONS``) are left alone.
    """
    if not text or not terms:
        return text
    items = tuple(sorted(terms.items()))
    folded = {key.casefold(): value for key, value in items}
    regex = _compile_term_regex(items)

    pieces: List[str] = []
    cursor = 0
    for match in regex.finditer(_mask_control_codes(text)):
        pieces.append(text[cursor:match.start()])
        pieces.append(folded.get(match.group(1).casefold(), match.group(1)))
        cursor = match.end()
    pieces.append(text[cursor:])
    return "".join(pieces)


def find_terms(text: str, terms: Dict[str, str]) -> List[Tuple[str, str]]:
    """Return the ``(key, translation)`` term pairs occurring in ``text``."""
    if not text or not terms:
        return []
    items = tuple(sorted(terms.items()))
    folded = {key.casefold(): (key, value) for key, value in items}
    regex = _compile_term_regex(items)
    found: List[Tuple[str, str]] = []
    seen = set()
    for match in regex.finditer(_mask_control_codes(text)):
        pair = folded.get(match.group(1).casefold())
        if pair is not None and pair[0] not in seen:
            seen.add(pair[0])
            found.append(pair)
    return found


# --------------------------------------------------------------------------
# Engine
# --------------------------------------------------------------------------

@dataclass
class AlignmentResult:
    """A single successful alignment."""

    translation: str
    match_type: str
    matched_key: Optional[str] = None
    confidence: float = 1.0

    def as_dict(self) -> dict:
        return {
            "translation": self.translation,
            "match_type": self.match_type,
            "matched_key": self.matched_key,
            "confidence": self.confidence,
        }


def load_base_dict(path: str = BASE_DICT_PATH) -> dict:
    """Load ``base_dict.json`` as UTF-8."""
    with open(path, "r", encoding="utf-8") as fp:
        return json.load(fp)


def flatten_terms(base_dict: dict) -> Dict[str, str]:
    """Merge every term section of ``base_dict`` into one mapping.

    The first definition of a key wins, so the more specific species/move/item
    sections take precedence over the generic ``game_terms`` duplicates.
    """
    terms: Dict[str, str] = {}
    for section in TERM_SECTIONS:
        data = base_dict.get(section)
        if not isinstance(data, dict):
            continue
        for key, value in data.items():
            if isinstance(value, str) and value and key not in terms:
                terms[key] = value
    return terms


class AlignerEngine:
    """Match corpus strings against the base dictionary and HGSS dialogues."""

    def __init__(self, base_dict: Optional[dict] = None):
        self.base_dict = base_dict if base_dict is not None else {}

        self.terms = flatten_terms(self.base_dict)
        self.term_count = len(self.terms)

        #: Term keys that are too ambiguous to auto-align; they keep working as
        #: translation hints but are never emitted as an alignment.
        self.ambiguous_terms = {
            normalize_skeleton(key)
            for key in self.base_dict.get(AMBIGUOUS_TERMS_KEY, []) or []
            if isinstance(key, str)
        }

        # skeleton -> translation / display key
        self.term_index: Dict[str, str] = {}
        self.term_key_index: Dict[str, str] = {}
        for key, value in self.terms.items():
            skeleton = normalize_skeleton(key)
            if skeleton and skeleton not in self.term_index:
                self.term_index[skeleton] = value
                self.term_key_index[skeleton] = key

        # dialogues
        self.dialogue_exact: Dict[str, str] = {}
        self.dialogue_skeleton: Dict[str, str] = {}
        self.dialogue_count = 0
        for pair in self.base_dict.get("dialogues", []) or []:
            if not isinstance(pair, dict):
                continue
            english = pair.get("en")
            chinese = pair.get("zh")
            if not isinstance(english, str) or not isinstance(chinese, str):
                continue
            if not english or not chinese:
                continue
            self.dialogue_count += 1
            self.dialogue_exact.setdefault(english, chinese)
            skeleton = normalize_skeleton(english)
            if skeleton:
                self.dialogue_skeleton.setdefault(skeleton, chinese)

        self._cache: Dict[str, Optional[AlignmentResult]] = {}

    # -- construction helpers -------------------------------------------------

    @classmethod
    def from_file(cls, path: str = BASE_DICT_PATH, **kwargs) -> "AlignerEngine":
        return cls(load_base_dict(path), **kwargs)

    # -- lookups --------------------------------------------------------------

    def lookup_term(self, key: str) -> Optional[str]:
        """Return the translation registered for ``key`` (skeleton match)."""
        return self.term_index.get(normalize_skeleton(key))

    def align(self, text: str) -> Optional[AlignmentResult]:
        """Align one corpus string; ``None`` when nothing is known about it."""
        if not text:
            return None
        if text not in self._cache:
            self._cache[text] = self._align_uncached(text)
        return self._cache[text]

    def _align_uncached(self, text: str) -> Optional[AlignmentResult]:
        skeleton = normalize_skeleton(text)

        # 1. Verbatim dialogue hit.
        candidate = self.dialogue_exact.get(text)
        if candidate is not None and self._accept(text, candidate):
            return AlignmentResult(candidate, MATCH_EXACT, text, CONFIDENCE[MATCH_EXACT])

        # 2. Same dialogue modulo line wrapping / whitespace.
        if skeleton:
            candidate = self.dialogue_skeleton.get(skeleton)
            if candidate is not None and self._accept(text, candidate):
                return AlignmentResult(
                    candidate, MATCH_DIALOGUE_SKELETON, skeleton,
                    CONFIDENCE[MATCH_DIALOGUE_SKELETON],
                )

            # 3. The whole string is one dictionary term.  Only whole-string
            # equality counts: "POKéMON!" or "No!" are dialogue exclamations,
            # not the bare term, and translate differently in Chinese.
            if skeleton in self.term_index and skeleton not in self.ambiguous_terms:
                candidate = repair_terminator(text, self.term_index[skeleton])
                if self._accept(text, candidate):
                    return AlignmentResult(
                        candidate, MATCH_TERM, self.term_key_index[skeleton],
                        CONFIDENCE[MATCH_TERM],
                    )

        return None

    @staticmethod
    def _accept(source: str, translation: Optional[str]) -> bool:
        """Reject anything that would corrupt the source string."""
        if not translation:
            return False
        return validate_control_codes_preserved(source, translation)

    # -- batch ----------------------------------------------------------------

    def align_corpus(
        self, entries: Sequence[dict]
    ) -> Tuple[List[dict], List[dict]]:
        """Align a whole corpus, returning ``(aligned, unmatched)``.

        Every input field is preserved in the output entry.  Aligned entries
        gain ``translation``/``match_type``/``matched_key``/``confidence``;
        unmatched entries get ``translation: None`` plus ``term_hints`` listing
        the base-dictionary terms the string contains, to seed the translation
        stage.
        """
        aligned: List[dict] = []
        unmatched: List[dict] = []

        for entry in entries:
            source = entry.get("source", "")
            result = self.align(source)
            out = dict(entry)
            if result is not None:
                out.update(result.as_dict())
                aligned.append(out)
            else:
                out["translation"] = None
                out["match_type"] = None
                out["matched_key"] = None
                out["confidence"] = None
                out["reason"] = "NO_MATCH"
                hints = find_terms(source, self.terms)
                if hints:
                    out["term_hints"] = [[key, value] for key, value in hints]
                unmatched.append(out)

        return aligned, unmatched


# --------------------------------------------------------------------------
# CLI
# --------------------------------------------------------------------------


def _write_json(path: str, payload) -> None:
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as fp:
        json.dump(payload, fp, ensure_ascii=False, indent=2)


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(
        description="Align the extracted corpus against the HGSS base dictionary."
    )
    parser.add_argument("--base-dict", default=BASE_DICT_PATH, help="Base dictionary JSON.")
    parser.add_argument("--raw", default=RAW_CORPUS_PATH, help="Raw corpus JSON.")
    parser.add_argument("--aligned", default=ALIGNED_CORPUS_PATH, help="Aligned corpus output.")
    parser.add_argument("--unmatched", default=UNMATCHED_CORPUS_PATH, help="Unmatched corpus output.")
    args = parser.parse_args(argv)

    engine = AlignerEngine.from_file(args.base_dict)
    with open(args.raw, "r", encoding="utf-8") as fp:
        corpus = json.load(fp)

    aligned, unmatched = engine.align_corpus(corpus)

    _write_json(args.aligned, aligned)
    _write_json(args.unmatched, unmatched)

    total = len(corpus) or 1
    breakdown = Counter(entry["match_type"] for entry in aligned)
    print(f"base dictionary terms : {engine.term_count}")
    print(f"HGSS dialogues        : {engine.dialogue_count}")
    print(f"corpus entries        : {len(corpus)}")
    print(f"aligned               : {len(aligned)} ({len(aligned) * 100.0 / total:.2f}%)")
    for match_type, count in breakdown.most_common():
        print(f"    {match_type:<20}: {count}")
    print(f"unmatched             : {len(unmatched)}")
    print(f"written               : {args.aligned}")
    print(f"written               : {args.unmatched}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
