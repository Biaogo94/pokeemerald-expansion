"""Regression checks for HnS localized terminology and summary screen text."""
from pathlib import Path
import re

from tools.i18n.extractor import scan_repository

ROOT = Path(__file__).resolve().parents[3]


def read(relative):
    return (ROOT / relative).read_text(encoding="utf-8")


def test_player_bag_is_never_called_baobao_in_active_sources():
    paths = [
        *sorted((ROOT / "src").rglob("*.c")),
        *sorted((ROOT / "src").rglob("*.h")),
        *sorted((ROOT / "data").rglob("*.inc")),
        *sorted((ROOT / "data").rglob("*.h")),
    ]
    offenders = []
    for path in paths:
        text = path.read_text(encoding="utf-8")
        if "包包" in text or re.search(r"包\\\\n包", text):
            offenders.append(str(path.relative_to(ROOT)))
    assert offenders == []


def test_all_move_type_names_are_simplified_chinese():
    text = read("src/data/types_info.h")
    expected = {
        "TYPE_NORMAL": "一般", "TYPE_FIGHTING": "格斗", "TYPE_FLYING": "飞行",
        "TYPE_POISON": "毒", "TYPE_GROUND": "地面", "TYPE_ROCK": "岩石",
        "TYPE_BUG": "虫", "TYPE_GHOST": "幽灵", "TYPE_STEEL": "钢",
        "TYPE_FIRE": "火", "TYPE_WATER": "水", "TYPE_GRASS": "草",
        "TYPE_ELECTRIC": "电", "TYPE_PSYCHIC": "超能力", "TYPE_ICE": "冰",
        "TYPE_DRAGON": "龙", "TYPE_DARK": "恶", "TYPE_FAIRY": "妖精",
        "TYPE_STELLAR": "星晶",
    }
    for type_name, chinese in expected.items():
        start = re.search(rf"\[{type_name}\]\s*=", text)
        assert start, type_name
        # The same enum labels occur in the matchup table above the TypeInfo
        # table; anchor the search to the later name field instead.
        block = text[start.start():]
        name = re.search(rf"\.name\s*=\s*_\(\"{re.escape(chinese)}\"\)", block)
        assert name, type_name
        assert not re.search(r"\.name\s*=\s*_\(\"[A-Za-z]", block[:name.end()])


def test_trainer_memo_has_complete_met_and_nature_variants():
    strings = read("src/strings.c")
    for name in (
        "gText_XNatureMetAtYZ", "gText_XNatureHatchedAtYZ",
        "gText_XNatureProbablyMetAt", "gText_XNatureMetSomewhereAt",
        "gText_XNatureHatchedSomewhereAt",
    ):
        match = re.search(rf"const u8 {name}\[\].*?= _\(\"(.*?)\"\);", strings)
        assert match, name
        value = match.group(1)
        assert "性格" in value
        assert "DYNAMIC 3" in value
        assert "DYNAMIC 4" in value or "某处" in value


def test_summary_trainer_memo_uses_window_newlines_not_dialogue_scroll():
    strings = read("src/strings.c")
    memo_names = (
        "gText_XNatureMetAtYZ", "gText_XNatureHatchedAtYZ",
        "gText_XNatureObtainedInTrade", "gText_XNatureFatefulEncounter",
        "gText_XNatureProbablyMetAt", "gText_XNatureMetSomewhereAt",
        "gText_XNatureHatchedSomewhereAt",
    )
    for name in memo_names:
        match = re.search(rf"const u8 {name}\[\].*?= _\(\"(.*?)\"\);", strings)
        assert match, name
        assert r"\l" not in match.group(1), name
        assert r"\n" in match.group(1), name
    summary = read("src/pokemon_summary_screen.c")
    memo_printer = re.search(r"static void PrintMonTrainerMemo\(void\)\s*\{(.*?)\n\}", summary, re.S)
    assert memo_printer and "PrintTextOnWindowToFit" in memo_printer.group(1)


def test_summary_page_wraps_move_descriptions_to_fit_pixel_width():
    text = read("src/pokemon_summary_screen.c")
    move_details = re.search(r"static void PrintMoveDetails\(enum Move move\)\s*\{(.*?)\n\}", text, re.S)
    assert move_details
    assert "PrintTextOnWindowToFitPx" in move_details.group(1)
    assert "WindowWidthPx(windowId) - 6" in move_details.group(1)


def test_summary_graphic_page_title_is_localized():
    renderer = read("tools/i18n/draw_summary_labels.py")
    assert "((192, 196), '招式', [(193, 193), (194, 194)])" in renderer


def test_nature_names_remain_current_official_simplified_names():
    text = read("src/pokemon.c")
    expected = {
        "NATURE_HARDY": "勤奋", "NATURE_LONELY": "怕寂寞", "NATURE_BRAVE": "勇敢",
        "NATURE_ADAMANT": "固执", "NATURE_NAUGHTY": "顽皮", "NATURE_BOLD": "大胆",
        "NATURE_DOCILE": "坦率", "NATURE_RELAXED": "悠闲", "NATURE_IMPISH": "淘气",
        "NATURE_LAX": "乐天", "NATURE_TIMID": "胆小", "NATURE_HASTY": "急躁",
        "NATURE_SERIOUS": "认真", "NATURE_JOLLY": "开朗", "NATURE_NAIVE": "天真",
        "NATURE_MODEST": "内敛", "NATURE_MILD": "温和", "NATURE_QUIET": "冷静",
        "NATURE_BASHFUL": "害羞", "NATURE_RASH": "马虎", "NATURE_CALM": "温顺",
        "NATURE_GENTLE": "温柔", "NATURE_SASSY": "自大", "NATURE_CAREFUL": "慎重",
        "NATURE_QUIRKY": "浮躁",
    }
    for enum_name, official_name in expected.items():
        match = re.search(rf"\[{enum_name}\]\s*=\s*\{{(.*?)\n\s*\}},", text, re.S)
        assert match and f'.name = COMPOUND_STRING("{official_name}")' in match.group(1)


def test_dialogue_breaks_do_not_orphan_punctuation_or_split_ascii_tokens():
    punctuation = "，。！？、；：）》”’』】"
    orphan_pattern = re.compile(r"\\[nl][" + re.escape(punctuation) + r"]")
    split_ascii = re.compile(r"[A-Za-z0-9]\\[nl][A-Za-z0-9]")
    too_many_full_width = []
    orphaned_punctuation = []
    split_tokens = []

    for entry in scan_repository(str(ROOT)):
        if not entry.file.startswith(("./data/maps/", "./data/text/", "./data/scripts/")):
            continue
        if entry.file.endswith("/debug.inc"):
            continue

        for line_number, line in enumerate(re.split(r"\\[nlp]", entry.source), 1):
            visible = re.sub(r"\{[^}]*\}", "", line).replace("$", "")
            full_width_count = sum("\u3400" <= char <= "\u9fff" for char in visible)
            if full_width_count > 16:
                too_many_full_width.append((entry.file, entry.label, line_number, visible))

        orphan_match = orphan_pattern.search(entry.source)
        if orphan_match:
            orphaned_punctuation.append((entry.file, entry.label, orphan_match.group()))
        split_match = split_ascii.search(entry.source)
        if split_match:
            split_tokens.append((entry.file, entry.label, split_match.group()))

    assert too_many_full_width == []
    assert orphaned_punctuation == []
    assert split_tokens == []
