# -*- coding: utf-8 -*-
r"""Extract the Chinese expansion fork's translations into a joinable corpus.

Heart & Soul is built on ``rh-hideout/pokeemerald-expansion``.  The Chinese
fork (``rh-hideout-chinese/pokeemerald-expansion``) translated the *shared
engine files* -- item names and descriptions, move descriptions, battle
messages, system strings -- and those strings are game-agnostic: an item
description reads the same in Emerald or in Johto.  Reusing them beats machine
translation by a wide margin, so they become the aligner's highest-priority
source (see ``tools/i18n/aligner.py``).

The join key
------------
Nothing here is matched on text.  An entry is addressed by

    ``(file, label, index)``

which is exactly the identity ``extractor.py`` already stamps on every entry of
the HnS corpus (``id`` is ``"<file>:<label>:<index>"``).  That key is only
meaningful if **both refs are parsed by the same code**, so this module does not
re-implement any parsing: it hands the fork's file content to
``extractor.extract_strings_from_c`` / ``extractor.extract_strings_from_inc``,
the very functions that produced the HnS corpus.  Block boundaries, label
synthesis and index assignment are therefore identical by construction.

Kept only when it is really Chinese
-----------------------------------
An entry survives only if its extracted text contains a CJK Unified Ideograph
(U+4E00-U+9FFF).  That one filter is enough to drop the fork's untranslated
strings -- ``src/data/text/radio_strings.h`` is English-only in the fork and
yields zero entries -- without a per-file allowlist that would go stale.

Refused blocks
--------------
Two shapes make the extractor's ``source`` not a string the ROM ever builds,
and the injector refuses both.  No fork translation is adopted for them, and
they are counted separately in the stats:

``spliced``
    Nine blocks in ``src/data/moves_info.h`` splice a macro *inside* the string
    (``"for "BINDING_TURNS" turns."``).  To the compiler that is one string; to
    the extractor it is two adjacent literals, so the ``source`` silently loses
    the macro (``for  turns.``).
``guarded``
    An ``#if``/``#else``/``#endif`` runs through the block, so the ``source``
    concatenates *both* branches
    (``"May lower Sp. Def.May lower Defense."``).

Both are detected with the injector's own predicates -- ``_is_guarded_block``
and ``_C_GAP_LAYOUT_RE`` over the literal gaps -- rather than a restatement
that could drift.  The fork reflowed its copy, so the check runs on both refs.

Output schema (``zh_corpus.json``)::

    {"file": "src/data/moves_info.h", "label": "MOVE_TACKLE.description",
     "index": 0, "zh": "用整个身体\\n撞向对手进行攻击。", "ref": "remotes/zh/master"}

CLI::

    python tools/i18n/zh_source.py --ref remotes/zh/master \
        --output tools/i18n/data/zh_corpus.json
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
from dataclasses import dataclass, field
from typing import Dict, List, Optional, Sequence, Set, Tuple

# Running as a script puts ``tools/i18n`` -- not the repository root -- on
# ``sys.path``; put the root back so ``tools.i18n`` imports resolve to the same
# module objects as ``python -m``.
_REPO_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
if _REPO_ROOT not in sys.path:
    sys.path.insert(0, _REPO_ROOT)

from tools.i18n.aligner import normalize_join_path  # noqa: E402
from tools.i18n.extractor import (  # noqa: E402  (import after sys.path bootstrap)
    _default_c_category,
    _iter_c_files,
    _iter_inc_files,
    _mask_comments,
    _read,
    extract_strings_from_c,
    extract_strings_from_inc,
)
from tools.i18n.injector import (  # noqa: E402  (import after sys.path bootstrap)
    _C_GAP_LAYOUT_RE,
    _is_guarded_block,
    _literal_bodies,
    _locate_c_macros,
    _PREPROC_RE,
    _splice_with_index_map,
)

# --------------------------------------------------------------------------
# Constants
# --------------------------------------------------------------------------

HERE = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.join(HERE, "data")
DEFAULT_REF = "remotes/zh/master"
DEFAULT_OUTPUT = os.path.join(DATA_DIR, "zh_corpus.json")

#: The one range that decides "this entry is Chinese": CJK Unified Ideographs.
#: Deliberately narrow -- kana, full-width punctuation and CJK punctuation are
#: *not* accepted on their own, so a string that merely contains a full-width
#: comma stays out.
CJK_UNIFIED_RANGE: Tuple[int, int] = (0x4E00, 0x9FFF)

#: The two extraction dialects, keyed by the extractor entry point used.
KIND_INC = "inc"
KIND_C = "c"


def has_cjk(text: str) -> bool:
    """True when ``text`` contains a CJK Unified Ideograph (U+4E00-U+9FFF)."""
    if not text:
        return False
    low, high = CJK_UNIFIED_RANGE
    return any(low <= ord(ch) <= high for ch in text)


def normalize_path(path: str) -> str:
    """Canonical form of a repository-relative path, for both sides of the join.

    The extractor emits ``./src/foo.c`` when it scans from ``.``; a path taken
    straight from ``git ls-tree`` has no ``./``.  The canonicalization lives in
    ``aligner.normalize_join_path`` -- the module that performs the join -- so
    this corpus and the aligner can never disagree about a key.
    """
    return normalize_join_path(path)


# --------------------------------------------------------------------------
# Reading the fork's files
# --------------------------------------------------------------------------


class RefReader:
    """Minimal protocol: ``list_paths()`` and ``read_many(paths)``."""

    def list_paths(self) -> Set[str]:  # pragma: no cover - interface
        raise NotImplementedError

    def read_many(self, paths: Sequence[str]) -> Dict[str, str]:  # pragma: no cover
        raise NotImplementedError


class GitRefReader(RefReader):
    """Read blob contents out of a git ref without a working tree checkout.

    ``git ls-tree`` gives the ref's file set once, so files the fork never had
    are skipped without a failed subprocess each; ``git cat-file --batch`` then
    streams every blob that *is* wanted in a single invocation.  On Windows a
    subprocess spawn is expensive enough that one-per-file would dominate the
    run, and the fork has ~1000 text files.
    """

    def __init__(self, ref: str, repo_root: str = "."):
        self.ref = ref
        self.repo_root = repo_root
        self._paths: Optional[Set[str]] = None
        self._cache: Dict[str, str] = {}

    def _git(self, args: Sequence[str], payload: Optional[bytes] = None):
        return subprocess.run(
            ["git", "-C", self.repo_root] + list(args),
            input=payload,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=False,
        )

    def list_paths(self) -> Set[str]:
        if self._paths is None:
            result = self._git(["ls-tree", "-r", "--name-only", self.ref])
            if result.returncode != 0:
                raise RuntimeError(
                    "git ls-tree %s failed: %s"
                    % (self.ref, result.stderr.decode("utf-8", "replace").strip())
                )
            self._paths = set(
                result.stdout.decode("utf-8", "replace").splitlines()
            )
        return self._paths

    def read_many(self, paths: Sequence[str]) -> Dict[str, str]:
        known = self.list_paths()
        wanted = [p for p in paths if p in known and p not in self._cache]
        if wanted:
            payload = "".join(
                "%s:%s\n" % (self.ref, path) for path in wanted
            ).encode("utf-8")
            result = self._git(["cat-file", "--batch"], payload)
            if result.returncode != 0:
                raise RuntimeError(
                    "git cat-file --batch failed: %s"
                    % result.stderr.decode("utf-8", "replace").strip()
                )
            self._consume_batch(result.stdout, wanted)
        return {path: self._cache[path] for path in paths if path in self._cache}

    def _consume_batch(self, blob: bytes, wanted: Sequence[str]) -> None:
        """Parse ``<sha> <type> <size>\\n<content>\\n`` records in request order."""
        position = 0
        length = len(blob)
        for index, path in enumerate(wanted):
            newline = blob.find(b"\n", position)
            if newline == -1:
                break
            header = blob[position:newline].decode("utf-8", "replace")
            position = newline + 1
            parts = header.split(" ")
            if len(parts) < 3:
                # ``<object> missing`` -- the path came from ls-tree, so this is
                # a race against a ref update, not a normal outcome.
                continue
            try:
                size = int(parts[2])
            except ValueError:
                continue
            content = blob[position : position + size]
            position += size + 1  # the record's trailing newline
            self._cache[path] = content.decode("utf-8", "replace")


class MappingRefReader(RefReader):
    """A ref backed by an in-memory ``{path: content}`` mapping (tests)."""

    def __init__(self, files: Dict[str, str]):
        self.files = {normalize_path(path): text for path, text in files.items()}

    def list_paths(self) -> Set[str]:
        return set(self.files)

    def read_many(self, paths: Sequence[str]) -> Dict[str, str]:
        return {
            path: self.files[normalize_path(path)]
            for path in paths
            if normalize_path(path) in self.files
        }


# --------------------------------------------------------------------------
# Refused blocks
# --------------------------------------------------------------------------


#: Why a block can never be written back, using the injector's own vocabulary
#: and its own precedence (guarded first, then the literal-gap check).
REFUSAL_GUARDED = "guarded"
REFUSAL_SPLICED = "spliced"


def unusable_c_keys(
    file_path: str, content: str, category: Optional[str] = None
) -> Optional[Dict[Tuple[str, int], str]]:
    """Keys whose extracted ``source`` is not a string that can be translated.

    Two shapes defeat the extractor, and both are refused by the injector:

    ``spliced``
        A macro sits between two adjacent literals
        (``"for "BINDING_TURNS" turns."``).  The extractor concatenates
        literals only, so the ``source`` silently loses the macro.  The
        injector's ``_C_GAP_LAYOUT_RE`` over the literal gaps is the predicate;
        it is reused here rather than restated.
    ``guarded``
        An ``#if``/``#else``/``#endif`` runs through the block, so the
        ``source`` concatenates *both* branches into one nonsense string
        (``"May lower Sp. Def.May lower Defense."``).

    Either way the extracted text is not a string the ROM ever builds, so no
    fork translation may be adopted for it.

    Returns ``None`` when the entry count and the located-macro count disagree:
    the two scans can then not be correlated positionally, and the caller must
    treat the whole file as unsupported rather than guess.
    """
    if category is None:
        category = _default_c_category(file_path)

    # Mirrors ``injector._inject_c``: splice continuations with an offset map,
    # mask comments (one-for-one, so the map survives), then locate macros.
    spliced_text, index_map = _splice_with_index_map(content)
    text = _mask_comments(spliced_text)
    located = _locate_c_macros(text)
    entries = extract_strings_from_c(file_path, content, category)
    if len(entries) != len(located):
        return None

    lines = content.split("\n")
    directive_lines = [bool(_PREPROC_RE.match(line)) for line in lines]

    unusable: Dict[Tuple[str, int], str] = {}
    for entry, (macro_start, open_paren, close) in zip(entries, located):
        if close == -1:
            continue
        start_line = content.count("\n", 0, index_map[macro_start])
        end_line = content.count("\n", 0, index_map[close - 1])
        if _is_guarded_block(directive_lines, start_line, start_line, end_line + 1):
            unusable[(entry.label, entry.index)] = REFUSAL_GUARDED
            continue
        bodies = _literal_bodies(text, open_paren + 1, close - 1)
        # ``_literal_bodies`` reports the *contents* of each literal, so the
        # closing quote sits at ``bodies[i][1]`` and the next opening quote at
        # ``bodies[i + 1][0] - 1``.  The gap is strictly between them -- the same
        # span ``injector._inject_c`` calls a gap.
        for index in range(len(bodies) - 1):
            gap = text[bodies[index][1] + 1 : bodies[index + 1][0] - 1]
            if not _C_GAP_LAYOUT_RE.match(gap):
                unusable[(entry.label, entry.index)] = REFUSAL_SPLICED
                break
    return unusable


# --------------------------------------------------------------------------
# Extraction
# --------------------------------------------------------------------------


@dataclass
class ZhCorpusStats:
    """Everything the report needs to explain what was and was not taken."""

    files_present_in_ref: int = 0
    files_scanned: int = 0
    files_with_entries: int = 0
    extracted: int = 0
    #: Entries dropped because a macro sits between the block's literals, so the
    #: extracted source is not the whole string (``"for "BINDING_TURNS" turns."``).
    dropped_spliced: int = 0
    #: Entries dropped because a preprocessor conditional runs through the block,
    #: so the extracted source concatenates both branches.
    dropped_guarded: int = 0
    #: Entries dropped because the join key does not exist on the HnS side.
    dropped_unjoinable: int = 0
    #: Files skipped because their two scans could not be correlated.
    dropped_uncorrelated: int = 0
    per_file: Dict[str, int] = field(default_factory=dict)

    def as_dict(self) -> dict:
        return {
            "files_present_in_ref": self.files_present_in_ref,
            "files_scanned": self.files_scanned,
            "files_with_entries": self.files_with_entries,
            "extracted": self.extracted,
            "dropped_spliced": self.dropped_spliced,
            "dropped_guarded": self.dropped_guarded,
            "dropped_unjoinable": self.dropped_unjoinable,
            "dropped_uncorrelated": self.dropped_uncorrelated,
        }


def _make_entry(file_path: str, label: str, index: int, zh: str, ref: str) -> dict:
    return {
        "file": normalize_path(file_path),
        "label": label,
        "index": index,
        "zh": zh,
        "ref": ref,
    }


def extract_zh_entries_from_c(
    file_path: str,
    zh_content: str,
    hs_content: str,
    ref: str,
    category: Optional[str] = None,
) -> Tuple[List[dict], Dict[str, int]]:
    """CJK-bearing fork entries of one C file that are safe to adopt.

    ``hs_content`` is the working tree's own copy of the file.  It supplies the
    set of join keys that actually exist on the HnS side and the literal-gap
    check that marks the spliced blocks.
    """
    if category is None:
        category = _default_c_category(file_path)

    counts = {"spliced": 0, "guarded": 0, "unjoinable": 0, "uncorrelated": 0}

    hs_entries = extract_strings_from_c(file_path, hs_content, category)
    hs_keys = {(entry.label, entry.index) for entry in hs_entries}

    unusable_hs = unusable_c_keys(file_path, hs_content, category)
    unusable_zh = unusable_c_keys(file_path, zh_content, category)
    if unusable_hs is None or unusable_zh is None:
        counts["uncorrelated"] = 1
        return [], counts
    unusable = dict(unusable_hs)
    unusable.update(unusable_zh)

    entries: List[dict] = []
    for entry in extract_strings_from_c(file_path, zh_content, category):
        if not has_cjk(entry.source):
            continue
        key = (entry.label, entry.index)
        if key in unusable:
            counts[unusable[key]] += 1
            continue
        if key not in hs_keys:
            counts["unjoinable"] += 1
            continue
        entries.append(
            _make_entry(file_path, entry.label, entry.index, entry.source, ref)
        )
    return entries, counts


def extract_zh_entries_from_inc(
    file_path: str, zh_content: str, hs_content: str, ref: str
) -> Tuple[List[dict], Dict[str, int]]:
    """CJK-bearing fork entries of one ``.inc`` file that are safe to adopt."""
    counts = {"spliced": 0, "guarded": 0, "unjoinable": 0, "uncorrelated": 0}

    hs_keys = {
        (entry.label, entry.index)
        for entry in extract_strings_from_inc(file_path, hs_content)
    }

    entries: List[dict] = []
    for entry in extract_strings_from_inc(file_path, zh_content):
        if not has_cjk(entry.source):
            continue
        if (entry.label, entry.index) not in hs_keys:
            counts["unjoinable"] += 1
            continue
        entries.append(
            _make_entry(file_path, entry.label, entry.index, entry.source, ref)
        )
    return entries, counts


# --------------------------------------------------------------------------
# Corpus build
# --------------------------------------------------------------------------


def _target_files(root: str) -> List[Tuple[str, str, str]]:
    """``(path, kind, category)`` for every file the extractor scans.

    The same roots ``extractor.scan_repository`` walks, so the fork corpus can
    only ever contain files the HnS corpus also covers.
    """
    targets: List[Tuple[str, str, str]] = []
    for path in _iter_inc_files(root):
        targets.append((normalize_path(path), KIND_INC, ""))
    for path, category in _iter_c_files(root):
        targets.append((normalize_path(path), KIND_C, category))
    return targets


def build_zh_corpus(
    ref: str = DEFAULT_REF,
    root: str = ".",
    reader: Optional[RefReader] = None,
    targets: Optional[Sequence[Tuple[str, str, str]]] = None,
) -> Tuple[List[dict], ZhCorpusStats]:
    """Build the fork corpus, returning ``(entries, stats)``.

    ``reader`` defaults to :class:`GitRefReader` over ``ref``; pass a
    :class:`MappingRefReader` to run the same extraction without git.
    """
    if reader is None:
        reader = GitRefReader(ref, root)

    if targets is None:
        targets = _target_files(root)

    stats = ZhCorpusStats()
    stats.files_present_in_ref = len(reader.list_paths())

    available = [
        (path, kind, category)
        for path, kind, category in targets
        if normalize_path(path) in reader.list_paths()
    ]
    contents = reader.read_many([path for path, _kind, _category in available])

    entries: List[dict] = []
    for path, kind, category in available:
        zh_content = contents.get(path)
        if zh_content is None:
            continue
        hs_content = _read(os.path.join(root, path))
        if hs_content is None:
            continue
        stats.files_scanned += 1

        if kind == KIND_INC:
            found, counts = extract_zh_entries_from_inc(
                path, zh_content, hs_content, ref
            )
        else:
            found, counts = extract_zh_entries_from_c(
                path, zh_content, hs_content, ref, category or None
            )

        stats.dropped_spliced += counts["spliced"]
        stats.dropped_guarded += counts["guarded"]
        stats.dropped_unjoinable += counts["unjoinable"]
        stats.dropped_uncorrelated += counts["uncorrelated"]
        if found:
            stats.files_with_entries += 1
            stats.per_file[path] = len(found)
        stats.extracted += len(found)
        entries.extend(found)

    return entries, stats


# --------------------------------------------------------------------------
# CLI
# --------------------------------------------------------------------------


def write_corpus(path: str, entries: Sequence[dict]) -> None:
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    with open(path, "w", encoding="utf-8") as handle:
        json.dump(list(entries), handle, ensure_ascii=False, indent=2)


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(
        description="Extract the Chinese expansion fork's translations."
    )
    parser.add_argument("--ref", default=DEFAULT_REF, help="Git ref to read.")
    parser.add_argument("--output", default=DEFAULT_OUTPUT, help="Output JSON.")
    parser.add_argument("--root", default=".", help="Working tree root.")
    parser.add_argument(
        "--stats", default=None, help="Optional path to write the stats JSON."
    )
    args = parser.parse_args(argv)

    entries, stats = build_zh_corpus(ref=args.ref, root=args.root)
    write_corpus(args.output, entries)

    print("ref                   : %s" % args.ref)
    print("files in ref          : %d" % stats.files_present_in_ref)
    print("files scanned         : %d" % stats.files_scanned)
    print("files with zh entries : %d" % stats.files_with_entries)
    print("entries extracted     : %d" % stats.extracted)
    print("dropped (spliced)     : %d" % stats.dropped_spliced)
    print("dropped (guarded)     : %d" % stats.dropped_guarded)
    print("dropped (unjoinable)  : %d" % stats.dropped_unjoinable)
    print("dropped (uncorrelated): %d" % stats.dropped_uncorrelated)
    print("written               : %s" % args.output)

    if args.stats:
        with open(args.stats, "w", encoding="utf-8") as handle:
            json.dump(stats.as_dict(), handle, ensure_ascii=False, indent=2)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
