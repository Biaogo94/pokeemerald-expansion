Route26_House1_hns_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
    .string "你的宝可梦看起来有点累了。\p"
    .string "在这里休息一会儿吧。$"

Route26_Text_HealHouseKeepAtIt:
    .string "好啦！\p"
    .string "你的宝可梦都恢复精神了！\p"
    .string "继续加油吧！$"
