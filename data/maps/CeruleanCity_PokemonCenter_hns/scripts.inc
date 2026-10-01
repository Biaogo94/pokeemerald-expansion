CeruleanCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY_HNS
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "要是进行对战，我更想用自己一直精\n"
	.string "心培育的宝可梦，\p"
	.string "即使它们可能比新抓到的宝可梦要弱\n"
	.string "一些。$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "磁悬浮列车的时速超过550公里。转\n"
	.string "瞬之间就能穿梭于关都与城都之间。\p"
	.string "去城都真的变得非常方便呢。$"
