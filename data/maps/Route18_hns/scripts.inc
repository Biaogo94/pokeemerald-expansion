Route18_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route18_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route18_EventScript_Trigger_HideKecleon0::
	setvar VAR_TEMP_0, 1
	setflag FLAG_TEMP_1
	removeobject LOCALID_ROUTE18_KECLEON0
	end

Route18_EventScript_Trigger_HideKecleon1::
	setvar VAR_TEMP_1, 1
	setflag FLAG_TEMP_2
	removeobject LOCALID_ROUTE18_KECLEON1
	end

Route18_EventScript_Boris::
	trainerbattle_single TRAINER_BORIS_HNS, Route18_Text_BirdKeeperBorisSeen, Route18_Text_BirdKeeperBorisBeaten
	msgbox Route18_Text_BirdKeeperBorisAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Bob::
	trainerbattle_single TRAINER_BOB_HNS, Route18_Text_BirdKeeperBobSeen, Route18_Text_BirdKeeperBobBeaten
	msgbox Route18_Text_BirdKeeperBobAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_SIGN
	end

Route18_Text_BirdKeeperBorisSeen:
	.string "要是想找宝可梦的话，就得去草丛里\n"
	.string "找找看。$"

Route18_Text_BirdKeeperBorisBeaten:
	.string "哎呀--！$"

Route18_Text_BirdKeeperBorisAfterBattle:
	.string "你这么强，对战起来一定很有意思吧\n"
	.string "。$"

Route18_Text_BirdKeeperBobSeen:
	.string "走自行车道是去玉虹市的捷径。$"

Route18_Text_BirdKeeperBobBeaten:
	.string "……呼！$"

Route18_Text_BirdKeeperBobAfterBattle:
	.string "要是没有自行车的话，是不准走这条\n"
	.string "捷径的。$"

Route18_Text_Sign:
	.string "18号道路\p"
	.string "玉虹市 - 浅红市$"
