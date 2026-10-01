BattleFrontier_ScottsHouse_hns_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott_hns::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment_hns::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns:
	.string "亚希达：哎呀，欢迎欢迎！嘿嘿..……\n"
	.string "地方有点窄，别介意啊。\p"
	.string "不管怎样，{PLAYER}\n"
	.string "{KUN}，让我正式欢迎你来到对\l"
	.string "战开拓区。\p"
	.string "这里是实现我梦想的地方。虽然花了\n"
	.string "我好多年好多年，但我终于把梦想变\l"
	.string "成了现实。$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns:
	.string "回想起来，那真是一段漫长的旅途\n"
	.string "啊......\p"
	.string "我独自离开家乡，踏上寻找强大训练\n"
	.string "家的旅程。\p"
	.string "没有人能想象为了将它实现，我付出\n"
	.string "了多少心血和时间。$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns:
	.string "不过那都是过去的事了，提这些也没\n"
	.string "意思！\p"
	.string "我只想让你在这里尽情享受对战的乐\n"
	.string "趣。\p"
	.string "{PLAYER}{KUN}，这个\n"
	.string "送给你，作为我们旅途中多次相遇的\l"
	.string "纪念吧。$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns:
	.string "{PLAYER}获得了\n"
	.string "{STR_VAR_1}点对战点\l"
	.string "数。$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns:
	.string "亚希达：你可以在开拓区通行证上查\n"
	.string "看你的对战点数。\p"
	.string "你在对战开拓区取得的胜利越多，就\n"
	.string "能积攒越多的对战点数。\p"
	.string "按照你喜欢的方式使用对战点数吧，\n"
	.string "比如拿去兑换道具。$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns:
	.string "我非常期待你的精彩表现哦！$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns:
	.string "亚希达：每个训练家都是独特的个\n"
	.string "体，各自过着属于自己的人生。\p"
	.string "但是，一旦站上对战场地，他们是谁\n"
	.string "就都不重要了。\p"
	.string "大家全都是平等的！\p"
	.string "我喜欢对战的那份纯粹，在对战中人\n"
	.string "人平等。\p"
	.string "正因如此，我才会四处寻找对战斗充\n"
	.string "满热忱的训练家，并邀请他们来到这\l"
	.string "里。$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns:
	.string "亚希达：你见过开拓之脑了吗？\p"
	.string "或者更进一步，拿到他们手中的象征\n"
	.string "了吗？\p"
	.string "那些开拓之脑可是我从各地精挑细选\n"
	.string "出来的顶尖强者。\p"
	.string "但我相信，只要见识了你的强大，连\n"
	.string "他们也一定会大吃一惊的！$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns:
	.string "亚希达：你并不只是为了对战而特\n"
	.string "训，对吧？\p"
	.string "我记得你好像也在收集宝可梦图鉴\n"
	.string "呢。\p"
	.string "那，你猜怎么着？\p"
	.string "在对战开拓区的某个角落，你也许会\n"
	.string "遇到野生宝可梦哦……呼呼呼！$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns:
	.string "亚希达：在对战开拓区玩得开心吗？\p"
	.string "……等等……噢！\p"
	.string "你的开拓区通行证！你已经集齐了全\n"
	.string "部的银色象征？！\p"
	.string "这简直太让人惊叹了！你果然很强，\n"
	.string "和我料想的一样！\p"
	.string "平时我可不会这么做，但现在是个特\n"
	.string "别的时刻！\p"
	.string "这个送给你。我相信你一定能物尽其\n"
	.string "用的。$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns:
	.string "亚希达：希望你在对战开拓区一切都\n"
	.string "过得开心。\p"
	.string "……等等……天哪，我简直不敢相信自己\n"
	.string "的眼睛！\p"
	.string "你的开拓区通行证！你竟然集齐了全\n"
	.string "部的金色象征？！\p"
	.string "这简直强得令人难以置信！你真是太\n"
	.string "不可思议了，不出我所料！\p"
	.string "..................\p"
	.string "{PLAYER}，你一定要收下这\n"
	.string "个！\p"
	.string "我相信唯有你，才能明白这份礼物的\n"
	.string "真正价值！$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns:
	.string "不得不说，我在识别人才训练家方面\n"
	.string "确实很有天赋呢。\p"
	.string "真庆幸我有先见之明把你带到了这\n"
	.string "里！$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns:
	.string "你的树果口袋好像已经装满了。$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns:
	.string "亚希达：噢，我都听说了！你在对战\n"
	.string "塔大展神威的事迹！你连续击败了超\l"
	.string "过50名训练家？\p"
	.string "太不可思议了！这个请你收下！$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns:
	.string "亚希达：天哪！我都听说了！你彻底\n"
	.string "制霸了对战塔！你竟然连续击败了超\l"
	.string "过100名训练家？！\p"
	.string "这简直是神乎其技的壮举！你一定要\n"
	.string "收下这个！$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns:
	.string "我今后会期待听到你更加惊人的传\n"
	.string "闻！$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns:
	.string "哎呀，既然你带的东西太多了，那就\n"
	.string "等以后再来拿吧。$"

