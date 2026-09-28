BattleFrontier_PokemonCenter_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition_hns
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition_hns:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST_HNS
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse_hns::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon_hns:
	.string "这里有人用着我从没见过的宝可梦。\p"
	.string "至少在训练家学校里从没学过。\p"
	.string "真不知道在哪里能捉到那样的宝可梦\n"
	.string "。$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena_hns:
	.string "好！下一站是对战竞技场！我得先去\n"
	.string "宝可梦储存系统里取出合适的宝可梦\l"
	.string "才行。$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge_hns:
	.string "咯咯......我就带着这孩子去\n"
	.string "通关所有挑战！$"

BattleFrontier_PokemonCenter_1F_Text_Skitty_hns:
	.string "向尾喵：喵~呜！$"

