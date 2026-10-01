BattleFrontier_BattlePyramidLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth_hns:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints_hns::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag_hns
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge_hns::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag_hns
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR_HNS, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver_hns::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot_hns, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hns::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLvOpen_hns
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLv50_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLv50Streak_hns
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLv50Streak_hns::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLvOpenStreak_hns
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLvOpenStreak_hns::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn_hns
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste_hns
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate_hns
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility_hns
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce_hns
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion_hns
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic_hns
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock_hns
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting_hns
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather_hns
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug_hns
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark_hns
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater_hns
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost_hns
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel_hns
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon_hns
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve_hns
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag_hns::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag_hns

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag_hns::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel_hns
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside_hns:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel_hns:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake_hns, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag_hns
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag_hns, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag_hns::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty_hns::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze_hns
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag_hns
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid_hns:
	.string "这里是考验训练家勇气的舞台！\p"
	.string "欢迎来到对战金字塔！\p"
	.string "我是对战探险的向导。$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge_hns:
	.string "你有踏上对战探险的勇气吗？$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge_hns:
	.string "期待你的下次挑战！$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid_hns:
	.string "所谓对战探险，就是一边探索金字塔\n"
	.string "一边以塔顶为目标的挑战。\p"
	.string "金字塔内共有7层的迷宫，不仅有实\n"
	.string "力强劲的训练家，还有野生的宝可梦\l"
	.string "在潜伏着。\p"
	.string "挑战时必须携带3只宝可梦，并且不\n"
	.string "能携带任何道具。\p"
	.string "在攀登途中，我们会为你提供一个装\n"
	.string "道具的对战背包。\p"
	.string "如果挑战失败，放在对战背包里的道\n"
	.string "具就会消失。\p"
	.string "如果想要中途暂停挑战，请选择“休\n"
	.string "息”并保存记录。\p"
	.string "如果不保存就结束游戏的话，就会被\n"
	.string "取消挑战资格。$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode_hns:
	.string "金字塔分为50级组和公开级别组。你\n"
	.string "要挑战哪一个呢？$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons_hns:
	.string "好的。那么请选择3只一同同行的宝\n"
	.string "可梦。$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "探险者，出了点小问题！\p"
	.string "你好像没有3只符合挑战资格的宝可\n"
	.string "梦。\p"
	.string "另外，也请不要让你的宝可梦携带任\n"
	.string "何道具。\p"
	.string "蛋{STR_VAR_1}。$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "探险者，出了点小问题！\p"
	.string "你好像没有3只符合挑战资格的宝可\n"
	.string "梦。\p"
	.string "3只宝可梦必须不同，且等级都不能\n"
	.string "超过50级。\p"
	.string "另外，也请不要让你的宝可梦携带任\n"
	.string "何道具。\p"
	.string "蛋{STR_VAR_1}。$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "准备好之后，请再来和我说话。$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "在进入对战金字塔之前需要保存游\n"
	.string "戏。可以吗？$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid_hns:
	.string "好的。那么这就带你前往对战金字\n"
	.string "塔。$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping_hns:
	.string "在探索期间，我们会替你保管背包，\n"
	.string "{PLAYER}。$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag_hns:
	.string "作为交换，请拿着这个你上次用过的\n"
	.string "对战背包。$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag_hns:
	.string "作为交换，请拿着这个对战背包。$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag_hns:
	.string "{PLAYER}把背包换成了对战\n"
	.string "背包。$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel_hns:
	.string "踩在这个地板光圈上，就会被传送到\n"
	.string "金字塔的更高层。\p"
	.string "祝你的探险一路平安！$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag_hns:
	.string "探险者，出大问题了！\p"
	.string "你上次结束挑战时没有保存记录。\p"
	.string "因此非常遗憾，你的挑战资格已被取\n"
	.string "消。\p"
	.string "这是我们替你保管的背包，物归原\n"
	.string "主。\p"
	.string "{PLAYER}取回了自己的背\n"
	.string "包。$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid_hns:
	.string "欢迎平安归来！\p"
	.string "你征服了金字塔！太了不起了！$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake_hns:
	.string "啊，出了点小问题。\p"
	.string "有宝可梦还携带着道具。\p"
	.string "很遗憾，在金字塔里获得的道具是不\n"
	.string "能带出去的。$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag_hns:
	.string "宝可梦携带的所有道具都将放进对战\n"
	.string "背包里，{PLAYER}。$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep_hns:
	.string "很遗憾，对战背包装不下所有的道\n"
	.string "具。\p"
	.string "请选择要留在对战背包里的道具，以\n"
	.string "及宝可梦携带的道具。$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem_hns:
	.string "还有宝可梦携带着道具。$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns:
	.string "请选择要留在对战背包里的道具，以\n"
	.string "及宝可梦携带的道具。$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld_hns:
	.string "{PLAYER}放回了宝可梦携带\n"
	.string "的所有道具。$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept_hns:
	.string "你使用过的对战背包将妥善保存，以\n"
	.string "备下次挑战使用。\p"
	.string "{PLAYER}交还了对战背包，\n"
	.string "换回了自己的背包。$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns:
	.string "我需要记录您的成绩。请稍候。$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis_hns:
	.string "这个请收下，作为攻破对战金字塔的\n"
	.string "纪念品。$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem_hns:
	.string "{PLAYER}获得了奖品\n"
	.string "{STR_VAR_1}。$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull_hns:
	.string "……啊……你的背包似乎已经满了。\p"
	.string "请整理好背包里的物品后再来吧。$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag_hns:
	.string "真遗憾……\p"
	.string "这是我们为您保管的背包。\p"
	.string "{PLAYER}取回了背包。$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns:
	.string "期待您的下次挑战！$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize_hns:
	.string "我们一直恭候着您的到来！\p"
	.string "这是您攻破金字塔的奖励。$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait_hns:
	.string "欢迎……\p"
	.string "就让我来告诉你，在金字塔中等待着\n"
	.string "你的灾难吧……$"

BattleFrontier_BattlePyramidLobby_Text_Aah_hns:
	.string "..................\n"
	.string "..................\p"
	.string "..................啊！$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis_hns:
	.string "我看到了倾泻的电火花……\p"
	.string "……在其中，我看到了你的宝可梦在麻\n"
	.string "痹中痛苦挣扎……..$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison_hns:
	.string "我看到了剧毒……\p"
	.string "……而且，我看到了你的宝可梦饱受中\n"
	.string "毒之苦……$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn_hns:
	.string "我看到了鲜红的烈焰……\p"
	.string "……而且，我看到了你的宝可梦饱受灼\n"
	.string "伤之苦……$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste_hns:
	.string "我感受到了无法宣泄的怒火所带来的\n"
	.string "巨大压力……\p"
	.string "那是一道诅咒……\p"
	.string "……而且，我看到你的宝可梦耗尽了招\n"
	.string "式的能量，不得不使出挣扎……$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate_hns:
	.string "我看到了高高飞在空中的宝可梦。.\n"
	.string "....\p"
	.string "……而且，我看到你的宝可梦因地面属\n"
	.string "性招式无效而束手无策......$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility_hns:
	.string "我感受到可怕的能量从地底喷涌而\n"
	.string "出……\p"
	.string "……而且，我看到你的宝可梦无法逃脱\n"
	.string "那股力量的束缚......$"

BattleFrontier_BattlePyramidLobby_Text_HintIce_hns:
	.string "我看到了冰属性宝可梦……\p"
	.string "……而且，我看到了你的宝可梦正在与\n"
	.string "冰冻状态苦苦抗争......$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion_hns:
	.string "我看到了连番伤及自身的招式......\p"
	.string "……而且，我看到你的宝可梦倒在它们\n"
	.string "面前……$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic_hns:
	.string "我看到了超能力属性宝可梦......\p"
	.string "……而且，我看到了你的宝可梦饱受超\n"
	.string "能力招式的折磨......$"

BattleFrontier_BattlePyramidLobby_Text_HintRock_hns:
	.string "我看到了岩石属性宝可梦……..\p"
	.string "……而且，我看到了你的宝可梦饱受岩\n"
	.string "石招式的折磨……..$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting_hns:
	.string "我看到了格斗属性宝可梦……..\p"
	.string "……而且，我看到了你的宝可梦被格斗\n"
	.string "招式痛击……$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather_hns:
	.string "求雨……大晴天……..沙暴……冰雹......\p"
	.string "我看到了因天气而变强的宝可梦。.\n"
	.string "....\p"
	.string "……而且，我看到你的宝可梦被各种属\n"
	.string "性的招式打得晕头转向......$"

BattleFrontier_BattlePyramidLobby_Text_HintBug_hns:
	.string "我看到了虫属性宝可梦……\p"
	.string "……而且，我看到了你的宝可梦饱受各\n"
	.string "种攻击之苦……$"

BattleFrontier_BattlePyramidLobby_Text_HintDark_hns:
	.string "我看到了恶属性宝可梦……\p"
	.string "……而且，我看到了你的宝可梦饱受恶\n"
	.string "属性招式之苦……..$"

BattleFrontier_BattlePyramidLobby_Text_HintWater_hns:
	.string "我看到了水属性宝可梦……\p"
	.string "……而且，我看到了你的宝可梦饱受水\n"
	.string "属性招式之苦……..$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost_hns:
	.string "我看到了幽灵属性宝可梦……..\p"
	.string "……而且，我看到了你的宝可梦饱受幽\n"
	.string "灵属性招式之苦......$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel_hns:
	.string "我看到了钢属性宝可梦……\p"
	.string "……而且，我看到了你的宝可梦饱受威\n"
	.string "力极其强大的招式之苦......$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon_hns:
	.string "我看到了飞行属性的宝可梦……..\p"
	.string "……而且，我还看到了你的宝可梦正在\n"
	.string "威力极其巨大的招式下受苦……$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve_hns:
	.string "我看到了借助进化的石头之力量而进\n"
	.string "化的宝可梦们……\p"
	.string "我还感受到了火、水、以及电......\p"
	.string "……而且，我还看到了你的宝可梦正饱\n"
	.string "受这三种力量的折磨......$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal_hns:
	.string "我看到了一般属性的宝可梦……..\p"
	.string "……而且，我还看到了你的宝可梦正在\n"
	.string "威力极其巨大的招式下受苦……$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot_hns:
	.string "你是否相信我的占卜，取决于你自己\n"
	.string "的选择……\p"
	.string "未来随时都可以改变……祝你一路平\n"
	.string "安……$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning_hns:
	.string "你知道吗？\p"
	.string "如果你跑得很快，训练家可能会注意\n"
	.string "到你，并跑过来向你发起挑战。\p"
	.string "所以，如果你想避开训练家，就不要\n"
	.string "引起他们的注意，小心而安静地悄悄\l"
	.string "溜过去吧。$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems_hns:
	.string "啊啊啊啊啊啊啊啊！\p"
	.string "我本来带了好多道具，结果输掉之后\n"
	.string "全都没了！\p"
	.string "啊啊啊啊啊啊啊啊！$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing_hns:
	.string "欢迎回来！你完成了不可思议的壮\n"
	.string "举！\p"
	.string "你击败了金字塔法老，彻底征服了对\n"
	.string "战金字塔！$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints_hns:
	.string "年轻的探险家！为了赞赏你的勇气，\n"
	.string "特向你赠予对战点数！$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed_hns:
	.string "记录着对战探索的规则。$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading_hns:
	.string "想了解哪一项？$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules_hns:
	.string "当征服金字塔后，其中出现的野生宝\n"
	.string "可梦种类便会发生改变。\p"
	.string "探索、观察并了解你可能会遭遇什么\n"
	.string "样的野生宝可梦吧。$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules_hns:
	.string "金字塔内有训练家在埋伏等待着你。\p"
	.string "每一层最多会有8位训练家。\p"
	.string "击败训练家后，你就会获得对探险有\n"
	.string "帮助的提示。$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules_hns:
	.string "每次进入金字塔，迷宫的构造都会重\n"
	.string "新排列。\p"
	.string "迷宫内部光线昏暗，你必须谨慎前\n"
	.string "进。\p"
	.string "每当你击败一只野生宝可梦或一名训\n"
	.string "练家，光线就会变得更明亮。$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules_hns:
	.string "在金字塔内，对战背包将作为你的背\n"
	.string "包。\p"
	.string "对战背包分为两个独立的背包，分别\n"
	.string "用于50级挑战和公开级别挑战。\p"
	.string "每个背包最多可存放10种道具，每种\n"
	.string "上限99个。\p"
	.string "如果在探索中失败，对战背包里的所\n"
	.string "有物品都会丢失。$"

