BlackthornCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "在遥远的石英高原深处，坐落着宝可\n"
	.string "梦联盟。\p"
	.string "听说全国顶尖的训练家都会聚集在那\n"
	.string "里。$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "我有一招无论如何都想让宝可梦学会\n"
	.string "的招式。\p"
	.string "所以我去找了招式遗忘狂，让宝可梦\n"
	.string "把秘传学习器的招式忘掉了。$"
