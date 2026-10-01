ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
	.string "大木$"

ViridianCity_Text_OakCall:
	.string "大木博士：啊，{PLAYER}！\p"
	.string "你有空的时候，请来一趟真新镇的研\n"
	.string "究所吧。$"

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "喂，小鬼！我刚喝了双份浓缩咖啡，\n"
	.string "现在精神头足得很！\p"
	.string "我正想找人聊聊呢，就你了吧！\p"
	.string "虽然我现在看起来平平无奇，但我以\n"
	.string "前可是抓宝可梦的名手呢。\p"
	.string "你相信吗？$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "很好，很好。跟你说，我年轻时可真\n"
	.string "不是一般人啊！$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "什么？你这个不知天高地厚的小鬼！\p"
	.string "要是我再年轻几岁，非得让你见识见\n"
	.string "识不可。哼！$"

ViridianCity_Text_GrampsNearGym:
	.string "这家道馆直到最近都还没有馆主呢。\p"
	.string "后来有个来自真新镇的年轻人当上了\n"
	.string "馆主，不过他经常不在。$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "你要去挑战道馆馆主吗？\p"
	.string "祝你好运，你肯定会需要运气的。$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "……呼--噜--......\p"
	.string "哈欠--！\p"
	.string "不知不觉在太阳底下睡着了。\p"
	.string "怎么？我让你想起谁了吗？\p"
	.string "我也不清楚，喏，这个给你吧。$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "……呼--噜--......$"

ViridianCity_Text_DreamEaterFisher:
	.string "哈欠--！\p"
	.string "不知不觉在太阳底下睡着了。\p"
	.string "……我刚才做了个梦，梦见一只催眠貘\n"
	.string "吃掉了我的梦。很奇怪吧？\p"
	.string "咦？这是什么？\p"
	.string "这张招式学习器是从哪来的？\p"
	.string "真邪门！喏，这招式学习器就送给你\n"
	.string "吧。$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "招式学习器42里面是“食梦”......\p"
	.string "……呼--噜--......$"

ViridianCity_Text_Youngster:
	.string "听说常青森林的地上掉落着不少道具\n"
	.string "呢。$"

ViridianCity_Text_Sign:
	.string "常青市\p"
	.string "绿意常在的常青乐土$"

ViridianCity_Text_GymSign:
	.string "常青市宝可梦道馆馆主：......\p"
	.string "后面的文字模糊不清，看不清了...\n"
	.string "...$"

ViridianCity_Text_WelcomeSign:
	.string "常青市欢迎你，\p"
	.string "通往石英高原的玄关$"

ViridianCity_Text_TrainerHouseSign:
	.string "训练家之舍\p"
	.string "顶级训练家对战俱乐部$"
