LakeOfRage_House2_hns_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "LAKE OF RAGE is actually a crater\n"
    .string "made by rampaging GYARADOS.\p"
    .string "The crater filled up with rainwater\n"
    .string "and the LAKE was formed.\p"
    .string "That's the story passed on from my\n"
    .string "Grandpa's great-great-grandpa.\p"
    .string "It used to be that you could catch\n"
    .string "lively MAGIKARP there, but…\p"
    .string "I don't understand what's happening.$"

LakeOfRage_House2_Text_MenInBlack:
    .string "The LAKE hasn't been normal since\n"
    .string "those men wearing black arrived.$"

LakeOfRage_House2_Text_LastMon:
    .string "Well don't let me take your last\n"
    .string "POKéMON!$"

LakeOfRage_House2_Text_WorldsLargest:
    .string "LAKE OF RAGE is back to normal.\p"
    .string "The MAGIKARP have returned.\p"
    .string "I may yet realize my dream of own-\n"
    .string "ing the world's largest MAGIKARP.\p"
    .string "In fact... I'll pay you ¥2000 for\n"
	.string "every MAGIKARP you give me, and\l"
	.string "¥100,000 for a HUGE MAGIKARP!$"

LakeOfRage_House2_Text_ForMe:
	.string "So... Do you have a MAGIKARP for\n"
	.string "me?$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "Ah, you have a MAGIKARP! Let's\n"
    .string "see how big that baby is.$"

LakeOfRage_House2_Text_BigPayout:
    .string "哇！这条真是太出色了！\p"
    .string "我对你佩服得五体投地！\p"
    .string "这点薄礼是给你的酬劳。$"

LakeOfRage_House2_Text_Bonus:
    .string "最重要的还是打破纪录。\p"
    .string "那个就当作是额外的奖励吧！$"

LakeOfRage_House2_Text_TooShort:
    .string "哇！这条真是太出色了！\p"
    .string "......虽然很想这么说，但我\n"
    .string "以前见过更大的。\p"
    .string "不过也是值得奖励的。$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "什么？这不是鲤鱼王啊！$"

LakeOfRage_House2_Text_Refused:
    .string "Oh… So you didn't get one good\n"
    .string "enough to show me? Maybe next time.$"
