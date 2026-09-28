Route4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK_HNS, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE_HNS, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON_HNS, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "我正在培育我的宝可梦。想和我对战\n"
	.string "一场吗？$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "哎呀！这局竟然输了......$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "If you have a specific POKéMON that you\n"
	.string "want to raise, put it out first, then\l"
	.string "switch it right away.\p"
	.string "That's how to do it.$"

Route4_Text_PicnickerHope_Seen:
	.string "我有种能赢的预感。\p"
	.string "来看看我的直觉准不准吧！$"

Route4_Text_PicnickerHope_Beaten:
	.string "啊~你太强了吧。$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "我听说月见山会有皮皮出没。\p"
	.string "但它们究竟在哪里呢？$"

Route4_Text_PicnickerSharon_Seen:
	.string "Um…\n"
	.string "I…$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "......我还是再去多修行一下\n"
	.string "吧......$"

Route4_Text_MtMoonSquareSign:
	.string "月见山因塌方开辟新入口\p"
	.string "请注意脚下安全$"

