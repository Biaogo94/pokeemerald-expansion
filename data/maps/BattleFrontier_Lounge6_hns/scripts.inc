BattleFrontier_Lounge6_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader_hns::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted_hns
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns, BattleFrontier_Lounge6_EventScript_DeclineTrade_hns, BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade_hns::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted_hns::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns:
	.string "我的宝可梦是\n"
	.string "{STR_VAR_2}。你认识它\l"
	.string "吗？它长得可爱，性格也很乖巧。\p"
	.string "这小家伙，我可是能自豪地拿来交换\n"
	.string "的！\p"
	.string "你愿意用你的\n"
	.string "{STR_VAR_1}换我的\l"
	.string "{STR_VAR_2}吗？$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns:
	.string "哎呀，太招人喜欢了！谢谢你！我保\n"
	.string "证会好好待它的！\p"
	.string "对了！也希望你能善待我的\n"
	.string "{STR_VAR_2}哦！$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns:
	.string "啊，真遗憾！除了\n"
	.string "{STR_VAR_1}以外，我并\l"
	.string "不打算换别的宝可梦。$"

BattleFrontier_Lounge6_Text_WellThatsFineToo_hns:
	.string "啊，你不换吗？那也没关系。欢迎下\n"
	.string "次再来找我们玩。$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns:
	.string "嘻嘻！向尾喵比我想象中的还要可爱\n"
	.string "得多。我太开心了！$"
