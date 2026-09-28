.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}！\p"
	.string "你在这里做什么？\p"
	.string "我的助手还在等着给你精灵球呢！$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1_Register, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_RegisteredElm, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "最好不要随便乱碰！$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "空木：{PLAYER}！你来啦！\p"
	.string "我有件事想拜托你。\p"
	.string "我正在做新的宝可梦研究，想请你帮\n"
	.string "帮忙，{PLAYER}。\p"
	.string "你看......\p"
	.string "我正在写一篇论文，想在学会上发表\n"
	.string "。\p"
	.string "但还有些地方我怎么也想不明白。\p"
	.string "所以！\p"
	.string "我想请你培育一只我最近刚捉到的宝\n"
	.string "可梦。$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "谢谢你，{PLAYER}！帮了我\n"
	.string "大忙了！$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "可是……拜托了，我真的很需要你的\n"
	.string "帮助！$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "当我公布我的研究成果时，我相信我\n"
	.string "们一定能更深入地\p"
	.string "了解宝可梦进化的诸多未解之谜！\p"
	.string "相信我准没错！$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "哎呀！我收到了一封邮件！\p"
	.string "…… …… …… …… …… …\n"
	.string "… …… ……嗯…… 原来如此…\l"
	.string "…\p"
	.string "好的！$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "嘿，听我说。\p"
	.string "我有一个熟人，大家都叫他宝可梦爷\n"
	.string "爷。\p"
	.string "他经常在各地跑，能发现各种奇特的\n"
	.string "珍贵之物。\p"
	.string "就在刚才，他又发邮件过来说这次发\n"
	.string "现的绝对是真家伙，肯定不会有假。\p"
	.string "这很不可思议，但我们现在忙着进行\n"
	.string "宝可梦的研究……\p"
	.string "等等！我想到了！\p"
	.string "{PLAYER}，能不能替我走这\n"
	.string "一趟？$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "我想请你带上一只精灵球里的宝可梦\n"
	.string "作为同伴！\p"
	.string "你将成为它的第一位伙伴，\n"
	.string "{PLAYER}！\p"
	.string "去吧，挑一只你最中意的吧！$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "空木：等等！你要去哪里？$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "空木：你要选\n"
	.string "{STR_VAR_1}，那只\l"
	.string "{STR_VAR_2}宝可梦吗？$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "空木：你想要\n"
	.string "{STR_VAR_1}，那只\l"
	.string "{STR_VAR_2}宝可梦吗？$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "空木：这么说，你喜欢\n"
	.string "{STR_VAR_1}，那只\l"
	.string "{STR_VAR_2}宝可梦？$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "空木：好好考虑吧。\p"
	.string "你的伙伴很重要。$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "空木：我觉得那只宝可梦也很棒！$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER}获得了\n"
	.string "{STR_VAR_1}！$"

NewBarkTown_Lab_Text_Nickname:
	.string "想给你的{STR_VAR_1}起\n"
	.string "一个昵称吗？$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "宝可梦爷爷住在吉花市再往前一点的\n"
	.string "地方。\p"
	.string "顺着路一直走就能到，你绝不会迷路\n"
	.string "的。\p"
	.string "不过以防万一，你有我的电话号码。\n"
	.string "遇到什么事就给我打电话吧！$"

NewBarkTown_Lab_Text_ElmDirections1_Register:
	.string "宝可梦爷爷住在吉花市再往前一点的\n"
	.string "地方。\p"
	.string "顺着路一直走就能到，你绝不会迷路\n"
	.string "的。\p"
	.string "不过以防万一，这是我的电话号码。\n"
	.string "遇到什么事就给我打电话吧！$"

NewBarkTown_Lab_Text_RegisteredElm:
	.string "在宝可梦齿轮中登记了空木博士。$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "如果有野生宝可梦出现，就让你的宝\n"
	.string "可梦去对战吧！$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "如果遇到野生宝可梦，就让你的宝可\n"
	.string "梦去战斗吧！\p"
	.string "要是宝可梦受伤了，可以用我右手边\n"
	.string "的机器，或者去宝可梦中心治疗。\p"
	.string "拜托你啦！$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER}记下了空木博士的\n"
	.string "电话号码。$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "宝可梦爷爷总是到处跑，收集各种稀\n"
	.string "奇古怪的东西。\p"
	.string "可惜大多只是罕见，并没有什么用处\n"
	.string "......$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "里面装着空木博士捕获的宝可梦。$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "空木：{PLAYER}，出大事了\n"
	.string "......\p"
	.string "啊，对了，宝可梦爷爷的大发现到底\n"
	.string "是什么？$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER}将不可思议的蛋交\n"
	.string "给了空木博士。$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "空木：这个？$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "但是......这难道是宝可梦的\n"
	.string "蛋？\p"
	.string "如果真是这样，那可是一项重大发现\n"
	.string "啊！\p"
	.string "空木：什么！？！？\p"
	.string "大木博士给了你宝可梦图鉴？\p"
	.string "{PLAYER}，这是真的吗？这\n"
	.string "也太难以置信了！\p"
	.string "大木博士看穿训练家潜能的眼光可是\n"
	.string "顶尖的。\p"
	.string "哇，{PLAYER}。你可能真的\n"
	.string "具备成为冠军的资质呢。\p"
	.string "而且看来你和宝可梦也相处得非常融\n"
	.string "洽。\p"
	.string "你应该去挑战宝可梦道馆看看。\p"
	.string "最近的道馆就在桔梗市。\p"
	.string "......{PLAYER}。通\n"
	.string "往冠军之路可是很漫长的。\p"
	.string "出发之前，记得一定要去跟你妈妈打\n"
	.string "声招呼。$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "空木：别放弃！那枚蛋要是有什么消\n"
	.string "息，我会打电话给你的！$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "空木：{PLAYER}？你没遇到\n"
	.string "我的助手吗？\p"
	.string "他应该带着那枚蛋在桔梗市的\p"
	.string "宝可梦中心等你才对啊。\p"
	.string "你们肯定是错过了。去那里找找他看\n"
	.string "吧。$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "空木：那枚蛋有什么变化吗？$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER}? I thought the EGG\n"
	.string "hatched.\p"
	.string "Where is the POKéMON?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "空木：{PLAYER}，你看起来\n"
	.string "很有精神嘛！$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "什么？那只宝可梦是！？！$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "The EGG hatched! So, POKéMON\n"
	.string "are born from EGGS…\p"
	.string "No, perhaps not all POKéMON\n"
	.string "are.\p"
	.string "Wow, there's still a lot of\n"
	.string "research to be done.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Thanks, {PLAYER}! You're helping\n"
	.string "unravel POKéMON mysteries for us!\p"
	.string "I want you to have this as a\n"
	.string "token of our appreciation.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "That's an EVERSTONE.\p"
	.string "Some species of POKéMON evolve\n"
	.string "when they grow to certain levels.\p"
	.string "A POKéMON holding the EVERSTONE\n"
	.string "won't evolve.\p"
	.string "Give it to a POKéMON you don't\n"
	.string "want to evolve.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ELM: {PLAYER}, I'll call you if\n"
	.string "anything comes up.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "…sigh… That stolen POKéMON.\p"
	.string "I wonder how it's doing.\p"
	.string "They say a POKéMON raised by a\n"
	.string "bad person turns bad itself.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ELM: Hi, {PLAYER}!\p"
	.string "Thanks to you, my research is\n"
	.string "going great!\p"
	.string "Take this as a token of my\n"
	.string "appreciation.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "The MASTER BALL is the best!\p"
	.string "It's the ultimate BALL! It'll\n"
	.string "catch any POKéMON without fail.\p"
	.string "It's given only to recognized\n"
	.string "POKéMON researchers.\p"
	.string "I think you can make much better\n"
	.string "use of it than I can, {PLAYER}!$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "By the way...\n"
	.string "A group of beautiful KIMONO\l"
	.string "GIRLS were looking for you.\p"
	.string "They told me they are\n"
	.string "waiting for you at the\l" 
	.string "ECRUTEAK DANCE THEATER.\p"
	.string "I know you've gone through many\n"
	.string "things since that EGG got you\l"
	.string "involved in all this...\p"
	.string "I hope you'll carry through it.$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF.ELM: The KIMONO\n"
	.string "GIRLS are waiting for you at\l"
	.string "the ECRUTEAK DANCE THEATER.$"

NewBarkTown_Lab_Text_League:
	.string "PROF.ELM: Hahaha...\n"
	.string "Good job!\p"
	.string "That rare EGG has brought you\n"
	.string "a lot of trouble, huh?\p"
	.string "The KIMONO GIRLS said something\n"
	.string "about me?\p"
	.string "I have nothing to do with it.\p"
	.string "You made your decision and went\n"
	.string "through with it.\p"
	.string "Having done so much, you should\n"
	.string "be able to face the LEAGUE now!\p"
	.string "You should head for INDIGO\n"
	.string "PLATEAU!\p"
	.string "Do you know how to get there?\n"
	.string "Follow ROUTE 27 to ROUTE 26.\p"
	.string "Once there, go straight north!$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ELM: {PLAYER}! There you are!\p"
	.string "I called because I have\n"
	.string "something for you.\p"
	.string "See? It's an S.S.TICKET.\p"
	.string "Now you can catch POKéMON in\n"
	.string "KANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "The ship departs from OLIVINE\n"
	.string "CITY.\p"
	.string "But you knew that already,\n"
	.string "{PLAYER}.\p"
	.string "After all, you've traveled all\n"
	.string "over with your POKéMON.\p"
	.string "Give my regards to PROF.OAK in\n"
	.string "KANTO!$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "It's the POKéMON EGG being\n"
	.string "studied by PROF.ELM.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, I want you to have\n"
	.string "this for your errand.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "There are only three of us, so\n"
	.string "we're always busy.$"

NewBarkTown_Lab_Text_AideSave:
	.string "平时一定要记得多存档！\p"
	.string "按下START键打开菜单，然后选\n"
	.string "择“记录”即可保存游戏！$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "There was a loud noise\n"
	.string "outside…\p"
	.string "When we went to look,\n"
	.string "someone stole a POKéMON.\p"
	.string "It's unbelievable that anyone\n"
	.string "would do that!\p"
	.string "…sigh… That stolen POKéMON.\p"
	.string "I wonder how it's doing.\p"
	.string "They say a POKéMON raised by a\n"
	.string "bad person turns bad itself.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER}！\p"
	.string "这些给你，在你的宝可梦图鉴冒险路\n"
	.string "上一定会用得上的！$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "要完成宝可梦图鉴，你就必须去捕捉\n"
	.string "宝可梦。\p"
	.string "在遇到野生宝可梦时，向它们投掷精\n"
	.string "灵球就能捉到它们。$"

NewBarkTown_Lab_Text_Officer1:
	.string "I heard a POKéMON was stolen\n"
	.string "here…\p"
	.string "I was just getting some\n"
	.string "information from PROF.ELM.\p"
	.string "Apparently, it was a young\n"
	.string "male with long, red hair…\p"
	.string "What?\p"
	.string "You battled a trainer like\n"
	.string "that?\p"
	.string "Did you happen to get his\n"
	.string "name?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "好！原来他的名字叫{RIVAL}\n"
	.string "啊？$"

NewBarkTown_Lab_Text_Officer2:
	.string "Thanks for helping my\n"
	.string "investigation!$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "你肯定知道他的名字吧？！$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "Ah, {PLAYER}!\p"
	.string "How's your POKéDEX coming along?\n"
	.string "I'm busy now, but call me sometime\l"
	.string "and I can check your progress!$"
