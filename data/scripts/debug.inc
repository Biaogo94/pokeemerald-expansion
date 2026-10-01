Debug_MessageEnd:
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	goto Debug_MessageEnd

Debug_CheatStart::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	release
	end

Debug_CheatStartFrlg::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
	setflag FLAG_OPENED_START_MENU
	setflag FLAG_VISITED_OAKS_LAB
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
	givemon SPECIES_BULBASAUR, 20, ITEM_NONE
	givemon SPECIES_CHARMANDER, 20, ITEM_NONE
	givemon SPECIES_SQUIRTLE, 20, ITEM_NONE
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	setflag FLAG_HIDE_RIVAL_IN_LAB
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1 @ prevents Oak scene when trying to enter Route 1
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6 @ state after handing in parcel and getting pokedex
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
	setvar VAR_MAP_SCENE_ROUTE22, 1
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1 @ end
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_SYS_B_DASH
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_GOT_BIKE_VOUCHER
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	setflag FLAG_WORLD_MAP_PALLET_TOWN
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	setflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_CERULEAN_CITY
	setflag FLAG_WORLD_MAP_VERMILION_CITY
	setflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setflag FLAG_WORLD_MAP_CELADON_CITY
	setflag FLAG_WORLD_MAP_FUCHSIA_CITY
	setflag FLAG_WORLD_MAP_SAFFRON_CITY
	setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	setflag FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR
	setflag FLAG_WORLD_MAP_ONE_ISLAND
	setflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_WORLD_MAP_THREE_ISLAND
	setflag FLAG_WORLD_MAP_FOUR_ISLAND
	setflag FLAG_WORLD_MAP_FIVE_ISLAND
	setflag FLAG_WORLD_MAP_SIX_ISLAND
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND
	release
	end

Debug_FlagsNotSetOverworldConfigMessage::
	message Debug_FlagsNotSetOverworldConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetOverworldConfigMessage_Text:
	.string "功能不可用！\n"
	.string "请在这里定义该标志：\l"
	.string "'include/config/overworld.h'！$"

Debug_FlagsNotSetBattleConfigMessage::
	message Debug_FlagsNotSetBattleConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetBattleConfigMessage_Text:
	.string "功能不可用！\n"
	.string "请在这里定义一个可用标志：\l"
	.string "'include/config/battle.h'！$"

Debug_VarsNotSetBattleConfigMessage::
	message Debug_VarsNotSetBattleConfigMessage_Text
	goto Debug_MessageEnd

Debug_VarsNotSetBattleConfigMessage_Text:
	.string "Feature unavailable!\n"
	.string "Please define a usable var in:\l"
	.string "'include/config/battle.h'!$"

Debug_BoxFilledMessage::
	message Debug_BoxFilledMessage_Text
	goto Debug_MessageEnd

Debug_BoxFilledMessage_Text:
	.string "盒子已满！$"

Debug_EventScript_CheckEVs::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckEVs_End
	callnative Script_GetChosenMonOffensiveEVs
	msgbox Debug_EventScript_Text_OffensiveEVs, MSGBOX_DEFAULT
	callnative Script_GetChosenMonDefensiveEVs
	msgbox Debug_EventScript_Text_DefensiveEVs, MSGBOX_DEFAULT
Debug_EventScript_CheckEVs_End::
	releaseall
	end

Debug_EventScript_Text_OffensiveEVs:
	.string "ATK EVs: {STR_VAR_1}, SPATK EVs: {STR_VAR_2}, SPEED EVs: {STR_VAR_3}$"

Debug_EventScript_Text_DefensiveEVs:
	.string "HP EVs: {STR_VAR_1}, DEF EVs: {STR_VAR_2}, SPDEF EVs: {STR_VAR_3}$"

Debug_EventScript_CheckIVs::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckIVs_End
	callnative Script_GetChosenMonOffensiveIVs
	msgbox Debug_EventScript_Text_OffensiveIVs, MSGBOX_DEFAULT
	callnative Script_GetChosenMonDefensiveIVs
	msgbox Debug_EventScript_Text_DefensiveIVs, MSGBOX_DEFAULT
Debug_EventScript_CheckIVs_End::
	releaseall
	end

Debug_EventScript_Text_OffensiveIVs:
	.string "ATK IVs: {STR_VAR_1}, SPATK IVs: {STR_VAR_2}, SPEED IVs: {STR_VAR_3}$"

Debug_EventScript_Text_DefensiveIVs:
	.string "HP IVs: {STR_VAR_1}, DEF IVs: {STR_VAR_2}, SPDEF IVs: {STR_VAR_3}$"

Debug_EventScript_Script_1::
	goto UnionCave_B2F_EventScript_Lapras
	release
	end

Debug_Text_1:
	.string "{STR_VAR_1}$"


Debug_EventScript_Script_2::
	finditem ITEM_POTION
	giveitem ITEM_SUPER_POTION
	release
	end

Debug_EventScript_Script_3::
	goto SinjohRuins_EventScript_StevenBattle
	release
	end

Debug_EventScript_Script_4::
	msgbox SinjohRuins_Lab_Text_StevenCall3Plates, MSGBOX_DEFAULT
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	release
	end

Debug_EventScript_Script_5::
	special InitKantoRoamers
	release
	end

Debug_EventScript_Script_6::
	lockall
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_settrainers
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, FRONTIER_TRAINER_LEADER_BROCK_HNS
	special HealPlayerParty
	dofacilitytrainerbattle FACILITY_BATTLE_TOWER
	waitstate
	special HealPlayerParty
	releaseall
	end

Debug_EventScript_Script_7::
	release
	end

Debug_EventScript_Script_8::
	release
	end

Debug_EventScript_Lance_Multi::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, Debug_EventScript_DoLanceMultiBattle
	special LoadPlayerParty
	release
	end

Debug_EventScript_DoLanceMultiBattle::
	multi_2_vs_2 TRAINER_ARIANA_1_HNS, Debug_Text_ArianaDefeat, TRAINER_GRUNT_23_HNS, Debug_Text_Grunt23Defeat, PARTNER_LANCE_HNS
	switch VAR_RESULT
	case 1, Debug_EventScript_LanceMultiWin
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Debug_EventScript_LanceMultiWin::
	msgbox Debug_Text_LanceMultiVictory, MSGBOX_DEFAULT
	release
	end

Debug_Text_ArianaDefeat:
	.string "You haven't seen the last of me!$"

Debug_Text_Grunt23Defeat:
	.string "I won't accept this!$"

Debug_Text_LanceMultiVictory:
	.string "Lance multi battle complete!$"

Debug_EventScript_Silver_Multi::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, Debug_EventScript_PickSilverPartner
	special LoadPlayerParty
	release
	end

Debug_EventScript_PickSilverPartner::
	switch VAR_STARTER_MON
	case 0, Debug_EventScript_DoSilverMulti_Typhlosion
	case 1, Debug_EventScript_DoSilverMulti_Feraligatr
	case 2, Debug_EventScript_DoSilverMulti_Meganium
	goto Debug_EventScript_DoSilverMulti_Typhlosion

Debug_EventScript_DoSilverMulti_Typhlosion::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, Debug_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, Debug_Text_Clair3Defeat, PARTNER_SILVER_TYPHLOSION_HNS
	goto Debug_EventScript_SilverMultiResult

Debug_EventScript_DoSilverMulti_Feraligatr::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, Debug_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, Debug_Text_Clair3Defeat, PARTNER_SILVER_FERALIGATR_HNS
	goto Debug_EventScript_SilverMultiResult

Debug_EventScript_DoSilverMulti_Meganium::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, Debug_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, Debug_Text_Clair3Defeat, PARTNER_SILVER_MEGANIUM_HNS
	goto Debug_EventScript_SilverMultiResult

Debug_EventScript_SilverMultiResult::
	switch VAR_RESULT
	case 1, Debug_EventScript_SilverMultiWin
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Debug_EventScript_SilverMultiWin::
	msgbox Debug_Text_SilverMultiVictory, MSGBOX_DEFAULT
	release
	end

Debug_Text_SilverMultiVictory:
	.string "Silver multi battle complete!$"

Debug_Text_Lance3Defeat:
	.string "You haven't seen the last of me!$"

Debug_Text_Clair3Defeat:
	.string "I won't accept this!$"

Debug_CheckSaveBlock::
	callnative CheckSaveBlock1Size
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock2Size
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock3Size
	msgbox Debug_SaveBlock3Size, MSGBOX_DEFAULT
	callnative CheckPokemonStorageSize
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
	release
	end

Debug_SaveBlock1Size::
	.string "SaveBlock1 大小：{STR_VAR_1}b/{STR_VAR_2}b。\n"
	.string "剩余空间：{STR_VAR_3}b。$"

Debug_SaveBlock2Size::
	.string "SaveBlock2 大小：{STR_VAR_1}b/{STR_VAR_2}b。\n"
	.string "剩余空间：{STR_VAR_3}b。$"

Debug_SaveBlock3Size::
	.string "SaveBlock3 大小：{STR_VAR_1}b/{STR_VAR_2}b。\n"
	.string "剩余空间：{STR_VAR_3}b。$"

Debug_PokemonStorageSize::
	.string "{PKMN}Storage size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
	.string "Free space: {STR_VAR_3}b.$"

Debug_CheckROMSpace::
	callnative CheckROMSize
	msgbox Debug_ROMSize, MSGBOX_DEFAULT
	release
	end

Debug_ROMSize::
	.string "ROM 大小：{STR_VAR_1}MB/32MB。\n"
	.string "剩余空间：{STR_VAR_2}MB。$"

Debug_HatchAnEgg::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_HatchAnEgg_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_ne VAR_RESULT, SPECIES_EGG, DebugScript_HatchAnEgg_CantForceHatch
	special EggHatch
	waitstate
Debug_HatchAnEgg_End::
	releaseall
	end

Debug_NoPokemon::
	msgbox DebugScript_Text_EmptyParty, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_HatchAnEgg_CantForceHatch::
	msgbox DebugScript_HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_Text_EmptyParty::
	.string "你既没有宝可梦也没有宝可梦的蛋。$"

DebugScript_HatchAnEgg_Text_NotAnEgg::
	.string "那不是宝可梦的蛋。$"

DebugScript_ZeroDaycareMons::
	msgbox DebugText_DaycareNoPokemon, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_OneDaycareMons::
	msgbox DebugText_DaycareOnePokemon, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_DaycareMonsNotCompatible::
	msgbox DebugText_DaycarePokemonNotCompatible, MSGBOX_DEFAULT
	releaseall
	end

DebugText_DaycareNoPokemon:
	.string "你没有在培育屋的宝可梦。$"

DebugText_DaycareOnePokemon:
	.string "你仅有一个在培育屋的宝可梦。$"

DebugText_DaycarePokemonNotCompatible:
	.string "你在培育屋的宝可梦\n"
	.string "不能生育幼年宝可梦！$"

Debug_ShowExpansionVersion::
	callnative BufferExpansionVersion
	msgbox Debug_ExpansionVersion, MSGBOX_DEFAULT
	release
	end

Debug_ExpansionVersion:
	.string "pokeemerald-expansion {STR_VAR_1}$"

Debug_Follower_NPC_Not_Enabled::
	msgbox Debug_Enable_To_Use_Follower_NPCs, MSGBOX_DEFAULT
	release
	end

Debug_Enable_To_Use_Follower_NPCs:
	.string "Feature unavailable.\nSet FNPC_ENABLE_NPC_FOLLOWERS toTRUE in 'include/config/follower_npc.h'.$"

Debug_Follower_NPC_Event_Script::
	lock
	facefollowernpc
	msgbox Debug_Follower_NPC_Test_Message, MSGBOX_DEFAULT
	releaseall
	end

Debug_Follower_NPC_Test_Message:
	.string "This is a Follower NPC test.$"

Debug_EventScript_Steven_Multi::
	call MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	release
	end

Debug_EventScript_WallyTutorial::
	special SavePlayerParty
	special LoadWallyZigzagoon
	special StartWallyTutorialBattle
	waitstate
	special LoadPlayerParty
	release
	end

Debug_BerryPestsDisabled::
	msgbox DebugText_BerryPestsDisabled, MSGBOX_DEFAULT
	release
	end

DebugText_BerryPestsDisabled:
	.string "OW_BERRY_PESTS未开启。\n"
	.string "无法在果树上强制添加害虫。$"

Debug_BerryWeedsDisabled::
	msgbox DebugText_BerryWeedsDisabled, MSGBOX_DEFAULT
	release
	end

DebugText_BerryWeedsDisabled:
	.string "OW_BERRY_WEEDS is disabled.\n"
	.string "Unable to force weeds onto berry trees.$"

Debug_EventScript_InflictStatus1::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Single
	case 1, Debug_EventScript_InflictStatus1_Party
	case 2, Debug_EventScript_InflictStatus1_Close
Debug_EventScript_InflictStatus1_Close:
	releaseall
	end

Debug_EventScript_InflictStatus1_Single:
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Single_Poison
	case 1, Debug_EventScript_InflictStatus1_Single_Paralysis
	case 2, Debug_EventScript_InflictStatus1_Single_Sleep
	case 3, Debug_EventScript_InflictStatus1_Single_Burn
	case 4, Debug_EventScript_InflictStatus1_Single_Freeze
	case 5, Debug_EventScript_InflictStatus1_Single_Frostbite
	case 6, Debug_EventScript_InflictStatus1_Close
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	releaseall
	end

Debug_EventScript_KoPokemon::
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	setko VAR_0x8004
	releaseall
	end

Debug_EventScript_SetHiddenNature::
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	dynmultipush Debug_EventScript_ChangeNature_Text_Hardy, 0
	dynmultipush Debug_EventScript_ChangeNature_Text_Lonely, 1
	dynmultipush Debug_EventScript_ChangeNature_Text_Brave, 2
	dynmultipush Debug_EventScript_ChangeNature_Text_Adamant, 3
	dynmultipush Debug_EventScript_ChangeNature_Text_Naughty, 4
	dynmultipush Debug_EventScript_ChangeNature_Text_Bold, 5
	dynmultipush Debug_EventScript_ChangeNature_Text_Docile, 6
	dynmultipush Debug_EventScript_ChangeNature_Text_Relaxed, 7
	dynmultipush Debug_EventScript_ChangeNature_Text_Impish, 8
	dynmultipush Debug_EventScript_ChangeNature_Text_Lax, 9
	dynmultipush Debug_EventScript_ChangeNature_Text_Timid, 10
	dynmultipush Debug_EventScript_ChangeNature_Text_Hasty, 11
	dynmultipush Debug_EventScript_ChangeNature_Text_Serious, 12
	dynmultipush Debug_EventScript_ChangeNature_Text_Jolly, 13
	dynmultipush Debug_EventScript_ChangeNature_Text_Naive, 14
	dynmultipush Debug_EventScript_ChangeNature_Text_Modest, 15
	dynmultipush Debug_EventScript_ChangeNature_Text_Mild, 16
	dynmultipush Debug_EventScript_ChangeNature_Text_Quiet, 17
	dynmultipush Debug_EventScript_ChangeNature_Text_Bashful, 18
	dynmultipush Debug_EventScript_ChangeNature_Text_Rash, 19
	dynmultipush Debug_EventScript_ChangeNature_Text_Calm, 20
	dynmultipush Debug_EventScript_ChangeNature_Text_Gentle, 21
	dynmultipush Debug_EventScript_ChangeNature_Text_Sassy, 22
	dynmultipush Debug_EventScript_ChangeNature_Text_Careful, 23
	dynmultipush Debug_EventScript_ChangeNature_Text_Quirky, 24
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	special SetHiddenNature
	releaseall
	end

Debug_EventScript_SetAbility::
	special ChoosePartyMon
	waitstate
	callnative DebugNative_GetAbilityNames
	dynmultipush gStringVar1, 0
	dynmultipush gStringVar2, 1
	dynmultipush gStringVar3, 2
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, Debug_EventScript_SetAbilityClose
	special SetAbility
Debug_EventScript_SetAbilityClose:
	releaseall
	end

Debug_EventScript_SetFriendship::
	special ChoosePartyMon
	waitstate
	callnative DebugNative_Party_SetFriendship
	releaseall
	end

Debug_EventScript_GivePokerus::
	special ChoosePartyMon
	waitstate
	callnative DebugNative_Party_SetPokerus
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Poison:
	setstatus1 STATUS1_POISON, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Paralysis:
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Sleep:
	setstatus1 STATUS1_SLEEP, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Burn:
	setstatus1 STATUS1_BURN, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Freeze:
	setstatus1 STATUS1_FREEZE, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Frostbite:
	setstatus1 STATUS1_FROSTBITE, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Party:
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Party_Poison
	case 1, Debug_EventScript_InflictStatus1_Party_Paralysis
	case 2, Debug_EventScript_InflictStatus1_Party_Sleep
	case 3, Debug_EventScript_InflictStatus1_Party_Burn
	case 4, Debug_EventScript_InflictStatus1_Party_Freeze
	case 5, Debug_EventScript_InflictStatus1_Party_Frostbite
	case 6, Debug_EventScript_InflictStatus1_Close
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Poison:
	setstatus1 STATUS1_POISON, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Paralysis:
	setstatus1 STATUS1_PARALYSIS, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Sleep:
	setstatus1 STATUS1_SLEEP, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Burn:
	setstatus1 STATUS1_BURN, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Freeze:
	setstatus1 STATUS1_FREEZE, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Frostbite:
	setstatus1 STATUS1_FROSTBITE, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Text_Single:
	.string "单体$"

Debug_EventScript_InflictStatus1_Text_PartyWide:
	.string "全队$"

Debug_EventScript_InflictStatus1_Text_Close:
	.string "关闭$"

Debug_EventScript_InflictStatus1_Text_Poison:
	.string "中毒$"

Debug_EventScript_InflictStatus1_Text_Paralysis:
	.string "麻痹$"

Debug_EventScript_InflictStatus1_Text_Sleep:
	.string "睡眠$"

Debug_EventScript_InflictStatus1_Text_Burn:
	.string "灼伤$"

Debug_EventScript_InflictStatus1_Text_Freeze:
	.string "冰冻$"

Debug_EventScript_InflictStatus1_Text_Frostbite:
	.string "冻伤$"

Debug_EventScript_InflictStatus1_Text_KO:
	.string "KO$"

Debug_EventScript_ChangeNature_Text_Hardy:
	.string "勤奋$"
Debug_EventScript_ChangeNature_Text_Lonely:
	.string "怕寂寞$"
Debug_EventScript_ChangeNature_Text_Brave:
	.string "勇敢$"
Debug_EventScript_ChangeNature_Text_Adamant:
	.string "固执$"
Debug_EventScript_ChangeNature_Text_Naughty:
	.string "顽皮$"
Debug_EventScript_ChangeNature_Text_Bold:
	.string "大胆$"
Debug_EventScript_ChangeNature_Text_Docile:
	.string "坦率$"
Debug_EventScript_ChangeNature_Text_Relaxed:
	.string "悠闲$"
Debug_EventScript_ChangeNature_Text_Impish:
	.string "淘气$"
Debug_EventScript_ChangeNature_Text_Lax:
	.string "Lax$"
Debug_EventScript_ChangeNature_Text_Timid:
	.string "胆小$"
Debug_EventScript_ChangeNature_Text_Hasty:
	.string "急躁$"
Debug_EventScript_ChangeNature_Text_Serious:
	.string "认真$"
Debug_EventScript_ChangeNature_Text_Jolly:
	.string "爽朗$"
Debug_EventScript_ChangeNature_Text_Naive:
	.string "天真$"
Debug_EventScript_ChangeNature_Text_Modest:
	.string "内敛$"
Debug_EventScript_ChangeNature_Text_Mild:
	.string "慢吞吞$"
Debug_EventScript_ChangeNature_Text_Quiet:
	.string "冷静$"
Debug_EventScript_ChangeNature_Text_Bashful:
	.string "害羞$"
Debug_EventScript_ChangeNature_Text_Rash:
	.string "马虎$"
Debug_EventScript_ChangeNature_Text_Calm:
	.string "温和$"
Debug_EventScript_ChangeNature_Text_Gentle:
	.string "温顺$"
Debug_EventScript_ChangeNature_Text_Sassy:
	.string "自大$"
Debug_EventScript_ChangeNature_Text_Careful:
	.string "慎重$"
Debug_EventScript_ChangeNature_Text_Quirky:
	.string "浮躁$"

Debug_EventScript_EWRAMCounters::
	callnative CheckEWRAMCounters
	msgbox Debug_EventScript_EWRAMCounters_Text, MSGBOX_DEFAULT
	release
	end

Debug_EventScript_EWRAMCounters_Text::
	.string "跟随步数：{STR_VAR_1}。\n"
	.string "钓鱼次数：{STR_VAR_2}。$"

Debug_EventScript_FontTest_Text_1::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Angel Adept Blind Bodice Clique"
	.string "Coast Dunce Docile Enact Eosin\l"
	.string "Furlong Focal Gnome Gondola Human"
	.string "Hoist Inlet Iodine Justin Jocose\l"
	.string "Knoll Koala Linden Loads Milliner"
	.string "Modal Number Nodule Onset Oddball\l"
	.string "Pneumo Poncho Quanta Qophs Rhone"
	.string "Roman Snout Sodium Tundra Tocsin\l"
	.string "Uncle Udder Vulcan Vocal Whale"
	.string "Woman Xmas Xenon Yunnan Young\l"
	.string "Zloty Zodiac.$"

Debug_EventScript_FontTest_Text_2::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "安静的世界充满细语\n"
	.string "城堡中的精灵追逐梦想。\l"
	.string "飞鸟飞鸟掠过蓝天白云，\l"
	.string "风铃响起，带来午后微光。\l"
	.string "欢乐的旅人走过古道幽径，\l"
	.string "梦境与现实在交界相融。\l"
	.string "光辉之地记录回忆点滴，\l"
	.string "盛开的梨花低语着春意。$"

Debug_EventScript_FontTest_Text_3::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Enact enact eosin for the quench coed"
	.string "of the pique canoe and bleep. Furlong\l"
	.string "furlong focal for the genuflect"
	.string "profound of the motif aloof and offers.\l"
	.string "Gnome gnome gondola for the impugn"
	.string "logos of the unplug analog and smuggle.\l"
	.string "Human human hoist for the buddhist"
	.string "alcohol of the riyadh caliph and\l"
	.string "bathhouse.$"

Debug_EventScript_FontTest_Text_4::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Inlet inlet iodine for the quince"
	.string "champion of the ennui scampi and shiite.\l"
	.string "Justin justin jocose for the djibouti"
	.string "sojourn of the oranj raj and hajjis.\l"
	.string "Knoll knoll koala for the banknote"
	.string "lookout of the dybbuk outlook and\l"
	.string "trekked. Linden linden loads for the"
	.string "ulna monolog of the consul menthol and\l"
	.string "shallot.$"

Debug_EventScript_FontTest_Text_5::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Milliner milliner modal for the alumna"
	.string "solomon of the album custom and summon.\l"
	.string "Number number nodule for the unmade"
	.string "economic of the shotgun bison and\l"
	.string "tunnel. Onset onset oddball for the"
	.string "abandon podium of the antiquo tempo\l"
	.string "and moonlit. Pneumo pneumo poncho for"
	.string "the dauphin opossum of the holdup\l"
	.string "bishop and supplies.$"

Debug_EventScript_FontTest_Text_6::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "风起时叶随梦飘摇\n"
	.string "泉水清清流过岁月。\l"
	.string "山峰巍峨如岁月沉淀，\l"
	.string "月色温柔照亮心房。\l"
	.string "星辰之间闪烁故事，\l"
	.string "长夜不再孤单徘徊。\l"
	.string "梦境醒来仍有诗意，\l"
	.string "新的一天缓缓到来。$"

Debug_EventScript_FontTest_Text_7::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "Uncle uncle udder for the dunes cloud"
	.string "of the hindu thou and continuum. Vulcan\l"
	.string "vulcan vocal for the alluvial ovoid of"
	.string "the yugoslav chekhov and revved. Whale\l"
	.string "whale woman for the meanwhile blowout"
	.string "of the forepaw meadow and glowworm.\l"
	.string "Xmas xmas xenon for the bauxite"
	.string "doxology of the tableaux equinox and\l"
	.string "exxon.$"

Debug_EventScript_FontTest_Text_8::
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "云南古老神秘土地\n"
	.string "年轻梦想在此启程。\l"
	.string "风中回荡过往旋律，\l"
	.string "遥远旅途逐梦不停。$"


Debug_EventScript_FontTest_Text_9::                 @ Special thanks to Nintendo for this nice pangram to test other glyphs
	.string "{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "42 × 138 = 5796.\n"
	.string "Mr Jock, TV quiz PhD: bags 20% fewer"
	.string "lynx at a café; voilà, they're “worth”\l"
	.string "♂1/♀1 = ¥1. That's 10 + 9 - 8 = 11"
	.string "Nintendo GBA can connect to a Nintendo\l"
	.string "GameCube console! He claimed-though I don't"
	.string "believe him-to have done so in an eyes-shut\l"
	.string "state…?$"

Debug_PrintFontTest::
	msgbox Debug_EventScript_FontTest_Text_1, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_2, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_3, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_4, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_5, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_6, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_7, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_8, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_9, MSGBOX_DEFAULT
	releaseall
	end

Debug_EventScript_FontTest::
	lockall
	goto Debug_PrintFontTest
@	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
@	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
@	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
@	switch VAR_RESULT
@	case 0, Debug_EventScript_InflictStatus1_Single
@	case 1, Debug_EventScript_InflictStatus1_Party
@	case 2, Debug_EventScript_InflictStatus1_Close
@Debug_EventScript_InflictStatus1_Close:
@	releaseall
@	end

Debug_EventScript_TellTheTime::
	callnative DebugMenu_CalculateTime
	msgbox Debug_EventScript_TellTheTime_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Debug_EventScript_PrintTimeOfDay::
	callnative DebugMenu_CalculateTimeOfDay
	msgbox DebugEventScript_PrintWeekday_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Debug_EventScript_FakeRTCNotEnabled::
	msgbox Debug_EventScript_FakeRTCNotEnabled_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	return

Debug_EventScript_FakeRTCNotEnabled_Text_0:
	.string "您当前未启用FakeRTC功能。\n"
	.string "请在include/config/overworld.h文件中\l"
	.string "启用该功能。$"


Debug_EventScript_TellTheTime_Text_0:
	.string "时间与日期：\n"
	.string "{STR_VAR_1}, {STR_VAR_2}:{STR_VAR_3}$"

DebugEventScript_PrintWeekday_Text_0:
	.string "时间段： {STR_VAR_1}$"
