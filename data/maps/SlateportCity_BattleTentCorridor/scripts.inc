SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "需要一点点关于华丽大赛的建议吗？\p"
	.string "在某些特定种类的招式后使用特定招\n"
	.string "式可以给你带来额外的注视度。\p"
	.string "如果你知道该怎么做，你可以获得更\n"
	.string "高的吸引力。\p"
	.string "当然，你的对手会试着干扰你宝可梦\n"
	.string "的表演。$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "我的爸爸，是华丽大赛裁判\p"
	.string "我不知道长大后做什么裁判还是道馆\n"
	.string "馆主呢？$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "那个，兄弟，你能理解偶有多毛么！\n"
	.string "你知道么！那个，我就想不通了，我\l"
	.string "想不通为啥偶的宝可梦\p"
	.string "从来没赢过？你知道么？！所以，那\n"
	.string "个，偶向裁判抱怨，\p"
	.string "但他们根本不鸟我，真那啥的。\p"
	.string "所以那个，说你呢！闭嘴行不？那个\n"
	.string "，偶说，这个拿去！$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "拿着，TM41，嘿，就是无理取闹\n"
	.string "，你在听我说吗？\p"
	.string "就像是，它不允许同一场中使用2次\n"
	.string "同样的的招式，了解？\p"
	.string "嘿，现在，听好，就像是希望我并没\n"
	.string "有给你带来麻烦！$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "主持人：天啊，天啊！它难道不是宝\n"
	.string "可梦中的花花公子？\p"
	.string "请一定快点来参加我们完美的华丽大\n"
	.string "赛！\p"
	.string "你会做得很好的！我相信你！我看好\n"
	.string "你哟！$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "裁判：你好啊！看来你是个训练家！\p"
	.string "那么，对你来说千万不要错过华丽大\n"
	.string "赛！\p"
	.string "获得绿茵镇的华丽大赛通行证并且随\n"
	.string "时可以再来！$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "吸引力时间！有什么我可以报导的呢\n"
	.string "？$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "他们没有太注意我的宝可梦的吸引力\n"
	.string "……\p"
	.string "哼，那个裁判，他根本就不懂得欣赏\n"
	.string "。$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "你好！你一定是追求此项活动的狂热\n"
	.string "爱好者。\p"
	.string "为了奖励你的热情给你一条忠告吧。\p"
	.string "如果一个招式表现的非常好，观众会\n"
	.string "变得很激动。\p"
	.string "当观众变得激动时做出这个招式的宝\n"
	.string "可梦吸引力就会……\p"
	.string "好了，会发生什么好事你应该可以想\n"
	.string "象得到吧！$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "我不能这么做！我比我的宝可梦还要\n"
	.string "紧张。\p"
	.string "我的心脏跳得很厉害以至于发抖了！$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "虽然对战和华丽大赛并不一样但它们\n"
	.string "也有相似之处。\p"
	.string "你需要更努力并且要相信你所培育的\n"
	.string "宝可梦。$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "那只宝可梦看起来像是比赛中的高手\n"
	.string "，嗯？\p"
	.string "宝可梦在评判比赛中做得好的话会比\n"
	.string "在吸引力比赛中看起来更放松。$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "你看起来怎么那么难过？\p"
	.string "嘿，我的宝可梦绝对是最棒的！$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "你是不是一直渴望宝可梦在吸引力比\n"
	.string "赛中有精神的表演带来的感动呢？$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "宝可梦华丽大赛特级会场！$"

