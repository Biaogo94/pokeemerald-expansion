Melemele_House_3_hns_MapScripts::
	.byte 0


Melemele_House3_Woman::
	lock
	faceplayer
	msgbox Melemele_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Man::
	lock
	faceplayer
	msgbox Melemele_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Woman_Text_0:
	.string "这里的海岛生活真惬意！\p"
	.string "而且我的孙辈们都在关都，坐一小会\n"
	.string "儿船就能见到，太棒了！$"

Melemele_House3_Man_Text_0:
	.string "讨厌的游客！\p"
	.string "房产中介明明跟我说这里很清静的。\n"
	.string "……不过比起大老远去阿罗拉\l"
	.string "，来这儿旅游确实便宜得多。$"
