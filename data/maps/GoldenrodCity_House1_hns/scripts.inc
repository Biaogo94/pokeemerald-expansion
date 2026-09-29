GoldenrodCity_House1_hns_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	@special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "要切换异色宝可梦的专属配色设置吗\n"
	.string "？$"

GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "已切换异色配色设置！\p"
	.string "可以在任意电脑的挑战查看器中查看\n"
	.string "你的设置。$"

GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "是新闻……\p"
	.string "警察正在寻找这个红发少年！\p"
	.string "你知道他的名字吗？$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "你好呀！我是姓名鉴定师！我能为名\n"
	.string "字占卜算命哦！\p"
	.string "我很乐意为你宝可梦的昵称进行一番\n"
	.string "鉴定。$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "你想让我为哪只宝可梦鉴定昵称呢？$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "唔……叫\n"
	.string "{STR_VAR_1}是吧？起得\l"
	.string "相当不错嘛。\p"
	.string "不过！如果让我给它改一个稍微好听\n"
	.string "一点的名字，你意下如何？$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "啊，太好了。那么，新的昵称要叫什\n"
	.string "么呢？$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "搞定！从现在起，这只宝可梦的名字\n"
	.string "就叫做{STR_VAR_1}了！\p"
	.string "比以前的名字更好听呢！真是太幸运\n"
	.string "啦！$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "这样啊。欢迎下次再来。$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "搞定！从现在起，这只宝可梦的名字\n"
	.string "就叫做{STR_VAR_1}了！\p"
	.string "虽然看起来和之前一样，但这可是比\n"
	.string "原来大有长进哦！\p"
	.string "真是太幸运啦！$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "唔……是\n"
	.string "{STR_VAR_1}啊！\p"
	.string "这真是一个极好的昵称！简直无可挑\n"
	.string "剔！\p"
	.string "从今往后，你也要好好珍惜你的\n"
	.string "{STR_VAR_1}哦。$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "哎呀呀。这只是个蛋呀！$"


