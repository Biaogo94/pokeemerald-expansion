SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "看一看瞧一瞧啊！老夫乃姓名鉴定师\n"
	.string "。也就是看名字算命的。\p"
	.string "来，让老夫来算算你宝可梦的昵称吧\n"
	.string "。$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "你想算哪只宝可梦的昵称啊？$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "唔......叫\n"
	.string "{STR_VAR_1}是吧？起得\l"
	.string "相当不错嘛。\p"
	.string "不过！如果让我给它改一个稍微好听\n"
	.string "一点的名字，你意下如何？$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "是吗，那……取个什么昵称好呢？$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "好！从今天起这只宝可梦就叫\n"
	.string "{STR_VAR_1}啦！\p"
	.string "比之前的名字好听太多了，太好了太\n"
	.string "好了！$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "这样啊。知道了，你有空再来吧。$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "搞定！从现在起，这只宝可梦的名字\n"
	.string "就叫做{STR_VAR_1}了！\p"
	.string "虽然看起来和之前一样，但这可是比\n"
	.string "原来大有长进哦！\p"
	.string "真是太幸运啦！$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "唔嗯……{STR_VAR_1}啊\n"
	.string "！\p"
	.string "这昵称好听到无可挑剔！\p"
	.string "今后你也要好好爱护\n"
	.string "{STR_VAR_1}哦！$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "喂喂……这不是颗蛋吗！$"

