Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "我们正在阿罗拉群岛度假呢！\p"
	.string "这里就像阿罗拉地区一样，而且离关\n"
	.string "都更近！\p"
	.string "省下了一大笔路费呢！$"

Melemele_House4_Woman_Text_0:
	.string "我男朋友跟我说我们要去阿罗拉...\n"
	.string "...\p"
	.string "我还以为是阿罗拉地区呢，没想到只\n"
	.string "是关都沿海的这些小岛。$"
