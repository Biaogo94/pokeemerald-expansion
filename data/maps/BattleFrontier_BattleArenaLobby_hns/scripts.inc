BattleFrontier_BattleArenaLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR_HNS, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns:
	.string "这里是考验训练家斗志的舞台！\p"
	.string "欢迎来到对战竞技场！\p"
	.string "我负责为您介绍判决淘汰赛！$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns:
	.string "那么，您要挑战对战竞技场吗？$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns:
	.string "期待您的下次挑战！$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns:
	.string "在对战竞技场中，我们将进行判决淘\n"
	.string "汰赛。\p"
	.string "所有参赛者需携带3只宝可梦组成的\n"
	.string "队伍出战。\p"
	.string "这3只宝可梦必须按出场顺序排好队\n"
	.string "伍。\p"
	.string "在对战中，宝可梦将按照预设的顺序\n"
	.string "一只一只出场。\p"
	.string "宝可梦一旦上场对战，就必须一直战\n"
	.string "斗直至分出胜负。\p"
	.string "如果在3个回合内未能分出胜负，就\n"
	.string "会由裁判进行判决。\p"
	.string "如果您想中断挑战，请保存记录。\p"
	.string "如果不保存，就无法继续进行挑战。\p"
	.string "如果您成功达成了连胜7名训练家的\n"
	.string "壮举，我们就会向您赠送对战点数。$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns:
	.string "在带您前往对战竞技场之前，需要保\n"
	.string "存记录。这样可以吗？$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns:
	.string "对战竞技场提供两种挑战等级：50\n"
	.string "级挑战和公开等级。您选择哪一种？$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns:
	.string "好的，那么请选择您要参赛的3只宝\n"
	.string "可梦。$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "尊敬的挑战者！\p"
	.string "您没有带齐参加挑战所需的3只宝可\n"
	.string "梦。\p"
	.string "参加的条件是，必须携带3只不同种\n"
	.string "类的宝可梦。\p"
	.string "它们也不能携带相同种类的道具。\p"
	.string "蛋{STR_VAR_1}。$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "等您准备周全之后，请务必再来。$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "尊敬的挑战者！\p"
	.string "您没有带齐参加挑战所需的3只宝可\n"
	.string "梦。\p"
	.string "参加的条件是，必须携带3只不同种\n"
	.string "类的宝可梦。\p"
	.string "而且这3只不同的宝可梦等级都必须\n"
	.string "在50级或以下。\p"
	.string "它们也不能携带相同种类的道具。\p"
	.string "蛋{STR_VAR_1}。$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns:
	.string "那么现在就由我带您前往对战竞技场\n"
	.string "。$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns:
	.string "尊敬的挑战者！\p"
	.string "您在关机前没有保存记录，对不对？\p"
	.string "很遗憾，由于未保存记录，您已被取\n"
	.string "消了挑战资格。\p"
	.string "当然，您可以重新开始一场全新的挑\n"
	.string "战。$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns:
	.string "恭喜您达成连胜7名训练家的辉煌战\n"
	.string "绩！$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns:
	.string "我们正在记录您的战绩。正在保存记\n"
	.string "录，请稍候。$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize_hns:
	.string "为纪念您的7连胜，我们向您颁发这\n"
	.string "份奖品。$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER}获得了奖品\n"
	.string "{STR_VAR_1}。$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize_hns:
	.string "哎呀？您的背包好像满了。\p"
	.string "请整理出空间后再来领取您的奖品。$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns:
	.string "非常感谢您的参与！\p"
	.string "正在保存记录，请稍候。$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns:
	.string "期待您的下次挑战！$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns:
	.string "我们一直期待着您的到来。\p"
	.string "在带您前往对战竞技场之前，需要保\n"
	.string "存记录。请稍候。$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns:
	.string "要把您在对战竞技场的最后一场对战\n"
	.string "记录在开拓对战手账上吗？$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns:
	.string "我在裁判的判定中输了……\p"
	.string "光用防御招式而不去攻击，看来真的\n"
	.string "不是个好策略啊……$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns:
	.string "我靠裁判判定赢了！\p"
	.string "不断给对手的宝可梦造成有效打击，\n"
	.string "果然起作用了！$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns:
	.string "我们的比赛被判定为平局。\p"
	.string "时间到了的时候，我和对手宝可梦剩\n"
	.string "下的HP几乎完全一样多。$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns:
	.string "在对战竞技场，宝可梦的出场顺序是\n"
	.string "至关重要的。\p"
	.string "举个例子，如果你的首发宝可梦在属\n"
	.string "性上处于劣势，那就尽量让第二只宝\l"
	.string "可梦掌握能克制前者的属性招式。\p"
	.string "我觉得这是构建强力队伍的一个好方\n"
	.string "法。$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns:
	.string "上面写着连胜淘汰赛的规则。$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns:
	.string "想了解哪一项？$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns:
	.string "连胜淘汰赛有着不同于普通对战的特\n"
	.string "殊规则。\p"
	.string "首先，一场对战只持续3个回合。\p"
	.string "如果3个回合后仍未分出胜负，就会\n"
	.string "进入裁判判定环节。\p"
	.string "裁判将根据宝可梦在对战中的表现来\n"
	.string "裁定胜者。\p"
	.string "此外，在对战分出胜负之前，宝可梦\n"
	.string "是无法被换下场的。$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns:
	.string "第1个判定标准是“心”。这一项用\n"
	.string "来评估对战双方的积极程度。\p"
	.string "裁判会根据训练家指示使用攻击招式\n"
	.string "的频率来进行评判。$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns:
	.string "第2个判定标准是“技”。这一项用\n"
	.string "来评估宝可梦招式运用的有效程度。\p"
	.string "如果招式成功生效，“技”的评分就\n"
	.string "会上升。\p"
	.string "如果招式落空或失败，评分就会下\n"
	.string "降。\p"
	.string "若是攻击招式，击中时如果“效果绝\n"
	.string "佳”，评分会上升;若“效果不好\l"
	.string "”，评分则会下降。\p"
	.string "使用“守住”或“看穿”等招式不会\n"
	.string "增加“技”的评分。\p"
	.string "如果对手使用了“守住”或“看穿”\n"
	.string "导致你的招式未击中，评分并不会因\l"
	.string "此降低。$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns:
	.string "第3个判定标准是“体”。这一项基\n"
	.string "于对战结束时所剩的HP多少进行判\l"
	.string "定。\p"
	.string "评分会综合考量宝可梦在对战开始时\n"
	.string "的HP，以及在结束时所剩余的HP\l"
	.string "比例。$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns:
	.string "从竞技场主将手中夺得胜利，完成了\n"
	.string "连克7名训练家的壮举！\p"
	.string "恭喜你达成了如此辉煌的挑战！$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns:
	.string "了不起的挑战者，为表彰你坚韧不拔\n"
	.string "的精神，请收下这些对战点数。$"
