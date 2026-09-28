CeruleanCity_Mart_hns_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "去往华蓝海角的小路上会遇到很多训\n"
	.string "练家。\p"
	.string "他们都想和其他训练家比试一下自己\n"
	.string "的实力。$"

CeruleanMart_Text_CooltrainerF:
	.string "小霞大概是镇上唯一能打赢华蓝海角\n"
	.string "那些训练家的人了。$"
