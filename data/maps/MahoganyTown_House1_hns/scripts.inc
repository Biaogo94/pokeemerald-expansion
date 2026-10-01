MahoganyTown_House1_hns_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "我听说湖里出现了红色的暴鲤龙。\p"
    .string "这可真奇怪，因为那个湖里就连普通\n"
    .string "的暴鲤龙都很少见呢……$"

MahoganyRedGyaradosHouse_Text_Teacher:
    .string "我最喜欢的广播节目？那当然是宝可\n"
    .string "梦音乐了。$"

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "我刚才在收音机里听到了笑声......\p"
    .string "真叫人毛骨悚然。$"
