LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "如果训练家和宝可梦经常在一起，他\n"
	.string "们会变得更加亲密的，\p"
	.string "而且越久越好。我是这么想的。$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "在温泉中坐一会儿就会再次充满活力\n"
	.string "，好像魔术一样。\p"
	.string "如果能让宝可梦也泡泡多好。$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "呵呵呵！喂，孩子，你可以从这里进\n"
	.string "入温泉。\p"
	.string "宝可梦休息的时候，训练家也该放松\n"
	.string "一下。$"

