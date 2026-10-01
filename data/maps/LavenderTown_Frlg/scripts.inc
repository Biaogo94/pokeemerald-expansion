LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
	.string "你相信世界上有幽灵吗？$"

LavenderTown_Text_SoThereAreBelievers::
	.string "真的？真有相信的啊……$"

LavenderTown_Text_JustImaginingWhiteHand::
	.string "哈哈哈，我可不这么认为喔。\p"
	.string "看你肩膀上那只白色的鬼手…………这只\n"
	.string "是我的想象而已。$"

LavenderTown_Text_TownKnownAsMonGraveSite::
	.string "这座城镇是宝可梦的墓地。\p"
	.string "追悼仪式会在宝可梦塔举行。$"

LavenderTown_Text_GhostsAppearedInTower::
	.string "幽灵在宝可梦塔里出没。\p"
	.string "我想那应该是被火箭队所害的宝可梦\n"
	.string "的灵魂吧。$"

LavenderTown_Text_TownSign::
	.string "紫苑镇：高贵优雅的紫色小镇$"

LavenderTown_Text_SilphScopeNotice::
	.string "新的西尔佛观测镜！让无形的东西变\n"
	.string "得有形！\p"
	.string "西尔佛公司$"

LavenderTown_Text_VolunteerPokemonHouse::
	.string "紫苑宝可梦宝可梦之家$"

LavenderTown_Text_PokemonTowerSign::
	.string "宝可梦塔宝可梦的灵魂在这里安息$"

