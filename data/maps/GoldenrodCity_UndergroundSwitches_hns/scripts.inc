GoldenrodCity_UndergroundSwitches_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodUnderground1_OnLoad
	.byte 0

GoldenrodUnderground1_OnLoad::
	setvar VAR_TEMP_0, 0
	call_if_set FLAG_COMPLETED_SWITCHES, GoldenrodUnderground1_ClearTheWay
	clearflag FLAG_GOLDENROD_SWITCH_1
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	end

GoldenrodUnderground1_ClearTheWay::
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	return

@ Added an antisoft lock, using wall panels
@ Added more anti softlock 

GoldenrodCity_UndergroundSwitches_InDoorAntiLock::
	lock
	msgbox GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NoOp
	warp MAP_GOLDENROD_CITY_UNDERGROUND_SWITCHES_HNS, 2, 25, 5
	waitstate
	release
	end

GoldenrodCity_UndergroundSwitches_InDoorAntiLock2::
	lock
	setvar VAR_TEMP_0, 1
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock::
	lock
	msgbox GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP::
	warp MAP_GOLDENROD_CITY_UNDERGROUND_SWITCHES_HNS, 2, 25, 5
	waitstate
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text::
	.string "你好像被困住了。\p"
	.string "要回到入口处重置开关吗？$"

@ 3->2->1

@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel1::
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_Panel1Activate @lock all
	clearflag FLAG_GOLDENROD_SWITCH_1
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch1Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel1Activate:: @unlock basic
	setflag FLAG_GOLDENROD_SWITCH_1
	goto_if_set FLAG_GOLDENROD_SWITCH_ORDER, GoldenrodCity_UndergroundSwitches_EventScript_Panel1ActivateCorrect
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_Panel1ActivateCorrect:: @unlock the right path
	playse SE_CLICK
	setflag FLAG_COMPLETED_SWITCHES
	msgbox GoldenrodUnderground_Text_Switch1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end
@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel2:: @lock all
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_Panel2Activate
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2Activate:: @unlock basic
	setflag FLAG_GOLDENROD_SWITCH_2
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateWrong
	goto_if_set FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateCorrect
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateWrong:: @unlock basic
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateCorrect:: @unlock item2
	setflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel3:: @lock all
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_Panel3Activate
	clearflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch3Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel3Activate:: @unlock item 1
	setflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_Switch3, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

@==============================================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1::
	setmetatile 5, 7, 0x399, FALSE
	setmetatile 6, 7, 0x39A, FALSE
	setmetatile 7, 7, 0x39B, FALSE

	setmetatile 5, 8, 0x3A1, FALSE
	setmetatile 6, 8, 0x3A2, FALSE
	setmetatile 7, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2::
	setmetatile 14, 7, 0x399, FALSE
	setmetatile 15, 7, 0x39A, FALSE
	setmetatile 16, 7, 0x39B, FALSE

	setmetatile 14, 8, 0x3A1, FALSE
	setmetatile 15, 8, 0x3A2, FALSE
	setmetatile 16, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3::
	setmetatile 23, 7, 0x399, FALSE
	setmetatile 24, 7, 0x39A, FALSE
	setmetatile 25, 7, 0x39B, FALSE

	setmetatile 23, 8, 0x3A1, FALSE
	setmetatile 24, 8, 0x3A2, FALSE
	setmetatile 25, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4::
	setmetatile 5, 11, 0x399, FALSE
	setmetatile 6, 11, 0x39A, FALSE
	setmetatile 7, 11, 0x39B, FALSE

	setmetatile 5, 12, 0x3A1, FALSE
	setmetatile 6, 12, 0x3A2, FALSE
	setmetatile 7, 12, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5::
	setmetatile 14, 11, 0x399, FALSE
	setmetatile 15, 11, 0x39A, FALSE
	setmetatile 16, 11, 0x39B, FALSE

	setmetatile 14, 12, 0x3A1, FALSE
	setmetatile 15, 12, 0x3A2, FALSE
	setmetatile 16, 12, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6::
	setmetatile 23, 11, 0x399, FALSE
	setmetatile 24, 11, 0x39A, FALSE
	setmetatile 25, 11, 0x39B, FALSE

	setmetatile 23, 12, 0x3A1, FALSE
	setmetatile 24, 12, 0x3A2, FALSE
	setmetatile 25, 12, 0x3A3, FALSE
	return
@======================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1::
	setmetatile 5, 7, 0x378, FALSE
	setmetatile 6, 7, 0x379, FALSE
	setmetatile 7, 7, 0x37A, FALSE
	
	setmetatile 5, 8, 0x380, FALSE
	setmetatile 6, 8, 0x381, FALSE
	setmetatile 7, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2::
	setmetatile 14, 7, 0x378, FALSE
	setmetatile 15, 7, 0x379, FALSE
	setmetatile 16, 7, 0x37A, FALSE
	
	setmetatile 14, 8, 0x380, FALSE
	setmetatile 15, 8, 0x381, FALSE
	setmetatile 16, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3::
	setmetatile 23, 7, 0x378, FALSE
	setmetatile 24, 7, 0x379, FALSE
	setmetatile 25, 7, 0x37A, FALSE
	
	setmetatile 23, 8, 0x380, FALSE
	setmetatile 24, 8, 0x381, FALSE
	setmetatile 25, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4::
	setmetatile 5, 11, 0x378, FALSE
	setmetatile 6, 11, 0x379, FALSE
	setmetatile 7, 11, 0x37A, FALSE
	
	setmetatile 5, 12, 0x380, FALSE
	setmetatile 6, 12, 0x381, FALSE
	setmetatile 7, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5::
	setmetatile 14, 11, 0x378, FALSE
	setmetatile 15, 11, 0x379, FALSE
	setmetatile 16, 11, 0x37A, FALSE
	
	setmetatile 14, 12, 0x380, FALSE
	setmetatile 15, 12, 0x381, FALSE
	setmetatile 16, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6::
	setmetatile 23, 11, 0x378, FALSE
	setmetatile 24, 11, 0x379, FALSE
	setmetatile 25, 11, 0x37A, FALSE
	
	setmetatile 23, 12, 0x380, FALSE
	setmetatile 24, 12, 0x381, FALSE
	setmetatile 25, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerTop::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	@clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 9
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerBot::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 9
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_4_HNS, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_4_HNS, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_4_HNS, GoldenrodUnderground_Text_SilverWin
	return



GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_right
	step_end


GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end	

GoldenrodCity_UndergroundSwitches_EventScript_Grunt10::
    trainerbattle_single TRAINER_GRUNT_10_HNS, GoldenrodUnderground_Text_GruntM11Seen, GoldenrodUnderground_Text_GruntM11Beaten
	msgbox GoldenrodUnderground_Text_GruntM11After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt20::
    trainerbattle_single TRAINER_GRUNT_20_HNS, GoldenrodUnderground_Text_GruntM25Seen, GoldenrodUnderground_Text_GruntM25Beaten
	msgbox GoldenrodUnderground_Text_GruntM25After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Duncan::
    trainerbattle_single TRAINER_DUNCAN_HNS, GoldenrodUnderground_Text_BurglarDuncanSeen, GoldenrodUnderground_Text_BurglarDuncanBeaten
	msgbox GoldenrodUnderground_Text_BurglarDuncanAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Eddie::
    trainerbattle_single TRAINER_EDDIE_HNS, GoldenrodUnderground_Text_BurglarEddieSeen, GoldenrodUnderground_Text_BurglarEddieBeaten
	msgbox GoldenrodUnderground_Text_BurglarEddieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt11::
    trainerbattle_single TRAINER_GRUNT_11_HNS, GoldenrodUnderground_Text_GruntM13Seen, GoldenrodUnderground_Text_GruntM13Beaten
	msgbox GoldenrodUnderground_Text_GruntM13After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt27::
    trainerbattle_single TRAINER_GRUNT_27_HNS, GoldenrodUnderground_Text_GruntF3Seen, GoldenrodUnderground_Text_GruntF3Beaten
	msgbox GoldenrodUnderground_Text_GruntF3After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_Revive::
	finditem ITEM_MAX_REVIVE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_MaxPotion::
	finditem ITEM_MAX_POTION
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_SmokeBall::
	finditem ITEM_SMOKE_BALL
	end

GoldenrodUnderground_Text_SilverBefore:
    .string "站住！\p"
    .string "看到你的身影，我就一路跟过来了。\p"
    .string "我去收拾火箭队的时候，可不想被你\n"
    .string "碍手碍脚。\p"
    .string "……等等。你之前赢过我对\n"
    .string "吧？\p"
    .string "那纯粹只是侥幸。\p"
    .string "我重新锻炼了我的队伍，现在就来把\n"
    .string "这笔账彻底还清！$"

GoldenrodUnderground_Text_SilverWin:
    .string "……为什么……为\n"
    .string "什么我会输？\p"
    .string "我集结的明明全是最强的宝可梦。\p"
    .string "我也从没有一丝松懈。\p"
    .string "那为什么我还会输？$"

GoldenrodUnderground_Text_SilverAfter:
    .string "……我想不明白……\n"
    .string "..\p"
    .string "难道那个叫阿渡的家伙说的是真的\n"
    .string "吗？\p"
    .string "说我没有正确对待宝可梦？\p"
    .string "爱……\p"
    .string "信任……\p"
    .string "这就是我所欠缺的吗？\p"
    .string "这就是我赢不了的原因吗？\p"
    .string "我……我实在搞不懂。\p"
    .string "但是，我绝不会到此为止。\p"
    .string "绝不可能。我绝不会因此止步。\p"
    .string "我是不会放弃成为世界最强的宝可梦\n"
    .string "训练家的！$"

GoldenrodUnderground_Text_SilverLoss:
    .string "哼。这才是我的真正实力，窝囊废。\p"
    .string "火箭队由我来彻底解决。\p"
    .string "至于那个阿渡，我早晚也会把他踩在\n"
    .string "脚下。$"

GoldenrodUnderground_Text_GruntM11Seen:
    .string "开了一扇门，另一扇就会关上。\p"
    .string "我敢说你绝对到不了想去的地方！$"

GoldenrodUnderground_Text_GruntM11Beaten:
    .string "可恶！我一犹豫就彻底翻船了！$"

GoldenrodUnderground_Text_GruntM11After:
    .string "其实我也被绕晕了……虽然\n"
    .string "最里面的开关应该最先按下去，可\l"
    .string "是……$"

GoldenrodUnderground_Text_GruntM25Seen:
    .string "嘎哈哈哈！\p"
    .string "被这些卷帘门搞得团团转了吧？\p"
    .string "要是你能赢过我，我就告诉你个秘密\n"
    .string "！$"

GoldenrodUnderground_Text_GruntM25Beaten:
    .string "呜呜呜……我搞砸了。$"

GoldenrodUnderground_Text_GruntM25After:
    .string "好吧。给你个提示！\p"
    .string "改变按下开关的顺序。\p"
    .string "这样卷帘门开启和关闭的规则就会随\n"
    .string "之改变。$"

GoldenrodUnderground_Text_BurglarDuncanSeen:
    .string "把身上的好东西乖乖交出来！$"

GoldenrodUnderground_Text_BurglarDuncanBeaten:
    .string "饶命啊！$"

GoldenrodUnderground_Text_BurglarDuncanAfter:
    .string "偷来再卖掉！这可是犯罪的基本功\n"
    .string "啊，小鬼！$"

GoldenrodUnderground_Text_BurglarEddieSeen:
    .string "工程还没搞完，他们就把这里废弃了\n"
    .string "。\p"
    .string "我正在找找有没有剩下的值钱玩意。$"

GoldenrodUnderground_Text_BurglarEddieBeaten:
    .string "太嚣张了吧！$"

GoldenrodUnderground_Text_BurglarEddieAfter:
    .string "地下仓库？\p"
    .string "你想去那里干什么？\p"
    .string "那下面可什么都没有啊。$"

GoldenrodUnderground_Text_GruntM13Seen:
    .string "我可不管你是不是迷路的。\p"
    .string "既然敢闯到这里，你就只能任人宰割\n"
    .string "！$"

GoldenrodUnderground_Text_GruntM13Beaten:
    .string "呃！哼，真以为自己很神气吗？$"

GoldenrodUnderground_Text_GruntM13After:
    .string "敢跟火箭队作对，你胆子可真不小啊\n"
    .string "。$"

GoldenrodUnderground_Text_GruntF3Seen:
    .string "你迷路了吗？不，看起来不像。\p"
    .string "你脸上一副天不怕地不怕的样子嘛。\p"
    .string "那就让我来让你尝尝害怕的滋味吧！$"

GoldenrodUnderground_Text_GruntF3Beaten:
    .string "怎么会这样？！$"

GoldenrodUnderground_Text_GruntF3After:
    .string "想去哪就去哪吧！快滚！我才懒得管\n"
    .string "你！$"

GoldenrodUnderground_Text_Switch1:
    .string "启动了开关1。$"

GoldenrodUnderground_Text_Switch2:
    .string "启动了开关2。$"

GoldenrodUnderground_Text_Switch3:
    .string "启动了开关3。$"

GoldenrodUnderground_Text_Switch1Off:
    .string "解除了开关1。$"

GoldenrodUnderground_Text_Switch2Off:
    .string "解除了开关2。$"

GoldenrodUnderground_Text_Switch3Off:
    .string "解除了开关3。$"
