LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "小遥：嗨，你好啊？\n"
	.string "{PLAYER}{KUN}，你也\l"
	.string "来购物吗？\p"
	.string "我买了好多的玩偶和海报呢！\p"
	.string "当然，我也捕捉了不少宝可梦，而且\n"
	.string "也有好好培育它们哦。\p"
	.string "不如说，我反而更担心你有没有认真\n"
	.string "培养你的宝可梦，{PLAYER}\l"
	.string "{KUN}。\p"
	.string "来和我对战吧，{PLAYER}\n"
	.string "{KUN}，给看看你的宝可梦！$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "小遥：哎——为什么？\n"
	.string "{PLAYER}{KUN}，你没\l"
	.string "好好培育你的宝可梦吗？\p"
	.string "作为一个训练家这样可不行呢……$"

LilycoveCity_Text_MayBattleMe:
	.string "小遥：来和我对战吧，给看看你的宝\n"
	.string "可梦！$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "小遥：我培育的宝可梦才不会输给你\n"
	.string "呢，{PLAYER}{KUN}！$"

LilycoveCity_Text_MayDefeat:
	.string "…… …… …… ……\p"
	.string "想起我们之前在103号道路的对战\n"
	.string "了，{PLAYER}{KUN}。\p"
	.string "那场对战让你变得这么强了，是吗，\n"
	.string "{PLAYER}{KUN}？$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "小遥：我打算不久后回未白镇了。\p"
	.string "我已经捕捉了不少宝可梦，宝可梦图\n"
	.string "鉴也进展顺利，我想回家给爸爸看。$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}，你接\n"
	.string "下来打算怎么做？\p"
	.string "集齐所有道馆徽章，去挑战宝可梦联\n"
	.string "盟吗？\p"
	.string "那好，在{PLAYER}\n"
	.string "{KUN}收集徽章的时候，我就去\l"
	.string "全力完成宝可梦图鉴。我一定会比你\l"
	.string "更快集齐的！\p"
	.string "再见啦！$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}，你接\n"
	.string "下来打算做什么？\p"
	.string "想挑战宝可梦联盟吗？\p"
	.string "或者你想完成宝可梦图鉴？\p"
	.string "也许对战上我会输给你，但我会比你\n"
	.string "先完成宝可梦图鉴的！\p"
	.string "再见了！$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}，你接\n"
	.string "下来打算做什么？\p"
	.string "你要挑战对战开拓区吗？\p"
	.string "或者你想完成宝可梦图鉴？\p"
	.string "也许对战上我会输给你，但我会比你\n"
	.string "先完成宝可梦图鉴的！\p"
	.string "再见了！$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "小悠：嗨，这不是{PLAYER}\n"
	.string "吗！\p"
	.string "我来帮爸爸跑腿买东西。……才没打算\n"
	.string "买玩偶呢！\p"
	.string "总之，离上次我们见面已经有段时间\n"
	.string "了，\p"
	.string "要不要来场对战比比看谁培育的宝可\n"
	.string "梦更好？$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "小悠：哦，怎么了？没信心吗？$"

LilycoveCity_Text_BrendanBattleMe:
	.string "小悠：要不要来场对战比比看谁培育\n"
	.string "的宝可梦更好？$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "小悠：好，不过我是不会输给\n"
	.string "{PLAYER}的！$"

LilycoveCity_Text_BrendanDefeat:
	.string "唔……你的宝可梦培育得不错。\p"
	.string "明明我才是前辈训练家……有点不甘心\n"
	.string "啊。$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "小悠：我……我打算回未白镇了。\p"
	.string "你也知道我在帮爸爸收集宝可梦图\n"
	.string "鉴，现在进展得还挺不错，我要回去\l"
	.string "给他看看。$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}，你接下来打算做\n"
	.string "什么？\p"
	.string "收集所有的道馆徽章，然后去挑战宝\n"
	.string "可梦联盟吗？\p"
	.string "也许我也会试试……\p"
	.string "好了，无论如何，加油吧！$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}，你接下来打算做\n"
	.string "什么？\p"
	.string "你变得这么强了，试试挑战宝可梦联\n"
	.string "盟去吗？\p"
	.string "呵呵，就算我——如果能再努力训练一\n"
	.string "下，也许会比你更强的，\l"
	.string "{PLAYER}。\p"
	.string "好了，无论如何，加油吧！$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}，你接下来打算做\n"
	.string "什么？\p"
	.string "想去对战开拓区挑战吗？\p"
	.string "或者你想完成宝可梦图鉴？\p"
	.string "既然你已经这么强了，考虑一下去对\n"
	.string "战开拓区吧。\p"
	.string "呵呵，如果我更努力训练的话，也许\n"
	.string "就会比你更强了，\l"
	.string "{PLAYER}。\p"
	.string "可能我也该去对战开拓区看看。\p"
	.string "好了，无论如何，加油吧！$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "哼哼哼……\p"
	.string "我们今天往基地里搬了不少战利品……\p"
	.string "你……你是谁？！我只是在自言自语而\n"
	.string "已！$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "我只不过是个小兵，根本不知道老大\n"
	.string "在想什么……\p"
	.string "但我知道，只要加入海洋队，我总有\n"
	.string "机会做些大事的！\p"
	.string "你……你是谁？！我只是在自言自语而\n"
	.string "已！$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "喂，说你呢！\p"
	.string "别靠近海湾那儿的洞窟！\p"
	.string "为什么？我凭啥要告诉你！我是大\n"
	.string "人，所以你得听我的！$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "如果这广阔的世界都归属于我们海洋\n"
	.string "队，那么世上的宝可梦会生活得更快\l"
	.string "乐的。$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "这里！吼吼鲸！跳出水来！$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "嗯？你想干什么？\p"
	.string "你打扰了我们训练了，所以你能不\n"
	.string "能，那个，赶紧消失啊？$"

LilycoveCity_Text_ContestHallInTown:
	.string "这个城镇里就有个宝可梦华丽大赛会\n"
	.string "场，\p"
	.string "全国的悉心培育的宝可梦都会在这里\n"
	.string "聚集。\p"
	.string "我已经激动得心跳加速了！$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "你看到镇子边缘的海湾里那个可疑的\n"
	.string "洞窟了吗？$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "我打算教我的宝可梦一些新的招式去\n"
	.string "参加比赛，\p"
	.string "但我得先去遗忘爷爷那儿让它忘记秘\n"
	.string "传招式。$"

LilycoveCity_Text_ImFromKanto:
	.string "我是从关都来的。\p"
	.string "有着青山碧水的丰缘地区真的很美。\p"
	.string "呃？等等……\p"
	.string "也许会有只在这片地区生活的稀有宝\n"
	.string "可梦吧？$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "海洋队一直在海湾训练他们的吼吼\n"
	.string "鲸。\p"
	.string "他们挡着路，我们水手根本没法驾船\n"
	.string "出海！$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "喂，知道吗？\p"
	.string "有人替我们赶走了海洋队！\p"
	.string "海湾那边的那些吼吼鲸也因此离开\n"
	.string "了，我们的船又能出海了。$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "刚才我在海边的民宿里听着潮声睡了\n"
	.string "一觉……\p"
	.string "有人却趁机偷了我的宝可梦！\p"
	.string "是谁干的？海洋队？是海洋队吗？$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "我那失踪的宝可梦……在我没注意时自\n"
	.string "己回来了！$"

LilycoveCity_Text_ImArtDealer:
	.string "我是一名艺术品商人。\p"
	.string "我的工作是买卖艺术品，尤其是绘\n"
	.string "画。\p"
	.string "我听说这里的美术馆正在展出美妙绝\n"
	.string "伦的艺术品……$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "时间在我们的脸上刻下了皱纹，而大\n"
	.string "海却还是一如既往地年轻，充满了生\l"
	.string "命的活力……\p"
	.string "呼呵呵呵呵……$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "老伴提议到这儿来居住已经是六十年\n"
	.string "前的事了，而大海却依旧那样年轻美\l"
	.string "丽。\p"
	.string "呼呵呵呵呵……$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "你知道这个海湾那里奇怪的山洞吗？\p"
	.string "那里原来是个天然洞窟，后来海洋队\n"
	.string "来到这里，整修了那个山洞。\p"
	.string "他们自称“热爱自然的海洋队”！\p"
	.string "但他们说的跟做的完全背道而驰！$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "那个海湾的洞窟……\p"
	.string "一开始我没注意，但它现在已经空\n"
	.string "了。\p"
	.string "那些海洋队一定是全体卷铺盖跑路\n"
	.string "了。$"

LilycoveCity_Text_CitySign:
	.string "水静市\p"
	.string "“陆地尽头，海洋开始的地方。”$"

LilycoveCity_Text_ContestHallSign:
	.string "宝可梦华丽大赛会场“训练家聚集的\n"
	.string "地方！”$"

LilycoveCity_Text_MotelSign:
	.string "静水民宿\p"
	.string "“请记住我们——水静市的静水。”$"

LilycoveCity_Text_MuseumSign:
	.string "水静市美术馆\p"
	.string "“大量宝可梦名作正在展出！”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "水静市美术馆\p"
	.string "“{PLAYER}的宝可梦收藏品\n"
	.string "正在展出！”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "水静市港口\p"
	.string "“破浪号渡轮正在凯那市建造中，\p"
	.string "预计近期即可通航。”$"

LilycoveCity_Text_HarborSign:
	.string "水静市港口\p"
	.string "“愿破浪号渡轮能为您带来最快乐的\n"
	.string "旅行体验。”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "宝可梦训练家俱乐部\p"
	.string "牌子上潦草地写着一些训练家的名\n"
	.string "字……$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "水静百货\p"
	.string "“满载着商品和快乐回家！”\p"
	.string "“寻找你所需要的物品的最佳地点！"
	.string "”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "遗忘爷爷的家\p"
	.string "“让宝可梦忘记不需要的招式。”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "你知道叫做树果混合器的机器吗？$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "大家必须齐心协力才能让它转得更\n"
	.string "快。\p"
	.string "听说转得越快，就能做出品质越好的\n"
	.string "{POKEBLOCK}呢。$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "这是用来制作一种叫作\n"
	.string "{POKEBLOCK}的糖果的。\p"
	.string "给宝可梦喂食高品质的\n"
	.string "{POKEBLOCK}，它的状态\l"
	.string "就会大幅提升哦。$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "据说水路某处有座塔，\p"
	.string "叫做天空之柱。$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "我在130号水路的附近看到过一座高\n"
	.string "高的塔，\p"
	.string "那会不会是……？$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "我们刚刚来这里蜜月旅行，\p"
	.string "却偶然看到一只龙属性宝可梦从天空\n"
	.string "飞过。\p"
	.string "丰缘有生活着那么厉害的宝可梦吗？$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "我们曾许愿要在蜜月中看到很多很多\n"
	.string "稀有宝可梦，\p"
	.string "并且我们一到这儿就看到了稀有宝可\n"
	.string "梦。\p"
	.string "我是说，我真的很高兴！$"

