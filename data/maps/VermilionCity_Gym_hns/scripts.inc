.set FOUND_FIRST_SWITCH, FLAG_TEMP_1
.set SWITCH1_ID,         VAR_0x8004
.set SWITCH2_ID,         VAR_0x8005
.set TRASH_CAN_ID,       VAR_0x8008

.set CHECK_VISITOR_STATE, 6
.set TYPE, VAR_0x8003
.set ARGUMENT, VAR_0x8004

VermilionCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_Return::
	end

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_EventScript_Gregory::
	trainerbattle_single TRAINER_GREGORY_HNS, VermilionGym_Text_GentlemanGregorySeen, VermilionGym_Text_GentlemanGregoryBeaten
	msgbox VermilionGym_Text_GentlemanGregoryAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT_HNS, VermilionGym_Text_GuitaristVincentSeen, VermilionGym_Text_GuitaristVincentBeaten
	msgbox VermilionGym_Text_GuitaristVincentAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Horton::
	trainerbattle_single TRAINER_HORTON_HNS, VermilionGym_Text_JugglerHortonSeen, VermilionGym_Text_JugglerHortonBeaten
	msgbox VermilionGym_Text_JugglerHortonAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_Surge_Defeated
	msgbox VermilionGym_Text_LtSurgeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, VermilionGym_Text_LtSurgeWinLoss
	message VermilionGym_Text_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VermilionGym_Text_ThunderBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE11_GET
	setflag FLAG_DEFEATED_VERMILION_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers_hns
	checkitem ITEM_TM_SHOCK_WAVE
	call_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_GiveThunderstone
	call_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_GiveTM
	clearflag FLAG_HIDE_PLANT_SURGE
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GiveThunderstone::
	msgbox VermilionGym_Text_LtSurgeThunderstone, MSGBOX_DEFAULT
	giveitem ITEM_THUNDER_STONE
	return

VermilionCity_Gym_EventScript_GiveTM::
	msgbox VermilionGym_Text_LtSurge_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SHOCK_WAVE
	msgbox VermilionGym_Text_LtSurge_ExplainTM, MSGBOX_DEFAULT
	return

VermilionCity_Gym_EventScript_Surge_Defeated::
	msgbox VermilionGym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionGym_Text_LtSurgeIntro:
	.string "马志士：嘿，小鬼头！\p"
	.string "我不得不佩服你啊。敢来挑战我，虽\n"
	.string "然算不上聪明，但胆量确实不小！\p"
	.string "要说起电属性宝可梦，老子可是天下\n"
	.string "第一！\p"
	.string "在战场上我可从来没吃过败仗。\p"
	.string "老子会像当年在战争中消灭敌人一\n"
	.string "样，把你电个精光！$"

VermilionGym_Text_LtSurgeWinLoss:
	.string "马志士：呃啊啊！实力真硬啊！\p"
	.string "好吧，小鬼。这枚橙色徽章归你了！$"

VermilionGym_Text_ReceivedThunderBadge:
	.string "{PLAYER}获得了橙色徽章。$"

VermilionGym_Text_ThunderBadgeInfo:
	.string "马志士：橙色徽章能提升宝可梦的速\n"
	.string "度。\p"
	.string "这是你战胜我的证明。\p"
	.string "自豪地戴着它吧，听见没有？$"

VermilionGym_Text_LtSurge_GiveTM:
	.string "还有这个招式学习器也拿去吧。它在\n"
	.string "战争中可是立了大功的！$"

VermilionGym_Text_LtSurge_ExplainTM:
	.string "里面是“电击波”。\p"
	.string "这招奇准无比，绝对是百发百中！$"

VermilionGym_Text_LtSurgeThunderstone:
	.string "再把这块石头也拿去吧。它里面蕴含\n"
	.string "着货真价实的雷电之力！$"


VermilionGym_Text_LtSurgePostBattle:
	.string "马志士：嘿，小鬼！还在继续奋勇向\n"
	.string "前吗？\p"
	.string "我和我的宝可梦也依然在全力操练着\n"
	.string "呢！$"

VermilionGym_Text_SurgeRematch:
	.string "马志士：这么说，你现在已经是关都\n"
	.string "冠军了！\p"
	.string "干得漂亮，小鬼！但别以为我就认输\n"
	.string "了！\p"
	.string "怎么样，要不要再跟我战个痛快？$"

VermilionGym_Text_SurgeRematchDefeat:
	.string "马志士：哇啊啊！你果然还是那么厉\n"
	.string "害啊！$"

VermilionGym_Text_GentlemanGregorySeen:
	.string "你是来打倒马志士馆长的？\p"
	.string "有我在，你休想得逞！$"

VermilionGym_Text_GentlemanGregoryBeaten:
	.string "非常抱歉，马志士长官，属下让您失\n"
	.string "望了！$"

VermilionGym_Text_GentlemanGregoryAfter:
	.string "想当年我还在军队的时候，是马志士\n"
	.string "长官救了我的命。$"

VermilionGym_Text_GuitaristVincentSeen:
	.string "马志士长官认可了我使用电属性宝可\n"
	.string "梦的潜力。\p"
	.string "你觉得你能战胜我吗？$"

VermilionGym_Text_GuitaristVincentBeaten:
	.string "哎哟，电得我发麻！$"

VermilionGym_Text_GuitaristVincentAfter:
	.string "妈妈叫我别辞掉本职工作，但既然我\n"
	.string "在那边也毫无起色，又能怎么办呢？$"

VermilionGym_Text_JugglerHortonSeen:
	.string "我要打倒你！准备好被电得麻酥酥的\n"
	.string "吧！$"

VermilionGym_Text_JugglerHortonBeaten:
	.string "哇啊！被彻底压制了……$"

VermilionGym_Text_JugglerHortonAfter:
	.string "赢了我可别太得意……\p"
	.string "马志士馆主可是非常厉害的。$"

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "哟！未来的冠军！\p"
    .string "马志士有个外号。\p"
    .string "大家都叫他“电光闪闪的美国人”！\p"
    .string "他是电属性宝可梦的行家。\p"
    .string "飞行属性和水属性的宝可梦对上电属\n"
    .string "性可是大不利哦。\p"
    .string "还要千万小心麻痹状态。\p"
    .string "马志士非常谨慎。\p"
    .string "他把自己锁在里面了，想接近他可不\n"
    .string "容易。$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "呼！真是一场激动人心的战斗！\p"
	.string "看得我都紧张死了。$"

VermilionCity_Gym_Text_GymStatue::
    .string "枯叶市宝可梦道馆馆主：马志士\p"
    .string "获胜训练家：青绿、赤红$"


VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "枯叶市宝可梦道馆馆主：马志士\p"
    .string "获胜训练家：青绿、赤红、\n"
    .string "{PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "不对！这里只有垃圾。$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "嘿！垃圾桶底下有个开关！按下去！\p"
    .string "第1道电子锁打开了！$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "第2道电子锁打开了！电动门开启了\n"
    .string "！$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "不对！这里只有垃圾。\p"
    .string "哎呀！电子锁被重置了！$"

