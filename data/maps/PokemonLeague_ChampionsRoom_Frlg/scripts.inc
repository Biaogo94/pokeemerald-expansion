PokemonLeague_ChampionsRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander
	end

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle::
	goto_if_defeated TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur::
	goto_if_defeated TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander::
	goto_if_defeated TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_ChampionsRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	setflag FLAG_TEMP_2
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_Intro
	call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_VICTORY_GYM_LEADER
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Battle
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Rematch
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_DEFEATED_CHAMP
	setflag FLAG_TEMP_4
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
	playbgm MUS_RG_SLOW_PALLET, 0
	addobject LOCALID_CHAMPIONS_ROOM_PROF_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
	closemessage
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	delay 25
	specialvar VAR_RESULT, GetStarterPokemon
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
	closemessage
	delay 13
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 5, 12
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_QuestLogEnd::
	call PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_Battle::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_BattleCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Rematch::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_RematchCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Intro::
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
	return

PokemonLeague_ChampionsRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchIntro
	return

PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerExit::
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
	delay_8
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter::
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_faster_down
	delay_16
	step_end

PokemonLeague_ChampionsRoom_Movement_OakExit::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Text_Intro::
	.string "{RIVAL}：你也来了，\n"
	.string "{PLAYER}！\p"
	.string "我之前就期待着见你，\n"
	.string "{PLAYER}。\p"
	.string "我的对手就应该这样强大，这样才能\n"
	.string "迫使我不断的前进。\p"
	.string "当我完成宝可梦图鉴时 我到各处寻\n"
	.string "找宝可梦。\p"
	.string "不仅如此我建立的完美队伍将会打败\n"
	.string "任何的宝可梦。\p"
	.string "而现在……\p"
	.string "我就是宝可梦联盟冠军！\p"
	.string "{PLAYER}！你知道这意味着\n"
	.string "什么吗？\p"
	.string "我告诉你。\p"
	.string "我是宝可梦史上最伟大的训练家！$"

PokemonLeague_ChampionsRoom_Text_RematchIntro::
	.string "{RIVAL}：嘿，\n"
	.string "{PLAYER}！\p"
	.string "你回来了，{PLAYER}！哈哈\n"
	.string "哈，那真是太好了！\p"
	.string "我的对手就应该这样强大，这样才能\n"
	.string "迫使我不断的前进。\p"
	.string "当我完成宝可梦图鉴时 我到各处寻\n"
	.string "找宝可梦。\p"
	.string "不仅如此我建立的完美队伍将会打败\n"
	.string "任何的宝可梦。\p"
	.string "而现在……\p"
	.string "我就是宝可梦联盟冠军！\p"
	.string "{PLAYER}！你知道这意味着\n"
	.string "什么吗？\p"
	.string "我告诉你。\p"
	.string "我是宝可梦史上最伟大的训练家！$"

PokemonLeague_ChampionsRoom_Text_Defeat::
	.string "什么！这不可能！我尽了全力还是输\n"
	.string "了！\p"
	.string "我好不容易才终于成为了联盟冠军，\p"
	.string "但我的时代已经结束了这不公平！$"

PokemonLeague_ChampionsRoom_Text_Victory::
	.string "哈-哈！赢了！赢了！本大爷赢了！\p"
	.string "本大爷怎么可能会输给\n"
	.string "{PLAYER}呢！\p"
	.string "嘛！作为宝可梦天才{RIVAL}\n"
	.string "大人的对手，你能撑到现在已经很努\l"
	.string "力了！\p"
	.string "就好好夸奖你一下吧！哈-！哈哈-\n"
	.string "哈！$"

PokemonLeague_ChampionsRoom_Text_PostBattle::
	.string "为什么？我为什么会输？\p"
	.string "我培养宝可梦时从来没有出过任何的\n"
	.string "错误……\p"
	.string "可恶！你是新的宝可梦联盟冠军！\p"
	.string "虽然我不太想承认这一点……$"

PokemonLeague_ChampionsRoom_Text_OakPlayer::
	.string "大木：{PLAYER}！$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations::
	.string "大木：堂堂正正，你赢了！真心地祝\n"
	.string "贺你！\p"
	.string "你是宝可梦联盟新的联盟冠军！\p"
	.string "从一开始你带着\n"
	.string "{STR_VAR_1}去完成宝可\l"
	.string "梦图鉴，应该说你长大了！\p"
	.string "{PLAYER}，你的时代来临了$"

PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival::
	.string "大木：{RIVAL}……我对你很失\n"
	.string "望。\p"
	.string "听说你打败了四天王的消息我飞奔到\n"
	.string "这里来。\p"
	.string "但是，当我到达的时候 你已经输\n"
	.string "了！\p"
	.string "{RIVAL}，你明白你为什么会\n"
	.string "失败吗？\p"
	.string "因为你没有给予你的宝可梦信任和\n"
	.string "爱！\p"
	.string "没了它们，你再怎么努力也不会再站\n"
	.string "在冠军的顶峰的！$"

PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe::
	.string "大木：{PLAYER}。\p"
	.string "你能获得胜利不止是靠自己的一个人\n"
	.string "力量。\p"
	.string "你和你的宝可梦心灵有着奇妙非凡的\n"
	.string "感情。\p"
	.string "{PLAYER}！跟我来！$"

