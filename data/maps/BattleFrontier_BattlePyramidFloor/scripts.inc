BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "测试信息。$"

gText_BattlePyramidConfirmRest::
	.string "要暂停对战金字塔的探索需要先写入\n"
	.string "记录，可以吗？$"

gText_BattlePyramidConfirmRetire::
	.string "您确定要退出金字塔的探索吗？$"

BattlePyramid_Text_ExitHintUp1::
	.string "这层的出口方向是：\n"
	.string "{UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "这层的出口方向是：\n"
	.string "{LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "这层的出口方向是：\n"
	.string "{RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "这层的出口方向是：\n"
	.string "{DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "出口位于这层的\n"
	.string "{UP_ARROW} 方向。$"

BattlePyramid_Text_ExitHintLeft2::
	.string "出口位于这层的\n"
	.string "{LEFT_ARROW} 方向。$"

BattlePyramid_Text_ExitHintRight2::
	.string "出口位于这层的\n"
	.string "{RIGHT_ARROW} 方\l"
	.string "向。$"

BattlePyramid_Text_ExitHintDown2::
	.string "出口位于这层的\n"
	.string "{DOWN_ARROW} 方向。$"

BattlePyramid_Text_ExitHintUp3::
	.string "出口在通过{UP_ARROW} \n"
	.string "的路上。$"

BattlePyramid_Text_ExitHintLeft3::
	.string "出口在通过\n"
	.string "{LEFT_ARROW} 的路\l"
	.string "上。$"

BattlePyramid_Text_ExitHintRight3::
	.string "出口在通过\n"
	.string "{RIGHT_ARROW} 的路\l"
	.string "上。$"

BattlePyramid_Text_ExitHintDown3::
	.string "出口在通过\n"
	.string "{DOWN_ARROW} 的路\l"
	.string "上。$"

BattlePyramid_Text_ExitHintUp4::
	.string "在这层，出口位于\n"
	.string "{UP_ARROW} 方向的某个\l"
	.string "位置。$"

BattlePyramid_Text_ExitHintLeft4::
	.string "在这层，出口位于\n"
	.string "{LEFT_ARROW} 方向的\l"
	.string "某个位置。$"

BattlePyramid_Text_ExitHintRight4::
	.string "在这层，出口位于\n"
	.string "{RIGHT_ARROW} 方向\l"
	.string "的某个位置。$"

BattlePyramid_Text_ExitHintDown4::
	.string "在这层，出口位于\n"
	.string "{DOWN_ARROW} 方向的\l"
	.string "某个位置。$"

BattlePyramid_Text_ExitHintUp5::
	.string "出口吗？在 {UP_ARROW}\n"
	.string " 。$"

BattlePyramid_Text_ExitHintLeft5::
	.string "出口吗？在 \n"
	.string "{LEFT_ARROW} 。$"

BattlePyramid_Text_ExitHintRight5::
	.string "出口吗？在 \n"
	.string "{RIGHT_ARROW} 。$"

BattlePyramid_Text_ExitHintDown5::
	.string "出口吗？在 \n"
	.string "{DOWN_ARROW} 。$"

BattlePyramid_Text_ExitHintUp6::
	.string "出口出现在{UP_ARROW} \n"
	.string "方向。$"

BattlePyramid_Text_ExitHintLeft6::
	.string "出口出现在\n"
	.string "{LEFT_ARROW} 方向。$"

BattlePyramid_Text_ExitHintRight6::
	.string "出口出现在\n"
	.string "{RIGHT_ARROW} 方\l"
	.string "向。$"

BattlePyramid_Text_ExitHintDown6::
	.string "出口出现在\n"
	.string "{DOWN_ARROW} 方向。$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有8个道具没找到呢！$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有7个道具没找到呢！$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有6个道具没找到呢！$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有5个道具没找到呢！$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有4个道具没找到呢！$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有3个道具没找到呢！$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有2个道具没找到呢！$"

BattlePyramid_Text_OneItemRemaining1::
	.string "你在寻找道具吗？\p"
	.string "还有1个道具没找到呢！$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "你在寻找道具吗？\p"
	.string "这儿已经没有道具可以寻找的了。$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里共有8个道具哦！$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里共有7个道具哦！$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里共有6个道具哦！$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里共有5个道具哦！$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里共有4个道具哦！$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里共有3个道具哦！$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里共有2个道具哦！$"

BattlePyramid_Text_OneItemRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "在这里还有1个道具哦！$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "既然你赢了，那我就告诉你一个秘密\n"
	.string "做奖励吧！\p"
	.string "这里已经没有任何道具了！$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层还有8个道具。$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层还有7个道具。$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层还有6个道具。$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层还有5个道具。$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层还有4个道具。$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层还有3个道具。$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层还有2个道具。$"

BattlePyramid_Text_OneItemRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，在这一层可能只剩1个道具\n"
	.string "了。$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "你的背包还能放下几个道具？\p"
	.string "我估计，这一层已经没有道具可以找\n"
	.string "了。你多保重！$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有8个道具哦！$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有7个道具哦！$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有6个道具哦！$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有5个道具哦！$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有4个道具哦！$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有3个道具哦！$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有2个道具哦！$"

BattlePyramid_Text_OneItemRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "在地面上有1个道具哦！$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "你真强！给你个提示吧！\p"
	.string "地面上已经没有任何道具了。$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "在这层金字塔中，我听说有8个道具\n"
	.string "……$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "在这层金字塔中，我听说有7个道具\n"
	.string "……$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "在这层金字塔中，我听说有6个道具\n"
	.string "……$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "在这层金字塔中，我听说有5个道具\n"
	.string "……$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "在这层金字塔中，我听说有4个道具\n"
	.string "……$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "在这层金字塔中，我听说有3个道具\n"
	.string "……$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "在这层金字塔中，我听说有2个道具\n"
	.string "……$"

BattlePyramid_Text_OneItemRemaining5::
	.string "在这层金字塔中，我听说有1个道具\n"
	.string "……$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "在这层金字塔中，我听说这儿没道\n"
	.string "具……$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该有8个道具吧。$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该有7个道具吧。$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该有6个道具吧。$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该有5个道具吧。$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该有4个道具吧。$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该有3个道具吧。$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该有2个道具吧。$"

BattlePyramid_Text_OneItemRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该还有1个道具吧。$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "你有没有搜集道具呢？\p"
	.string "我认为这一层应该没有道具了。$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "你是很强！\p"
	.string "可还有7个比我更强的训练家等着\n"
	.string "你！$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "你是很强！\p"
	.string "可还有6个比我更强的训练家等着\n"
	.string "你！$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "你是很强！\p"
	.string "可还有5个比我更强的训练家等着\n"
	.string "你！$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "你是很强！\p"
	.string "可还有4个比我更强的训练家等着\n"
	.string "你！$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "你是很强！\p"
	.string "可还有3个比我更强的训练家等着\n"
	.string "你！$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "你是很强！\p"
	.string "可还有2个比我更强的训练家等着\n"
	.string "你！$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "你是很强！\p"
	.string "可还有1个比我更强的训练家等着\n"
	.string "你！$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "你真强！\p"
	.string "现在已经没有人能够打败你了！$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面还有7位训练家！他们中或许有\n"
	.string "人比你弱！$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面还有6位训练家！他们中或许有\n"
	.string "人比你弱！$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面还有5位训练家！他们中或许有\n"
	.string "人比你弱！$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面还有4位训练家！他们中或许有\n"
	.string "人比你弱！$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面还有3位训练家！他们中或许有\n"
	.string "人比你弱！$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面还有2位训练家！他们中或许有\n"
	.string "人比你弱！$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面还有1位训练家！他或许比你\n"
	.string "弱！$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "真不幸！\p"
	.string "后面已经没有训练家可以和你一起对\n"
	.string "战了。$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "这层还有7位训练家，你能打败他们\n"
	.string "吧？$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "这层还有6位训练家，你能打败他们\n"
	.string "吧？$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "这层还有5位训练家，你能打败他们\n"
	.string "吧？$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "这层还有4位训练家，你能打败他们\n"
	.string "吧？$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "这层还有3位训练家你能打败他们\n"
	.string "吧？$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "这层还有2位训练家，你能打败他们\n"
	.string "吧？$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "这层还有1位训练家，你能打败他\n"
	.string "吧？$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "真是场精彩的对战！\p"
	.string "你已经打败了这层所有的训练家。$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "或许你能一口气解决这层的其他7位\n"
	.string "训练家吧！$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "或许你能一口气解决这层的其他6位\n"
	.string "训练家吧！$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "或许你能一口气解决这层的其他5位\n"
	.string "训练家吧！$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "或许你能一口气解决这层的其他4位\n"
	.string "训练家吧！$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "或许你能一口气解决这层的其他3位\n"
	.string "训练家吧！$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "或许你能一口气解决这层的其他2位\n"
	.string "训练家吧！$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "或许你能一口气解决这层剩下那1位\n"
	.string "训练家吧！$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "已经没有人能打败你了……$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "你还需要打败7位专业训练家。$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "你还需要打败6位专业训练家。$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "你还需要打败5位专业训练家。$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "你还需要打败4位专业训练家。$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "你还需要打败3位专业训练家。$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "你还需要打败2位专业训练家。$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "你还需要打败1位专业训练家。$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "你的技术真娴熟！\p"
	.string "这儿已经没有训练家能打败你了。$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "你能继续保持打败剩下7位训练家的\n"
	.string "信心吗？$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "你能继续保持打败剩下6位训练家的\n"
	.string "信心吗？$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "你能继续保持打败剩下5位训练家的\n"
	.string "信心吗？$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "你能继续保持打败剩下4位训练家的\n"
	.string "信心吗？$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "你能继续保持打败剩下3位训练家的\n"
	.string "信心吗？$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "你能继续保持打败剩下2位训练家的\n"
	.string "信心吗？$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "你能继续保持打败剩下1位训练家的\n"
	.string "信心吗？$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "已经没有训练家可以和你对战了……$"
