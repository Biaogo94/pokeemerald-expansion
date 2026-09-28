Route25_BillsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_BillsHouse_hns_OnTransition
	.byte 0

Route25_BillsHouse_hns_OnTransition::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	end

Route25_BillsHouse_hns_EventScript_TeleporterTest::
	lockall
	goto_if_unset FLAG_TELEPORTER_UNLOCKED, Route25_BillsHouse_hns_EndChoice
	helpwindow HELP_TELEPORTER_WINDOW
	msgbox Route25_BillsHouse_Text_Teleporter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_hns_EndChoice
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, Route25_BillsHouse_hns_Text_Meowth, Route25_BillsHouse_hns_Text_Ponyta, Route25_BillsHouse_hns_Text_Rapidash, Route25_BillsHouse_hns_Text_Slowpoke, Route25_BillsHouse_hns_Text_Slowbro, Route25_BillsHouse_hns_Text_Slowking, Route25_BillsHouse_hns_Text_Farfetchd, Route25_BillsHouse_hns_Text_Weezing, Route25_BillsHouse_hns_Text_MrMime, Route25_BillsHouse_hns_Text_Articuno, Route25_BillsHouse_hns_Text_Zapdos, Route25_BillsHouse_hns_Text_Moltres, Route25_BillsHouse_hns_Text_Corsola, Route25_BillsHouse_hns_Text_Zigzagoon, Route25_BillsHouse_hns_Text_Linoone, Route25_BillsHouse_hns_Text_Cancel
	switch VAR_RESULT
	case 0, Route25_BillsHouse_hns_PickMeowth
	case 1, Route25_BillsHouse_hns_PickPonyta
	case 2, Route25_BillsHouse_hns_PickRapidash
	case 3, Route25_BillsHouse_hns_PickSlowpoke
	case 4, Route25_BillsHouse_hns_PickSlowbro
	case 5, Route25_BillsHouse_hns_PickSlowking
	case 6, Route25_BillsHouse_hns_PickFarfetchd
	case 7, Route25_BillsHouse_hns_PickWeezing
	case 8, Route25_BillsHouse_hns_PickMrMime
	case 9, Route25_BillsHouse_hns_PickArticuno
	case 10, Route25_BillsHouse_hns_PickZapdos
	case 11, Route25_BillsHouse_hns_PickMoltres
	case 12, Route25_BillsHouse_hns_PickCorsola
	case 13, Route25_BillsHouse_hns_PickZigzagoon
	case 14, Route25_BillsHouse_hns_PickLinoone
	case 15, Route25_BillsHouse_hns_EndChoice
	case 127, Route25_BillsHouse_hns_EndChoice
	end

Route25_BillsHouse_Text_Teleporter:
	.string "这台机器可以将宝可梦转换为伽勒尔\n"
	.string "的样子。该转化是不可逆的。要继续\l"
	.string "吗？$"

Route25_BillsHouse_hns_PickMeowth::
	setvar VAR_0x8004, SPECIES_MEOWTH
	setvar VAR_TEMP_0, SPECIES_MEOWTH
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickPonyta::
	setvar VAR_0x8004, SPECIES_PONYTA
	setvar VAR_TEMP_0, SPECIES_PONYTA
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickRapidash::
	setvar VAR_0x8004, SPECIES_RAPIDASH
	setvar VAR_TEMP_0, SPECIES_RAPIDASH
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickSlowpoke::
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	setvar VAR_TEMP_0, SPECIES_SLOWPOKE
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickSlowbro::
	setvar VAR_0x8004, SPECIES_SLOWBRO
	setvar VAR_TEMP_0, SPECIES_SLOWBRO
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickSlowking::
	setvar VAR_0x8004, SPECIES_SLOWKING
	setvar VAR_TEMP_0, SPECIES_SLOWKING
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickFarfetchd::
	setvar VAR_0x8004, SPECIES_FARFETCHD
	setvar VAR_TEMP_0, SPECIES_FARFETCHD
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickWeezing::
	setvar VAR_0x8004, SPECIES_WEEZING
	setvar VAR_TEMP_0, SPECIES_WEEZING
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickMrMime::
	setvar VAR_0x8004, SPECIES_MR_MIME
	setvar VAR_TEMP_0, SPECIES_MR_MIME
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	setvar VAR_TEMP_0, SPECIES_ARTICUNO
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	setvar VAR_TEMP_0, SPECIES_ZAPDOS
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	setvar VAR_TEMP_0, SPECIES_MOLTRES
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickCorsola::
	setvar VAR_0x8004, SPECIES_CORSOLA
	setvar VAR_TEMP_0, SPECIES_CORSOLA
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickZigzagoon::
	setvar VAR_0x8004, SPECIES_ZIGZAGOON
	setvar VAR_TEMP_0, SPECIES_ZIGZAGOON
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_PickLinoone::
	setvar VAR_0x8004, SPECIES_LINOONE
	setvar VAR_TEMP_0, SPECIES_LINOONE
	goto Route25_BillsHouse_hns_CheckParty
	end

Route25_BillsHouse_hns_EndChoice::
	closemessage
	releaseall
	end

Route25_BillsHouse_hns_CheckParty::
	special CheckPartyForSpecies
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_hns_NoPokemon
	closemessage
	goto Route25_BillsHouse_hns_CutsceneSetup
	end

Route25_BillsHouse_hns_NoPokemon::
	msgbox Route25_BillsHouse_hns_Text_NotInParty
	closemessage
	releaseall
	end


Route25_BillsHouse_SetPlayerMale::
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_GOLD_NORMAL_HNS
	return

Route25_BillsHouse_SetPlayerFemale::
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_KRIS_NORMAL_HNS
	return

Route25_BillsHouse_hns_CutsceneSetup::
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_1
	copyvar VAR_OBJ_GFX_ID_0, VAR_TEMP_0
	addvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MON_BASE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route25_BillsHouse_SetPlayerMale
	call_if_eq VAR_RESULT, FEMALE, Route25_BillsHouse_SetPlayerFemale
	addobject LOCALID_BILLS_GRANDPA_PLAYER
	addobject LOCALID_BILLS_GRANDPA_OLD_MON
	applymovement OBJ_EVENT_ID_PLAYER, Route25_BillsHouse_Movement_HidePlayer
	hidefollower
	turnobject LOCALID_BILLS_GRANDPA, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Route25_BillsHouse_Movement_CameraPanUp
	waitmovement 0
	delay 60
	fadescreen FADE_FROM_BLACK

Route25_BillsHouse_hns_CutsceneBeforeTeleport::
	delay 60
	opendoor 10, 3
	waitdooranim
	playmoncry VAR_TEMP_0, CRY_MODE_NORMAL
	waitmoncry 
	applymovement LOCALID_BILLS_GRANDPA_OLD_MON, Common_Movement_WalkUp1
	waitmovement 0
	turnobject LOCALID_BILLS_GRANDPA_OLD_MON, DIR_SOUTH
	applymovement LOCALID_BILLS_GRANDPA_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject LOCALID_BILLS_GRANDPA_PLAYER, DIR_NORTH
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 10, 3
	delay 10
	removeobject LOCALID_BILLS_GRANDPA_OLD_MON
	waitdooranim

Route25_BillsHouse_hns_CutsceneTeleport::
	delay 35
	playse SE_PIN
	waitse
	setvar VAR_0x8004, 0
	special AnimateTeleporterHousing
	delay 10
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	setvar VAR_0x8004, 1
	special AnimateTeleporterHousing
	playse SE_WARP_IN
	special AnimateTeleporterCable
	delay 30
	applymovement LOCALID_BILLS_GRANDPA_PLAYER, Route25_BillsHouse_Movement_PlayerMoveLeft
	waitse
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	special GetRegionalFormSpecies
	copyvar VAR_TEMP_1, VAR_RESULT
	clearflag FLAG_TEMP_2
	copyvar VAR_OBJ_GFX_ID_1, VAR_TEMP_1
	addvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE
	
Route25_BillsHouse_hns_CutsceneAfterTeleport::
	opendoor 3, 3
	delay 10
	addobject LOCALID_BILLS_GRANDPA_NEW_MON
	waitdooranim
	applymovement LOCALID_BILLS_GRANDPA_PLAYER, Route25_BillsHouse_Movement_PlayerSlideDown
	playse SE_LEDGE
	applymovement LOCALID_BILLS_GRANDPA_NEW_MON, Common_Movement_WalkDown1
	waitmovement 0
	waitmovement 0
	@playse SE_PIN
	@applymovement LOCALID_BILLS_GRANDPA_PLAYER, Common_Movement_ExclamationMark
	@delay 60
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 3, 3
	delay 10
	applymovement LOCALID_BILLS_GRANDPA_NEW_MON, Route25_BillsHouse_Movement_MonCelebration
	waitmovement 0
	playmoncry VAR_TEMP_0, CRY_MODE_NORMAL
	waitmoncry
	delay 60

Route25_BillsHouse_hns_CutsceneCleanup::
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, Route25_BillsHouse_Movement_CameraPanDown
	waitmovement 0
	removeobject LOCALID_BILLS_GRANDPA_NEW_MON
	removeobject LOCALID_BILLS_GRANDPA_OLD_MON
	removeobject LOCALID_BILLS_GRANDPA_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Route25_BillsHouse_Movement_ShowPlayer
	waitmovement 0
	turnobject LOCALID_BILLS_GRANDPA, DIR_SOUTH
	special RemoveCameraObject
	special ConvertToRegionalForm
	delay 60
	callnative UpdateFollowingPokemon
	fadescreen FADE_FROM_BLACK
	setflag FLAG_USED_TELEPORTER
	releaseall
	end

Route25_BillsHouse_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route25_BillsHouse_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_BillsHouse_Movement_PlayerMoveLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

Route25_BillsHouse_Movement_PlayerSlideDown:
	lock_facing_direction
	jump_down
	unlock_facing_direction
	step_end

Route25_BillsHouse_hns_BeepSE::
	playse SE_BALL
	waitse
	delay 20
	return

Route25_BillsHouse_Movement_HidePlayer:
	set_invisible
	step_end

Route25_BillsHouse_Movement_ShowPlayer:
	set_visible
	step_end

Route25_BillsHouse_hns_Text_Meowth:
	.string "喵喵$"

Route25_BillsHouse_hns_Text_Ponyta:
	.string "小火马$"

Route25_BillsHouse_hns_Text_Rapidash:
	.string "烈焰马$"

Route25_BillsHouse_hns_Text_Slowpoke:
	.string "呆呆兽$"

Route25_BillsHouse_hns_Text_Slowbro:
	.string "呆壳兽$"

Route25_BillsHouse_hns_Text_Slowking:
	.string "呆呆王$"

Route25_BillsHouse_hns_Text_Farfetchd:
	.string "大葱鸭$"

Route25_BillsHouse_hns_Text_Weezing:
	.string "双弹瓦斯$"

Route25_BillsHouse_hns_Text_MrMime:
	.string "魔墙人偶$"

Route25_BillsHouse_hns_Text_Articuno:
	.string "急冻鸟$"

Route25_BillsHouse_hns_Text_Zapdos:
	.string "闪电鸟$"

Route25_BillsHouse_hns_Text_Moltres:
	.string "火焰鸟$"

Route25_BillsHouse_hns_Text_Corsola:
	.string "太阳珊瑚$"

Route25_BillsHouse_hns_Text_Zigzagoon:
	.string "蛇纹熊$"

Route25_BillsHouse_hns_Text_Linoone:
	.string "直冲熊$"

Route25_BillsHouse_hns_Text_Cancel:
	.string "取消$"

Route25_BillsHouse_hns_Text_NotInParty:
	.string "未检测到宝可梦。$"

@VAR_BILLS_GRANDPA

Route25_BillsHouse_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_BILLS_GRANDPA, 1, Route25_BillsHouse_EventScript_Gramps_Meowth
	goto_if_eq VAR_BILLS_GRANDPA, 2, Route25_BillsHouse_EventScript_Gramps_Zigzagoon
	goto_if_eq VAR_BILLS_GRANDPA, 3, Route25_BillsHouse_EventScript_Gramps_Ponyta
	goto_if_eq VAR_BILLS_GRANDPA, 4, Route25_BillsHouse_EventScript_Gramps_Farfetchd
	goto_if_eq VAR_BILLS_GRANDPA, 5, Route25_BillsHouse_EventScript_Gramps_Slowpoke
	goto_if_eq VAR_BILLS_GRANDPA, 6, Route25_BillsHouse_EventScript_Gramps_ShownAll
	msgbox Route25_BillsHouse_Text_GrandpaIntro, MSGBOX_DEFAULT
	setvar VAR_BILLS_GRANDPA, 1
	goto Route25_BillsHouse_EventScript_Gramps_Meowth

Route25_BillsHouse_EventScript_Gramps_Declined::
	msgbox Route25_BillsHouse_Text_YouDontHaveIt, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_WrongMon::
	msgbox Route25_BillsHouse_Text_WrongPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Meowth::
	msgbox Route25_BillsHouse_Text_GrampsMeowth, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_MEOWTH, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_MEOWTH
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 1
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Zigzagoon::
	msgbox Route25_BillsHouse_Text_GrampsZigzagoon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_ZIGZAGOON, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 3
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Ponyta::
	msgbox Route25_BillsHouse_Text_GrampsPonyta, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_eq VAR_RESULT, SPECIES_PONYTA, Route25_BillsHouse_EventScript_Gramps_PonytaRightMon
	goto_if_eq VAR_RESULT, SPECIES_RAPIDASH, Route25_BillsHouse_EventScript_Gramps_PonytaRightMon
	goto Route25_BillsHouse_EventScript_Gramps_WrongMon
Route25_BillsHouse_EventScript_Gramps_PonytaRightMon::
	bufferspeciesname STR_VAR_1, SPECIES_PONYTA
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 5
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Farfetchd::
	msgbox Route25_BillsHouse_Text_GrampsFarfetchd, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_FARFETCHD, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_FARFETCHD
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 7
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Slowpoke::
	msgbox Route25_BillsHouse_Text_GrampsSlowpoke, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_SLOWPOKE, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_SLOWPOKE
	goto Route25_BillsHouse_EventScript_Gramps_SlowpokeReward

Route25_BillsHouse_EventScript_Gramps_SlowpokeReward::
	msgbox Route25_BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	giveitem ITEM_GALARICA_CUFF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_GALARICA_WREATH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route25_BillsHouse_Text_TeleporterUnlocked, MSGBOX_DEFAULT
	setflag FLAG_TELEPORTER_UNLOCKED
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_ShownAll::
	msgbox Route25_BillsHouse_Text_ShownAll, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Correctmon::
	msgbox Route25_BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	setvar VAR_0x8006, 0
Route25_BillsHouse_EventScript_Gramps_GiveLoop::
	giveitem VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	addvar VAR_0x8006, 1
	compare VAR_0x8006, VAR_TEMP_1
	goto_if_lt Route25_BillsHouse_EventScript_Gramps_GiveLoop
	msgbox Route25_BillsHouse_Text_ComeAgain, MSGBOX_DEFAULT
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25_BillsHouse_Test::
	givemon SPECIES_MEOWTH, 10
	givemon SPECIES_ZIGZAGOON, 10
	givemon SPECIES_PONYTA, 10
	givemon SPECIES_FARFETCHD, 10
	givemon SPECIES_SLOWPOKE, 10
	end

Route25_BillsHouse_Movement_MonCelebration:
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_down
	step_end

Route25_BillsHouse_Text_GrandpaIntro:
	.string "嗯？你认识正辉？他是我的孙子。\p"
	.string "他现在在城都地区。说是去搞什么电\n"
	.string "脑相关的事，所以我就帮他看家了。$"

Route25_BillsHouse_Text_GrampsMeowth:
	.string "我孙子正辉曾跟我提过一种宝可梦，\n"
	.string "它有着锋利的爪子，额头上贴着小判\l"
	.string "金币，\p"
	.string "据说还会带来财运呢。$"

Route25_BillsHouse_Text_GrampsZigzagoon:
	.string "正辉跟我提过一种总是走之字形路线\n"
	.string "的宝可梦。\p"
	.string "听说它还是个很擅长到处捡东西的小\n"
	.string "家伙呢。$"

Route25_BillsHouse_Text_GrampsPonyta:
	.string "你知道一种长着火焰鬃毛的宝可梦吗\n"
	.string "？\p"
	.string "听说它跑起来比大多数列车还要快呢\n"
	.string "。$"

Route25_BillsHouse_Text_GrampsFarfetchd:
	.string "正辉跟我提过一种总是拿着一根大葱\n"
	.string "的宝可梦。\p"
	.string "真是个奇特的家伙啊。$"

Route25_BillsHouse_Text_GrampsSlowpoke:
	.string "你知道那种总是呆呆地发愣的宝可梦\n"
	.string "吗？\p"
	.string "听说它的尾巴经常在黑市上被贩卖呢\n"
	.string "。$"

Route25_BillsHouse_Text_TeleporterUnlocked:
	.string "哦，还有一件事！\p"
	.string "正辉的传送机，就是那边那个大机器\n"
	.string "。\p"
	.string "他其实一直没能把它彻底搞好。\p"
	.string "不过它对宝可梦好像会有些奇妙的作\n"
	.string "用。\p"
	.string "如果你想试试的话，随时欢迎！\p"
	.string "只要操作那边的那台电脑就行了。$"

Route25_BillsHouse_Text_AskToSeeMon:
	.string "如果你有那只宝可梦，能让我看一看\n"
	.string "吗？$"

Route25_BillsHouse_Text_ExcitedToSee:
	.string "你愿意给我看吗？那真是太好了！$"

Route25_BillsHouse_Text_YouDontHaveIt:
	.string "你身上没有吗？那可真遗憾....\n"
	.string "..$"

Route25_BillsHouse_Text_ShownPokemon:
	.string "啊，这就是{STR_VAR_1}\n"
	.string "吗？\p"
	.string "真可爱啊！你人真好。$"

Route25_BillsHouse_Text_Appreciation:
	.string "谢谢你！\p"
	.string "这点小心意请收下吧。$"

Route25_BillsHouse_Text_ComeAgain:
	.string "有空再来玩啊。$"

Route25_BillsHouse_Text_ShownAll:
	.string "谢谢你给我看了这么多可爱的宝可梦\n"
	.string "。\p"
	.string "我真的很开心。活了这么大把年纪，\n"
	.string "真是一件幸事啊。\p"
	.string "传送机你想用的时候随时都可以用。$"

Route25_BillsHouse_Text_WrongPokemon:
	.string "嗯？\p"
	.string "这不是我听说的那只宝可梦啊。$"


