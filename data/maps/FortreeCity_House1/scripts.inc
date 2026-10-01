FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PLUSLE, FortreeCity_House1_Text_YouWillTradeWontYou, FortreeCity_House1_EventScript_DeclineTrade, FortreeCity_House1_EventScript_NotRequestedMon, FortreeCity_House1_Text_MonYouTakeCare
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "唔啊啊啊！我想要！我想要只\n"
	.string "{STR_VAR_1}！我会拼尽\l"
	.string "全力找到它的！\p"
	.string "……呃……被你听到了吗？被你听到了我\n"
	.string "那发自内心的呼喊？\p"
	.string "既然听见了，就用\n"
	.string "{STR_VAR_1}来换我的\l"
	.string "{STR_VAR_2}吧，好吗？$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "哦，耶，对！\p"
	.string "欢迎，{STR_VAR_1}！你\n"
	.string "要照顾好{STR_VAR_2}！$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "呃，不，我想这不是\n"
	.string "{STR_VAR_1}。$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "不？你不跟我换？即使你看到了我的\n"
	.string "真心也不肯换？$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "从现在开始，我要把甜甜萤养得壮壮\n"
	.string "的！\p"
	.string "你也要善待正电拍拍啊！$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "和别人交换宝可梦……\p"
	.string "就像跟别人交换自己的记忆一样。$"

FortreeCity_House1_Text_Zigzagoon:
	.string "蛇纹熊：咕莫莫？$"

