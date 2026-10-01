.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

FiveIsland_RocketWarehouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_RocketWarehouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_RocketWarehouse_OnTransition
	.byte 0

FiveIsland_RocketWarehouse_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
	end

FiveIsland_RocketWarehouse_OnLoad::
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	end

FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry::
	setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
	setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
	return

FiveIsland_RocketWarehouse_EventScript_Cage::
	lockall
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FiveIsland_RocketWarehouse_EventScript_CageUnlocked
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_CageUnlocked::
	msgbox FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Computer::
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end

FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
	lockall
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Gideon::
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, FiveIsland_RocketWarehouse_EventScript_DefeatedGideon
	goto_if_set FLAG_IS_CHAMPION, FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid::
	famechecker FAMECHECKER_GIOVANNI, 5
	msgbox FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedGideon::
	msgbox FiveIsland_RocketWarehouse_Text_GideonPostBattle
	setflag FLAG_RECOVERED_SAPPHIRE
	giveitem ITEM_SAPPHIRE
	release
	end

FiveIsland_RocketWarehouse_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin2::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WAREHOUSE_GRUNT2
	removeobject LOCALID_WAREHOUSE_GRUNT3
	removeobject LOCALID_WAREHOUSE_ADMIN2
	removeobject LOCALID_WAREHOUSE_ADMIN1
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin1::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_Admin1PostBattle
	closemessage
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	playse SE_PIN
	call FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	special DrawWholeMapView
	waitse
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1::
	goto_if_eq PLAYER_X_POS, 27, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar::
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch::
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen::
	.string "有很多宝可梦被锁在围栏里……$"

FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled::
	.string "因为围栏的大门没上锁。宝可梦逃跑\n"
	.string "了。$"

FiveIsland_RocketWarehouse_Text_Grunt2Intro::
	.string "你敢来这里是因为知道这里是火箭队\n"
	.string "的仓库吗？$"

FiveIsland_RocketWarehouse_Text_Grunt2Defeat::
	.string "你清楚自己在做什么吗？！$"

FiveIsland_RocketWarehouse_Text_Grunt2PostBattle::
	.string "你说火箭队解散了？你来自哪个星\n"
	.string "球？$"

FiveIsland_RocketWarehouse_Text_Grunt1Intro::
	.string "哦，你的宝可梦现在看起来很强。愿\n"
	.string "意卖掉它们吗？\p"
	.string "哦？想要打一场？$"

FiveIsland_RocketWarehouse_Text_Grunt1Defeat::
	.string "哦，但是……太多了！$"

FiveIsland_RocketWarehouse_Text_Grunt1PostBattle::
	.string "我们会给你开一个好价钱。把宝可梦\n"
	.string "卖给我们吧！$"

FiveIsland_RocketWarehouse_Text_Grunt3Intro::
	.string "我从别人那听说过关于你的事情。\p"
	.string "但是像你这样的孩子不可能了解我们\n"
	.string "的坂木老大！$"

FiveIsland_RocketWarehouse_Text_Grunt3Defeat::
	.string "你…不…准…笑…$"

FiveIsland_RocketWarehouse_Text_Grunt3PostBattle::
	.string "不要掺和到大人的事情中来，你这只\n"
	.string "上窜下跳的小老鼠！$"

FiveIsland_RocketWarehouse_Text_Admin1Intro::
	.string "我不知道我做的是对还是错……\p"
	.string "我只是信任坂木并且按照命令行事。$"

FiveIsland_RocketWarehouse_Text_Admin1Defeat::
	.string "我……我被击垮了……$"

FiveIsland_RocketWarehouse_Text_Admin1PostBattle::
	.string "你在按照你的信仰和道德行事。\p"
	.string "我现在明白了……$"

FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
	.string "我做到了，因此你能从那回来。\p"
	.string "你休息恢复下之后准备继续前进吧。\p"
	.string "干部们成为训练家要比我晚，但现在\n"
	.string "却完全超越了我。\p"
	.string "你最好好好锻炼自己来迎接严厉的挑\n"
	.string "战。$"

FiveIsland_RocketWarehouse_Text_Admin2Intro::
	.string "小朋友，扮英雄的游戏结束了。\p"
	.string "散播关于火箭队如何解散的谎言……\p"
	.string "这是一个明显的想要扰乱我们的队伍\n"
	.string "的计划。\p"
	.string "幸好，我们不会无知到因为一个孩子\n"
	.string "的谎言而就此沦落！\p"
	.string "而现在，我会让你见识一下生气的大\n"
	.string "人有多可怕！$"

FiveIsland_RocketWarehouse_Text_Admin2Defeat::
	.string "呃……你太强了……\p"
	.string "……那-那是坂木的徽章！\p"
	.string "传言是真的吗？火箭队真的解散了？$"

FiveIsland_RocketWarehouse_Text_Admin2PostBattle::
	.string "我们将放弃这个仓库……\p"
	.string "但不要认为已经结束了。我不会善罢\n"
	.string "甘休的。\p"
	.string "我会找到坂木。并且复活火箭队！我\n"
	.string "要…\p"
	.string "就这样，再会！$"

FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText::
	.string "电脑屏幕上有图表和文字的报告。\p"
	.string "“电波对宝可梦进化的影响”\p"
	.string "…… …… ……\p"
	.string "这太难懂了……$"

FiveIsland_RocketWarehouse_Text_GideonIntro::
	.string "我差一点就能把蓝宝石卖了赚到大笔\n"
	.string "大笔的钱……\p"
	.string "你却过来毁了整个交易！\p"
	.string "呋呋……呋呋呋呋……绝不能饶恕你"
	.string "！$"

FiveIsland_RocketWarehouse_Text_GideonDefeat::
	.string "噶！该死！混蛋！真气人！$"

FiveIsland_RocketWarehouse_Text_GideonPostBattle::
	.string "如果我卖不了它，它就没价值了！来\n"
	.string "吧，拿着它吧！$"

FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe::
	.string "你现在想要什么？走开，滚远点，让\n"
	.string "我一个人呆着。$"

FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair::
	.string "什么，又是你？\p"
	.string "你……你莫非是坂木的孩子？我没认错\n"
	.string "吧？\p"
	.string "不，我认错了。坂木的孩子是红头\n"
	.string "发。\p"
	.string "那你别来烦我了。让我单独呆一会\n"
	.string "儿！$"

