Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER}在门上写下密码。\p"
	.string "“戏法大王是我的生命”…… ……\n"
	.string " …… ……\p"
	.string "锁“咔嗒”一声开了！$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "我听说这儿有间奇怪的房子，所以我\n"
	.string "就来了。$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "我发现了一个强大的训练家！$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "调查这个地方令我非常快乐。\p"
	.string "这是值得一遍遍地挑战的地方！$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "也许我能让我的鸟类宝可梦飞过这些\n"
	.string "墙去……$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "唔哇啊啊！计划告吹！$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "哦呵呵呵……我想我试图作弊才会输\n"
	.string "的。$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "我快要被这些旋转门弄晕了……$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "周围的一切都在转啊转啊……我再也\n"
	.string "受不了了……$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "你好像没受影响啊，还是说你只是摆\n"
	.string "出一副面无表情的样子？$"

