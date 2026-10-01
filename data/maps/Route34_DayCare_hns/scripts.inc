Route34_DayCare_hns_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	lock
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE1_WINDOW
	release
	end

Route34_DayCare_Bookshelf2::
	lock
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE2_WINDOW
	release
	end

Route34_DayCare_Bookshelf3::
	lock
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE3_WINDOW
	release
	end

Route34_DayCare_Bookshelf4::
	lock
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE4_WINDOW
	release
	end

Route34_DayCare_Text_Bookshelf1:
	.string "幼年宝可梦百科全书！\p"
	.string "第1卷：特性大揭秘$"

Route34_DayCare_Text_Bookshelf2:
	.string "幼年宝可梦百科全书！\p"
	.string "第2卷：常见属性$"

Route34_DayCare_Text_Bookshelf3:
	.string "幼年宝可梦百科全书！\p"
	.string "第3卷：宝宝们的叫声$"

Route34_DayCare_Text_Bookshelf4:
	.string "幼年宝可梦百科全书！\p"
	.string "第4卷：可爱的动作$"

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	setvar VAR_0x8005, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	case 8, Route34_DayCare_EventScript_GiveMantyke
	case 9, Route34_DayCare_EventScript_GiveBonsly
	case 10, Route34_DayCare_EventScript_GiveHappiny
	case 11, Route34_DayCare_EventScript_GiveMimeJr
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMantyke::
	giveoddegg 8
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveBonsly::
	giveoddegg 9
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveHappiny::
	giveoddegg 10
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMimeJr::
	giveoddegg 11
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
	.string "我是培育屋夫妇的儿子。\p"
	.string "在一位训练家的宝可梦身边发现了一\n"
	.string "颗不可思议的蛋，但他们并不想要"
	.string "。.....\p"
	.string "我很想把它交给你……但我怎么能确定\n"
	.string "你会好好照顾它呢？$"

Route34_DayCare_Text_ClerkNoRoom:
	.string "看来你身上已经带不下更多的宝可梦\n"
	.string "了。$"

Route34_DayCare_Text_ClerkQuestion:
	.string "回答我这个问题。你对这颗不可思议\n"
	.string "的蛋怎么看？$"

Route34_DayCare_Text_Rejection:
	.string "嗯，我觉得这颗蛋不适合你。\p"
	.string "要是把这么珍贵的蛋交给一个对幼年\n"
	.string "宝可梦不够了解的人，未免也太不负\l"
	.string "责任了！$"

Route34_DayCare_Text_ReceivedOddEgg:
	.string "{PLAYER}收下了不可思议的\n"
	.string "蛋。$"

Route34_DayCare_Text_TakeCare:
	.string "我就知道你是最合适的人选。请好好\n"
	.string "照顾它吧！$"

Route34_DayCare_Text_ClerkAfter:
	.string "我们在这附近见过很多蛋，\p"
	.string "不过那个蛋总觉得有点与众不同呢。$"

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
	.string "百变怪：呗哆！$"

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_HG_OBTAIN_EGG
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_ClosedForChallenge::
	msgbox Route34_DayCare_Text_ClosedForChallenge, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Text_ClosedForChallenge:
	.string "抱歉，在同行宝可梦数量受限的挑战\n"
	.string "期间，我们不能代为照顾你的宝可\l"
	.string "梦！$"

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "我是培育屋的爷爷。\p"
	.string "我负责替训练家照顾他们珍贵的宝可\n"
	.string "梦。\p"
	.string "如果你想寄放宝可梦，请跟我老伴说\n"
	.string "吧。$"

Route34_Text_DoYouWantEgg:
	.string "哎呀，是你啊！\p"
	.string "在照顾你的宝可梦的时候，真是吓了\n"
	.string "一大跳啊！\p"
	.string "你的宝可梦竟然抱着一个蛋！\p"
	.string "虽然不知道是怎么来的，但确实是你\n"
	.string "的宝可梦带来的。\p"
	.string "你想要这个蛋吧？$"

Route34_Text_YourMonIsDoingFine:
	.string "哎呀，是你啊！见到你真高兴。你的\n"
	.string "{STR_VAR_1}精神得很\l"
	.string "呢。$"

Route34_Text_IllKeepIt:
	.string "这样啊，那我就自己留着了。谢谢你\n"
	.string "啦！$"

Route34_Text_YouHaveNoRoomForIt:
	.string "你的同行宝可梦已经满了…….腾出空\n"
	.string "位后再来吧。$"

Route34_Text_ReceivedEgg:
	.string "{PLAYER}从培育屋爷爷那里\n"
	.string "收到了蛋！$"

Route34_Text_TakeGoodCareOfIt:
	.string "要好好照顾它哦。$"

Route34_Text_FriendlyWithOtherTrainersMon:
	.string "顺便说一下你的\n"
	.string "{STR_VAR_1}，它和\l"
	.string "{STR_VAR_2}的\l"
	.string "{STR_VAR_3}相处得挺不\l"
	.string "错呢。\p"
	.string "我好像还看到它收到了一封邮件呢。$"

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
	.string "如果你想领回宝可梦，请跟我老伴说\n"
	.string "吧。$"

Route34_Text_YourMonsAreDoingFine:
	.string "哎呀，是你啊！你的\n"
	.string "{STR_VAR_1}和\l"
	.string "{STR_VAR_2}都精神得很\l"
	.string "呢。$"

Route34_Text_IWillKeepDoYouWantIt:
	.string "我真的会自己留着的哦。你其实还是\n"
	.string "想要的，对吧？$"

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "我是培育屋的奶奶。\p"
	.string "我们能替你照顾宝可梦。\p"
	.string "你想寄放宝可梦吗？$"

Route34_DayCare_Text_WhichMonShouldWeRaise:
	.string "要把哪只宝可梦寄放在这里呢？$"

Route34_DayCare_Text_WellRaiseYourMon:
	.string "好的，我们会替你照顾\n"
	.string "{STR_VAR_1}一阵子的。\p"
	.string "过段时间再来领吧。$"

Route34_DayCare_Text_WeCanRaiseOneMore:
	.string "我们一共可以寄放两只宝可梦。还要\n"
	.string "再寄放一只吗？$"

Route34_DayCare_Text_HusbandWasLookingForYou:
	.string "我老伴刚才在找你呢。$"

Route34_DayCare_Text_FineThenComeAgain:
	.string "哎呀，这样啊。欢迎下次再来。$"

Route34_DayCare_Text_NotEnoughMoney:
	.string "你的钱不够呢……$"

Route34_DayCare_Text_TakeOtherOneBackToo:
	.string "另一只也要一起领回去吗？$"

Route34_DayCare_Text_ComeAgain:
	.string "好嘞。欢迎下次再来。$"

Route34_DayCare_Text_GoodToSeeYou:
	.string "哎呀，是你啊！见到你真高兴。你的\n"
	.string "宝可梦好得不能再好啦！$"

Route34_DayCare_Text_YourMonHasGrownXLevels:
	.string "按等级来看，你的\n"
	.string "{STR_VAR_1}提升了\l"
	.string "{STR_VAR_2}级。$"

Route34_DayCare_Text_YourTeamIsFull:
	.string "你的宝可梦队伍已经满了。腾出空位\n"
	.string "后再来找我吧。$"

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
	.string "你要领回哪只宝可梦？$"

Route34_DayCare_Text_ItWillCostX:
	.string "如果想领回你的\n"
	.string "{STR_VAR_1}，费用是¥\l"
	.string "{STR_VAR_2}。$"

Route34_DayCare_Text_HeresYourMon:
	.string "好的！这是你的宝可梦。$"

Route34_DayCare_Text_TookBackMon:
	.string "{PLAYER}从培育屋婆婆那里\n"
	.string "领回了{STR_VAR_1}。$"

Route34_DayCare_Text_YouHaveJustOneMon:
	.string "哎呀？可是你身上只有一只宝可梦\n"
	.string "呀。\p"
	.string "下次再来吧。$"

Route34_DayCare_Text_TakeYourMonBack:
	.string "要领回你的宝可梦吗？$"

Route34_DayCare_Text_WhatWillYouBattleWith:
	.string "要是把这只宝可梦留在我这儿，你拿\n"
	.string "什么去对战呢？\p"
	.string "下次再来吧。$"

Route34_DayCare_Text_YoullBeLeftWithJustOne:
	.string "哎？等等，等等。\p"
	.string "要是把那只宝可梦留在我这儿，你就\n"
	.string "只剩下一只宝可梦了。\p"
	.string "依老夫看，你最好多捉几只宝可梦再\n"
	.string "来吧。$"
