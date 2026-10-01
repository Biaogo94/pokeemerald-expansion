VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
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
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "满充：嗨！{PLAYER}！\p"
	.string "没想到会在这里见到我吧！\p"
	.string "能走到这里都是多亏了你！\p"
	.string "{PLAYER}，那次输给你让我\n"
	.string "变得更强了……\p"
	.string "但这次我不会再输了！\p"
	.string "为了给了我勇气和力量的宝可梦们——\n"
	.string "我一定要赢！\p"
	.string "那么……开始吧！$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "哇！{PLAYER}，你果然还是\n"
	.string "更强啊！$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "满充：{PLAYER}，虽然今天\n"
	.string "还是没能赢你……但总有一天我一定会\l"
	.string "追上你的！$"

VictoryRoad_1F_Text_WallyIntro:
	.string "满充：嗨！{PLAYER}！\p"
	.string "我比上一次变得更强了！想让你看\n"
	.string "看，{PLAYER}！\p"
	.string "那么……开始吧！$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "哇！{PLAYER}，你果然还是\n"
	.string "更强啊！$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "满充：这次我还是赢不了你……但总有\n"
	.string "一天，{PLAYER}，我会追上\l"
	.string "你……\p"
	.string "然后挑战宝可梦联盟！$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "我花了这么长时间到达这里，但这最\n"
	.string "后一段路实在是太长了……$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "我的梦想要再次终结了吗……$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "既然好不容易来到这里，就顺着这势\n"
	.string "头冲向冠军吧！要说谁能做到的话，\l"
	.string "那就是你！$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "我千里迢迢来这里可不是为了失败\n"
	.string "的。那是绝对不可能的事情！$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "不可能……我输了？$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "我输在了这里……\p"
	.string "这就是说我没有成为冠军的资格……$"

VictoryRoad_1F_Text_HopeIntro:
	.string "这条无尽却艰险的道路不愧于冠军之\n"
	.string "名。$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "你的战斗风格真完美……$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "看起来你有成为冠军的潜力。$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "冠军之路是什么？如果你赢了，我会\n"
	.string "告诉你的！$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "嘿！干得漂亮！$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "顺利地通过这里——这是对所有想成为\n"
	.string "宝可梦冠军的训练家们的最终考验。\p"
	.string "这也是它被称作冠军之路的原因。$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "我对来到这里的人没有什么话可说。\n"
	.string "上吧！$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "太丢脸了……$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "唔，继续走吧。我不介意。$"
