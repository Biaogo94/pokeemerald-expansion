UnionCave_B1F_hns_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP_HNS, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD_HNS, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW_HNS, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN_HNS, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "好久没见到其他人了。\p"
	.string "别客气，来对战吧！$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "呜呃呃……$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "我已经迷路很久了……\p"
	.string "待在这里倒无所谓，但我肚子真--的\n"
	.string "好饿啊！$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "哎呀真稀奇！竟然有客人来！$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "哇哈哈！你可真够带劲的！$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "我就住在这下面。\p"
	.string "你想的话也可以住下哦。\p"
	.string "你看，这里的空地方多得很。$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "是谁在那儿？\p"
	.string "别来打扰我和我的宝可梦！$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "走……快走开！$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "只有我和宝可梦相伴，我已经乐得找\n"
	.string "不着北了。$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "我大老远跑到这里来进行宝可梦研\n"
	.string "究。\p"
	.string "就让我在实战中展现一下我的研究成\n"
	.string "果吧！$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "反被你好好上了一课！$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "我得好好整理并发表我的研究成果。\p"
	.string "说不定还能像空木博士那样变得赫赫\n"
	.string "有名呢。$"
