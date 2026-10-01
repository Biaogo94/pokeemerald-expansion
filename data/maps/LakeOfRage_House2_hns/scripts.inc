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
    .string "愤怒之湖其实是狂暴的暴鲤龙大肆破\n"
    .string "坏留下的凹坑。\p"
    .string "雨水积聚在凹坑里，最终形成了这个\n"
    .string "湖泊。\p"
    .string "这是从我爷爷的高祖父那一辈代代流\n"
    .string "传下来的传说。\p"
    .string "以前在那里还能钓到活蹦乱跳的鲤鱼\n"
    .string "王，可是……\p"
    .string "我完全搞不懂到底发生了什么。$"

LakeOfRage_House2_Text_MenInBlack:
    .string "自从那些穿黑衣服的家伙来之后，这\n"
    .string "片湖就变得不正常了。$"

LakeOfRage_House2_Text_LastMon:
    .string "哎呀，我可不能夺走你最后的宝可\n"
    .string "梦！$"

LakeOfRage_House2_Text_WorldsLargest:
    .string "愤怒之湖恢复正常了。\p"
    .string "鲤鱼王们都回来了。\p"
    .string "我终于有机会实现拥有世界第一大鲤\n"
    .string "鱼王的梦想了。\p"
    .string "这样吧……你给我的每一条鲤鱼王，我\n"
    .string "都付你¥2000，如果是特大号鲤鱼\l"
    .string "王，我就给¥100,000！$"

LakeOfRage_House2_Text_ForMe:
	.string "那么……你有带鲤鱼王来给我吗？$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "啊，你有鲤鱼王！来看看这个小家伙\n"
    .string "有多大吧。$"

LakeOfRage_House2_Text_BigPayout:
    .string "哇！这条真是太出色了！\p"
    .string "我对你佩服得五体投地！\p"
    .string "这点薄礼是给你的酬劳。$"

LakeOfRage_House2_Text_Bonus:
    .string "最重要的还是打破纪录。\p"
    .string "那个就当作是额外的奖励吧！$"

LakeOfRage_House2_Text_TooShort:
    .string "哇！这条真是太出色了！\p"
    .string "……虽然很想这么说，但我以前见过更\n"
    .string "大的。\p"
    .string "不过也是值得奖励的。$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "什么？这不是鲤鱼王啊！$"

LakeOfRage_House2_Text_Refused:
    .string "哎……没钓到能拿得出手的吗？那下次\n"
    .string "再说吧。$"
