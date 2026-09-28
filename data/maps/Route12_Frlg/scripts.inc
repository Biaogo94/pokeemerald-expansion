Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
	.string "这只宝可梦伸展着四肢舒舒服服地着\n"
	.string "。$"

Text_SnorlaxWokeUp::
	.string "卡比兽醒来了！\p"
	.string "它发动着狂暴的攻击扑了过来！$"

Text_SnorlaxReturnedToMountains::
	.string "卡比兽平静了下来。它打了个大哈欠\n"
	.string "…回山上去了。$"

Text_WantToUsePokeFlute::
	.string "要使用宝可梦笛子吗？$"

Text_PlayedPokeFlute::
	.string "{PLAYER}吹起了宝可梦笛子\n"
	.string "。$"

Route12_Text_NedIntro::
	.string "好！咬钩了！$"

Route12_Text_NedDefeat::
	.string "切！是条小鱼……$"

Route12_Text_NedPostBattle::
	.string "坚持就是胜利！我的鱼线有反应了！$"

Route12_Text_ChipIntro::
	.string "心如止水。钓鱼就是比的耐心。$"

Route12_Text_ChipDefeat::
	.string "那条鱼跑了！$"

Route12_Text_ChipPostBattle::
	.string "用这根好点的钓竿 就可以钓起来更\n"
	.string "好的宝可梦……$"

Route12_Text_JustinIntro::
	.string "我在寻找月之石。你有看到过吗？$"

Route12_Text_JustinDefeat::
	.string "喔啊$"

Route12_Text_JustinPostBattle::
	.string "我的宝可梦需要靠月之石进化。\p"
	.string "我打赌一定会赢的。$"

Route12_Text_LucaIntro::
	.string "电属性就是我的特长。\p"
	.string "海里的宝可梦什么的，我完全不懂。$"

Route12_Text_LucaDefeat::
	.string "忘接插座了！$"

Route12_Text_LucaPostBattle::
	.string "水导电，所以电能打败海里的宝可梦\n"
	.string "。$"

Route12_Text_HankIntro::
	.string "钓鱼白痴VS宝可梦小孩！$"

Route12_Text_HankDefeat::
	.string "太感人了！$"

Route12_Text_HankPostBattle::
	.string "我猜你在你爱好的事情方面很在行。\p"
	.string "我承认你在宝可梦方面赢了我，但在\n"
	.string "垂钓方面你撼动不了我的王座。$"

Route12_Text_ElliotIntro::
	.string "我热爱钓鱼，你可别冤枉了我。\p"
	.string "但是我如果有更多的活可干就更好了\n"
	.string "。$"

Route12_Text_ElliotDefeat::
	.string "事情没那么简单……$"

Route12_Text_ElliotPostBattle::
	.string "没关系。失败不能影响我。$"

Route12_Text_AndrewIntro::
	.string "钓到了什么？\p"
	.string "你永远不能提前知道你钓到了什么！$"

Route12_Text_AndrewDefeat::
	.string "输了！$"

Route12_Text_AndrewPostBattle::
	.string "什么，又是鲤鱼王？\p"
	.string "我钓到的总是它！真的。可它们实在\n"
	.string "太弱了。$"

Route12_Text_RouteSign::
	.string "12号道路 往北到紫苑$"

Route12_Text_SportfishingArea::
	.string "垂钓地带$"

Route12_Text_JesIntro::
	.string "阿重 如果我赢了，我就答应阿谀的\n"
	.string "求婚。$"

Route12_Text_JesDefeat::
	.string "阿重 喔，拜托，为什么不让我们赢\n"
	.string "啊？$"

Route12_Text_JesPostBattle::
	.string "阿重 噢， 阿谀，原谅我，亲爱的\n"
	.string "！$"

Route12_Text_JesNotEnoughMons::
	.string "阿重 阿谀和我，我们会永远在一起\p"
	.string "如果你没有两只宝可梦我们不会和你\n"
	.string "战斗。$"

Route12_Text_GiaIntro::
	.string "阿谀嘿，阿重……\p"
	.string "如果我们赢了，我就要娶你！$"

Route12_Text_GiaDefeat::
	.string "阿谀 喔，这是为什么！$"

Route12_Text_GiaPostBattle::
	.string "阿谀 阿重，你这个笨蛋！你毁了我\n"
	.string "的好事！$"

Route12_Text_GiaNotEnoughMons::
	.string "阿谀我可不能忍受没有我的阿重的战\n"
	.string "斗！\p"
	.string "你还有更多宝可梦吗？$"
