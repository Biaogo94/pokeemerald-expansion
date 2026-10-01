UlaulaIsle_hns_MapScripts::
	.byte 0

Alola_Ulaula_FindItem1::
	finditem ITEM_FRIEND_BALL, 1
	end


Alola_Ulaula_FindItem2::
	finditem ITEM_PROTEIN, 1
	end


Alola_Ulaula_MtLanikalaSign::
	lock
	msgbox Alola_Ulaula_MtLanikalaSign_Text_0
	release
	end


Alola_Ulaula_UlaulaSign::
	lock
	msgbox Alola_Ulaula_UlaulaSign_Text_0
	release
	end


Alola_Ulaula_TapuBulu_Flyover::
	goto_if_set FLAG_FLYOVER_TAPU_BULU, Alola_Ulaula_TapuBulu_Flyover_2
	release
	end

Alola_Ulaula_TapuBulu_Flyover_2:
	addobject Ulaula_Flyover_Tapu
	playse SE_M_FLY
	applymovement Ulaula_Flyover_Tapu, Alola_Ulaula_TapuBulu_Flyover_Movement_0
	waitmovement 0
	removeobject Ulaula_Flyover_Tapu
	clearflag FLAG_FLYOVER_TAPU_BULU
	clearflag FLAG_HIDE_TAPU_BULU
	release
	end


Alola_Ulaula_Phant_outside::
	lock
	faceplayer
	hidefollower
	msgbox Alola_Ulaula_Phant_outside_Text_0, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 35
	goto_if_eq Alola_Ulaula_Phant_outside_3
Alola_Ulaula_Phant_outside_1:
	compare VAR_TEMP_0, 36
	goto_if_eq Alola_Ulaula_Phant_outside_8
Alola_Ulaula_Phant_outside_6:
	compare VAR_TEMP_0, 37
	goto_if_eq Alola_Ulaula_Phant_outside_13
Alola_Ulaula_Phant_outside_11:
	compare VAR_TEMP_0, 36
	goto_if_eq Alola_Ulaula_Phant_outside_18
Alola_Ulaula_Phant_outside_16:
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Ulaula_Phant_outside_Text_1, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 35
	goto_if_eq Alola_Ulaula_Phant_outside_23
Alola_Ulaula_Phant_outside_22:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_6
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement Phant_Noivern_Outside, Alola_Ulaula_Phant_outside_Movement_5
	waitmovement 0
	removeobject Phant_Noivern_Outside
	removeobject Phant_Outside
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

Alola_Ulaula_Phant_outside_2:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_0
	goto Alola_Ulaula_Phant_outside_1

Alola_Ulaula_Phant_outside_3:
	compare VAR_TEMP_1, 46
	goto_if_eq Alola_Ulaula_Phant_outside_2
	goto Alola_Ulaula_Phant_outside_1

Alola_Ulaula_Phant_outside_7:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_1
	goto Alola_Ulaula_Phant_outside_6

Alola_Ulaula_Phant_outside_8:
	compare VAR_TEMP_1, 47
	goto_if_eq Alola_Ulaula_Phant_outside_7
	goto Alola_Ulaula_Phant_outside_6

Alola_Ulaula_Phant_outside_12:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_2
	goto Alola_Ulaula_Phant_outside_11

Alola_Ulaula_Phant_outside_13:
	compare VAR_TEMP_1, 46
	goto_if_eq Alola_Ulaula_Phant_outside_12
	goto Alola_Ulaula_Phant_outside_11

Alola_Ulaula_Phant_outside_17:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_3
	goto Alola_Ulaula_Phant_outside_16

Alola_Ulaula_Phant_outside_18:
	compare VAR_TEMP_1, 45
	goto_if_eq Alola_Ulaula_Phant_outside_17
	goto Alola_Ulaula_Phant_outside_16

Alola_Ulaula_Phant_outside_21:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_4
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement Phant_Noivern_Outside, Alola_Ulaula_Phant_outside_Movement_5
	waitmovement 0
	removeobject Phant_Noivern_Outside
	removeobject Phant_Outside
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

Alola_Ulaula_Phant_outside_23:
	compare VAR_TEMP_1, 46
	goto_if_eq Alola_Ulaula_Phant_outside_21
	goto Alola_Ulaula_Phant_outside_22


Alola_Ulaula_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_ULAULA_PICNICKER_HNS, Alola_Ulaula_TrainerBattlePicnicker_Text_0, Alola_Ulaula_TrainerBattlePicnicker_Text_1
	msgbox Alola_Ulaula_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_TrainerBattleYoungster::
	trainerbattle_single TRAINER_ULAULA_YOUNGSTER_HNS, Alola_Ulaula_TrainerBattleYoungster_Text_0, Alola_Ulaula_TrainerBattleYoungster_Text_1
	msgbox Alola_Ulaula_TrainerBattleYoungster_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_TrainerBattleHiker::
	trainerbattle_single TRAINER_ULAULA_HIKER_HNS, Alola_Ulaula_TrainerBattleHiker_Text_0, Alola_Ulaula_TrainerBattleHiker_Text_1
	msgbox Alola_Ulaula_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_TrainerBattleCooltrainer::
	trainerbattle_single TRAINER_ULAULA_COOLTRAINER_HNS, Alola_Ulaula_TrainerBattleCooltrainer_Text_0, Alola_Ulaula_TrainerBattleCooltrainer_Text_1
	msgbox Alola_Ulaula_TrainerBattleCooltrainer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_LassNPC::
	lock
	faceplayer
	msgbox Alola_Ulaula_LassNPC_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_Bench_Heal_Right::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq Alola_Ulaula_Bench_Heal_Skip
	goto Alola_Ulaula_Bench_Heal

Alola_Ulaula_Bench_Heal_Left::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq Alola_Ulaula_Bench_Heal_Skip
	goto Alola_Ulaula_Bench_Heal

Alola_Ulaula_Bench_Heal_Skip:
	end

Alola_Ulaula_Bench_Heal:
	lock
	faceplayer
	msgbox Alola_Ulaula_Bench_Heal_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Ulaula_Bench_Heal_2
Alola_Ulaula_Bench_Heal_1:
	callnative UpdateFollowingPokemon
	release
	end

Alola_Ulaula_Bench_Heal_2:
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	applymovement LOCALID_PLAYER, Alola_Ulaula_Bench_Heal_Movement_0
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Alola_Ulaula_Bench_Heal_1


Alola_Ulaula_TapuBulu_Flyover_Movement_0:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Alola_Ulaula_Phant_outside_Movement_0:
	jump_in_place_left
	jump_in_place_left
	step_end

Alola_Ulaula_Phant_outside_Movement_1:
	jump_in_place_down
	jump_in_place_down
	step_end

Alola_Ulaula_Phant_outside_Movement_2:
	jump_in_place_right
	jump_in_place_right
	step_end

Alola_Ulaula_Phant_outside_Movement_3:
	jump_in_place_up
	jump_in_place_up
	step_end

Alola_Ulaula_Phant_outside_Movement_4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

Alola_Ulaula_Phant_outside_Movement_5:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Alola_Ulaula_Phant_outside_Movement_6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

Alola_Ulaula_Bench_Heal_Movement_0:
	face_down
	step_end

Alola_Ulaula_BattlePalossand_Text_0:
	.string "壶壶！$"

Alola_Ulaula_MtLanikalaSign_Text_0:
	.string "当地人亲切地称这座山为拉纳基拉\n"
	.string "山，因为它是阿罗拉群岛中最高的山\l"
	.string "峰。\p"
	.string "至于这座山真正的名字，早已随着岁\n"
	.string "月流逝被人们遗忘了。$"

Alola_Ulaula_UlaulaSign_Text_0:
	.string "乌拉乌拉岛$"

Alola_Ulaula_Phant_outside_Text_0:
	.string "你好啊，{PLAYER}！\p"
	.string "我是制作了这个游戏区域的开发者！\p"
	.string "希望你喜欢这处阿罗拉的风景。\p"
	.string "我目前正在制作阿罗拉地区的复古重\n"
	.string "制作品--《究极日蚀》。$"

Alola_Ulaula_Phant_outside_Text_1:
	.string "欢迎来我位于这座岛屿山顶的家里坐\n"
	.string "坐。绝对不会让你白跑一趟的！$"

Alola_Ulaula_TrainerBattlePicnicker_Text_0:
	.string "惊喜吧！我其实一直躲在树上呢！$"

Alola_Ulaula_TrainerBattlePicnicker_Text_1:
	.string "我又躲回去啦……$"

Alola_Ulaula_TrainerBattlePicnicker_Text_2:
	.string "我刚才好像看到有什么红色的东西在\n"
	.string "天上飞。\p"
	.string "难道那是宝可梦吗？$"

Alola_Ulaula_TrainerBattleYoungster_Text_0:
	.string "嘿，我绝对会成为第一个登顶拉纳基\n"
	.string "拉山的人！$"

Alola_Ulaula_TrainerBattleYoungster_Text_1:
	.string "这里甚至都不是真正的拉纳基拉山"
	.string "。.....$"

Alola_Ulaula_TrainerBattleYoungster_Text_2:
	.string "老爸从没告诉过我这座山真正的名\n"
	.string "字。\p"
	.string "我们一直都管它叫拉纳基拉山。$"

Alola_Ulaula_TrainerBattleHiker_Text_0:
	.string "能在这么险峻的地形上行动，你一定\n"
	.string "很有两下子吧！$"

Alola_Ulaula_TrainerBattleHiker_Text_1:
	.string "呜呃……我真该更刻苦训练的……$"

Alola_Ulaula_TrainerBattleHiker_Text_2:
	.string "乌拉乌拉岛可是徒步旅行的绝佳去\n"
	.string "处！\p"
	.string "当地人称这座山为拉纳基拉山，因为\n"
	.string "它是阿罗拉群岛中最高的山峰！$"

Alola_Ulaula_TrainerBattleCooltrainer_Text_0:
	.string "这个洞窟闻起来太糟糕了！赶紧对战\n"
	.string "一场，转移一下注意力吧！$"

Alola_Ulaula_TrainerBattleCooltrainer_Text_1:
	.string "真该带个空气清新剂来的…….$"

Alola_Ulaula_TrainerBattleCooltrainer_Text_2:
	.string "如果你打算进那个洞窟，最好先把鼻\n"
	.string "子捏住。$"

Alola_Ulaula_LassNPC_Text_0:
	.string "群岛附近的大海真是美得令人屏息。\p"
	.string "我可以整天坐在这里，静静地看波浪\n"
	.string "翻涌。$"

Alola_Ulaula_Bench_Heal_Text_0:
	.string "你想在这张长椅上休息一下吗？$"

Alola_Ulaula_EventScript_MoveTutor::
	lock
	faceplayer
	goto_if_set FLAG_ULAULA_MOVE_TUTOR_PAID, Alola_Ulaula_EventScript_MoveTutorMenu
	msgbox Alola_Ulaula_Text_MoveTutorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Alola_Ulaula_EventScript_MoveTutorDecline
	checkitem ITEM_HEART_SCALE, 5
	goto_if_eq VAR_RESULT, FALSE, Alola_Ulaula_EventScript_MoveTutorNoScales
	removeitem ITEM_HEART_SCALE, 5
	setflag FLAG_ULAULA_MOVE_TUTOR_PAID
	msgbox Alola_Ulaula_Text_MoveTutorPaid, MSGBOX_DEFAULT

Alola_Ulaula_EventScript_MoveTutorMenu::
	message Alola_Ulaula_Text_MoveTutorChoose
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, Alola_Ulaula_Text_TutorMove_Acrobatics, Alola_Ulaula_Text_TutorMove_AuroraVeil, Alola_Ulaula_Text_TutorMove_BrutalSwing, Alola_Ulaula_Text_TutorMove_Bulldoze, Alola_Ulaula_Text_TutorMove_Confide, Alola_Ulaula_Text_TutorMove_DazzlingGleam, Alola_Ulaula_Text_TutorMove_DragonTail, Alola_Ulaula_Text_TutorMove_EchoedVoice, Alola_Ulaula_Text_TutorMove_FlameCharge, Alola_Ulaula_Text_TutorMove_FrostBreath, Alola_Ulaula_Text_TutorMove_Infestation, Alola_Ulaula_Text_TutorMove_LeechLife, Alola_Ulaula_Text_TutorMove_LowSweep, Alola_Ulaula_Text_TutorMove_Psyshock, Alola_Ulaula_Text_TutorMove_Quash, Alola_Ulaula_Text_TutorMove_Round, Alola_Ulaula_Text_TutorMove_Scald, Alola_Ulaula_Text_TutorMove_SkyDrop, Alola_Ulaula_Text_TutorMove_SludgeWave, Alola_Ulaula_Text_TutorMove_SmackDown, Alola_Ulaula_Text_TutorMove_SmartStrike, Alola_Ulaula_Text_TutorMove_Snarl, Alola_Ulaula_Text_TutorMove_Venoshock, Alola_Ulaula_Text_TutorMove_VoltSwitch, Alola_Ulaula_Text_TutorMove_WildCharge, Alola_Ulaula_Text_TutorMove_WorkUp, Alola_Ulaula_Text_TutorMove_Cancel
	switch VAR_RESULT
	case 0, Alola_Ulaula_EventScript_TutorTeach_Acrobatics
	case 1, Alola_Ulaula_EventScript_TutorTeach_AuroraVeil
	case 2, Alola_Ulaula_EventScript_TutorTeach_BrutalSwing
	case 3, Alola_Ulaula_EventScript_TutorTeach_Bulldoze
	case 4, Alola_Ulaula_EventScript_TutorTeach_Confide
	case 5, Alola_Ulaula_EventScript_TutorTeach_DazzlingGleam
	case 6, Alola_Ulaula_EventScript_TutorTeach_DragonTail
	case 7, Alola_Ulaula_EventScript_TutorTeach_EchoedVoice
	case 8, Alola_Ulaula_EventScript_TutorTeach_FlameCharge
	case 9, Alola_Ulaula_EventScript_TutorTeach_FrostBreath
	case 10, Alola_Ulaula_EventScript_TutorTeach_Infestation
	case 11, Alola_Ulaula_EventScript_TutorTeach_LeechLife
	case 12, Alola_Ulaula_EventScript_TutorTeach_LowSweep
	case 13, Alola_Ulaula_EventScript_TutorTeach_Psyshock
	case 14, Alola_Ulaula_EventScript_TutorTeach_Quash
	case 15, Alola_Ulaula_EventScript_TutorTeach_Round
	case 16, Alola_Ulaula_EventScript_TutorTeach_Scald
	case 17, Alola_Ulaula_EventScript_TutorTeach_SkyDrop
	case 18, Alola_Ulaula_EventScript_TutorTeach_SludgeWave
	case 19, Alola_Ulaula_EventScript_TutorTeach_SmackDown
	case 20, Alola_Ulaula_EventScript_TutorTeach_SmartStrike
	case 21, Alola_Ulaula_EventScript_TutorTeach_Snarl
	case 22, Alola_Ulaula_EventScript_TutorTeach_Venoshock
	case 23, Alola_Ulaula_EventScript_TutorTeach_VoltSwitch
	case 24, Alola_Ulaula_EventScript_TutorTeach_WildCharge
	case 25, Alola_Ulaula_EventScript_TutorTeach_WorkUp
	case 26, Alola_Ulaula_EventScript_MoveTutorDecline
	case MULTI_B_PRESSED, Alola_Ulaula_EventScript_MoveTutorDecline
	end

Alola_Ulaula_EventScript_TutorTeach_Acrobatics::
	setvar VAR_0x8005, MOVE_ACROBATICS
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_AuroraVeil::
	setvar VAR_0x8005, MOVE_AURORA_VEIL
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_BrutalSwing::
	setvar VAR_0x8005, MOVE_BRUTAL_SWING
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Bulldoze::
	setvar VAR_0x8005, MOVE_BULLDOZE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Confide::
	setvar VAR_0x8005, MOVE_CONFIDE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_DazzlingGleam::
	setvar VAR_0x8005, MOVE_DAZZLING_GLEAM
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_DragonTail::
	setvar VAR_0x8005, MOVE_DRAGON_TAIL
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_EchoedVoice::
	setvar VAR_0x8005, MOVE_ECHOED_VOICE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_FlameCharge::
	setvar VAR_0x8005, MOVE_FLAME_CHARGE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_FrostBreath::
	setvar VAR_0x8005, MOVE_FROST_BREATH
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Infestation::
	setvar VAR_0x8005, MOVE_INFESTATION
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_LeechLife::
	setvar VAR_0x8005, MOVE_LEECH_LIFE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_LowSweep::
	setvar VAR_0x8005, MOVE_LOW_SWEEP
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Psyshock::
	setvar VAR_0x8005, MOVE_PSYSHOCK
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Quash::
	setvar VAR_0x8005, MOVE_QUASH
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Round::
	setvar VAR_0x8005, MOVE_ROUND
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Scald::
	setvar VAR_0x8005, MOVE_SCALD
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SkyDrop::
	setvar VAR_0x8005, MOVE_SKY_DROP
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SludgeWave::
	setvar VAR_0x8005, MOVE_SLUDGE_WAVE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SmackDown::
	setvar VAR_0x8005, MOVE_SMACK_DOWN
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SmartStrike::
	setvar VAR_0x8005, MOVE_SMART_STRIKE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Snarl::
	setvar VAR_0x8005, MOVE_SNARL
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Venoshock::
	setvar VAR_0x8005, MOVE_VENOSHOCK
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_VoltSwitch::
	setvar VAR_0x8005, MOVE_VOLT_SWITCH
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_WildCharge::
	setvar VAR_0x8005, MOVE_WILD_CHARGE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_WorkUp::
	setvar VAR_0x8005, MOVE_WORK_UP
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_MoveTutorTeachMove::
	buffermovename STR_VAR_1, VAR_0x8005
	msgbox Alola_Ulaula_Text_MoveTutorConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Alola_Ulaula_EventScript_MoveTutorMenu
	msgbox Alola_Ulaula_Text_MoveTutorWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, Alola_Ulaula_EventScript_MoveTutorCancelMon
	msgbox Alola_Ulaula_Text_MoveTutorDone, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_EventScript_MoveTutorCancelMon::
	msgbox Alola_Ulaula_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_EventScript_MoveTutorDecline::
	msgbox Alola_Ulaula_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_EventScript_MoveTutorNoScales::
	msgbox Alola_Ulaula_Text_MoveTutorNoScales, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_Text_MoveTutorIntro:
	.string "唔啊！啊！\p"
	.string "你！\p"
	.string "是其他人让你来这儿的吗？他们告诉\n"
	.string "你我是精通宝可梦招式的大师了吗？\p"
	.string "..................\p"
	.string "我可以按群岛的方式传授你的宝可\n"
	.string "梦，不过嘛，得先收一点点费用。\p"
	.string "价格是5个心之鳞片。\p"
	.string "你带来了吗？$"

Alola_Ulaula_Text_MoveTutorPaid:
	.string "我老婆最喜欢这东西了。\p"
	.string "从现在起，我的本领随时任你差遣。$"

Alola_Ulaula_Text_MoveTutorNoScales:
	.string "是5个心之鳞片。可不是4个。\p"
	.string "去试试碎岩吧。不管是让宝可梦来，\n"
	.string "还是用你的拳头！$"

Alola_Ulaula_Text_MoveTutorChoose:
	.string "你想学哪个招式？$"

Alola_Ulaula_Text_MoveTutorConfirm:
	.string "想要学习{STR_VAR_1}\n"
	.string "吗？$"

Alola_Ulaula_Text_MoveTutorWhichMon:
	.string "要让哪只宝可梦学习？$"

Alola_Ulaula_Text_MoveTutorDone:
	.string "太棒了！\p"
	.string "你的宝可梦已经领悟了群岛的招式奥\n"
	.string "秘。$"

Alola_Ulaula_Text_MoveTutorComeBack:
	.string "群岛又不会跑掉。随时欢迎你再来。$"

Alola_Ulaula_Text_TutorMove_Acrobatics:
	.string "特技演员$"

Alola_Ulaula_Text_TutorMove_AuroraVeil:
	.string "极光幕$"

Alola_Ulaula_Text_TutorMove_BrutalSwing:
	.string "狂舞挥打$"

Alola_Ulaula_Text_TutorMove_Bulldoze:
	.string "重踏$"

Alola_Ulaula_Text_TutorMove_Confide:
	.string "密语$"

Alola_Ulaula_Text_TutorMove_DazzlingGleam:
	.string "魔法闪耀$"

Alola_Ulaula_Text_TutorMove_DragonTail:
	.string "龙尾$"

Alola_Ulaula_Text_TutorMove_EchoedVoice:
	.string "回声$"

Alola_Ulaula_Text_TutorMove_FlameCharge:
	.string "蓄能焰袭$"

Alola_Ulaula_Text_TutorMove_FrostBreath:
	.string "冰息$"

Alola_Ulaula_Text_TutorMove_Infestation:
	.string "死缠烂打$"

Alola_Ulaula_Text_TutorMove_LeechLife:
	.string "吸血$"

Alola_Ulaula_Text_TutorMove_LowSweep:
	.string "下盘踢$"

Alola_Ulaula_Text_TutorMove_Psyshock:
	.string "精神冲击$"

Alola_Ulaula_Text_TutorMove_Quash:
	.string "延后$"

Alola_Ulaula_Text_TutorMove_Round:
	.string "轮唱$"

Alola_Ulaula_Text_TutorMove_Scald:
	.string "热水$"

Alola_Ulaula_Text_TutorMove_SkyDrop:
	.string "自由落体$"

Alola_Ulaula_Text_TutorMove_SludgeWave:
	.string "污泥波$"

Alola_Ulaula_Text_TutorMove_SmackDown:
	.string "击落$"

Alola_Ulaula_Text_TutorMove_SmartStrike:
	.string "修长之角$"

Alola_Ulaula_Text_TutorMove_Snarl:
	.string "大声咆哮$"

Alola_Ulaula_Text_TutorMove_Venoshock:
	.string "毒液冲击$"

Alola_Ulaula_Text_TutorMove_VoltSwitch:
	.string "伏特替换$"

Alola_Ulaula_Text_TutorMove_WildCharge:
	.string "疯狂伏特$"

Alola_Ulaula_Text_TutorMove_WorkUp:
	.string "自我激励$"

Alola_Ulaula_Text_TutorMove_Cancel:
	.string "取消$"

