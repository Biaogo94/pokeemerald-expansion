PokemonLeague_WillsRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_WillsRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

EliteFourRoom_OnLoad::
	call_if_eq VAR_TEMP_0, 1, EliteFourRoom_CreateDoor
	end

EliteFourRoom_CreateDoor::
	setmetatile 5, 11, 0x29D, TRUE
	setmetatile 6, 11, 0x29E, TRUE
	setmetatile 7, 11, 0x29F, TRUE
	setmetatile 5, 12, 0x2A5, TRUE
	setmetatile 6, 12, 0x2A6, TRUE
	setmetatile 7, 12, 0x2A7, TRUE
	return

PokemonLeague_WillsRoom_OnResume::
	setvar VAR_0x8004, 0
	special DoPokemonLeagueLightingEffect
	end

EliteFourRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, EliteFourRoom_CloseDoor
	.2byte 0

EliteFourRoom_CloseDoor::
	lock
	setflag FLAG_TEMP_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setmetatile 5, 11, 0x29D, TRUE
	setmetatile 6, 11, 0x29E, TRUE
	setmetatile 7, 11, 0x29F, TRUE
	setmetatile 5, 12, 0x2A5, TRUE
	setmetatile 6, 12, 0x2A6, TRUE
	setmetatile 7, 12, 0x2A7, TRUE
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_TEMP_0, 1
	release
	end

PokemonLeague_WillsRoom_EventScript_Will::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 2, PokemonLeague_WillsRoom_EventScript_WillDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_WillsRoom_EventScript_WillRematch
	msgbox PokemonLeague_WillsRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_WILL_1_HNS, PokemonLeague_WillsRoom_Text_Beaten
	goto PokemonLeague_WillsRoom_EventScript_WillOnDefeat

PokemonLeague_WillsRoom_EventScript_WillRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_WillsRoom_EventScript_WillRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_WillsRoom_EventScript_WillRematchPostOBC

PokemonLeague_WillsRoom_EventScript_WillRematchStandard::
	msgbox PokemonLeague_WillsRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_WILL_2_HNS, PokemonLeague_WillsRoom_Text_Beaten
	goto PokemonLeague_WillsRoom_EventScript_WillOnDefeat

PokemonLeague_WillsRoom_EventScript_WillRematchPostOBC::
	msgbox PokemonLeague_WillsRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_WILL_POSTOBC_HNS, PokemonLeague_WillsRoom_Text_Beaten
	goto PokemonLeague_WillsRoom_EventScript_WillOnDefeat

PokemonLeague_WillsRoom_EventScript_WillOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_WillsRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 2
	release
	end

PokemonLeague_WillsRoom_EventScript_WillDefeated::
	msgbox PokemonLeague_WillsRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_WillsRoom_Text_Before:
    .string "欢迎来到宝可梦联盟，\n"
    .string "{PLAYER}。\p"
    .string "容我自我介绍一下。我是一树。\p"
    .string "我在世界各地修行，培育出了强大的\n"
    .string "超能力属性宝可梦。\p"
    .string "终于，我获得了认可，跻身四天王之\n"
    .string "列。\p"
    .string "我只会不断变得更强！\p"
    .string "输掉是绝不可能的！$"

PokemonLeague_WillsRoom_Text_Beaten:
    .string "我……我居然……\n"
    .string "不敢相信……$"

PokemonLeague_WillsRoom_Text_Defeat:
    .string "即使被击败了，我也不会改变前进的\n"
    .string "方向。\p"
    .string "我会继续战斗，直到立于所有训练家\n"
    .string "之巅！\p"
    .string "去吧，{PLAYER}，继续前进\n"
    .string "，去见识四天王真正的可怕之处吧。$"

PokemonLeague_WillsRoom_Text_RematchBefore:
    .string "一树：啊，欢迎回来。\p"
    .string "我早已预见到了这次重逢。\p"
    .string "我和我的超能力宝可梦都已脱胎换骨\n"
    .string "，研发出了全新的战术。\p"
    .string "准备迎接一场策略与力量皆大幅升级\n"
    .string "的决战吧。\p"
    .string "让我看看你的预见力是否能与我匹敌\n"
    .string "。$"
