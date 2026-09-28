Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "沿着那条路一直往北走，就能看到宝\n"
	.string "可梦爷爷的家了。\p"
	.string "不过在去之前，先让我给你讲讲树果\n"
	.string "的事吧！\p"
	.string "宝可梦吃下树果就会变得更有精神。\p"
	.string "它们在对战中甚至可以自己吃下身上\n"
	.string "携带的树果哦。\p"
	.string "桧皮镇的钢铁先生还可以把树果做成\n"
	.string "精灵球呢。\p"
	.string "来，这个分你一个吧！$"

Route30_BerryHouse_Text_CheckTrees:
	.string "多调查调查果树上的树果吧。过几个\n"
	.string "小时它们就会重新长出来的。$"
