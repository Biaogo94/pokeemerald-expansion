SilphCo_6F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
	.string "火箭队闯进来占领了这幢大厦！$"

SilphCo_6F_Text_BetterGetBackToWork::
	.string "嘛，最好回去继续工作。$"

SilphCo_6F_Text_HelpMePlease::
	.string "哦，天哪，我的天哪。救命， 请救\n"
	.string "救我们！$"

SilphCo_6F_Text_WeGotEngaged::
	.string "我们订婚了。呵呵！$"

SilphCo_6F_Text_ThatManIsSuchACoward::
	.string "我旁边的那个男人……他居然是这样\n"
	.string "的一个懦夫！$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
	.string "他很绝望，他需要像我这样的人来照\n"
	.string "顾他。$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
	.string "火箭队正试图用宝可梦征服世界。$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
	.string "火箭队逃跑了，这都对亏有你！$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
	.string "他们一定是因为宝可梦产品而盯上了\n"
	.string "我们西尔佛。$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
	.string "等你长大了就来西尔佛来上班吧。$"

SilphCo_6F_Text_Grunt1Intro::
	.string "我是火箭队四兄弟之一！$"

SilphCo_6F_Text_Grunt1Defeat::
	.string "真让人火大！$"

SilphCo_6F_Text_Grunt1PostBattle::
	.string "没关系！我的兄弟们会为我报仇的！$"

SilphCo_6F_Text_TaylorIntro::
	.string "那个可恶的总裁！\p"
	.string "该死的家伙用船把我送到了缇斯基分\n"
	.string "部！\p"
	.string "我敢肯定这就是为什么火箭队追着我\n"
	.string "们不放！$"

SilphCo_6F_Text_TaylorDefeat::
	.string "该死！$"

SilphCo_6F_Text_TaylorPostBattle::
	.string "缇斯基分部？在俄罗斯语里这是无人\n"
	.string "岛的意思！$"

SilphCo_6F_Text_Grunt2Intro::
	.string "你竟敢出卖火箭队？$"

SilphCo_6F_Text_Grunt2Defeat::
	.string "你这个叛徒！$"

SilphCo_6F_Text_Grunt2PostBattle::
	.string "如果你代表正义，那你就出卖了我们\n"
	.string "这些坏家伙！$"

SilphCo_6F_Text_FloorSign::
	.string "西尔佛公司总部6层$"

