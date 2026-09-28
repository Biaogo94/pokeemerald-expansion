CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "老夫年轻那会儿，也是个厉害的训练\n"
	.string "家呢！\p"
	.string "给你一句忠告吧：多去捕捉宝可梦！\p"
	.string "然后温柔地对待它们！$"
