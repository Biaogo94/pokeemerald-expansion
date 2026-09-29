Route50_hns_MapScripts::
	.byte 0

Route50_EventScript_BlackBelt1::
	msgbox Route50_Text_BlackBelt1, MSGBOX_NPC
	end

Route50_Text_BlackBelt1::
	.string "必须在最严苛的环境中磨砺体魄，锤\n"
	.string "炼意志！$"

Route50_EventScript_BlackBelt2::
	msgbox Route50_Text_BlackBelt2, MSGBOX_NPC
	end

Route50_Text_BlackBelt2::
    .string "呼！\p"
    .string "我可没他那么拼命。\p"
    .string "不过在这里除了修行，也确实没别的\n"
    .string "事可做了。$"
  

Route50_EventScript_Wessel::
	goto_if_defeated TRAINER_WESSEL_HNS, Route50_EventScript_WesselAfter
	msgbox Route50_Text_WesselBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_WESSEL_HNS, Route50_EventScript_TryWesselBattle
	end
Route50_EventScript_TryWesselBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, Route50_EventScript_WesselBattle
	end
Route50_EventScript_WesselBattle::
	lock
	msgbox Route50_Text_WesselBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_WESSEL_HNS, Route50_Text_WesselDefeat
	giveitem ITEM_IRON_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox Route50_Text_WesselAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
Route50_EventScript_WesselAfter::
	msgbox Route50_Text_WesselAfter, MSGBOX_NPC
	end

Route50_Text_WesselBefore:
	.string "太不可思议了，是霹雳电球！\p"
	.string "但它看起来居然像是……木\n"
	.string "头做的？\p"
	.string "看来我关于这条道路上栖息着许多钢\n"
	.string "属性宝可梦的假说，又一次被推翻\l"
	.string "了。\p"
	.string "但如果不是这样，我为什么会在这捡\n"
	.string "到这块钢铁石板呢？\p"
	.string "我必须收集更多的数据！$"

Route50_Text_WesselBeforeBattle:
	.string "你想要这块石板？但我还没把它分析\n"
	.string "透彻呢！\p"
	.string "好吧，那就通过对战来决定归属！$"

Route50_Text_WesselDefeat:
	.string "我的假说果然错了……$"

Route50_Text_WesselAfter:
	.string "把石板拿走吧。我现在什么都不想说\n"
	.string "了。$"

Route50_EventScript_Finley::
	goto_if_defeated TRAINER_FINLEY_HNS, Route50_EventScript_FinleyAfter
	msgbox Route50_Text_FinleyBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_FINLEY_HNS, Route50_EventScript_TryFinleyBattle
	end
Route50_EventScript_TryFinleyBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, Route50_EventScript_FinleyBattle
	end
Route50_EventScript_FinleyBattle::
	lock
	msgbox Route50_Text_FinleyBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_FINLEY_HNS, Route50_Text_FinleyDefeat
	giveitem ITEM_DRACO_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox Route50_Text_FinleyAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
Route50_EventScript_FinleyAfter::
	msgbox Route50_Text_FinleyAfter, MSGBOX_NPC
	end

Route50_Text_FinleyBefore:
	.string "村民们对你的态度怎么样？\p"
	.string "他们对待陌生人可能不太友好。\p"
	.string "但是与新的人相遇，可是人生一大乐\n"
	.string "事啊。\p"
	.string "我希望有一天能见到阿渡冠军。\p"
	.string "他是一位传奇的龙使者，就像我一\n"
	.string "样。我是谁？\p"
	.string "哈哈，我是芬利，龙之石板的守护\n"
	.string "者。$"

Route50_Text_FinleyBeforeBattle:
	.string "我知道是舞姬们让你来收集这些石板\n"
	.string "的。\p"
	.string "她们说你很有能耐……但你\n"
	.string "能够战胜我的龙宝可梦吗？$"

Route50_Text_FinleyDefeat:
	.string "我的龙宝可梦们表现得很不错。$"

Route50_Text_FinleyAfter:
	.string "也许你甚至有实力战胜阿渡……\n"
	.string "..$"

Route50_EventScript_Item_ULtraBall::
    finditem ITEM_ULTRA_BALL
    end

Route50_EventScript_Item_Big_Nugget::
    finditem ITEM_BIG_NUGGET
    end

Route50_EventScript_ActivateKleavor::
    lock
    setobjectxyperm LOCALID_ROUTE50_NOBLE_KLEAVOR, 75, 12
    playse SE_M_DETECT
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	dofieldeffectsparkle VAR_TEMP_1, VAR_TEMP_2, 0
	waitfieldeffect FLDEFF_SPARKLE
    playse SE_PIN
    applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_PLAYER
    msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
	closemessage
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
    playbgm MUS_DP_AZURE_FLUTE, FALSE
    delay 200
    fadedefaultbgm
    addobject LOCALID_ROUTE50_NOBLE_KLEAVOR
    clearflag FLAG_HIDE_ROUTE50_NOBLE_KLEAVOR
    applymovement2 LOCALID_ROUTE50_NOBLE_KLEAVOR, Route50_Movement_KleavorEntrance1
    delay 10
    playmoncry SPECIES_KLEAVOR, CRY_MODE_NORMAL
    waitmoncry
    playmoncry SPECIES_KLEAVOR, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_ROUTE50_NOBLE_KLEAVOR, Route50_Movement_KleavorEntrance2
    delay 10
    playse SE_LEDGE
    delay 20
	waitmovement LOCALID_ROUTE50_NOBLE_KLEAVOR
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_ROUTE50_NOBLE_KLEAVOR, 75, 14
    setvar VAR_NOBLE_KLEAVOR, 2
    release
    end

Route50_Movement_KleavorEntrance1:
    jump_in_place_down
    walk_in_place_fast_down
    walk_in_place_fast_down
	step_end

Route50_Movement_KleavorEntrance2:
	jump_2_down
    walk_in_place_slow_down
	walk_in_place_slow_down
	jump_in_place_down
	step_end

Route50_EventScript_Kleavor::
	lock
	faceplayer
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_KLEAVOR, level=80, item=ITEM_SCOPE_LENS, move1_1=MOVE_STONE_AXE, move1_2=MOVE_CROSS_POISON, move1_3=MOVE_LUNGE move1_4=MOVE_FOCUS_ENERGY
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 0, 0, 2, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route50_EventScript_KleavorRan
    bufferspeciesname STR_VAR_1, SPECIES_KLEAVOR
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_INSECT_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE50_NOBLE_KLEAVOR
	setflag FLAG_HIDE_ROUTE50_NOBLE_KLEAVOR
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Route50_EventScript_KleavorRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end


Route50_EventScript_ActivateElectrode::
    lock
    setobjectxyperm LOCALID_ROUTE50_NOBLE_ELECTRODE, 18, 26
    playse SE_M_DETECT
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	dofieldeffectsparkle VAR_TEMP_1, VAR_TEMP_2, 0
	waitfieldeffect FLDEFF_SPARKLE
    playse SE_PIN
    applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_PLAYER
    msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
	closemessage
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
    playbgm MUS_DP_AZURE_FLUTE, FALSE
    delay 200
    fadedefaultbgm
    addobject LOCALID_ROUTE50_NOBLE_ELECTRODE
    clearflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
    applymovement2 LOCALID_ROUTE50_NOBLE_ELECTRODE, Route50_Movement_ElectrodeEntrance1
    delay 10
    playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_ROUTE50_NOBLE_ELECTRODE, Route50_Movement_ElectrodeEntrance2
    delay 10
    playse SE_LEDGE
    delay 20
	waitmovement 0
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	applymovement2 LOCALID_ROUTE50_NOBLE_ELECTRODE, Route50_Movement_ElectrodeEntrance3
	waitmovement LOCALID_ROUTE50_NOBLE_ELECTRODE
	removeobject LOCALID_ROUTE50_NOBLE_ELECTRODE
	delay 20
	setobjectxyperm LOCALID_ROUTE50_NOBLE_ELECTRODE, 14, 31
	addobject LOCALID_ROUTE50_NOBLE_ELECTRODE
	clearflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
    setvar VAR_NOBLE_ELECTRODE, 2
    release
    end

Route50_Movement_ElectrodeEntrance1:
	walk_right
    jump_in_place_right
    walk_in_place_fast_right
    walk_in_place_fast_right
	step_end

Route50_Movement_ElectrodeEntrance2:
	jump_2_right
    walk_in_place_slow_up
	walk_in_place_slow_up
	jump_in_place_down
	step_end

Route50_Movement_ElectrodeEntrance3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route50_EventScript_Electrode::
	lock
	faceplayer
	playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_ELECTRODE_HISUI, level=80, item=ITEM_BRIGHT_POWDER, move1_1=MOVE_FOUL_PLAY, move1_2=MOVE_ELECTRO_BALL, move1_3=MOVE_ENERGY_BALL move1_4=MOVE_CHLOROBLAST
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 3, 1, 0, 3, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route50_EventScript_ElectrodeRan
    bufferspeciesname STR_VAR_1, SPECIES_ELECTRODE_HISUI
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_ZAP_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE50_NOBLE_ELECTRODE
	setflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Route50_EventScript_ElectrodeRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end
