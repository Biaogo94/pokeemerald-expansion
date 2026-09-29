Route30_MrPokemonsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_MRPOKEMON
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, FALSE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "你好呀，你好呀！你就是\n"
	.string "{PLAYER}吧。\p"
	.string "空木博士跟我说过你会过来。$"

MrPokemonHouse_Text_Intro2:
	.string "这就是我想拜托空木博士调查的东\n"
	.string "西。$"

MrPokemonHouse_Text_GotEgg:
	.string "{PLAYER}收下了不思议的蛋\n"
	.string "。$"

MrPokemonHouse_Text_Intro3:
	.string "我认识一对经营宝可梦培育屋的夫\n"
	.string "妇。\p"
	.string "这个蛋就是他们给我的。\p"
	.string "我觉得很有意思，就给空木博士发了\n"
	.string "邮件。\p"
	.string "说到宝可梦的进化，空木博士可是这\n"
	.string "方面的权威啊。$"


MrPokemonHouse_Text_Intro4:
	.string "就连身旁的这位大木博士也是这么认\n"
	.string "可的呢。$"

MrPokemonHouse_Text_Intro5:
	.string "如果我的推断没错的话，空木博士应\n"
	.string "该会知道的。$"

MrPokemonHouse_Text_Heal:
	.string "你要回空木博士那里吗？\p"
	.string "来，让你的宝可梦好好休息一下吧。$"

MrPokemonHouse_Text_DependingOnYou:
	.string "拜托你啦！$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "生活真是美妙啊！总能有新的发现。$"

MrPokemonHouse_Text_OakIntro:
	.string "大木：啊哈！原来你就是\n"
	.string "{PLAYER}！\p"
	.string "我是大木！是一名宝可梦研究员。\p"
	.string "我正好来拜访我的老朋友宝可梦先生\n"
	.string "。\p"
	.string "听说你在帮空木博士跑腿，所以我特\n"
	.string "意在这里等你。\p"
	.string "哦！这是什么？好罕见的宝可梦！\p"
	.string "让我看看……嗯，原来如此\n"
	.string "！\p"
	.string "我明白空木博士为什么会托付你一只\n"
	.string "宝可梦来跑腿了。\p"
	.string "对我和空木博士这样的研究员来说，\n"
	.string "宝可梦就是我们的伙伴。\p"
	.string "他一定是看出了你对待宝可梦充满了\n"
	.string "爱心与关怀。\p"
	.string "……啊！\p"
	.string "你看起来很值得信赖。不知你愿不愿\n"
	.string "意帮我一个忙？\p"
	.string "看到了吗？这是最新型的宝可梦图鉴\n"
	.string "。\p"
	.string "只要是见过或捉到的宝可梦，它都会\n"
	.string "自动记录相关资料。\p"
	.string "这可是高科技的百科全书！\p"
	.string "它能显示栖息地、进化方式以及能学\n"
	.string "会的招式呢。$"

MrPokemonHouse_Text_GetDex:
	.string "{PLAYER}获得了宝可梦图鉴\n"
	.string "！$"

MrPokemonHouse_Text_OakParting:
	.string "去邂逅各种各样的宝可梦，完成那本\n"
	.string "宝可梦图鉴吧！\p"
	.string "哎呀，我在这里耽搁太久了。\p"
	.string "我还得赶去满金市录制常规的广播节\n"
	.string "目呢。\p"
	.string "{PLAYER}，就拜托你了！$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "嗯？那片鳞片！那是……？\n"
	.string "红色暴鲤龙的鳞片？！\p"
	.string "太罕见了！我、好想得到它……\n"
	.string "..\p"
	.string "{PLAYER}，你愿意跟我交换\n"
	.string "吗？\p"
	.string "我可以把从大木博士那里得到的学习\n"
	.string "装置换给你！$"

MrPokemonHouse_Text_Disappointed:
	.string "真让人失望啊。那可是非常罕见的东\n"
	.string "西呢。$"

MrPokemonHouse_Text_ExpShare:
	.string "我这里也有件特别的物品要给你。$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "塞满了外国的杂志。\p"
	.string "连标题都看不懂……$"

MrPokemonHouse_Text_BrokenComputer:
	.string "一台大电脑。唔……好像坏\n"
	.string "掉了。$"

MrPokemonHouse_Text_StrangeCoins:
	.string "堆成小山的奇怪硬币！\p"
	.string "说不定是外国的钱币……$"

MrPokemonHouse_Text_GotExpShare:
	.string "{PLAYER}获得了学习装置！$"
