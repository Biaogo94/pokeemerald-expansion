Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "黑暗穴......\p"
	.string "如果有宝可梦能把里面照亮，我也想\n"
	.string "去探索一番呢。$"

Route31_Text_BugCatcherWade1_Seen:
	.string "我抓了好多宝可梦。来和我对战吧！$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "啊啊啊啊......$"

Route31_Text_BugCatcherWade1_After:
	.string "就算随身带了6只宝可梦，也一样可\n"
	.string "以捕捉新的宝可梦哦。\p"
	.string "抓到的宝可梦会自动传送到你的盒子\n"
	.string "里。$"

Route31_Text_SleepyMan:
	.string "......呼噜噜......嗯\n"
	.string "？\p"
	.string "今天为了找宝可梦，走得太远了。\p"
	.string "脚好酸，好困啊......\p"
	.string "如果我是野生宝可梦，肯定一下就被\n"
	.string "捉住了吧......\p"
	.string "......呼--呼--....\n"
	.string "..$"

Route31_Text_SleepyManGotMail:
	.string "......呼--......嗯\n"
	.string "？\p"
	.string "那是什么？你有邮件要给我吗？$"

Route31_Text_SleepyManFail:
	.string "......呼--呼--....\n"
	.string "..$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER}交出了携带邮件的\n"
	.string "宝可梦。$"

Route31_Text_ReadingMail:
	.string "我来看看......\p"
	.string "谢谢你特地送来给我。\p"
	.string "我朋友真是个大好人，你也是个热心\n"
	.string "肠！\p"
	.string "我也得好好报答你一下！\p"
	.string "有了！这个就送给你吧！$"

Route31_Text_DescribeRest:
	.string "......呼--......\p"
	.string "......唔......睡觉！\p"
	.string "“睡一觉就能恢复体力”，所以才叫\n"
	.string "“睡觉”，明白吗？\p"
	.string "这是一个在睡眠中恢复HP的招式\n"
	.string "哦。$"

Route31_Text_WrongMail:
	.string "这封邮件不是给我的。$"

Route31_Text_MissingMail:
	.string "这只宝可梦有什么特别的吗？\p"
	.string "上面根本没有携带邮件呀。$"

Route31_Text_DeclinedToHandOverMail:
	.string "什么？你什么都不想要吗？$"

Route31_Text_CantTakeLastMon:
	.string "如果我把那只宝可梦收下了，\p"
	.string "你接下来要用什么去战斗呢？$"

Route31_Text_Youngster:
	.string "我在黑暗穴抓到了一只很棒的宝可梦\n"
	.string "。\p"
	.string "我打算好好培育它，再去挑战阿速。\p"
	.string "他就是桔梗道馆的馆主哦。$"

Route31_Text_Sign:
	.string "31号道路\p"
	.string "桔梗市 - 吉花市$"

Route31_Text_WadeRegister:
	.string "你真厉害！我很中意你！\p"
	.string "我每天都在这里寻找宝可梦。\p"
	.string "钻草丛的时候，总能发现各种各样的\n"
	.string "树果。\p"
	.string "如果你喜欢的话，我就分你一些吧。$"

Route31_Text_WadeRematchIntro:
	.string "我可等你好久了。来对战吧！$"

Route31_Text_WadeRematchDefeat:
	.string "啊啊啊啊......$"

Route31_Text_WadePostRematch:
	.string "只要我一找到你可能会喜欢的东西，\n"
	.string "就会立刻联系你！$"

Route31_Text_WadeHasItem:
	.string "嘿！我正找你呢！\p"
	.string "我在草丛里发现了好东西。\p"
	.string "给你，拿去吧！$"

Route31_Text_WadeGaveItem:
	.string "如果再找到别的东西，我还会通知你\n"
	.string "的！$"

Route31_Text_WadeNoRoom:
	.string "唔，看起来你的背包已经满了。\p"
	.string "等整理出空位再来找我吧！$"

Route31_Text_DarkCaveSign:
	.string "黑暗穴$"
