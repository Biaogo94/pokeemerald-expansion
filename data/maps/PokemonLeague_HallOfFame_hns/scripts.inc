PokemonLeague_HallOfFame_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	.byte 0

PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 6, PokemonLeague_HallOfFame_EventScript_Cutscene
	.2byte 0

PokemonLeague_HallOfFame_EventScript_Cutscene::
	lock
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp::
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_Rematch_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags::
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_TAILED_SLOWPOKES
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setvar VAR_LEAGUE_STATE, 1
	setvar VAR_NEWBARK_TOWN_STATE, 6
	setvar VAR_SSAQUA_STATE, 0
	return

PokemonLeague_HallOfFame_EventScript_SetGameClearFlags::
	setflag FLAG_HIDE_CERULEANCAVE_GUARD
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_TAILED_SLOWPOKES
	clearflag FLAG_HIDE_LATIOS
	clearflag FLAG_HIDE_LATIAS
	clearflag FLAG_HIDE_RAYQUAZA
	clearflag FLAG_HIDE_GROUDON
	clearflag FLAG_HIDE_KYOGRE
	clearflag FLAG_HIDE_MEWTWO
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	clearflag FLAG_ITEM_GS_BALL
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setflag FLAG_IS_KANTO_CHAMPION
	setvar VAR_COMPLETED_LUGIA, 4
	clearflag FLAG_HIDE_LUGIA
	setvar VAR_COMPLETED_HO_OH, 4
	clearflag FLAG_HIDE_HO_OH
	call PokemonLeague_HallOfFame_EventScript_SpawnRoamers
	call_if_ge VAR_SUICUNE_ENCOUNTERS, 8, PokemonLeague_HallOfFame_EventScript_SpawnSuicune
	call_if_set FLAG_CAUGHT_CELEBI, PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi
	call_if_ge VAR_VIRIDIAN_FOREST_PICHU, 4, PokemonLeague_HallOfFame_EventScript_SpawnPichu
	call_if_ge VAR_ALOLA_STATE, 4, PokemonLeague_HallOfFame_EventScript_SpawnAlolaMons
	call PokemonLeague_HallOfFame_EventScript_SpawnSinjohMons
	call_if_ge VAR_SINJOH_STORYLINE, 13 PokemonLeague_HallOfFame_EventScript_SpawnArceus
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_CAUGHT_MEW
	clearflag FLAG_BATTLED_DEOXYS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_SUMMONED_MTMOON_JIRACHI
	setvar VAR_LEAGUE_STATE, 1
	return

PokemonLeague_HallOfFame_EventScript_SpawnAlolaMons::
	clearflag FLAG_HIDE_TAPU_BULU
	clearflag FLAG_HIDE_TAPU_FINI
	clearflag FLAG_HIDE_TAPU_KOKO
	clearflag FLAG_HIDE_TAPU_LELE
	clearflag FLAG_HIDE_DUGTRIO_ALOLA
	clearflag FLAG_HIDE_MAROWAK_ALOLA
	clearflag FLAG_HIDE_EXEGGUTOR_ALOLA
	clearflag FLAG_HIDE_SANDSLASH_ALOLA
	clearflag FLAG_HIDE_NINETALES_ALOLA
	clearflag FLAG_HIDE_MUK_ALOLA
	clearflag FLAG_HIDE_RAICHU_ALOLA
	clearflag FLAG_HIDE_GOLEM_ALOLA
	return

PokemonLeague_HallOfFame_EventScript_SpawnSinjohMons::
	clearflag FLAG_HIDE_SINJOHRUINS_REGIROCK
	clearflag FLAG_HIDE_SINJOHRUINS_REGICE
	clearflag FLAG_HIDE_SINJOHRUINS_REGISTEEL
	clearflag FLAG_HIDE_SINJOHRUINS_REGIELEKI
	clearflag FLAG_HIDE_SINJOHRUINS_REGIDRAGO
	clearflag FLAG_HIDE_SINJOHRUINS_REGIGIGAS
	return

PokemonLeague_HallOfFame_EventScript_SpawnArceus::
	clearflag FLAG_HIDE_SINJOHRUINS_ARCEUSROOM_ARCEUS
	return

PokemonLeague_HallOfFame_EventScript_SpawnPichu::
	clearflag FLAG_HIDE_VIRIDIAN_FOREST_SPIKY_EARED_PICHU
	return

PokemonLeague_HallOfFame_EventScript_SpawnRoamers::
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	special InitRoamer
	copyvar VAR_0x8004, VAR_ROAMER_POKEMON_HNS
	special InitKantoRoamers
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	return

PokemonLeague_HallOfFame_EventScript_SpawnSuicune::
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi::
	clearflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	return

PokemonLeague_HallOfFame_Movement_LanceEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

PokemonLeague_HallOfFame_LanceText:
    .string "阿渡：好久没有来到这里了。\p"
    .string "这里是让联盟冠军的荣耀永世流传的\n"
    .string "神圣殿堂。\p"
    .string "与冠军并肩作战的勇敢宝可梦们，也\n"
    .string "会一同名列于此。\p"
    .string "今天，在这里，我们见证了新联盟冠\n"
    .string "军的诞生--\p"
    .string "一位关爱并信任所有宝可梦的训练家\n"
    .string "，\p"
    .string "一位凭借毅力与决心走向成功的训练\n"
    .string "家，\p"
    .string "一位具备伟大资质的新联盟冠军！\p"
    .string "{PLAYER}，请允许我将你与\n"
    .string "你的伙伴们作为冠军铭刻于此！$"

PokemonLeague_HallOfFame_Rematch_LanceText:
    .string "阿渡：还记得不久前，我在这里迎接\n"
    .string "你成为\p"
    .string "城都冠军的那一刻。\p"
    .string "如今我们再度来到这个神圣的殿堂，\n"
    .string "铭记最杰出的\p"
    .string "训练家与宝可梦。\p"
    .string "今天，你不只在城都，也在关都证明\n"
    .string "了自己，连我最强的队伍也没能赢过\l"
    .string "你。\p"
    .string "你对宝可梦的信任与关爱，是你一次\n"
    .string "次获胜的力量。\p"
    .string "一路走来，你始终坚持不懈，从未动\n"
    .string "摇。这正是训练家真正的精神。\p"
    .string "你已具备成为伟大训练家的一切资\n"
    .string "质，甚至可以成为最伟大的那一位。\p"
    .string "{PLAYER}，能再次将你和值\n"
    .string "得信赖的伙伴们登录为冠军，是我的\l"
    .string "荣幸。$"

