Gate_Route31_VioletCity_hns_MapScripts::
	.byte 0

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "你好呀！你去过喇叭芽之塔了吗？$"

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "我在外面看到了一只超可爱的宝可梦\n"
	.string "。\p"
	.string "长得跟皮卡丘特别像呢！$"
