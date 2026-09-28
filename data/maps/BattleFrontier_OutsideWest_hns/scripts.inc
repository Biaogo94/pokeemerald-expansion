BattleFrontier_OutsideWest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition_hns
	.byte 0

BattleFrontier_OutsideWest_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_EventScript_Sailor_hns::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_AsYouLike_hns
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	hideobjectat LOCALID_BATTLE_FRONTIER_SAILOR_HNS, MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS
	setvar VAR_0x8004, LOCALID_FARAWAY_BATTLE_FRONTIER_HNS_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_AsYouLike_hns::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign_hns, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2_hns::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1_hns::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_Maniac2_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hns::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns::
	return

BattleFrontier_OutsideWest_EventScript_Girl_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass_hns::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM_hns::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2_hns::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1_hns::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2_hns::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF_hns::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign_hns:
	.string "这里是对战巨蛋！通往无敌超级巨星\n"
	.string "之路！$"

BattleFrontier_OutsideWest_Text_BattleFactorySign_hns:
	.string "这里是对战工厂！寻找最强的宝可梦\n"
	.string "吧！$"

BattleFrontier_OutsideWest_Text_BattlePikeSign_hns:
	.string "这里是对战管道！在三条路中选择一\n"
	.string "条前进吧！$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns:
	.string "这里是对战塔。\p"
	.string "训练家们会带着精心培育的宝可梦前\n"
	.string "来参加淘汰赛。$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket_hns:
	.string "您好，您是要乘渡轮吗？请出示您的\n"
	.string "船票。$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard_hns:
	.string "{PLAYER}没有船票....\n"
	.string "..\p"
	.string "非常抱歉。\p"
	.string "必须持有船票才能乘渡轮。$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo_hns:
	.string "{PLAYER}出示了船票。\p"
	.string "很好！这就没问题了！\p"
	.string "请问您想去哪里呢？$"

BattleFrontier_OutsideWest_Text_SlateportItIs_hns:
	.string "那么，就前往凯那市！$"

BattleFrontier_OutsideWest_Text_LilycoveItIs_hns:
	.string "那么，就前往水静市！$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime_hns:
	.string "欢迎下次再度光临！$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry_hns:
	.string "请登上渡轮，等待出发。$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo_hns:
	.string "那么，您想去哪里呢？$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns:
	.string "我在朋友当中明明是最强的，可在这\n"
	.string "里......根本不堪一击！$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns:
	.string "我想去对战塔，可哪怕拿着对战开拓\n"
	.string "区的地图，也还是找不到。\p"
	.string "这里实在太大了！$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns:
	.string "我本来打算一到这里就去挑战的。\p"
	.string "可路上晕船晕得厉害......呕\n"
	.string "......$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns:
	.string "可不是谁都能来这里的，知道吗？\p"
	.string "只有被认可为强者的训练家才会被带\n"
	.string "到这里来。\p"
	.string "正因如此，很多训练家甚至连对战开\n"
	.string "拓区都不知道呢。$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns:
	.string "喂，哥......\p"
	.string "就算一只宝可梦都没有，真的也能挑\n"
	.string "战吗？$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns:
	.string "呃......应该没问题的吧。\p"
	.string "大概......\p"
	.string "不过你还记得那个很凶的大叔吗？他\n"
	.string "说：“我可以借你们宝可梦！”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns:
	.string "那是对战工厂。在那里可以租借到强\n"
	.string "大的宝可梦。\p"
	.string "不过真让人好奇，那些供租借的宝可\n"
	.string "梦到底是谁培育的呢？$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns:
	.string "因为饭匙蛇的关系，我很害怕进对战\n"
	.string "管道......\p"
	.string "但、但我大老远来了这里，就一定要\n"
	.string "制霸所有设施！......瑟瑟发\l"
	.string "抖......$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns:
	.string "来玩石头剪刀布吧！石头、剪子、布\n"
	.string "！\p"
	.string "..................$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns:
	.string "好耶！我赢了！我去挑战对战管道咯\n"
	.string "！$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns:
	.string "哎呀......我输了。\p"
	.string "看来我今天的运气不怎么样。挑战对\n"
	.string "战管道的事，还是推迟到明天吧。$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns:
	.string "不知为何，我大概是这里唯一一个比\n"
	.string "起对战更喜欢钓鱼的人吧。\p"
	.string "咦？这里什么都钓不到？真叫人失望\n"
	.string "......$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns:
	.string "今天无论如何我都要一直对战下去，\n"
	.string "直到拿到开拓象征为止。$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns:
	.string "哦？你正打算去挑战对战巨蛋吗？\p"
	.string "祝你好运。让我们一路赢下去，在对\n"
	.string "战中相会吧。$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns:
	.string "爷爷，这边！对战巨蛋在这里！加油\n"
	.string "啊，爷爷！$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns:
	.string "哦，这里就是对战巨蛋吗？我可不会\n"
	.string "输给那些绅士！\p"
	.string "不过入口在哪里呢？$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns:
	.string "不久之前这里还什么都没有呢。\p"
	.string "可现在看看这里！真了不起！我也要\n"
	.string "带妈妈来看看。$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns:
	.string "终于来到对战开拓区了！\p"
	.string "凭我的美貌和实力，一定会大受瞩目\n"
	.string "的！$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns:
	.string "嚼，嚼......\p"
	.string "这个广场上看起来满是厉害的家伙啊\n"
	.string "。\p"
	.string "嚼，嚼......$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns:
	.string "咔嚓，嚼嚼......\p"
	.string "前阵子，我在对战管子遇到了一位大\n"
	.string "姐姐。\p"
	.string "她的眼神非常凶恶，透着一股狠劲。\p"
	.string "咔嚓，嚼嚼......\p"
	.string "她气得大喊：“你给我别吃了！”然\n"
	.string "后就把我暴揍了一顿。\p"
	.string "那可真是一段让人毛骨悚然的恐怖经\n"
	.string "历啊。\p"
	.string "咔嚓，嚼嚼......$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns:
	.string "哈？听听你说的什么话！那根本不算\n"
	.string "什么！\p"
	.string "我上次为他加油时，我们可是四目相\n"
	.string "对，火花四溅呢！$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns:
	.string "什--么？！切！\p"
	.string "那不过是因为我碰巧坐在你旁边罢了\n"
	.string "！\p"
	.string "巨蛋巨星会往我们这边看，全是因为\n"
	.string "我的加油声最大！$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns:
	.string "哼，吵死了！小声点！\p"
	.string "你们这种跟风粉丝还是去给道馆馆主\n"
	.string "加油吧！\p"
	.string "巨蛋巨星是属于我的！是我唯一的偶\n"
	.string "像！$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns:
	.string "在那边吵架的那些人......\p"
	.string "虽然难以置信，但她们以前也是训练\n"
	.string "家，而且相当厉害呢。\p"
	.string "曾经不仅实力超强，还很有名气。\p"
	.string "但是在一场锦标赛中，她们被某个训\n"
	.string "练家彻底击溃了。\p"
	.string "因为输得太惨，她们反而被那个训练\n"
	.string "家迷得神魂颠倒。\p"
	.string "现在就只是那个训练家的粉丝了。每\n"
	.string "天都去对战巨蛋为她们的偶像加油助\l"
	.string "威。$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns:
	.string "我听到传闻，说有人在对战开拓区的\n"
	.string "某个地方见到了尾巴特别长的宝可梦\l"
	.string "。\p"
	.string "肯定非常可爱。我敢肯定.....\n"
	.string ".\p"
	.string "哎呀，挑战的事先放一边。我忍不住\n"
	.string "想要去找找那个惹人怜爱的家伙了！$"

