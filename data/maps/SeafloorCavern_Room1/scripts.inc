SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "小鬼别在这里碍事！赶紧回家去！$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "我想回家了……$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "好想升职当干部，那样就能使唤小卒\n"
	.string "们了……$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "那潜水艇……里面也太窄了！挤得真难\n"
	.string "受！$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "失败让我更难受！$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "我们抢来的那潜水艇坐起来简直折磨\n"
	.string "人！里面挤得要命！$"

