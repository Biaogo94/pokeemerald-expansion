Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_HILLARY_2_HNS, Route15_EventScript_RematchHillaryTryGiveItem
	end

Route15_EventScript_RematchHillaryTryGiveItem::
	checkitem ITEM_TM_ENERGY_BALL
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_ENERGY_BALL
	closemessage
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP_HNS, Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY_HNS, Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY_HNS, Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY_HNS, Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten, Route15_EventScript_RegisterBilly
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBilly
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBilly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY_HNS
	release
	end

Route15_EventScript_RematchBilly::
	trainerbattle_rematch TRAINER_BILLY_HNS, Route15_Text_BillyRematchIntro, Route15_Text_BillyRematchDefeat
	msgbox Route15_Text_BillyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_BILLY_2_HNS, Route15_EventScript_RematchBillyTryGiveItem
	end

Route15_EventScript_RematchBillyTryGiveItem::
	checkitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_FACADE
	closemessage
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "你有没有落下什么东西？$"

Route15_Text_TeacherColetteBeaten:
	.string "呀啊--！$"

Route15_Text_TeacherColetteAfterBattle:
	.string "在当老师之前，我也经常丢三落四的\n"
	.string "。$"

Route15_Text_TeacherHillarySeen:
	.string "大晴天的时候，孩子们比起在教室里\n"
	.string "学习，应该更想在操场上奔跑玩耍吧\l"
	.string "。$"

Route15_Text_TeacherHillaryBeaten:
	.string "我本来不想输的......$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "学习固然重要，但体育锻炼也同样不\n"
	.string "可或缺哦。$"

Route15_Text_HillaryRegister:
	.string "你可真给我上了一课！能告诉我你的\n"
	.string "电话号码吗？$"

Route15_Text_HillaryRematchIntro:
	.string "这次由我来给你上一课！$"

Route15_Text_HillaryRematchDefeat:
	.string "得从头再学起啦......$"

Route15_Text_HillaryPostRematch:
	.string "培育宝可梦就跟教导小孩子一样，必\n"
	.string "须要有耐心！$"

Route15_Text_SchoolboyKippSeen:
	.string "等等，我得先给我妈妈打个电话。$"

Route15_Text_SchoolboyKippBeaten:
	.string "对不起，妈妈！我打输了！$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "我妈妈总是特别担心我，所以我随时\n"
	.string "都得跟她通个电话。$"

Route15_Text_SchoolboyTommySeen:
	.string "来对战吧！我可不会输！$"

Route15_Text_SchoolboyTommyBeaten:
	.string "我忘了写作业啦！$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Sayonara! I just learned that in\n"
	.string "my Japanese class.$"

Route15_Text_SchoolboyJohnnySeen:
	.string "我们的社会实践课是要去紫苑广播电\n"
	.string "台参观哦。$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "你也太强了吧！$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "走得累死我了。我得歇一会儿。$"

Route15_Text_SchoolboyBillySeen:
	.string "我最喜欢的课就是体育课！$"

Route15_Text_SchoolboyBillyBeaten:
	.string "天啊！我怎么会输？$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "如果学校里有宝可梦这一门课，我肯\n"
	.string "定是第一名！$"

Route15_Text_BillyRegister:
	.string "看来我上课得多听讲才行了。能把你\n"
	.string "的电话号码告诉我吗？$"

Route15_Text_BillyRematchIntro:
	.string "我一直都在用功学习！让你见识一下\n"
	.string "我的学习成果！$"

Route15_Text_BillyRematchDefeat:
	.string "我还得多多用功才行......$"

Route15_Text_BillyPostRematch:
	.string "光读死书可不行，我还欠缺对战经验\n"
	.string "啊！$"

Route15_Text_Sign:
	.string "15号道路\p"
	.string "浅红市 - 紫苑镇$"

