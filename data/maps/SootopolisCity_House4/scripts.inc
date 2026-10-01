SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "听着，我要告诉你一些好事。\p"
	.string "据说这附近的海里有一座古代遗迹，\p"
	.string "那里面一定有等待被发掘的宝藏。$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "古代的宝藏……\p"
	.string "如果真的有当然好，但就算没有，和\n"
	.string "宝可梦一起进行一次海底旅行也不\l"
	.string "错。$"

SootopolisCity_House4_Text_Azumarill:
	.string "玛力露丽：马鹿马鹿。$"

