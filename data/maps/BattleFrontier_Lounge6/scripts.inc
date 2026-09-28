BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "我的宝可梦是\n"
	.string "{STR_VAR_2}，你知道它\l"
	.string "吗？它很可爱，很讨人喜欢。\p"
	.string "我可是很自豪有这么一只能与别人交\n"
	.string "换！\p"
	.string "你想用{STR_VAR_1}换我\n"
	.string "的{STR_VAR_2}吗？$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "哇，太可爱了！谢谢！我保证会好好\n"
	.string "照顾它的！\p"
	.string "啊，你也要好好照顾我的\n"
	.string "{STR_VAR_2}哦！$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "啊，抱歉！我只想换一只\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "哎，你不想换吗？唉，那就算了。下\n"
	.string "回再说吧。$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "嘻嘻！向尾喵比我想象中可爱多了！\n"
	.string "太高兴了！$"
