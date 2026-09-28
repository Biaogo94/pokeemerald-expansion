MahoganyTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "怎么回事？火箭队卷土重来了？\p"
    .string "我在愤怒之湖看到了几个黑衣人..\n"
    .string "....$"

MahoganyTown_PokemonCenter_Text_Youngster:
    .string "我不会让我的宝可梦太早进化。\p"
    .string "我会让它们先学会某些招式，然后再\n"
    .string "让它们进化。$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "宝可梦进化后确实会变强，\p"
    .string "但学习新招式的速度也会变慢。$"
