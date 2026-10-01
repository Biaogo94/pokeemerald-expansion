.equ REQUIRED_OWNED_MONS, 20

Route10_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Aide::
	lock
	faceplayer
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE, Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone
	msgbox Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_OWNED_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route10_PokemonCenter_1F_Text_GreatHereYouGo
	checkitemspace ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide, ITEM_EVERSTONE
	setflag FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone::
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_OWNED_MONS
	bufferitemname STR_VAR_2, ITEM_EVERSTONE
	return

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
	.string "将宝可梦的属性互相不同搭配起来。\p"
	.string "每一种属性都比其它一些属性强，相\n"
	.string "对的，也比其它一些属性弱。$"

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
	.string "一个金珠实在没什么用，因此我以5000元\n"
	.string "的价格把它卖了。$"

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
	.string "我听说那个幽灵经常出没于紫苑镇。$"

Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons::
	.string "哦…… {PLAYER}我一直在找\n"
	.string "你。\p"
	.string "是我 你经常会看到的大木博士的助\n"
	.string "手之一。\p"
	.string "如果你的宝可梦图鉴已经收集了20个\n"
	.string "不同的宝可梦的数据，我就会把大木\l"
	.string "博士的奖励给你。\p"
	.string "他委托我给你这个不变之石。\p"
	.string "那么，{PLAYER} 让我问问\n"
	.string "你吧。\p"
	.string "你的宝可梦图鉴已经收集到20个宝可\n"
	.string "梦的数据吗？$"

Route10_PokemonCenter_1F_Text_GreatHereYouGo::
	.string "太棒了！你已经收集了\n"
	.string "{STR_VAR_3}种宝可梦！\p"
	.string "恭喜！奖励，拿去吧！$"

Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide::
	.string "{PLAYER}从助手那儿获得了\n"
	.string "不变之石。$"

Route10_PokemonCenter_1F_Text_ExplainEverstone::
	.string "如果宝可梦进化数据一样可以加入宝\n"
	.string "可梦图鉴。\p"
	.string "但有时，你也许会不希望一个宝可梦\n"
	.string "进化。\p"
	.string "在那种情况下 就把不变之石给那只\n"
	.string "宝可梦吧。\p"
	.string "根据博士的话所说，它会阻止宝可梦\n"
	.string "的进化$"

