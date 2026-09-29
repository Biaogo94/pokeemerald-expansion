EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "铃铛之音清脆悠扬，为受高塔庇佑之\n"
	.string "人鸣响。$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "未经认可之人不得进入铃铛塔。很抱\n"
	.string "歉，请你离开这里。$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "没有圆朱道馆徽章的人，是禁止进入\n"
	.string "铃铛塔的。\p"
	.string "啊！\p"
	.string "那是圆朱道馆的徽章！请进，请直接\n"
	.string "通过吧。$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "发生了非常重大的事。\p"
	.string "恕我冒昧，必须请你离开。\p"
	.string "……抚慰心灵之物……\n"
	.string "..\p"
	.string "缘寿三老说的话总是这么深奥难懂。\n"
	.string ".....$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "发生了非常重大的事。\p"
	.string "恕我冒昧，必须请你离开。\p"
	.string "....................................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "啊！\p"
	.string "那是透明铃铛的声音！\p"
	.string "这……这真是太美妙了！\p"
	.string "我从未听过如此动听的声音！\p"
	.string "这铃声正映照着持有者纯洁的心灵。\p"
	.string "你……\p"
	.string "或许你能通过这里，登上铃铛塔。\p"
	.string "请，快请进吧。$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "请，快请进吧。$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "这铃声正映照着持有者纯洁的心灵。\p"
	.string "你……确实是天选之人。$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "前方的铃铛塔是一座神圣而美丽的九\n"
	.string "层高塔。\p"
	.string "目睹它的人，心灵都将得到抚慰。$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "铃铛塔摇晃起来了！一定是那只宝可\n"
	.string "梦回到塔顶了！$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "两座塔……两只宝可梦..\n"
	.string "....\p"
	.string "但当其中一座被烧毁时，两只宝可梦\n"
	.string "便都飞离而去，再未归来。$"
