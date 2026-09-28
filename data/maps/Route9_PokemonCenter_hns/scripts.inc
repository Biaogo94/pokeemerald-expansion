Route9_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route9_PokemonCenter_OnTransition::
	setflag FLAG_VISITED_ROUTE10
	setrespawn HEAL_LOCATION_ROUTE10_HNS
	end

Route9_PokemonCenter_EventScript_Engineer1::
	msgbox Route9_PokemonCenter_Text_Engineer1, MSGBOX_NPC
	end

Route9_PokemonCenter_EventScript_Engineer2::
	msgbox Route9_PokemonCenter_Text_Engineer2, MSGBOX_NPC
	end

Route9_PokemonCenter_Text_Engineer1:
	.string "我们工程师偶尔会来这里休息。其实\n"
	.string "就是为了躲开我们的厂长。\p"
	.string "那家伙简直是个工作狂。$"

Route9_PokemonCenter_Text_Engineer2:
	.string "发电厂的位置非常偏僻，所以我每天\n"
	.string "上班都要走很远的路。$"
