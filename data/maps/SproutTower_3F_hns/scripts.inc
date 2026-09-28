SproutTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN_HNS, SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL_HNS, SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY_HNS, SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI_HNS, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "长老：作为训练家，你的本领确实了\n"
	.string "得。\p"
	.string "按照约定，这个秘传学习器给你。\p"
	.string "但我有一言相劝：你应该对自己的宝\n"
	.string "可梦更好一些。\p"
	.string "你的对战方式实在太残酷了。\p"
	.string "宝可梦可不是战斗的工具.....\n"
	.string ".$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "............哼！\p"
	.string "自称是什么长老，实力不过如此。\p"
	.string "这也难怪。\p"
	.string "成天把“要善待宝可梦”挂在嘴边的\n"
	.string "蠢货，我怎么可能会输给他们。\p"
	.string "我只在乎能打赢的强力宝可梦。\p"
	.string "弱小的宝可梦，我根本不屑一顾。$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{RIVAL}使用了脱洞绳！$"

SproutTower_Text_SageLi_Seen:
	.string "欢迎你的到来！\p"
	.string "喇叭芽之塔是一处修行之地。\p"
	.string "人与宝可梦在这里考验彼此的羁绊，\n"
	.string "共同开创光明的未来。\p"
	.string "我就是最后的考验。\p"
	.string "让我来见识一下你与宝可梦之间的羁\n"
	.string "绊吧！$"

SproutTower_Text_SageLi_Beaten:
	.string "啊，精彩绝伦！$"

SproutTower_Text_SageLi_TakeFlash:
	.string "你和你的宝可梦一定能熟练运用这个\n"
	.string "招式。\p"
	.string "收下这个闪光秘传学习器吧。$"

SproutTower_Text_SageLi_FlashExplain:
	.string "闪光能照亮最漆黑的地方。\p"
	.string "但要在对战外使用它，你需要桔梗道\n"
	.string "馆的徽章。$"

SproutTower_Text_SageLi_AfterBattle:
	.string "愿你在旅途中不断学习与成长。$"

SproutTower_Text_SageJin_Seen:
	.string "我为了从宝可梦中悟道而修行！$"

SproutTower_Text_SageJin_Beaten:
	.string "我的修行还未到家......$"

SproutTower_Text_SageJin_AfterBattle:
	.string "宝可梦变强，训练家也会跟着变强。\p"
	.string "不，等等。应该是训练家变强了，宝\n"
	.string "可梦才会跟着变强。$"

SproutTower_Text_SageTroy_Seen:
	.string "让我看看你有多信任自己的宝可梦。$"

SproutTower_Text_SageTroy_Beaten:
	.string "确实，你们之间的信赖是真的！$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "长老就在前面不远处了。$"

SproutTower_Text_SageNeal_Seen:
	.string "长老的秘传学习器能照亮伸手不见五\n"
	.string "指的黑暗。$"

SproutTower_Text_SageNeal_Beaten:
	.string "明明是我的光头更亮吧！$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "愿你的旅途充满光明。$"

SproutTower_Text_3F_Painting:
	.string "这是一幅气势磅礴的喇叭芽画像。$"
