PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "在丰缘地区有3只宝可梦，分别代表\n"
	.string "岩石、冰雪、钢铁的力量，\p"
	.string "据说它们都躲藏在某些山洞的深处。\p"
	.string "这是我孩提时听过的传说。$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“6个点打开3扇门”。\p"
	.string "爷爷经常这么说，但我不知道是什么\n"
	.string "意思。$"

