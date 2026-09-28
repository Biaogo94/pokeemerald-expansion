BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "请从聚集在此的训练家中选择一位搭\n"
	.string "档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}，您尚未找到组队\n"
	.string "的搭档，\p"
	.string "要放弃寻找搭档返回接待柜台吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "那么，请从聚集在此的训练家中选择\n"
	.string "一位搭档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "感谢您完成组队。\p"
	.string "现在将带您前往多人对战间。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "我是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}个徒弟。你\l"
	.string "可以叫我{STR_VAR_3}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "按照{STR_VAR_1}的指点\n"
	.string "，我带了一只携带了\l"
	.string "{STR_VAR_2}的\l"
	.string "{STR_VAR_3}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "一只携带了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "请和我一起组队吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "谢谢你！我马上就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "我十分想和你组队，\n"
	.string "{PLAYER}……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "我是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}个徒弟。我\l"
	.string "叫{STR_VAR_3}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "我从{STR_VAR_1}那里得\n"
	.string "到了建议并且选择了一只携带了\l"
	.string "{STR_VAR_2}的\l"
	.string "{STR_VAR_3}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "一只携带了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "请和我一起组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "非常感谢！我马上就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}，我希望我能成为\n"
	.string "你的搭档……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "呃，我叫{STR_VAR_3}，\n"
	.string "是{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟。\p"
	.string "呜呜……\p"
	.string "对不起！我太紧张了，不小心哭了…\n"
	.string "…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "我听了{STR_VAR_3}的建\n"
	.string "议，带了会{STR_VAR_1}\l"
	.string "的{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "呜呜……和、和我组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "真、真的吗？太棒了！好高兴！呜～\n"
	.string "呜……\p"
	.string "啊……抱歉……我太兴奋，都哭出来\n"
	.string "了……\p"
	.string "我这就去登记，别走啊！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "啊，怎么会……呜……呜……呜哇啊\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "嗨！我是{STR_VAR_3}！\n"
	.string "也就是{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3}为我推荐了\n"
	.string "一支队伍。我所拥有的是会\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。很棒是不\l"
	.string "是？\p"
	.string "那就来吧！我们组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "哈！棒极了！好了，我去登记，好吗\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "呃，为什么？我想跟你组队啊，\n"
	.string "{PLAYER}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "我是{STR_VAR_3}，伟大\n"
	.string "的{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "我向{STR_VAR_3}征询了\n"
	.string "一些意见。会\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}就是我带的\l"
	.string "伙伴。\p"
	.string "拜托了，跟我组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "谢谢！我这就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}，我一直希望能和\n"
	.string "你组队……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "唔……你能花时间来找我我真的很高\n"
	.string "兴。\p"
	.string "我是{STR_VAR_3}，也就\n"
	.string "是{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3}给过我一些\n"
	.string "建议，为此我非常感激。\p"
	.string "我的队伍里有一只会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。我知道我\l"
	.string "的要求有点过分……\p"
	.string "我想你可能不愿意，但我真的想成为\n"
	.string "你的搭档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "真的吗？真不敢相信！我真的不敢相\n"
	.string "信你会接纳我！我……我一定不会让\l"
	.string "你失望的！\p"
	.string "唔……真的可以的话，我这就去登记\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "啊……我知道我水平还不够……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "嗨，我是{STR_VAR_3}，\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3}告诉我这样\n"
	.string "的队伍不错：会\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "不错的队伍，是不？想和我组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "太好了，很荣幸和你组队！我希望你\n"
	.string "不要拖我的后腿！我现在去登记一下\l"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "啊？为什么你要拒绝我？不要光看外\n"
	.string "表啊！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "我是{STR_VAR_3}，一个\n"
	.string "铁人三项选手。我每天都忙着跑步、\l"
	.string "锻炼还有说唱，\p"
	.string "偶然之下成了\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "我用的是{STR_VAR_3}推\n"
	.string "荐的会{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "无论我有多忙，我都会尽最大的努力\n"
	.string "去培育它们。\p"
	.string "让我们组队横扫一切对手吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "好极了，要的就是这种精神！我去登\n"
	.string "记，你就在这儿等一下吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "我是从排得满满的日程表里挤出时间\n"
	.string "来这里的！别让我失望！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "嗨！怎么样？\p"
	.string "我是{STR_VAR_3}，\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟。很\l"
	.string "高兴见到你！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "听着，听着！你有必要听听\n"
	.string "{STR_VAR_3}推荐的宝可\l"
	.string "梦。有会{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。当然，我\l"
	.string "的培育方式也非常完美！\p"
	.string "好了，组个队如何？我相信我们的联\n"
	.string "手一定超强！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "哈，我想这次一定会很有趣的！我去\n"
	.string "登记了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "哼，真小气！要知道我可是经常被夸\n"
	.string "奖的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "请允许我先介绍一下自己。我是\n"
	.string "{STR_VAR_3}，\p"
	.string "也就是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}个徒弟。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "我遵从了睿智的\n"
	.string "{STR_VAR_3}的建议，培\l"
	.string "育了会{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "请与我组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "哇……太高兴了！我保证我一定会做\n"
	.string "到最好！\p"
	.string "我现在就去登记！请稍等！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "我一直都想和你组队的，\n"
	.string "{PLAYER}……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "哇！你和我说话了！我……我太高兴\n"
	.string "了！\p"
	.string "我是{STR_VAR_3}！\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "按照{STR_VAR_3}的建议\n"
	.string "，我训练了会\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "拜托，答应我吧，我想成为你的搭档\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "喔！我……我兴奋地要晕倒了！非常\n"
	.string "感谢！我马上就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "天哪！你没有一点同情心吗？不过你\n"
	.string "看上去更酷了……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "呀哈！我就是\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个弟子！\p"
	.string "我叫{STR_VAR_3}，你好\n"
	.string "，你好！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "我的老师{STR_VAR_3}建\n"
	.string "议我用擅长{STR_VAR_1}\l"
	.string "的{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "和擅长{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "这组合不错吧？你会和我搭档的吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "好，太棒了！我很快就能登记好！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "切！你真是个斤斤计较的家伙，\n"
	.string "{PLAYER}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "嘿！我们有大麻烦了！明天对战塔就\n"
	.string "要关门了！\p"
	.string "…… …… ……只是开个玩笑！\p"
	.string "人们都叫我{STR_VAR_3}\n"
	.string "！{STR_VAR_1}的第一千\l"
	.string "个徒弟！但实际上，我是第\l"
	.string "{STR_VAR_2}个！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3}给过我一些\n"
	.string "建议，让我使用会\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。每种我都\l"
	.string "有十只！呃，实际上，只是每种一只\l"
	.string "！\p"
	.string "如何？想和我组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "哈哈哈！作为感谢，我送你一只宝可\n"
	.string "梦！\p"
	.string "当然，是开玩笑的！那么我这就去登\n"
	.string "记，可以吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "啊，你真绝情！那就让我破坏掉对战\n"
	.string "塔吧！\p"
	.string "当然，我不是说真的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "嘿，就是你，我是个玩摇滚的说！宝\n"
	.string "可梦，我也能控制的说！\p"
	.string "我是{STR_VAR_3}，一个\n"
	.string "说唱水手的说，别把我当成普通艺人\l"
	.string "了的说！\p"
	.string "我是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}个徒弟，哼\l"
	.string "哼，可别那么快拒绝我！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "{STR_VAR_3}给的建议我\n"
	.string "照做了，我为我的队伍感到骄傲！使\l"
	.string "用{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "和使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "让组队的胜利纪念我们的相遇！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "嘿嘿，我喜欢这样的你！让我现在就\n"
	.string "去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "哦呀，{PLAYER}，你真绝情\n"
	.string "！或许是我太唐突了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "喂喂，呀——呼——！喂，别跑呀！\n"
	.string "我没病，只是自娱自乐！\p"
	.string "喔哈哈！我是\n"
	.string "{STR_VAR_3}！\l"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3}教我怎么做\n"
	.string "，使用{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，这就是我\l"
	.string "的选择。\p"
	.string "好了，你觉得怎么样？我们来组个队\n"
	.string "吧！\p"
	.string "拜托你让我加入！别徒留我一人感伤\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "呀哈！幸运站在我身边！现在的我好\n"
	.string "高兴！\p"
	.string "我们开始比赛前，还要赶快去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "这么干脆地拒绝我？\n"
	.string "{PLAYER}你让我很不爽！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "咳咳！\p"
	.string "啊，抱歉，我感冒了。但我的宝可梦\n"
	.string "没事。\p"
	.string "我的名字是{STR_VAR_3}\n"
	.string "，{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟。咳\l"
	.string "咳！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "我把{STR_VAR_3}的建议\n"
	.string "牢牢记在心里了，我的队伍是掌握\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "我天天都在训练它们，风雨无阻。\p"
	.string "我想就因此才会感冒吧。\p"
	.string "这就是我。要我做你的搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "谢谢，非常感激你！咳咳，咳咳！稍\n"
	.string "等，我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "啊，你不想吗？{PLAYER}，\n"
	.string "我们肯定能搭档得很好的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "你好！这里真是个强者云集的地方。\p"
	.string "我是{STR_VAR_3}，\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}个徒弟。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3}说这样的队\n"
	.string "伍不错——会\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "虽然有点害羞，不过，能让我跟你组\n"
	.string "队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "啊呀，谢谢！就算有点局促，我也会\n"
	.string "尽力的！\p"
	.string "我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "呜，不要拒绝呀！我感觉已经够糟了\n"
	.string "……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "我是{STR_VAR_3}，没骗\n"
	.string "你。我是{STR_VAR_1}的\l"
	.string "第{STR_VAR_2}个徒弟。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3}给我推荐了\n"
	.string "一支队伍。\p"
	.string "他是很认真地建议我的，所以我听了\n"
	.string "他的话，带了使用\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "和使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "如果可能的话，希望你能允许我成为\n"
	.string "你的搭档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "你真的接受我这个搭档？还好，否则\n"
	.string "我都不知道该怎么办了。\p"
	.string "你同意就好。我去登记一下我们的信\n"
	.string "息。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "哎？你为什么拒绝我？是在开我玩笑\n"
	.string "吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "我是{STR_VAR_1}，一个\n"
	.string "迷你裙！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "我有使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，现在带的\l"
	.string "就是它们。\p"
	.string "愿意成为我的搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "谢谢！我这就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "你不想做我的搭档？你一定会后悔的\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "嗨！\p"
	.string "我是短裤小子\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "想不想知道我有什么？学会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "学会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "你肯定想成为我的搭档，对吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "耶！我这就去登记，行吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "啊！如果是你和我的宝可梦搭档的话\n"
	.string "，我们会战无不胜的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "呀嗬！我是登山男\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "知道我有什么吗？使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "还不错吧？组个队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "呀嗬！那我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "我真的很想跟你并肩战斗。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "你好！我是{STR_VAR_1}\n"
	.string "，一个大姐姐！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "你知道我都训练了些什么吗？会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "觉得怎么样？一起组个队如何？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "棒极了！我现在就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "太让我失望了！\p"
	.string "我们两个组队的话，一定会是最棒的\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "哟！\p"
	.string "知道我是谁吗？我就是\n"
	.string "{STR_VAR_1}，垂钓者！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "我的队伍是使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "觉得怎样？要和我一起战斗吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "好的，好的！交给我吧！\p"
	.string "我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "我们的组合会是最完美的……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "非常高兴认识你。我是\n"
	.string "{STR_VAR_1}，一个千金\l"
	.string "小姐。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "陪同我的队伍是会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "希望我能符合你的要求。让我成为你\n"
	.string "的搭档吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "我发自内心地感激你。登记的事情就\n"
	.string "交给我吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "我肯定你会后悔没有和我搭档的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "我是铁人三项选手\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "我带着的是……会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！这就是我\l"
	.string "的队伍！\p"
	.string "如何？和我组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "哈哈，谢了！我马上去前台登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "我们两个一起的话，肯定会是极强的\n"
	.string "组合！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "嗨呀！我是捕虫少年\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "让你看看我有什么！会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "所以说，跟我组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "太棒了！\p"
	.string "我马上去前台进行登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "呃，我的宝可梦很优秀的。希望你不\n"
	.string "要为此后悔！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "你好！我是补习班学生\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "我培育的是使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "和使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "不觉得这组合不错吗？有没有兴趣一\n"
	.string "起组队呢？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "非常感谢！让我去登记吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "真遗憾啊……\p"
	.string "我还期待做你的搭档跟你学习呢……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "哟！让我告诉你我是谁！我就是富家\n"
	.string "少爷{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "猜猜看我有什么！会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "我就大发慈悲的给你个机会让你和我\n"
	.string "组个队吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "很高明的决定！\p"
	.string "我很快就会解决登记的程序的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "你居然拒绝杰出的我？你一定会为这\n"
	.string "个决定后悔的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "嗨！我是空手道王\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "我的伙伴是使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "和使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "请满足我的愿望吧！让我做你的搭档\n"
	.string "吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "哈哈！我立刻就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "我明白了……希望下次见面的时候你\n"
	.string "还能给我个机会……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "嗨，这里！我是\n"
	.string "{STR_VAR_1}，一个泳圈\l"
	.string "女孩！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "告诉你我有什么吧。会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！我能成为\l"
	.string "你的队友吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "谢谢！我马上去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "我们两个搭档的话，可是会变得很强\n"
	.string "的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "你好……我是灵异迷\n"
	.string "{STR_VAR_1}……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "我拥有使用{STR_VAR_1}\n"
	.string "的{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}……\p"
	.string "我看好你……我们组队……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "谢……我去登记……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "我好想加入……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "你好吗？我是\n"
	.string "{STR_VAR_1}，一个宝可\l"
	.string "梦培育家！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "我很细心地培育了两个伙伴！会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "怎么样？和我组队如何？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "太感谢了！\p"
	.string "我马上就去登记，请在这里稍等！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "我本来还很期待能成为你的搭档的…\n"
	.string "…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "你好呀！我是铁人三项选手\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "想知道我跟谁一起跑步吗？会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "怎样？想和我组队了吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "漂亮的决定！\p"
	.string "我马上就去搞定登记的事情！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "你和我，肯定会成为冠军的。真可惜\n"
	.string "……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "嗨！我是{STR_VAR_1}！\n"
	.string "一个铁人三项选手！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "跑步的时候我都会带着同样的伙伴—\n"
	.string "—会{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "这队伍还不坏，对吧？我们组队肯定\n"
	.string "不错！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "太好了！我一瞬间就能完成登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "我真的很想和你一起组队战斗……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "我是对战少女\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "我一直在训练使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "使用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "喜欢这样的组合吗？那么你我就一起\n"
	.string "组队吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "哇，谢谢！\p"
	.string "我这就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "我想，和你一起的话，我们会成为顶\n"
	.string "尖队伍的……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "我是铁人三项选手\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "我一直带着会使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "和会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}跑步！\p"
	.string "我们两个组队的话，不是很棒吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "谢谢！\p"
	.string "我去登记，现在立刻就去！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "呃，真可惜。我们应该能成为最强的\n"
	.string "队伍的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "我？我是泳圈男孩\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "我有什么？会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "嗯？你会和我组队的，是吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "好！\p"
	.string "我去登记！一起发挥我们的实力吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "我的宝可梦确实很强的……不和我组\n"
	.string "队真可惜啊。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "呀——嘿！叫我吉他手\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "我来介绍一下我的随从！一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "呀——嘿！非常棒，是不是？让我们\n"
	.string "在队伍里继续交流吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "呀——嘿！痛快！我这就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "我的宝可梦酷毙了！走着瞧，你会后\n"
	.string "悔的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "很高兴见到你。我是\n"
	.string "{STR_VAR_1}，一个绅士\l"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "我一直带着我信任的掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "我邀请你和我组一支二人战斗队，如\n"
	.string "何？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "啊，谢谢你对我的信任。我会去登记\n"
	.string "的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "这太不幸了……\p"
	.string "我只好去找下一个机会了……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "你好，我是{STR_VAR_1}\n"
	.string "，我是发烧友俱乐部的成员。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "我现在有一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "喜欢它们吗？那为什么不成为我的搭\n"
	.string "档呢？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "谢谢！我这就去找登记点！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "我的宝可梦是顶尖级别的……你竟然\n"
	.string "不懂得欣赏它们。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "那个！我是{STR_VAR_1}\n"
	.string "，一个达人！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "我带着的宝可梦是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "和我组个队如何？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "那个！我会马上去登记的！让我们做\n"
	.string "到最好吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "我希望你的决定不会让你后悔……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "你好，你好。我是\n"
	.string "{STR_VAR_1}，一个达人\l"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "我十分的热爱宝可梦。一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}——这就是\l"
	.string "我拥有的。\p"
	.string "你难道不想和我组一个队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "好，太好了。我马上就到登记点去。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "希望在我们下一次见面的时候你会回\n"
	.string "心转意。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "我是驯龙师{STR_VAR_1}\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "我一直训练的队伍是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "如何？和我搭档怎么样？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "好极，我一定会做到最好的！这就去\n"
	.string "登记，没问题吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "你不会找到比我再好的搭档了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "我是养鸟人{STR_VAR_1}\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "我有什么宝可梦？一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "你不觉得我们能构成一支像样的队伍\n"
	.string "吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "太好了，谢谢！我马上去找登记点！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "我的宝可梦和我都很强。太让人失望\n"
	.string "了。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "我是忍者小子\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "我的宝可梦队伍由一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}构成！\p"
	.string "让我们组一支队伍吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "耶！我去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "你会后悔没有接受我强大的宝可梦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "你好！我是阳伞姐姐\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "现在守护着我的是我的学会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "学会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "它们很棒吧？想和我们合作吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "真是太谢谢你了！\p"
	.string "我去登记点登记一下。我们都不要让\n"
	.string "彼此失望喔！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "我的宝可梦是很强的。太失望了呀…\n"
	.string "…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "你好。我是{STR_VAR_1}\n"
	.string "，一个昆虫狂！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "我也有宝可梦，没错。一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}——这就是\l"
	.string "我拥有的。\p"
	.string "那么有没有兴趣组一个队呢？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "好极了！了解！\p"
	.string "我不会用太多时间去登记的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "和我找到的宝可梦一起，我们不可能\n"
	.string "输的……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "喂，这里呀！我是水手\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "这是让我快乐和骄傲的宝贝们！一只\n"
	.string "掌握{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "当然你不会让我失望的我们会组成一\n"
	.string "个队的，对吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "这简直太出乎我的意料了！我现在就\n"
	.string "去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "我们本可以暴风雨般击败敌人的！太\n"
	.string "糟了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "嗨，我是{STR_VAR_1}。\n"
	.string "我是宝可梦收藏家。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "我收集的宝贝是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "很有气势，是不是？我们应该组一个\n"
	.string "队的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "太棒啦！\p"
	.string "好的，那就不要浪费时间了。我这就\n"
	.string "去帮我们登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "呃，这真让人心烦。你竟然不赏识我\n"
	.string "的宝可梦。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "你好，我是{STR_VAR_1}\n"
	.string "。一个宝可梦巡护员。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "守护我的伙伴是一只学会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "你不认为我们我们能构成一支令人印\n"
	.string "象深刻的队伍吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "太好了！我马上就去解决登记问题。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "下一次，你会选择我的宝可梦的，是\n"
	.string "吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "我的名字是{STR_VAR_1}\n"
	.string "。一个宝可梦巡护员！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "让你了解一下我的队伍。我有一只掌\n"
	.string "握{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "那么，你想不想加入我的小组？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "我们都要做到最好！我会很快去登记\n"
	.string "的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "我多希望下一次你会选择我的宝可梦\n"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "很高兴见到你。我是\n"
	.string "{STR_VAR_1}。我自认为\l"
	.string "我是一个香氛姐姐。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "我带着一只学会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "一只学会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}到处旅行。\p"
	.string "希望你会喜欢它们。你想成为我的搭\n"
	.string "档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "我很荣幸你同意了。刻不容缓，我这\n"
	.string "就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "没关系，我们下次再组队那也是非常\n"
	.string "美好的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "想知道我是谁吗？我是\n"
	.string "{STR_VAR_1}，一个遗迹\l"
	.string "迷！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "我拥有的宝可梦是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "很迷人，是吧？你和我，组个队如何\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "合理的决断！我这就去填登记申请表\n"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "嗯……我认为我的宝可梦很强的……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "我是精英训练家\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "我现在有的宝可梦是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。酷，是不\l"
	.string "是？\p"
	.string "你不觉得如果我们组队它们会变得更\n"
	.string "酷吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "酷！看我瞬间就搞定登记项目！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "我觉得我们能组成一支最强的队伍的\n"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "我是精英训练家\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "我的队伍里有一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "听起来很棒吧？我们组成一支队伍如\n"
	.string "何？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "听起来好极了！我最好现在就去登记\n"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "我一直在想怎样才能建一支坚韧的队\n"
	.string "伍……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "嘿！我是{STR_VAR_1}，\n"
	.string "怪兽狂！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "像我这样的人应该有什么呢？一只掌\n"
	.string "握{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，就是它们\l"
	.string "！\p"
	.string "无所不能！我们组了队一定会威震八\n"
	.string "方的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "说得好！这就去登记我们两个！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "我的宝可梦是无敌的！你可不要后悔\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "你好！我是营火专家\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "你知道我训练了一支什么队伍吗？一\n"
	.string "只掌握{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "你想说什么？想和我组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "好极了！我马上去登记点。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "好吧，那答应我下次一定要和我组队\n"
	.string "，好吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "我是{STR_VAR_1}，一个\n"
	.string "露营少年！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "我有一只学会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和一只$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "学会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "你不觉得和我组队会很有趣吗？我打\n"
	.string "赌一定会！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "耶！我这就去登记了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "下一次吧，好吗？我真的很想成为你\n"
	.string "的队友。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "你好！我是{STR_VAR_1}\n"
	.string "，一个野餐女孩！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "我带着的宝可梦是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "你有没有兴趣和我组一支队伍呢？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "哇，谢谢！我现在就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "今后还有机会，我会努力加入你的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "我是超能力者\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "我训练的两个伙伴是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "你想和我组个队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "理所当然！我会马上去登记的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "如果我们下次还能见面，我依然希望\n"
	.string "加入你。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "我是{STR_VAR_1}。一个\n"
	.string "超能力者。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}——这就是\l"
	.string "我的伙伴。\p"
	.string "建一支二人战斗组，你觉得如何？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "谢谢。接下来的申请就交给我了。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "我希望下一次我们还有机会。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "我是补习班学生\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "一只学会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "和一只学会{STR_VAR_1}\n"
	.string "的{STR_VAR_2}就是我的\l"
	.string "宝可梦搭档。\p"
	.string "我能成为你的战斗伙伴吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "哇，谢谢！我现在就去登记台！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "哎？那么，下一次我能加入你吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "你好！{STR_VAR_1}是我\n"
	.string "的名字！我是一个宝可梦培育家！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "我有的宝可梦是一只学会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "一只学会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "听起来不错吧？接下来，我们组个队\n"
	.string "如何？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "太好了！请允许我这就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "下一次你会答应我的，对吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "我是{STR_VAR_1}，我可\n"
	.string "以很自豪的说我是发烧友俱乐部的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "我心爱的宝可梦是一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "它们很聪明伶俐吧？我们应该组一支\n"
	.string "队伍！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "谢谢，亲爱的！我这就登记去！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "我心爱的宝可梦是最棒的，我会让你\n"
	.string "知道。真恼火！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "嗨，我是比基尼姐姐\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "一只学会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "和一只学会{STR_VAR_1}\n"
	.string "的{STR_VAR_2}是我的旅\l"
	.string "行伙伴。\p"
	.string "你和我，让我们组一支队伍吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "那太酷了！我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "下次见面时，你一定要让我加入你！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "怎么了？我是\n"
	.string "{STR_VAR_1}，一个铁人\l"
	.string "三项选手。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "我有一对高贵的宝可梦。一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "如果我们组队，那是多高雅的一件事\n"
	.string "呀，你觉得呢？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "太好了！你等我去登记一下，好不好\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "那么下一次见面的时候请让我加入你\n"
	.string "，好不好？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "我是铁人三项选手\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "另一只懂得如何使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。这就是我\l"
	.string "的搭档。\p"
	.string "你觉得如何？我们一定能组成一支很\n"
	.string "好的队伍，我这么觉得。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "我喜欢这个答案！我会很快去登记的\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "下一次你还会给我一个机会的，是不\n"
	.string "是？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "嘿！你好！我是\n"
	.string "{STR_VAR_1}，一个泳裤\l"
	.string "小伙子！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "给你看看我的队伍吧！一只掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "一只掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "不错，是不是？我很想和你组个队的\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "太棒了！我马上就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "如果我们再见面，你会和我组队的，\n"
	.string "你一定会的，对吧？$"

