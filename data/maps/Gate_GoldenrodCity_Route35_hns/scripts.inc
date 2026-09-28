Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "打扰一下，小朋友！能不能帮大叔一\n"
	.string "个忙？\p"
	.string "可以帮我把这只带着邮件的宝可梦带\n"
	.string "给我朋友吗？\p"
	.string "他在31号道路。$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "愿意帮忙吗？太好了！谢谢你，小朋\n"
	.string "友！\p"
	.string "我那个朋友是个胖乎乎的家伙，整天\n"
	.string "都在打瞌睡。\p"
	.string "你一眼就能认出他来的！$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER}收下了带着邮件的\n"
	.string "宝可梦。$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "Make sure to put it at the front of\n"
	.string "your team when you find my friend!\p"
	.string "ROUTE 31!\p"
	.string "Oh, yeah. There was a weird tree\n"
	.string "blocking the road.\p"
	.string "I wonder if it's been cleared?$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "你无法携带更多的宝可梦了....\n"
	.string "..$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "这样啊......那就算了吧..\n"
	.string "....$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "谢谢你，小朋友！你帮我送到了啊！\p"
	.string "这是给你的谢礼！$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "我那哥们果然在睡觉吧？嘿嘿，我没\n"
	.string "说错吧？$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "有棵奇怪的树挡住了道路。\p"
	.string "对着它说话的话，它还会扭来扭去。\p"
	.string "听说有人用杰尼龟喷壶给它浇水后，\n"
	.string "它就发狂了。$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "我很喜欢收音机里放的宝可梦摇篮曲\n"
	.string "。$"

Route35GoldenrodGate_Text_Fisher:
	.string "不知道世界上到底有多少种宝可梦呢\n"
	.string "。\p"
	.string "3年前，大木博士说一共有150种\n"
	.string "。\p"
	.string "但最近我听说已经超过400种了！$"
