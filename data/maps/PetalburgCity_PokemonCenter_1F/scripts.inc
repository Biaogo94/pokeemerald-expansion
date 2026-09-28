PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "电脑上的宝可梦寄放系统……\p"
	.string "无论是谁发明的，那人一定是个科学\n"
	.string "奇人！$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "我的宝可梦吃了蓝橘果后，它的体力\n"
	.string "就恢复了！$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "宝可梦分为很多属性。\p"
	.string "每种属性对其他属性都有不同的优势\n"
	.string "和弱点。\p"
	.string "由于宝可梦属性的不同，战斗可能会\n"
	.string "变得更加容易或棘手。$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "比如，你的木守宫是草属性。\p"
	.string "它对水属性和地面属性时占有优势，\p"
	.string "但对火属性宝可梦时则处于劣势。$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "比如，你的火稚鸡是火属性。\p"
	.string "它对草属性和虫属性时占有优势，\p"
	.string "但对水属性宝可梦时则处于劣势。$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "比如，你的水跃鱼是水属性。\p"
	.string "它对火属性时占有优势，\p"
	.string "但对草属性和电属性宝可梦时则处于\n"
	.string "劣势。$"

