EcruteakCity_Mart_hns_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "我的伊布进化成了太阳伊布。\p"
	.string "但我朋友的伊布却进化成了月亮伊布\n"
	.string "。\p"
	.string "这是为什么呢？我们培育伊布的方法\n"
	.string "明明是一样的呀……$"

EcruteakMart_Text_Granny:
	.string "如果使用活力碎片，陷入濒死的宝可\n"
	.string "梦就能立刻清醒过来。$"
