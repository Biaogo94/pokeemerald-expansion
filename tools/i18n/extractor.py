"""Extract localizable strings from the pokeemerald-expansion source tree.

The corpus is the input to the rest of the i18n pipeline (``aligner.py``,
``ai_translator.py``, ``injector.py``), so the output schema is frozen::

    {"id", "file", "label", "index", "source", "category"}

Two very different source dialects are covered.

``.inc`` script data (``data/maps/*.inc``, ``data/text/*.inc``)
    A label followed by a run of ``.string "..."`` lines.  The run ends at the
    first line that is not a ``.string`` line -- in particular at any
    ``#if``/``#else``/``#elif``/``#endif``.  That mirrors
    ``injector._parse_inc_blocks`` exactly; when the two disagreed on where a
    block stopped, ``(label, index)`` addressed a different string for the
    injector than for the extractor and the entry could never be translated.

C sources (``src/``)
    Text lives in macro invocations -- ``_("...")``, ``COMPOUND_STRING(...)``,
    ``ITEM_NAME(...)``, ``ITEM_PLURAL_NAME(...)`` and
    ``COMPOUND_STRING_SIZE_LIMIT(..., LIMIT)``.  Long strings are written as
    several adjacent C literals (sometimes split with backslash line
    continuations); they are concatenated into one logical string here, because
    a one-literal-at-a-time regex loses almost all of ``src/data/items.h`` and
    ``src/data/moves_info.h``.

Each C entry gets a label that addresses it:

* array declaration  ``sText_Foo[] = _("...")``  -> ``sText_Foo``
* struct field       ``[ITEM_POKE_BALL] = { .description = COMPOUND_STRING(...) }``
                     -> ``ITEM_POKE_BALL.description``
* ``#define Foo <macro>(...)`` -> ``Foo``
* anything else -> the enclosing container's name plus a running index

The C ``index`` is the file-global ordinal of the macro invocation, which is
what ``injector._inject_c`` counts; empty and non-meaningful strings still
advance it so the numbering never shifts.
"""

import argparse
import glob
import json
import os
import re
from dataclasses import asdict, dataclass
from typing import Dict, Iterator, List, Optional, Sequence, Tuple

# --------------------------------------------------------------------------
# Output model
# --------------------------------------------------------------------------


@dataclass
class ExtractedEntry:
    id: str
    file: str
    label: str
    index: int
    source: str
    category: str


#: Categories.  ``c_source`` is kept for the pre-existing ``src/data/text``
#: roots so their entries (and indices) are unchanged; the engine text files
#: added later get their own category.
MAP_SCRIPT_CATEGORY = "map_script"
TEXT_DATA_CATEGORY = "text_data"
C_SOURCE_CATEGORY = "c_source"
ENGINE_C_CATEGORY = "engine_c"

#: ``src`` roots that keep the historical ``c_source`` category.
LEGACY_C_CATEGORY_PATHS = ("src/data/text/",)


def is_meaningful_string(s: str) -> bool:
    cleaned = s.replace("$", "").strip()
    if not cleaned:
        return False
    # Check if contains letters or numbers
    if not any(c.isalnum() for c in cleaned):
        return False
    return True


def _entry_id(file_path: str, label: str, index: int) -> str:
    return f"{file_path}:{label}:{index}"


# --------------------------------------------------------------------------
# .inc extraction
# --------------------------------------------------------------------------

_INC_LABEL_RE = re.compile(r"^([A-Za-z0-9_]+)::")
_INC_SINGLE_LABEL_RE = re.compile(r"^([A-Za-z0-9_]+):")
_INC_STRING_RE = re.compile(r'^\s*\.string\s+"(.*)"\s*$')


def extract_strings_from_inc(file_path: str, content: str) -> List[ExtractedEntry]:
    """Extract ``.string`` blocks from an ``.inc`` script file.

    A block is a maximal run of consecutive ``.string`` lines inside one label,
    cut short once the accumulated text ends with ``$``.  Any other line ends
    the run, so a ``#if``/``#else``/``#endif`` between two strings yields two
    blocks -- the same two the injector sees.
    """
    entries: List[ExtractedEntry] = []
    category = MAP_SCRIPT_CATEGORY if "maps" in file_path else TEXT_DATA_CATEGORY
    lines = content.splitlines()
    count = len(lines)

    label: Optional[str] = None
    index = 0
    i = 0
    while i < count:
        line = lines[i]

        label_match = _INC_LABEL_RE.match(line) or _INC_SINGLE_LABEL_RE.match(line)
        if label_match:
            label = label_match.group(1)
            index = 0
            i += 1
            continue

        if label is not None and _INC_STRING_RE.match(line):
            parts: List[str] = []
            while i < count:
                inner = _INC_STRING_RE.match(lines[i])
                if not inner:
                    break
                parts.append(inner.group(1))
                i += 1
                if "".join(parts).endswith("$"):
                    break
            text = "".join(parts)
            if is_meaningful_string(text):
                entries.append(
                    ExtractedEntry(
                        _entry_id(file_path, label, index),
                        file_path,
                        label,
                        index,
                        text,
                        category,
                    )
                )
                index += 1
            continue

        i += 1

    return entries


# --------------------------------------------------------------------------
# C extraction
# --------------------------------------------------------------------------

#: Longest name first: ``COMPOUND_STRING`` must not match the prefix of
#: ``COMPOUND_STRING_SIZE_LIMIT``.  ``_`` is matched separately because no other
#: macro starts with it.
_C_MACRO_RE = re.compile(
    r"(?<![A-Za-z0-9_])(?:COMPOUND_STRING_SIZE_LIMIT|COMPOUND_STRING|ITEM_PLURAL_NAME|ITEM_NAME)\s*\("
    r"|(?<![A-Za-z0-9_])_\s*\("
)

_C_CONTINUATION_RE = re.compile(r"\\\r?\n")
_C_DEFINE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_][A-Za-z0-9_]*)")
#: ``gFoo[] =`` / ``gFoo[LIMIT] =`` / ``gFoo[][3] =`` -- the declared container.
_C_ARRAY_TAIL_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[[^\]]*\]\s*)+=\s*$")
#: ``[ITEM_POKE_BALL] =`` / ``[EC_INDEX(EC_WORD_DARK)] =`` -- the row being
#: declared.  The last identifier inside the brackets is the usable one, so a
#: wrapped designator still yields ``EC_WORD_DARK`` rather than ``EC_INDEX``.
_C_DESIGNATOR_TAIL_RE = re.compile(r"\[([^\[\]]*)\]\s*=\s*$")
_C_IDENTIFIER_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
_C_FIELD_TAIL_RE = re.compile(r"\.\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*$")


def _declared_tail(text: str) -> Tuple[Optional[str], Optional[str]]:
    """Classify the declaration a fragment ends with.

    The array form is tested first: in ``const u8 gFoo[LIMIT] =`` the brackets
    belong to the container name, not to a designator.
    """
    match = _C_ARRAY_TAIL_RE.search(text)
    if match:
        return "array", match.group(1)

    match = _C_DESIGNATOR_TAIL_RE.search(text)
    if match:
        identifiers = _C_IDENTIFIER_RE.findall(match.group(1))
        if identifiers:
            return "designator", identifiers[-1]

    return None, None


def _splice_continuations(text: str) -> str:
    """Apply C translation phase 2: a backslash-newline is removed entirely.

    This is what makes ``#define X \\`` + ``COMPOUND_STRING(...)`` one
    declaration again.
    """
    return _C_CONTINUATION_RE.sub("", text)


def _mask_comments(text: str) -> str:
    """Blank out ``//`` and ``/* */`` comments, keeping the text length.

    Commented-out code is common in this tree; without masking it would be
    extracted as if it were live text.  String and character literals are
    skipped so a ``"//"`` inside a string survives.
    """
    out = list(text)
    i = 0
    n = len(text)
    while i < n:
        ch = text[i]
        if ch == '"' or ch == "'":
            quote = ch
            i += 1
            while i < n:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == quote:
                    i += 1
                    break
                i += 1
            continue
        if ch == "/" and i + 1 < n:
            nxt = text[i + 1]
            if nxt == "/":
                end = text.find("\n", i)
                end = n if end == -1 else end
                for k in range(i, end):
                    out[k] = " "
                i = end
                continue
            if nxt == "*":
                found = text.find("*/", i + 2)
                end = n if found == -1 else found + 2
                for k in range(i, end):
                    if out[k] != "\n":
                        out[k] = " "
                i = end
                continue
        i += 1
    return "".join(out)


def _close_paren(text: str, open_index: int) -> int:
    """Index just past the ``)`` matching ``text[open_index] == '('``, or -1."""
    depth = 0
    i = open_index
    n = len(text)
    while i < n:
        ch = text[i]
        if ch == '"' or ch == "'":
            quote = ch
            i += 1
            while i < n:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == quote:
                    i += 1
                    break
                i += 1
            continue
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return -1


def _string_literals(text: str) -> List[str]:
    """Raw contents (escapes untouched) of every string literal in ``text``."""
    literals: List[str] = []
    i = 0
    n = len(text)
    while i < n:
        ch = text[i]
        if ch == "'":
            i += 1
            while i < n:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == "'":
                    i += 1
                    break
                i += 1
            continue
        if ch == '"':
            i += 1
            start = i
            buf: List[str] = []
            while i < n:
                if text[i] == "\\" and i + 1 < n:
                    buf.append(text[i : i + 2])
                    i += 2
                    continue
                if text[i] == '"':
                    i += 1
                    break
                buf.append(text[i])
                i += 1
            literals.append("".join(buf))
            continue
        i += 1
    return literals


@dataclass
class _Frame:
    """One brace scope, carrying whatever names the entries inside it."""

    designator: Optional[str] = None
    name: Optional[str] = None
    count: int = 0

    @property
    def owner(self) -> Optional[str]:
        return self.designator or self.name


def _owner_frame(stack: Sequence[_Frame]) -> Optional[_Frame]:
    for frame in reversed(stack):
        if frame.owner:
            return frame
    return None


def _statement_context(line_prefix: str, line: str) -> Tuple[Optional[str], Optional[str]]:
    """Classify what ``line_prefix`` -- the text before a macro call -- is.

    Returns ``(kind, value)`` where kind is one of ``designator``, ``field``,
    ``array``, ``define`` or ``None``.
    """
    kind, value = _declared_tail(line_prefix)
    if kind:
        return kind, value

    match = _C_FIELD_TAIL_RE.search(line_prefix)
    if match:
        return "field", match.group(1)

    match = _C_DEFINE_RE.match(line)
    if match:
        return "define", match.group(1)

    return None, None


def _declaration_kind(line: str) -> Tuple[Optional[str], Optional[str]]:
    """Classify a line that declares a container, e.g. ``[ITEM_X] =``.

    Such a line has no macro on it, so it is invisible to
    :func:`_statement_context`; the name it introduces has to be remembered
    until the ``{`` that opens the initializer shows up.
    """
    stripped = line.rstrip()
    if not stripped.endswith("="):
        return None, None
    return _declared_tail(stripped)


def _label_for(
    kind: Optional[str],
    value: Optional[str],
    stack: Sequence[_Frame],
    pending: _Frame,
    ordinal: int,
) -> Tuple[str, Optional[_Frame]]:
    """Resolve a stable, unique label.  Returns ``(label, frame_to_count)``."""
    owner = _owner_frame(stack)

    if kind == "field":
        if owner is not None:
            return f"{owner.owner}.{value}", None
        return f"__field_{value}__{ordinal}", None

    if kind in ("array", "define"):
        return value, None

    if kind == "designator":
        if owner is not None:
            return f"{owner.owner}.{value}", None
        return value, None

    if owner is not None:
        # A bare entry inside a container: number it within that container, so
        # the counter lives on the frame that supplies the name.
        index = owner.count
        return f"{owner.owner}[{index}]", owner

    if pending.owner:
        # ``NAME[] =`` on one line, the initializer on the next.
        return pending.owner, None

    return f"__text_{ordinal}", None


#: Characters that structure a C file: braces open scopes, ``;`` ends a
#: declaration.  Quotes start literals and are handled by the scanner.
_STRUCTURE_RE = re.compile(r"[\"'{};]")


def _skip_literal(text: str, index: int) -> int:
    """Index just past the string or character literal starting at ``index``."""
    quote = text[index]
    i = index + 1
    n = len(text)
    while i < n:
        if text[i] == "\\":
            i += 2
            continue
        if text[i] == quote:
            return i + 1
        i += 1
    return n


def _structural_events(text: str) -> List[Tuple[int, str, Optional[re.Match]]]:
    """Every brace, semicolon and text-macro call, in source order.

    Braces inside string literals (``COMPOUND_STRING("{PLAYER}...")``) are not
    structure and must not open or close a scope, so the scan skips literals.
    """
    events: List[Tuple[int, str, Optional[re.Match]]] = []

    i = 0
    while True:
        match = _STRUCTURE_RE.search(text, i)
        if match is None:
            break
        ch = match.group()
        if ch in "\"'":
            i = _skip_literal(text, match.start())
            continue
        events.append((match.start(), "open" if ch == "{" else "close" if ch == "}" else "semi", None))
        i = match.start() + 1

    for match in _C_MACRO_RE.finditer(text):
        events.append((match.start(), "macro", match))

    events.sort(key=lambda item: item[0])
    return events


def extract_strings_from_c(
    file_path: str, content: str, category: Optional[str] = None
) -> List[ExtractedEntry]:
    """Extract every text macro invocation in a C source file.

    Adjacent string literals are concatenated, so a
    ``COMPOUND_STRING("a\\n" "b")`` split across lines becomes one entry.

    ``index`` counts occurrences of the entry's own label, the same convention
    the ``.inc`` extractor uses.  It is the minimal disambiguator, and it stays
    stable when an unrelated macro call is added or removed above it -- which is
    what lets the same ``(file, label, index)`` key join two refs of a file.
    The legacy ``src/data/text`` roots are the one exception: their committed
    injection corpus was numbered with the file-global macro ordinal that
    ``injector._inject_c`` matches against, so they keep that numbering.
    """
    if category is None:
        category = _default_c_category(file_path)

    global_index = category == C_SOURCE_CATEGORY

    text = _mask_comments(_splice_continuations(content))
    events = _structural_events(text)

    entries: List[ExtractedEntry] = []
    label_counts: Dict[str, int] = {}
    stack: List[_Frame] = []
    pending = _Frame()
    ordinal = 0
    cursor = 0
    line_start = 0
    n = len(text)

    while line_start <= n:
        newline = text.find("\n", line_start)
        line_end = n if newline == -1 else newline
        line = text[line_start:line_end]

        decl_kind, decl_value = _declaration_kind(line)
        if decl_kind == "designator":
            pending.designator = decl_value
        elif decl_kind == "array":
            pending.name = decl_value

        while cursor < len(events) and events[cursor][0] < line_end:
            position, kind, match = events[cursor]
            cursor += 1

            if kind == "open":
                # ``const struct X gY[] = {`` puts the declaration and the brace
                # on one line, so the name has to come from the prefix too.
                decl_kind, decl_value = _statement_context(line[: position - line_start], line)
                if decl_kind == "designator":
                    pending.designator = pending.designator or decl_value
                elif decl_kind == "array":
                    pending.name = pending.name or decl_value

                parent = stack[-1] if stack else None
                stack.append(
                    _Frame(
                        designator=pending.designator,
                        name=pending.name,
                    )
                )
                pending = _Frame()
                continue

            if kind == "close":
                if stack:
                    stack.pop()
                continue

            if kind == "semi":
                pending = _Frame()
                continue

            assert match is not None
            ctx_kind, ctx_value = _statement_context(line[: position - line_start], line)
            label, owner = _label_for(ctx_kind, ctx_value, stack, pending, ordinal)
            if owner is not None:
                owner.count += 1

            open_paren = match.end() - 1
            close = _close_paren(text, open_paren)
            if global_index:
                index = ordinal
            else:
                index = label_counts.get(label, 0)
            ordinal += 1
            if close == -1:
                continue
            literals = _string_literals(text[open_paren + 1 : close - 1])
            if not literals:
                continue
            combined = "".join(literals)
            if not is_meaningful_string(combined):
                continue
            entries.append(
                ExtractedEntry(
                    _entry_id(file_path, label, index),
                    file_path,
                    label,
                    index,
                    combined,
                    category,
                )
            )
            label_counts[label] = index + 1

        if newline == -1:
            break
        line_start = line_end + 1

    return entries


def _default_c_category(file_path: str) -> str:
    normalized = file_path.replace("\\", "/")
    if normalized.startswith("./"):
        normalized = normalized[2:]
    for prefix in LEGACY_C_CATEGORY_PATHS:
        if normalized.startswith(prefix) or f"/{prefix}" in normalized:
            return C_SOURCE_CATEGORY
    return ENGINE_C_CATEGORY


# --------------------------------------------------------------------------
# Repository scan
# --------------------------------------------------------------------------

#: ``.inc`` dialects, scanned recursively.
INC_SCAN_DIRS: Tuple[str, ...] = (
    "data/maps",
    "data/text",
)

#: Engine text files, listed one by one.  Deliberately *not* a walk of all of
#: ``src/``: that would drag in debug tooling (``src/debug.c``,
#: ``src/battle_debug.c``, ...) whose strings never ship.  Add a line here as
#: more text tables are brought into scope.
C_SCAN_FILES: Tuple[str, ...] = (
    "src/strings.c",
    "src/battle_message.c",
    "src/data/items.h",
    "src/data/moves_info.h",
    "src/data/abilities.h",
    "src/data/script_menu.h",
    "src/data/trade.h",
    "src/data/help_window.h",
    "src/data/party_menu.h",
    "src/data/lilycove_lady.h",
    "src/data/union_room.h",
    "src/data/contest_text_tables.h",
    "src/data/pokemon/species_info.h",
)

#: Globs for the same, for roots that are whole directories of text tables.
C_SCAN_GLOBS: Tuple[str, ...] = (
    "src/data/text/*.h",
    "src/data/text/*.c",
    "src/data/decoration/*.h",
    "src/data/easy_chat/*.h",
    "src/data/pokemon/species_info/*.h",
)


def _read(path: str) -> Optional[str]:
    try:
        with open(path, "r", encoding="utf-8", errors="ignore") as handle:
            return handle.read()
    except Exception as e:  # pragma: no cover - unreadable file
        print(f"Error reading {path}: {e}")
        return None


def _normalize(path: str) -> str:
    return path.replace("\\", "/")


def _iter_inc_files(root_dir: str) -> Iterator[str]:
    for relative in INC_SCAN_DIRS:
        directory = os.path.join(root_dir, relative)
        if not os.path.exists(directory):
            continue
        for walk_root, _, files in os.walk(directory):
            for name in sorted(files):
                if name.endswith(".inc"):
                    yield _normalize(os.path.join(walk_root, name))


def _iter_c_files(root_dir: str) -> Iterator[Tuple[str, str]]:
    """Yield ``(path, category)`` for every configured engine text file."""
    for relative in C_SCAN_FILES:
        path = os.path.join(root_dir, relative)
        if os.path.exists(path):
            yield _normalize(path), _default_c_category(_normalize(path))

    for pattern in C_SCAN_GLOBS:
        full = os.path.join(root_dir, pattern)
        for path in sorted(glob.glob(full)):
            if os.path.isfile(path):
                normalized = _normalize(path)
                yield normalized, _default_c_category(normalized)


def scan_repository(root_dir: str = ".") -> List[ExtractedEntry]:
    all_entries: List[ExtractedEntry] = []

    for path in _iter_inc_files(root_dir):
        content = _read(path)
        if content is not None:
            all_entries.extend(extract_strings_from_inc(path, content))

    for path, category in _iter_c_files(root_dir):
        content = _read(path)
        if content is not None:
            all_entries.extend(extract_strings_from_c(path, content, category))

    return all_entries


def main():
    parser = argparse.ArgumentParser(description="Extract localizable strings from pokeemerald repo.")
    parser.add_argument("--output", default="tools/i18n/data/raw_corpus.json", help="Path to output json file.")
    args = parser.parse_args()

    os.makedirs(os.path.dirname(args.output), exist_ok=True)
    entries = scan_repository(".")
    print(f"Extracted {len(entries)} strings from repository.")
    counts: Dict[str, int] = {}
    for entry in entries:
        counts[entry.category] = counts.get(entry.category, 0) + 1
    for category in sorted(counts):
        print(f"  {category}: {counts[category]}")
    with open(args.output, "w", encoding="utf-8") as f:
        json.dump([asdict(e) for e in entries], f, ensure_ascii=False, indent=2)
    print(f"Saved to {args.output}")


if __name__ == "__main__":
    main()
