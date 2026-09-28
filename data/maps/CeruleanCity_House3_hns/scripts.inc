CeruleanCity_House3_hns_MapScripts::
	.byte 0

CeruleanCity_House3_EventScript_Granny::
	msgbox CeruleanHouse_Text_Granny, MSGBOX_NPC
	end
CeruleanCity_House3_EventScript_Gramps::
	msgbox CeruleanHouse_Text_Gramps, MSGBOX_NPC
	end

CeruleanCity_House3_EventScript_Kangaskhan::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	msgbox CeruleanHouse_Text_Kangaskhan, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_House3_EventScript_Zubat::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	msgbox CeruleanHouse_Text_Zubat, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanHouse_Text_Granny:
	.string "我丈夫和交换来的宝可梦一起生活得\n"
	.string "非常幸福。$"

CeruleanHouse_Text_Gramps:
	.string "啊......我好幸福啊....\n"
	.string "..$"

CeruleanHouse_Text_Kangaskhan:
	.string "袋兽：嘎噜嘎噜。$"

CeruleanHouse_Text_Zubat:
	.string "超音蝠：吱吧吱吧。$"

