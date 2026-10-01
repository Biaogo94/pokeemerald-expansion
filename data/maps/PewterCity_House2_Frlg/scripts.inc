PewterCity_House2_Frlg_MapScripts::
	.byte 0

PewterCity_House2_EventScript_OldMan::
	msgbox PewterCity_House2_Text_MonsLearnTechniquesAsTheyGrow, MSGBOX_NPC
	end

PewterCity_House2_EventScript_LittleBoy::
	msgbox PewterCity_House2_Text_MonsEasierCatchIfStatused, MSGBOX_NPC
	end

PewterCity_House2_Text_MonsLearnTechniquesAsTheyGrow::
	.string "宝可梦在成长过程中可以学到新的技\n"
	.string "能。\p"
	.string "但是有一些必须要有人教它们才能学\n"
	.string "会。$"

PewterCity_House2_Text_MonsEasierCatchIfStatused::
	.string "当一只宝可梦进入异常状态时会容易\n"
	.string "收服一些。\p"
	.string "睡眠，中毒，烧伤，或者麻痹……这些\n"
	.string "都能对其造成影响。\p"
	.string "但是收服一只宝可梦从来都不是件容\n"
	.string "易的事！$"

