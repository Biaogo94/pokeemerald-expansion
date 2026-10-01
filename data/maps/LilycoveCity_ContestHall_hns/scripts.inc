@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_hns_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1_hns::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2_hns::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl_hns::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor_hns::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1_hns::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1_hns::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear_hns, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns:
	.string "这只宝可梦之前在这里拿过美丽大赛\n"
	.string "的冠军。\p"
	.string "你猜怎么着？今天我又让它赢下了聪\n"
	.string "明大赛！\p"
	.string "我连自己的才能都感到害怕了......$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns:
	.string "我参加过很多次华丽大赛，所以差不\n"
	.string "多摸清门道了。\p"
	.string "比如在帅气大赛中，帅气的招式就能\n"
	.string "获得热烈反响。\p"
	.string "但要是用聪明或可爱的招式，反响就\n"
	.string "不会太好了。$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns:
	.string "刚才获胜的那个小伙子有好多不同种\n"
	.string "类的{POKEBLOCK}呢。\p"
	.string "只要拥有那么多，就能获胜吗？$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns:
	.string "哇，这地方也太大了吧！\p"
	.string "空气中弥漫的紧张感……跟乡下的华丽\n"
	.string "大赛会场完全不同。$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns:
	.string "主持人：好啦，各位聪明的宝可梦和\n"
	.string "训练家们，准备好了吗？！\p"
	.string "发挥出你们最棒的实力吧！表演开\n"
	.string "始！$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns:
	.string "评审：这次华丽大赛玩得开心吗？\p"
	.string "叫上三个朋友一起来，大家就能一起\n"
	.string "参加华丽大赛了哦！$"

LilycoveCity_ContestHall_Text_EnteredWrongContest_hns:
	.string "哎呀呀呀……我报错组别了"
	.string "。\p"
	.string "居然把这只擅长强壮的宝可梦报进了\n"
	.string "聪明大赛……\p"
	.string "上吧，用看起来很聪明的碎岩震撼全\n"
	.string "场吧！$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns:
	.string "我耗费了多年心血和全部智慧，才把\n"
	.string "这只宝可梦培养得如此聪明。\p"
	.string "它可不会轻易输给那些年轻毛头的宝\n"
	.string "可梦。\p"
	.string "老伴啊，你看到了吗？$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns:
	.string "机会来了！\p"
	.string "如果我的宝可梦接下来用出聪明的招\n"
	.string "式，全场观众的热情就会达到最高\l"
	.string "潮！$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns:
	.string "哎呀，怎么这样！\p"
	.string "我家宝贝超音蝠的吸血那么可爱，所\n"
	.string "以我才连续用了好几次嘛！\p"
	.string "这些不解风情的人完全不懂得欣赏！$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns:
	.string "呀啊--！爷爷好美啊！$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns:
	.string "即使训练家派出了同一种宝可梦，表\n"
	.string "演时使用的招式似乎也各不相同呢。\p"
	.string "就像每个人都有不同的对战风格一\n"
	.string "样。$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns:
	.string "我觉得那些宝可梦看起来比它们的训\n"
	.string "练家聪明多了，而且是聪明得多。$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns:
	.string "说到底，我还是最喜欢聪明大赛。\p"
	.string "那充满知性的绿色……真是太……太帅气\n"
	.string "了。$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns:
	.string "主持人：你也要参加美丽组的华丽大\n"
	.string "赛吗？祝你好运！$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns:
	.string "评委：啊，这里的每一只宝可梦都是\n"
	.string "纯粹美丽的典范！\p"
	.string "哎呀，我都陶醉得差点忘了打分了！$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns:
	.string "这么美丽的宝可梦……绝找不出第二\n"
	.string "只。\p"
	.string "大家的目光都会被我的美丽所吸引。$"

LilycoveCity_ContestHall_Text_OverdidGrooming_hns:
	.string "哇啊啊！\p"
	.string "为了这次华丽大赛，我明明很用心地\n"
	.string "给宝可梦梳理毛发了……\p"
	.string "但我弄得太起劲了……它的毛发全变得\n"
	.string "乱蓬蓬的了……\p"
	.string "我该怎么办啊？$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns:
	.string "这招极光束实在是太耀眼了，耀眼得\n"
	.string "评委都看不清了。\p"
	.string "呃，等等……这样一来不就完全没有意\n"
	.string "义了吗！$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns:
	.string "这只漂亮的宝可梦，长得就像我年轻\n"
	.string "的时候一样呢。\p"
	.string "结果我刚这么一说，我丈夫就把嘴里\n"
	.string "的咖啡喷了出来。\p"
	.string "我有说什么好笑的事吗？$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns:
	.string "要是能在美丽组的大赛中获胜，真的\n"
	.string "会让人超级开心呢。不管怎样，都比\l"
	.string "平时高兴多了。$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns:
	.string "哇哈哈哈哈！\p"
	.string "快瞧瞧那些漂亮的宝可梦！我就喜欢\n"
	.string "这种光彩夺目的场面！$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns:
	.string "光靠天生漂亮可赢不了比赛。\p"
	.string "你必须好好打理你的宝可梦，让它像\n"
	.string "我这只一样光鲜亮丽才行。$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns:
	.string "主持人：哎呀！你好呀！我们正在举\n"
	.string "行华丽大赛呢！\p"
	.string "如果想登台，请先到接待处报名登记\n"
	.string "再入场好吗？$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns:
	.string "评委：哦，真是既迷人又可爱的表演\n"
	.string "啊！\p"
	.string "天哪！这记“玩水”招式的表演真是可\n"
	.string "爱极了！$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns:
	.string "哎呀，糟了……我可爱的露力丽被别的\n"
	.string "宝可梦分散了注意力。$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns:
	.string "我的宝可梦在对战中从没赢过，但要\n"
	.string "是来华丽大赛，可得小心它的厉害\l"
	.string "了！$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns:
	.string "我的宝可梦跳出的花瓣舞，那可是优\n"
	.string "雅的极致。\p"
	.string "我绝不会让任何人打扰它的表演。$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns:
	.string "大家的宝可梦都很可爱。\p"
	.string "不过，要是我家宝可梦使出可爱表演\n"
	.string "的话……\p"
	.string "我相信绝对会比其他人可爱得多。$"

LilycoveCity_ContestHall_Text_MyChildIsInContest_hns:
	.string "我的孩子正在参加这场比赛呢。$"

LilycoveCity_ContestHall_Text_ComeOnDear_hns:
	.string "加油啊，宝贝，冲呀！你的宝可梦是\n"
	.string "最棒的！$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns:
	.string "我觉得那边那个女孩子是所有人里最\n"
	.string "可爱的。\p"
	.string "你说什么？这里评审的是宝可梦的外\n"
	.string "貌？$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns:
	.string "哇……看着这些可爱的宝可梦，我也好\n"
	.string "想拥有自己的宝可梦啊！\p"
	.string "我这就去抓几只！$"

LilycoveCity_ContestHall_Text_BeautyContestStage_hns:
	.string "美丽组华丽大赛舞台为美丽的宝可梦\n"
	.string "倾倒吧！$"

LilycoveCity_ContestHall_Text_CuteContestStage_hns:
	.string "可爱组华丽大赛舞台沉醉在可爱宝可\n"
	.string "梦的魅力中吧！$"

LilycoveCity_ContestHall_Text_SmartContestStage_hns:
	.string "聪明组华丽大赛舞台感受聪明宝可梦\n"
	.string "的过人智慧！$"

