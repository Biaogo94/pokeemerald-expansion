LavenderTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN_HNS
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "紫苑镇的北边就是岩山隧道。穿过去\n"
	.string "就能到达发电厂了。$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "有个广播节目会播放宝可梦之笛的音\n"
	.string "乐。\p"
	.string "哦？啊，你的收音机需要扩展卡才能\n"
	.string "收听到那个频道。\p"
	.string "镇上的广播电台说不定能给你一张？$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "如果发电厂不运转，磁悬浮列车就跑\n"
	.string "不起来……\p"
	.string "而且广播电台也没法进行广播了。\n"
	.string ".....$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "广播电台的台长当时可高兴坏了。\p"
	.string "他说因为发电厂恢复正常运转，他们\n"
	.string "终于能重新开播了。$"
