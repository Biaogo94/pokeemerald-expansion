Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "安：我和安妮可是齐心协力的！$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "安与安妮：呜呜......稍微有\n"
	.string "点太强了吧。$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "安：我能明白妹妹和宝可梦心里在想\n"
	.string "什么。$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "安妮：我和安可是齐心协力的！$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "安与安妮：呜呜......稍微有\n"
	.string "点太强了吧。$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "安妮：我们和宝可梦的心情是一样\n"
	.string "的。$"

Route37_Text_PsychicGreg_Seen:
	.string "宝可梦睡着之后就什么也做不了。\p"
	.string "就让我来让你见识见识这有多可怕吧\n"
	.string "！$"

Route37_Text_PsychicGreg_Beaten:
	.string "我输了。好难过啊......$"

Route37_Text_PsychicGreg_After:
	.string "让宝可梦陷入睡眠或麻痹状态，是极\n"
	.string "佳的对战技巧。$"

Route37_Text_Sunny_Meet:
	.string "日夫：你好！\p"
	.string "我是星期兄弟姐妹中的日夫！\p"
	.string "要是你能猜出我最喜欢星期几，我就\n"
	.string "送你一份礼物！$"

Route37_Text_Sunny_GiveGift1:
	.string "别人交代过我，要是碰见你，就把这\n"
	.string "个送给你！$"

Route37_Text_Sunny_GiveGift2:
	.string "别人交代过我，要是碰见你，就把这\n"
	.string "个送给你！$"

Route37_Text_Sunny_GaveGift:
	.string "日夫：那个东西......\p"
	.string "嗯......\p"
	.string "......是什么来着....\n"
	.string "..\p"
	.string "......\p"
	.string "啊！我想起来了！\p"
	.string "让学会电属性招式的宝可梦携带它\n"
	.string "吧。\p"
	.string "月子姐姐说它能提升电属性招式的威\n"
	.string "力！$"

Route37_Text_Sunny_Sunday:
	.string "日夫：我的哥哥姐姐们是月子、火\n"
	.string "男、水木、木男、金美和土子。\p"
	.string "他们都比我大！$"

Route37_Text_Sunny_NotSunday:
	.string "日夫：今天不是星期天吗？唔..\n"
	.string "....我忘了！$"

Route37_Text_Sign:
	.string "37号道路前方为圆朱市$"
