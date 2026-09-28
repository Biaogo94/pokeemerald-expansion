BattleFrontier_BattlePikeLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving_hns::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen_hns
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance_hns, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen_hns, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults_hns
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults_hns
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay_hns, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor_hns
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain_hns
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR_HNS, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor_hns::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor_hns
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor_hns:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag_hns
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems_hns
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder_hns
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain_hns::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike_hns:
	.string "这里是考验训练家运气的场所...\n"
	.string "...\p"
	.string "欢迎来到对战水管......\p"
	.string "我是为您指引对战水管的向导...\n"
	.string "...$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge_hns:
	.string "您要参加挑选对战的挑战吗？$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike_hns:
	.string "这里举行的是被称为“挑选对战”的\n"
	.string "项目。\p"
	.string "挑选对战的规则非常简单....\n"
	.string "..\p"
	.string "从3条路中选择1条，前往对战水管\n"
	.string "尽头的终点房间。就这么简单。\p"
	.string "但是，在选择的路上会发生什么，完\n"
	.string "全取决于挑战者的运气......\p"
	.string "如果到达终点，您将获得对战点数作\n"
	.string "为奖励。\p"
	.string "如果您想中断挑战，请在中途的大房\n"
	.string "间里与工作人员说明。\p"
	.string "如果中断前没有保存记录，您的挑战\n"
	.string "资格就会被取消。$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns:
	.string "期待您的下次光临......$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode_hns:
	.string "有50级和公开级别2种赛程。您要\n"
	.string "挑战哪一种？$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "非常抱歉......\p"
	.string "您没有3只符合挑选对战参赛条件的\n"
	.string "宝可梦。\p"
	.string "您必须拥有3只50级以下且不同的\n"
	.string "宝可梦才能参加。\p"
	.string "并且它们携带的道具种类也必须各不\n"
	.string "相同。\p"
	.string "蛋{STR_VAR_1}。$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "准备好之后请再来找我......$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "非常抱歉......\p"
	.string "您没有3只符合挑选对战参赛条件的\n"
	.string "宝可梦。\p"
	.string "您必须拥有3只不同的宝可梦才能参\n"
	.string "加。\p"
	.string "并且它们携带的道具种类也必须各不\n"
	.string "相同。\p"
	.string "蛋{STR_VAR_1}。$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons_hns:
	.string "请选择3只您想用来参加挑战的宝可\n"
	.string "梦......$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge_hns:
	.string "在开始挑选对战挑战之前，需要保存\n"
	.string "游戏记录。这样可以吗？$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay_hns:
	.string "请往这边走......$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults_hns:
	.string "您的挑战结束了......\p"
	.string "现在为您记录成绩。请稍候...\n"
	.string "...$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance_hns:
	.string "您顺利完成了挑战......\p"
	.string "不得不说......您的运气似乎\n"
	.string "好得惊人呢......$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults_hns:
	.string "现在为您记录成绩。请稍候...\n"
	.string "...$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns2_hns:
	.string "为了庆祝您顺利完成挑选对战挑战，\n"
	.string "向您赠送这些对战点数......$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit_hns:
	.string "您的对战点数似乎已经达到上限了.\n"
	.string ".....\p"
	.string "请先将一些对战点数兑换成奖品后再\n"
	.string "来吧......$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting_hns:
	.string "非常抱歉......\p"
	.string "您上次退出挑战前没有保存记录。\p"
	.string "因此，您之前的挑战已被判无效。非\n"
	.string "常遗憾......$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen_hns:
	.string "恭喜您......\p"
	.string "您战胜了水管首领，顺利通关了该项\n"
	.string "目......$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns:
	.string "为了表彰您惊人的运气，向您赠送这\n"
	.string "些对战点数......$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal_hns:
	.string "啊啊！搞砸了！明明离终点就只差一\n"
	.string "个房间了！\p"
	.string "在这个地方，你最好小心防范中毒和\n"
	.string "冰冻之类的异常状态。$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer_hns:
	.string "我已经通关挑战10次了，可是一次\n"
	.string "都没有跟训练家对战过呢。$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere_hns:
	.string "听我说！听我说！\p"
	.string "你不觉得宝可梦的特性在这里能派上\n"
	.string "大用场吗？$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose_hns:
	.string "这什么奇怪的地方啊？我完全搞不明\n"
	.string "白！\p"
	.string "我都挑战好多次了，可不管选哪条\n"
	.string "路，遇到的全都是训练家！$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed_hns:
	.string "写着对战水管的规则。$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading_hns:
	.string "想了解哪一项？$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules_hns:
	.string "在挑战对战水管期间，不能使用“背\n"
	.string "包”和“宝可梦领航员”。$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules_hns:
	.string "在挑战对战水管期间，宝可梦携带的\n"
	.string "树果或草药只生效一次。$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules_hns:
	.string "在挑战对战水管期间，不能调换宝可\n"
	.string "梦的出场顺序。\p"
	.string "必须在开始挑战前确定好顺序。$"

