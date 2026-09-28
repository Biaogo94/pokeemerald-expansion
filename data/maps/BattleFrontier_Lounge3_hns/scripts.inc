BattleFrontier_Lounge3_hns_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5_hns
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10_hns
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15_hns
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet5_hns::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet10_hns::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet15_hns::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet_hns
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_PlaceBet_hns::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet_hns
	end

BattleFrontier_Lounge3_EventScript_FinishBet_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns::
	msgbox BattleFrontier_Lounge3_Text_Oh_hns, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults_hns
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults_hns::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge_hns
	goto BattleFrontier_Lounge3_EventScript_LostChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_WonChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15_hns
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NotInterested_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet_hns::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_PokefanF_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FatMan_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns::
	.string "......你想要干什么？\p"
	.string "没看到我们正忙着吗？你的事情不能\n"
	.string "等会儿再说吗？$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns::
	.string "......嗯？我看你像个厉害的\n"
	.string "训练家。\p"
	.string "嘿嘿......听着，我有个提议\n"
	.string "。\p"
	.string "我们在这里建了个小团体，拿对战开\n"
	.string "拓区里发生的事来玩个小游戏。\p"
	.string "规则非常简单。\p"
	.string "首先，我们选出对战开拓区里的一个\n"
	.string "设施。\p"
	.string "然后，我们各自挑选一名去挑战该设\n"
	.string "施的训练家，并押上我们的对战点数\l"
	.string "。\p"
	.string "谁押的训练家战绩最好，谁就能拿走\n"
	.string "奖池里所有的对战点数。\p"
	.string "听起来很简单吧？所以说呢....\n"
	.string "..$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle_hns::
	.string "我正在寻找一位准备去挑战对战塔单\n"
	.string "打对战室的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble_hns::
	.string "我正在寻找一位准备去挑战对战塔双\n"
	.string "打对战室的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti_hns::
	.string "我正在寻找一位准备去挑战对战塔多\n"
	.string "人对战室的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle_hns::
	.string "我正在寻找一位准备去参加对战巨蛋\n"
	.string "单打锦标赛的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble_hns::
	.string "我正在寻找一位准备去参加对战巨蛋\n"
	.string "双打锦标赛的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle_hns::
	.string "我正在寻找一位准备去参加对战工厂\n"
	.string "交换单打锦标赛的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble_hns::
	.string "我正在寻找一位准备去参加对战工厂\n"
	.string "交换双打锦标赛的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle_hns::
	.string "我正在寻找一位准备去挑战对战宫殿\n"
	.string "单打大厅的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble_hns::
	.string "我正在寻找一位准备去挑战对战宫殿\n"
	.string "双打大厅的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena_hns::
	.string "我正在寻找一位准备去参加对战竞技\n"
	.string "场淘汰锦标赛的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike_hns::
	.string "我正在寻找一位准备去参加对战管道\n"
	.string "对战选拔的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid_hns::
	.string "我正在寻找一位准备去参加对战金字\n"
	.string "塔对战探索的训练家。\p"
	.string "但到目前为止，我还没看到哪个训练\n"
	.string "家具备冠军相。$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns::
	.string "我也不会亏待你的。那么怎么样？替\n"
	.string "我去参加那场比赛如何？$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns::
	.string "太好了，简直完美！那个，呃...\n"
	.string "...能不能借我一点你的对战点数\l"
	.string "？\p"
	.string "相信我，事成之后我绝对会好好感谢\n"
	.string "你的！$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns::
	.string "太棒了，太棒了！那么，你能借我多\n"
	.string "少点呢？$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns::
	.string "哎呀，不行不行不行！你的对战点数\n"
	.string "根本不够嘛！\p"
	.string "别恶作剧浪费大家的时间好不好！$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns::
	.string "嘿嘿！多谢啦！那么，快出发吧！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle_hns::
	.string "立刻前往对战塔的单打对战室！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble_hns::
	.string "立刻前往对战塔的双打对战室！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti_hns::
	.string "立刻前往对战塔的多人对战室！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle_hns::
	.string "立刻前往对战巨蛋的单打淘汰赛！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble_hns::
	.string "立刻前往对战巨蛋的双打淘汰赛！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle_hns::
	.string "立刻前往对战工厂的交换单打锦标赛\n"
	.string "！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble_hns::
	.string "立刻前往对战工厂的交换双打锦标赛\n"
	.string "！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle_hns::
	.string "立刻前往对战宫殿的单打大厅！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble_hns::
	.string "立刻前往对战宫殿的双打大厅！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattleArena_hns::
	.string "立刻前往对战竞技场的判定淘汰赛！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattlePike_hns::
	.string "立刻前往对战水管的选路对战！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid_hns::
	.string "立刻前往对战金字塔的探索对战！\p"
	.string "这可是一场绝不能输的战斗！千万别\n"
	.string "搞砸了！我们两个的未来都靠你了！$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns::
	.string "唉，是你啊......你尽力了.\n"
	.string ".....\p"
	.string "虽然很遗憾，但我没法退还你的对战\n"
	.string "点数了......\p"
	.string "就当是激励我们下次更加努力吧！$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns::
	.string "噢，太棒了！你好啊，大赢家！\p"
	.string "我就知道你能行！我就知道你办得到\n"
	.string "！我们都是大赢家啦！\p"
	.string "这是还你的对战点数，当然，还有我\n"
	.string "的一点额外心意！$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns::
	.string "{PLAYER}获得了\n"
	.string "{STR_VAR_1}点对战点数\l"
	.string "。$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns::
	.string "要是你还想再次挑战，可一定要想着\n"
	.string "我啊！$"

BattleFrontier_Lounge3_Text_NotInterested_hns::
	.string "没兴趣？！你可不能这么害怕冒险啊\n"
	.string "！$"

BattleFrontier_Lounge3_Text_Oh_hns::
	.string "噢......$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns::
	.string "我又押错训练家了！\p"
	.string "也许我也该像其他人一样，堂堂正正\n"
	.string "地去对战才对......$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns::
	.string "那个训练家......\p"
	.string "实力是不错，但他太容易慌乱了，在\n"
	.string "对战巨蛋是走不远的......$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns::
	.string "嘻嘻！谁能赢，我一眼就能看出来！$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns::
	.string "那些训练家......他们到底在\n"
	.string "做什么啊？明明应该去接受挑战的。$"
