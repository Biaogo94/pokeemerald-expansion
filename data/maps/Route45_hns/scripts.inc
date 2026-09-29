Route45_hns_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK_HNS, Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL_HNS, Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY_HNS, Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten, Route45_EventScript_RegisterParry
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchParry
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterParry::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_ParryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PARRY_HNS
	release
	end

Route45_EventScript_RematchParry::
	trainerbattle_rematch TRAINER_PARRY_HNS, Route45_Text_ParryRematchIntro, Route45_Text_ParryRematchDefeat
	msgbox Route45_Text_ParryPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_HNS, Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI_HNS, Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten, Route45_EventScript_RegisterKenji
	goto_if_set FLAG_KENJI_HAS_ITEM_HNS, Route45_EventScript_KenjiGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchKenji
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterKenji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_KenjiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENJI_HNS
	release
	end

Route45_EventScript_RematchKenji::
	trainerbattle_rematch TRAINER_KENJI_HNS, Route45_Text_KenjiRematchIntro, Route45_Text_KenjiRematchDefeat
	msgbox Route45_Text_KenjiPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiGiveItem::
	msgbox Route45_Text_KenjiHasItem, MSGBOX_DEFAULT
	giveitem VAR_KENJI_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route45_EventScript_KenjiNoRoom
	clearflag FLAG_KENJI_HAS_ITEM_HNS
	msgbox Route45_Text_KenjiGaveItem, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiNoRoom::
	msgbox Route45_Text_KenjiNoRoom, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN_HNS, Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY_HNS, Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN_HNS, Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "无论何时都要做好万全的准备！\p"
    .string "让我看看你的宝可梦有没有被好好培\n"
    .string "育吧！$"

Route45_Text_HikerErikBeaten:
    .string "哎呀，我输掉了！$"

Route45_Text_HikerErikAfter:
    .string "我要回烟墨市那边的冰雪小径再好好\n"
    .string "修行一番。$"

Route45_Text_HikerMichaelSeen:
    .string "哟！你挺有干劲的嘛！不过你知道\n"
    .string "吗？\p"
    .string "要说干劲冲天，我可不会输给任何\n"
    .string "人！$"

Route45_Text_HikerMichaelBeaten:
    .string "我的宝可梦干劲还不够足啊！$"

Route45_Text_HikerMichaelAfter:
    .string "哎呀，我真是太喜欢HP增强剂了！\n"
    .string "嗯~美味！\p"
    .string "我总忍不住喝掉宝可梦的那份！\p"
    .string "根本停不下来啊！$"

Route45_Text_HikerParrySeen:
    .string "我的宝可梦可是充满了力量！$"

Route45_Text_HikerParryBeaten:
    .string "哇哈哈哈！我输得彻彻底底！$"

Route45_Text_HikerParryAfter:
    .string "我这人不太擅长动脑筋，明白吧？\p"
    .string "所以只要靠蛮力一路猛冲就行了！$"

Route45_Text_ParryRegister:
    .string "我这人不太擅长动脑筋，明白吧？\p"
    .string "所以只要靠蛮力一路猛冲就行了！$"

Route45_Text_ParryRematchIntro:
    .string "我的宝可梦可是充满了力量！$"

Route45_Text_ParryRematchDefeat:
    .string "哇哈哈哈！我输得彻彻底底！$"

Route45_Text_ParryPostRematch:
    .string "我这人不太擅长动脑筋，明白吧？\p"
    .string "所以只要靠蛮力一路猛冲就行了！$"

Route45_Text_HikerTimothySeen:
    .string "我为什么登山？\p"
    .string "因为山就在那里。\p"
    .string "我为什么培育宝可梦？\p"
    .string "因为它们就在那里！$"

Route45_Text_HikerTimothyBeaten:
    .string "失败……也是无法避免的啊\n"
    .string "！$"

Route45_Text_HikerTimothyAfter:
    .string "发生在我身上最棒的事，就是与宝可\n"
    .string "梦相遇。$"

Route45_Text_HikerParryGivesIron:
    .string "我就是找不到获胜的方法！\p"
    .string "继续加油吧！\p"
    .string "哦对了，收下这个吧--这是上次见\n"
    .string "面时你包满没能拿走的礼物。$"

Route45_Text_BlackbeltKenjiSeen:
    .string "我一直独自在此修行。\p"
    .string "见识一下我苦修的成果吧！$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "哇啊啊啊！$"

Route45_Text_BlackbeltKenjiAfter:
    .string "看来必须采取非常手段了。\p"
    .string "我得隐入深山，独自闭关苦修。$"

Route45_Text_KenjiRegister:
    .string "看来必须采取非常手段了。\p"
    .string "我得隐入深山，独自闭关苦修。$"

Route45_Text_KenjiRematchIntro:
    .string "我一直独自在此修行。\p"
    .string "见识一下我苦修的成果吧！$"

Route45_Text_KenjiRematchDefeat:
    .string "哇啊啊啊！$"

Route45_Text_KenjiPostRematch:
    .string "看来必须采取非常手段了。\p"
    .string "我得隐入深山，独自闭关苦修。$"

Route45_Text_KenjiHasItem:
    .string "喂！我修行正告一段落呢。\p"
    .string "刚才在外面捡到了好东西。来，这个\n"
    .string "送给你！$"

Route45_Text_KenjiGaveItem:
    .string "好好利用它吧！\p"
    .string "我也得回去继续修行了。喝啊啊啊啊\n"
    .string "啊！$"

Route45_Text_KenjiNoRoom:
    .string "嗯，你的包包装满了。\p"
    .string "腾出地方再来找我吧。$"

Route45_Text_BlackbeltKenjiMorning:
    .string "吃午饭前，我还要再修行一会儿。$"

Route45_Text_BlackbeltKenjiNight:
    .string "午饭时我们休息得非常充分，\p"
    .string "现在已经准备好再次出发了！\p"
    .string "我们又要开始修行啦！$"

Route45_Text_CooltrainermRyanSeen:
    .string "关于培育宝可梦，你有什么心得？$"

Route45_Text_CooltrainermRyanBeaten:
    .string "我打心底佩服你。$"

Route45_Text_CooltrainermRyanAfter:
    .string "看得出来，你是在用心培育宝可梦。\p"
    .string "你们之间建立的羁绊，一定会在关键\n"
    .string "时刻助你脱离险境。$"

Route45_Text_CooltrainerfKellySeen:
    .string "你的战斗策略是什么？\p"
    .string "盲目胡乱使用强力招式，可是很愚蠢\n"
    .string "的。$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "好吧，是我输了。$"

Route45_Text_CooltrainerfKellyAfter:
    .string "我并不赞同滥用威力过大的招式。\p"
    .string "虽然我想赢，但我也不想伤害到宝可\n"
    .string "梦。$"

Route45_Text_CamperQuentinSeen:
    .string "我可是超级超级强的！$"

Route45_Text_CamperQuentinBeaten:
    .string "我在训练家之丘的时候明明很强的。\n"
    .string ".....$"

Route45_Text_CamperQuentinAfter:
    .string "你去过训练家之丘吗？\p"
    .string "我在那里可从来没输过，但是...\n"
    .string "...$"

Route45_Text_Sign:
    .string "45号道路前方山路$"
