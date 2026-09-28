MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "我热爱一切恐怖的事物……就像一种\n"
	.string "病……\p"
	.string "当我在此……我因恐惧而颤抖……$"

MtPyre_4F_Text_TashaDefeat:
	.string "我讨厌失败……$"

MtPyre_4F_Text_TashaPostBattle:
	.string "我想看看可怕的东西……我不能离开\n"
	.string "……\p"
	.string "呐……你不想和我一起来吗？$"

