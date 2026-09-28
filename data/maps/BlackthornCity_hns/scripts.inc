BlackthornCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	setspeaker BlackthornCity_Text_ElmName
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_ElmName:
	.string "空木博士$"

BlackthornCity_Text_BaobaCall:
	.string "巴奥巴园长：{PLAYER}！\p"
	.string "我是巴奥巴园长。\p"
	.string "我打电话是想通知你，狩猎地带扩建\n"
	.string "了！\p"
	.string "请一定要来看看哦！$"

BlackthornCity_Text_ElmCall:
	.string "空木博士：喂喂，是\n"
	.string "{PLAYER}吗？\p"
	.string "我有样东西想交给你，你能来一趟研\n"
	.string "究所吗？\p"
	.string "待会儿见啦！$"

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
	.string "我们的道馆馆主小椿，一直在关注你\n"
	.string "的表现。\p"
	.string "不过，她只会与已经收集了7枚徽章\n"
	.string "的训练家对战。$"

BlackthornCity_Text_ClairIsIn:
	.string "我们的道馆馆主小椿正在等你。\p"
	.string "不过，泛泛之辈的训练家是绝对赢不\n"
	.string "了她的。$"

BlackthornCity_Text_ClairIsBeaten:
	.string "你打赢了小椿？！\p"
	.string "太不可思议了！\p"
	.string "除了阿渡先生之外，我还没听说过有\n"
	.string "谁能赢过她。$"

BlackthornGrampsRefusesEntryText:
	.string "不行，只有被选中的训练家才能在这\n"
	.string "里修行。\p"
	.string "请回吧。$"

BlackthornGrampsGrantsEntryText:
	.string "既然小椿允许了，她的祖父--也就\n"
	.string "是我们的长老想必也是。\p"
	.string "你可以进去了。$"

BlackBeltText_VoicesInMyHead:
	.string "哇啊--！脑子里有声音！\p"
	.string "咦？原来是我在听收音机啊！$"

BlackthornCooltrainerF1Text:
	.string "你是打算让你的宝可梦回忆起招式吗\n"
	.string "？$"

BlackthornYoungsterText:
	.string "所有的龙属性大师，都是出自烟墨市\n"
	.string "哦。$"

BlackthornCity_MeetSantosText:
	.string "土夫：......\p"
	.string "我是星期兄弟姐妹里的土夫。\p"
	.string "猜猜看是星期几......$"

BlackthornCity_SantosGivesGiftText:
	.string "这个给你......$"

BlackthornCity_SantosGaveGiftText:
	.string "土夫：......\p"
	.string "诅咒之符......\p"
	.string "能提升幽灵属性招式的威力....\n"
	.string "..\p"
	.string "可别被吓到了......$"

BlackthornCity_SantosSaturdayText:
	.string "土夫：......\p"
	.string "等下个星期六再见吧......\p"
	.string "不过我不会再送礼物了......$"

BlackthornCity_SantosNopeText:
	.string "土夫：不是。$"

BlackthornCooltrainerF2Text:
	.string "哇，你是穿过冰之通路过来的吗？\p"
	.string "那你一定是个身手不凡的训练家！$"

BlackthornCitySignText:
	.string "烟墨市\p"
	.string "群山环抱的静谧山居$"

BlackthornGymSignText:
	.string "烟墨市宝可梦道馆馆主：小椿\p"
	.string "圣洁的龙属性宝可梦使者$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "招式专家之家$"

BlackthornCity_Text_DragonDenSign:
	.string "前方 龙之穴$"

