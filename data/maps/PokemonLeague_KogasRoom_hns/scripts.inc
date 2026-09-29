PokemonLeague_KogasRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_KogasRoom_EventScript_KogaRematchPostOBC

PokemonLeague_KogasRoom_EventScript_KogaRematchStandard::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_2_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematchPostOBC::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_POSTOBC_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "阿桔：哈哈哈哈！\p"
    .string "勇敢的挑战者，你又回来了啊。\p"
    .string "吾之忍者秘术已磨砺得愈发凌厉。\p"
    .string "阴险的新陷阱正在等待着你。\p"
    .string "剧毒、睡眠，还有更多……\n"
    .string "准备接招吧！\p"
    .string "哈哈哈哈！\p"
    .string "让吾看看你成长了多少！$"

PokemonLeague_KogasRoom_Text_Before:
    .string "哈哈哈哈！\p"
    .string "吾乃四天王之一的阿桔！\p"
    .string "潜伏于暗影之中的忍者！\p"
    .string "吾那精妙复杂的战术会将你玩弄并毁\n"
    .string "灭！\p"
    .string "混乱、睡眠、剧毒……\p"
    .string "准备成为吾阴险秘术的牺牲品吧！\p"
    .string "哈哈哈哈！\p"
    .string "宝可梦对战可不仅仅是蛮力比拼--\n"
    .string "你马上就会领教到的！$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "啊！你证明了自己的能耐！$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "吾已竭尽所能倾囊相授。\p"
    .string "然而依然落败。吾必须继续磨砺身手\n"
    .string "。\p"
    .string "前往下一个房间吧，去考验你的实力\n"
    .string "！$"
