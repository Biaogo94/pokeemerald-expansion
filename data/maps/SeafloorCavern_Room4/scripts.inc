SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "什么人？从哪儿进来的？$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "输了……$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "根本找不到出口！\p"
	.string "先说好——我才没害怕！$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "什么人？想上哪儿去？$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "任务失败！$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "我那废物搭档把地图忘潜艇里了！\p"
	.string "你说这货有什么用？$"

