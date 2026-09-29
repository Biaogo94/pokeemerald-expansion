OlivineCity_House1_hns_MapScripts::
	.byte 0

OlivineCity_House1_EventScript_Tim::
	lock
	faceplayer
	goto_if_set FLAG_OLIVINE_NPC_TRADE_COMPLETED, OlivineCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_VOLTORB, OlivineCity_House1_Text_YouWillTradeWontYou, OlivineCity_House1_EventScript_DeclineTrade, OlivineCity_House1_EventScript_NotRequestedMon, OlivineCity_House1_Text_MonYouTakeCare
	setflag FLAG_OLIVINE_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_House1_EventScript_DeclineTrade::
	msgbox OlivineCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox OlivineCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_TradeCompleted::
	msgbox OlivineCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_Text_YouWillTradeWontYou:
	.string "我正在收集宝可梦！你有\n"
	.string "{STR_VAR_1}吗？\p"
	.string "想用它来交换我的\n"
	.string "{STR_VAR_2}吗？$"

OlivineCity_House1_Text_MonYouTakeCare:
	.string "太好啦！我得到\n"
	.string "{STR_VAR_1}了！\p"
	.string "{STR_VAR_2}，你要保重\n"
	.string "哦！$"

OlivineCity_House1_Text_ThisIsntAMon:
	.string "呃，不对吧。这并不是\n"
	.string "{STR_VAR_1}啊。$"

OlivineCity_House1_Text_YouWontTradeMe:
	.string "不想交换吗？好吧……$"

OlivineCity_House1_Text_After:
	.string "嗨，我以前的那只霹雳电球过得怎么\n"
	.string "样啦？$"
