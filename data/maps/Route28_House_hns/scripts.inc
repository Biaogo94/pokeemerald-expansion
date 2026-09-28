Route28_House_hns_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_STEEL_WING, Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "哎呀。被你发现了。\p"
	.string "请千万别告诉别人我在这里。\p"
	.string "送你这个作为保密的谢礼，好吗？$"

Route28House_Text_Celebrity2:
	.string "当超级大明星真辛苦啊。\p"
	.string "无论我走到哪里，都有人追着我跑。\p"
	.string "我只想一个人静静......$"

Route28House_Text_Fearow:
	.string "大嘴雀：嘎啊！$"

