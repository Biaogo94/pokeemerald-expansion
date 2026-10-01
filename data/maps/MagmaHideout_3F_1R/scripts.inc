MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "我怎么会被分配到这个岗位上？\p"
	.string "我的左耳快烤熟了！$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "快热晕了……$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "在岩浆火山里戴着兜帽在你不觉得奇\n"
	.string "怪吗？$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "我们加入组织，为的是帮助老大实现\n"
	.string "他的雄图伟业。\p"
	.string "我不管你是海洋队的人还是偶尔路过\n"
	.string "的小鬼头，\p"
	.string "敢碍事的家伙一个都别想跑！$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "哦，不！真是不可轻视！$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "听好了——熔岩队才是正确的！\p"
	.string "别听海洋队的，别相信他们说的鬼\n"
	.string "话！$"

