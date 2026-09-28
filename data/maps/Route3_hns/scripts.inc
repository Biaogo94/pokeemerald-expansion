Route3_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS_HNS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN_HNS, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY_HNS, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT_HNS, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "啊！天气还是这么晴朗呢。$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "虽然是大晴天，但我全身都湿透了.\n"
	.string ".....$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "一下雨，火就很难点起来了....\n"
	.string "..$"

Route3_Text_YoungsterWarren_Seen:
	.string "唔......我不知道该怎么办了\n"
	.string "......$"

Route3_Text_YoungsterWarren_Beaten:
	.string "我就知道会输......$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "你看起来很强。\p"
	.string "我之前都不敢向你挑战呢.....\n"
	.string ".$"

Route3_Text_YoungsterJimmy_Seen:
	.string "我能跑得像风一样快！$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "被吹跑了！$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "我一年四季都穿着短裤。\p"
	.string "这就是我的时尚信条。$"

Route3_Text_FirebreatherBurt_Seen:
	.string "走过路过，快来看一眼啦！$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "哇！好烫！$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "关都最厉害的喷火艺人，就是本大爷\n"
	.string "我啦。\p"
	.string "不过可算不上是最厉害的训练家..\n"
	.string "....$"

Route3_Text_MtMoonSquareSign:
	.string "月见山广场\p"
	.string "走上台阶即到。$"

