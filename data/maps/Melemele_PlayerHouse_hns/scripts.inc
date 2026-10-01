Melemele_PlayerHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_STATE, 1, Alola_Melemele_SamsonOakVillaIntro_Trigger
	.2byte 0


Alola_Melemele_SamsonOakVillaIntro_Trigger::
	lock
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3
	waitmovement 0
	setvar VAR_ALOLA_STATE, 2
	release
	end


Alola_Melemele_SamsonOakVilla_Dialogue::
	lock
	faceplayer
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Melemele_SamsonOakVilla_Dialogue_4
Alola_Melemele_SamsonOakVilla_Dialogue_2:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_16
Alola_Melemele_SamsonOakVilla_Dialogue_14:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_10
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Melemele_SamsonOakVilla_Dialogue_Text_11, Alola_Melemele_SamsonOakVilla_Dialogue_Text_12, Alola_Melemele_SamsonOakVilla_Dialogue_Text_13, Alola_Melemele_SamsonOakVilla_Dialogue_Text_14, Alola_Melemele_SamsonOakVilla_Dialogue_Text_15
	compare VAR_RESULT, 0
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_31
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_32
	compare VAR_RESULT, 2
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_33
	compare VAR_RESULT, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_53
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_34, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_1:
	compare VAR_ALOLA_STATE, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_10
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_3:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Melemele_SamsonOakVilla_Dialogue_7
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_4:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Melemele_SamsonOakVilla_Dialogue_3
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_7:
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Melemele_SamsonOakVilla_Dialogue_1
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_10:
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_0, MSGBOX_AUTOCLOSE
	giveitem ITEM_BEAST_BALL
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_1, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 4
	clearflag FLAG_HIDE_PHANT_OUTSIDE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_13:
	goto_if_set FLAG_DEFEATED_MELEMELE_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_25
Alola_Melemele_SamsonOakVilla_Dialogue_23:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_9, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_15:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_19
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_16:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_15
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_19:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_13
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_22:
	goto_if_set FLAG_DEFEATED_SAMSON_OAK, Alola_Melemele_SamsonOakVilla_Dialogue_40
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_55
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_8, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_24:
	goto_if_set FLAG_DEFEATED_ULAULA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_28
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_25:
	goto_if_set FLAG_DEFEATED_AKALA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_24
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_28:
	goto_if_set FLAG_DEFEATED_PONI_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_22
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_31:
	getcaughtmon SPECIES_MEOWTH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_44
Alola_Melemele_SamsonOakVilla_Dialogue_43:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_23, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_32:
	getcaughtmon SPECIES_MAROWAK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_47
Alola_Melemele_SamsonOakVilla_Dialogue_46:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_27, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_33:
	getcaughtmon SPECIES_VULPIX_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_50
Alola_Melemele_SamsonOakVilla_Dialogue_49:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_30, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_34:
	getcaughtmon SPECIES_RAICHU_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_68
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46
	end

Alola_Melemele_SamsonOakVilla_Dialogue_52:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_33, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_40:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_44:
	getcaughtmon SPECIES_PERSIAN_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_58
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_47:
	getcaughtmon SPECIES_DIGLETT_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_60
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_50:
	getcaughtmon SPECIES_NINETALES_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_62
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_53:
	getcaughtmon SPECIES_GEODUDE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_64
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_55:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_4
	trainerbattle_no_intro TRAINER_SAMSON_OAK_HNS, Alola_Melemele_SamsonOakVilla_Dialogue_Text_5
	special GivePartyMonMarineRibbon
	special HealPlayerParty
	setflag FLAG_DEFEATED_SAMSON_OAK
	setflag FLAG_FLYOVER_TAPU_KOKO
	setflag FLAG_FLYOVER_TAPU_LELE
	setflag FLAG_FLYOVER_TAPU_BULU
	setflag FLAG_FLYOVER_TAPU_FINI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_6, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_7, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 3
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_58:
	getcaughtmon SPECIES_RATTATA_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_66
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_60:
	getcaughtmon SPECIES_DUGTRIO_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_34
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_62:
	getcaughtmon SPECIES_SANDSHREW_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_70
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_64:
	getcaughtmon SPECIES_GRAVELER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_72
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_66:
	getcaughtmon SPECIES_RATICATE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_74
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_68:
	goto_if_unset FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_76
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_26, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_70:
	getcaughtmon SPECIES_SANDSLASH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_79
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_72:
	getcaughtmon SPECIES_GOLEM_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_81
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_74:
	goto_if_unset FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_83
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_22, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_76:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_86
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_79:
	getcaughtmon SPECIES_GRIMER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_93
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_81:
	getcaughtmon SPECIES_EXEGGUTOR_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_95
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_83:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_97
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_86:
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_107
Alola_Melemele_SamsonOakVilla_Dialogue_105:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_93:
	getcaughtmon SPECIES_MUK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_113
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_95:
	goto_if_unset FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_115
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_32, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_97:
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_121
Alola_Melemele_SamsonOakVilla_Dialogue_119:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_104:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_106:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_110
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_107:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_106
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_110:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_104
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_113:
	goto_if_unset FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_127
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_29, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_115:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_118:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_20, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_120:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_124
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_121:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_120
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_124:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_118
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_127:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_137
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_130:
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_147
Alola_Melemele_SamsonOakVilla_Dialogue_145:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_137:
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_156
Alola_Melemele_SamsonOakVilla_Dialogue_154:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_144:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_146:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_150
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_147:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_146
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_150:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_144
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_153:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_155:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_159
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_156:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_155
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_159:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_153
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154


Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0:
	emote_exclamation_mark
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1:
	walk_down
	walk_left
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3:
	walk_right
	walk_up
	face_right
	step_end

Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0:
	emote_exclamation_mark
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0:
	.string "阿罗拉，{PLAYER}！$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1:
	.string "太好了，你来啦！欢迎来到我的别\n"
	.string "庄！\p"
	.string "我正住在这里调查阿罗拉群岛，研究\n"
	.string "它与阿罗拉地区的相似之处呢。\p"
	.string "我尤其对“地区形态”的现象很感兴\n"
	.string "趣。$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2:
	.string "你看上去实力相当不错呢。\p"
	.string "如果是你，来协助我调查阿罗拉群岛\n"
	.string "绝对再合适不过了！\p"
	.string "去探索所有岛屿吧，要是发现了长得\n"
	.string "像关都地区那些眼熟的宝可梦......\l"
	.string "就回来把宝可梦图鉴展示给我看！\p"
	.string "我会在这里耐心等待你的好消息！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_0:
	.string "哇！你见到守护神了？！\p"
	.string "干得太漂亮了，{PLAYER}。\p"
	.string "这是我四处闲逛时捡到的。\p"
	.string "我也不太清楚这有什么用，不过你收\n"
	.string "下吧。$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_1:
	.string "既然守护神们都亲自现身了，这阿罗\n"
	.string "拉群岛一定非同寻常！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_2:
	.string "多亏有你协助我的研究，\n"
	.string "{PLAYER}！\p"
	.string "托你的福，我们对阿罗拉群岛的了解\n"
	.string "有了极大的进展！\p"
	.string "希望你能继续探索这些岛屿，揭开它\n"
	.string "们所隐藏的所有秘密！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_3:
	.string "阿罗拉，{PLAYER}！\p"
	.string "这么说，你把群岛上所有的霸主宝可\n"
	.string "梦都打败了，是吗？\p"
	.string "这可是一项相当了不起的成就！\p"
	.string "我们认识也很久了……\p"
	.string "差不多是时候来一场宝可梦对战了，\n"
	.string "你觉得呢？$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_4:
	.string "太棒了！我可不会手下留情哦！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_5:
	.string "太不可思议了，{PLAYER}！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_6:
	.string "哇，{PLAYER}！你真是一位\n"
	.string "强大的训练家！\p"
	.string "你已经证明了自己有资格知晓我一直\n"
	.string "保守的关于这些岛屿的秘密……..\p"
	.string "并不是只有我注意到了阿罗拉群岛与\n"
	.string "阿罗拉地区之间的惊人相似之处...\l"
	.string "...\p"
	.string "卡璞守护神们似乎也亲自造访了这些\n"
	.string "岛屿。\p"
	.string "如果你看到它们飞过岛屿，就前往图\n"
	.string "腾柱……它们也许正在那里等着你呢！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_7:
	.string "还在等什么呢，{PLAYER}？\n"
	.string "快去外面探索吧！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_8:
	.string "没关系，{PLAYER}！\p"
	.string "慢慢做好对战的准备，准备好了再来\n"
	.string "找我吧！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_9:
	.string "阿罗拉，{PLAYER}！\p"
	.string "虽然你已经找到了群岛上所有的阿罗\n"
	.string "拉形态，不过你打败所有的霸主宝可\l"
	.string "梦了吗？\p"
	.string "你应该去每座岛上寻找奇异的石柱，\n"
	.string "霸主宝可梦就在那里守卫着它！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_10:
	.string "又见面了，{PLAYER}！\p"
	.string "你对阿罗拉群岛的调查进展如何了？\p"
	.string "想和我分享某一特定岛屿的调查成果\n"
	.string "吗？$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_11:
	.string "美乐美乐岛$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_12:
	.string "阿卡拉岛$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_13:
	.string "乌拉乌拉岛$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_14:
	.string "波尼岛$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_15:
	.string "现在先不用。$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_16:
	.string "让我看一下你的宝可梦图鉴吧\n"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}。$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_17:
	.string "哇，{PLAYER}！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_18:
	.string "你找到了生活在美乐美乐岛上的所有\n"
	.string "阿罗拉形态！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_19:
	.string "而且看起来你也找齐了其他岛屿上的\n"
	.string "所有阿罗拉形态！\p"
	.string "太不可思议了，{PLAYER}！\p"
	.string "你真该为自己感到骄傲！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_20:
	.string "多亏了你，我得以证实所有的阿罗拉\n"
	.string "形态都在阿罗拉群岛上生活着！\p"
	.string "我还想请你帮我做一件事…….\p"
	.string "你能帮我调查一下据守在各岛图腾处\n"
	.string "的霸主宝可梦吗？\p"
	.string "但千万要小心！据说这些霸主宝可梦\n"
	.string "比同类的普通宝可梦强大得多......\p"
	.string "说不定正有谁在暗中观察，看你是否\n"
	.string "配做真正的对手呢！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_21:
	.string "继续探索其他岛屿，并向我汇报你的\n"
	.string "进展吧！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_22:
	.string "看来你已经找齐了美乐美乐岛上的所\n"
	.string "有阿罗拉形态！\p"
	.string "干得好！\p"
	.string "继续探索其他岛屿，并向我汇报你的\n"
	.string "进展吧！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_23:
	.string "让我看看你的宝可梦图鉴\n"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\p"
	.string "看来你还没有找齐美乐美乐岛上所有\n"
	.string "的阿罗拉样子的宝可梦呢。\p"
	.string "我听说美乐美乐岛上有\n"
	.string "{COLOR RED}4\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "种阿罗拉样子的宝可梦等着你去发\l"
	.string "现......\p"
	.string "分别是{COLOR RED}小拉\n"
	.string "达\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}拉达\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}喵喵\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "和{COLOR RED}猫老大\l"
	.string "{COLOR DARK_GRAY}"
	.string "。\p"
	.string "继续探索吧，等把它们都捉齐了再来\n"
	.string "找我！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_24:
	.string "你找到了生活在阿卡拉岛上的所有阿\n"
	.string "罗拉样子的宝可梦！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_25:
	.string "多亏了你，我终于确认了阿罗拉群岛\n"
	.string "上栖息的所有阿罗拉样子的宝可梦。\p"
	.string "不过，我还想请你帮我一个忙......\p"
	.string "你能帮我去调查一下传说中守护着各\n"
	.string "岛屿霸主之证的“霸主宝可梦”吗？\p"
	.string "千万要当心！据说那些霸主宝可梦比\n"
	.string "通常形态的要强大得多……\p"
	.string "说不定正有谁在暗中观察，看你是否\n"
	.string "具备挑战的资格呢！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_26:
	.string "看来你已经找齐阿卡拉岛上所有阿罗\n"
	.string "拉样子的宝可梦了！\p"
	.string "干得漂亮！\p"
	.string "继续探索其他岛屿，随时来向我汇报\n"
	.string "进展吧！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_27:
	.string "让我看看你的宝可梦图鉴\n"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\p"
	.string "看来你还没有找齐阿卡拉岛上所有的\n"
	.string "阿罗拉样子的宝可梦呢。\p"
	.string "我听说阿卡拉岛上有\n"
	.string "{COLOR RED}4\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "种阿罗拉样子的宝可梦等着你去发\l"
	.string "现......\p"
	.string "分别是{COLOR RED}雷丘\n"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}嘎啦嘎啦\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}地鼠\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "和{COLOR RED}三地鼠\l"
	.string "{COLOR DARK_GRAY}"
	.string "。\p"
	.string "继续探索吧，等把它们都捉齐了再来\n"
	.string "找我！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_28:
	.string "你找到了生活在乌拉乌拉岛上的所有\n"
	.string "阿罗拉样子的宝可梦！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_29:
	.string "看来你已经找齐乌拉乌拉岛上所有阿\n"
	.string "罗拉样子的宝可梦了！\p"
	.string "干得漂亮！\p"
	.string "继续探索其他岛屿，随时来向我汇报\n"
	.string "进展吧！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_30:
	.string "让我看看你的宝可梦图鉴\n"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\p"
	.string "看来你还没有找齐乌拉乌拉岛上所有\n"
	.string "的阿罗拉样子的宝可梦呢。\p"
	.string "我听说乌拉乌拉岛上有\n"
	.string "{COLOR RED}6\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "种阿罗拉样子的宝可梦等着你去发\l"
	.string "现......\p"
	.string "分别是{COLOR RED}六尾\n"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}九尾\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}穿山鼠\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}穿山王\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}臭泥\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "和{COLOR RED}臭臭泥\l"
	.string "{COLOR DARK_GRAY}"
	.string "。\p"
	.string "继续探索吧，等把它们都捉齐了再来\n"
	.string "找我！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_31:
	.string "你找到了生活在波尼岛上的所有阿罗\n"
	.string "拉样子的宝可梦！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_32:
	.string "看来你已经找齐波尼岛上所有阿罗拉\n"
	.string "样子的宝可梦了！\p"
	.string "干得漂亮！\p"
	.string "继续探索其他岛屿，随时来向我汇报\n"
	.string "进展吧！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_33:
	.string "让我看看你的宝可梦图鉴\n"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\l"
	.string "{PAUSE 15}......\p"
	.string "看来你还没有找齐波尼岛上所有的阿\n"
	.string "罗拉样子的宝可梦呢。\p"
	.string "我听说波尼岛上有\n"
	.string "{COLOR RED}4\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "种阿罗拉样子的宝可梦等着你去发\l"
	.string "现......\p"
	.string "分别是{COLOR RED}小拳\n"
	.string "石\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}隆隆石\l"
	.string "{COLOR DARK_GRAY}"
	.string "、{COLOR RED}隆隆岩\l"
	.string "{COLOR DARK_GRAY}\l"
	.string "和{COLOR RED}椰蛋树\l"
	.string "{COLOR DARK_GRAY}"
	.string "。\p"
	.string "继续探索吧，等把它们都捉齐了再来\n"
	.string "找我！$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_34:
	.string "没关系，{PLAYER}！\p"
	.string "什么时候想和我分享阿罗拉群岛的新\n"
	.string "发现，随时再来找我吧！$"
