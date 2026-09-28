Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "宝可梦爷爷的家$"

Route30_Text_UseTackle:
	.string "上啊，小拉达！\p"
	.string "撞击！$"

Route30_Text_ThisIsABigBattle:
	.string "干什么？这可是场激烈的对战！别来\n"
	.string "打扰我！$"

Route30_Text_YoungsterJoey1Seen:
	.string "我刚刚输了，所以正打算多抓几只宝\n"
	.string "可梦。\p"
	.string "等等！你看上去挺弱的嘛！来，跟我\n"
	.string "对战一场！$"

Route30_Text_YoungsterJoey1Beaten:
	.string "啊！我又输了！真可恶！$"

Route30_Text_YoungsterJoey1After:
	.string "要想对战变得更强，就非得收服更多\n"
	.string "宝可梦不可吗？\p"
	.string "不！不管怎样，我都要和这只伙伴坚\n"
	.string "持到底！$"

Route30_Text_YoungsterMikeySeen:
	.string "你也是宝可梦训练家，对吧？\p"
	.string "那就非得和我对战不可啦！$"

Route30_Text_YoungsterMikeyBeaten:
	.string "真奇怪。我以前明明赢过的。$"

Route30_Text_YoungsterMikeyAfter:
	.string "要成为优秀的训练家真不容易啊。\p"
	.string "我得去多和别人对战来提升自己。$"

Route30_Text_BugCatcherDonSeen:
	.string "没抓到虫宝可梦，倒抓到一个训练\n"
	.string "家！$"

Route30_Text_BugCatcherDonBeaten:
	.string "哎呀！你也太强了吧！$"

Route30_Text_BugCatcherDonAfter:
	.string "抓宝可梦的时候精灵球用光了。\p"
	.string "真应该多买几个备着的......$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "宝可梦爷爷的家？还要往前走一段路\n"
	.string "呢。$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "大家都在开心地对战呢！\p"
	.string "你也一起来吧！$"

Route30_Text_CooltrainerF:
	.string "我可不是训练家。\p"
	.string "不过只要和训练家眼神相遇，就得做\n"
	.string "好对战的准备哦。$"

Route30_Text_Sign:
	.string "30号道路\p"
	.string "桔梗市 - 吉花市$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "宝可梦爷爷的家直走即是！$"

Route30_Text_MrPokemonsHouseSign:
	.string "宝可梦爷爷的家$"

Route30_Text_TrainerTips:
	.string "训练家心得\p"
	.string "不准偷别人的宝可梦！\p"
	.string "精灵球只能用来收服野生的宝可梦！$"

Route30_Text_JoeyRegister:
	.string "你真厉害！\p"
	.string "不过我的小拉达也是干劲满满哦。\p"
	.string "虽然我只有这一只宝可梦，但我一定\n"
	.string "要和它一起成为顶尖的训练家！\p"
	.string "下次再来对战吧！$"

Route30_Text_JoeyRematchIntro:
	.string "我说过这次结果会不一样！来对战\n"
	.string "吧！$"

Route30_Text_JoeyRematchDefeat:
	.string "啊！我又输了！真可恶！$"

Route30_Text_JoeyPostRematch:
	.string "我正在研究小拉达的招式，思考新的\n"
	.string "战术呢。\p"
	.string "等我想到了好点子，咱们就来对战\n"
	.string "吧！$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "我又输了......天哪，你也太\n"
	.string "强了吧！\p"
	.string "对了，我差点忘了要把这个交给你。\p"
	.string "用它让自己变得更强吧，好吗？\p"
	.string "我也一定会变得更强的！$"

Route30_Text_ElmName:
	.string "空木博士$"

Route30_Text_Elm_Disaster:
	.string "空木博士：喂......喂？是\n"
	.string "{PLAYER}吗？大事不好了！\p"
	.string "呃、呜......简直太糟糕了！\p"
	.string "怎么办才好？它......天哪\n"
	.string "......\p"
	.string "请快点赶回研究所来！$"


Route30_Text_Poliwag:
	.string "蚊香蝌蚪：呦~呦！$"
