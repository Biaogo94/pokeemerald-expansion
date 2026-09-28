Gate_EcruteakCity_Route38_hns_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "你说你是从哪里来的？\p"
	.string "若叶镇？\p"
	.string "空木博士就住在那里，对吧？\p"
	.string "那你可真是一路远道而来呢。$"
