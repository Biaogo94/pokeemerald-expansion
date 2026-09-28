PokemonLeague_KarensRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC

PokemonLeague_KarensRoom_EventScript_KarenRematchStandard::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_POSTOBC_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "梨花：啊，又是你啊。\p"
    .string "我相信你还没有忘记我的信念吧：\p"
    .string "真正的强大，源自对宝可梦的信赖。\p"
    .string "自我们上次相遇以来，我和我的宝可\n"
    .string "梦之间的羁绊变得更加深厚了。\p"
    .string "你准备好面对这支由坚不可摧的羁绊\n"
    .string "所维系的队伍了吗？\p"
    .string "让我见识一下你与宝可梦之间羁绊的\n"
    .string "力量吧。$"

PokemonLeague_KarensRoom_Text_Before:
    .string "我是四天王之一的梨花。\p"
    .string "你就是{PLAYER}？真有趣。\p"
    .string "我最喜欢恶属性的宝可梦了。\p"
    .string "它们那狂野又强悍的形象深深吸引着\n"
    .string "我。而且还那么强大。\p"
    .string "你觉得自己能对付它们吗？可要好好\n"
    .string "取悦我一下哦。\p"
    .string "来吧。$"

PokemonLeague_KarensRoom_Text_Beaten:
    .string "哎呀，挺厉害的嘛。我很欣赏你这样\n"
    .string "的训练家。$"

PokemonLeague_KarensRoom_Text_Defeat:
    .string "强力的宝可梦、\p"
    .string "弱小的宝可梦，\p"
    .string "那都只是人任性的想法。\p"
    .string "真正优秀的训练家，应该为了让自己\n"
    .string "喜欢的宝可梦获胜而努力。\p"
    .string "我很喜欢你的风格。你明白什么才是\n"
    .string "最重要的。\p"
    .string "走吧--冠军正在等着你呢。$"

