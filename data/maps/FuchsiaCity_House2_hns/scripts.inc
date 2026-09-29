FuchsiaCity_House2_hns_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "我爷爷是狩猎地带的园长。\p"
	.string "至少以前是……\p"
	.string "他心血来潮要去度假，一个人跑到海\n"
	.string "外去了。\p"
	.string "就这么把狩猎地带给抛下不管了。$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "狩猎地带关闭让大家都挺失望的，但\n"
	.string "我爷爷实在太固执了……$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "这是一张照片，上面是一位被宝可梦\n"
	.string "们簇拥着、咧嘴大笑的老爷爷。$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "这是一张照片，广袤的草地上有稀有\n"
	.string "的宝可梦在欢快嬉戏。$"
