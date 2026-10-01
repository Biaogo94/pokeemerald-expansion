Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER}在门上写下密码。\p"
	.string "“戏法大王是传说般的人”…… …… …… \n"
	.string "……\p"
	.string "锁“咔嗒”一声开了！$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "我要用刚刚学会的居合劈砍出一条\n"
	.string "路！$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "你这么认真干什么？$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "对砍树我永远不会厌烦！$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "我只是偶然地走进了这间奇怪的房\n"
	.string "屋……$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "我输了……$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "我迷路了，我输了对战，现在我越来\n"
	.string "越伤心……我出不去了……$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "戏法大王究竟是谁？$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "在我出神的时候，我输掉了！$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "你真强！你究竟是谁？$"

