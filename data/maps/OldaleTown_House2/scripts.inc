OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "宝可梦战斗时，会获得经验升级变\n"
	.string "强。$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "如果你的宝可梦变强了，你就可能走\n"
	.string "得更远。$"

