LavenderTown_SoulHouse_hns_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "富士老人：欢迎。\p"
	.string "嗯......看来你平时对待宝可\n"
	.string "梦既温柔又充满爱心啊。\p"
	.string "热爱宝可梦的人们会来这里悼念逝去\n"
	.string "的宝可梦。\p"
	.string "请为逝去宝可梦的灵魂献上哀思吧。\p"
	.string "它们感受到的话，一定会很欣慰的。$"

SoulHouse_Text_Teacher:
	.string "我想这里应该还有其他的宝可梦墓穴\n"
	.string "。\p"
	.string "有很多房间只有富士老人才能进去呢\n"
	.string "。$"

SoulHouse_Text_Lass:
	.string "我是和妈妈一起来给宝可梦扫墓的.\n"
	.string ".....$"

SoulHouse_Text_Granny:
	.string "那些曾和我相伴生活的宝可梦...\n"
	.string "...\p"
	.string "我疼爱它们就像疼爱自己的孙儿一样\n"
	.string "......$"
