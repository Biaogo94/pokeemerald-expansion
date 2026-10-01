SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "巴奥巴$"

SaffronCity_Text_Baoba:
	.string "巴奥巴园长：{PLAYER}！\p"
	.string "我是巴奥巴园长。\p"
	.string "我打电话是想告诉你，狩猎地带又扩\n"
	.string "建啦！\p"
	.string "我的狩猎地带终于完全建成了！\p"
	.string "你还记得它在哪儿吧？\p"
	.string "就在湛蓝市西边！回头见啦！$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "我最喜欢六尾了！:D$"

SaffronCity_Text_Lass1:
	.string "这里住着一个小女孩，是个模仿达\n"
	.string "人。\p"
	.string "她甚至还会模仿正在跟她说话的人，\n"
	.string "搞得人晕头转向的。$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "那个模仿少女看起来闷闷不乐的。\p"
	.string "她说她弄丢了最喜欢的皮皮宝可梦玩\n"
	.string "偶。$"

SaffronCity_Text_PokefanM:
	.string "你是从城都地区过来的？\p"
	.string "如果磁悬浮列车通了的话，一眨眼就\n"
	.string "能回老家了呢。$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "你是从城都地区过来的？\p"
	.string "只要坐上磁悬浮列车，一眨眼就能回\n"
	.string "到老家了呢。$"

SaffronCity_Text_CooltrainerM:
	.string "我本来兴致勃勃地去道馆，想跟训练\n"
	.string "家们大战一场……\p"
	.string "结果，误闯进了隔壁已经废弃的道\n"
	.string "馆。\p"
	.string "哎呀，真是丢死人了。$"

SaffronCity_Text_CooltrainerF:
	.string "这里是西尔佛公司，以生产各种宝可\n"
	.string "梦用品而闻名。\p"
	.string "以前火箭队就是因为这个盯上了这家\n"
	.string "公司。$"

SaffronCity_Text_Fisher:
	.string "嚼……嚼……\p"
	.string "听说发电厂那边出大乱子了。\p"
	.string "嚼……嚼……$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "嚼……嚼……\p"
	.string "听说发电厂那边之前出了大乱子啊。\p"
	.string "嚼……嚼……哈啊，吃饱了！$"

SaffronCity_Text_Youngster1:
	.string "第一次走进小巷子里，心里总有点发\n"
	.string "慌呢。$"

SaffronCity_Text_Youngster2:
	.string "常青市有个叫华丽大赛会场的地方，\n"
	.string "来自各地的训练家都会聚在那里。$"

SaffronCity_Text_Lass2:
	.string "广播节目里提到了我们的城市呢。\p"
	.string "听到别人夸奖自己的家乡固然开心，\n"
	.string "但总觉得有点不好意思呢。$"

SaffronCity_Text_Sign:
	.string "金黄市\p"
	.string "闪耀黄金光芒的商业之都$"

SaffronCity_Text_GymSign:
	.string "金黄市宝可梦道馆馆主：娜姿\p"
	.string "超能力宝可梦的大师！$"

SaffronCity_Text_FightingDojoSign:
	.string "欢迎任何人挑战！格斗道场$"

SaffronCity_Text_SilphCoSign:
	.string "西尔佛公司办公大楼$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "超能力大叔的家$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "金黄市磁浮列车站$"
