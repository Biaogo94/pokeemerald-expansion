Route20_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE_HNS, Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten, Route20_EventScript_RegisterNicole
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RematchNicole
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_RegisterNicole::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_NicoleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLE_HNS
	release
	end

Route20_EventScript_RematchNicole::
	trainerbattle_rematch TRAINER_NICOLE_HNS, Route20_Text_NicoleRematchIntro, Route20_Text_NicoleRematchDefeat
	msgbox Route20_Text_NicolePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_NICOLE_2_HNS, Route20_EventScript_RematchNicoleTryGiveItem
	end

Route20_EventScript_RematchNicoleTryGiveItem::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_HEART_SCALE
	closemessage
	end

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI_HNS, Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_HNS, Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "丹尼斯：沙----！$"

Route20_Text_Headlocker:
	.string "这条路上有种稀有的宝可梦。\p"
	.string "而且它有时还会携带着稀有的进化道\n"
	.string "具。\p"
	.string "可以说是双重稀有！\p"
	.string "为了完成我的宝可梦图鉴，我已经在\n"
	.string "这里钓了好几个小时了！$"

Route20_Text_Seel:
	.string "小海狮：叭恰叭恰！$"

Route20_Text_Dewgong:
	.string "白海狮：昂----！$"

Route20_Text_SeafoamSign:
	.string "双子岛$"

Route20_Text_NicoleRegister:
	.string "你的宝可梦游得真快！告诉我你的电\n"
	.string "话号码吧！$"

Route20_Text_NicoleRematchIntro:
	.string "游了这么久，我的宝可梦更强健了！\n"
	.string "来对战吧！$"

Route20_Text_NicoleRematchDefeat:
	.string "又被冲走了……$"

Route20_Text_NicolePostRematch:
	.string "不管输赢，反正我和我的宝可梦身体\n"
	.string "都锻炼得棒棒的！$"

Route20_Text_SwimmerfNicoleSeen:
	.string "在水里感觉整个人都变轻盈了。$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "怎么会这样！$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "游泳能锻炼到全身肌肉。\p"
	.string "对身体真的特别好呢。$"

Route20_Text_SwimmerfLoriSeen:
	.string "你收集的道馆徽章可真壮观啊。我们\n"
	.string "来对战一场吧！$"

Route20_Text_SwimmerfLoriBeaten:
	.string "不会吧！$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "冲浪已经不是唯一能在水上使用的秘\n"
	.string "传招式了。$"

Route20_Text_SwimmermCameronSeen:
	.string "看来想要一路游到城都，果然还是不\n"
	.string "可能的啊。$"

Route20_Text_SwimmermCameronBeaten:
	.string "哎呀！$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "除了大海，我平时在池塘和小河里也\n"
	.string "能游泳哦。$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "这块指示牌上写着什么？\p"
	.string "红莲道馆 馆主：夏伯$"

