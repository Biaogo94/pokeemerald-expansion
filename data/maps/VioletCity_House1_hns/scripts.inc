VioletCity_House1_hns_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_EventScript_Rudy::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_ONIX, VioletCity_House1_Text_YouWillTradeWontYou, VioletCity_House1_EventScript_DeclineTrade, VioletCity_House1_EventScript_NotRequestedMon, VioletCity_House1_Text_MonYouTakeCare
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	release
	end

VioletCity_House1_EventScript_DeclineTrade::
	msgbox VioletCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VioletCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_TradeCompleted::
	msgbox VioletCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_Text_YouWillTradeWontYou:
	.string "我正在收集宝可梦！你有\n"
	.string "{STR_VAR_1}吗？\p"
	.string "想用它来交换我的\n"
	.string "{STR_VAR_2}吗？$"

VioletCity_House1_Text_MonYouTakeCare:
	.string "太好啦！我得到\n"
	.string "{STR_VAR_1}了！\p"
	.string "{STR_VAR_2}，你要保重\n"
	.string "哦！$"

VioletCity_House1_Text_ThisIsntAMon:
	.string "呃，不对吧。这并不是\n"
	.string "{STR_VAR_1}啊。$"

VioletCity_House1_Text_YouWontTradeMe:
	.string "不想交换吗？好吧……$"

VioletCity_House1_Text_After:
	.string "嗨，之前换给你的大岩蛇过得怎么样\n"
	.string "？$"

VioletCity_House1_Text_PokefanM:
	.string "通过交换得到的宝可梦成长得非常快\n"
	.string "。\p"
	.string "但要是没有对应的道馆徽章，它们可\n"
	.string "能就不会听话哦。$"
