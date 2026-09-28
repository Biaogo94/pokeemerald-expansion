# -*- coding: utf-8 -*-
r"""HGSS alignment engine for the Heart & Soul Chinese localization pipeline.

The aligner reuses already-known Chinese text instead of machine-translating
everything from scratch.  Three sources of known text are supported, tried in
this order:

* ``zh_corpus.json`` -- the Chinese expansion fork's translations of the shared
  engine files (item names and descriptions, move descriptions, battle
  messages, system strings).  These are professional-quality, game-agnostic
  translations, so they outrank everything else.  They are addressed by the
  extractor's own identity, ``(file, label, index)``, and joined on it exactly:
  a zh translation is adopted only for the very entry it was extracted from,
  never by matching text to text.  See ``tools/i18n/zh_source.py``.
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

A ``zh_fork`` candidate is subject to exactly the same guard as every other
source, and is *dropped* -- not repaired, not guessed -- when it fails.  The
fork reflowed its copy of the engine files, so its ``\n`` layout legitimately
differs from HnS's; what must survive is ``$``, ``\p`` and the placeholder set.

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
ZH_CORPUS_PATH = os.path.join(DATA_DIR, "zh_corpus.json")

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
#: A translation taken from the Chinese expansion fork's copy of the same
#: engine file, joined on ``(file, label, index)``.  Its confidence sits above
#: the dictionary tier: it is a human translation of the very same string, not
#: a term substitution.
MATCH_ZH_FORK = "zh_fork"

CONFIDENCE = {
    MATCH_EXACT: 1.0,
    MATCH_DIALOGUE_SKELETON: 0.99,
    MATCH_ZH_FORK: 0.98,
    MATCH_TERM: 0.9,
}


# --------------------------------------------------------------------------
# Join keys
# --------------------------------------------------------------------------


def normalize_join_path(path: str) -> str:
    """Canonical form of a repository-relative path, for both sides of a join.

    The extractor emits ``./src/foo.c`` when it scans from ``.``, while
    ``zh_source.py`` stores the fork's paths without the ``./``.  Normalizing
    both sides here keeps ``(file, label, index)`` independent of which form a
    caller happens to hold.  :func:`join_key` applies it, so no caller has to.
    """
    normalized = path.replace("\\", "/")
    while normalized.startswith("./"):
        normalized = normalized[2:]
    return normalized


def join_key(file_path: str, label: str, index: int) -> Tuple[str, str, int]:
    """The identity shared by the HnS corpus and the fork corpus."""
    return (normalize_join_path(file_path), label, index)


def format_join_key(key: Tuple[str, str, int]) -> str:
    """``matched_key`` rendering of a :func:`join_key` triple."""
    return "%s:%s:%d" % key


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
    * the ``$`` terminator in the same *place*, not merely the same number of
      times: present at the end if and only if the source ends with one.  A
      translation that keeps the count but moves the terminator
      (``"$Hello"`` for ``"Hello$"``) truncates the string.
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
    # The terminator must sit where the source put it: present if and only if the
    # source ends with one.  A ``$`` that moved (``"$Hello"`` for ``"Hello$"``)
    # truncates the string at once, and a matching *count* alone hides that.
    # ``rstrip()`` first, as everywhere else in the pipeline: whitespace behind a
    # terminator is dead.
    if source.rstrip().endswith(TERMINATOR) != translation.rstrip().endswith(TERMINATOR):
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


def load_zh_corpus(path: str = ZH_CORPUS_PATH) -> List[dict]:
    """Load ``zh_corpus.json`` as UTF-8; ``[]`` when it has not been built yet.

    The fork corpus is generated by ``tools/i18n/zh_source.py``, so a fresh
    checkout may not have it.  Missing is not an error: it only means the
    highest-priority source is inactive.
    """
    if not os.path.exists(path):
        return []
    with open(path, "r", encoding="utf-8") as fp:
        data = json.load(fp)
    if not isinstance(data, list):
        raise ValueError("zh corpus %s is not a JSON list" % (path,))
    return data


def build_zh_index(entries: Sequence[dict]) -> Dict[Tuple[str, str, int], str]:
    """Index fork entries by ``(file, label, index)``.

    The first entry for a key wins, so the index is deterministic when a corpus
    is concatenated.  An entry missing any part of its identity is skipped
    rather than guessed at -- a translation with no key can never be joined.
    """
    index: Dict[Tuple[str, str, int], str] = {}
    for entry in entries:
        if not isinstance(entry, dict):
            continue
        file_path = entry.get("file")
        label = entry.get("label")
        position = entry.get("index")
        translation = entry.get("zh")
        if not isinstance(file_path, str) or not file_path:
            continue
        if not isinstance(label, str) or not label:
            continue
        if not isinstance(position, int) or isinstance(position, bool):
            continue
        if not isinstance(translation, str) or not translation:
            continue
        index.setdefault(join_key(file_path, label, position), translation)
    return index


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
    """Match corpus strings against the fork corpus, base dictionary and dialogues."""

    def __init__(
        self,
        base_dict: Optional[dict] = None,
        zh_corpus: Optional[Sequence[dict]] = None,
        zh_corpus_path: str = ZH_CORPUS_PATH,
    ):
        self.base_dict = base_dict if base_dict is not None else {}

        # The fork corpus is the highest-priority source, so it is loaded by
        # default; ``zh_corpus=[]`` disables it explicitly.
        if zh_corpus is None:
            zh_corpus = load_zh_corpus(zh_corpus_path)
        self.zh_index = build_zh_index(zh_corpus)
        self.zh_count = len(self.zh_index)

        #: Adoptions and rejections observed by the last :meth:`align_corpus`.
        self.zh_adopted = 0
        self.zh_dropped_by_guard = 0

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
    def from_file(
        cls,
        path: str = BASE_DICT_PATH,
        zh_corpus_path: str = ZH_CORPUS_PATH,
        **kwargs,
    ) -> "AlignerEngine":
        return cls(
            load_base_dict(path), zh_corpus_path=zh_corpus_path, **kwargs
        )

    # -- lookups --------------------------------------------------------------

    def lookup_term(self, key: str) -> Optional[str]:
        """Return the translation registered for ``key`` (skeleton match)."""
        return self.term_index.get(normalize_skeleton(key))

    def lookup_zh_fork(self, entry: dict) -> Optional[str]:
        """The fork's translation for ``entry``'s exact identity, or ``None``."""
        if not isinstance(entry, dict):
            return None
        file_path = entry.get("file")
        label = entry.get("label")
        position = entry.get("index")
        if not isinstance(file_path, str) or not file_path:
            return None
        if not isinstance(label, str) or not label:
            return None
        if not isinstance(position, int) or isinstance(position, bool):
            return None
        return self.zh_index.get(join_key(file_path, label, position))

    def align(self, text: str) -> Optional[AlignmentResult]:
        """Align one corpus string by *text*; ``None`` when nothing is known.

        Identity-based sources cannot be reached from a bare string, so this
        only consults the dialogues and the base dictionary.  Use
        :meth:`align_entry` for a corpus entry, which tries the fork corpus
        first.
        """
        if not text:
            return None
        if text not in self._cache:
            self._cache[text] = self._align_uncached(text)
        return self._cache[text]

    def align_entry(self, entry: dict) -> Optional[AlignmentResult]:
        """Align one corpus entry, fork corpus first, then :meth:`align`."""
        result = self._align_zh_fork(entry)
        if result is not None:
            return result
        return self.align(entry.get("source", "") or "")

    def _align_zh_fork(self, entry: dict) -> Optional[AlignmentResult]:
        """Adopt the fork's translation for this entry, if it survives the guard.

        The join is exact: the translation is only ever the one extracted from
        this very ``(file, label, index)``.  Nothing is fuzzy-matched, and a
        candidate that would lose a ``{PLACEHOLDER}``, a ``\\p`` or its ``$``
        terminator is dropped and counted rather than repaired -- the fork may
        legitimately have a different control-code set for the string, and
        guessing which one the ROM needs is how a string gets truncated.
        """
        candidate = self.lookup_zh_fork(entry)
        if candidate is None:
            return None
        source = entry.get("source", "") or ""
        if not self._accept(source, candidate):
            self.zh_dropped_by_guard += 1
            return None
        self.zh_adopted += 1
        return AlignmentResult(
            candidate,
            MATCH_ZH_FORK,
            format_join_key(
                join_key(entry["file"], entry["label"], entry["index"])
            ),
            CONFIDENCE[MATCH_ZH_FORK],
        )

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

        Sources are tried in precedence order, so a fork translation wins over
        a dialogue hit and a dictionary term for the same entry.  Counters for
        the fork tier are reset here and readable afterwards as
        :attr:`zh_adopted` and :attr:`zh_dropped_by_guard`.
        """
        aligned: List[dict] = []
        unmatched: List[dict] = []
        self.zh_adopted = 0
        self.zh_dropped_by_guard = 0

        for entry in entries:
            source = entry.get("source", "")
            result = self.align_entry(entry)
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
    parser.add_argument("--zh", default=ZH_CORPUS_PATH, help="Chinese fork corpus JSON.")
    parser.add_argument("--raw", default=RAW_CORPUS_PATH, help="Raw corpus JSON.")
    parser.add_argument("--aligned", default=ALIGNED_CORPUS_PATH, help="Aligned corpus output.")
    parser.add_argument("--unmatched", default=UNMATCHED_CORPUS_PATH, help="Unmatched corpus output.")
    args = parser.parse_args(argv)

    engine = AlignerEngine.from_file(args.base_dict, zh_corpus_path=args.zh)
    with open(args.raw, "r", encoding="utf-8") as fp:
        corpus = json.load(fp)

    aligned, unmatched = engine.align_corpus(corpus)

    _write_json(args.aligned, aligned)
    _write_json(args.unmatched, unmatched)

    total = len(corpus) or 1
    breakdown = Counter(entry["match_type"] for entry in aligned)
    print(f"zh fork translations  : {engine.zh_count}")
    print(f"base dictionary terms : {engine.term_count}")
    print(f"HGSS dialogues        : {engine.dialogue_count}")
    print(f"corpus entries        : {len(corpus)}")
    print(f"aligned               : {len(aligned)} ({len(aligned) * 100.0 / total:.2f}%)")
    for match_type, count in breakdown.most_common():
        print(f"    {match_type:<20}: {count}")
    print(f"zh fork dropped by guard: {engine.zh_dropped_by_guard}")
    print(f"unmatched             : {len(unmatched)}")
    print(f"written               : {args.aligned}")
    print(f"written               : {args.unmatched}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
