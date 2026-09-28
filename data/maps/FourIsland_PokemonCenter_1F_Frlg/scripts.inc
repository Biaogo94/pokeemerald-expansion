FourIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FourIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FOUR_ISLAND
	end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FourIsland_PokemonCenter_1F_EventScript_Man::
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Woman::
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
	end

@ The 5 texts below are supposed to be in FourIsland_House1
Text_BodySlamTeach::
	.string "准备好了吗？啪啪啪！\p"
	.string "我们在举行泰山压顶比赛。我倒要看\n"
	.string "看是谁先倒下。\p"
	.string "即使你让加入我们，你也是一个新手\n"
	.string "。\p"
	.string "不如让我把泰山压顶教给你的一只宝\n"
	.string "可梦怎么样？$"

Text_BodySlamDeclined::
	.string "下次再来吧！啪啪啪！$"

Text_BodySlamWhichMon::
	.string "想让哪只宝可梦掌握泰山压顶？$"

Text_BodySlamTaught::
	.string "啪啪啪$"

FourIsland_House1_Text_FatMan::
	.string "看招，啵呦--！你可真沉啊--！$"

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
	.string "在那个洞穴里住着一只稀有的冰属性\n"
	.string "宝可梦。\p"
	.string "很多游客都想去亲眼见识一下那只宝\n"
	.string "可梦。$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
	.string "什么？宝可梦的蛋？……我不知道。\p"
	.string "……哦，我想起来了！培育屋的人在\n"
	.string "城镇里说过什么。\p"
	.string "他们过去在他们的房屋里找到了蛋。$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
	.string "这是？\p"
	.string "新的宝可梦特刊还没有送到这座岛上\n"
	.string "来吗？$"

