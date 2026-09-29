TohjoFalls_GiovanniRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TohjoFalls_GiovanniRoom_OnTransition
	.byte 0

TohjoFalls_GiovanniRoom_OnTransition::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, TRUE, TohjoFalls_GiovanniRoom_SetScene
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 0
	end

TohjoFalls_GiovanniRoom_SetScene::
	setflag FLAG_HIDE_TOHJO_GIOVANNI
	goto_if_ne VAR_TOHJO_FALLS_GIOVANNI_STATE, 0, TohjoFalls_GiovanniRoom_DoNothing
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 1
	end

TohjoFalls_GiovanniRoom_DoNothing::
	end

TohjoFalls_GiovanniRoom_EventScript_Radio::
	msgbox TohjoFalls_GiovanniRoom_Text_RadioObject, MSGBOX_SIGN
	end

TohjoFalls_GiovanniRoom_Text_RadioObject::
	.string "是一台收音机……电池已经\n"
	.string "没电了……$"

TohjoFalls_GiovanniRoom_CancelScene::
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 0
	end

TohjoFalls_EventScript_GiovanniSceneRight::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	goto TohjoFalls_EventScript_GiovanniScene

TohjoFalls_EventScript_GiovanniSceneLeft::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	goto TohjoFalls_EventScript_GiovanniScene

TohjoFalls_EventScript_GiovanniScene::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiSpin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	@playse SE_M_PETAL_DANCE
	@delay 10
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	clearflag FLAG_HIDE_TOHJO_GIOVANNI
	addobject LOCALID_TOHJOFALLS_GIOVANNI
	waitse
	playbgm MUS_HG_RADIO_ROCKET, FALSE
	fadescreen FADE_FROM_WHITE
	delay 50
	turnobject  OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox TohjoFalls_GiovanniRoom_Text_Radio, MSGBOX_DEFAULT
	closemessage
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement 0
	waitmovement OBJ_EVENT_ID_FOLLOWER
	playse SE_PIN
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_TOHJOFALLS_GIOVANNI
	turnobject LOCALID_TOHJOFALLS_GIOVANNI, DIR_SOUTH
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniIntro, MSGBOX_DEFAULT
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, Common_Movement_WalkDown1
	waitmovement 0
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GIOVANNI_HNS, TohjoFalls_GiovanniRoom_Text_GiovanniDefeat
	playbgm MUS_HG_RADIO_ROCKET, FALSE
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, TohjoFalls_Movement_GiovanniTakenAback
	waitmovement 0
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniAfter, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, TohjoFalls_Movement_GiovanniLeave
	waitmovement 0 
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TOHJOFALLS_GIOVANNI
	playse SE_EXIT
	fadescreen FADE_FROM_BLACK
	delay 30

	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiSpin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	@playse SE_M_PETAL_DANCE
	@delay 10
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	fadedefaultbgm
	fadescreen FADE_FROM_WHITE
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 2
	release
	end

TohjoFalls_Movement_CelebiBegin:
	jump_in_place_up
	jump_in_place_up
	step_end

TohjoFalls_Movement_CelebiSpin:
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

TohjoFalls_Movement_GiovanniTakenAback:
	lock_facing_direction
	walk_slow_up
	unlock_facing_direction
	walk_slow_right
	walk_slow_right
	step_end

TohjoFalls_Movement_GiovanniLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	walk_in_place_down
	step_end

TohjoFalls_GiovanniRoom_Text_Radio:
	.string "收音机：...... .....\n"
	.string ".咳咳，我们是火箭队！经过三年的\l"
	.string "潜心蛰伏，我们如今浴火重生了！坂\l"
	.string "木老大！您能听到吗？！我们成功了\l"
	.string "！我们的首领在哪？他有在听吗？！$"

TohjoFalls_GiovanniRoom_Text_GiovanniIntro:
	.string "坂木：......\p"
	.string "我不知道你为何会来这里。\p"
	.string "不过，我必须警告你，这里可不是你\n"
	.string "这种小鬼该来的地方。\p"
	.string "你的眼神……让我想起了三\n"
	.string "年前站在我面前的那个小鬼……\l"
	.string "..\p"
	.string "你们有着一模一样的眼神……\n"
	.string ".\p"
	.string "......\p"
	.string "我正准备前往满金市，回应呼唤并与\n"
	.string "我的部下汇合。你打算挡我的路吗？$"

TohjoFalls_GiovanniRoom_Text_GiovanniBeforeBattle:
	.string "曾经的同伴正在需要我……\n"
	.string "我们绝不会重蹈三年前的覆辙！$"

TohjoFalls_GiovanniRoom_Text_GiovanniDefeat:
	.string "你这家伙到底是什么人？！$"

TohjoFalls_GiovanniRoom_Text_GiovanniAfter:
	.string "坂木：怎么可能……？这三\n"
	.string "年来全都白费了吗……？\p"
	.string "为什么又会是你这种小鬼，再次粉碎\n"
	.string "了我的梦想？！\p"
	.string "火箭队珍视的梦想，如今竟已彻底沦\n"
	.string "为幻影了吗……$"
