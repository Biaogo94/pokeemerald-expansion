PalletTown_RedsHouse_1F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "你好呀！\p"
	.string "赤红已经出门好久了。\p"
	.string "他也没打过电话，我完全不知道他现\n"
	.string "在在哪儿，在做些什么。\p"
	.string "虽说没有消息就是好消息，可我还是\n"
	.string "会担心他呀。$"

RedsHouse_Text_Mom2:
	.string "我总担心赤红会不会受伤或是生病，\n"
	.string "不过他毕竟是个男孩子。\p"
	.string "能去做自己想做的事，我为他感到骄\n"
	.string "傲。$"

RedsHouse_Text_TV:
	.string "正在播放城都地区看不到的电视节\n"
	.string "目......$"
