TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "这里是训练家之丘，您可以在此享受\n"
	.string "与众多训练师的双打战斗。\p"
	.string "很抱歉，我们仍在准备中。请您下次\n"
	.string "再来！$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "欢迎！\p"
	.string "这里是训练家之丘，您可以在此享受\n"
	.string "与众多训练师的双打对战！$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "是第一次来这里吗？\p"
	.string "在进入之前，请先写入记录。$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "唔，我看看……当前在场的训练家…\n"
	.string "…\p"
	.string "最高到第{STR_VAR_1}层\n"
	.string "。$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "唔，我看看……当前在场的训练家…\n"
	.string "…\p"
	.string "似乎每个房间都有训练家聚集。$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "要挑战正在等待的训练家吗？$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "我将为您计时，祝您好运！\p"
	.string "各就各位……\p"
	.string "预备……\p"
	.string "开始！$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "欢迎下次再来！$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "真是遗憾。\p"
	.string "但看得出您已付出巨大的努力。\p"
	.string "欢迎再来挑战！$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "期待您的精彩表现。$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "训练家们更换位置的时候，场面可能\n"
	.string "显得有些混乱。\p"
	.string "为避免拥挤踩踏，我们就把接待处搬\n"
	.string "到这里来了。\p"
	.string "对此造成的不便深表歉意。$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "辛苦了！$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "在训练家之丘，我们举办名为计时挑\n"
	.string "战的活动，\p"
	.string "比赛内容是从服务台出发，计时抵达\n"
	.string "楼顶的馆主处。\p"
	.string "最快纪录将展示在计时榜上——不妨\n"
	.string "和朋友比比看。\p"
	.string "在沿途的训练家对战中，无法获得经\n"
	.string "验值或金钱。$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "哦，对不起，但是您只有1只宝可梦\n"
	.string "。\p"
	.string "您最少需要2只宝可梦来参加这个活\n"
	.string "动。$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "嗯！嗯！\p"
	.string "你终于来了！没错，你到了！\p"
	.string "等等！别说！我知道你一个人千里迢\n"
	.string "迢跑到这里来是为了什么！\p"
	.string "你想见我，训练家之丘的主人，是因\n"
	.string "为......\p"
	.string "你想和我组队双打对吧！哇呼--！\p"
	.string "......咦？不是吗？\p"
	.string "不管怎样，你一路打上来的英姿我都\n"
	.string "看到了。真是精彩绝伦的对战！太棒\l"
	.string "了！$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "像你这样了不起的人，我有最棒的礼\n"
	.string "物要送给你！$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "噢，不行，背包已经装满了！你晚点\n"
	.string "再来拿这个吧！$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "噢，稍等一下！你是不是以惊人的速\n"
	.string "度赶到了这里？\p"
	.string "太棒了！其实你不必这么急着来见我\n"
	.string "的！\p"
	.string "真是令人开心。我会让接待处的计时\n"
	.string "板更新你的成绩！$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "但是，噢……你来得可不算快呢。$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "也许下次你能更快一点的话，我会更\n"
	.string "高兴的。\p"
	.string "那样的话，我会很乐意和你组队搭档\n"
	.string "！\p"
	.string "下次再见，朋友！$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "我建造这座训练师之丘只有一个原因\n"
	.string "！\p"
	.string "那就是找到最适合的搭档，和我组成\n"
	.string "双打队伍！$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1}分\n"
	.string "{STR_VAR_2}.\l"
	.string "{STR_VAR_3}秒。$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "谁知道前面会遇到什么样的训练师和\n"
	.string "宝可梦组合呢？\p"
	.string "我只知道，我会打倒所有挡路的家伙\n"
	.string "！$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "听说各地的强大训练师都会来这座训\n"
	.string "练师之丘。\p"
	.string "我已经等不及要试试身手了！\p"
	.string "我会打倒所有挡路的家伙！$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "你看到那边的计时板了吗？\p"
	.string "我和朋友们正在比赛，看谁能用最短\n"
	.string "时间登顶。$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "你知道这里什么时候正式开放吗？\p"
	.string "我在这儿等着成为第一个挑战者呢！$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "要返回接待处吗？$"
