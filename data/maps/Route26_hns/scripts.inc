Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "我正在为挑战宝可梦联盟做最后的准\n"
    .string "备呢。$"

Route26_Text_CooltrainermJakeBeaten:
    .string "搞砸了！$"

Route26_Text_CooltrainermJakeAfter:
    .string "想要在联盟获胜可真不容易。\p"
    .string "我得再多修行修行才行。\p"
    .string "听说联盟的四天王比道馆馆主还要厉\n"
    .string "害呢。$"

Route26_Text_CooltrainermGavenSeen:
    .string "经历过艰难的对战，才能获得强大的\n"
    .string "力量。$"

Route26_Text_CooltrainermGavenBeaten:
    .string "哇啊！人生可比这还要艰难啊！$"

Route26_Text_CooltrainermGavenAfter:
    .string "要想前往宝可梦联盟，就必须穿过冠\n"
    .string "军之路。\p"
    .string "但是冠军之路非常艰险。\p"
    .string "几乎没有人能去那里！$"

Route26_Text_GavenRegister:
    .string "要想前往宝可梦联盟，就必须穿过冠\n"
    .string "军之路。\p"
    .string "但是冠军之路非常艰险。\p"
    .string "几乎没有人能去那里！$"

Route26_Text_GavenRematchIntro:
    .string "经历过艰难的对战，才能获得强大的\n"
    .string "力量。$"

Route26_Text_GavenRematchDefeat:
    .string "哇啊！人生可比这还要艰难啊！$"

Route26_Text_GavenPostRematch:
    .string "要想前往宝可梦联盟，就必须穿过冠\n"
    .string "军之路。\p"
    .string "但是冠军之路非常艰险。\p"
    .string "几乎没有人能去那里！$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "既然你能走到这里，实力一定非同小\n"
    .string "可。\p"
    .string "这场对战我也会全力以赴的！$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "不！这不可能！$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "我已经打赢了8位道馆馆主，本来还\n"
    .string "挺有自信的。\p"
    .string "看来下次得更加努力才行了。$"

Route26_Text_CooltrainerfBethSeen:
    .string "我输给了一个叫{RIVAL}的训\n"
    .string "练家。\p"
    .string "他确实很强，但是……\p"
    .string "他给人的感觉就像是不择手段也一定\n"
    .string "要赢似的。\p"
    .string "真替他的宝可梦感到难过。$"

Route26_Text_CooltrainerfBethBeaten:
    .string "宝可梦可不是争斗的工具。$"

Route26_Text_CooltrainerfBethAfter:
    .string "宝可梦是无比珍贵、相伴一生的伙伴\n"
    .string "。$"

Route26_Text_BethRegister:
    .string "宝可梦是无比珍贵、相伴一生的伙伴\n"
    .string "。$"

Route26_Text_BethRematchIntro:
    .string "我输给了一个叫{RIVAL}的训\n"
    .string "练家。\p"
    .string "但我可不会再输给你！$"

Route26_Text_BethRematchDefeat:
    .string "宝可梦可不是争斗的工具。$"

Route26_Text_BethPostRematch:
    .string "宝可梦是无比珍贵、相伴一生的伙伴\n"
    .string "。$"

Route26_Text_PsychicRichardSeen:
    .string "哇，瞧瞧你身上这一排徽章！真让人\n"
    .string "佩服。\p"
    .string "不过你不会光收集到徽章就满足了吧\n"
    .string "？$"

Route26_Text_PsychicRichardBeaten:
    .string "精彩的对战！$"

Route26_Text_PsychicRichardAfter:
    .string "人和宝可梦都是从经验中成长的。\p"
    .string "可千万别懈怠自满哦。$"

Route26_Text_Sign:
    .string "26号道路\p"
    .string "宝可梦联盟接待大门$"

