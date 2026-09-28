PokemonMansion_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
	.string "一个秘密的开关！\p"
	.string "要按下它吗？$"

PokemonMansion_Text_WhoWouldnt::
	.string "谁不愿意？$"

PokemonMansion_Text_NotQuiteYet::
	.string "还没到时候呢！$"

PokemonMansion_1F_Text_ArnieIntro::
	.string "我出不去！这个古老的地方是一个巨\n"
	.string "大的迷宫。$"

PokemonMansion_1F_Text_ArnieDefeat::
	.string "不！！这是我的战利品！$"

PokemonMansion_1F_Text_ArniePostBattle::
	.string "拨动这里的开关可以切换门的开关状\n"
	.string "态。$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
	.string "日记：7月5日圭亚那，南美洲\p"
	.string "在丛林深处发现了一只新的宝可梦。$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
	.string "日记：7月10日我们把新发现的宝\n"
	.string "可梦称为梦幻。$"

