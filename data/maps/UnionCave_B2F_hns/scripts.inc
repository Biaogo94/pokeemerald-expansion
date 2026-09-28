UnionCave_B2F_hns_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK_HNS, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN_HNS, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA_HNS, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 20
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_B2F_EventScript_Item_MaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "世上有两种人。\p"
	.string "一种是有格调的人，另一种则是没有\n"
	.string "格调的人。\p"
	.string "你是哪种人呢？$"

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "你的格调真是光彩夺目！$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "我承认，你的宝可梦风格绚丽又多姿\n"
	.string "多彩。\p"
	.string "你一定会变得越来越棒的！$"

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "我正在特训。要来过过招吗？$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "呜哇，不行！你实在太厉害了。$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "在变强之前，我还是自己一个人继续\n"
	.string "特训吧。$"

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "只要有我喜欢的宝可梦在，天涯海角\n"
	.string "我都愿意去。\p"
	.string "这才称得上是真正的训练家。$"

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "与其做这个，我还不如去摸摸我的小\n"
	.string "宝贝们！$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "每周只有一次，会有一只宝可梦来到\n"
	.string "水边。\p"
	.string "我好想亲眼见见那只宝可梦啊..\n"
	.string "....$"
