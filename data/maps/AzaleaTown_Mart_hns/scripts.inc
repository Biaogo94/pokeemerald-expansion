AzaleaTown_Mart_hns_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "你能买到超级球吗？我能买到的只有\n"
	.string "精灵球。\p"
	.string "听说赢得道馆徽章后，店里能买到的\n"
	.string "道具就会变多！\p"
	.string "真希望钢铁先生能为我做一些他特制\n"
	.string "的球啊。$"

AzaleaMart_Text_BugCatcher:
	.string "超级球比精灵球更容易捉到宝可梦。\p"
	.string "不过有时钢铁先生做的球效果会更好\n"
	.string "呢。$"

