Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
    .string "哎呀！\p"
    .string "你害我的蚊香蝌蚪跑掉了！你要怎么\n"
    .string "赔我啊？$"

Route44_Text_FisherWilton1Beaten:
    .string "算了，当我没说。$"

Route44_Text_FisherWiltonHugePoliwag:
    .string "刚才跑掉的那只蚊香蝌蚪....\n"
    .string "..可大着呢。\p"
    .string "我发誓它少说也得有5米长！$"

Route44_Text_WiltonRegister:
    .string "刚才跑掉的那只蚊香蝌蚪....\n"
    .string "..可大着呢。\p"
    .string "我发誓它少说也得有5米长！$"

Route44_Text_WiltonRematchIntro:
    .string "哎呀！\p"
    .string "你害我的蚊香蝌蚪跑掉了！你要怎么\n"
    .string "赔我啊？$"

Route44_Text_WiltonRematchDefeat:
    .string "算了，当我没说。$"

Route44_Text_WiltonPostRematch:
    .string "刚才跑掉的那只蚊香蝌蚪....\n"
    .string "..可大着呢。\p"
    .string "我发誓它少说也得有5米长！$"

Route44_Text_WiltonHasItem:
    .string "嘿！我钓上来了个宝可梦以外的玩意\n"
    .string "儿！\p"
    .string "来，这个送给你！$"

Route44_Text_WiltonGaveItem:
    .string "要是我还钓到了别的东西，会再通知\n"
    .string "你的！$"

Route44_Text_WiltonNoRoom:
    .string "嗯，你的包包装满了。\p"
    .string "腾出地方再来找我吧。$"

Route44_Text_FisherEdgarSeen:
    .string "我钓鱼直到筋疲力尽，\p"
    .string "对战也是拼到倒下为止。\p"
    .string "这就是我和我的宝可梦之间的相处之\n"
    .string "道！$"

Route44_Text_FisherEdgarBeaten:
    .string "唔......这不对劲啊。$"

Route44_Text_FisherEdgarAfter:
    .string "这样战绩就是100胜101负了。\p"
    .string "我暂时都不想再对战了。$"

Route44_Text_BirdKeeperVance1Seen:
    .string "你知道传说的鸟宝可梦吗？$"

Route44_Text_BirdKeeperVance1Beaten:
    .string "呼！你可真有一手。$"

Route44_Text_BirdKeeperVanceBirds:
    .string "急冻鸟、闪电鸟和火焰鸟是三只传说\n"
    .string "的鸟宝可梦。\p"
    .string "不过我听说，其实还有其他传说的鸟\n"
    .string "宝可梦呢。$"

Route44_Text_VanceRegister:
    .string "急冻鸟、闪电鸟和火焰鸟是三只传说\n"
    .string "的鸟宝可梦。\p"
    .string "不过我听说，其实还有其他传说的鸟\n"
    .string "宝可梦呢。$"

Route44_Text_VanceRematchIntro:
    .string "你知道传说的鸟宝可梦吗？$"

Route44_Text_VanceRematchDefeat:
    .string "呼！你可真有一手。$"

Route44_Text_VancePostRematch:
    .string "急冻鸟、闪电鸟和火焰鸟是三只传说\n"
    .string "的鸟宝可梦。\p"
    .string "不过我听说，其实还有其他传说的鸟\n"
    .string "宝可梦呢。$"

Route44_Text_PsychicPhilSeen:
    .string "这场我赢定了！$"

Route44_Text_PsychicPhilBeaten:
    .string "啊......居然输得这么彻底.\n"
    .string ".....$"

Route44_Text_PsychicPhilAfter:
    .string "无论何时，拥有坚定的信念都是很重\n"
    .string "要的。$"

Route44_Text_PokemaniacZachSeen:
    .string "为了把稀有的宝可梦弄到手，我什么\n"
    .string "都愿意做！$"

Route44_Text_PokemaniacZachBeaten:
    .string "噢噢，你的宝可梦真是太迷人了。$"

Route44_Text_PokemaniacZachAfter:
    .string "如果宝可梦的颜色和普通的不一样，\n"
    .string "那就更有价值啦。\p"
    .string "咦？你说不是那么回事？$"

Route44_Text_CooltrainermAllenSeen:
    .string "我看你一眼就知道，你是个优秀的训\n"
    .string "练家。\p"
    .string "我很擅长宝可梦对战，而且我看得出\n"
    .string "你也是。$"

Route44_Text_CooltrainermAllenBeaten:
    .string "啧！是我彻底输了。$"

Route44_Text_CooltrainermAllenAfter:
    .string "哇，你收集了好多徽章啊。\p"
    .string "难怪你这么厉害。\p"
    .string "不知道圆朱道馆的小松还在继续修行\n"
    .string "吗？\p"
    .string "他之前可把我修理惨了。$"

Route44_Text_CooltrainerfCybilSeen:
    .string "你看起来很强。\p"
    .string "优秀的训练家总是会本能地去寻找强\n"
    .string "敌。$"

Route44_Text_CooltrainerfCybilBeaten:
    .string "不行！这样完全不行啊。$"

Route44_Text_CooltrainerfCybilAfter:
    .string "经历无数次战斗后，我们都会变得更\n"
    .string "强。\p"
    .string "我也是经过了千锤百炼，才成为如今\n"
    .string "的精英训练家。$"

Route44_Text_Sign1:
    .string "44号道路前方为冰雪小径$"

Route44_Text_Sign2:
    .string "44号道路\p"
    .string "卡吉镇 - 烟墨市$"

