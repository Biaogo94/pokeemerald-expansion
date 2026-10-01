SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKantoMidBattle
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_ExitKantoMidBattle::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockGone::
	lockall
	message SafariZone_Text_PokeblockGone
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_PokeblockGone:
	.string "{STR_VAR_1}被吃光了！$"

SafariZone_Text_WouldYouLikeToExit:
	.string "要现在就退出狩猎地带吗？$"

SafariZone_Text_TimesUp:
	.string "叮——咚！时间到！狩猎游戏结束了。$"

SafariZone_Text_OutOfBalls:
	.string "狩猎球用完了，狩猎游戏结束了。$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "要在{POKEBLOCK}喂食器\n"
	.string "里放置{POKEBLOCK}吗？$"

SafariZone_Text_PokeblockStillHere:
	.string "之前放进去的\n"
	.string "{STR_VAR_1}还在里面。$"

SafariZone_Text_PokeblockWasPlaced:
	.string "把{STR_VAR_1}放进了\n"
	.string "{POKEBLOCK}喂食器里。$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "欢迎来到狩猎地带！\p"
	.string "在这里有许多丰缘地区难得一见的宝\n"
	.string "可梦，\p"
	.string "您可以观察这些野生宝可梦在自然栖\n"
	.string "息地的原始状态。\p"
	.string "更重要的是，我们已经向宝可梦训练\n"
	.string "家敞开了大门。\p"
	.string "您可以在这里捕捉想要的宝可梦并永\n"
	.string "久保留！\p"
	.string "尽情享受狩猎地带的乐趣吧！$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "欢迎来到狩猎地带！请问是第一次来\n"
	.string "这里吗？$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "尽情享受狩猎地带的乐趣吧！$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "进入狩猎地带以后，会给您30只狩猎\n"
	.string "球用来捕捉宝可梦，\p"
	.string "狩猎球用完或者您走满500步以后，\n"
	.string "狩猎游戏就会结束。\p"
	.string "尽情享受狩猎地带的乐趣吧！$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "欢迎来到狩猎地带！\p"
	.string "花¥500就可以尽情地捕捉宝可梦！要\n"
	.string "不要参加狩猎游戏呢？$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "好的，欢迎下次再来！$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "抱歉，您带的钱不够。$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "那么，收您¥500。$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "请收下狩猎球！$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER}得到了30个狩猎\n"
	.string "球。$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "游戏结束时我们会通知你的。\p"
	.string "在那之前，好好享受这次野外探险\n"
	.string "吧！$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "很抱歉，您的电脑盒子满了。$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "不好意思！你好像还没有\n"
	.string "{POKEBLOCK}盒。\p"
	.string "用{POKEBLOCK}S参加狩\n"
	.string "猎游戏，收获会更丰富。\p"
	.string "请带着{POKEBLOCK}盒再\n"
	.string "来。\p"
	.string "你可以从那里获得\n{POKEBLOCK}盒："
#if IS_HNS
	.string "那边的男孩。$"
#else
	.string "琉璃市华丽大赛会场。$"
#endif

SafariZone_South_Text_StillHaveTimeExit:
	.string "时间还有剩余，确定要结束狩猎游戏\n"
	.string "吗？$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "是吗，那就请您尽情享受狩猎游戏\n"
	.string "吧！$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "好吧。\p"
	.string "我会收回剩下的野生球。\p"
	.string "谢谢你的参与。欢迎下次再来！$"

SafariZone_South_Text_GoodLuck:
	.string "祝您好运！\p"
	.string "如果您需要什么，请随时告诉我！$"

SafariZone_South_Text_Boy:
	.string "知道吗？如果在那个\p"
	.string "方方的箱子里放进\n"
	.string "{POKEBLOCK}，宝可梦就\l"
	.string "会聚集到那附近。$"

SafariZone_South_Text_Man:
	.string "我本来想走得更深入一些，但我忘记\n"
	.string "带自行车了。\p"
	.string "直觉告诉我有稀有宝可梦生活在比较\n"
	.string "偏僻的地方。$"

SafariZone_Southwest_Text_Woman:
	.string "有的时候，宝可梦会无视我扔出去的\n"
	.string "{POKEBLOCK}。\p"
	.string "是不是宝可梦们对于食物也有不同的\n"
	.string "喜好呢？$"

SafariZone_Northwest_Text_Man:
	.string "呼……呼……我……终于到这儿了……不过……\p"
	.string "我已经累了……没力气去捕捉宝可梦\n"
	.string "了……$"

SafariZone_North_Text_Fisherman:
	.string "我需要找到一些丰缘地区所没有的水\n"
	.string "属性宝可梦，\p"
	.string "你知道湖泊在哪儿吗？$"

SafariZone_North_Text_Man:
	.string "我要在这里捕捉好多稀有宝可梦，然\n"
	.string "后跟我的朋友们交换！$"

SafariZone_South_Text_Youngster:
	.string "我把{POKEBLOCK}放到了\n"
	.string "{POKEBLOCK}喂食器里，\l"
	.string "但它很快就消失了。\p"
	.string "可能是在我没注意的时候被宝可梦吃\n"
	.string "掉了。$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "狩猎地带公告牌！\p"
	.string "向野生宝可梦投掷\n"
	.string "{POKEBLOCK}，可以降低\l"
	.string "它们逃跑的可能性。$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“放松一下你疲惫的双脚吧”休息小屋$"

SafariZone_RestHouse_Text_Youngster:
	.string "我没有{POKEBLOCK}，但\n"
	.string "我还是捕捉了很多宝可梦。\p"
	.string "先小心地接近，然后再扔出狩猎球，\n"
	.string "就更有可能捕捉到它们。$"

SafariZone_RestHouse_Text_PsychicM:
	.string "如果使用{POKEBLOCK}，\n"
	.string "野生宝可梦就不会那么容易逃跑。\p"
	.string "而对那些本就不太容易逃跑的宝可\n"
	.string "梦，使用{POKEBLOCK}效\l"
	.string "果不大。$"

SafariZone_RestHouse_Text_FatMan:
	.string "放在喂食器里的\n"
	.string "{POKEBLOCK}能够把宝可\l"
	.string "梦吸引来。\p"
	.string "我想有相似性格的宝可梦会被同一种\n"
	.string "{POKEBLOCK}吸引。$"

SafariZone_South_Text_AreaOffLimits1:
	.string "此处正在建设中，禁止入内。$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "狩猎地带的扩建已经完工。\p"
	.string "希望您能喜欢新的区域。$"

SafariZone_South_Text_AreaOffLimits2:
	.string "此处正在建设中，禁止入内。$"

SafariZone_Southeast_Text_LittleGirl:
	.string "呀～嗬！这些宝可梦都是我从来没见\n"
	.string "过的！$"

SafariZone_Southeast_Text_FatMan:
	.string "这些宝可梦我还是第一次见到，\p"
	.string "而且我还能捕捉这些稀有宝可梦！太\n"
	.string "棒了！$"

SafariZone_Southeast_Text_RichBoy:
	.string "这里的宝可梦好像是从丰缘以外的地\n"
	.string "区来的。$"

SafariZone_Northeast_Text_Boy:
	.string "我的狩猎球不剩几个了，\p"
	.string "我得好好考虑一下要捕捉什么样的宝\n"
	.string "可梦。$"

SafariZone_Northeast_Text_Woman:
	.string "据说有人在这附近发现过皮卡丘，究\n"
	.string "竟在哪儿呢？$"

SafariZone_Northeast_Text_Girl:
	.string "啊，真烦！怎么都抓不到宝可梦！\p"
	.string "要是再不捕捉些什么的话我就不在这\n"
	.string "儿浪费钱了！$"
