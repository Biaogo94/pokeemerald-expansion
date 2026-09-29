VictoryRoadKanto_1F_hns_MapScripts::
	.byte 0

VictoryRoadKanto_1F_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
VictoryRoadKanto_1F_EventScript_Item_MaxEther::
	finditem ITEM_MAX_ETHER
	end
VictoryRoadKanto_EventScript_Item_Dark_Pulse::
    finditem ITEM_TM_DARK_PULSE
    end

VictoryRoadKanto_1F_Trigger::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 5
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject LOCALID_VICTORYROAD_SILVER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 27, VictoryRoadKanto_1F_EventScript_SilverEnterLeft
	call_if_eq VAR_TEMP_0, 28, VictoryRoadKanto_1F_EventScript_SilverEnterMid
	call_if_eq VAR_TEMP_0, 29, VictoryRoadKanto_1F_EventScript_SilverEnterRight
	msgbox VictoryRoad_Text_RivalBefore, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, VictoryRoadKanto_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, VictoryRoadKanto_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, VictoryRoadKanto_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox VictoryRoad_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverLeave
	waitmovement 0
	removeobject LOCALID_VICTORYROAD_SILVER
	fadedefaultbgm
	release
	setvar VAR_ROUTE27_STATE, 3
	end

VictoryRoadKanto_1F_EventScript_SilverEnterLeft::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterLeft
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterMid::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterMid
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterRight::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterRight
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return


VictoryRoadKanto_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_5_HNS, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_5_HNS, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_5_HNS, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Movement_SilverEnterLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterMid:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverLeave:
	walk_down
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
	walk_left
	step_end

VictoryRoad_Text_RivalBefore:
    .string "慢着。\p"
    .string "……你是准备去挑战宝可梦\n"
    .string "联盟吗？\p"
    .string "……别笑死人了。\p"
    .string "你明明比我弱多了。\p"
    .string "我已经和以前不一样了。\p"
    .string "我现在带着最优秀、最强大的宝可梦\n"
    .string "。\p"
    .string "我是无敌的！\p"
    .string "{PLAYER}！我要向你挑战！$"

VictoryRoad_Text_RivalDefeat:
    .string "……我竟然赢不了……\n"
    .string "..\p"
    .string "我已经倾尽了全力……\p"
    .string "你所拥有的，还有我所欠缺的...\n"
    .string "...\p"
    .string "我开始明白那个龙之大师对我说过的\n"
    .string "话了……$"

VictoryRoad_Text_RivalAfter:
    .string "……我可还没放弃成为最强\n"
    .string "训练家的目标……\p"
    .string "我会查明白自己为什么赢不了，并且\n"
    .string "变得更强……\p"
    .string "等到了那时候，我一定会再来挑战\n"
    .string "你。\p"
    .string "然后全力以赴把你打趴下。\p"
    .string "……哼！在那之前，你可别\n"
    .string "懈怠了。$"
