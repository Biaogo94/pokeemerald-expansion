MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "我从大吾那儿得到的这东西，但我不\n"
	.string "知道它有什么用。\p"
	.string "我想它叫做王者之证，你想要吗？$"

MossdeepCity_Text_YouCanKeepIt:
	.string "你想要它？为什么？你真奇怪。\p"
	.string "拿着吧，但千万对大吾保密。$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "大吾的家就在那儿！$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "是吗，你也这么想啊！拿着这种奇怪\n"
	.string "的石头有什么用吗？$"

MossdeepCity_Text_WailmerWatching:
	.string "在绿岭市周围可以看到野生吼吼鲸。\p"
	.string "这叫啥来着，呃……是那啥……\p"
	.string "吼，吼，吼……\p"
	.string "吼吼鲸观赏！$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "岛上的宇宙中心曾经发射过巨大的火\n"
	.string "箭。\p"
	.string "最近他们收到了一封信，引起了大骚\n"
	.string "动。$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "岛上的宇宙中心曾经发射过巨大的火\n"
	.string "箭。$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "我听一个水手说海洋队在水静市惹了\n"
	.string "些麻烦，\p"
	.string "但后来有人到那儿，把他们都驱逐了\n"
	.string "出去！\p"
	.string "可现在绿岭市被熔岩队盯上了。\p"
	.string "你想要知道他们的目的的话，就去宇\n"
	.string "宙中心看看吧。$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "我是个水手，大海对我来说应该更重\n"
	.string "要。\p"
	.string "但你知道吗？在每次长途航行后回到\n"
	.string "陆地上时，我都会觉得松了口气！$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "如果整个世界都像这个小岛一样被红\n"
	.string "花绿草所覆盖，\p"
	.string "那不是很好吗？$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "所有的生命都要依靠大海才能生存，\n"
	.string "即使是生活在陆地上的生命也一样。\p"
	.string "当一个生命走完了它的旅程，它又变\n"
	.string "成泥土回归大地。\p"
	.string "而大地总是和海洋紧密相连的。\p"
	.string "没错，就像这里的海岸线一样。$"

MossdeepCity_Text_SurfExhilarating:
	.string "虽然乘船航行还算不错，\p"
	.string "但乘着宝可梦渡海的话……\p"
	.string "那简直是太美妙了！你不这么想吗，\n"
	.string "年轻人？$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "这块石头对宇宙中心的人来说意义非\n"
	.string "凡，\p"
	.string "他们把它放在这里，祈祷火箭能安全\n"
	.string "上天。\p"
	.string "你许愿的时候会怎么做？你会向流星\n"
	.string "许愿吗？\p"
	.string "我会把愿望写在纸签上，祈祷它能实\n"
	.string "现。$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "这是一块白色石头。$"

MossdeepCity_Text_GymSign:
	.string "绿岭市宝可梦道馆馆主：小枫与小南\p"
	.string "“神秘的组合！！”$"

MossdeepCity_Text_CitySign:
	.string "这里是绿岭市。“我们的口号：珍爱\n"
	.string "宝可梦！”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "绿岭市宇宙中心“最接近宇宙的地方\n"
	.string "。”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "亚希达：{PLAYER}\n"
	.string "{KUN}，还好吗？我这儿很顺利\l"
	.string "！\p"
	.string "我听说绿岭市的道馆馆主实力很强，\n"
	.string "所以我打算过来亲眼见识一下。\p"
	.string "但这镇子上好像不太对劲，\p"
	.string "人们都在谈论什么宇宙中心和一封警\n"
	.string "告信……\p"
	.string "虽然我觉得这事跟我没啥关系就是了\n"
	.string "。$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "啊……海浪冲刷双脚的感觉……真好\n"
	.string "……\p"
	.string "说到海浪，你知道那个水上城市琉璃\n"
	.string "市吗？\p"
	.string "那儿的道馆来了个新馆主，\p"
	.string "据说他曾教导过米可利。$"

