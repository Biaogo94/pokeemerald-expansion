MelemeleIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MELEMELE_ISLE_HNS
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_DAY
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( RATICATE_ALOLA )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_C, 0, MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	map_script_2 VAR_ALOLA_TRAVEL, 1, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

MelemeleIsle_hns_SetTotemSignWarpFacing:
	setvar VAR_TEMP_C, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 34
	goto_if_ne MelemeleIsle_hns_SetTotemSignWarpFacing_End
	compare VAR_TEMP_B, 26
	goto_if_eq MelemeleIsle_hns_SetTotemSignWarpFacing_Set
	compare VAR_TEMP_B, 27
	goto_if_eq MelemeleIsle_hns_SetTotemSignWarpFacing_Set
	goto MelemeleIsle_hns_SetTotemSignWarpFacing_End

MelemeleIsle_hns_SetTotemSignWarpFacing_Set:
	setvar VAR_TEMP_C, 0

MelemeleIsle_hns_SetTotemSignWarpFacing_End:
	return

MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp::
	setvar VAR_TEMP_C, 1
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_Movement_FacePlayerUpAfterTotemWarp
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	applymovement Alola_Melemele_Captain, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_TRAVEL, 1, Alola_Melemele_GetOffBoat
	.2byte 0


Alola_Melemele_GetOffBoat::
	lock
	delay 30
	applymovement Alola_Melemele_Captain, Alola_Melemele_GetOffBoat_Movement_0
	applymovement LOCALID_PLAYER, Alola_Melemele_GetOffBoat_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_GetOffBoat_Text_0, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_TRAVEL, 2
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	waitmovement 0
	release
	end


Alola_Melemele_TravelToKanto::
	lock
	faceplayer
	msgbox Alola_Melemele_TravelToKanto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Melemele_TravelToKanto_1
	msgbox Alola_Melemele_TravelToKanto_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_TravelToKanto_1:
	msgbox Alola_Melemele_TravelToKanto_Text_1, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 32
	goto_if_eq Alola_Melemele_TravelToKanto_5
	compare VAR_TEMP_0, 23
	goto_if_eq Alola_Melemele_TravelToKanto_8
Alola_Melemele_TravelToKanto_7:
Alola_Melemele_TravelToKanto_4:
	applymovement Alola_Melemele_Captain, Alola_Melemele_TravelToKanto_Movement_2
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_2
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_MELEMELE_ISLE_HNS
	hideobjectat Alola_Melemele_Captain, MAP_MELEMELE_ISLE_HNS
	applymovement OBJ_EVENT_ID_CAMERA, Alola_Melemele_TravelToKanto_Movement_3
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN
	waitse
	playse SE_M_SURF
	applymovement Alola_Melemele_Ship, Alola_Melemele_TravelToKanto_Movement_4
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	special RemoveCameraObject
	warp MAP_ROUTE13_HNS, 77, 26
	waitstate
	end

Alola_Melemele_TravelToKanto_5:
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_0
	waitmovement 0
	goto Alola_Melemele_TravelToKanto_4

Alola_Melemele_TravelToKanto_6:
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_1
	waitmovement 0
	goto Alola_Melemele_TravelToKanto_4

Alola_Melemele_TravelToKanto_8:
	compare VAR_TEMP_1, 33
	goto_if_eq Alola_Melemele_TravelToKanto_6
	goto Alola_Melemele_TravelToKanto_7


Alola_Melemele_Mailbox::
	lock
	msgbox Alola_Melemele_Mailbox_Text_0
	release
	end


Alola_Melemele_Melemele_Sign::
	lock
	msgbox Alola_Melemele_Melemele_Sign_Text_0
	release
	end


Alola_Melemele_Pokecenter_Sign::
	lock
	msgbox Alola_Melemele_Pokecenter_Sign_Text_0
	release
	end


Alola_Melemele_MelemeleMart_Sign::
	lock
	msgbox Alola_Melemele_MelemeleMart_Sign_Text_0
	release
	end


Alola_Melemele_FindItem1::
	finditem ITEM_RARE_CANDY, 1
	end


Alola_Melemele_SamsonOak_Trigger_Beginning::
	lock
	addobject SamsonOakMelemeleIntro
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_0
	waitmovement 0
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_1, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_3
	waitmovement 0
	delay 15
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_3, MSGBOX_AUTOCLOSE
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_4
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_5
	waitmovement 0
	delay 30
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_4
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_5, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_6, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_7
	waitmovement 0
	delay 30
	fadedefaultbgm
	setvar VAR_ALOLA_STATE, 1
	removeobject SamsonOakMelemeleIntro
	setflag FLAG_VISITED_ALOLA
	release
	end


Alola_Melemele_NeedToTalkToSamsonOak::
	lock
	msgbox Alola_Melemele_NeedToTalkToSamsonOak_Text_0, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Alola_Melemele_NeedToTalkToSamsonOak_Movement_0
	waitmovement 0
	release
	end


Alola_Melemele_TotemBattle_Trigger::
	goto_if_unset FLAG_TRIGGERED_MELEMELE_TOTEM, Alola_Melemele_TotemBattle_Trigger_1
	end

Alola_Melemele_TotemBattle_Trigger_1:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_TotemBattle_Trigger_7
Alola_Melemele_TotemBattle_Trigger_5:
	end

Alola_Melemele_TotemBattle_Trigger_4:
	lock
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	fadescreenswapbuffers FADE_TO_BLACK
	delay 30
	clearflag FLAG_HIDE_MELEMELE_TOTEM
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	playmoncry SPECIES_RATICATE_ALOLA, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( RATICATE_ALOLA )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	addobject Melemele_Totem
	waitmoncry
Alola_Melemele_TotemBattle_Trigger_13:
	special DrawWholeMapView
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	playmoncry SPECIES_RATICATE_ALOLA, 0
	applymovement Melemele_Totem, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
Alola_Melemele_TotemBattle_Trigger_19:
	setflag FLAG_TRIGGERED_MELEMELE_TOTEM
	release
	end

Alola_Melemele_TotemBattle_Trigger_6:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_TotemBattle_Trigger_10
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_7:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_TotemBattle_Trigger_6
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_10:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_TotemBattle_Trigger_4
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_14:
	playmoncry SPECIES_LEAFEON, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	addobject Melemele_Totem
	waitmoncry
	goto Alola_Melemele_TotemBattle_Trigger_13

Alola_Melemele_TotemBattle_Trigger_20:
	playmoncry SPECIES_LEAFEON, 0
	applymovement Melemele_Totem, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
	goto Alola_Melemele_TotemBattle_Trigger_19


Alola_Melemele_TotemBattle::
	lock
	faceplayer
	goto_if_set FLAG_MELEMELE_TOTEM_DAY, Alola_Melemele_TotemBattle_1
	playmoncry SPECIES_RATICATE_ALOLA, 0
	msgbox Alola_Melemele_TotemBattle_Text_2, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_RATTATA_ALOLA, 60, ITEM_NONE, SPECIES_RATICATE_ALOLA_TOTEM, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 0, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_TotemBattle_7
	return

Alola_Melemele_TotemBattle_1:
	playmoncry SPECIES_LEAFEON, 0
	msgbox Alola_Melemele_TotemBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_EEVEE, 60, ITEM_NONE, SPECIES_LEAFEON, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_TotemBattle_5
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Alola_Melemele_TotemBattle_9
	return

Alola_Melemele_TotemBattle_5:
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_DEFEATED_MELEMELE_TOTEM
	removeobject Melemele_Totem
	msgbox Alola_Melemele_TotemBattle_Text_1, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Alola_Melemele_TotemBattle_7:
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_DEFEATED_MELEMELE_TOTEM
	removeobject Melemele_Totem
	msgbox Alola_Melemele_TotemBattle_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Alola_Melemele_TotemBattle_9:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end


Alola_Melemele_Totem_sign::
	lock
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Melemele_Totem_sign_5
Alola_Melemele_Totem_sign_3:
	msgbox Alola_Melemele_Totem_sign_Text_6, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_Totem_sign_2:
	msgbox Alola_Melemele_Totem_sign_Text_0
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Melemele_Totem_sign_Text_1, Alola_Melemele_Totem_sign_Text_2, Alola_Melemele_Totem_sign_Text_3, Alola_Melemele_Totem_sign_Text_4, Alola_Melemele_Totem_sign_Text_5
	compare VAR_RESULT, 0
	goto_if_eq Alola_Melemele_Totem_sign_12
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_Totem_sign_15
	compare VAR_RESULT, 2
	goto_if_eq Alola_Melemele_Totem_sign_18
	compare VAR_RESULT, 3
	goto_if_eq Alola_Melemele_Totem_sign_20
	release
	end

Alola_Melemele_Totem_sign_4:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Melemele_Totem_sign_8
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_5:
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Melemele_Totem_sign_4
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_8:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Melemele_Totem_sign_2
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_12:
	goto_if_unset FLAG_HIDE_TAPU_KOKO, Alola_Melemele_Totem_sign_12_Lower
	warp MAP_MELEMELE_ISLE_HNS, 34, 26
	waitstate
	end

Alola_Melemele_Totem_sign_12_Lower:
	warp MAP_MELEMELE_ISLE_HNS, 34, 27
	waitstate
	end

Alola_Melemele_Totem_sign_15:
	goto_if_unset FLAG_HIDE_TAPU_LELE, Alola_Melemele_Totem_sign_15_Lower
	warp MAP_AKALA_ISLE_HNS, 9, 11
	waitstate
	end

Alola_Melemele_Totem_sign_15_Lower:
	warp MAP_AKALA_ISLE_HNS, 9, 12
	waitstate
	end

Alola_Melemele_Totem_sign_18:
	goto_if_unset FLAG_HIDE_TAPU_BULU, Alola_Melemele_Totem_sign_18_Lower
	warp MAP_ULA_ULA_FOREST_HNS, 16, 5
	waitstate
	end

Alola_Melemele_Totem_sign_18_Lower:
	warp MAP_ULA_ULA_FOREST_HNS, 16, 6
	waitstate
	end

Alola_Melemele_Totem_sign_20:
	goto_if_unset FLAG_HIDE_TAPU_FINI, Alola_Melemele_Totem_sign_20_Lower
	warp MAP_PONI_ISLE_HNS, 13, 8
	waitstate
	end

Alola_Melemele_Totem_sign_20_Lower:
	warp MAP_PONI_ISLE_HNS, 13, 9
	waitstate
	end


Alola_MeleMele_TapuKoko_Flyover::
	goto_if_set FLAG_FLYOVER_TAPU_KOKO, Alola_MeleMele_TapuKoko_Flyover_2
	release
	end

Alola_MeleMele_TapuKoko_Flyover_2:
	addobject Melemele_Flyover_Tapu
	playse SE_M_FLY
	applymovement Melemele_Flyover_Tapu, Alola_MeleMele_TapuKoko_Flyover_Movement_0
	waitmovement 0
	removeobject Melemele_Flyover_Tapu
	clearflag FLAG_FLYOVER_TAPU_KOKO
	clearflag FLAG_HIDE_TAPU_KOKO
	release
	end


Alola_Melemele_BattleVsTapuKoko::
	lock
	faceplayer
	playmoncry SPECIES_TAPU_KOKO, CRY_MODE_ENCOUNTER
	msgbox Alola_Melemele_BattleVsTapuKoko_Text_0
	waitmoncry
	seteventmon SPECIES_TAPU_KOKO, 60
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Melemele_BattleVsTapuKoko_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_BattleVsTapuKoko_3
	release
	end

	release
	end

Alola_Melemele_BattleVsTapuKoko_2:
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_BATTLED_TAPU_KOKO
	removeobject Melemele_Tapu
	release
	end

Alola_Melemele_BattleVsTapuKoko_3:
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_BATTLED_TAPU_KOKO
	removeobject Melemele_Tapu
	release
	end


Alola_Melemele_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_1_HNS, Alola_Melemele_TrainerBattleSwimmer_Text_0, Alola_Melemele_TrainerBattleSwimmer_Text_1
	msgbox Alola_Melemele_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_Bugcatcher::
	lock
	faceplayer
	msgbox Alola_Melemele_Bugcatcher_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_camper::
	lock
	faceplayer
	msgbox Alola_Melemele_camper_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_Picnicker::
	lock
	faceplayer
	msgbox Alola_Melemele_Picnicker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
	face_up
	step_end

Alola_Melemele_GetOffBoat_Movement_0:
	face_right
	step_end

Alola_Melemele_GetOffBoat_Movement_1:
	face_left
	step_end

Alola_Melemele_TravelToKanto_Movement_0:
	walk_right
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_1:
	walk_up
	walk_right
	walk_right
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_2:
	face_down
	step_end

Alola_Melemele_TravelToKanto_Movement_3:
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_0:
	emote_exclamation_mark
	face_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_3:
	walk_in_place_up
	walk_in_place_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_4:
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_5:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6:
	jump_in_place_down
	jump_in_place_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_7:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Alola_Melemele_NeedToTalkToSamsonOak_Movement_0:
	walk_up
	step_end

Alola_MeleMele_TapuKoko_Flyover_Movement_0:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Alola_Melemele_GetOffBoat_Text_0:
	.string "欢迎回到群岛！\p"
	.string "如果想去关都大陆旅行，随时再来找\n"
	.string "我！$"

Alola_Melemele_TravelToKanto_Text_0:
	.string "嗨！\p"
	.string "想去关都大陆吗？$"

Alola_Melemele_TravelToKanto_Text_1:
	.string "嗨！这就带你上船！$"

Alola_Melemele_TravelToKanto_Text_2:
	.string "嗨！想启航的时候随时再来。$"

Alola_Melemele_Mailbox_Text_0:
	.string "成也・大木的别墅$"

Alola_Melemele_Melemele_Sign_Text_0:
	.string "欢迎来到美乐美乐岛！$"

Alola_Melemele_Pokecenter_Sign_Text_0:
	.string "欢迎来到美乐美乐岛的宝可梦中心！\p"
	.string "这里是阿罗拉群岛上唯一的宝可梦中\n"
	.string "心，不过你也可以在群岛各处的长椅\l"
	.string "上休息。$"

Alola_Melemele_MelemeleMart_Sign_Text_0:
	.string "美乐美乐岛 友好商店$"

Alola_Melemele_BattleSandygast_Text_0:
	.string "库呜--！$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_0:
	.string "阿罗拉！$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_1:
	.string "欢迎来到阿罗拉群岛！$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_2:
	.string "我叫成也・大木！是一名宝可梦博士\n"
	.string "。\p"
	.string "你叫什么名字？$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_3:
	.string "啊，{PLAYER}。真是个好名\n"
	.string "字！\p"
	.string "你可能认识我在关都地区的堂兄--\n"
	.string "大木博士吧。\p"
	.string "来，我带你去镇上！$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_4:
	.string "这里是群岛的主要城镇。\p"
	.string "它和阿罗拉的好奥乐市惊人地相似.\n"
	.string ".....{PAUSE 30}这\l"
	.string "么一想......\p"
	.string "这整座岛也让我联想到了美乐美乐岛\n"
	.string "......$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_5:
	.string "哎呀，不管怎么说！\p"
	.string "我致力于研究不同地区的宝可梦形态\n"
	.string "！\p"
	.string "在从阿罗拉地区回来的路上，我偶然\n"
	.string "发现了这些岛屿......\p"
	.string "令人惊讶的是，我在阿罗拉见过的许\n"
	.string "多宝可梦这里居然也有，所以我把这\l"
	.string "里称为......\l"
	.string "{PAUSE 30}阿罗拉群岛！$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_6:
	.string "虽说我还没把群岛彻底调查一遍..\n"
	.string "....{PAUSE 30}毕竟\l"
	.string "我也是刚登岛不久。\p"
	.string "我想知道阿罗拉独有的形态是否都在\n"
	.string "这里。\p"
	.string "要是你碰巧遇到了，请顺路来岛东侧\n"
	.string "的别墅给我瞧瞧！\p"
	.string "哦，去别墅的路上也别忘了好好探索\n"
	.string "这座岛屿！\p"
	.string "回头见啦！$"

Alola_Melemele_NeedToTalkToSamsonOak_Text_0:
	.string "成也博士正在别墅等你呢.....\n"
	.string ".{PAUSE 30}最好别让他\l"
	.string "等太久！$"

Alola_Melemele_TotemBattle_Text_0:
	.string "哩--！$"

Alola_Melemele_TotemBattle_Text_1:
	.string "霸主叶伊布被击溃了！它不知道逃窜\n"
	.string "到哪里去了......$"

Alola_Melemele_TotemBattle_Text_2:
	.string "嘶--！$"

Alola_Melemele_TotemBattle_Text_3:
	.string "霸主拉达被打倒了！它不知逃窜到哪\n"
	.string "里去了......$"

MelemeleIsle_hns_Movement_FacePlayerUpAfterTotemWarp:
	face_up
	step_end


Alola_Melemele_Totem_sign_Text_0:
	.string "图腾正散发出一股强烈的能量...\n"
	.string "...\p"
	.string "要触碰图腾传送至其他岛屿吗？$"

Alola_Melemele_Totem_sign_Text_1:
	.string "美乐美乐岛$"

Alola_Melemele_Totem_sign_Text_2:
	.string "阿卡拉岛$"

Alola_Melemele_Totem_sign_Text_3:
	.string "乌拉乌拉岛$"

Alola_Melemele_Totem_sign_Text_4:
	.string "波尼岛$"

Alola_Melemele_Totem_sign_Text_5:
	.string "取消$"

Alola_Melemele_Totem_sign_Text_6:
	.string "这里伫立着一个奇异的图腾，正散发\n"
	.string "出一股能量......$"

Alola_Melemele_BattleVsTapuKoko_Text_0:
	.string "咯咯--咯--！$"

Alola_Melemele_TrainerBattleSwimmer_Text_0:
	.string "群岛这边的海水真暖和啊！$"

Alola_Melemele_TrainerBattleSwimmer_Text_1:
	.string "也许我该上岸晒干一下身体....\n"
	.string "..$"

Alola_Melemele_TrainerBattleSwimmer_Text_2:
	.string "水里有好多很棒的宝可梦，把你所有\n"
	.string "的钓竿都试一遍吧！$"

Alola_Melemele_Bugcatcher_Text_0:
	.string "阿罗拉群岛上的虫属性宝可梦，可比\n"
	.string "关都的大得多呢！$"

Alola_Melemele_camper_Text_0:
	.string "我大老远从关都赶来，就是为了见识\n"
	.string "一下我最喜欢的猫猫宝可梦--喵喵\l"
	.string "的其他形态！$"

Alola_Melemele_Picnicker_Text_0:
	.string "这些群岛上到处都是与众不同的宝可\n"
	.string "梦！\p"
	.string "我得多备点精灵球，把它们全部收服\n"
	.string "才行！$"
