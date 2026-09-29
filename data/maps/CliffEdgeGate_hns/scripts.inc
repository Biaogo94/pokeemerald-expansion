CliffEdgeGate_hns_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "你知道吗？前面不远处新开了一家狩\n"
	.string "猎地带哦。\p"
	.string "那里可有意思了！不仅能见到形形色\n"
	.string "色的宝可梦，还能抓个痛快！\p"
	.string "根本没有不去的理由嘛，对吧？就在\n"
	.string "前面不远处哦。$"

CliffEdgeGate_Text_Expectations:
	.string "大家都很期待是挺好的啦。\p"
	.string "不过前台那位接待小姐似乎有点戏太\n"
	.string "过了……\p"
	.string "可别抱太高的期望哦！$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "处处皆刺激！探险寻找野生宝可梦！\n"
	.string "巴奥巴园长的狩猎地带现已盛大开业\l"
	.string "！$"

