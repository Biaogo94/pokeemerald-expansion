CinnabarIsland_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_OnTransition
	.byte 0

CinnabarIsland_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND_HNS
	end

CinnabarIsland_PokemonCenter_EventScript_Cooltrainer::
	msgbox CinnabarIsland_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_EventScript_Fisher::
	msgbox CinnabarIsland_PokemonCenter1F_Text_Fisher, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter1F_Text_CooltrainerF:
	.string "听说红莲道馆的夏伯正一个人住在双\n"
	.string "子岛的洞窟里……$"

CinnabarIsland_PokemonCenter1F_Text_Fisher:
	.string "火山爆发已经过去一年了。$"
