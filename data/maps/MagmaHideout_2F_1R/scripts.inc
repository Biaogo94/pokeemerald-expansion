MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "什么什么什么？\p"
	.string "只有熔岩队才准进来！\p"
	.string "但你没穿熔岩队的制服……\p"
	.string "你很可疑！和我对战吧！$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "呜哇……我作为熔岩队手下的尊严啊\n"
	.string "……$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "要是你怕冷的话，不如加入我们熔岩\n"
	.string "队吧。$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "站住！\p"
	.string "你不会以为我会眼睁睁地站在这里，\n"
	.string "放你大摇大摆地过去吧？$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "哇啊！我认输！$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "早知道这样，还不如直接放你过去算\n"
	.string "了……$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "啊！有入侵者！$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "哇啊啊！$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "都已经输了……\p"
	.string "我还有必要继续在这儿转圈巡逻吗？$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "哦，哦！有入侵者！$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "切……$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "说实话，我本来就不擅长对战……$"

