OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	map_script_2 VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	setspeaker OlivineCity_Text_BaobaName
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_BaobaName:
	.string "巴奥巴$"

OlivineCity_Text_Baoba:
	.string "{PLAYER}！\p"
	.string "我是巴奥巴园长。\p"
	.string "让你久等啦。我们的狩猎地带终于开\n"
	.string "业了！\p"
	.string "你知道在哪里吗？\p"
	.string "湛蓝市洞窟里面的那个大门，你还记\n"
	.string "得吧？\p"
	.string "从那里穿过去走上一小段路，马上就\n"
	.string "能看到狩猎地带了！\p"
	.string "虽然路途有点偏远，但请一定要来玩\n"
	.string "哦！$"

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0
	
	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "又是你？别那么提心吊胆的。\p"
	.string "我才没闲工夫理会像你这样的弱者。\p"
	.string "说到弱者……这座城市的道馆馆主根本\n"
	.string "不在这里。听说是在灯塔照料生病的\l"
	.string "宝可梦呢。\p"
	.string "哼！真是笑话！生病的宝可梦丢掉不\n"
	.string "就行了！\p"
	.string "不能战斗的宝可梦根本毫无价值！\p"
	.string "你也去灯塔特训一下如何？\p"
	.string "谁知道呢，说不定能让你稍微变强那\n"
	.string "么一点点！$"

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_ChargeBeam::
	finditem ITEM_TM_CHARGE_BEAM
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "浅黄咖啡厅让强壮水手大快朵颐长力\n"
	.string "气的地方$"

OlivineCity_Text_EonTicketWoman1:
	.string "我叫玛丽！\p"
	.string "开个玩笑啦，不过我真的很喜欢玛丽\n"
	.string "主持的广播节目！$"

OlivineCity_Text_EonTicketWoman2:
	.string "你一定就是{PLAYER}吧！"
	.string "！！\p"
	.string "天哪！是冠军本人！\p"
	.string "我在玛丽的广播节目里听到过你的事\n"
	.string "迹！\p"
	.string "来，这个送给你！$"

OlivineCity_Text_EonTicketWoman3:
	.string "真不敢相信我竟然见到了冠军！！！$"

OlivineCity_Text_Sailor1:
	.string "夜里走暗路很危险。\p"
	.string "可大海一片漆黑的时候，就更加凶险\n"
	.string "了！\p"
	.string "没有灯塔指引，船就无法航行。$"

OlivineCity_Text_YoungsterPokegear:
	.string "你拿的那个--是宝可梦齿轮吧？哇，\n"
	.string "真酷啊。$"

OlivineCity_Text_YoungsterPokedex:
	.string "哇，你有宝可梦图鉴！\p"
	.string "这也太厉害了吧。$"

OlivineCity_Text_Sailor2:
	.string "联盟居然把阿蜜评为第六强的道馆馆\n"
	.string "主！\p"
	.string "哈！简直是一派胡言。\p"
	.string "柳伯根本不可能伤到阿蜜的钢属性宝\n"
	.string "可梦好吗！\p"
	.string "依我看纯粹是官僚做派。\p"
	.string "她的实力绝对令人畏惧，这是毫无疑\n"
	.string "问的！$"

OlivineCity_Text_Sign:
	.string "浅黄市\p"
	.string "散发异国情调的港口$"

OlivineCity_Text_PortSign:
	.string "浅黄港高速船码头$"

OlivineCity_Text_GymSign:
	.string "浅黄市宝可梦道馆馆主：阿蜜\p"
	.string "铁壁防守的少女$"

OlivineCity_Text_LighthouseSign:
	.string "浅黄灯塔别名 光辉灯塔$"

OlivineCity_Text_BattleTowerSign:
	.string "前方为训练家之丘与对战帐篷。\p"
	.string "现已开放！$"

OlivineCity_Text_Machoke:
	.string "豪力：巧！$"
