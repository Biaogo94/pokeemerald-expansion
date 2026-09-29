Melemele_House_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Melemele_House_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Melemele_House_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MELEMELE_ISLE_HNS
	end


Alola_Melemele_Pokecenter_EventScript_Swimmer::
	lock
	faceplayer
	msgbox Alola_Melemele_Pokecenter_Text_Swimmer, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_MELEMELE_POKEMONCENTER_SWIMMER, DIR_NORTH
	release
	end

Alola_Melemele_Pokecenter_Text_Swimmer:
	.string "哎呀，这些岛屿真是让人分不清！\p"
	.string "我总是会把它们搞混！\p"
	.string "多亏有这张地图在！$"

Alola_Melemele_Pokecenter_Map::
	lockall
	setvar VAR_0x8000, 0 @ SCREENSHOT_ALOLA_MAP
	msgbox Alola_Melemele_Pokecenter_Map_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

Alola_Melemele_Pokecenter_AceTrainer::
	lock
	faceplayer
	msgbox Alola_Melemele_Pokecenter_AceTrainer_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_Pokecenter_BugCatcher::
	lock
	faceplayer
	msgbox Alola_Melemele_Pokecenter_BugCatcher_Text_0, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement Melemele_PokecenterGrubbin, Alola_Melemele_Pokecenter_BugCatcher_Movement_0
	waitmovement 0
	waitse
	playmoncry SPECIES_RATTATA, 0
	waitmoncry
	release
	end


Alola_Melemele_Pokecenter_Grubbin::
	lock
	faceplayer
	playmoncry SPECIES_RATTATA, 0
	msgbox Alola_Melemele_Pokecenter_Grubbin_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end


Alola_Melemele_Pokecenter_BugCatcher_Movement_0:
	face_up
	emote_exclamation_mark
	step_end

Alola_Melemele_Pokecenter_AceTrainer_Text_0:
	.string "这里有好多特别的宝可梦！我要把它\n"
	.string "们全部收服！$"

Alola_Melemele_Pokecenter_BugCatcher_Text_0:
	.string "我在群岛上发现了一些全新的宝可梦\n"
	.string "！\p"
	.string "比如我的新朋友--这只小拉达！$"

Alola_Melemele_Pokecenter_Grubbin_Text_0:
	.string "咕噜噜！$"


@ Jessica's Paldean Tauros trade. Which Tauros she offers depends on the
@ player's starter, so the trade always covers one of its weaknesses:
@ Cyndaquil -> Aqua, Totodile -> Blaze, Chikorita -> Combat.
Alola_Melemele_Pokecenter_Jessica::
	lock
	faceplayer
	goto_if_set FLAG_COMPLETED_TAUROS_TRADE, Alola_Melemele_Pokecenter_Jessica_TradeCompleted
	goto_if_eq VAR_STARTER_MON, 0, Alola_Melemele_Pokecenter_Jessica_TradeWater
	goto_if_eq VAR_STARTER_MON, 1, Alola_Melemele_Pokecenter_Jessica_TradeFire
	goto Alola_Melemele_Pokecenter_Jessica_TradeFight
	end

Alola_Melemele_Pokecenter_Jessica_TradeWater::
	setvar VAR_0x8005, INGAME_TRADE_TAUROS_WATER
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_WantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Alola_Melemele_Pokecenter_Jessica_DeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Alola_Melemele_Pokecenter_Jessica_DeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_TakeCare, MSGBOX_DEFAULT
	setflag FLAG_COMPLETED_TAUROS_TRADE
	release
	end

Alola_Melemele_Pokecenter_Jessica_TradeFight::
	setvar VAR_0x8005, INGAME_TRADE_TAUROS_FIGHT
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_WantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Alola_Melemele_Pokecenter_Jessica_DeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Alola_Melemele_Pokecenter_Jessica_DeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_TakeCare, MSGBOX_DEFAULT
	setflag FLAG_COMPLETED_TAUROS_TRADE
	release
	end

Alola_Melemele_Pokecenter_Jessica_TradeFire::
	setvar VAR_0x8005, INGAME_TRADE_TAUROS_FIRE
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_WantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Alola_Melemele_Pokecenter_Jessica_DeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Alola_Melemele_Pokecenter_Jessica_DeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_TakeCare, MSGBOX_DEFAULT
	setflag FLAG_COMPLETED_TAUROS_TRADE
	release
	end

Alola_Melemele_Pokecenter_Jessica_DeclineTrade::
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Alola_Melemele_Pokecenter_Jessica_TradeCompleted::
	msgbox Alola_Melemele_Pokecenter_Jessica_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

Alola_Melemele_Pokecenter_Jessica_Text_WantToTrade:
	.string "这里的{STR_VAR_2}和大\n"
	.string "陆上的不大一样。\p"
	.string "想拿你的宝可梦来换我的\n"
	.string "{STR_VAR_2}吗？$"

Alola_Melemele_Pokecenter_Jessica_Text_TakeCare:
	.string "谢谢你！托里，你要多保重啊！$"

Alola_Melemele_Pokecenter_Jessica_Text_DeclineTrade:
	.string "不想交换吗？好吧……$"

Alola_Melemele_Pokecenter_Jessica_Text_TradeCompleted:
	.string "嗨，我的老托里过得怎么样？$"

Alola_Melemele_Pokecenter_Map_Text_0:
	.string "{PLAYER}仔细查看了阿罗拉\n"
	.string "群岛的地图。$"
