Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "这里的水温好暖和。我筋骨都活动开\n"
	.string "了。\p"
	.string "好啊，我来跟你切磋切磋！$"

Route41_Text_SwimmermCharlieBeaten:
	.string "哎呀！手皮都泡皱了！$"

Route41_Text_SwimmermCharlieAfter:
	.string "像这样漂浮在水上，不是很惬意吗？$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "我游得有点累了。如果我赢了，把你\n"
	.string "的宝可梦借我骑骑。$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "呼……哈……$"

Route41_Text_SwimmermGeorgeAfter:
	.string "去湛蓝市还有好远啊。\p"
	.string "可回浅黄市也没那么容易了。\p"
	.string "我该怎么办啊？$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "看到那些被漩涡包围的岛屿了吗？\p"
	.string "那里肯定藏着什么秘密！$"

Route41_Text_SwimmermBerkeBeaten:
	.string "你强大的秘诀究竟是什么？$"

Route41_Text_SwimmermBerkeAfter:
	.string "那是一个漆黑而暴风雨交加的夜晚。\n"
	.string ".....\p"
	.string "我看见一只巨大的宝可梦从岛上飞了\n"
	.string "出来。\p"
	.string "它银色的羽翼上洒下点点光芒。$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "这里的风浪好大啊。\p"
	.string "游起泳来特别耗费体力。$"

Route41_Text_SwimmermKirkBeaten:
	.string "我认输了！$"

Route41_Text_SwimmermKirkAfter:
	.string "海流太急了，我游不到那座岛上去。$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "你也是来探寻漩涡列岛的秘密的吗？$"

Route41_Text_SwimmermMathewBeaten:
	.string "呜哇，你的体力真好！$"

Route41_Text_SwimmermMathewAfter:
	.string "关于漩涡列岛的秘密嘛……\p"
	.string "里面可是黑得伸手不见五指！$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "我正打算前往漩涡列岛。\p"
	.string "准备和朋友们一起去探险。$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "原来是这么对战的吗？$"

Route41_Text_SwimmerfKayleeAfter:
	.string "听说漩涡列岛深处沉睡着一只巨大的\n"
	.string "宝可梦。\p"
	.string "真想知道它到底是什么呀？$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "你乘在宝可梦身上的样子，看起来可\n"
	.string "真优雅。$"

Route41_Text_SwimmerfSusieBeaten:
	.string "我惨败了……$"

Route41_Text_SwimmerfSusieAfter:
	.string "以前是不是有首很火的歌，讲的是一\n"
	.string "个乘着拉普拉斯的少年？$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "天气这么好，我都舒服得发呆了！$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "哎呀--！$"

Route41_Text_SwimmerfDeniseAfter:
	.string "晒伤对皮肤最不好了。\p"
	.string "不过我可不用防晒霜，\p"
	.string "因为我不想污染海水。$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "要是游累了，只要踩踩水歇会儿就\n"
	.string "行。\p"
	.string "缓过气来之后，就能精神抖擞地继续\n"
	.string "游了。$"

Route41_Text_SwimmerfKaraBeaten:
	.string "哎呀！你的体力比我还充沛呢。$"

Route41_Text_SwimmerfKaraAfter:
	.string "我听到了从岛屿深处传来的咆哮声。$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "一到晚上，海星星就会聚集在水面附\n"
	.string "近。$"

Route41_Text_SwimmerfWendyBeaten:
	.string "天哪……$"

Route41_Text_SwimmerfWendyAfter:
	.string "成群的海星星会同时散发出光芒。\p"
	.string "美得甚至让人感到有些害怕。$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "毒刺水母：咕噜噜噜……$"

Route41_Text_TentacruelAttack:
	.string "毒刺水母：咕噜噜噜--！$"

Route41_Text_TentacruelHeal:
	.string "毒刺水母使出了自我再生！体力完全\n"
	.string "恢复了！$"
