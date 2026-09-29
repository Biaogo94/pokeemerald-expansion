BattleFrontier_OutsideEast_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition_hns
	.byte 0

BattleFrontier_OutsideEast_OnResume_hns:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker_hns::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac_hns::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1_hns::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin_hns::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM_hns::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo_hns::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo_hns::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1_hns::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl_hns::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM_hns::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2_hns::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2_hns::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hns::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper_hns::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign_hns:
	.string "这里是对战塔！以最强训练家为目标\n"
	.string "保持连胜吧！$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns:
	.string "这里是对战宫殿！目不转睛地注视宝\n"
	.string "可梦的战斗吧！$"

BattleFrontier_OutsideEast_Text_BattleArenaSign_hns:
	.string "这里是对战竞技场！最强的队伍聚集\n"
	.string "于此吧！$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns:
	.string "这里是对战金字塔！在对战探险中勇\n"
	.string "往直前吧！$"

BattleFrontier_OutsideEast_Text_RankingHallSign_hns:
	.string "对战开拓区排名大厅瞄准新纪录发起\n"
	.string "冲击吧！$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns:
	.string "对战点数兑换处兑换你的对战点数吧\n"
	.string "！$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns:
	.string "哇！好大啊！\p"
	.string "对战塔感觉格外特别呢。和其他设施\n"
	.string "都不一样。$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns:
	.string "我的宏伟抱负就是制霸对战开拓区和\n"
	.string "宝可梦联盟。\p"
	.string "如果我的梦想实现了……\p"
	.string "我……我就去问隔壁的美美\n"
	.string "愿不愿意和我做朋友！$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns:
	.string "对战金字塔太残酷了！我根本到不了\n"
	.string "顶层！\p"
	.string "既然已经无计可施了，也许我能从外\n"
	.string "面爬上去……$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns:
	.string "我在黑暗中茁壮成长……是\n"
	.string "的……有什么配得上我？非\l"
	.string "对战金字塔莫属……\p"
	.string "在彻头彻尾的绝望黑暗中漫步，你觉\n"
	.string "得如何？$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns:
	.string "我一个星期没睡觉，但终于组建出了\n"
	.string "究极队伍！\p"
	.string "不夸张地说，我都不知道自己怎么输\n"
	.string "。我们要横扫对战竞技场！$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns:
	.string "也是亚希达带你来的吗？那家伙到底\n"
	.string "是怎么回事？\p"
	.string "虽然听上去他确实挺有发掘优秀训练\n"
	.string "家的眼光，但是……\p"
	.string "我从没亲眼见过他亲自对战过。$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns:
	.string "蛇蛇！我相信你，小搭档！\p"
	.string "要是赢了，无论什么你爱吃的美味零\n"
	.string "食，我都给你做！$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns:
	.string "蛇纹熊一脸茫然……$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns:
	.string "人们都说我是个爱管闲事的人，但我\n"
	.string "就是忍不住嘛。\p"
	.string "你的帽子戴歪了！哎呀不行，地上有\n"
	.string "垃圾！糟了，快到吃晚饭的时间了！\p"
	.string "在对战宫殿只能在旁边看着，我都不\n"
	.string "知道自己忍不忍得住……$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns:
	.string "我现在看着可能不起眼，但我曾经打\n"
	.string "败过道馆馆主哦。\p"
	.string "谁知道呢，说不定我应该再去重温一\n"
	.string "下当年的荣耀。$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns:
	.string "我骑自行车飞快，我的对战风格也是\n"
	.string "如此。\p"
	.string "我眨眼之间就能赢得比赛！$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns:
	.string "我玩宝可梦比我爸爸还厉害！$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns:
	.string "去吧，我的小宝贝！去给爸爸多拿几\n"
	.string "场胜利回来！\p"
	.string "你跟你妈妈一模一样，绝对能所向披\n"
	.string "靡！$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns:
	.string "来到这里可不容易，因为我听说在对\n"
	.string "战竞技场有个倾国倾城的大美女。\p"
	.string "结果呢，你猜我看到了什么？\p"
	.string "一大群浑身臭汗、粗鲁又野蛮的格斗\n"
	.string "家！$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns:
	.string "我有时会看到一个看起来很有威望的\n"
	.string "老人走进去。\p"
	.string "他的宝可梦非常厉害，不过他人看起\n"
	.string "来非常和善。$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns:
	.string "你知道吗？关于对战金字塔的传说？\p"
	.string "“当自信满满的训练家踏上金色的顶\n"
	.string "峰之时，人中豪杰便将现身。”\p"
	.string "没听说过这个传说？哎呀，那是当然\n"
	.string "的啦！这可是我刚刚现编的！\p"
	.string "到底是什么意思？这我就无可奉告\n"
	.string "了，朋友！$"

BattleFrontier_OutsideEast_Text_GotWipedOut_hns:
	.string "天哪！天哪！我以前可是一次都没输\n"
	.string "过！\p"
	.string "结果被毫无悬念地全灭了！\p"
	.string "然后居然还被说毫无才能？！搞什么\n"
	.string "啊！$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns:
	.string "这家伙在挑战对战塔的时候，遇到了\n"
	.string "一个强得可怕的训练家。\p"
	.string "现在看看他成了什么样……\p"
	.string "如果你想去对战塔，可一定要小心谨\n"
	.string "慎。$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns:
	.string "太好了！我的对战点数终于攒够了！\p"
	.string "这就去再换一个超大的毛绒玩偶吧！$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns:
	.string "噢，原来如此！这里就是排行大厅啊\n"
	.string "！\p"
	.string "我想作为超级冠军名垂青史，把名字\n"
	.string "永远刻在这里供后人瞻仰。$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns:
	.string "只要有你在我身边，我什么都做得到\n"
	.string "。$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns:
	.string "噢，亲爱的，你太棒了！\p"
	.string "噢，我真是一刻也等不及了！\p"
	.string "我们马上就去多人对战室吧！\p"
	.string "只要我们在对战沙龙携手，我们爱的\n"
	.string "力量就能战胜遇到的所有人。\p"
	.string "哎呀亲爱的，在我们面前，一切都会\n"
	.string "像多米诺骨牌一样应声倒下！$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns:
	.string "对战开拓区可不只是为强大的训练家\n"
	.string "准备的。\p"
	.string "看起来，许多身怀绝技的人也都受到\n"
	.string "了邀请。\p"
	.string "亚希达那个人……\p"
	.string "建造这个地方，也许是为了更大的目\n"
	.string "标……$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns:
	.string "打扰一下，年轻人。你的视力好吗？\p"
	.string "前面有一棵奇怪的树，在我这双老花\n"
	.string "眼里，它好像在晃动。$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns:
	.string "打扰一下，年轻人。你的记性好吗？\p"
	.string "我总觉得过去这里曾经有棵奇怪的树\n"
	.string "。$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns:
	.string "我……我看见了！\p"
	.string "前面有一只黏糊糊的、长着长尾巴的\n"
	.string "宝可梦！\p"
	.string "它藏在一块巨石下面，还一直死死盯\n"
	.string "着我看！$"
