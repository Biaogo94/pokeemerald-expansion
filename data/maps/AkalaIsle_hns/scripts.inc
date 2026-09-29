AkalaIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_DAY
	goto_if_eq AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( PROBOPASS )
	clearflag FLAG_AKALA_TOTEM_DAY
	call AkalaIsle_hns_SetTotemSignWarpFacing
	return

AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( MAGMORTAR )
	setflag FLAG_AKALA_TOTEM_DAY
	call AkalaIsle_hns_SetTotemSignWarpFacing
	return

AkalaIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_C, 0, AkalaIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	.2byte 0

AkalaIsle_hns_SetTotemSignWarpFacing:
	setvar VAR_TEMP_C, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 9
	goto_if_ne AkalaIsle_hns_SetTotemSignWarpFacing_End
	compare VAR_TEMP_B, 11
	goto_if_eq AkalaIsle_hns_SetTotemSignWarpFacing_Set
	compare VAR_TEMP_B, 12
	goto_if_eq AkalaIsle_hns_SetTotemSignWarpFacing_Set
	goto AkalaIsle_hns_SetTotemSignWarpFacing_End

AkalaIsle_hns_SetTotemSignWarpFacing_Set:
	setvar VAR_TEMP_C, 0

AkalaIsle_hns_SetTotemSignWarpFacing_End:
	return

AkalaIsle_hns_EventScript_FacePlayerUpAfterTotemWarp::
	setvar VAR_TEMP_C, 1
	applymovement LOCALID_PLAYER, AkalaIsle_hns_Movement_FacePlayerUpAfterTotemWarp
	return


Alola_Akala_Island_FindItem1::
	finditem ITEM_PROTEIN, 1
	end


Alola_Akala_Island_FindItem2::
	finditem ITEM_IRON, 1
	end


Alola_Akala_Island_Finditem3::
	finditem ITEM_ZINC, 1
	end


Alola_Akala_Sign::
	lock
	msgbox Alola_Akala_Sign_Text_0
	release
	end


Alola_Akala_House_Sign::
	lock
	msgbox Alola_Akala_House_Sign_Text_0
	release
	end


Alola_Akala_Natu::
	lock
	faceplayer
	playmoncry SPECIES_NATU, 0
	msgbox Alola_Akala_Natu_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end


Alola_Akala_OldManOnBench::
	lock
	faceplayer
	msgbox Alola_Akala_OldManOnBench_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_TotemBattle_Trigger::
	goto_if_unset FLAG_TRIGGERED_AKALA_TOTEM, Alola_Akala_TotemBattle_Trigger_1
	end

Alola_Akala_TotemBattle_Trigger_1:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Akala_TotemBattle_Trigger_7
Alola_Akala_TotemBattle_Trigger_5:
	end

Alola_Akala_TotemBattle_Trigger_4:
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
	clearflag FLAG_HIDE_AKALA_TOTEM
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Akala_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Akala_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Akala_TotemBattle_Trigger_14
	playmoncry SPECIES_PROBOPASS, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( PROBOPASS )
	clearflag FLAG_AKALA_TOTEM_DAY
	addobject Akala_Totem
	waitmoncry
Alola_Akala_TotemBattle_Trigger_13:
	special DrawWholeMapView
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Akala_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Akala_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Akala_TotemBattle_Trigger_20
	playmoncry SPECIES_PROBOPASS, 0
	applymovement Akala_Totem, Alola_Akala_TotemBattle_Trigger_Movement_0
	waitmovement 0
	waitmoncry
Alola_Akala_TotemBattle_Trigger_19:
	setflag FLAG_TRIGGERED_AKALA_TOTEM
	release
	end

Alola_Akala_TotemBattle_Trigger_6:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Akala_TotemBattle_Trigger_10
	goto Alola_Akala_TotemBattle_Trigger_5

Alola_Akala_TotemBattle_Trigger_7:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Akala_TotemBattle_Trigger_6
	goto Alola_Akala_TotemBattle_Trigger_5

Alola_Akala_TotemBattle_Trigger_10:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Akala_TotemBattle_Trigger_4
	goto Alola_Akala_TotemBattle_Trigger_5

Alola_Akala_TotemBattle_Trigger_14:
	playmoncry SPECIES_MAGMORTAR, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( MAGMORTAR )
	setflag FLAG_AKALA_TOTEM_DAY
	addobject Akala_Totem
	waitmoncry
	goto Alola_Akala_TotemBattle_Trigger_13

Alola_Akala_TotemBattle_Trigger_20:
	playmoncry SPECIES_MAGMORTAR, 0
	applymovement Akala_Totem, Alola_Akala_TotemBattle_Trigger_Movement_0
	waitmovement 0
	waitmoncry
	goto Alola_Akala_TotemBattle_Trigger_19


Alola_Akala_TotemBattle::
	lock
	faceplayer
	goto_if_set FLAG_AKALA_TOTEM_DAY, Alola_Akala_TotemBattle_1
	playmoncry SPECIES_PROBOPASS, 0
	msgbox Alola_Akala_TotemBattle_Text_2, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_NOSEPASS, 60, ITEM_NONE, SPECIES_PROBOPASS, 60, ITEM_PETAYA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Akala_TotemBattle_7
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Alola_Akala_TotemBattle_9
	return

Alola_Akala_TotemBattle_1:
	playmoncry SPECIES_MAGMORTAR, 0
	msgbox Alola_Akala_TotemBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_MAGMAR, 60, ITEM_NONE, SPECIES_MAGMORTAR, 60, ITEM_SITRUS_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Akala_TotemBattle_4
	return

Alola_Akala_TotemBattle_4:
	setflag FLAG_HIDE_AKALA_TOTEM
	setflag FLAG_DEFEATED_AKALA_TOTEM
	removeobject Akala_Totem
	msgbox Alola_Akala_TotemBattle_Text_1, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	release
	end

Alola_Akala_TotemBattle_7:
	setflag FLAG_HIDE_AKALA_TOTEM
	setflag FLAG_DEFEATED_AKALA_TOTEM
	removeobject Akala_Totem
	msgbox Alola_Akala_TotemBattle_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	release
	end

Alola_Akala_TotemBattle_9:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	release
	end


Alola_Akala_Totem_sign::
	lock
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Akala_Totem_sign_5
Alola_Akala_Totem_sign_3:
	msgbox Alola_Akala_Totem_sign_Text_5, MSGBOX_AUTOCLOSE
	release
	end

Alola_Akala_Totem_sign_2:
	msgbox Alola_Akala_Totem_sign_Text_0
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Akala_Totem_sign_Text_1, Alola_Akala_Sign_Text_0, Alola_Akala_Totem_sign_Text_2, Alola_Akala_Totem_sign_Text_3, Alola_Akala_Totem_sign_Text_4
	compare VAR_RESULT, 0
	goto_if_eq Alola_Akala_Totem_sign_12
	compare VAR_RESULT, 1
	goto_if_eq Alola_Akala_Totem_sign_15
	compare VAR_RESULT, 2
	goto_if_eq Alola_Akala_Totem_sign_18
	compare VAR_RESULT, 3
	goto_if_eq Alola_Akala_Totem_sign_20
	release
	end

Alola_Akala_Totem_sign_4:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Akala_Totem_sign_8
	goto Alola_Akala_Totem_sign_3

Alola_Akala_Totem_sign_5:
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Akala_Totem_sign_4
	goto Alola_Akala_Totem_sign_3

Alola_Akala_Totem_sign_8:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Akala_Totem_sign_2
	goto Alola_Akala_Totem_sign_3

Alola_Akala_Totem_sign_12:
	goto_if_unset FLAG_HIDE_TAPU_KOKO, Alola_Akala_Totem_sign_12_Lower
	warp MAP_MELEMELE_ISLE_HNS, 34, 26
	waitstate
	end

Alola_Akala_Totem_sign_12_Lower:
	warp MAP_MELEMELE_ISLE_HNS, 34, 27
	waitstate
	end

Alola_Akala_Totem_sign_15:
	goto_if_unset FLAG_HIDE_TAPU_LELE, Alola_Akala_Totem_sign_15_Lower
	warp MAP_AKALA_ISLE_HNS, 9, 11
	waitstate
	end

Alola_Akala_Totem_sign_15_Lower:
	warp MAP_AKALA_ISLE_HNS, 9, 12
	waitstate
	end

Alola_Akala_Totem_sign_18:
	goto_if_unset FLAG_HIDE_TAPU_BULU, Alola_Akala_Totem_sign_18_Lower
	warp MAP_ULA_ULA_FOREST_HNS, 16, 5
	waitstate
	end

Alola_Akala_Totem_sign_18_Lower:
	warp MAP_ULA_ULA_FOREST_HNS, 16, 6
	waitstate
	end

Alola_Akala_Totem_sign_20:
	goto_if_unset FLAG_HIDE_TAPU_FINI, Alola_Akala_Totem_sign_20_Lower
	warp MAP_PONI_ISLE_HNS, 13, 8
	waitstate
	end

Alola_Akala_Totem_sign_20_Lower:
	warp MAP_PONI_ISLE_HNS, 13, 9
	waitstate
	end


Alola_Akala_TapuLele_Flyover::
	goto_if_set FLAG_FLYOVER_TAPU_LELE, Alola_Akala_TapuLele_Flyover_2
	release
	end

Alola_Akala_TapuLele_Flyover_2:
	addobject Akala_Flyover_Tapu
	playse SE_M_FLY
	applymovement Akala_Flyover_Tapu, Alola_Akala_TapuLele_Flyover_Movement_0
	waitmovement 0
	removeobject Akala_Flyover_Tapu
	clearflag FLAG_FLYOVER_TAPU_LELE
	clearflag FLAG_HIDE_TAPU_LELE
	release
	end


Alola_Akala_BattleVsTapuLele::
	lock
	faceplayer
	playmoncry SPECIES_TAPU_LELE, CRY_MODE_ENCOUNTER
	msgbox Alola_Akala_BattleVsTapuLele_Text_0
	waitmoncry
	seteventmon SPECIES_TAPU_LELE, 60
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Akala_BattleVsTapuLele_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Akala_BattleVsTapuLele_3
	release
	end

	release
	end

Alola_Akala_BattleVsTapuLele_2:
	setflag FLAG_HIDE_TAPU_LELE
	setflag FLAG_BATTLED_TAPU_LELE
	removeobject Akala_Tapu
	release
	end

Alola_Akala_BattleVsTapuLele_3:
	setflag FLAG_HIDE_TAPU_LELE
	setflag FLAG_BATTLED_TAPU_LELE
	removeobject Akala_Tapu
	release
	end


Alola_Akala_TrainerBattleHiker::
	trainerbattle_single TRAINER_AKALA_HIKER_HNS, Alola_Akala_TrainerBattleHiker_Text_0, Alola_Akala_TrainerBattleHiker_Text_1
	msgbox Alola_Akala_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_AKALA_PICNICKER_HNS, Alola_Akala_TrainerBattlePicnicker_Text_0, Alola_Akala_TrainerBattlePicnicker_Text_1
	msgbox Alola_Akala_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_TrainerBattleCamper::
	trainerbattle_single TRAINER_AKALA_CAMPER_HNS, Alola_Akala_TrainerBattleCamper_Text_0, Alola_Akala_TrainerBattleCamper_Text_1
	msgbox Alola_Akala_TrainerBattleCamper_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_TrainerBattleSwimmerLand::
	trainerbattle_single TRAINER_AKALA_SWIMMER_2_HNS, Alola_Akala_TrainerBattleSwimmerLand_Text_0, Alola_Akala_TrainerBattleSwimmerLand_Text_1
	msgbox Alola_Akala_TrainerBattleSwimmerLand_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_TrainerBattleSwimmerWater::
	trainerbattle_single TRAINER_AKALA_SWIMMER_1_HNS, Alola_Akala_TrainerBattleSwimmerWater_Text_0, Alola_Akala_TrainerBattleSwimmerWater_Text_1
	msgbox Alola_Akala_TrainerBattleSwimmerWater_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_TrainerBattleSwimmerWaterM::
	trainerbattle_single TRAINER_AKALA_SWIMMER_3_HNS, Alola_Akala_TrainerBattleSwimmerWaterM_Text_0, Alola_Akala_TrainerBattleSwimmerWaterM_Text_1
	msgbox Alola_Akala_TrainerBattleSwimmerWaterM_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_Bench_Heal_Right::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq Alola_Akala_Bench_Heal_Skip
	goto Alola_Akala_Bench_Heal

Alola_Akala_Bench_Heal_Left::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq Alola_Akala_Bench_Heal_Skip
	goto Alola_Akala_Bench_Heal

Alola_Akala_Bench_Heal_Skip:
	end

Alola_Akala_Bench_Heal:
	lock
	faceplayer
	msgbox Alola_Akala_Bench_Heal_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Akala_Bench_Heal_2
Alola_Akala_Bench_Heal_1::
	callnative UpdateFollowingPokemon
	release
	end

Alola_Akala_Bench_Heal_2:
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	applymovement LOCALID_PLAYER, Alola_Akala_Bench_Heal_Movement_0
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Alola_Akala_Bench_Heal_1


Alola_Akala_TotemBattle_Trigger_Movement_0:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Akala_TapuLele_Flyover_Movement_0:
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

Alola_Akala_Bench_Heal_Movement_0:
	face_down
	step_end

Alola_Akala_BattleSandygast_Text_0:
	.string "库呜--！$"

AkalaIsle_hns_Movement_FacePlayerUpAfterTotemWarp:
	face_up
	step_end


Alola_Akala_Sign_Text_0:
	.string "阿卡拉岛$"

Alola_Akala_House_Sign_Text_0:
	.string "阿卡拉度假别庄\p"
	.string "专供造访阿卡拉岛的游客住宿的地方\n"
	.string "。$"

Alola_Akala_Natu_Text_0:
	.string "天然雀：嘟--！$"

Alola_Akala_OldManOnBench_Text_0:
	.string "啊，今天天气真好，不是吗？\p"
	.string "我刚刚正在喂天然雀，这只就跑来长\n"
	.string "椅上陪我了！$"

Alola_Akala_TotemBattle_Text_0:
	.string "莫塔--！$"

Alola_Akala_TotemBattle_Text_1:
	.string "霸主鸭嘴炎兽被击败了！它不知道逃\n"
	.string "往哪里去了……$"

Alola_Akala_TotemBattle_Text_2:
	.string "普罗--！$"

Alola_Akala_TotemBattle_Text_3:
	.string "霸主大朝北鼻被击败了！它不知道逃\n"
	.string "往哪里去了……$"

Alola_Akala_Totem_sign_Text_0:
	.string "图腾正散发出一股强烈的能量...\n"
	.string "...\p"
	.string "要触碰图腾传送至其他岛屿吗？$"

Alola_Akala_Totem_sign_Text_1:
	.string "美乐美乐岛$"

Alola_Akala_Totem_sign_Text_2:
	.string "乌拉乌拉岛$"

Alola_Akala_Totem_sign_Text_3:
	.string "波尼岛$"

Alola_Akala_Totem_sign_Text_4:
	.string "取消$"

Alola_Akala_Totem_sign_Text_5:
	.string "这里伫立着一个奇异的图腾，正散发\n"
	.string "出一股能量……$"

Alola_Akala_BattleVsTapuLele_Text_0:
	.string "哩--哩哩！$"

Alola_Akala_TrainerBattleHiker_Text_0:
	.string "我来到这些岛屿是为了登山！$"

Alola_Akala_TrainerBattleHiker_Text_1:
	.string "结果我摔倒了……$"

Alola_Akala_TrainerBattleHiker_Text_2:
	.string "阿卡拉岛最适合登山了！这里有茂密\n"
	.string "的森林和险峻的山路！$"

Alola_Akala_TrainerBattlePicnicker_Text_0:
	.string "哈！没看到我吧？$"

Alola_Akala_TrainerBattlePicnicker_Text_1:
	.string "看来出其不意也不是每次都效果绝佳\n"
	.string "啊……$"

Alola_Akala_TrainerBattlePicnicker_Text_2:
	.string "阿卡拉岛草木郁郁葱葱，我可以轻松\n"
	.string "躲在树林里！$"

Alola_Akala_TrainerBattleCamper_Text_0:
	.string "我想成为第一个向霸主宝可梦证明自\n"
	.string "己实力的人！$"

Alola_Akala_TrainerBattleCamper_Text_1:
	.string "可恶，这样可证明不了我的实力啊。$"

Alola_Akala_TrainerBattleCamper_Text_2:
	.string "前面有一个奇怪的图腾，但我还没见\n"
	.string "到霸主宝可梦。$"

Alola_Akala_TrainerBattleSwimmerLand_Text_0:
	.string "喂！沙滩上可不能穿鞋！$"

Alola_Akala_TrainerBattleSwimmerLand_Text_1:
	.string "哎哟，需要救生员的时候他们都去哪\n"
	.string "儿了……$"

Alola_Akala_TrainerBattleSwimmerLand_Text_2:
	.string "阿卡拉岛的海滩最棒了！沙子又软，\n"
	.string "海水又清澈！$"

Alola_Akala_TrainerBattleSwimmerWater_Text_0:
	.string "借过借过！我正在折返游呢！$"

Alola_Akala_TrainerBattleSwimmerWater_Text_1:
	.string "我想要的休息可不是这种啊……\n"
	.string "..$"

Alola_Akala_TrainerBattleSwimmerWater_Text_2:
	.string "乌拉乌拉岛的海滩才是最棒的！别听\n"
	.string "其他人胡说八道！$"

Alola_Akala_TrainerBattleSwimmerWaterM_Text_0:
	.string "哈！你冲浪居然还要骑宝可梦？$"

Alola_Akala_TrainerBattleSwimmerWaterM_Text_1:
	.string "如果不是我自己游过来，也许还有力\n"
	.string "气能赢呢……$"

Alola_Akala_TrainerBattleSwimmerWaterM_Text_2:
	.string "这里的洋流很急！能一路迁徙到这些\n"
	.string "岛屿上的宝可梦，一定非常强壮吧！$"

Alola_Akala_Bench_Heal_Text_0:
	.string "你想在这张长椅上休息一下吗？$"
