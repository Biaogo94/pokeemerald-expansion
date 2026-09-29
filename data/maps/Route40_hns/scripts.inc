Route40_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON_HNS, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "下水之前必须要先做热身运动。\p"
	.string "这可是基本常识。$"

Route40_Text_SwimmermSimonBeaten:
	.string "好啦！我投降！认输了！$"

Route40_Text_SwimmermSimonAfter:
	.string "湛蓝市离这里还有一段挺远的距离呢\n"
	.string "。$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "嘿，你这么年轻体壮！\p"
	.string "别骑着宝可梦，自己游呀！$"

Route40_Text_SwimmermRandallBeaten:
	.string "哎呀。我输了……$"

Route40_Text_SwimmermRandallAfter:
	.string "游泳可是全身运动，对身体很健康的\n"
	.string "哦。$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "你要去湛蓝市吗？\p"
	.string "在那之前先来场痛快的对战吧！$"

Route40_Text_SwimmerfElaineBeaten:
	.string "是我输了！$"

Route40_Text_SwimmerfElaineAfter:
	.string "论游泳的话还是我更厉害。耶！$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "我才不需要游泳圈呢。\p"
	.string "我正抓着一只水宝可梦呢！$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "哎呀，头好晕啊！$"

Route40_Text_SwimmerfPaulaAfter:
	.string "像这样浮在水面上，海浪就会带着我\n"
	.string "往前飘。$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "虽然从这里还看不见，但湛蓝市就在\n"
	.string "大海的另一边哦。$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "我乘船来浅黄市观光，感受这里的港\n"
	.string "口风情。\p"
	.string "作为一座港口，这里的氛围和大都市\n"
	.string "完全不同呢。$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "你去过训练家之丘了吗？\p"
	.string "我想那里一定聚集了好多强力训练家\n"
	.string "。\p"
	.string "不过你拿到了这么多徽章，表现一定\n"
	.string "不会差的。$"

Route40_Text_Monica:
	.string "月姬：很高兴认识你。我是曜日七兄\n"
	.string "妹里的月姬。\p"
	.string "你肯定猜不到我最喜欢星期几吧！$"

Route40_Text_MonicaGivesGift:
	.string "答对啦！\p"
	.string "为了纪念我们的友谊，我有样礼物要\n"
	.string "送给你！$"

Route40_Text_MonicaGaveGift:
	.string "月姬：那是能提升飞行属性招式威力\n"
	.string "的道具。\p"
	.string "你一定要让鸟宝可梦携带哦。$"

Route40_Text_MonicaMonday:
	.string "月姬：我的兄弟姐妹们分布在各个地\n"
	.string "方。\p"
	.string "试着把他们都找齐吧！$"

Route40_Text_MonicaNotMonday:
	.string "月姬：今天好像不是星期一呢。真遗\n"
	.string "憾……$"

Route40_Text_MonicaNope:
	.string "不对哦。$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
