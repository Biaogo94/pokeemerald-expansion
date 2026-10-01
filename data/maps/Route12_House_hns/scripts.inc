Route12_House_hns_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "我是钓鱼名人的弟弟。\p"
	.string "我一眼就能看出来，你很喜欢钓鱼。\p"
	.string "我对此深信不疑！\p"
	.string "怎么样？我没说错吧。$"

Route12_House_Text_GiveSuperRod:
	.string "对嘛对嘛！果然不出我所料！\p"
	.string "来，钓鱼迷！收下这个--这是厉害钓\n"
	.string "竿。$"

Route12_House_Text_GaveSuperRod:
	.string "只要是有水的地方，就去挥竿试试看\n"
	.string "吧。\p"
	.string "记住了--使用不同的钓竿，钓到的宝\n"
	.string "可梦也是不一样的哦。$"

Route12_House_Text_DontWantSuperRod:
	.string "咦？难道是我看走眼了？$"

