SinjohRuins_hns_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_OnFrame
    map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_hns_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SinjohRuins_hns_OnLoad
	.byte 0

SinjohRuins_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 8, SinjohRuins_StairsScene
	.2byte 0

SinjohRuins_hns_OnTransition::
    call_if_eq VAR_SINJOH_STORYLINE, 9, SinjohRuins_StevenLanding
    call_if_eq VAR_SINJOH_STORYLINE, 10, SinjohRuins_StevenLanding
    call_if_eq VAR_SINJOH_STORYLINE, 11, SinjohRuins_StevenLanding
    call_if_eq VAR_SINJOH_STORYLINE, 12, SinjohRuins_StevenLanding
    callnative SetTimeBasedEncounters
	end

SinjohRuins_StevenLanding::
    setobjectxyperm LOCALID_SINJOHRUINS_STEVEN, 24, 31
    setobjectmovementtype LOCALID_SINJOHRUINS_STEVEN, MOVEMENT_TYPE_FACE_UP
    return

SinjohRuins_hns_OnLoad::
    call_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_OpenRegirock
    call_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_OpenRegice
    call_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_OpenRegisteel
    call_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_OpenRegieleki
    call_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_OpenRegidrago
    call_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_OpenArceus
    end

SinjohRuins_OpenRegirock::
    setmetatile 9, 44, 0x378, FALSE
    setmetatile 8, 44, 0x0BE, TRUE
    return
SinjohRuins_OpenRegice::
    setmetatile 7, 48, 0x370, FALSE
    setmetatile 6, 48, 0x0BE, TRUE
    return
SinjohRuins_OpenRegisteel::
    setmetatile 8, 54, 0x370, FALSE
    setmetatile 7, 54, 0x0BE, TRUE
    return
SinjohRuins_OpenRegieleki::
    setmetatile 38, 44, 0x371, FALSE
    setmetatile 39, 44, 0x0BD, TRUE
    return
SinjohRuins_OpenRegidrago::
    setmetatile 37, 49, 0x371, FALSE
    setmetatile 38, 49, 0x0BD, TRUE
    return

SinjohRuins_OpenArceus::
    @left stairs
    setmetatile 17, 32, 0x089, FALSE
    setmetatile 17, 33, 0x089, FALSE
    setmetatile 17, 34, 0x089, FALSE
    setmetatile 17, 35, 0x089, FALSE
    setmetatile 17, 36, 0x089, FALSE
    setmetatile 18, 32, 0x091, FALSE
    setmetatile 18, 33, 0x091, FALSE
    setmetatile 18, 34, 0x091, FALSE
    setmetatile 18, 35, 0x091, FALSE
    setmetatile 18, 36, 0x091, FALSE
    setmetatile 19, 32, 0x091, FALSE
    setmetatile 19, 33, 0x091, FALSE
    setmetatile 19, 34, 0x091, FALSE
    setmetatile 19, 35, 0x091, FALSE
    setmetatile 19, 36, 0x091, FALSE
    @right stairs
    setmetatile 29, 32, 0x089, FALSE
    setmetatile 29, 33, 0x089, FALSE
    setmetatile 29, 34, 0x089, FALSE
    setmetatile 29, 35, 0x089, FALSE
    setmetatile 29, 36, 0x089, FALSE
    setmetatile 30, 32, 0x091, FALSE
    setmetatile 30, 33, 0x091, FALSE
    setmetatile 30, 34, 0x091, FALSE
    setmetatile 30, 35, 0x091, FALSE
    setmetatile 30, 36, 0x091, FALSE
    setmetatile 31, 32, 0x091, FALSE
    setmetatile 31, 33, 0x091, FALSE
    setmetatile 31, 34, 0x091, FALSE
    setmetatile 31, 35, 0x091, FALSE
    setmetatile 31, 36, 0x091, FALSE
    return

SinjohRuins_StairsScene::
    lock
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
    applymovement LOCALID_PLAYER, SinjohRuins_Movement_PlayerWalkRight
    opendoor 14, 52
	waitdooranim
    addobject LOCALID_SINJOHRUINS_STEVEN
    clearflag FLAG_HIDE_SINJOHRUINS_STEVEN
    applymovement LOCALID_SINJOHRUINS_STEVEN, Common_Movement_WalkDown1
    waitmovement LOCALID_SINJOHRUINS_STEVEN
    applymovement LOCALID_SINJOHRUINS_STEVEN, SinjohRuins_Movement_StevenWalkRight
    waitmovement 0
    closedoor 14, 52
	waitdooranim
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
    waitmovement LOCALID_SINJOHRUINS_STEVEN
    waitmovement 0
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
    special SpawnCameraObject
    applymovement OBJ_EVENT_ID_CAMERA, SinjohRuins_Movement_CameraPanUp
    waitmovement 0
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_SINJOHRUINS_STEVEN, 19, 52
    setobjectmovementtype LOCALID_SINJOHRUINS_STEVEN, MOVEMENT_TYPE_FACE_UP
    call SinjohRuins_OpenArceus
    special DrawWholeMapView
    delay 60
    applymovement OBJ_EVENT_ID_CAMERA, SinjohRuins_Movement_CameraPanDown
    waitmovement 0
    special RemoveCameraObject
    msgbox SinjohRuins_Text_StevenGotoStairs1, MSGBOX_AUTOCLOSE
    turnobject LOCALID_SINJOHRUINS_STEVEN, DIR_EAST
    delay 10
    turnobject LOCALID_PLAYER, DIR_WEST
    msgbox SinjohRuins_Text_StevenGotoStairs2, MSGBOX_AUTOCLOSE
    setvar VAR_SINJOH_STORYLINE, 9
    setvar VAR_PLATECOUNTER, 17
    applymovement LOCALID_SINJOHRUINS_STEVEN, SinjohRuins_Movement_StevenGoesToStairs
    waitmovement 0
    removeobject LOCALID_SINJOHRUINS_STEVEN
    setobjectxyperm LOCALID_SINJOHRUINS_STEVEN, 24, 31
    setobjectmovementtype LOCALID_SINJOHRUINS_STEVEN, MOVEMENT_TYPE_FACE_UP
    addobject LOCALID_SINJOHRUINS_STEVEN
    clearflag FLAG_HIDE_SINJOHRUINS_STEVEN
    setflag FLAG_HIDE_SINJOHRUINS_LAB_STEVEN
    setvar VAR_SINJOH_STORYLINE, 9
    release
    end

SinjohRuins_Text_StevenGotoStairs1:
    .string "大吾：这只能说明一件事。$"

SinjohRuins_Text_StevenGotoStairs2:
    .string "{PLAYER}。我们已经解读出\n"
    .string "其余的古代文字了……\p"
    .string "如果解读没有出错，在那座阶梯顶端\n"
    .string "的宝可梦，就是全宇宙最强大的存在\l"
    .string "。\p"
    .string "而作为丰缘联盟的前任冠军，我有责\n"
    .string "任确认你是否具备足够直面它的实力\l"
    .string "。\p"
    .string "等你准备好了，就到那个平台来找我\n"
    .string "吧。$"

SinjohRuins_Movement_StevenGoesToStairs:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    walk_diag_southeast
    walk_diag_southeast
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

SinjohRuins_Movement_CameraPanDown:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_diag_southwest
    walk_diag_southwest
    walk_diag_southwest
    walk_diag_southwest
    step_end

SinjohRuins_Movement_CameraPanUp:
    walk_diag_northeast
    walk_diag_northeast
    walk_diag_northeast
    walk_diag_northeast
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

SinjohRuins_Movement_StevenWalkRight:
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_up
    step_end

SinjohRuins_Movement_PlayerWalkRight:
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_up
    step_end
SinjohRuins_EventScript_TriggerStevenBattleRight::
    lock
    turnobject LOCALID_SINJOHRUINS_STEVEN, DIR_EAST
    msgbox SinjohRuins_Text_StevenReadytoBattle, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_EventScript_TriggerPlayerLeaveRight
    call SinjohRuins_EventScript_StevenBattle
    setvar VAR_SINJOH_STORYLINE, 10
    release
    end
SinjohRuins_EventScript_TriggerPlayerLeaveRight::
    closemessage
    applymovement LOCALID_PLAYER, Common_Movement_WalkRight1
    waitmovement 0
    release
    end
SinjohRuins_EventScript_TriggerStevenBattleLeft::
    lock
    turnobject LOCALID_SINJOHRUINS_STEVEN, DIR_WEST
    msgbox SinjohRuins_Text_StevenReadytoBattle, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_EventScript_TriggerPlayerLeaveLeft
    call SinjohRuins_EventScript_StevenBattle
    setvar VAR_SINJOH_STORYLINE, 10
    release
    end
SinjohRuins_EventScript_TriggerPlayerLeaveLeft::
    closemessage
    applymovement LOCALID_PLAYER, Common_Movement_WalkLeft1
    waitmovement 0
    release
    end 

SinjohRuins_Movement_StevenLeaveRight:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

SinjohRuins_Movement_StevenLeaveLeft:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

SinjohRuins_EventScript_StevenBattle::
    msgbox SinjohRuins_Text_ChallengeSteven, MSGBOX_AUTOCLOSE
    trainerbattle_no_intro TRAINER_STEVEN_HNS, SinjohRuins_Text_StevenDefeat
    msgbox SinjohRuins_Text_StevenAfterBattle, MSGBOX_AUTOCLOSE
    giveitem ITEM_STONE_PLATE
    msgbox SinjohRuins_Text_HealParty, MSGBOX_AUTOCLOSE
    fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox SinjohRuins_Text_StevenAfterPlate, MSGBOX_AUTOCLOSE
    return

SinjohRuins_Text_HealParty::
    .string "大吾：出发之前，让我先为你的宝可\n"
    .string "梦回复体力吧。$"

SinjohRuins_Text_StevenAfterPlate:
    .string "大吾：祝你好运，{PLAYER}\n"
    .string "。\p"
    .string "去吧，我就在你身后。$"

SinjohRuins_Text_StevenAfterBattle:
	.string "大吾：真没想到，居然又有一位训练\n"
	.string "家能将我击败至此。\p"
	.string "真是不可思议。\p"
	.string "收下这个吧，这是最后一块石板。$"

SinjohRuins_Text_StevenReadytoBattle:
    .string "大吾：{PLAYER}。\p"
    .string "从我第一次看到你眼中坚定的意志起\n"
    .string "，我就预感到会有这么一天。\p"
    .string "就让我来考验你与宝可梦之间的羁绊\n"
    .string "吧。\p"
    .string "准备好了吗？$"

SinjohRuins_Text_ChallengeSteven:
	.string "好，{PLAYER}{KUN}，\n"
	.string "既然你要全力以赴向我发起挑战，那\l"
	.string "就做好吃苦头的觉悟吧！$"

SinjohRuins_Text_StevenDefeat:
	.string "你……你已经做好了万全的\n"
	.string "准备。$"

SinjohRuins_EventScript_Steven::
    msgbox SinjohRuins_Text_StevenAfterPlate, MSGBOX_NPC
    end

SinjohRuins_EventScript_Sign::
    msgbox SinjohRuins_Text_Sign, MSGBOX_SIGN
    end

SinjohRuins_Text_Sign:
    .string "神都遗迹$"

