CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "我都记不清上一次有人来拜访我是什\n"
	.string "么时候了。\p"
	.string "年轻时，我也曾是一名宝可梦训练家\n"
	.string "。登过巍峨高塔，也潜过浩瀚深海。\p"
	.string "凡事都倾注了无数心血。\p"
	.string "不过现在嘛，我在这片海滩上听听风\n"
	.string "浪声，过着清闲日子，倒也乐得自在\l"
	.string "。$"

CianwoodCity_Text_BellTowerStory:
	.string "Have you heard of the TIN TOWER\n"
	.string "in ECRUTEAK?\p"
	.string "There are what they call Clear Bells\n"
	.string "on top of the tower.\p"
	.string "They don't make a single noise\n"
	.string "in strong winds.\p"
	.string "There is only one way to make them\n"
	.string "ring.\p"
	.string "It is to obtain another CLEAR BELL\n"
	.string "just like the ones at the top of the\l"
	.string "tower.\p"
	.string "I went after it when I was young.\n"
	.string "But I never got one...$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "Have you heard of WHIRL ISLANDS?\p"
	.string "There are what they call Tidal Bells\n"
	.string "at its waterfall basin.\p"
	.string "They don't make a single noise\n"
	.string "in crashing waves.\p"
	.string "There is only one way to make them\n"
	.string "ring.\p"
	.string "It is to obtain another Tidal Bell\n"
	.string "just like the ones at the waterfall\l"
	.string "basin.\p"
	.string "I went after it when I was young.\n"
	.string "But I never got one...$"

CianwoodCity_Text_ClearBellReaction:
	.string "噢！你居然拿到了透明铃铛？！\p"
	.string "那可是我当年的梦想啊......\n"
	.string "原来如此......\p"
	.string "你真的做到了..........\n"
	.string "........我听到了！\p"
	.string "乘着微风，从铃铛塔的方向传来了清\n"
	.string "脆悠扬的铃声......$"

CianwoodCity_Text_TidalBellReaction:
	.string "噢！你居然拿到了海潮铃铛？！\p"
	.string "那可是我当年的梦想啊......\n"
	.string "原来如此......\p"
	.string "你真的做到了..........\n"
	.string "........我听到了！\p"
	.string "乘着海风，从漩涡列岛的方向传来了\n"
	.string "清脆悠扬的铃声......$"
