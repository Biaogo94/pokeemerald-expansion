Gate_AzaleaTown_IlexForest_hns_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "桐树林可大着呢。千万小心！可别迷\n"
	.string "路了。$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "桐树林由这里的守护神在默默庇佑\n"
	.string "着。\p"
	.string "可不要在这里恶作剧哦！$"
