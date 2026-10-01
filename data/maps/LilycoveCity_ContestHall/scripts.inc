@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "这只宝可梦曾在这里胜过漂亮华丽大\n"
	.string "赛，\p"
	.string "然后你猜怎么了？我今天又带它赢了\n"
	.string "聪明华丽大赛！\p"
	.string "我的能力连我自己都吓了一跳……$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "我多次参加过华丽大赛，所以比较了\n"
	.string "解这里的规则。\p"
	.string "如果你参加帅气大赛，帅气的招式才\n"
	.string "会吸引人，\p"
	.string "相对地，聪明的招式或可爱的招式等\n"
	.string "等就吸引不了别人。$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "刚才获胜的那个小伙子有好多不同种\n"
	.string "类的{POKEBLOCK}呢。\p"
	.string "只要拥有那么多，就能获胜吗？$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "哇，这儿好大！\p"
	.string "空气中充满了紧张感……一点也不像是\n"
	.string "华丽大赛会场。$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "主持人：好了，聪明宝可梦和训练家\n"
	.string "们，准备好了吗？！\p"
	.string "努力吧！开始！$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "评委：你喜欢这华丽大赛吗？\p"
	.string "和3个朋友一起来，大家可以一起参\n"
	.string "加大赛！$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "啊呀啊呀啊呀……我参加错了，\p"
	.string "我让我强大的宝可梦参加了聪明大\n"
	.string "赛……\p"
	.string "好吧，用你聪慧的碎岩让他们大吃一\n"
	.string "惊吧。$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "我花了多年时间，用尽心思让我的宝\n"
	.string "可梦看上去聪明些，\p"
	.string "我不会被那些年轻人的宝可梦轻易比\n"
	.string "下去的。\p"
	.string "亲爱的，你看到了吗？$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "就是现在！\p"
	.string "如果下面我的宝可梦使用聪明的招\n"
	.string "式，观众的兴奋点会达到巅峰！$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "哎，宝贝，不！\p"
	.string "我亲爱的超音蝠的吸血太可爱了，我\n"
	.string "就一遍遍不断使用它！\p"
	.string "但这就意味着大家不会再欣赏它了！$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "呀啊啊啊！爷爷，你真棒！$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "即使训练家使用相同的宝可梦，他们\n"
	.string "用来吸引人的招式也会不一样，\p"
	.string "这和大家的对战方式不同是同样的道\n"
	.string "理。$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "我想宝可梦看上去比它们的训练家还\n"
	.string "要聪明。$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "无论人们说什么，我都喜欢聪明大\n"
	.string "赛。\p"
	.string "那智慧的绿色……它非常……非常……美\n"
	.string "妙。$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "主持人：你也要参加漂亮部门吗？加\n"
	.string "油！$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "评委：啊，这儿的每只宝可梦都拥有\n"
	.string "着纯洁的美！\p"
	.string "哎，我都忘了要为它们计分了！$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "这么漂亮的宝可梦……没有什么能比得\n"
	.string "上它，\p"
	.string "大家的目光都会聚集在它的美丽上。$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "哇啊啊啊！\p"
	.string "参加大赛前我非常细心地为我的宝可\n"
	.string "梦梳洗……\p"
	.string "但我做得好像过头了……我的宝可梦的\n"
	.string "服装看上去很乱……\p"
	.string "我该怎么办？$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "极光束太耀眼了，评委会看不清的。\p"
	.string "呃，等等……这根本没有意义！$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "这只漂亮的宝可梦和我小时候很像。\p"
	.string "我这么说的时候，老公把咖啡都喷\n"
	.string "了。\p"
	.string "这句话很奇怪吗？$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "如果我在美丽华丽大赛取胜我会比平\n"
	.string "常任何时候都开心。$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "啊哈哈哈哈！\p"
	.string "看看这些漂亮的宝可梦！我最喜欢这\n"
	.string "种华丽！$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "只有美丽不可能长久获胜下去，\p"
	.string "还得经常为宝可梦梳洗，让它像我一\n"
	.string "样光彩照人。$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "主持人：呃，啊，你好！现在华丽大\n"
	.string "赛正在进行之中！\p"
	.string "请先去接待处登记再来参加比赛。$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "评委：啊，如此迷人，如此可爱！\p"
	.string "哎，天啊！那水之游多么完美，多么\n"
	.string "可爱！$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "哦，不……我的小露力丽被忽视了。$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "我的宝可梦对战从未赢过，但看看它\n"
	.string "在华丽大赛的表现吧！$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "我的宝可梦的花之舞奇妙而优美，\p"
	.string "我不会让任何人打扰它的表演。$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "大家的宝可梦都很可爱，\p"
	.string "但是，如果我的宝可梦想表现的可爱\n"
	.string "一些……\p"
	.string "我相信它会比其他的更可爱。$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "我孩子正在参加华丽大赛。$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "来吧，加油！你的宝可梦是最棒的！$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "我想那边的女孩是人群中最可爱的。\p"
	.string "你说什么？他们是在评判宝可梦的外\n"
	.string "貌？$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "看着这些可爱的宝可梦，让我也想自\n"
	.string "己拥有一只！\p"
	.string "我要去捕捉一只来！$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "漂亮部门会场美丽宝可梦的诱惑！$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "可爱部门会场迷醉于可爱的宝可梦\n"
	.string "吧！$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "聪明部门会场聪明的宝可梦，深刻的\n"
	.string "印象！$"

