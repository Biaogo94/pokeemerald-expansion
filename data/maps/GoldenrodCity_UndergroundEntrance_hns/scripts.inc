GoldenrodCity_UndergroundEntrance_hns_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "我在下面被人发起挑战了。\p"
	.string "地下通道里挺乱的，你最好小心一\n"
	.string "点。$"


GoldenrodUnderground1_Text_Teacher:
	.string "虽然楼下有些店铺……但也有不少训练\n"
	.string "家。\p"
	.string "我可不敢下去。$"
