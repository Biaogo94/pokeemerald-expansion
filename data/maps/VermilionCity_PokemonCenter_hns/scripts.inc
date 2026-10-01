VermilionCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY_HNS
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "地鼠洞穴前趴着一只睡着的宝可梦。\p"
	.string "这可是收服它的绝好机会，但要怎么\n"
	.string "叫醒它呢？$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "之前地鼠洞穴前一直趴着一只睡着的\n"
	.string "宝可梦。\p"
	.string "不过现在好像不见了。$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "水手号可是结识训练家并展开对战的\n"
	.string "好地方。$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "哦？你戴着一些我从没见过的徽章\n"
	.string "呢。\p"
	.string "啊，我知道了。是在城都地区拿到的\n"
	.string "吧。$"
