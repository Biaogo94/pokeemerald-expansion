Route21_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH_HNS, Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI_HNS, Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD_HNS, Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "看到陆地了！要加把劲游过去！$"

Route21_Text_SwimmermSethBeaten:
	.string "咕嘟……$"

Route21_Text_SwimmermSethAfterBattle:
	.string "红莲岛的火山那边，有个神气活现的\n"
	.string "家伙。$"

Route21_Text_SwimmerfNikkiSeen:
	.string "如果我赢了，你可得帮我涂防晒油\n"
	.string "哦！$"

Route21_Text_SwimmerfNikkiBeaten:
	.string "真担心会被晒伤啊……$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "我可得留心别被大太阳晒出斑点才\n"
	.string "行。$"

Route21_Text_FisherArnoldSeen:
	.string "钓鱼钓腻了。来对战吧！$"

Route21_Text_FisherArnoldBeaten:
	.string "一败涂地……$"

Route21_Text_FisherArnoldAfterBattle:
	.string "我还是回去钓鱼吧……$"

