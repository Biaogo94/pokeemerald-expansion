MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "我明白老大所说的话。但说实话——\p"
	.string "又是挖掘超古代宝可梦又是抢夺别人\n"
	.string "的陨石……\p"
	.string "是不是有些做过头了。你怎么想？$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "果然……确实做得不太对。$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "说实话，输给你后我反而清醒了许\n"
	.string "多。\p"
	.string "下次见到老大的时候，我打算问个明\n"
	.string "白。$"

