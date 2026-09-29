BattleFrontier_BattlePyramidFloor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition_hns
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame_hns:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume_hns:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY_HNS, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition_hns:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor_hns::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop_hns
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR_HNS, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP_HNS, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle_hns::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall_hns::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBall_hnsEnd_hns
	pyramid_hideitem
BattlePyramid_FindItemBall_hnsEnd_hns::
	end

BattlePyramid_Retire_hns::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText_hns:
	.string "这是一条示例信息。$"

gText_BattlePyramidConfirmRest_hns::
	.string "将保存对战金字塔的探索进度，以便\n"
	.string "您暂时退出游戏。这样可以吗？$"

gText_BattlePyramidConfirmRetire_hns::
	.string "您确定要放弃金字塔的探索吗？$"

BattlePyramid_Text_ExitHintUp1_hns::
	.string "这一层的出口在那个方向：\n"
	.string "{UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1_hns::
	.string "这一层的出口在那个方向：\n"
	.string "{LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1_hns::
	.string "这一层的出口在那个方向：\n"
	.string "{RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1_hns::
	.string "这一层的出口在那个方向：\n"
	.string "{DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2_hns::
	.string "这一层的出口在\n"
	.string "{UP_ARROW}方向。$"

BattlePyramid_Text_ExitHintLeft2_hns::
	.string "这一层的出口在\n"
	.string "{LEFT_ARROW}方向。$"

BattlePyramid_Text_ExitHintRight2_hns::
	.string "这一层的出口在\n"
	.string "{RIGHT_ARROW}方向。$"

BattlePyramid_Text_ExitHintDown2_hns::
	.string "这一层的出口在\n"
	.string "{DOWN_ARROW}方向。$"

BattlePyramid_Text_ExitHintUp3_hns::
	.string "出口在{UP_ARROW}那边。$"

BattlePyramid_Text_ExitHintLeft3_hns::
	.string "出口在{LEFT_ARROW}那\n"
	.string "边。$"

BattlePyramid_Text_ExitHintRight3_hns::
	.string "出口在{RIGHT_ARROW}\n"
	.string "那边。$"

BattlePyramid_Text_ExitHintDown3_hns::
	.string "出口在{DOWN_ARROW}那\n"
	.string "边。$"

BattlePyramid_Text_ExitHintUp4_hns::
	.string "在这一层，出口在\n"
	.string "{UP_ARROW}方向的某处。$"

BattlePyramid_Text_ExitHintLeft4_hns::
	.string "在这一层，出口在\n"
	.string "{LEFT_ARROW}方向的某\l"
	.string "处。$"

BattlePyramid_Text_ExitHintRight4_hns::
	.string "在这一层，出口在\n"
	.string "{RIGHT_ARROW}方向的\l"
	.string "某处。$"

BattlePyramid_Text_ExitHintDown4_hns::
	.string "在这一层，出口在\n"
	.string "{DOWN_ARROW}方向的某\l"
	.string "处。$"

BattlePyramid_Text_ExitHintUp5_hns::
	.string "出口吗？在{UP_ARROW}那\n"
	.string "边。$"

BattlePyramid_Text_ExitHintLeft5_hns::
	.string "出口吗？在\n"
	.string "{LEFT_ARROW}那边。$"

BattlePyramid_Text_ExitHintRight5_hns::
	.string "出口吗？在\n"
	.string "{RIGHT_ARROW}那边。$"

BattlePyramid_Text_ExitHintDown5_hns::
	.string "出口吗？在\n"
	.string "{DOWN_ARROW}那边。$"

BattlePyramid_Text_ExitHintUp6_hns::
	.string "出口正好在{UP_ARROW}方\n"
	.string "向。$"

BattlePyramid_Text_ExitHintLeft6_hns::
	.string "出口正好在\n"
	.string "{LEFT_ARROW}方向。$"

BattlePyramid_Text_ExitHintRight6_hns::
	.string "出口正好在\n"
	.string "{RIGHT_ARROW}方向。$"

BattlePyramid_Text_ExitHintDown6_hns::
	.string "出口正好在\n"
	.string "{DOWN_ARROW}方向。$"

BattlePyramid_Text_EightItemsRemaining1_hns::
	.string "你在找道具吗？\p"
	.string "还剩下8个道具没有被找到。$"

BattlePyramid_Text_SevenItemsRemaining1_hns::
	.string "你在找道具吗？\p"
	.string "还剩下7个道具没有被找到。$"

BattlePyramid_Text_SixItemsRemaining1_hns::
	.string "你在寻找道具吗？\p"
	.string "还有6个道具没有被找到哦。$"

BattlePyramid_Text_FiveItemsRemaining1_hns::
	.string "你在寻找道具吗？\p"
	.string "还有5个道具没有被找到哦。$"

BattlePyramid_Text_FourItemsRemaining1_hns::
	.string "你在寻找道具吗？\p"
	.string "还有4个道具没有被找到哦。$"

BattlePyramid_Text_ThreeItemsRemaining1_hns::
	.string "你在寻找道具吗？\p"
	.string "还有3个道具没有被找到哦。$"

BattlePyramid_Text_TwoItemsRemaining1_hns::
	.string "你在寻找道具吗？\p"
	.string "还有2个道具没有被找到哦。$"

BattlePyramid_Text_OneItemRemaining1_hns::
	.string "你在寻找道具吗？\p"
	.string "还剩1个道具没有被找到哦。$"

BattlePyramid_Text_ZeroItemsRemaining1_hns::
	.string "你在寻找道具吗？\p"
	.string "已经没有任何道具留在这里了！$"

BattlePyramid_Text_EightItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近散落着8个道具哦。$"

BattlePyramid_Text_SevenItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近还散落着7个道具哦。$"

BattlePyramid_Text_SixItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近还散落着6个道具哦。$"

BattlePyramid_Text_FiveItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近还散落着5个道具哦。$"

BattlePyramid_Text_FourItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近还散落着4个道具哦。$"

BattlePyramid_Text_ThreeItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近还散落着3个道具哦。$"

BattlePyramid_Text_TwoItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近还散落着2个道具哦。$"

BattlePyramid_Text_OneItemRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近只剩最后1个道具了哦。$"

BattlePyramid_Text_ZeroItemsRemaining2_hns::
	.string "既然你赢了，我就告诉你一个小秘密\n"
	.string "吧！\p"
	.string "这附近已经没有任何道具散落在地上\n"
	.string "了哦。$"

BattlePyramid_Text_EightItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层还有8个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_SevenItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层还有7个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_SixItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层还有6个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_FiveItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层还有5个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_FourItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层还有4个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_ThreeItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层还有3个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_TwoItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层还有2个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_OneItemRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层只剩1个道具等着被\n"
	.string "人发现呢。$"

BattlePyramid_Text_ZeroItemsRemaining3_hns::
	.string "你带的道具还充足吗？\p"
	.string "我估摸着这一层已经没有等着被人发\n"
	.string "现的道具了。路上多加小心啊！$"

BattlePyramid_Text_EightItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像还有8个道具呢。$"

BattlePyramid_Text_SevenItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像还有7个道具呢。$"

BattlePyramid_Text_SixItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像还有6个道具呢。$"

BattlePyramid_Text_FiveItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像还有5个道具呢。$"

BattlePyramid_Text_FourItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像还有4个道具呢。$"

BattlePyramid_Text_ThreeItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像还有3个道具呢。$"

BattlePyramid_Text_TwoItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像还有2个道具呢。$"

BattlePyramid_Text_OneItemRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像只剩最后1个道具了。$"

BattlePyramid_Text_ZeroItemsRemaining4_hns::
	.string "你很强，我就给你一个提示吧！\p"
	.string "地上好像已经没有任何道具了。$"

BattlePyramid_Text_EightItemsRemaining5_hns::
	.string "听说在金字塔的这一层，有8个道具\n"
	.string "呢……$"

BattlePyramid_Text_SevenItemsRemaining5_hns::
	.string "听说在金字塔的这一层，有7个道具\n"
	.string "呢……$"

BattlePyramid_Text_SixItemsRemaining5_hns::
	.string "听说在金字塔的这一层，有6个道具\n"
	.string "呢……$"

BattlePyramid_Text_FiveItemsRemaining5_hns::
	.string "听说在金字塔的这一层，有5个道具\n"
	.string "呢……$"

BattlePyramid_Text_FourItemsRemaining5_hns::
	.string "听说在金字塔的这一层，有4个道具\n"
	.string "呢……$"

BattlePyramid_Text_ThreeItemsRemaining5_hns::
	.string "听说在金字塔的这一层，有3个道具\n"
	.string "呢……$"

BattlePyramid_Text_TwoItemsRemaining5_hns::
	.string "听说在金字塔的这一层，有2个道具\n"
	.string "呢……$"

BattlePyramid_Text_OneItemRemaining5_hns::
	.string "听说在金字塔的这一层，有1个道具\n"
	.string "呢……$"

BattlePyramid_Text_ZeroItemsRemaining5_hns::
	.string "听说在金字塔的这一层，没有任何道\n"
	.string "具呢……$"

BattlePyramid_Text_EightItemsRemaining6_hns::
	.string "你收集到道具了吗？\p"
	.string "我想这一层应该还有8个道具。$"

BattlePyramid_Text_SevenItemsRemaining6_hns::
	.string "你收集到道具了吗？\p"
	.string "我想这一层应该还有7个道具。$"

BattlePyramid_Text_SixItemsRemaining6_hns::
	.string "你收集到道具了吗？\p"
	.string "我想这一层应该还有6个道具。$"

BattlePyramid_Text_FiveItemsRemaining6_hns::
	.string "你收集到道具了吗？\p"
	.string "我想这一层应该还有5个道具。$"

BattlePyramid_Text_FourItemsRemaining6_hns::
	.string "你收集到道具了吗？\p"
	.string "我想这一层应该还有4个道具。$"

BattlePyramid_Text_ThreeItemsRemaining6_hns::
	.string "你收集到道具了吗？\p"
	.string "我想这一层应该还有3个道具。$"

BattlePyramid_Text_TwoItemsRemaining6_hns::
	.string "你收集到道具了吗？\p"
	.string "我想这一层应该还有2个道具。$"

BattlePyramid_Text_OneItemRemaining6_hns::
	.string "你有收集到道具吗？\p"
	.string "我想这一层应该还有一个道具。$"

BattlePyramid_Text_ZeroItemsRemaining6_hns::
	.string "你有收集到道具吗？\p"
	.string "我想这一层应该已经没有道具了。$"

BattlePyramid_Text_SevenTrainersRemaining1_hns::
	.string "你真的很厉害！\p"
	.string "但除了我以外，这里还有7位强力的\n"
	.string "训练家呢！$"

BattlePyramid_Text_SixTrainersRemaining1_hns::
	.string "你真的很厉害！\p"
	.string "但除了我以外，这里还有6位强力的\n"
	.string "训练家呢！$"

BattlePyramid_Text_FiveTrainersRemaining1_hns::
	.string "你真的很厉害！\p"
	.string "但除了我以外，这里还有5位强力的\n"
	.string "训练家呢！$"

BattlePyramid_Text_FourTrainersRemaining1_hns::
	.string "你真的很厉害！\p"
	.string "但除了我以外，这里还有4位强力的\n"
	.string "训练家呢！$"

BattlePyramid_Text_ThreeTrainersRemaining1_hns::
	.string "你真的很厉害！\p"
	.string "但除了我以外，这里还有3位强力的\n"
	.string "训练家呢！$"

BattlePyramid_Text_TwoTrainersRemaining1_hns::
	.string "你真的很厉害！\p"
	.string "但除了我以外，这里还有2位强力的\n"
	.string "训练家呢！$"

BattlePyramid_Text_OneTrainersRemaining1_hns::
	.string "你真的很厉害！\p"
	.string "但除了我以外，这里还有1位强力的\n"
	.string "训练家呢！$"

BattlePyramid_Text_ZeroTrainersRemaining1_hns::
	.string "你真的太厉害了！\p"
	.string "已经没有任何人能打败你了！$"

BattlePyramid_Text_SevenTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但还有7位训练家呢！肯定有人能挫\n"
	.string "挫你的锐气！$"

BattlePyramid_Text_SixTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但还有6位训练家呢！肯定有人能挫\n"
	.string "挫你的锐气！$"

BattlePyramid_Text_FiveTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但还有5位训练家呢！肯定有人能挫\n"
	.string "挫你的锐气！$"

BattlePyramid_Text_FourTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但还有4位训练家呢！肯定有人能挫\n"
	.string "挫你的锐气！$"

BattlePyramid_Text_ThreeTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但还有3位训练家呢！肯定有人能挫\n"
	.string "挫你的锐气！$"

BattlePyramid_Text_TwoTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但还有2位训练家呢！肯定有人能挫\n"
	.string "挫你的锐气！$"

BattlePyramid_Text_OneTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但还有1位训练家呢！你肯定会被打\n"
	.string "败的！$"

BattlePyramid_Text_ZeroTrainersRemaining2_hns::
	.string "真让人不甘心！\p"
	.string "但已经没有训练家能和你交手了！$"

BattlePyramid_Text_SevenTrainersRemaining3_hns::
	.string "真了不起！\p"
	.string "不过这一层还有7位训练家。你能全\n"
	.string "部打赢吗？$"

BattlePyramid_Text_SixTrainersRemaining3_hns::
	.string "真了不起！\p"
	.string "不过这一层还有6位训练家。你能全\n"
	.string "部打赢吗？$"

BattlePyramid_Text_FiveTrainersRemaining3_hns::
	.string "真了不起！\p"
	.string "不过这一层还有5位训练家。你能全\n"
	.string "部打赢吗？$"

BattlePyramid_Text_FourTrainersRemaining3_hns::
	.string "真了不起！\p"
	.string "不过这一层还有4位训练家。你能全\n"
	.string "部打赢吗？$"

BattlePyramid_Text_ThreeTrainersRemaining3_hns::
	.string "真了不起！\p"
	.string "不过这一层还有3位训练家。你能全\n"
	.string "部打赢吗？$"

BattlePyramid_Text_TwoTrainersRemaining3_hns::
	.string "真了不起！\p"
	.string "不过这一层还有2位训练家。你能把\n"
	.string "他们都打赢吗？$"

BattlePyramid_Text_OneTrainersRemaining3_hns::
	.string "真了不起！\p"
	.string "不过这一层还有1位训练家。你能战\n"
	.string "胜他吗？$"

BattlePyramid_Text_ZeroTrainersRemaining3_hns::
	.string "太了不起了！\p"
	.string "你战胜了这层所有的训练家。$"

BattlePyramid_Text_SevenTrainersRemaining4_hns::
	.string "说不定你能一口气击败这层剩下的7\n"
	.string "位训练家呢。$"

BattlePyramid_Text_SixTrainersRemaining4_hns::
	.string "说不定你能一口气击败这层剩下的6\n"
	.string "位训练家呢。$"

BattlePyramid_Text_FiveTrainersRemaining4_hns::
	.string "说不定你能一口气击败这层剩下的5\n"
	.string "位训练家呢。$"

BattlePyramid_Text_FourTrainersRemaining4_hns::
	.string "说不定你能一口气击败这层剩下的4\n"
	.string "位训练家呢。$"

BattlePyramid_Text_ThreeTrainersRemaining4_hns::
	.string "说不定你能一口气击败这层剩下的3\n"
	.string "位训练家呢。$"

BattlePyramid_Text_TwoTrainersRemaining4_hns::
	.string "说不定你能一口气击败这层剩下的2\n"
	.string "位训练家呢。$"

BattlePyramid_Text_OneTrainersRemaining4_hns::
	.string "说不定你能战胜这层剩下的最后1位\n"
	.string "训练家，完成全胜呢。$"

BattlePyramid_Text_ZeroTrainersRemaining4_hns::
	.string "现在已经没有任何一个人能打败你了\n"
	.string "......$"

BattlePyramid_Text_SevenTrainersRemaining5_hns::
	.string "说不定你有实力击败剩下的7位高手\n"
	.string "训练家。$"

BattlePyramid_Text_SixTrainersRemaining5_hns::
	.string "说不定你有实力击败剩下的6位高手\n"
	.string "训练家。$"

BattlePyramid_Text_FiveTrainersRemaining5_hns::
	.string "说不定你有实力击败剩下的5位高手\n"
	.string "训练家。$"

BattlePyramid_Text_FourTrainersRemaining5_hns::
	.string "说不定你有实力击败剩下的4位高手\n"
	.string "训练家。$"

BattlePyramid_Text_ThreeTrainersRemaining5_hns::
	.string "说不定你有实力击败剩下的3位高手\n"
	.string "训练家。$"

BattlePyramid_Text_TwoTrainersRemaining5_hns::
	.string "说不定你有实力击败剩下的2位高手\n"
	.string "训练家。$"

BattlePyramid_Text_OneTrainersRemaining5_hns::
	.string "说不定你有实力击败剩下的最后1位\n"
	.string "高手训练家。$"

BattlePyramid_Text_ZeroTrainersRemaining5_hns::
	.string "你的实力无可挑剔。\p"
	.string "这里已经没有训练家能够战胜你了。$"

BattlePyramid_Text_SevenTrainersRemaining6_hns::
	.string "面对剩下的7位训练家，你能继续保\n"
	.string "持胜利吗？$"

BattlePyramid_Text_SixTrainersRemaining6_hns::
	.string "面对剩下的6位训练家，你能继续保\n"
	.string "持胜利吗？$"

BattlePyramid_Text_FiveTrainersRemaining6_hns::
	.string "面对剩下的5位训练家，你能继续保\n"
	.string "持胜利吗？$"

BattlePyramid_Text_FourTrainersRemaining6_hns::
	.string "面对剩下的4位训练家，你能继续保\n"
	.string "持胜利吗？$"

BattlePyramid_Text_ThreeTrainersRemaining6_hns::
	.string "面对剩下的3位训练家，你能继续保\n"
	.string "持胜利吗？$"

BattlePyramid_Text_TwoTrainersRemaining6_hns::
	.string "面对剩下的2位训练家，你能继续保\n"
	.string "持胜利吗？$"

BattlePyramid_Text_OneTrainersRemaining6_hns::
	.string "面对最后剩下的1位训练家，你能继\n"
	.string "续保持胜利吗？$"

BattlePyramid_Text_ZeroTrainersRemaining6_hns::
	.string "现在已经没有训练家能够挑战你了。\n"
	.string ".....$"
