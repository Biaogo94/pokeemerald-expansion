Route33_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY_HNS, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_RegisterAnthony
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_RematchAnthony
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_RegisterAnthony::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route33_Text_AnthonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY_HNS
	release
	end

Route33_EventScript_RematchAnthony::
	trainerbattle_rematch TRAINER_ANTHONY_HNS, Route33_Text_AnthonyRematchIntro, Route33_Text_AnthonyRematchDefeat
	msgbox Route33_Text_AnthonyPostRematch, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "我一路穿过隧道走过来，但还是精力\n"
	.string "充沛呢！$"

Route33_Text_HikerAnthony2Beaten:
	.string "哇！你比我还要有干劲啊！$"

Route33_Text_HikerAnthony2After:
	.string "我们登山男在山里可是最精神的！$"

Route33_Text_AnthonyRegister:
	.string "我们登山男在山里可是最精神的！$"

Route33_Text_AnthonyRematchIntro:
	.string "我一路穿过隧道走过来，但还是精力\n"
	.string "充沛呢！$"

Route33_Text_AnthonyRematchDefeat:
	.string "哇！你比我还要有干劲啊！$"

Route33_Text_AnthonyPostRematch:
	.string "我们登山男在山里可是最精神的！$"

Route33_Text_HikerAnthonyDunsparce:
	.string "嘿，你抓到土龙弟弟了吗？\p"
	.string "我也抓到了一只。\p"
	.string "放到光亮的地方看看吧。它的长相可\n"
	.string "搞笑了！$"

Route33_Text_Lass:
	.string "呼，呼......\p"
	.string "那个洞窟比我想象的还要大。\p"
	.string "为了找玛力露探险累得够呛，所以我\n"
	.string "就先出来了。$"
