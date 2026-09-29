PokemonLeague_BrunosRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC

PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_POSTOBC_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "希巴：欢迎回来，年轻的战士。\p"
    .string "经过严苛的修行，我们变得更加强大\n"
    .string "了。\p"
    .string "我那坚如磐石的意志，如今更加不可\n"
    .string "动摇。\p"
    .string "你做好迎接更强大挑战的准备了吗？\p"
    .string "让我见识一下你的修行成果吧。\p"
    .string "喝啊--！$"

PokemonLeague_BrunosRoom_Text_Before:
    .string "我是四天王希巴！\p"
    .string "我总是将修行贯彻至极限，因为我相\n"
    .string "信我和宝可梦的无限潜能。\p"
    .string "这就是我们变强的秘诀！\p"
    .string "你能承受得住我们的威力吗？\p"
    .string "嗯？我在你的眼中看不到恐惧。你的\n"
    .string "目光充满决心，太适合战斗了！\p"
    .string "准备好了吗，{PLAYER}？屈\n"
    .string "服于我们压倒性的力量吧！\p"
    .string "喝啊--！$"

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "为什么？我们怎么会输？！$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "既然输了，我就没有资格再说什么。\n"
    .string ".....\p"
    .string "去迎接你接下来的挑战吧！$"
