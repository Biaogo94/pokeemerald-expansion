MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "叔叔：我想是宝可梦让那孩子打起精\n"
	.string "神来的……但他好像有点兴奋过头了\l"
	.string "……$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "满充：叔叔，拜托你了。\p"
	.string "我想挑战这个道馆，我想试试我变得\n"
	.string "多强了。\p"
	.string "可以吗？$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "叔叔：等等，满充。\p"
	.string "自从你开始和宝可梦旅行以来，确实\n"
	.string "成长了不少。\p"
	.string "但你不觉得现在就挑战道馆也太勉强\n"
	.string "了吗？$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "满充：才不勉强！\p"
	.string "只要和拉鲁拉丝齐心协力的话，我们\n"
	.string "不会输给任何人！$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "满充：啊，{PLAYER}！\p"
	.string "我比之前见面时要强多了。\p"
	.string "{PLAYER}，我想让你和叔叔\n"
	.string "看看！\p"
	.string "{PLAYER}，拜托了，和我对\n"
	.string "战吧！$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "满充：唔……{PLAYER}，如\n"
	.string "果你不跟我对战，叔叔就不会知道我\l"
	.string "真的变强了……$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "叔叔：你是{PLAYER}\n"
	.string "{KUN}吧？为了满充，能请你和\l"
	.string "来一场对战吗？\p"
	.string "我想他现在这样是没法听得进劝的。$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "满充：{PLAYER}，拜托了！\n"
	.string "和我对战吧！$"

MauvilleCity_Text_WallyHereICome:
	.string "满充：{PLAYER}，谢谢！\p"
	.string "那么……我要上了！$"

MauvilleCity_Text_WallyDefeat:
	.string "满充：…… …… …… ……\p"
	.string "…… …… …… ……\p"
	.string "我输了……$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "满充：叔叔……我会回绿茵镇的……$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}，谢谢你。果然做\n"
	.string "训练家真的很不容易啊……\p"
	.string "光是拥有自己的宝可梦让它们对战还\n"
	.string "不够，还算不上是真正的训练家……$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "叔叔：满充，别这么沮丧。\p"
	.string "想想是什么激励着你要变得越来越强\n"
	.string "的？\p"
	.string "好了，我们回家吧，大家都在等你呢\n"
	.string "。$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "叔叔：{PLAYER}{KUN}\n"
	.string "，我刚刚才想起来，你就是那位看着\l"
	.string "满充捕捉他的第一只宝可梦的训练家\l"
	.string "吧？\p"
	.string "有空的话，来绿茵镇转转好吗？我想\n"
	.string "满充也会很开心的。$"


MauvilleCity_Text_WallyPokenavCall:
	.string "…… …… ………… …… ……\n"
	.string "哔！\p"
	.string "满充：啊，{PLAYER}！\p"
	.string "我只是想告诉你我叔叔刚给我买了个\n"
	.string "宝可导航！\p"
	.string "现在我随时都可以联系你了，\n"
	.string "{PLAYER}！\p"
	.string "…… …… ………… …… ……\n"
	.string "咔哒！$"

MauvilleCity_Text_RegisteredWally:
	.string "把满充登记到宝可导航里了。$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "亚希达：嘿嘿……刚才的对战我都看\n"
	.string "到了！\p"
	.string "那个叫满充的男孩是你的朋友吧？\p"
	.string "即便如此你还是全力以赴漂亮地取胜\n"
	.string "了！\p"
	.string "没错！这才是真正的宝可梦对战！\p"
	.string "我所欣赏的就是这样的训练家！\p"
	.string "…… …… ……我会继续为你加油\n"
	.string "的！$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "铁旋：嗨，{PLAYER}\n"
	.string "{KUN}！你看起来挺精神嘛！不\l"
	.string "错，不错，啊哈哈哈哈！\p"
	.string "好！我决定了！{PLAYER}\n"
	.string "{KUN}，我需要帮助！\p"
	.string "紫堇市这里有一个叫做新紫堇的地下\n"
	.string "区域。\p"
	.string "{PLAYER}{KUN}，希望\n"
	.string "你能去那里关掉发电器。\p"
	.string "最近发电器的运转有些失控，现在那\n"
	.string "里不是很安全。\p"
	.string "给，这是进入新紫堇的钥匙。$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "铁旋：不用担心，这对你应该是小菜\n"
	.string "一碟。\p"
	.string "从110号道路用冲浪一小段就到新\n"
	.string "紫堇的入口了。\p"
	.string "那就这么说定了，我相信你！啊哈哈\n"
	.string "哈哈！$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "铁旋：啊哈哈哈哈！\p"
	.string "我就知道，{PLAYER}\n"
	.string "{KUN}！我就知道叫你去肯定没\l"
	.string "问题！\p"
	.string "这是我的谢礼——十万伏特的招式学\n"
	.string "习器！\p"
	.string "来，收下它吧！$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "铁旋：啊哈哈哈哈！\p"
	.string "我最喜欢看到年轻人挑起重担，引领\n"
	.string "这个时代！$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "你知道吗，看着宝可梦对战真是太棒\n"
	.string "了……\p"
	.string "但如果你的宝可梦受了伤，就得赶快\n"
	.string "帮它治疗。$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "这个镇子的道路通向四面八方。\p"
	.string "因此在这里能见到各式各样的人。$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "你去过风野的自行车行了吗？\p"
	.string "那里的主人风野是个很大方的人。$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "就算你骑着自行车，野生宝可梦也会\n"
	.string "跳出来袭击你。$"

MauvilleCity_Text_CitySign:
	.string "这里是紫堇市。“流光溢彩的欢乐城\n"
	.string "市！”$"

MauvilleCity_Text_GymSign:
	.string "紫堇市宝可梦道馆馆主：铁旋“开朗\n"
	.string "的电击大叔！”$"

MauvilleCity_Text_BikeShopSign:
	.string "“骑车到砂石路上去，晃动爱车的灵\n"
	.string "魂！”风野自行车店$"

MauvilleCity_Text_GameCornerSign:
	.string "“大家的游乐场！”紫堇游戏城$"

MauvilleCity_Text_ExplainTV:
	.string "嗨，你看电视了吗？\p"
	.string "最近电视台设立了很多新节目。\p"
	.string "电视太棒了，有一次我意外地发现我\n"
	.string "朋友上电视了。\p"
	.string "而且有时候电视台根本不告诉你你就\n"
	.string "会出现在荧屏上了。\p"
	.string "希望哪天我也能上电视，\p"
	.string "所以你要经常看电视哦。$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "嗨，你看过电视了吗？$"
