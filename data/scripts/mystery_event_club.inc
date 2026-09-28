.equ GAVE_PROFILE,  VAR_TEMP_1

MysteryEventClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq GAVE_PROFILE, TRUE, EventScript_AlreadyGaveProfile
	goto_if_set FLAG_SYS_SET_TRAINER_CARD_PROFILE, EventScript_GivenProfileBefore
	msgbox Text_IdLoveToHearYourProfile
	goto EventScript_AskForProfile
	end

EventScript_AlreadyGaveProfile:
	msgbox Text_TellMoreNextTime
	release
	end

EventScript_AskForProfile:
	message Text_TellMeWhatsYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveProfile
	case 1, EventScript_DeclineGiveProfile
	case 2, EventScript_ProfileInfo
	case MULTI_B_PRESSED, EventScript_DeclineGiveProfile
	end

EventScript_ProfileInfo:
	msgbox Text_ExplainProfile
	goto EventScript_AskForProfile
	end

EventScript_AcceptGiveProfile:
	msgbox Text_WhatsYourProfile
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_CancelGiveProfile:
	msgbox Text_DecidedNotTo
	release
	end

EventScript_GaveProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_ProfileSaysSomethingAboutYou
	release
	end

EventScript_DeclineGiveProfile:
	msgbox Text_DontBeLikeThat
	release
	end

EventScript_GivenProfileBefore:
	msgbox Text_HiWeMeetAgain
	goto EventScript_AskForNewProfile
	end

EventScript_AskForNewProfile:
	message Text_ChangeYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveNewProfile
	case 1, EventScript_DeclineGiveNewProfile
	case 2, EventScript_ProfileInfo2
	@case MULTI_B_PRESSED, EventScript_DeclineGiveNewProfile
	end

EventScript_ProfileInfo2:
	msgbox Text_ExplainProfile
	goto EventScript_AskForNewProfile
	end

EventScript_AcceptGiveNewProfile:
	msgbox Text_WhatAreYouLikeNow
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_DeclineGiveNewProfile:
	msgbox Text_LikeProfileWayItIs
	release
	end

EventScript_GaveSpecialProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_HeardThatBefore
	release
	end

EventScript_GiveProfile:
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_0x8004, 0, EventScript_GaveSpecialProfile
	goto_if_eq VAR_RESULT, FALSE, EventScript_CancelGiveProfile
	goto_if_eq VAR_RESULT, TRUE, EventScript_GaveProfile
	end

Text_IdLoveToHearYourProfile:
	.string "你好，很高兴认识你！\p"
	.string "……你怎么不回我一声？打个招呼嘛！\p"
	.string "来，说说你自己吧。\p"
	.string "我很想看看你的个人介绍！$"

Text_TellMeWhatsYourProfile:
	.string "跟我说说你自己吧。你的个人介绍是\n"
	.string "什么？$"

Text_ExplainProfile:
	.string "个人介绍由四个词语组成。\p"
	.string "可选的词语有很多。\p"
	.string "它们都分好了类，找起来很方便。\p"
	.string "先选类别，再选一个词语。\p"
	.string "……听起来复杂，其实很简单。试试看\n"
	.string "吧？$"

Text_WhatsYourProfile:
	.string "你的个人介绍是什么？$"

Text_DontBeLikeThat:
	.string "哎呀，别这样。告诉我你的个人介绍\n"
	.string "嘛。$"

Text_DecidedNotTo:
	.string "哦，不想说了？你可真善变。$"

Text_HiWeMeetAgain:
	.string "嗨！我们又见面了！$"

Text_ChangeYourProfile:
	.string "要修改你的个人介绍吗？$"

Text_WhatAreYouLikeNow:
	.string "现在的你是什么样的？真想听听。$"

Text_LikeProfileWayItIs:
	.string "好，你喜欢现在的个人介绍。\p"
	.string "我也觉得挺好。$"

Text_ProfileSaysSomethingAboutYou:
	.string "嗯哼……\p"
	.string "你的个人介绍很能体现你的性格。\p"
	.string "现在更了解你了，我们也更像朋友\n"
	.string "了！$"

Text_HeardThatBefore:
	.string "哦，这话我好像听过……\p"
	.string "住在远方的表亲似乎总爱这么说。$"

Text_TellMoreNextTime:
	.string "下次再多说说你的事吧！$"
