SilphCo_7F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
	.string "啊！你！你不是火箭队的吧！你是来\n"
	.string "救我们吗？呃，谢谢！\p"
	.string "我想把这个宝可梦送给你来表达感\n"
	.string "谢。$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
	.string "{PLAYER}从西尔佛的员工处\n"
	.string "得到了一只拉普拉斯！$"

SilphCo_7F_Text_ExplainLapras::
	.string "它是一个拉普拉斯。这是一个很聪明\n"
	.string "的宝可梦。\p"
	.string "我们一直养在我们的实验室里，但它\n"
	.string "在你手里会更有用。\p"
	.string "我想你会成为一个优秀的拉普拉斯训\n"
	.string "练家！\p"
	.string "它是一只游泳高手。它可以带你漫游\n"
	.string "四海！$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
	.string "火箭队的老大去了会议室！\p"
	.string "我们的总裁还好吗？我很担心。$"

SilphCo_7F_Text_RocketsAfterMasterBall::
	.string "火箭队在找大师球，那是能抓住任何\n"
	.string "宝可梦的精灵球。$"

SilphCo_7F_Text_CanceledMasterBallProject::
	.string "我们取消了大师球项目就是因为担心\n"
	.string "火箭队。$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
	.string "如果火箭队接管西尔佛或者宝可梦的\n"
	.string "话事情就难以想象了。$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
	.string "哇喔！\p"
	.string "你一个人就赶走了全部火箭队？$"

SilphCo_7F_Text_ReallyDangerousHere::
	.string "你！这里真的很危险！\p"
	.string "你来救我的？你做不到的！$"

SilphCo_7F_Text_ThankYouSoMuch::
	.string "太感谢你了！$"

SilphCo_7F_Text_Grunt3Intro::
	.string "嗯，哦！我闻到了一只小老鼠的味\n"
	.string "道！$"

SilphCo_7F_Text_Grunt3Defeat::
	.string "看不见了！$"

SilphCo_7F_Text_Grunt3PostBattle::
	.string "你到处乱窜是不会找到我们的老大\n"
	.string "的！$"

SilphCo_7F_Text_JoshuaIntro::
	.string "呵呵呵！\p"
	.string "你当我是西尔佛的员工？$"

SilphCo_7F_Text_JoshuaDefeat::
	.string "我完成了！$"

SilphCo_7F_Text_JoshuaPostBattle::
	.string "尽管你如此年轻，你也是一个技术高\n"
	.string "超的训练家！$"

SilphCo_7F_Text_Grunt1Intro::
	.string "我是火箭队四兄弟之一！$"

SilphCo_7F_Text_Grunt1Defeat::
	.string "哎咳！哥哥，我输了！$"

SilphCo_7F_Text_Grunt1PostBattle::
	.string "没关系。我的哥哥们会好好回报你\n"
	.string "的！$"

SilphCo_7F_Text_Grunt2Intro::
	.string "一个少年入侵者？那一定就是你！$"

SilphCo_7F_Text_Grunt2Defeat::
	.string "好吧！我输了！$"

SilphCo_7F_Text_Grunt2PostBattle::
	.string "在把我们的老大惹火之前赶快回家\n"
	.string "吧！$"

SilphCo_7F_Text_RivalWhatKeptYou::
	.string "{RIVAL}：你来的可真慢，\n"
	.string "{PLAYER}？$"

SilphCo_7F_Text_RivalIntro::
	.string "{RIVAL}：哈哈哈！我等在这\n"
	.string "儿还以为会让你感动万分呢！\p"
	.string "我猜火箭队拖慢了你的脚步？我才不\n"
	.string "会管那些呢！\p"
	.string "我在金黄市看到了你，所以我决定来\n"
	.string "看看你是否有所成长了！$"

SilphCo_7F_Text_RivalDefeat::
	.string "哎呀哎呀！那么，看来你准备好面对\n"
	.string "火箭队的老大了啊！$"

SilphCo_7F_Text_RivalPostBattle::
	.string "好，{PLAYER}！那我先走一\n"
	.string "步了！\p"
	.string "只要查询宝可梦图鉴，我就能知道哪\n"
	.string "个宝可梦比较强以及它们是怎么进化\l"
	.string "的！\p"
	.string "哈哈我真是个天才啊\p"
	.string "我准备去宝可梦联盟把四天王消灭\n"
	.string "掉。\p"
	.string "我将会成为世界上最强大的训练家！\p"
	.string "{PLAYER}，嗯，祝你好运！\n"
	.string "别翻白眼哦！哈哈！$"

SilphCo_7F_Text_FloorSign::
	.string "西尔佛公司总部7层$"

