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
	.string "That's strange.\n"
	.string "I won before.$"

Route30_Text_YoungsterMikeyAfter:
	.string "Becoming a good trainer is\n"
	.string "really tough.\p"
	.string "I'm going to battle other\n"
	.string "people to get better.$"

Route30_Text_BugCatcherDonSeen:
	.string "Instead of a bug POKéMON,\n"
	.string "I found a trainer!$"

Route30_Text_BugCatcherDonBeaten:
	.string "哎呀！你也太强了吧！$"

Route30_Text_BugCatcherDonAfter:
	.string "I ran out of POKé BALLS while\n"
	.string "I was catching POKéMON.\p"
	.string "I should've bought some more…$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "MR. POKéMON's house?\n"
	.string "It's a bit farther ahead.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "大家都在开心地对战呢！\p"
	.string "你也一起来吧！$"

Route30_Text_CooltrainerF:
	.string "I'm not a trainer.\p"
	.string "But if you look one in the\n"
	.string "eyes, prepare to battle.$"

Route30_Text_Sign:
	.string "30号道路\p"
	.string "桔梗市 - 吉花市$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "MR. POKéMON'S HOUSE\n"
	.string "STRAIGHT AHEAD!$"

Route30_Text_MrPokemonsHouseSign:
	.string "宝可梦爷爷的家$"

Route30_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "No stealing other people's\n"
	.string "POKéMON!\p"
	.string "POKé BALLS are to be thrown\n"
	.string "only at wild POKéMON!$"

Route30_Text_JoeyRegister:
	.string "You're pretty good!\p"
	.string "My RATTATA's raring to go,\n"
	.string "just like always.\p"
	.string "It's the only one I have.\n"
	.string "I'm going to become a great\l"
	.string "TRAINER with it!\p"
	.string "Let's battle again sometime!$"

Route30_Text_JoeyRematchIntro:
	.string "I promised things would be\n"
	.string "different! Let's battle!$"

Route30_Text_JoeyRematchDefeat:
	.string "啊！我又输了！真可恶！$"

Route30_Text_JoeyPostRematch:
	.string "I'm checking out my\n"
	.string "RATTATA's moves and devising\l"
	.string "some strategies.\p"
	.string "When I come up with a good\n"
	.string "one, let's battle!$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "I lost again…\n"
	.string "Gee, you're tough!\p"
	.string "Oh yeah, I almost forgot that\n"
	.string "I had to give you this.\p"
	.string "Use it to get even tougher,\n"
	.string "OK?\p"
	.string "I'm going to get tougher too.$"

Route30_Text_ElmName:
	.string "空木博士$"

Route30_Text_Elm_Disaster:
	.string "PROF.ELM: H-hello? {PLAYER}? It's\n"
	.string "a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do? It…\n"
	.string "Oh, no…\p"
	.string "Please get back here now!$"


Route30_Text_Poliwag:
	.string "蚊香蝌蚪：呦~呦！$"
