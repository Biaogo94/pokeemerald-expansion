"""Focused control-stream regressions for evolution and move-learning messages.

These inspect the production message resources, not exact Chinese wording.
They do not reproduce a full evolution scene or prove the user's unspecified
visual symptom. In text.c, \\l waits and scrolls; \\p waits and clears, whereas
WAIT_SE/PAUSE/PLAY_SE do not print a visible character.
"""

import re
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[3]
BATTLE_MESSAGES = ROOT / "src/battle_message.c"
_LITERAL = r'"((?:\\.|[^"\\])*)"'
_TOKEN = re.compile(r"\{[^}]*\}|\\.|[^\\{]+")


def _message(symbol):
    source = BATTLE_MESSAGES.read_text(encoding="utf-8")
    if symbol.startswith("STRINGID_"):
        declaration = rf"\[{re.escape(symbol)}\]\s*=\s*COMPOUND_STRING\("
    else:
        declaration = rf"\b{re.escape(symbol)}\[\]\s*=\s*_\("
    match = re.search(declaration + rf"\s*((?:{_LITERAL}\s*)+)\)", source)
    assert match, f"Missing production message: {symbol}"
    return "".join(re.findall(_LITERAL, match.group(1)))


def _scrolls_without_following_text(message):
    # A scroll must introduce visible text, rather than only timing/sound
    # controls and another input prompt. STR_VAR/B_BUFF placeholders print text.
    pending_scroll = None
    empty_scrolls = []
    for token in _TOKEN.findall(message):
        if token in (r"\n", r"\l", r"\p", "{PAUSE_UNTIL_PRESS}"):
            if pending_scroll is not None:
                empty_scrolls.append(pending_scroll)
            pending_scroll = token if token == r"\l" else None
        elif token.startswith("{"):
            if token.startswith(("{STR_VAR_", "{B_BUFF")):
                pending_scroll = None
        elif token.strip():
            pending_scroll = None
    if pending_scroll is not None:
        empty_scrolls.append(pending_scroll)
    return empty_scrolls


@pytest.mark.parametrize("symbol", [
    "gText_CongratsPkmnEvolved",
    "STRINGID_PKMNGREWTOLV",
    "STRINGID_PKMNLEARNEDMOVE",
    "STRINGID_123POOF",
])
def test_evolution_and_learning_prompts_do_not_scroll_to_empty_lines(symbol):
    message = _message(symbol)
    assert not _scrolls_without_following_text(message), (
        f"{symbol} scrolls to a blank line before another wait/clear: {message}"
    )


@pytest.mark.parametrize(("symbol", "variables"), [
    ("gText_PkmnIsEvolving", {"STR_VAR_1"}),
    ("gText_CongratsPkmnEvolved", {"STR_VAR_1", "STR_VAR_2"}),
    ("STRINGID_PKMNGREWTOLV", {"B_BUFF1", "B_BUFF2"}),
    ("STRINGID_PKMNLEARNEDMOVE", {"B_BUFF1", "B_BUFF2"}),
    ("STRINGID_TRYTOLEARNMOVE1", {"B_BUFF1", "B_BUFF2"}),
    ("STRINGID_TRYTOLEARNMOVE2", {"B_BUFF1"}),
    ("STRINGID_TRYTOLEARNMOVE3", {"B_BUFF2"}),
    ("STRINGID_PKMNFORGOTMOVE", {"B_BUFF1", "B_BUFF2"}),
    ("STRINGID_STOPLEARNINGMOVE", {"B_BUFF1", "B_BUFF2"}),
    ("STRINGID_DIDNOTLEARNMOVE", {"B_BUFF1", "B_BUFF2"}),
])
def test_evolution_messages_preserve_their_runtime_placeholder_contract(symbol, variables):
    actual = re.findall(r"\{((?:STR_VAR_|B_BUFF)[0-9]+)\}", _message(symbol))
    assert set(actual) == variables
    assert len(actual) == len(variables), "A name/move/level variable was duplicated"


@pytest.mark.parametrize("symbol", [
    "gText_CongratsPkmnEvolved",
    "STRINGID_PKMNGREWTOLV",
    "STRINGID_PKMNLEARNEDMOVE",
])
def test_completion_messages_keep_sound_wait_before_page_acknowledgement(symbol):
    message = _message(symbol)
    assert message.count("{WAIT_SE}") == 1
    assert message.endswith(r"{WAIT_SE}\p")


def test_forgetting_countdown_preserves_timing_and_sound_effect():
    message = _message("STRINGID_123POOF")
    assert re.findall(r"\{PAUSE ([0-9]+)\}", message) == ["10", "10", "10", "20"]
    assert message.count("{PLAY_SE SE_BALL_BOUNCE_1}") == 1
    assert message.endswith(r"\p")


@pytest.mark.parametrize(("message", "empty_count"), [
    (r"name\nmove!{WAIT_SE}\p", 0),
    (r"name\nmove!\l{WAIT_SE}\p", 1),
    (r"one\ntwo\lthree\p", 0),
    (r"one\ntwo\l{PAUSE 20}\l{PLAY_SE SE_BALL_BOUNCE_1}\lpoof!\p", 2),
    (r"one\ntwo\l{B_BUFF2}\p", 0),
])
def test_control_stream_guard_distinguishes_real_text_from_empty_scrolls(message, empty_count):
    assert len(_scrolls_without_following_text(message)) == empty_count
