ViridianCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY_HNS
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "常青道馆的馆主到底跑哪儿去了？我\n"
	.string "还想挑战他呢。$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "常青道馆里一个馆内训练家都没有。\p"
	.string "馆主自称他的方针是就算没有任何手\n"
	.string "下也照样能赢。$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "听说红莲岛的道馆已经没了。\p"
	.string "不知道馆主夏伯现在怎么样了。$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "我的梦想是成为一名道馆馆主。$"
