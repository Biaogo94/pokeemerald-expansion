SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "经常来宝可梦中心的人，往往都把自\n"
	.string "己的宝可梦照顾得很好。\p"
	.string "你觉得是不是这样？$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "在山路上走了好久，累得快要倒下时\n"
	.string "，终于找到了宝可梦中心……\l"
	.string ".\p"
	.string "那感觉就像来到了天堂一样！$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "狩猎、狩猎，真好玩~~狩猎、狩猎\n"
	.string "，真有趣呀~~\p"
	.string "好多宝可梦都在等着我们！\p"
	.string "……这是我自己编的歌。来\n"
	.string "狩猎地带的时候我就会唱呢。$"
