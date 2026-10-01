IndigoPlateau_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_PokemonCenter_OnFrame 
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Pokecenter_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 0, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 2, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 3, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 4, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 5, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 6, IndigoPlateau_PokemonCenter_Enter
	.2byte 0

IndigoPlateau_PokemonCenter_Enter::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setvar VAR_LEAGUE_STATE, 1
	end

IndigoPlateau_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU_HNS
	end


IndigoPlateau_EventScript_Cooltrainer::
	msgbox IndigoPlateau_Text_CooltrainerM, MSGBOX_NPC
	end

IndigoPlateau_EventScript_BlackBelt::
	msgbox IndigoPlateau_Text_Blackbelt, MSGBOX_NPC
	end

IndigoPlateau_EventScript_ShigyNinja::
	msgbox IndigoPlateau_Text_ShigyNinja, MSGBOX_NPC
	end

IndigoPlateau_Text_ShigyNinja:
	.string "恭喜你一路走到这里！\p"
	.string "这些年我见过无数训练家经过这里，\n"
	.string "他们每个人都有着独一无二的风采。\p"
	.string "能走到这一步，你完全值得为自己感\n"
	.string "到自豪！\p"
	.string "去吧，全力以赴！$"

IndigoPlateau_Text_Blackbelt:
	.string "宝可梦联盟目前暂不接受新的挑战\n"
	.string "者。\p"
	.string "请稍后再来。$"

IndigoPlateau_Text_CooltrainerM:
    .string "在宝可梦联盟，你将接受四天王的考\n"
    .string "验。\p"
    .string "你必须击败他们所有人。哪怕输了一\n"
    .string "场，就得全部从头再来！$"

IndigoPlateau_EventScript_Silver::
	lock
	faceplayer 
	goto_if_set FLAG_DAILY_BEAT_SILVER, IndigoPlateau_EventScript_SilverBeat
	msgbox IndigoPlateau_Text_RivalEntrance1, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, IndigoPlateau_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, IndigoPlateau_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, IndigoPlateau_Silver_Battle_Chikorita
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BEAT_SILVER
	release
	end

IndigoPlateau_EventScript_SilverBeat::
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Text_RivalEntrance1:
    .string "站住。\p"
    .string "你现在就想去挑战宝可梦联盟？\p"
    .string "别做白日梦了。\p"
    .string "我精心培育的宝可梦会把你彻底打\n"
    .string "垮。\p"
    .string "{PLAYER}！我要向你发起挑\n"
    .string "战！$"

IndigoPlateau_Text_RivalWin:
    .string "......\p"
    .string "好……我输了……$"

IndigoPlateau_Text_RivalAfter:
    .string "……可恶……还是赢不了吗……\p"
    .string "我……我必须更加为我的宝可梦着想才\n"
    .string "行……\p"
    .string "哼！可别输得太难看啊！$"

IndigoPlateau_EventScript_Psychic::
	lock
	faceplayer
	msgbox IndigoPlateau_Text_TeleportGuy1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_EventScript_PsychicTeleport
	msgbox IndigoPlateau_Text_TeleportGuyNo, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_EventScript_PsychicTeleport::
	msgbox IndigoPlateau_Text_TeleportGuyYes, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playbgm MUS_HG_NEW_BARK, FALSE
	delay 60
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	applymovement2 LOCALID_INDIGOPLATEAU_ABRA, IndigoPLateau_Movement_Abra
	waitmovement 0
	fadescreen FADE_TO_WHITE
	warpteleport MAP_NEW_BARK_TOWN_HNS, 20, 12
	waitstate
	release
	end
	
IndigoPLateau_Movement_Abra:
	jump_in_place_right
	jump_in_place_right
	step_end

IndigoPlateau_EventScript_Abra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	msgbox IndigoPlateau_Text_Abra, MSGBOX_DEFAULT
	waitmoncry
	release
	end

IndigoPlateau_Text_TeleportGuy1:
    .string "哎呀！你准备挑战四天王了吗？你确\n"
    .string "定准备好了吗？\p"
    .string "如果还需要再修行一番，我的凯西可\n"
    .string "以帮你。\p"
    .string "它可以使出瞬间移动带你回家。\p"
    .string "你现在想回家吗？$"

IndigoPlateau_Text_TeleportGuyYes:
    .string "好，好。在脑海中想象出你家的样子\n"
    .string "吧……$"

IndigoPlateau_Text_TeleportGuyNo:
    .string "好，好。祝你好运！$"

IndigoPlateau_Text_Abra:
    .string "凯西：开~西……$"
