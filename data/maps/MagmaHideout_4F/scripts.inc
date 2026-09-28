MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "我也想见固拉多，但他们连尾巴都不\n"
	.string "让我看……\p"
	.string "真让我难受。\p"
	.string "哦，不好！我怎么说出固拉多的事了\n"
	.string "！$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "我想头脑不够冷静的话是不可能赢的\n"
	.string "……$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "不知道固拉多有没有尾巴？$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "哇哈哈！快了！就快了！我们的伟大\n"
	.string "目标就要实现了！$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "啊……我努力了半天得到的就是这种\n"
	.string "结局？$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "赤焰松老大！有一名入侵者去你那儿\n"
	.string "了！$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "还没完呢！你别以为能轻易地干掉我\n"
	.string "！$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "我那么容易就被干掉了？$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "来——来吧，再战一回……$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "嘿嘿嘿！看在你这么努力的份上，我\n"
	.string "就告诉你好了！\p"
	.string "没错！固拉多就在前方沉睡着！\p"
	.string "赤焰松刚刚已经过去找固拉多了！\p"
	.string "它很快就要被唤醒了！嘿嘿！嘿嘿嘿\n"
	.string "！$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "又输给你了……嘿嘿嘿……$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "……在你和我浪费时间的时候，赤焰\n"
	.string "松应该已经唤醒了固拉多……$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "赤焰松：固拉多……\p"
	.string "无论怎样也不会从岩浆中苏醒的你…\n"
	.string "…\p"
	.string "一直在寻求的，是这个靛蓝色宝珠吧\n"
	.string "？\p"
	.string "我已带来了靛蓝色宝珠。就让它的光\n"
	.string "芒唤醒你吧！\p"
	.string "向我展示……展示的你全部的力量吧\n"
	.string "！$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "赤焰松：固拉多！怎么回事？\p"
	.string "难道靛蓝色宝珠不行吗？\p"
	.string "固拉多！你去哪了……$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "赤焰松：哦，原来是你？\p"
	.string "我早就注意到你一直到处鬼鬼祟祟的\n"
	.string "……\p"
	.string "明白了！一定是你动了手脚！$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "你为什么能如此娴熟地指挥宝可梦？$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "赤焰松：固拉多逃跑另有原因……\p"
	.string "你想说这个，对不对？\p"
	.string "…… …… ……\n"
	.string "…… …… ……\p"
	.string "哼……你以为我不知道吗？\p"
	.string "既然固拉多走了，这座破火山也没意\n"
	.string "义了。\p"
	.string "我要去追固拉多，告辞了！$"
