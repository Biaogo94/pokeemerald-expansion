ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
	.string "接待员告诉我。\p"
	.string "可以随便使用角落里的电脑。她真是\n"
	.string "太和蔼了！$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
	.string "每一个镇都有宝可梦中心。\p"
	.string "并且都是免费的，所以不要不好意思\n"
	.string "去治疗你的宝可梦。$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
	.string "宝可梦中心能治愈你的受伤的，或者\n"
	.string "濒死的宝可梦。\p"
	.string "他们能使你的宝可梦完全恢复健康。$"

