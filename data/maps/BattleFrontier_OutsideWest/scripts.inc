BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "这里是对战巨蛋！决定目标！无敌的\n"
	.string "超级巨星！$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "这里是对战工厂！寻找！最强宝可\n"
	.string "梦！$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "这里是对战管道！选择！3条道路！$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "这里是对战塔！\p"
	.string "训练家将他们最优秀的宝可梦带来进\n"
	.string "行淘汰赛。$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "您好，是来乘渡轮吗？可以出示您的\n"
	.string "船票吗？$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER}没有船票……\p"
	.string "非常抱歉。\p"
	.string "必须要持有船票才能登船。$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER}出示了船票。\p"
	.string "好的，没问题了！\p"
	.string "您想去哪里？$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "那就前往凯那市吧！$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "那就前往水静市吧！$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "欢迎下次再来！$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "请登船等候出发。$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "那么您想去哪里？$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "在朋友之中我是最强的，但在这儿……\n"
	.string "我根本不算什么！$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "我想去对战塔，但就算有地图，我也\n"
	.string "找不到对战开拓区。\p"
	.string "这块地方实在太大了！$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "我本来准备一到这儿就开始挑战的。\p"
	.string "不过，在路上，我晕船了……呜……$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "知道吗？并不是所有人都能到这里\n"
	.string "的。\p"
	.string "只有被认定是强大的训练家才能来到\n"
	.string "这里。\p"
	.string "所以很多训练家甚至对对战开拓区一\n"
	.string "无所知。$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "嗨，伙计……\p"
	.string "你敢肯定我们没有宝可梦也能进行挑\n"
	.string "战？$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "呃……大概不要紧吧。\p"
	.string "我想是的……\p"
	.string "记得那个吓人的大个子吗？他不是\n"
	.string "说：“我会借给你宝可梦！”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "那边的是对战工厂，在那儿你能借到\n"
	.string "强大的宝可梦，\p"
	.string "不过我一直在奇怪，那些宝可梦是谁\n"
	.string "培育出来的？$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "我不敢进对战管道，我怕饭匙蛇……\p"
	.string "但——但我既然已经到这儿来了我要努\n"
	.string "力战胜一切！……哆嗦……$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "来，石头剪子布！1～2～3！\p"
	.string "…… …… ……$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "耶！赢了！去挑战对战管道咯！$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "啊，不要啊……我输了。\p"
	.string "好像我今天的运气不是很好，明天再\n"
	.string "去挑战对战管道吧。$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "我想这儿除了我，再没有别人会因为\n"
	.string "某些原因不对战反而去钓鱼。\p"
	.string "嗯？这儿什么都钓不到？好失望……$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "今天，不论发生什么，我都要坚持战\n"
	.string "斗下去，直到获得象征为止。$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "嗯？你要去挑战对战巨蛋？\p"
	.string "祝你好运，希望我们都会一路获胜下\n"
	.string "去，然后在挑战中相遇。$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "爷爷，过来过来！对战巨蛋在这儿！\n"
	.string "一定要赢啊，爷爷！$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "啊，这儿就是对战巨蛋了。我不会被\n"
	.string "绅士打败的！\p"
	.string "对了，入口在哪儿？$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "就在不久之前，这里还是一片荒原。\p"
	.string "但现在看看这里吧！简直是奇迹！我\n"
	.string "要带妈妈来看看。$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "终于到达对战开拓区了！\p"
	.string "靠我的美貌和才能，肯定很快会成为\n"
	.string "焦点的！$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "嘎吱嘎吱……\p"
	.string "这广场上好像聚集了很多非常强的人\n"
	.string "啊。\p"
	.string "嘎吱嘎吱……$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "喀嚓喀嚓……\p"
	.string "前阵子，我在对战管道遇到了一位大\n"
	.string "姐姐。\p"
	.string "她那双眼睛凶得很，透着一股狠劲\n"
	.string "儿。\p"
	.string "喀嚓喀嚓……\p"
	.string "她气得大喊：“别再吃了！”然后狠狠\n"
	.string "揍了我一顿。\p"
	.string "那真是一次令人毛骨悚然的可怕经\n"
	.string "历。\p"
	.string "喀嚓喀嚓……$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "哈，你要不要听听你在说什么？那什\n"
	.string "么都算不上！\p"
	.string "看看，我为他加油的时候，我们交汇\n"
	.string "的眼神里都射出了火花！$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "什——么？！哼！\p"
	.string "这是因为我恰好坐在你旁边而已！\p"
	.string "是因为我的加油声很大，巨蛋超级巨\n"
	.string "星才会注意到这边的！$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "啊，嘘～嘘～吵死了，安静一下啦！\p"
	.string "你该让你那些不坚定的追星族们给别\n"
	.string "的道馆馆主加油！\p"
	.string "巨蛋超级巨星是我的！是只属于我的\n"
	.string "偶像！$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "那边吵架的那些人……\p"
	.string "真不敢相信那些人以前也都是训练\n"
	.string "家，而且还挺厉害的。\p"
	.string "他们以前非常强，同时也相当有名\n"
	.string "气。\p"
	.string "但在一场锦标赛中，他们都被某个训\n"
	.string "练家击倒了。\p"
	.string "他们完全地失败了，同时开始对那个\n"
	.string "训练家神魂颠倒。\p"
	.string "而现在，他们仅仅是那个训练家的狂\n"
	.string "热者而已，每天每天地在对战巨蛋为\l"
	.string "他们的偶像加油助威。$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "有传言说有人在对战开拓区的某处看\n"
	.string "到一种尾巴特别长的宝可梦。\p"
	.string "我敢肯定，它一定很可爱……\p"
	.string "啊，挑战什么的都一边去吧，我要去\n"
	.string "找那个小家伙了！$"

