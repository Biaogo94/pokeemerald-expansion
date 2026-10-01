LakeOfRage_House1_hns_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
    .string "……你走得很远了呢......\p"
    .string "我一直在此冥想。在我体内，有一股\n"
    .string "全新的力量觉醒了。\p"
    .string "让我把这份力量分给你的宝可梦吧。\n"
    .string "收下这个，孩子。$"

HiddenPowerGuy_Text_Explanation:
    .string "感觉到了吗？那就是“觉醒力量”！\p"
    .string "它是引出宝可梦潜能来进行攻击的招\n"
    .string "式。\p"
    .string "记住：它的属性和威力取决于使用它\n"
    .string "的宝可梦。$"

HiddenPowerGuy_Text_Meditating:
    .string "我正在冥想……$"
