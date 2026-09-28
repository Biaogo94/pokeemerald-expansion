NewSinjoh_HotSprings_hns_MapScripts::
	.byte 0

NewSinjoh_HotSprings_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

NewSinjoh_HotSprings_EventScript_Item_LavaCookie::
    finditem ITEM_LAVA_COOKIE
    end

NewSinjoh_HotSprings_EventScript_Mualani::
	goto_if_defeated TRAINER_MUALANI_HNS, NewSinjoh_HotSprings_EventScript_MualaniAfter
	msgbox NewSinjoh_HotSprings_Text_MualaniBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_MUALANI_HNS, NewSinjoh_HotSprings_EventScript_TryMualaniBattle
	end
NewSinjoh_HotSprings_EventScript_TryMualaniBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, NewSinjoh_HotSprings_EventScript_MualaniBattle
	end
NewSinjoh_HotSprings_EventScript_MualaniBattle::
	lock
	msgbox NewSinjoh_HotSprings_Text_MualaniBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MUALANI_HNS, NewSinjoh_HotSprings_Text_MualaniDefeat
	giveitem ITEM_SPLASH_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox NewSinjoh_HotSprings_Text_MualaniAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
NewSinjoh_HotSprings_EventScript_MualaniAfter::
	msgbox NewSinjoh_HotSprings_Text_MualaniAfter, MSGBOX_NPC
	end

NewSinjoh_HotSprings_Text_MualaniBefore:
	.string "问我是本地人还是游客？真没礼貌！\p"
	.string "非要问的话，我是本地人。\p"
	.string "我的家族可是最早享用这片温泉的。\p"
	.string "你看，我甚至有这块水滴石板为证呢\n"
	.string "。$"

NewSinjoh_HotSprings_Text_MualaniBeforeBattle:
	.string "等等......\p"
	.string "你需要用水滴石板去平息传说的宝可\n"
	.string "梦？\p"
	.string "既然舞姬们都认可了你的实力，那我\n"
	.string "也不多说了。\p"
	.string "不过，你还是得靠本事来赢取它。$"

NewSinjoh_HotSprings_Text_MualaniDefeat:
	.string "这是你应得的。$"

NewSinjoh_HotSprings_Text_MualaniAfter:
	.string "要割舍那块石板，对我来说确实不易\n"
	.string "。\p"
	.string "但世事变迁，我们自身也必须顺应改\n"
	.string "变才行。\p"
	.string "这块石板就归你了。$"


NewSinjoh_HotSprings_EventScript_Sign1::
    msgbox NewSinjoh_HotSprings_Text_Sign1, MSGBOX_SIGN
    end

NewSinjoh_HotSprings_Text_Sign1:
    .string "新神都温泉$"

NewSinjoh_HotSprings_EventScript_Sign2::
    msgbox NewSinjoh_HotSprings_Text_Sign2, MSGBOX_SIGN
    end

NewSinjoh_HotSprings_Text_Sign2:
    .string "危险野生宝可梦冬眠巢穴$"

NewSinjoh_HotSprings_EventScript_SkierF::
    msgbox NewSinjoh_HotSprings_Text_SkierF, MSGBOX_NPC
    end

NewSinjoh_HotSprings_Text_SkierF:
	.string "我最讨厌冷天了！\p"
	.string "我来这儿完全就是为了泡温泉！$"

NewSinjoh_HotSprings_EventScript_SkierM::
    msgbox NewSinjoh_HotSprings_Text_SkierM, MSGBOX_NPC
    end

NewSinjoh_HotSprings_Text_SkierM:
	.string "我本来是想来滑雪板的，可我女朋友\n"
	.string "却只想一整天都泡在温泉里！$"


NewSinjoh_HotSprings_EventScript_OldLady::
    msgbox NewSinjoh_HotSprings_Text_OldLady, MSGBOX_NPC
    end

NewSinjoh_HotSprings_Text_OldLady:
	.string "别理我丈夫。\p"
	.string "让所有的烦恼都随温水消散吧。$"

NewSinjoh_HotSprings_EventScript_CreepyMan::
	msgbox NewSinjoh_HotSprings_Text_CreepyMan, MSGBOX_NPC
	end

NewSinjoh_HotSprings_Text_CreepyMan:
	.string "呼啊......\p"
	.string "这泉水泡得我后背太舒服了，简直像\n"
	.string "有魔力一样。\p"
	.string "要是你也腰酸背痛的话，不妨留下来\n"
	.string "和我一起多泡泡......$"

NewSinjoh_HotSprings_EventScript_PLATutor::
	lock
	faceplayer
	msgbox NewSinjoh_HotSprings_Text_PLATutorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewSinjoh_HotSprings_EventScript_PLATutorDecline
	message NewSinjoh_HotSprings_Text_PLATutorChoose
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, NewSinjoh_HotSprings_Text_PLAMove_PowerShift, NewSinjoh_HotSprings_Text_PLAMove_SpringtideStorm, NewSinjoh_HotSprings_Text_PLAMove_MysticalPower, NewSinjoh_HotSprings_Text_PLAMove_WaveCrash, NewSinjoh_HotSprings_Text_PLAMove_MountainGale, NewSinjoh_HotSprings_Text_PLAMove_VictoryDance, NewSinjoh_HotSprings_Text_PLAMove_EsperWing, NewSinjoh_HotSprings_Text_PLAMove_BitterMalice, NewSinjoh_HotSprings_Text_PLAMove_Shelter, NewSinjoh_HotSprings_Text_PLAMove_BleakwindStorm, NewSinjoh_HotSprings_Text_PLAMove_WildboltStorm, NewSinjoh_HotSprings_Text_PLAMove_SandsearStorm, NewSinjoh_HotSprings_Text_PLAMove_LunarBlessing, NewSinjoh_HotSprings_Text_PLAMove_TakeHeart, NewSinjoh_HotSprings_Text_PLAMove_Cancel
	switch VAR_RESULT
	case 0, NewSinjoh_HotSprings_EventScript_PLATeach_PowerShift
	case 1, NewSinjoh_HotSprings_EventScript_PLATeach_SpringtideStorm
	case 2, NewSinjoh_HotSprings_EventScript_PLATeach_MysticalPower
	case 3, NewSinjoh_HotSprings_EventScript_PLATeach_WaveCrash
	case 4, NewSinjoh_HotSprings_EventScript_PLATeach_MountainGale
	case 5, NewSinjoh_HotSprings_EventScript_PLATeach_VictoryDance
	case 6, NewSinjoh_HotSprings_EventScript_PLATeach_EsperWing
	case 7, NewSinjoh_HotSprings_EventScript_PLATeach_BitterMalice
	case 8, NewSinjoh_HotSprings_EventScript_PLATeach_Shelter
	case 9, NewSinjoh_HotSprings_EventScript_PLATeach_BleakwindStorm
	case 10, NewSinjoh_HotSprings_EventScript_PLATeach_WildboltStorm
	case 11, NewSinjoh_HotSprings_EventScript_PLATeach_SandsearStorm
	case 12, NewSinjoh_HotSprings_EventScript_PLATeach_LunarBlessing
	case 13, NewSinjoh_HotSprings_EventScript_PLATeach_TakeHeart
	case 14, NewSinjoh_HotSprings_EventScript_PLATutorDecline
	case MULTI_B_PRESSED, NewSinjoh_HotSprings_EventScript_PLATutorDecline
	end

NewSinjoh_HotSprings_EventScript_PLATeach_PowerShift::
	setvar VAR_0x8005, MOVE_POWER_SHIFT
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_SpringtideStorm::
	setvar VAR_0x8005, MOVE_SPRINGTIDE_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_MysticalPower::
	setvar VAR_0x8005, MOVE_MYSTICAL_POWER
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_WaveCrash::
	setvar VAR_0x8005, MOVE_WAVE_CRASH
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_MountainGale::
	setvar VAR_0x8005, MOVE_MOUNTAIN_GALE
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_VictoryDance::
	setvar VAR_0x8005, MOVE_VICTORY_DANCE
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_EsperWing::
	setvar VAR_0x8005, MOVE_ESPER_WING
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_BitterMalice::
	setvar VAR_0x8005, MOVE_BITTER_MALICE
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_Shelter::
	setvar VAR_0x8005, MOVE_SHELTER
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_BleakwindStorm::
	setvar VAR_0x8005, MOVE_BLEAKWIND_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_WildboltStorm::
	setvar VAR_0x8005, MOVE_WILDBOLT_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_SandsearStorm::
	setvar VAR_0x8005, MOVE_SANDSEAR_STORM
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_LunarBlessing::
	setvar VAR_0x8005, MOVE_LUNAR_BLESSING
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeach_TakeHeart::
	setvar VAR_0x8005, MOVE_TAKE_HEART
	goto NewSinjoh_HotSprings_EventScript_PLATeachMove
	end

NewSinjoh_HotSprings_EventScript_PLATeachMove::
	buffermovename STR_VAR_1, VAR_0x8005
	msgbox NewSinjoh_HotSprings_Text_PLATutorConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewSinjoh_HotSprings_EventScript_PLATutor
	msgbox NewSinjoh_HotSprings_Text_PLATutorWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	chooseboxmon SELECT_PC_MON_PLA_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_HotSprings_EventScript_PLATutorCancelMon
	msgbox NewSinjoh_HotSprings_Text_PLATutorDone, MSGBOX_DEFAULT
	release
	end

NewSinjoh_HotSprings_EventScript_PLATutorCancelMon::
	msgbox NewSinjoh_HotSprings_Text_PLATutorComeBack, MSGBOX_DEFAULT
	release
	end

NewSinjoh_HotSprings_EventScript_PLATutorDecline::
	msgbox NewSinjoh_HotSprings_Text_PLATutorComeBack, MSGBOX_DEFAULT
	release
	end

NewSinjoh_HotSprings_Text_PLATutorIntro:
	.string "远古的力量在这些泉水中流淌。\p"
	.string "我可以传授你的宝可梦来自那个被遗\n"
	.string "忘时代的古老招式。\p"
	.string "有兴趣吗？$"

NewSinjoh_HotSprings_Text_PLATutorChoose:
	.string "你想学哪个招式？$"

NewSinjoh_HotSprings_Text_PLATutorConfirm:
	.string "想要学习{STR_VAR_1}吗\n"
	.string "？$"

NewSinjoh_HotSprings_Text_PLATutorWhichMon:
	.string "要让哪只宝可梦学习呢？$"

NewSinjoh_HotSprings_Text_PLATutorDone:
	.string "搞定！你的宝可梦已经掌握了这门古\n"
	.string "老的秘技。$"

NewSinjoh_HotSprings_Text_PLATutorComeBack:
	.string "欢迎随时再来。$"

NewSinjoh_HotSprings_Text_PLAMove_VictoryDance:
	.string "胜利之舞$"

NewSinjoh_HotSprings_Text_PLAMove_MountainGale:
	.string "冰山风$"

NewSinjoh_HotSprings_Text_PLAMove_BitterMalice:
	.string "冤冤相报$"

NewSinjoh_HotSprings_Text_PLAMove_SpringtideStorm:
	.string "阳春风暴$"

NewSinjoh_HotSprings_Text_PLAMove_LunarBlessing:
	.string "新月祈祷$"

NewSinjoh_HotSprings_Text_PLAMove_BleakwindStorm:
	.string "枯叶风暴$"

NewSinjoh_HotSprings_Text_PLAMove_WildboltStorm:
	.string "鸣雷风暴$"

NewSinjoh_HotSprings_Text_PLAMove_SandsearStorm:
	.string "热沙风暴$"

NewSinjoh_HotSprings_Text_PLAMove_Shelter:
	.string "闭关$"

NewSinjoh_HotSprings_Text_PLAMove_EsperWing:
	.string "气场之翼$"

NewSinjoh_HotSprings_Text_PLAMove_TakeHeart:
	.string "振奋$"

NewSinjoh_HotSprings_Text_PLAMove_MysticalPower:
	.string "神奇之力$"

NewSinjoh_HotSprings_Text_PLAMove_WaveCrash:
	.string "波动冲$"

NewSinjoh_HotSprings_Text_PLAMove_PowerShift:
	.string "力量转换$"

NewSinjoh_HotSprings_Text_PLAMove_Cancel:
	.string "取消$"


NewSinjoh_HotSprings_EventScript_ActivateArcanine::
    lock
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_ARCANINE, 16, 4
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
    addobject LOCALID_HOTSPRINGS_NOBLE_ARCANINE
    clearflag FLAG_HIDE_HOTSPRINGS_NOBLE_ARCANINE
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_ARCANINE, NewSinjoh_HotSprings_Movement_ArcanineEntrance1
    delay 10
	playse SE_LEDGE
    playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_ARCANINE, NewSinjoh_HotSprings_Movement_ArcanineEntrance2
    delay 10
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_NORMAL
    waitmoncry
    playse SE_LEDGE
    delay 20
	waitmovement LOCALID_HOTSPRINGS_NOBLE_ARCANINE
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_ARCANINE, 16, 8
    setvar VAR_NOBLE_ARCANINE, 2
    release
    end

NewSinjoh_HotSprings_Movement_ArcanineEntrance1:
    slide_down
	slide_down
	slide_down
	slide_down
	step_end

NewSinjoh_HotSprings_Movement_ArcanineEntrance2:
    walk_in_place_slow_down
	walk_in_place_slow_down
	jump_in_place_down
	step_end


NewSinjoh_HotSprings_EventScript_Arcanine::
	lock
	faceplayer
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_ENCOUNTER
	waitmoncry
    setwildbossbattle species=SPECIES_ARCANINE_HISUI, level=80, item=ITEM_LOADED_DICE, move1_1=MOVE_ROCK_BLAST, move1_2=MOVE_WILD_CHARGE, move1_3=MOVE_RAGING_FURY move1_4=MOVE_PROTECT
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 2, 0, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewSinjoh_HotSprings_EventScript_ArcanineRan
    bufferspeciesname STR_VAR_1, SPECIES_ARCANINE_HISUI
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_FLAME_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_HOTSPRINGS_NOBLE_ARCANINE
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_ARCANINE
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

NewSinjoh_HotSprings_EventScript_ArcanineRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end






NewSinjoh_HotSprings_EventScript_ActivateUrsaluna::
    lock
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_URSALUNA, 52, 26
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
    addobject LOCALID_HOTSPRINGS_NOBLE_URSALUNA
    clearflag FLAG_HIDE_HOTSPRINGS_NOBLE_URSALUNA
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_URSALUNA, NewSinjoh_HotSprings_Movement_UrsalunaEntrance1
    delay 10
	playse SE_LEDGE
    playmoncry SPECIES_URSALUNA, CRY_MODE_NORMAL
    waitmoncry
    waitmovement 0
    applymovement2 LOCALID_HOTSPRINGS_NOBLE_URSALUNA, NewSinjoh_HotSprings_Movement_UrsalunaEntrance2
    delay 10
	playmoncry SPECIES_URSALUNA, CRY_MODE_NORMAL
    waitmoncry
    playse SE_LEDGE
    delay 20
	waitmovement LOCALID_HOTSPRINGS_NOBLE_URSALUNA
    setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_HOTSPRINGS_NOBLE_URSALUNA, 52, 28
    setvar VAR_NOBLE_URSALUNA, 2
    release
    end

NewSinjoh_HotSprings_Movement_UrsalunaEntrance1:
    jump_in_place_down
    walk_in_place_fast_down
    walk_in_place_fast_down
	step_end

NewSinjoh_HotSprings_Movement_UrsalunaEntrance2:
	jump_2_down
    walk_in_place_slow_down
	walk_in_place_slow_down
	jump_in_place_down
	step_end


NewSinjoh_HotSprings_EventScript_Ursaluna::
	lock
	faceplayer
	playmoncry SPECIES_URSALUNA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_URSALUNA, level=80, item=ITEM_EARTH_PLATE, move1_1=MOVE_EARTHQUAKE, move1_2=MOVE_AVALANCHE, move1_3=MOVE_BULK_UP move1_4=MOVE_GIGA_IMPACT
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 2, 0, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewSinjoh_HotSprings_EventScript_UrsalunaRan
    bufferspeciesname STR_VAR_1, SPECIES_URSALUNA
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_EARTH_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_HOTSPRINGS_NOBLE_URSALUNA
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_URSALUNA
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

NewSinjoh_HotSprings_EventScript_UrsalunaRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end
