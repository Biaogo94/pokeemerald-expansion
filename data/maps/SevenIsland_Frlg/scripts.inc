SevenIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
	.byte 0

SevenIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND
	end

SevenIsland_EventScript_IslandSign::
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end

SevenIsland_EventScript_OldWoman::
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

SevenIsland_EventScript_Scientist::
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end

Text_SwordsDanceTeach::
	.string "没多少人会来这里。\p"
	.string "如果我在这里特训，我一定能变得越\n"
	.string "来越强。\p"
	.string "嗯，越来越强……\p"
	.string "你想不想学一下这个技能？剑舞。$"

Text_SwordsDanceDeclined::
	.string "好吧，没兴趣也没关系。$"

Text_SwordsDanceWhichMon::
	.string "哪只宝可梦想学会这个技能？我来教\n"
	.string "它。$"

Text_SwordsDanceTaught::
	.string "要是我们能不断变强该多好，对吧？$"

SevenIsland_Text_IslandSign::
	.string "七之岛无尽探索之岛$"

SevenIsland_Text_IslandsMadeInSevenDays::
	.string "因为一共有七个小岛，所以它们被统\n"
	.string "称为七岛。\p"
	.string "……年轻人都是这么认为的。\p"
	.string "事实上，这些岛之所以被这么命名，\n"
	.string "据说因为它们是在七天内造成的。$"

SevenIsland_Text_IslandVirtuallyUntouched::
	.string "这个岛几乎没有被开发过，还保持着\n"
	.string "它的自然风貌。\p"
	.string "所以如果想到处转转的话会稍微有点\n"
	.string "困难。$"

