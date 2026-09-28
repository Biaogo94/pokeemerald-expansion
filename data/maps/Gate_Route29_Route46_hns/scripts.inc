Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "高台是爬不上去的。\p"
	.string "但可以从上面跳下来抄近道哦。$"

Gate_Route29_Route46_Text_Youngster:
	.string "穿过这里后，会出现各种各样不同的\n"
	.string "宝可梦。\p"
	.string "要是想全部捉齐，就必须到处仔细找\n"
	.string "找才行。$"
