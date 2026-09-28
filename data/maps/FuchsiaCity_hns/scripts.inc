FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "巴奥巴$"

FuchsiaCity_Text_Baoba:
	.string "园长巴奥巴：{PLAYER}！\p"
	.string "我是园长巴奥巴。\p"
	.string "出大事了！我在浅红市的老狩猎地带\n"
	.string "被人收购并且重新开张了！\p"
	.string "而且据说里面有来自异国的新宝可\n"
	.string "梦！\p"
	.string "这严重影响了我的生意！\p"
	.string "{PLAYER}，你一定要去那个\n"
	.string "新的狩猎地带，抓一只宝可梦来给我\l"
	.string "看看。我必须弄清那些“异国”宝可\l"
	.string "梦的底细。\p"
	.string "拜托了{PLAYER}，我的生意\n"
	.string "全靠你了！$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "四天王中的一位，曾经是浅红道馆的\n"
	.string "馆主。$"

FuchsiaCity_Text_PokefanM:
	.string "阿桔加入四天王后，他的女儿接替了\n"
	.string "他成为道馆馆主。$"

FuchsiaCity_Text_Teacher:
	.string "狩猎地带换了新的管理者。\p"
	.string "而且里面有好多新的宝可梦呢！$"

FuchsiaCity_Text_Sign:
	.string "浅红市\p"
	.string "看啊！这热情的粉红！$"

FuchsiaCity_Text_GymSign:
	.string "浅红市宝可梦道馆馆主：阿杏\p"
	.string "剧毒的忍者大师$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "这里贴着一张告示......\p"
	.string "狩猎地带事务局暂时关闭，开放时间\n"
	.string "另行通知。$"

FuchsiaCity_Text_SafariZone:
	.string "狩猎地带现归属于得文公司$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "园长出远门去海外旅行了。\p"
	.string "因此，狩猎地带暂时关闭。$"

FuchsiaCity_Text_NoLitteringSign:
	.string "请勿乱扔垃圾。\p"
	.string "请随身带走您的废弃物。$"

