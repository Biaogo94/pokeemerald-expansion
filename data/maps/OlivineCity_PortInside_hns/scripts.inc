OlivineCity_PortInside_hns_MapScripts::
	.byte 0


OlivineCity_PortInside_EventScript_Oak::
	lock
	playbgm MUS_HG_OAK, FALSE
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_OLIVINEPORT_OAK
	turnobject LOCALID_OLIVINEPORT_OAK, DIR_NORTH
	msgbox OlivineCity_PortInside_Text_Nationaldex1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakFixDex
	waitmovement 0
	delay 30
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_ITEM
	message OlivineCity_PortInside_Text_Nationaldex2
	waitfanfare
	delay 50
	msgbox OlivineCity_PortInside_Text_Nationaldex3, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_OLIVINEPORT_OAK
	msgbox OlivineCity_PortInside_Text_Nationaldex4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OlivineCity_PortInside_Movement_PlayerMoveOver
	waitmovement 0
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakLeave
	waitmovement 0
	setflag FLAG_HIDE_OLIVINE_PORT_OAK
	playse SE_EXIT
	removeobject LOCALID_OLIVINEPORT_OAK
	fadedefaultbgm
	waitse
	release
	end

OlivineCity_PortInside_Movement_OakFixDex:
	walk_in_place_up
	walk_in_place_up
	step_end

OlivineCity_PortInside_Movement_PlayerMoveOver:
	walk_up
	walk_left
	face_right
	step_end

OlivineCity_PortInside_Movement_OakLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_PortInside_Text_Nationaldex1:
	.string "大木博士：你好啊！\n"
	.string "{PLAYER}，你现在越来越有\l"
	.string "冠军的架势了呢！\p"
	.string "是时候让你的图鉴也配得上现在的你\n"
	.string "了。\p"
	.string "把你的宝可梦图鉴借我看一下。\p"
	.string "我来帮你的宝可梦图鉴升级为全国图\n"
	.string "鉴模式。$"
OlivineCity_PortInside_Text_Nationaldex2:
	.string "{PLAYER}的宝可梦图鉴升级\n"
	.string "为全国图鉴模式！$"
OlivineCity_PortInside_Text_Nationaldex3:
	.string "大木博士：想要完成全国图鉴可不是\n"
	.string "件容易的事……\p"
	.string "不过，我相信你一定会全力以赴去挑\n"
	.string "战的！$"
OlivineCity_PortInside_Text_Nationaldex4:
	.string "哎呀，时间过得真快！\p"
	.string "我还要去满金广播电台录制广播节目\n"
	.string "呢。\p"
	.string "你接下来肯定是要去关都了吧。\p"
	.string "如果路过真新镇的话，一定要来我的\n"
	.string "宝可梦研究所坐坐啊！$"

OlivinePort_EventScript_CooltrainerF::
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher1::
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher2::
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
	end

OlivinePort_EventScript_Youngster::
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
	end

OlivinePort_EventScript_Sailor::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivinePort_EventScript_Sailor_AfterKanto
	msgbox OlivinePort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivinePort_EventScript_Sailor_MaidenVoyage
	msgbox OlivinePort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_AfterKanto::
	message OlivinePort_Text_WhereSail
	multichoice 20, 0, MULTI_OLIVINE_HARBOR, FALSE
	switch VAR_RESULT
	case 0, OlivinePort_EventScript_ChoseVermilion
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
	case 2, OlivinePort_EventScript_ChoseBirthIsland
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
	case 4, OlivinePort_EventScript_ChoseBattleFrontier
	case 5, OlivinePort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
	release
	end

OlivinePort_EventScript_ChoseVermilion::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE_HNS, 8, 9
	waitstate
	release
	end

OlivinePort_EventScript_ChoseSouthernIsland::
	closemessage
	delay 20
	checkitem ITEM_EON_TICKET
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR_HNS, 13, 22
	waitstate
	release
	end

OlivinePort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR_HNS, 13, 23
	waitstate
	release
	end

OlivinePort_EventScript_ChoseFarawayIsland::
	closemessage
	delay 20
	checkitem ITEM_OLD_SEA_MAP
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE_HNS, 13, 38
	waitstate
	release
	end	

OlivinePort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS, 20, 67
	waitstate
	release
	end	

OlivinePort_EventScript_Sailor_MaidenVoyage::
	msgbox OlivinePort_Text_FlashTicket, MSGBOX_DEFAULT
	call OlivinePort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	clearflag FLAG_HIDE_SSAQUA_SAILOR
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	warpsilent MAP_SSAQUA_1F_HNS, 29, 3
	waitstate
	release
	end

OlivinePort_EventScript_EnterShip::
	msgbox OlivinePort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, OlivinePort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_BoatLeave
	applymovement LOCALID_OLIVINEPORT_BOAT, OlivinePort_Movement_BoatLeave
	waitmovement LOCALID_OLIVINEPORT_BOAT
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	return

OlivinePort_EventScript_Sailor_Refused::
	msgbox OlivinePort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_NoCredentials::
	msgbox OlivinePort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

OlivinePort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

OlivinePort_Movement_BoatLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OlivinePort_Text_NoPass:
    .string "{PLAYER}想要出示\n"
    .string "{STR_VAR_1}......\p"
    .string "……但是没有找到\n"
    .string "{STR_VAR_1}！\p"
    .string "非常抱歉！必须持有\n"
    .string "{STR_VAR_1}才能登船。$"

OlivinePort_Text_SailorGetOnBoard:
    .string "马上就要启航了。请抓紧时间登船。$"

OlivinePort_Text_CantBoard:
    .string "很抱歉，现在还不能登船。$"

OlivinePort_Text_WhereSail:
    .string "请问您想航行到哪里？$"

OlivinePort_Text_AskBoard:
    .string "欢迎乘坐高速船阿库号。\p"
    .string "您今天要登船吗？$"

OlivinePort_Text_AskTicket:
    .string "请出示您的船票。$"

OlivinePort_Text_ComeAgain:
    .string "欢迎下次再来！$"

OlivinePort_Text_FlashTicket:
    .string "{PLAYER}出示了船票。\p"
    .string "确认无误。非常感谢！$"

OlivinePort_Text_NoTicket:
    .string "{PLAYER}正准备出示船票"
    .string "。.....\p"
    .string "……但是没有船票！\p"
    .string "很抱歉！只有持有船票的乘客才可以\n"
    .string "登船。$"

OlivinePort_Text_FishingGuru1:
    .string "在这里很容易钓到大舌贝呢。\p"
    .string "在别的地方可挺少见的。$"

OlivinePort_Text_FishingGuru2:
    .string "你有几种钓竿呢？\p"
    .string "不同的钓竿能钓到不同的宝可梦哦。$"

OlivinePort_Text_Youngster:
    .string "高速船阿库号是靠喷射水流破浪前行\n"
    .string "的哦！$"

OlivinePort_Text_CooltrainerF:
    .string "关都地区有很多宝可梦呢。\p"
    .string "真想去看看啊……$"

OlivinePort_Text_SailorBeforeHOF:
    .string "掉进海里可就危险了，所以禁止入内\n"
    .string "哦。$"
