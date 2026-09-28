PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "欢迎光临！\p"
	.string "向您说明一下，由于所有大型标本都\n"
	.string "被借调到其他博物馆展出了，\p"
	.string "因此目前本馆免费参观！\p"
	.string "请随意参观吧。$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "你一定是一位很厉害的训练家吧。\p"
	.string "那边柜台上的化石，我们留着也没什\n"
	.string "么用。\p"
	.string "是一位留着银色头发的奇怪男子送了\n"
	.string "一大堆过来的。\p"
	.string "如果你想要的话，尽管拿去吧。$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "我们经常和阿露福遗迹的研究员们共\n"
	.string "享研究成果。\p"
	.string "甚至还能通过电脑与他们共享化石\n"
	.string "呢！$"

PewterCity_Museum_1F_Text_Oldman:
	.string "活得久真是一件值得感激的事啊。\p"
	.string "做梦也没想到，我这辈子竟然能亲眼\n"
	.string "看到龙的骨骼！$"

PewterCity_Museum_1F_Text_Bones:
	.string "古代龙宝可梦的骨骼。$"
