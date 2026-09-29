"""Guard the HnS battle action grid and berry-tree messages against broken reflow."""

import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[3]
BATTLE = ROOT / "src/battle_message.c"
BERRIES = ROOT / "data/scripts/berry_tree.inc"


def _battle_message(symbol):
    source = BATTLE.read_text(encoding="utf-8")
    match = re.search(rf"const u8 {symbol}\[\] = _\(\"([^\"]+)\"\);", source)
    assert match, symbol
    return match.group(1)


def test_battle_actions_remain_two_rows_with_two_columns():
    message = _battle_message("gText_BattleMenu")
    assert message == r"战斗{CLEAR_TO 56}背包\n宝可梦{CLEAR_TO 56}逃走"
    assert message.count(r"\n") == 1
    assert r"\l" not in message
    assert message.count("{CLEAR_TO 56}") == 2


def test_berry_tree_picking_replants_and_reports_current_stage():
    script = BERRIES.read_text(encoding="utf-8").split("#else", 1)[0]
    picked = script.split("BerryTree_EventScript_Hns_PickBerry::", 1)[1].split("BerryTree_EventScript_Hns_BagFull::", 1)[0]
    assert picked.index("ObjectEventInteractionRemoveBerryTree") < picked.index("ObjectEventInteractionPlantBerryTree")
    assert "BERRY_STAGE_PLANTED, BerryTree_EventScript_Hns_NotRipe" in script
    assert "BERRY_STAGE_BERRIES, BerryTree_EventScript_Hns_FullyGrown" in script
    text = script.split("BerryTree_Text_Hns_NotRipe:", 1)[1].split("BerryTree_Text_Hns_Picked:", 1)[0]
    assert "果树" in text and "树果" in text
    assert "树果树" not in text


def test_picked_message_does_not_scroll_on_an_empty_line():
    script = BERRIES.read_text(encoding="utf-8").split("#else", 1)[0]
    text = script.split("BerryTree_Text_Hns_Picked:", 1)[1].split("BerryTree_Text_Hns_BagFull:", 1)[0]
    assert text.count(r"\n") == 1
    assert r"\l" not in text
    assert "{STR_VAR_1}" in text and "{STR_VAR_2}" in text
    assert re.search(r"\$\"", text)
