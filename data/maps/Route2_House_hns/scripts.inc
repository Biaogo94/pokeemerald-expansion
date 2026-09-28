Route2_House_hns_MapScripts::
	.byte 0

Route2_House_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROUTE2_NUGGET, Route2_House_EventScript_ManAfter
	msgbox Route2_House_Text_Fisher, MSGBOX_DEFAULT 
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_ROUTE2_NUGGET
	release
	end

Route2_House_EventScript_ManAfter::
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_House_Text_Fisher:
	.string "你好！哇，见到你真高兴。\p"
	.string "你可是好久以来第一个造访的客人呢\n"
	.string "。\p"
	.string "我真是太高兴了！送你一份小礼物吧\n"
	.string "。$"

Route2_House_Text_Fisher_GotNugget:
	.string "那是一颗金珠。\p"
	.string "虽然我没法给你什么金玉良言，但这\n"
	.string "个应该也足够了吧！$"
