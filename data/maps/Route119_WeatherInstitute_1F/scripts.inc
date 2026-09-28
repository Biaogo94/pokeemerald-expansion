Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "老大对这儿的研究很感兴趣，所以派\n"
	.string "我们来这里。\p"
	.string "你别来碍事！$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "输了……输给一个小鬼……$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "老大无所不知。\p"
	.string "但我只是个小人物，又怎么能猜到他\n"
	.string "的想法？$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "嗯？这儿怎么有个小孩子？$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "嗯？我输了？！$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "哦，不……输给个小鬼，我又得被唠\n"
	.string "叨了……\p"
	.string "还是躲床上打盹吧……$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "我睡觉的时候大家都上楼去了！$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "哇，你真强！\p"
	.string "真想成为和你一样的宝可梦训练家！$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "教授沉迷于降雨研究，这是事实。\p"
	.string "但如果雨一直不停，就会给人们带来\n"
	.string "麻烦，这也是事实。\p"
	.string "因此，教授在研究如何让雨造福于人\n"
	.string "。$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "我们在研究所二楼研究丰缘地区的天\n"
	.string "气变化情况。\p"
	.string "我们发现近期频繁出现局部突发性干\n"
	.string "旱与强降雨的异常现象……$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "嗨！谢谢你救了我们！\p"
	.string "但我真的想不通海洋队到底在打什么\n"
	.string "主意。$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "有张床……休息一下吧。$"

