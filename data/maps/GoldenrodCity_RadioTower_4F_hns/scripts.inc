GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "兰斯：等等，先别急着走！\p"
	.string "你不是在呆呆兽之井坏我们好事的那\n"
	.string "家伙吗？\p"
	.string "原来如此......看来你是存心\n"
	.string "想要惹怒我啊。真是不知死活！\p"
	.string "既然你这么想见识，那就让你好好尝\n"
	.string "尝火箭队干部的怒火吧！$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "呼......$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "兰斯：这次算你赢了......但\n"
	.string "你所做的一切，\p"
	.string "只会让火箭队的怒火更加猛烈！$"

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "我在遗迹的时候听了收音机。\p"
	.string "在那儿听到了奇怪的广播。$"

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "玛丽：为什么？为什么我要遭这种罪\n"
	.string "啊？\p"
	.string "喵喵，快救救我！$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "玛丽：啊！你真是我的小救星！\p"
	.string "收下这个作为谢礼吧！$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "玛丽：戴上它有助于闪避对手的攻击\n"
	.string "哦。$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "玛丽：请一定要收听《大木博士的宝\n"
	.string "可梦讲座》哦！$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "喵喵：喵~......$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "你打算去救台长？\p"
	.string "别做梦了，因为我要在这里把你打倒\n"
	.string "！$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "怎么会！难以置信！$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "真不敢相信！我居然输了！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "站住！我就是火箭队的铜墙铁壁！\p"
	.string "休想再往前迈进一步！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "要塞被攻破了！$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "我敬佩你的实力，奉劝你一句。\p"
	.string "现在回头还不算晚，趁早离开吧。$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "Don't I think POKéMON are cute?\p"
	.string "I'll think my POKéMON are cute--\p"
	.string "after they beat yours!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "天啊！真没用！$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "我最爱美丽的自己了！\p"
	.string "谁在乎什么宝可梦啊？$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "太棒了。\p"
	.string "这座广播塔将实现我们的宏图大业。$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "唔唔......\p"
	.string "任何宏伟的计划都会遇到波折啊。$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "你真以为自己能阻止得了火箭队吗？$"

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "4楼 制作室$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "4楼 第2录音室$"
