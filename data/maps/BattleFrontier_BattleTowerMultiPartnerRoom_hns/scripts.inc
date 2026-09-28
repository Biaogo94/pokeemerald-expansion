BattleFrontier_BattleTowerMultiPartnerRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns
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

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns::
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

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_hns::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR_HNS, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsEast_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsWest_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
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
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM_HNS, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns:
	.string "请从聚集在这里的训练家之中寻找一\n"
	.string "位搭档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns:
	.string "{PLAYER}，你还没有找到组\n"
	.string "成双打搭档的伙伴。\p"
	.string "要放弃寻找，返回接待处吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns:
	.string "那么，请从聚集在这里的训练家之中\n"
	.string "寻找搭档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns::
	.string "感谢您挑选搭档。\p"
	.string "现在将为您带路前往多人对战室。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro_hns::
	.string "我是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}号徒弟。叫\l"
	.string "我{STR_VAR_3}就好！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1_hns::
	.string "根据{STR_VAR_1}的建议\n"
	.string "，我带来了1只学会了\l"
	.string "{STR_VAR_2}的\l"
	.string "{STR_VAR_3}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask_hns::
	.string "1只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "拜托了，请让我和你组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept_hns::
	.string "太谢谢了！我这就去办登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject_hns::
	.string "{PLAYER}，我真的很想和你\n"
	.string "一起组队啊......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro_hns::
	.string "我是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}号徒弟。我\l"
	.string "叫{STR_VAR_3}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1_hns::
	.string "我听从了{STR_VAR_1}的\n"
	.string "建议，挑选了1只学会了\l"
	.string "{STR_VAR_2}的\l"
	.string "{STR_VAR_3}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask_hns::
	.string "1只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "拜托了，我们一起组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept_hns::
	.string "非常感谢！我马上就去办好登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject_hns::
	.string "{PLAYER}，我本来希望能和\n"
	.string "你成为搭档的......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro_hns::
	.string "那个，我叫{STR_VAR_3}\n"
	.string "，是{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号徒弟。\p"
	.string "呜呜......\p"
	.string "对不起！我太紧张了，忍不住哭了出\n"
	.string "来......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1_hns::
	.string "因为{STR_VAR_3}给了我\n"
	.string "建议，我带了1只学会了\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask_hns::
	.string "1只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "呜呜......求求你，请一定要\n"
	.string "和我组队！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept_hns::
	.string "啊，真的吗？你答应了？太棒了！太\n"
	.string "赞了！嗷呜--！\p"
	.string "啊......对不起......\n"
	.string "我太高兴了，眼泪都流出来了...\l"
	.string "...\p"
	.string "我这就去登记。请千万别走开哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject_hns::
	.string "啊，可、可是......呜呜..\n"
	.string "....哇啊啊啊！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro_hns::
	.string "你好！我是{STR_VAR_3}\n"
	.string "！我是{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号徒弟！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1_hns::
	.string "我的队伍是{STR_VAR_3}\n"
	.string "推荐的。一只带着\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask_hns::
	.string "一只带着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，这就是我\l"
	.string "的宝可梦！很帅吧？\p"
	.string "来吧！我们组成搭档吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept_hns::
	.string "太好了！太棒了！好，我这就去登记\n"
	.string "，等我哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject_hns::
	.string "啊，为什么啊？{PLAYER}，\n"
	.string "我很想和你组队啊！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro_hns::
	.string "我是名声显赫的\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号徒弟，\l"
	.string "{STR_VAR_3}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1_hns::
	.string "我向{STR_VAR_3}请教了\n"
	.string "建议。一只是会用\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask_hns::
	.string "另一只是带着\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，这就是我\l"
	.string "的组合。\p"
	.string "请问，你愿意和我组成搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept_hns::
	.string "谢谢你！我这就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject_hns::
	.string "{PLAYER}，我一直希望能和\n"
	.string "你组成搭档的......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro_hns::
	.string "那个......你能抽空和我说话\n"
	.string "，我由衷地感到高兴。\p"
	.string "我是{STR_VAR_3}。是\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号徒弟..\l"
	.string "....$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1_hns::
	.string "{STR_VAR_3}给了我建议\n"
	.string "。我非常感激。\p"
	.string "我的队伍是一只带着\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask_hns::
	.string "一只带着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。我知道这\l"
	.string "样很冒昧......\p"
	.string "虽然觉得你可能不愿意，但能让我和\n"
	.string "你组成搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept_hns::
	.string "真的吗？真不敢相信！真不敢相信你\n"
	.string "愿意和我组队！我......我一\l"
	.string "定不会让你失望的！\p"
	.string "那个......如果真的可以，我\n"
	.string "这就立刻去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject_hns::
	.string "这样啊......我也觉得自己还\n"
	.string "不够优秀......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro_hns::
	.string "嗨，我是{STR_VAR_3}。\n"
	.string "我是{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号徒弟！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1_hns::
	.string "{STR_VAR_3}建议我这样\n"
	.string "组队：一只会用\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask_hns::
	.string "以及一只熟练使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。\p"
	.string "还不错吧？想不想和我组队啊？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept_hns::
	.string "好嘞，很高兴能和你组队！可别拖我\n"
	.string "的后腿哦！我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject_hns::
	.string "哈？为什么拒绝我？你真没眼光！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro_hns::
	.string "我是{STR_VAR_3}，是一\n"
	.string "名铁人三项运动员。我每天都忙着慢\l"
	.string "跑、训练和说唱。\p"
	.string "顺便一提，我还是\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号徒弟。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1_hns::
	.string "这是{STR_VAR_3}给我推\n"
	.string "荐的。一只会用\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask_hns::
	.string "和一只会用{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "虽然我很忙，但我花了很多心血来培\n"
	.string "育它们。\p"
	.string "让我们组成搭档，好好干一场吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept_hns::
	.string "太好了，很有干劲嘛！我去报个名，\n"
	.string "稍等一下哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject_hns::
	.string "我可是抽空从百忙中赶过来的！别这\n"
	.string "样嘛！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro_hns::
	.string "嗨！你好吗？\p"
	.string "我是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}号弟子\l"
	.string "{STR_VAR_3}。很高兴认\l"
	.string "识你！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1_hns::
	.string "听我说，听我说！一定要听听\n"
	.string "{STR_VAR_3}推荐给我的\l"
	.string "宝可梦。一只学会了\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。我当然\l"
	.string "培育得很棒啦！\p"
	.string "怎么样，要组队吗？我们一定会是很\n"
	.string "棒的组合！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept_hns::
	.string "太棒了，一定会很有趣的！我去报名\n"
	.string "啦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject_hns::
	.string "哎呀，真冷淡！我可是有人推荐的呢\n"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro_hns::
	.string "请容我自我介绍一下。我叫\n"
	.string "{STR_VAR_3}。\p"
	.string "我是{STR_VAR_1}的第\n"
	.string "{STR_VAR_2}号弟子。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1_hns::
	.string "我请教了{STR_VAR_3}的\n"
	.string "高见，培育了一只学会了\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask_hns::
	.string "以及一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。\p"
	.string "请务必与我组成双打搭档！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept_hns::
	.string "哦......太高兴了！我一定会\n"
	.string "竭尽全力的！\p"
	.string "报名的事情就交给我吧！请稍等片刻\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject_hns::
	.string "我一直希望能和你组队呢，\n"
	.string "{PLAYER}......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro_hns::
	.string "呀！你跟我说话了！我......\n"
	.string "我太高兴了！\p"
	.string "我是{STR_VAR_3}！是\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号弟子！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1_hns::
	.string "听了{STR_VAR_3}的建议\n"
	.string "，我培育了一只掌握了\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask_hns::
	.string "和一只掌握了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。\p"
	.string "求求你，能满足我的愿望吗？我想成\n"
	.string "为你的双打搭档！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept_hns::
	.string "呀！我......我头都晕乎乎的\n"
	.string "了！太感谢你了！我这就去报名！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject_hns::
	.string "哇啊！你就一点都不同情我吗？不过\n"
	.string "这样反而更帅了......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro_hns::
	.string "唷呼！我是{STR_VAR_1}\n"
	.string "的第{STR_VAR_2}号弟子\l"
	.string "！\p"
	.string "我叫{STR_VAR_3}，你好\n"
	.string "你好！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1_hns::
	.string "我的师父{STR_VAR_3}推\n"
	.string "荐了一只精通\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask_hns::
	.string "和一只精通{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "很厉害吧？你要和我组队，对吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept_hns::
	.string "好咧，太棒了！我马上就去搞定报名\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject_hns::
	.string "哇啊！{PLAYER}，你还挺精\n"
	.string "明的嘛！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro_hns::
	.string "喂！出大事了！今天是对战塔开放的\n"
	.string "最后一天！\p"
	.string "...... ...... ..\n"
	.string ".... ...... ....\l"
	.string ".. ......开玩笑的啦！\p"
	.string "大家都叫我{STR_VAR_3}\n"
	.string "，我也这么叫自己！我是\l"
	.string "{STR_VAR_1}的第100\l"
	.string "0号弟子！其实是第\l"
	.string "{STR_VAR_2}号啦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1_hns::
	.string "{STR_VAR_3}给了我一些\n"
	.string "建议。学会了\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask_hns::
	.string "学会了{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。这两种我\l"
	.string "各有十只！其实各自只有一只啦！\p"
	.string "怎么样？要和我一起挑战双打对战吗\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept_hns::
	.string "太棒啦！为了表示感谢，送你一只宝\n"
	.string "可梦吧！\p"
	.string "开玩笑的啦！但我这就去办登记手续\n"
	.string "，等我哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject_hns::
	.string "呜，太无情了！看我不把对战塔给掀\n"
	.string "个底朝天！\p"
	.string "开玩笑的啦，我才不会呢！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro_hns::
	.string "哟，看我摇摆又摇摆！宝可梦指挥得\n"
	.string "帅不帅！\p"
	.string "我是会唱饶舌的水手\n"
	.string "{STR_VAR_3}。可别把我\l"
	.string "和哭哭啼啼的家伙混为一谈！\p"
	.string "我是{STR_VAR_1}门下第\n"
	.string "{STR_VAR_2}号学徒。瞧\l"
	.string "不起我可会让你吃大亏！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1_hns::
	.string "听从了{STR_VAR_3}的真\n"
	.string "传提议，组建起我引以为傲的战力！\l"
	.string "一只会用{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask_hns::
	.string "再加上一只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}！\p"
	.string "难得相逢必须好好庆祝，组队拿下胜\n"
	.string "利才算够酷！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept_hns::
	.string "嘿，嘿，我喜欢你的风格！这就去把\n"
	.string "咱俩的名字登记了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject_hns::
	.string "哦，嘿，{PLAYER}，你也太\n"
	.string "无情啦！恕我冒昧这么说！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro_hns::
	.string "咿哈--！哎，别跑呀！我只是逗你\n"
	.string "玩的！\p"
	.string "你好呀！我是\n"
	.string "{STR_VAR_3}！是\l"
	.string "{STR_VAR_1}门下的第\l"
	.string "{STR_VAR_2}号学徒！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1_hns::
	.string "{STR_VAR_3}指导了我该\n"
	.string "怎么做。所以选了一只会用\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask_hns::
	.string "还有一只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。\p"
	.string "那么，你怎么说？来吧，让我今天开\n"
	.string "心一下！\p"
	.string "求求你了！让我跟你组队吧，别让我\n"
	.string "难过！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept_hns::
	.string "耶！运气站在我这边！真是太让人开\n"
	.string "心了！\p"
	.string "在奔赴战场之前，我这就去办登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject_hns::
	.string "你拒绝了我？{PLAYER}，你\n"
	.string "让我好沮丧啊！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro_hns::
	.string "咳咳！\p"
	.string "啊，不好意思，我感冒了。不过我的\n"
	.string "宝可梦很有精神。\p"
	.string "我叫{STR_VAR_3}，是\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号学徒。咳\l"
	.string "咳！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1_hns::
	.string "我听从了{STR_VAR_3}的\n"
	.string "建议，组建了由一只会用\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和一只$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}组成的队伍\l"
	.string "。\p"
	.string "我每天都和它们一起训练，风雨无阻\n"
	.string "。\p"
	.string "我觉得这可能就是我感冒的原因吧。\p"
	.string "情况就是这样。你愿意和我做搭档吗\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept_hns::
	.string "太感谢了！咳，咳！请稍等，我这就\n"
	.string "去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject_hns::
	.string "啊，不行吗？{PLAYER}，我\n"
	.string "觉得我们很合得来呢。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro_hns::
	.string "啊，你好！真是好紧张啊。\p"
	.string "我是{STR_VAR_3}。是\n"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号学徒。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1_hns::
	.string "{STR_VAR_3}说这个组合\n"
	.string "很不错--一只会用\l"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和一只$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "虽然我挺不好意思开口的，但你能让\n"
	.string "我加入你的队伍吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept_hns::
	.string "啊，天哪，谢谢你！虽然有点害羞，\n"
	.string "但我会全力以赴的！\p"
	.string "我这就去办理登记手续。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject_hns::
	.string "啊，请别拒绝我呀！我已经够难为情\n"
	.string "的了......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro_hns::
	.string "我就是{STR_VAR_3}，千\n"
	.string "真万确。我是\l"
	.string "{STR_VAR_1}的第\l"
	.string "{STR_VAR_2}号学徒。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1_hns::
	.string "{STR_VAR_3}给我推荐了\n"
	.string "队伍。\p"
	.string "因为那建议听上去很中肯，所以我决\n"
	.string "定带上会用{STR_VAR_1}\l"
	.string "的{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "如果可以的话，我希望你能接受让我\n"
	.string "成为你的多打搭档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept_hns::
	.string "你真的愿意接受我吗？要是拒绝的话\n"
	.string "可就太糟糕了。\p"
	.string "既然你同意了，那就好。我去为我们\n"
	.string "两个人办理登记手续。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject_hns::
	.string "嗯？你为什么要拒绝呢？你是在开玩\n"
	.string "笑吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro_hns::
	.string "我是{STR_VAR_1}，是个\n"
	.string "迷你裙哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1_hns::
	.string "我带着的是一只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有一只$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。我随身带\l"
	.string "着它们呢。\p"
	.string "愿意做我的搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept_hns::
	.string "谢谢你！我去办理登记手续咯！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject_hns::
	.string "你不想做我的搭档吗？你之后一定会\n"
	.string "后悔的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro_hns::
	.string "你好！\p"
	.string "我是短裤小子\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1_hns::
	.string "想知道我带了什么吗？一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "你会成为我的搭档伙伴，对吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept_hns::
	.string "太好了！我去办理登记手续咯！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject_hns::
	.string "啊！要是你和我的宝可梦组队的话，\n"
	.string "我们肯定所向披靡的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro_hns::
	.string "呀呵！我是登山男\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1_hns::
	.string "知道我随身带了什么吗？我会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask_hns::
	.string "我会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "听起来很棒吧？要不要和我组成搭档\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept_hns::
	.string "呀呵！那我去办理登记手续啦。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject_hns::
	.string "我本来很想和你并肩作战的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro_hns::
	.string "你好呀！我是\n"
	.string "{STR_VAR_1}，是顺眼的\l"
	.string "美女哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1_hns::
	.string "你知道我都培育了什么宝可梦吗？一\n"
	.string "只学会了{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "你觉得怎么样？想和我一起组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept_hns::
	.string "太棒了！我现在就去办好登记手续！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject_hns::
	.string "真让人失望！\p"
	.string "只要我们两人联手，原本肯定是最强\n"
	.string "搭档的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro_hns::
	.string "哟！\p"
	.string "你知道我是谁吗？我就是钓客\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1_hns::
	.string "我带着的队伍有一只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask_hns::
	.string "一只会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "那么，你觉得如何？愿意与我并肩作\n"
	.string "战吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept_hns::
	.string "好极了，好极了！就交给我吧！\p"
	.string "我这就去给我们登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject_hns::
	.string "我们本来还挺合得来的......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro_hns::
	.string "初次见面，幸会。我是大小姐\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1_hns::
	.string "陪伴着我的队伍是一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "希望您能满意。因为我衷心希望能与\n"
	.string "您结为搭档。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept_hns::
	.string "衷心感谢您。登记手续就交给我来办\n"
	.string "理吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject_hns::
	.string "没能选我做搭档，我相信您一定会后\n"
	.string "悔的。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro_hns::
	.string "我是铁人三项运动员\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1_hns::
	.string "我的宝可梦是......一只学会\n"
	.string "了{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！这就是\l"
	.string "我的搭档组合！\p"
	.string "拜托啦！你愿意和我组成双打搭档吗\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept_hns::
	.string "太棒了，谢啦！我去柜台那边登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject_hns::
	.string "要是我们俩联手的话，肯定强得不行\n"
	.string "呢！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro_hns::
	.string "嗨！我是捕虫少年\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1_hns::
	.string "瞧瞧我的宝可梦！一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "所以，听我说！你想和我组成双打搭\n"
	.string "档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept_hns::
	.string "收到！\p"
	.string "我去柜台那边把登记手续办了。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject_hns::
	.string "唉，我的宝可梦可厉害了。希望你别\n"
	.string "后悔哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro_hns::
	.string "你好！我是学生\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1_hns::
	.string "我培育的宝可梦是一只会使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask_hns::
	.string "和一只会使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。\p"
	.string "还挺不错的吧？你愿意和我组成双打\n"
	.string "搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept_hns::
	.string "非常感谢！我去办理登记手续。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject_hns::
	.string "真遗憾......\p"
	.string "我还想着做你的搭档，能从你身上学\n"
	.string "到点东西呢......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro_hns::
	.string "哟！让我来做个自我介绍！本少爷可\n"
	.string "是富家少爷{STR_VAR_1}\l"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1_hns::
	.string "猜猜我带了什么！一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "本少爷大发慈悲，给你一个和我组成\n"
	.string "双打搭档的机会吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept_hns::
	.string "明智的选择！\p"
	.string "我会赶快把登记手续办好的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject_hns::
	.string "居然连我你都拒绝？你一定会后悔这\n"
	.string "个决定的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro_hns::
	.string "喝啊！我是格斗家\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1_hns::
	.string "我的伙伴是1只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask_hns::
	.string "和1只会用{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "拜托了，请成全我的心愿！让我成为\n"
	.string "你的多打搭档吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept_hns::
	.string "喝啊！我这就前去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject_hns::
	.string "这样啊......希望下次见面时\n"
	.string "能有机会合作......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro_hns::
	.string "嗨，你好！我是玩水生\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1_hns::
	.string "告诉你我都带了谁吧。1只会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask_hns::
	.string "1只会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！能让我加\l"
	.string "入你的多打队伍吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept_hns::
	.string "谢谢你！我这就去给我们办登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject_hns::
	.string "要是能成为搭档，我们本来可以变得\n"
	.string "超强的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro_hns::
	.string "向你问候......我是灵异狂\n"
	.string "{STR_VAR_1}.....\l"
	.string ".$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1_hns::
	.string "我携带着1只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及1只$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}.....\l"
	.string ".\p"
	.string "我请求你......和我组成多打\n"
	.string "搭档吧......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept_hns::
	.string "谢谢你......我去进行登记.\n"
	.string ".....$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject_hns::
	.string "我曾那么渴望能与你组队.....\n"
	.string ".$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro_hns::
	.string "你好啊！我是\n"
	.string "{STR_VAR_1}，是一名宝\l"
	.string "可梦培育家！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1_hns::
	.string "我培育了很棒的孩子哦！1只会\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask_hns::
	.string "1只会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "怎么样？想和我组个多打队伍吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept_hns::
	.string "太感谢了！\p"
	.string "我去处理一下登记手续，你就在这里\n"
	.string "稍等一下哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject_hns::
	.string "我本来很期待能成为你的搭档呢..\n"
	.string "....$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro_hns::
	.string "嗨，你好！我是铁人三项运动员\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1_hns::
	.string "想知道和我一起奔跑的伙伴吗？1只\n"
	.string "会{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask_hns::
	.string "1只会{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "怎么样？想和我组个多打队伍吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept_hns::
	.string "太棒了！\p"
	.string "我这就麻利地去办好登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject_hns::
	.string "要是你和我联手，肯定是最强的。真\n"
	.string "可惜啊......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro_hns::
	.string "嗨，你好！我叫\n"
	.string "{STR_VAR_1}！是一名铁\l"
	.string "人三项运动员！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1_hns::
	.string "我和我耐力超群的队伍一起奔跑--\n"
	.string "一只学会了{STR_VAR_1}\l"
	.string "的{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "很不错吧？我们一起组成双打搭档吧\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept_hns::
	.string "太好了！我这就去登记，一眨眼就好\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject_hns::
	.string "我真的很想作为你的搭档并肩作战的\n"
	.string "说......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro_hns::
	.string "我是对战少女\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1_hns::
	.string "我一直在严格锻炼一只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask_hns::
	.string "一只会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "你喜欢这个组合吗？我和你组队怎么\n"
	.string "样？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept_hns::
	.string "哎呀，多谢！\p"
	.string "我这就去办理登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject_hns::
	.string "要是和你联手，我觉得一定能组成终\n"
	.string "极的双打搭档的说......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro_hns::
	.string "我是铁人三项运动员\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1_hns::
	.string "我和一只懂得使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}一起跑步，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask_hns::
	.string "还有一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}！\p"
	.string "我们如果组成双打搭档，那不就很棒\n"
	.string "吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept_hns::
	.string "谢谢你！\p"
	.string "我这就去给我们登记，马上就好！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject_hns::
	.string "哎呀，真遗憾。要是能联手，我们肯\n"
	.string "定会是最强悍的双打搭档！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro_hns::
	.string "我吗？我是玩水生\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1_hns::
	.string "我都带了什么？一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "呐？你会和我组队，对吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept_hns::
	.string "好耶！\p"
	.string "我去登记啦！让我们一起大显身手吧\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject_hns::
	.string "我的宝可梦肯定很强的......\n"
	.string "你不想组队真是太遗憾了。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro_hns::
	.string "耶~嘿！叫我吉他手\n"
	.string "{STR_VAR_1}吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1_hns::
	.string "瞧瞧我的阵容！一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "耶~嘿！够狂野吧？我们一定要在双\n"
	.string "打中来场二重奏！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept_hns::
	.string "耶~嘿！太棒了！我这就去办登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject_hns::
	.string "我的宝可梦坚若磐石！你会后悔的，\n"
	.string "我敢说！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro_hns::
	.string "很高兴认识你。我是绅士\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1_hns::
	.string "伴随我的是我值得信赖的、掌握着\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask_hns::
	.string "掌握着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "可否邀请你与我结成双打搭档？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept_hns::
	.string "啊，非常感谢你的信任。我这就去办\n"
	.string "好登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject_hns::
	.string "那可真是太遗憾了......\p"
	.string "期待下一次与你合作的机会....\n"
	.string "..$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro_hns::
	.string "你好，我是{STR_VAR_1}\n"
	.string "，是一名宝可梦发烧友。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1_hns::
	.string "我现在带着学会了招式\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask_hns::
	.string "掌握着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "你觉得怎么样？要不要来做我的双打\n"
	.string "搭档？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept_hns::
	.string "谢谢你！登记的事就包在我身上了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject_hns::
	.string "我的宝可梦可是一流的......\n"
	.string "你没能领会到真是太可惜了。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro_hns::
	.string "哼！老夫是达人\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1_hns::
	.string "经老夫千锤百炼的宝可梦是掌握着\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask_hns::
	.string "掌握着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "意下如何？要和老夫组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept_hns::
	.string "好！老夫这就去登记！让我们全力以\n"
	.string "赴吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject_hns::
	.string "但愿你的选择真的是正确的....\n"
	.string "..$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro_hns::
	.string "你好呀。我是达人\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1_hns::
	.string "我把我的宝可梦培育得很充分。掌握\n"
	.string "着{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask_hns::
	.string "掌握着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}--这就是\l"
	.string "我的队伍。\p"
	.string "要不要和我组队试试看？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept_hns::
	.string "很好，很好。我这就去办登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject_hns::
	.string "也许下次见面时我们可以组队呢。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro_hns::
	.string "我是龙使者{STR_VAR_1}\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1_hns::
	.string "我精心锻炼出的搭档是掌握着\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask_hns::
	.string "掌握着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "怎么样？要当我的搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept_hns::
	.string "好，我会全力以赴的！我现在就去登\n"
	.string "记，可以吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject_hns::
	.string "You're not going to find many tougher\n"
	.string "partners than me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro_hns::
	.string "我是养鸟人{STR_VAR_1}\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1_hns::
	.string "What POKéMON do I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask_hns::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don't you think we'd make a decent\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept_hns::
	.string "Great, thanks!\n"
	.string "I'll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject_hns::
	.string "My POKéMON and I are strong.\n"
	.string "What a letdown.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro_hns::
	.string "我是忍者小子\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1_hns::
	.string "My POKéMON team consists of one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask_hns::
	.string "一只带着{STR_VAR_1}的\n"
	.string "{STR_VAR_2}组成的！\p"
	.string "我们一起来组队吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept_hns::
	.string "Yay!\n"
	.string "Let me go register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject_hns::
	.string "You'll regret not having my tough\n"
	.string "POKéMON on your side!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro_hns::
	.string "Hello!\n"
	.string "I'm PARASOL LADY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1_hns::
	.string "Escorting me now are my {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask_hns::
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Aren't they nice?\n"
	.string "Care to join us in a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept_hns::
	.string "Thanks a bunch!\p"
	.string "I'll go register at the counter.\n"
	.string "Let's not disappoint each other!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject_hns::
	.string "My POKéMON are tremendously strong.\n"
	.string "How disappointing…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro_hns::
	.string "Hello.\n"
	.string "I'm {STR_VAR_1}, and I'm a BUG MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1_hns::
	.string "I have found my POKéMON, yes.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask_hns::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they are what I found.\p"
	.string "Could I interest you in forming\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept_hns::
	.string "Okay!\n"
	.string "Understood!\p"
	.string "I won't be long with the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject_hns::
	.string "With the POKéMON I found, we wouldn't\n"
	.string "have lost…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro_hns::
	.string "Ahoy, there!\n"
	.string "I'm SAILOR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1_hns::
	.string "Let me show you my pride and joy!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask_hns::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Of course you're not going to turn\n"
	.string "me down. We will team up, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept_hns::
	.string "I didn't expect any less!\n"
	.string "I'll go register now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject_hns::
	.string "我们本来能横扫对手的！真可惜！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro_hns::
	.string "你好，我是{STR_VAR_1}\n"
	.string "。我是一名收藏家。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1_hns::
	.string "我收藏中的珍宝是学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask_hns::
	.string "学会了{STR_VAR_1}的\n"
	.string "{STR_VAR_2}！\p"
	.string "很棒吧？我们来组队吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept_hns::
	.string "太棒了！\p"
	.string "那么事不宜迟，我现在就去帮我们两\n"
	.string "个登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject_hns::
	.string "唉，真让人沮丧。你完全不懂得欣赏\n"
	.string "我的宝可梦。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro_hns::
	.string "你好啊，我是\n"
	.string "{STR_VAR_1}。我是一名\l"
	.string "宝可梦巡护员。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1_hns::
	.string "伴我同行的是一只会使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "你不觉得我们能组成一支令人瞩目的\n"
	.string "双打搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept_hns::
	.string "太棒了！我现在就去办理登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject_hns::
	.string "下次一定要选我的宝可梦哦，好吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro_hns::
	.string "我的名字叫{STR_VAR_1}\n"
	.string "。我是一名宝可梦巡护员！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1_hns::
	.string "让我来介绍一下我的队伍。我有一只\n"
	.string "学会了{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "要不要和我的这群小家伙组成双打搭\n"
	.string "档呢？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept_hns::
	.string "我们一定会全力以赴的！我马上就去\n"
	.string "搞定登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject_hns::
	.string "希望下次你能选我的宝可梦。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro_hns::
	.string "很高兴认识你。我是\n"
	.string "{STR_VAR_1}。我是一名\l"
	.string "芳香姐姐。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1_hns::
	.string "与我一同旅行的是一只会使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask_hns::
	.string "一只会使用{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "希望它们合你的心意。你愿意成为我\n"
	.string "的搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept_hns::
	.string "承蒙赏识，不胜荣幸。我这就去办理\n"
	.string "登记手续。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject_hns::
	.string "如果下次相遇时能与你组成双打搭档\n"
	.string "，那就太好了。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro_hns::
	.string "想知道我是谁吗？我就是遗迹狂迷\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1_hns::
	.string "我带在身边的宝可梦有一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "很有意思吧？要不要和我一起组队？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept_hns::
	.string "真是明智的决定！我这就去办理登记\n"
	.string "手续。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject_hns::
	.string "唔......我觉得我的宝可梦挺\n"
	.string "强的啊......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro_hns::
	.string "我是精英训练家\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1_hns::
	.string "我现在带的宝可梦是一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。很帅吧\l"
	.string "？\p"
	.string "你不觉得要是我们组成双打搭档，会\n"
	.string "非常帅气吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept_hns::
	.string "太棒了！我马上就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject_hns::
	.string "我本来还以为我们能成为最棒的组合\n"
	.string "呢。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro_hns::
	.string "我是精英训练家\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1_hns::
	.string "我培育的队伍里有一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "听起来怎么样？要不要和我组成双打\n"
	.string "搭档？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept_hns::
	.string "太好了！我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject_hns::
	.string "我本以为我们能成为一支强大的队伍\n"
	.string "呢......$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro_hns::
	.string "嘿！我是宝可梦狂\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1_hns::
	.string "像我这样的人带的是什么？是一只学\n"
	.string "会了{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}，就是这\l"
	.string "么回事！\p"
	.string "来吧！我们组成搭档去大闹一场！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept_hns::
	.string "好主意！我这就去把我们俩都登记上\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject_hns::
	.string "我的宝可梦可是很凶猛的！就算你之\n"
	.string "后后悔了我可不管哦！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro_hns::
	.string "哟！我是营火人\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1_hns::
	.string "你知道我特训出来的成果吗？就是学\n"
	.string "会了{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "怎么样，意下如何？要和我组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept_hns::
	.string "好嘞！我这就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject_hns::
	.string "下次再遇到的时候，一定要和我组队\n"
	.string "啊！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro_hns::
	.string "我是{STR_VAR_1}，是个\n"
	.string "野营少年！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1_hns::
	.string "我培育了一只会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有一只$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "你不觉得一起组队会很有趣吗？肯定\n"
	.string "超级好玩的！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept_hns::
	.string "太好啦！我去登记咯！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject_hns::
	.string "下次一定要哦！我想和你组成一队。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro_hns::
	.string "你好！我是{STR_VAR_1}\n"
	.string "，是个野餐女孩！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1_hns::
	.string "我带的宝可梦是掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask_hns::
	.string "掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "有兴趣和我组成双打搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept_hns::
	.string "哎呀，谢谢！我现在就去登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject_hns::
	.string "下次有机会的话，真希望能和你组队\n"
	.string "呢。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro_hns::
	.string "我是超能力者\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1_hns::
	.string "我培育的两只宝可梦是掌握\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask_hns::
	.string "掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "你想和我组成双打搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept_hns::
	.string "没问题！登记的事就交给我吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject_hns::
	.string "如果我们再次相遇，那时真想和你组\n"
	.string "队啊。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro_hns::
	.string "我是{STR_VAR_1}。是一\n"
	.string "名超能力者。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1_hns::
	.string "掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask_hns::
	.string "掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}--它们是\l"
	.string "我的弟子。\p"
	.string "和我组成双打搭档的想法，难道不让\n"
	.string "你心动吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept_hns::
	.string "谢谢你。我这就去办登记。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject_hns::
	.string "希望日后还能有机会与你并肩作战。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro_hns::
	.string "我是读书男童\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask_hns::
	.string "以及会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}就是我的宝\l"
	.string "可梦搭档。\p"
	.string "可以让我成为你的双打搭档吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept_hns::
	.string "哇，谢谢你！我这就去柜台登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject_hns::
	.string "拜托了，下次可以和我组队吗？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro_hns::
	.string "嗨！我叫{STR_VAR_1}！\n"
	.string "是个宝可梦培育家！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1_hns::
	.string "我培育的宝可梦是会用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}和$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}。\p"
	.string "听起来很有意思吧？那么，要不要和\n"
	.string "我组成双打搭档？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept_hns::
	.string "好嘞！登记的事就包在我身上！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject_hns::
	.string "下次一定要和我组队哦，说好了？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro_hns::
	.string "我是{STR_VAR_1}，我可\n"
	.string "以自豪地说，我是一名宝可梦狂热家\l"
	.string "。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1_hns::
	.string "我培育的心爱宝可梦是一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}。\p"
	.string "它们是不是超级可爱？我们组个队伍\n"
	.string "吧！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept_hns::
	.string "谢谢你，亲爱的！我这就去登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject_hns::
	.string "我心爱的宝可梦可是最棒的，你给我\n"
	.string "记好了。真让人不爽！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro_hns::
	.string "嗨，我是游泳健将\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1_hns::
	.string "会用{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask_hns::
	.string "和一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。\p"
	.string "你和我，一起组个双打队伍吧。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept_hns::
	.string "太棒了！我这就去登记我们两个。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject_hns::
	.string "下次再见面的话，你可得跟我组队哦\n"
	.string "！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro_hns::
	.string "嗨，你好！我是\n"
	.string "{STR_VAR_1}，是一名铁\l"
	.string "人三项运动员。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1_hns::
	.string "我手头有两只相当不错的宝可梦。一\n"
	.string "只学会了{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "如果我们一起组队的话肯定很酷，怎\n"
	.string "么样？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept_hns::
	.string "太好了！你先等我去登记一下，好吗\n"
	.string "？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject_hns::
	.string "下次可要让我加入你哦，怎么样？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro_hns::
	.string "我是铁人三项运动员\n"
	.string "{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1_hns::
	.string "掌握{STR_VAR_1}的\n"
	.string "{STR_VAR_2}，以及$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask_hns::
	.string "还有一只懂得使用\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}。这就是我\l"
	.string "的组合。\p"
	.string "你觉得怎么样？我觉得我们能组成一\n"
	.string "个很棒的队伍。$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept_hns::
	.string "我喜欢这个回答！我这就快快去完成\n"
	.string "登记！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject_hns::
	.string "下次你还会给我机会一起组队的，对\n"
	.string "吧？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro_hns::
	.string "嗨，你好呀！我是\n"
	.string "{STR_VAR_1}，是一名游\l"
	.string "泳健将！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1_hns::
	.string "看看我培育的宝可梦吧！一只学会了\n"
	.string "{STR_VAR_1}的\l"
	.string "{STR_VAR_2}，还有$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask_hns::
	.string "一只学会了{STR_VAR_1}\n"
	.string "的{STR_VAR_2}！\p"
	.string "很棒吧？要是能组个队就更棒了！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept_hns::
	.string "非常感谢！我这就去把登记办妥！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject_hns::
	.string "如果下次再遇到，你可得和我组队。\n"
	.string "会和我组队的，对吧？$"

