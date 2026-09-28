PewterCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY_HNS
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "...对啊，而且红莲岛的道馆也没\n"
	.string "了。\p"
	.string "我当时真是惊呆了。\p"
	.string "...嗯？我正在打电话呢。走开啦\n"
	.string "！$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "胖丁：波~波哩哩。$"

PewterCity_PokemonCenter_EventScript_Mondo::
	lock
	faceplayer
	goto_if_set FLAG_PEWTER_NPC_TRADE_COMPLETED, PewterCity_PokemonCenter_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HAUNTER, PewterCity_PokemonCenter_Text_WantToTrade, PewterCity_PokemonCenter_EventScript_DeclineTrade, PewterCity_PokemonCenter_EventScript_NotRequestedMon, PewterCity_PokemonCenter_Text_TakeCare
	setflag FLAG_PEWTER_NPC_TRADE_COMPLETED
	release
	end

PewterCity_PokemonCenter_EventScript_DeclineTrade::
	msgbox PewterCity_PokemonCenter_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_PokemonCenter_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_TradeCompleted::
	msgbox PewterCity_PokemonCenter_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_Text_WantToTrade:
	.string "我四处旅行，一直在寻找优秀的\n"
	.string "{STR_VAR_1}。\p"
	.string "你愿意用它来交换我的\n"
	.string "{STR_VAR_2}吗？$"

PewterCity_PokemonCenter_Text_TakeCare:
	.string "太感谢啦！要好好照顾我的\n"
	.string "{STR_VAR_1}哦！$"

PewterCity_PokemonCenter_Text_DeclineTrade:
	.string "不行吗？真遗憾......我觉得\n"
	.string "你应该会喜欢我的鬼斯通呢。$"

PewterCity_PokemonCenter_Text_NotRequestedMon:
	.string "唔，这不是{STR_VAR_1}\n"
	.string "啊。不是我要找的那种。$"

PewterCity_PokemonCenter_Text_TradeCompleted:
	.string "那只鬼斯通跟你相处得怎么样？它可\n"
	.string "是个不折不扣的淘气鬼呢！$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "大部分宝可梦听了胖丁的歌声都会犯\n"
	.string "困。\p"
	.string "有些招式只有在宝可梦睡着时才能使\n"
	.string "用哦。$"
