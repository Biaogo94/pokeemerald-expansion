FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "人类……宝可梦……\p"
	.string "他们隐藏的力量会被自然中的生活唤\n"
	.string "醒……$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "让我这老人看看你隐藏的力量是不是\n"
	.string "觉醒了……\p"
	.string "我手里有一枚硬币。\p"
	.string "告诉我，我是把它藏在了左手里呢，\n"
	.string "还有右手里？$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "哎，没错，答对了！\p"
	.string "我们再试一次。\p"
	.string "我把硬币藏在哪儿？左手还是右手？$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "哎，没错，答对了！\p"
	.string "我们再试一次。\p"
	.string "我把硬币藏在哪儿？左手还是右手？$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "啊！完全正确！你的力量觉醒了！\p"
	.string "来，这个给你，也让你的宝可梦的力\n"
	.string "量觉醒吧。$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "觉醒力量是会随着使用它的宝可梦不\n"
	.string "同而改变的招式。$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "哎，真遗憾，你猜错了。$"

