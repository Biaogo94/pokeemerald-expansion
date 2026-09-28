PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "看看这个{STR_VAR_2}！\p"
	.string "是我昨天为庆祝自己的生日捉到的\n"
	.string "{STR_VAR_2}！\p"
	.string "啊，看来你想要它！毕竟，它是无可\n"
	.string "估价的！\p"
	.string "但你如果愿意用\n"
	.string "{STR_VAR_1}跟我换的话\l"
	.string "，我也可以考虑。$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "呀，这个是{STR_VAR_1}\n"
	.string "？\p"
	.string "虽然跟{STR_VAR_2}有点\n"
	.string "像，但它们还是有不同之处。\p"
	.string "谢谢！$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "不不不，除了真正的\n"
	.string "{STR_VAR_1}，我什么都\l"
	.string "不换！$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "哦？你不想考虑一下吗？\p"
	.string "也好，我也不是急着想交换的。$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "我知道我也能自己去找一只，但是…\n"
	.string "…\p"
	.string "我真的很想要一只其他训练家捕捉的\n"
	.string "宝贝龙……$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "那是宝可梦图鉴吗？\p"
	.string "你见过了很多不同的宝可梦了吗？\p"
	.string "我要是也能像你一样多好。$"

