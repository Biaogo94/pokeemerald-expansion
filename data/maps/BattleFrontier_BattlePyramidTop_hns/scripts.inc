BattleFrontier_BattlePyramidTop_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp_hns
	.byte 0

BattleFrontier_BattlePyramidTop_OnTransition_hns:
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects_hns
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto_if_ne VAR_TEMP_C, 0, BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects_hns
	setobjectxyperm LOCALID_BRANDON, 0, 0
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects_hns::
	end

BattleFrontier_BattlePyramidTop_OnResume_hns:
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus_hns
	call BattleFrontier_EventScript_SetBrainObjectGfx
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus_hns::
	copyvar VAR_TEMP_C, VAR_RESULT
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge_hns
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge_hns
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	end

BattleFrontier_BattlePyramidTop_OnFrame_hns:
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic_hns
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName_hns
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic_hns::
	playbgm MUS_B_PYRAMID_TOP, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_ShowMapName_hns::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge_hns::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_Attendant_hns::
	lock
	faceplayer
	goto_if_ne VAR_TEMP_D, 0, BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady_hns
	goto_if_ne VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside_hns
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop_hns
	waitmovement 0
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath_hns
	waitmovement 0
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid_hns
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	closemessage
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY_HNS, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady_hns, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere_hns, MSGBOX_DEFAULT
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside_hns
	setvar VAR_TEMP_D, 1
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hns::
	lockall
	switch VAR_TEMP_C
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold_hns
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech_hns
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech_hns
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech_hns
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure_hns, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsSilver_hns
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech_hns::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsSilver_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle_hns
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver_hns
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver_hns::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns

BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold_hns::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech_hns
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned_hns, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsGold_hns
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech_hns::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsGold_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle_hns
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold_hns
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold_hns::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns

BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle_hns::
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_PYRAMID
	waitstate
	return

BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside_hns:
	walk_right
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath_hns:
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns:
	walk_fast_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_CameraPanUp_hns:
	walk_slow_up
	walk_slow_up
	delay_16
	step_end

BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo_hns:
	.string "能在这里见到你真是太令人高兴了！\n"
	.string "你已经到达了对战金字塔的顶峰！\p"
	.string "再往上就是金字塔的展望台了。\p"
	.string "那是只有征服了金字塔的人才能进入\n"
	.string "的地方。\p"
	.string "那么，请吧！走上去吧！$"

BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid_hns:
	.string "金字塔的新征服者！铭记\n"
	.string "{PLAYER}之名吧！$"

BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere_hns:
	.string "能在这里见到你真是太令人高兴了！\p"
	.string "可惜的是，你只差了一小步，屈居第\n"
	.string "二！\p"
	.string "我们的首领已经先你一步征服了金字\n"
	.string "塔。\p"
	.string "但是，年轻的探险家啊……你是一名训\n"
	.string "练家！\p"
	.string "展现你的力量，从首领手中夺取顶点\n"
	.string "的荣耀吧！\p"
	.string "那么，请吧！做好准备后，就怀揣勇\n"
	.string "气再踏出一步吧！$"

BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure_hns:
	.string "年轻的冒险者啊……\p"
	.string "你不觉得探险是最壮丽的冒险吗？\p"
	.string "你自己的智慧！\p"
	.string "你自己的力量！\p"
	.string "你自己的宝可梦！\p"
	.string "最重要的是，仅凭你自己的勇气，引\n"
	.string "领你穿行于未知的世界……$"

BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon_hns:
	.string "啊，没错，这样的人生确实壮丽！相\n"
	.string "当壮丽！对吧？\p"
	.string "我是神代！\p"
	.string "我是金字塔法老，也就是说这里是由\n"
	.string "我掌管的。\p"
	.string "大家都叫我首领！\p"
	.string "你能来到这里，就意味着你对自己有\n"
	.string "相当大的自信，对吧？\p"
	.string "哈哈哈哈！这可太令人兴奋了！$"

BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle_hns:
	.string "那么！带上你的勇气，来和我对战\n"
	.string "吧！$"

BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease_hns:
	.string "神代：哈哈哈哈！确实壮丽！当真壮\n"
	.string "丽无比！\p"
	.string "干得漂亮！你赢得了认可！请出示你\n"
	.string "的开拓通行证！$"

BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol_hns:
	.string "开拓通行证上被印上了英勇象征！$"

BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting_hns:
	.string "年轻的探险家！期待与你的下次相\n"
	.string "遇！$"

BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned_hns:
	.string "神代：……你终于回来了，年轻的探险\n"
	.string "家……\p"
	.string "看来你对冒险的热爱，发自你内心的\n"
	.string "最深处……\p"
	.string "是啊……你和我年轻的时候简直一模一\n"
	.string "样……\p"
	.string "..................啊……\p"
	.string "那份激情！\p"
	.string "那份危险！\p"
	.string "那份绝境！\p"
	.string "那些舍生忘死、感受生命真谛的冒险\n"
	.string "岁月，又回来了……$"

BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter_hns:
	.string "那么！\p"
	.string "我感到我自己的勇气已经彻底突破极\n"
	.string "限了！$"

BattleFrontier_BattlePyramidTop_Text_EverythingYouHave_hns:
	.string "拿出你的全部实力吧！我已经做好准\n"
	.string "备全盘接下了！$"

BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis_hns:
	.string "神代：哈哈哈哈！了不起！确实太壮\n"
	.string "观了！\p"
	.string "年轻的探险家啊！\p"
	.string "你彻底赢过了我！来吧！把这个收\n"
	.string "下！$"

BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine_hns:
	.string "勇敢象征放射出金色的光芒！$"

BattleFrontier_BattlePyramidTop_Text_FarewellForNow_hns:
	.string "哈，正是如此！这充分说明了我还有\n"
	.string "很多要学习的！\p"
	.string "愿我们能再次相遇！暂时告别了，年\n"
	.string "轻的探险家！$"

BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady_hns:
	.string "那么，做好准备后，拿出勇气向前迈\n"
	.string "进吧。$"

