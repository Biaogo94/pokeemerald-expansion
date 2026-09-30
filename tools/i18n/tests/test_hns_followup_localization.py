"""Regression checks for HnS localized terminology and summary screen text."""
from pathlib import Path
import re

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


def test_summary_page_wraps_move_descriptions_to_fit_pixel_width():
    text = read("src/pokemon_summary_screen.c")
    move_details = re.search(r"static void PrintMoveDetails\(enum Move move\)\s*\{(.*?)\n\}", text, re.S)
    assert move_details
    assert "PrintTextOnWindowToFitPx" in move_details.group(1)
    assert "WindowWidthPx(windowId) - 6" in move_details.group(1)


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
