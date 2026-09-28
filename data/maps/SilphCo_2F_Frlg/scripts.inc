SilphCo_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
	.string "救命！我是一个西尔佛的员工。$"

SilphCo_2F_Text_ConnorDefeat::
	.string "你怎么知道我是一个火箭队的队员？$"

SilphCo_2F_Text_ConnorPostBattle::
	.string "我在为西尔佛工作的同时也和火箭队\n"
	.string "合作。$"

SilphCo_2F_Text_JerryIntro::
	.string "这里禁止入内！回家吧！$"

SilphCo_2F_Text_JerryDefeat::
	.string "你很厉害。$"

SilphCo_2F_Text_JerryPostBattle::
	.string "你能解决这个麻烦吗？我告诉你，这\n"
	.string "可不容易！$"

SilphCo_2F_Text_Grunt1Intro::
	.string "孩子不允许在这里！$"

SilphCo_2F_Text_Grunt1Defeat::
	.string "好强！$"

SilphCo_2F_Text_Grunt1PostBattle::
	.string "菱形瓷砖是传送方块。\p"
	.string "他们是这个高科技建筑的传送装置。$"

SilphCo_2F_Text_Grunt2Intro::
	.string "嘿，小孩！你在这儿干嘛呢？$"

SilphCo_2F_Text_Grunt2Defeat::
	.string "我搞砸了！$"

SilphCo_2F_Text_Grunt2PostBattle::
	.string "西尔佛公司将与火箭队合并！$"

Text_ThunderWaveTeach::
	.string "呀！不要啊！住手！救命！\p"
	.string "哦，你不是火箭队的成员啊。抱歉，\n"
	.string "我以为……\p"
	.string "如果我教你的电磁波技能你会原谅我\n"
	.string "吗？$"

Text_ThunderWaveDeclined::
	.string "哦……但电磁波很厉害喔……$"

Text_ThunderWaveWhichMon::
	.string "我要教哪只宝可梦电磁波？$"

Text_ThunderWaveTaught::
	.string "电磁波的会使受方宝可梦麻痹。\p"
	.string "一个被麻痹的宝可梦可能在战斗中无\n"
	.string "法行动。\p"
	.string "它是电属性的技能，所以对一些宝可\n"
	.string "梦没有用。$"

SilphCo_2F_Text_FloorSign::
	.string "西尔佛公司总部2层$"

