CeruleanCity_House2_hns_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "听说有个鬼鬼祟祟的家伙在到处乱\n"
	.string "晃。\p"
	.string "要是被我发现他是小偷，我可绝对饶\n"
	.string "不了他！$"

CeruleanPolice_Text_PokefanF:
	.string "我们家以前曾被强盗光顾过呢。$"

CeruleanPolice_Text_Diglett:
	.string "地鼠：地咕地咕。$"
