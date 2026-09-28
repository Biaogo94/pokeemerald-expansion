AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "你的宝可梦学会秘传招式了吗？\p"
	.string "即使宝可梦陷入了濒死状态，也可以\n"
	.string "使用那些招式哦。$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "那个叫正辉的人开发了在电脑里寄放\n"
	.string "宝可梦的系统。\p"
	.string "正辉的电脑里，每个盒子最多可以存\n"
	.string "30只宝可梦。$"

AzaleaPokecenter_Text_FishingGuru:
	.string "正辉的电脑里，每个盒子最多可以存\n"
	.string "30只宝可梦。$"

AzaleaPokecenter_Text_PokefanF:
	.string "你知道树果吗？\p"
	.string "把它敲开，掏空果肉，再装上特殊的\n"
	.string "装置，\p"
	.string "就能用它来捉宝可梦了。\p"
	.string "在精灵球发明出来之前，大家都是用\n"
	.string "树果的。$"
