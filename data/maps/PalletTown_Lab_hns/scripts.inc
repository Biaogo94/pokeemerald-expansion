PalletTown_Lab_hns_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_ROUTE28_SCIENTIST, 1
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "你的宝可梦图鉴进展如何了？$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "大木：啊，{PLAYER}！你大\n"
	.string "老远赶到关都来，真是辛苦你了。\p"
	.string "你觉得这边的训练家怎么样？相当厉\n"
	.string "害吧？$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "如果你在附近的话，随时欢迎再来看\n"
	.string "看我。$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "大木：哇！太棒了！\p"
	.string "你集齐了关都的所有道馆徽章！干得\n"
	.string "真漂亮！\p"
	.string "我果然没有看错你。\p"
	.string "这样吧，{PLAYER}。我会去\n"
	.string "打个招呼，让你能够前往白银山。\p"
	.string "白银山是一座巨大的高山，栖息着很\n"
	.string "多野生的宝可梦。\p"
	.string "对一般的训练家来说那里太危险了，\n"
	.string "所以平常是禁止进入的。不过对你来\l"
	.string "说就可以破例了，{PLAYER}\l"
	.string "。\p"
	.string "前往石英高原吧。从那里就可以出发\n"
	.string "前往白银山了。$"

PalletTown_Lab_Text_OakOpenIndigoPlateau:
	.string "对了，说到石英高原，既然你已经拿\n"
	.string "到了全部16枚徽章，关都联盟也准\l"
	.string "备好再次接受你的挑战了。\p"
	.string "不过要小心，阿渡和他的四天王这次\n"
	.string "可绝对不会手下留情哦。\p"
	.string "祝你好运，{PLAYER}！$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "大木：嗯？你没在收集关都的道馆徽\n"
	.string "章吗？\p"
	.string "关都的道馆馆主们，可不输给城都地\n"
	.string "方的任何强敌啊。\p"
	.string "我建议你去向他们挑战看看。$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "大木：啊，你正在收集关都的道馆徽\n"
	.string "章啊。\p"
	.string "虽然一路肯定很不容易，但这段经历\n"
	.string "一定会成为你的宝贵财富。\p"
	.string "等你全部收集齐了，就来找我吧。\p"
	.string "我会准备一份礼物送给你的。\p"
	.string "继续加油哦，{PLAYER}！$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "关都这边收不到大木博士的《宝可梦\n"
	.string "讲座》广播呢。\p"
	.string "真可惜，我也好想听听看啊。$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "多亏了你在图鉴上的努力，博士的研\n"
	.string "究进展得非常顺利呢。$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "这事可别告诉别人，大木博士的《宝\n"
	.string "可梦讲座》其实不是现场直播的。$"

PalletTown_Lab_Text_OaksLabPC:
	.string "电脑上有一封电子邮件。\p"
	.string "......\p"
	.string "大木博士，您的研究进展得怎么样了\n"
	.string "？\p"
	.string "我这边还在埋头苦干呢。\p"
	.string "我听说{PLAYER}现在名气越\n"
	.string "来越大了。\p"
	.string "听到这个消息我真替TA高兴。\p"
	.string "若叶镇 空木 8-)$"
