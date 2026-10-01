MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "我和你无冤无仇，我只是奉命行事！$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "虽然我输了，可是……$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "我们挖掘到了难以置信的东西！还拿\n"
	.string "到了靛蓝色宝珠！\p"
	.string "现在只等老大……哼哼哼……哈哈哈哈！$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "实在受不了这热气。或许我当初该加\n"
	.string "入海洋队……$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "看来我真的不适合待在熔岩队……$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "待在这种地方你不会想念大海吗？$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "在这里有时能感觉到晃动。\p"
	.string "难道是火山在震动？还是固拉……\p"
	.string "哎呀！不，不，没什么！$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "你的进攻真猛烈，就像火山一样！$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "就算这次你赢了也改变不了什么。\p"
	.string "熔岩队的伟大目标马上就要实现了！$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "我们一个队员正因弄丢了熔岩标志而\n"
	.string "抓狂呢……\p"
	.string "等一下！该不会被你捡到了？$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "真是难以置信……$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "我总感觉我们的计划会以失败告终……$"

