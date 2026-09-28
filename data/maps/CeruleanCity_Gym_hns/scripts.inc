CeruleanCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CERULEAN_GYM_ROCKET
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_HNS, CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA_HNS, CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER_HNS, CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "CERULEAN POKéMON GYM\n"
    .string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "华蓝市宝可梦道馆馆主：小霞\p"
    .string "胜出训练家：青绿、赤红、\n"
    .string "{PLAYER}$"

CeruleanGym_Text_Note:
	.string "抱歉，我出门一阵子。馆主 小霞\p"
	.string "既然小霞不在，我们也就出去啦。道\n"
	.string "馆训练家们$"


CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY_HNS, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers_hns
	msgbox CeruleanGym_Text_Misty_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	msgbox CeruleanGym_Text_Misty_ExplainTM, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_CAPE_MISTY
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanGym_Text_GruntIntro:
	.string "哎呀！真对不起！你没受伤吧？\p"
	.string "我忙得很。没时间跟你废话。要是被\n"
	.string "谁看到，我可就麻烦了。$"

CeruleanGym_Text_GruntBigMistake:
	.string "糟了！你已经看到我了！我犯了大失\n"
	.string "误！$"

CeruleanGym_Text_GruntBye:
	.string "Hey, you! Forget you see me,\n"
	.string "okay?\p"
	.string "You see, hear, know nothing,\p"
	.string "okay? Bye, kid! Nothing!\p"
	.string "Bye-bye a go-go!$"

CeruleanGym_Text_Note1:
	.string "抱歉，我出门一阵子。馆主 小霞\p"
	.string "既然小霞不在，我们也就出去啦。道\n"
	.string "馆训练家们$"

CeruleanGym_Text_MistyIntro:
	.string "小霞：我可一直在等你呢，你这个碍\n"
	.string "事鬼！\p"
	.string "就算你拿到了很多城都的徽章，也最\n"
	.string "好别太小看我哦。\p"
	.string "我的水属性宝可梦可是很厉害的！$"

CeruleanGym_Text_MistyWinLoss:
	.string "小霞：你真的很强呢......\p"
	.string "我承认你的实力了......\p"
	.string "这个给你。这是蓝色徽章。$"

CeruleanGym_Text_ReceivedBadge:
	.string "{PLAYER}获得了蓝色徽章。$"

CeruleanGym_Text_MistyFightDone:
	.string "小霞：城都地区有很多像你一样厉害\n"
	.string "的训练家吗？\p"
	.string "总有一天我也要去旅行，去会会那些\n"
	.string "实力出众的训练家。$"

CeruleanGym_Text_MistyRematch:
	.string "小霞：哇，你现在已经是关都的冠军\n"
	.string "了啊！\p"
	.string "太厉害了！你这一路成长了好多呢，\n"
	.string "{PLAYER}。\p"
	.string "但我可不会认输哦。\p"
	.string "要跟我再比一场吗？$"

CeruleanGym_Text_MistyRematchDefeat:
	.string "小霞：你真的很厉害呢......$"

CeruleanGym_Text_SwimmerfDianaSeen:
	.string "抱歉刚刚不在。我们快开始吧！$"

CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "我认输！是你赢了！$"

CeruleanGym_Text_SwimmerfDianaAfter:
	.string "我就安安静静地游会儿泳吧。$"

CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "可别被我优雅的泳姿扰乱了心神哦。$"

CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "呜，你居然这么从容地就解决了我.\n"
	.string ".....$"

CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "打赢了我可别太得意忘形。\p"
	.string "你要是大意的话，小霞一定会把你打\n"
	.string "得落花流水的。$"

CeruleanGym_Text_SwimmermParkerSeen:
	.string "咕噜咕噜......\p"
	.string "我是第一个！放马过来吧！$"

CeruleanGym_Text_SwimmermParkerBeaten:
	.string "怎么会这样......$"

CeruleanGym_Text_SwimmermParkerAfter:
	.string "小霞这几年的实力可是突飞猛进呢。\p"
	.string "千万别掉以轻心，否则会被彻底击垮\n"
	.string "的！$"

CeruleanGym_Text_GuideIntro:
	.string "Yo! CHAMP in making!\p"
	.string "Since MISTY was away, I went out\p"
	.string "for some fun too. He-he-he.$"

CeruleanGym_Text_GuideWin:
	.string "呼，让我见识到了你的厉害！\p"
	.string "一如既往，真是一场无比精彩的对战\n"
	.string "啊！$"

CeruleanGym_Text_Misty_GiveTM:
	.string "来，把这个也收下吧。$"

CeruleanGym_Text_Misty_ExplainTM:
	.string "It's the WATER PULSE TM.\p"
	.string "It causes damage and sometimes\n"
	.string "causes confusion as well!$"
