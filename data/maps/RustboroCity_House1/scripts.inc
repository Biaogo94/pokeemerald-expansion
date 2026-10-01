RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SEEDOT, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "嗯？我的宝可梦很可爱？那是当然\n"
	.string "的。\p"
	.string "但你如果真的想要，我也可以考虑跟\n"
	.string "你交换。\p"
	.string "愿意的话，我用我的\n"
	.string "{STR_VAR_2}跟你换\l"
	.string "{STR_VAR_1}。$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "呵呵呵……要善待我的宝可梦啊。$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "嗯？这看上去可不是\n"
	.string "{STR_VAR_1}。$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "啊，如果你不想换也不要紧，但你知\n"
	.string "道，我的宝可梦非常可爱……$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "如果用爱心和细心去照顾宝可梦，它\n"
	.string "们都会变得十分可爱。$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "在不同地方生活着不同的人和不同的\n"
	.string "宝可梦，\p"
	.string "我觉得很有趣，所以四处旅行。$"

