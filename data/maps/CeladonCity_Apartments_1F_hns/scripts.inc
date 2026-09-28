CeladonCity_Apartments_1F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "只要有可爱的宝可梦陪着我，我就一\n"
	.string "点也不会觉得寂寞。\p"
	.string "喵喵甚至还会把钱捡回家呢。$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "玉虹大厦 管理人室$"
