VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "{PLAYER}，好久不见。\p"
	.string "空木博士让我来找你。\p"
	.string "他还有一件事想拜托你。\p"
	.string "你能收下这颗宝可梦的蛋吗？$"

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "{PLAYER}，好久不见。\p"
	.string "空木博士让我来找你。\p"
	.string "他还有一件事想拜托你。\p"
	.string "你能收下这颗宝可梦的蛋吗？\p"
	.string "啊，等等……你得先给同行的队伍腾出\n"
	.string "空位才行。$"

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "我们发现，宝可梦在蛋里成长成熟之\n"
	.string "前是不会孵化的。\p"
	.string "而且似乎还要和有活力的宝可梦呆在\n"
	.string "一起才会孵化出来。\p"
	.string "{PLAYER}，我们能依靠的就\n"
	.string "只有你了。$"

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "噢，还有这个，孵化的时候也许能派\n"
	.string "上用场。$"

VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "哎呀，糟糕。你已经带不下更多宝可\n"
	.string "梦了。\p"
	.string "你先去给蛋腾出个位置吧，我在这里\n"
	.string "等着你。$"

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
	.string "哎呀，你的同行宝可梦已经带不下了\n"
	.string "呢。\p"
	.string "别担心--我已经帮你把宝可梦蛋送到\n"
	.string "正辉的电脑里去了。$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "可、可是……空木博士有事找你……$"

VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "在宝可梦恢复体力的时候，我最喜欢\n"
	.string "读一本好书了。$"

VioletCity_PokeCenter_Text_MobileAdapter:
	.string "我刚刚通过联机和湛蓝市的朋友对战\n"
	.string "了一场。\p"
	.string "只要连接上移动适配器，就能和远方\n"
	.string "的朋友进行联机哦。$"

VioletCity_PokeCenter_Text_GameboyKid:
	.string "有个叫正辉的人开发了宝可梦电脑存\n"
	.string "储系统。$"

VioletCity_PokeCenter_Text_Gentleman:
	.string "那大概是三年前的事了。\p"
	.string "火箭队利用宝可梦到处作恶。\p"
	.string "但正义最终战胜了邪恶--一个年轻的\n"
	.string "少年把他们彻底瓦解了。$"

VioletCity_PokeCenter_Text_Youngster:
	.string "宝可梦可是很聪明的。它们不会听从\n"
	.string "自己不尊敬的训练家的指挥。\p"
	.string "要是没有相应的道馆徽章，它们就会\n"
	.string "自作主张、随心所欲。$"
