LavenderTown_House1_hns_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "你敢相信吗？\p"
	.string "有些人照顾宝可梦照顾腻了就丢下不\n"
	.string "管了。\p"
	.string "爷爷收留了那些可怜又无家可归的宝\n"
	.string "可梦，细心地照顾它们。$"
LavenderTown_House1_Text_Guy:
	.string "富士老人确实住在这里，但他现在出\n"
	.string "门了。他应该是在灵魂之屋。$"
LavenderTown_House1_Text_Marowak:
	.string ".............................$"

LavenderTown_House1_Text_Marowak2:
	.string "嘎啦嘎啦很安静，不过它看起来相当\n"
	.string "开心。$"

