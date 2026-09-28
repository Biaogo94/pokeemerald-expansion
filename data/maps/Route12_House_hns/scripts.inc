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
	.string "Yes, yes. Just as I thought!\p"
	.string "Here, fishing fan! Take this--\n"
	.string "it's a SUPER ROD.$"

Route12_House_Text_GaveSuperRod:
	.string "Try your hand at fishing wherever\n"
	.string "there is water.\p"
	.string "Remember--you can catch different\n"
	.string "POKéMON using different RODS.$"

Route12_House_Text_DontWantSuperRod:
	.string "咦？难道是我看走眼了？$"

