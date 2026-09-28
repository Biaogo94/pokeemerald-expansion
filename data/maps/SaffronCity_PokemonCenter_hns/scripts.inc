SaffronCity_PokemonCenter_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY_HNS
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "城都的宝可梦中心是什么样子的？\p"
	.string "......哦，原来如此。跟关都\n"
	.string "的也没什么太大区别嘛。\p"
	.string "那我就能放心地去城都啦！$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "我刚好穿过岩山隧道过来。\p"
	.string "发电厂那边好像出了点骚乱呢。$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "华蓝市有个奇怪的洞窟。\p"
	.string "作为一名专业的登山男，我本该去探\n"
	.string "索的，但那个地方连我都觉得毛骨悚\l"
	.string "然。$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "西尔佛公司的总公司大楼和磁浮列车\n"
	.string "站--它们可是金黄市最值得一看的\l"
	.string "地方。$"
