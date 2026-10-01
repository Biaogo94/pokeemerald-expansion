SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "您说什么？想要乘船吗？\p"
	.string "对不起，目前渡轮还未通航……$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "您好，是来乘渡轮吗？可以出示您的\n"
	.string "船票吗？$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER}没有船票……\p"
	.string "非常抱歉。\p"
	.string "必须要持有船票才能登船。$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER}出示了船票。\p"
	.string "好的，没问题了！\p"
	.string "您想去哪里？$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "欢迎下次再来！$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "那就前往水静市吧！$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "那就前往对战开拓区吧！$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "请登船等候出发。$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "那么您想去哪里？$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "去海底旅行……不知道会是什么样？\p"
	.string "希望哪天我也能到海底去。$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "要让船安全航行，我们就得事先了解\n"
	.string "天气变化！\p"
	.string "说到天气，我从天气研究所的一个人\n"
	.string "哪儿听说，\p"
	.string "他们接到了来自很多地方的关于天气\n"
	.string "反常的报告！\p"
	.string "你该去天气研究所了解一下情况！$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "我也想跟着楠木馆长去海底勘探，\p"
	.string "但潜水艇对我来说太小了。\p"
	.string "如果我挤进去，馆长就没地方了……$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "楠木馆长：那些恶棍……\p"
	.string "他们和上次在博物馆抢得文的物品的\n"
	.string "人是一伙儿的。$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "水梧桐：哦？又是你……\p"
	.string "坚持不懈地一路追到这里来，真是辛\n"
	.string "苦你了。\p"
	.string "但现在……谁也无法阻止我们！谁也不\n"
	.string "能！\p"
	.string "还是说你有胆量追着我们回水静市的\n"
	.string "基地吗？\p"
	.string "呵哈哈哈哈……$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "楠木馆长：为什么……\p"
	.string "为什么海洋队要抢我的海渊1号？\p"
	.string "他们不会是要去寻找那只沉睡在海底\n"
	.string "的宝可梦吧……\p"
	.string "但就算我追上去，也对付不了他们……$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "楠木馆长：啊，{PLAYER}\n"
	.string "{KUN}……\p"
	.string "所以……海洋队还是先一步逃跑了……\p"
	.string "不，别自责，这不是你的错。\p"
	.string "要追上一艘潜艇……对普通人来说几乎\n"
	.string "不可能。\p"
	.string "你或许需要一只会潜水的宝可梦……\p"
	.string "也许你去绿岭市的话……\p"
	.string "那儿住着很多潜水员，也许有人能教\n"
	.string "会你……$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "楠木馆长：要追上一艘潜艇……对普通\n"
	.string "人来说几乎不可能。\p"
	.string "你或许需要一只会潜水的宝可梦……\p"
	.string "也许你去绿岭市的话……\p"
	.string "那儿住着很多潜水员，也许有人能教\n"
	.string "会你……$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "楠木馆长：啊，没错，哈奇老人到我\n"
	.string "们船厂来了。\p"
	.string "这样渡轮很快就会完工了！$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "楠木馆长：{PLAYER}\n"
	.string "{KUN}！\p"
	.string "我们终于造好破浪号渡轮了！\p"
	.string "多亏了你朋友哈奇老人的帮忙，我们\n"
	.string "才能这么快完工。\p"
	.string "来坐船体验下短途航行吧！$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "楠木馆长：嗯？{PLAYER}\n"
	.string "{KUN}，你拿的是……\p"
	.string "那是探测器！这会在我们的勘探中派\n"
	.string "上大用场的。\p"
	.string "{PLAYER}{KUN}，你愿\n"
	.string "意用你的探测器换点东西吗？\p"
	.string "比如，嗯，深海之牙或者深海鳞片？$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "楠木馆长：真的吗？那对你而言没什\n"
	.string "么用处，{PLAYER}\l"
	.string "{KUN}……\p"
	.string "唉，那好吧，如果你改变主意了，再\n"
	.string "来告诉我。$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "楠木馆长：那么，你要用它跟我换深\n"
	.string "海之牙？$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "楠木馆长：那么，你要用它跟我换深\n"
	.string "海鳞片？$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "楠木馆长：你想要哪个？$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER}把探测器交给了楠\n"
	.string "木馆长。$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "楠木馆长：谢谢，{PLAYER}\n"
	.string "{KUN}！这对研究会有很大帮助\l"
	.string "的！$"
