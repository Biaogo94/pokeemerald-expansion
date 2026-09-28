BlackthornCity_House1_hns_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "能够随心驾驭巨龙的一族，就生活在\n"
	.string "烟墨市。\p"
	.string "因此，这座城镇里流传着许多与龙相\n"
	.string "关的传说。$"

BlackthornCity_House1_Text_Dratini:
	.string "迷你龙：咪呜--！$"
