TrainerHill_Entrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_hns_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_hns_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_hns_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_hns_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_hns_OnFrame
	.byte 0

TrainerHill_Entrance_hns_OnTransition:
	clearflag FLAG_LIMIT_TO_50
	calculatemonstats
	setflag FLAG_TEMP_HIDE_FOLLOWER
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerHill_Entrance_hns_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_TryFaceAttendant
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_hns_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_hns_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_hns_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_hns_OnReturn:
	addobject LOCALID_TRAINER_HILL_HNS_NURSE
	addobject LOCALID_TRAINER_HILL_HNS_ATTENDANT
	addobject LOCALID_TRAINER_HILL_HNS_MAN
	addobject LOCALID_TRAINER_HILL_HNS_GIRL
	end

TrainerHill_Entrance_hns_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_hns_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_hns_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_hns_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_hns_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_hns_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_hns_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_Entrance_hns_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_hns_EventScript_WarpToEntranceCounter::
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE_HNS, 9, 6
	waitstate
	end

TrainerHill_Entrance_hns_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_hns_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_hns_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_hns_EventScript_EndExitChallenge

TrainerHill_Entrance_hns_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_hns_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_PlayerExitChallenge

TrainerHill_Entrance_hns_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_hns_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_hns_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_hns_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_HNS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_hns_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_hns_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AttendantEnd

TrainerHill_Entrance_hns_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_hns_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_hns_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_Closed
	msgbox TrainerHill_Entrance_hns_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_hns_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_hns_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers

TrainerHill_Entrance_hns_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_hns_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_hns_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_hns_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_hns_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_hns_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_hns_EventScript_CancelEntry
	end

TrainerHill_Entrance_hns_EventScript_Info::
	msgbox TrainerHill_Entrance_hns_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_hns_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_hns_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_hns_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_hns_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_hns_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_hns_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_hns_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_hns_EventScript_CancelEntry
	end

TrainerHill_Entrance_hns_EventScript_Closed::
	msgbox TrainerHill_Entrance_hns_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

TrainerHill_Entrance_hns_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_hns_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_hns_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_hns_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Man2::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed2
	msgbox TrainerHill_Entrance_hns_Text_Money, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed2::
	msgbox TrainerHill_Entrance_hns_Text_HereToGetMoney, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_hns_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_hns_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerHill_Entrance_hns_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

TrainerHill_Entrance_hns_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_hns_Pokemart_Basic:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_hns_Text_HereToGetMoney:
	.string "我是来赚点钱的！为什么？因为每次\n"
	.string "登顶，都能拿到奖金啊！\p"
	.string "不知道他们什么时候才开门。我都等\n"
	.string "不及了！$"

TrainerHill_Entrance_hns_Text_Money:
	.string "每次登上顶楼，都能赚到一笔奖金。\p"
	.string "我听说只要在10分钟以内通关，最\n"
	.string "多能拿到1.000.000¥呢！\p"
	.string "但要是花的时间太长，奖励就会减少\n"
	.string "......$"

TrainerHill_Entrance_hns_Text_StillGettingReady:
	.string "这里是训练家之丘，在这里可以体验\n"
	.string "与众多训练家的双打对战。\p"
	.string "不过很遗憾，我们目前还在筹备中。\n"
	.string "请过段时间再来吧！$"

TrainerHill_Entrance_hns_Text_WelcomeToTrainerHill:
	.string "欢迎光临！\p"
	.string "这里是训练家之丘，在这里可以体验\n"
	.string "与众多训练家的双打对战！$"

TrainerHill_Entrance_hns_Text_SaveGameBeforeEnter:
	.string "你是第一次来这里吗？\p"
	.string "在进入之前，请先记录一下游戏进度\n"
	.string "。$"

TrainerHill_Entrance_hns_Text_TrainersUpToFloorX:
	.string "我看看......现在驻留在此的\n"
	.string "训练家......\p"
	.string "分布到了第{STR_VAR_1}\n"
	.string "层。$"

TrainerHill_Entrance_hns_Text_TrainersInEveryRoom:
	.string "我看看......现在驻留在此的\n"
	.string "训练家......\p"
	.string "似乎每一个房间里都聚集了训练家。$"

TrainerHill_Entrance_hns_Text_LikeToChallengeTrainers:
	.string "你要向在此等候的训练家们发起挑战\n"
	.string "吗？$"

TrainerHill_Entrance_hns_Text_TimeProgessGetSetGo:
	.string "我将为你记录挑战用时。祝你好运！\p"
	.string "各就各位......\p"
	.string "预备......\p"
	.string "跑！$"

TrainerHill_Entrance_hns_Text_PleaseVisitUsAgain:
	.string "欢迎下次再来！$"

TrainerHill_Entrance_hns_Text_TooBadTremendousEffort:
	.string "真可惜啊。\p"
	.string "不过我觉得你的对战已经非常非常努\n"
	.string "力了。\p"
	.string "请随时回来再次挑战！$"

TrainerHill_Entrance_hns_Text_HopeYouGiveItYourBest:
	.string "希望你能全力以赴。$"

TrainerHill_Entrance_hns_Text_MovedReceptionHereForSwitch:
	.string "当训练家们轮换位置时，场面可能会\n"
	.string "相当混乱。\p"
	.string "为了避免拥挤推搡，我们把接待处搬\n"
	.string "到了这里。\p"
	.string "给您带来不便，敬请谅解。$"

TrainerHill_Entrance_hns_Text_ThankYouForPlaying:
	.string "感谢您的游玩！$"

TrainerHill_Entrance_hns_Text_ExplainTrainerHill:
	.string "Here at the TRAINER HILL, we conduct\n"
	.string "an event called the Time Attack.\p"
	.string "It is a race that measures how long\n"
	.string "you take to reach our owner on\l"
	.string "the rooftop from this counter.\p"
	.string "The fastest times are posted on\n"
	.string "the Time Board--try competing with\l"
	.string "your friends.\p"
	.string "In TRAINER battles along the way,\n"
	.string "neither Exp. Points nor money will\l"
	.string "be awarded.$"

TrainerHill_Entrance_hns_Text_WhatSortOfTrainersAreAhead:
	.string "天晓得前面会有怎样的训练家和宝可\n"
	.string "梦组合在等着我们？\p"
	.string "我只知道，谁敢挡我的路，我就把谁\n"
	.string "打倒！$"

TrainerHill_Entrance_hns_Text_CantWaitToTestTheWaters:
	.string "听说来自各地的强力训练家都聚集到\n"
	.string "了这座训练家之丘。\p"
	.string "我都等不及想试探一下实力了！\p"
	.string "谁敢挡我的路，我就把谁打倒！$"

TrainerHill_Entrance_hns_Text_FriendsTryingToReachTimeBoardTop:
	.string "你看到那边的计时板了吗？\p"
	.string "我和朋友们正在比赛，看谁能以最短\n"
	.string "的时间登顶呢。$"

TrainerHill_Entrance_hns_Text_DoYouKnowWhenTheyOpen:
	.string "你知道这里什么时候开门吗？\p"
	.string "我一直守在这儿，就是想成为第一位\n"
	.string "挑战者！$"
