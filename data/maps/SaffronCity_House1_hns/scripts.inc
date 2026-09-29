SaffronCity_House1_hns_MapScripts::
	.byte 0

SaffronCity_House1_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_PSYCHIC, SaffronCity_House1_EventScript_MrPsychicAfter
	msgbox MrPsychic_Text_1, MSGBOX_NPC
	giveitem ITEM_TM_PSYCHIC
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	setflag FLAG_GOT_TM_PSYCHIC
	release
	end

SaffronCity_House1_EventScript_MrPsychicAfter::
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	end

MrPsychic_Text_1:
	.string "......\p"
	.string "......\p"
	.string "......\p"
	.string "……我知道了！\p"
	.string "你想要的是这个吧！$"

MrPsychic_Text_2:
	.string "招式学习器29是“精神强念”。\p"
	.string "有时会降低对手的特防。$"
