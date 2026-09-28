MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "当熔岩队点名布置任务的时候，我们\n"
	.string "按照排队的顺序各自领到重要性不同\l"
	.string "的守卫任务。\p"
	.string "所以我才被安排到这个角落里——因\n"
	.string "为我点名的时候总是迟到！$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "我训练时也总是迟到！\p"
	.string "虽然不想承认，可我真的很弱……$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "好吧，我以后做事会试着再努力一点\n"
	.string "的……$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "我们老大叫我们挖掘烟囱山，所以我\n"
	.string "们就一直挖啊挖。\p"
	.string "在挖的过程中，我们发现了劲爆的东\n"
	.string "西！\p"
	.string "究竟是什么？\p"
	.string "哈哈哈！打赢我的话就告诉你！$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "啊！输了！$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "我才不会告诉你。你到了那里就知道\n"
	.string "了！\p"
	.string "悬念要保存到最后一刻，你说对吧？$"

