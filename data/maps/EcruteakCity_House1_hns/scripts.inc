EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "这是我年轻时发生的事了。\p"
	.string "天空突然变得一片漆黑。一只巨大的\n"
	.string "飞行宝可梦遮住了太阳。\p"
	.string "那究竟是什么宝可梦呢？\p"
	.string "它既像一只大鸟，又像一条巨龙。$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "真的有那么巨大的宝可梦吗？\p"
	.string "如果真有的话，那它一定非常强大。$"
