ViridianCity_House1_hns_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "给宝可梦起昵称时你会深思熟虑吗？\p"
	.string "给它们起个好昵称，和别人交换时会\n"
	.string "更有乐趣哦。$"

ViridianCity_House1_Text_Lass:
	.string "它们是烈雀“雀宝”和小拉达“拉达宝"
	.string "”。$"

ViridianCity_House1_Text_Speary:
	.string "雀宝：啾啾！$"

ViridianCity_House1_Text_Rattey:
	.string "拉达宝：吱吱--！$"

