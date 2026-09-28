Route14_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route14_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route14_TriggerSuicune_5::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_5
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_4::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_4
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_3::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_3
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_2::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_1::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	goto Route14_EventScript_Suicune

Route14_Movement_5:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_4:
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_3:
	walk_right
	walk_right
	step_end

Route14_EventScript_Suicune::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE14_SUICUNE, Route14_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE14_EUSINE
	addobject LOCALID_ROUTE14_EUSINE
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineEnter
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 0
	msgbox Route14_Text_Eusine, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineLeave
	waitmovement 0
	setflag FLAG_HIDE_ROUTE14_EUSINE
	setflag FLAG_HIDE_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 5
	call_if_ge VAR_CERULEAN_CITY_STATE, 3, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

Route14_Movement_SuicuneLeave:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	step_end

Route14_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	walk_slow_right
	step_end

Route14_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER_HNS, Route14_Text_PokefanmCarterSeen, Route14_Text_PokefanmCarterBeaten, Route14_EventScript_RegisterCarter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route14_EventScript_RematchCarter
	msgbox Route14_Text_PokefanmCarterAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RegisterCarter::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_CarterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CARTER_HNS
	release
	end

Route14_EventScript_RematchCarter::
	trainerbattle_rematch TRAINER_CARTER_HNS, Route14_Text_CarterRematchIntro, Route14_Text_CarterRematchDefeat
	msgbox Route14_Text_CarterPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CARTER_2_HNS, Route14_EventScript_RematchCarterTryGiveItem
	end

Route14_EventScript_RematchCarterTryGiveItem::
	checkitem ITEM_TM_THUNDER_WAVE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_THUNDER_WAVE
	closemessage
	end

Route14_EventScript_Roy::
	trainerbattle_single TRAINER_ROY_HNS, Route14_Text_BirdKeeperRoySeen, Route14_Text_BirdKeeperRoyBeaten
	msgbox Route14_Text_BirdKeeperRoyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR_HNS, Route14_Text_PokefanmTrevorSeen, Route14_Text_PokefanmTrevorBeaten, Route14_EventScript_RegisterTrevor
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route14_EventScript_RematchTrevor
	msgbox Route14_Text_PokefanmTrevorAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RegisterTrevor::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_TrevorRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TREVOR_HNS
	release
	end

Route14_EventScript_RematchTrevor::
	trainerbattle_rematch TRAINER_TREVOR_HNS, Route14_Text_TrevorRematchIntro, Route14_Text_TrevorRematchDefeat
	msgbox Route14_Text_TrevorPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_TREVOR_2_HNS, Route14_EventScript_RematchTrevorTryGiveItem
	end

Route14_EventScript_RematchTrevorTryGiveItem::
	checkitem ITEM_TM_WILL_O_WISP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_WILL_O_WISP
	closemessage
	end



Route14_Text_Eusine:
	.string "米那君：{PLAYER}！又慢了\n"
	.string "一步！下次我一定会先赶到的！\p"
	.string "一路追踪到这里，我开始明白水君在\n"
	.string "追求什么了。\p"
	.string "说实话，这个情报我原本是想藏私的\n"
	.string "。\p"
	.string "但在水君面前，我想做个光明磊落的\n"
	.string "训练家！\p"
	.string "所以，我就把线索也分享给你吧。\p"
	.string "据说......水君喜欢高地..\n"
	.string "....靠近水边......而且\l"
	.string "在北方某个地方......\p"
	.string "具体在哪里我现在还不知道。只有我\n"
	.string "和你！\p"
	.string "看谁能先找到它！我要向你发起挑战\n"
	.string "！$"

Route14_Text_PokefanmTrevorSeen:
	.string "你好。你知道吗......？\p"
	.string "如果带宝可梦在它们有记忆的地方培\n"
	.string "育，它们会变得更加亲密哦。$"

Route14_Text_PokefanmTrevorBeaten:
	.string "我是在哪里遇到这只巨钳螳螂的来着\n"
	.string "？$"

Route14_Text_PokefanmTrevorAfterBattle:
	.string "要是有个能轻松查出宝可梦是在哪儿\n"
	.string "捕获的方法就好了......$"

Route14_Text_TrevorRegister:
	.string "你真有意思！能把电话号码告诉我吗\n"
	.string "？$"

Route14_Text_TrevorRematchIntro:
	.string "我一直在宝可梦熟悉的地方和它们一\n"
	.string "起特训呢！$"

Route14_Text_TrevorRematchDefeat:
	.string "也许我该去些新地方了......$"

Route14_Text_TrevorPostRematch:
	.string "亲密度能让宝可梦变得更强。我对此\n"
	.string "坚信不疑！$"

Route14_Text_PokefanmCarterSeen:
	.string "我跟你说，我为了捉到我最宝贝的宝\n"
	.string "可梦，可吃了不少苦头呢。$"

Route14_Text_PokefanmCarterBeaten:
	.string "哇啊啊啊！$"

Route14_Text_PokefanmCarterAfterBattle:
	.string "小锯鳄、火球鼠、菊草叶.....\n"
	.string ".\p"
	.string "我觉得这是个搭配很均衡的组合。$"

Route14_Text_CarterRegister:
	.string "你很懂最初的伙伴嘛！把电话号码留\n"
	.string "给我吧！$"

Route14_Text_CarterRematchIntro:
	.string "我又找到了更多稀有的最初伙伴来炫\n"
	.string "耀了！来对战吧！$"

Route14_Text_CarterRematchDefeat:
	.string "我宝贝的最初伙伴们......$"

Route14_Text_CarterPostRematch:
	.string "不同地区有好多最初的伙伴可以收集\n"
	.string "呢！$"

Route14_Text_BirdKeeperRoySeen:
	.string "我的梦想是和我心爱的鸟宝可梦一起\n"
	.string "在天空中翱翔。$"

Route14_Text_BirdKeeperRoyBeaten:
	.string "做梦归做梦，可我根本飞不起来啊.\n"
	.string ".....$"

Route14_Text_BirdKeeperRoyAfterBattle:
	.string "You have POKéMON that know the HM\n"
	.string "move FLY, don't you? I envy you.$"

Route14_EventScript_Pidgeotto::
	lockall
	faceplayer
	playmoncry SPECIES_PIDGEOTTO, CRY_MODE_NORMAL
	msgbox Route14_Text_Pidgeotto, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_GOT_ROUTE_14_AERIAL_ACE, Route14_EventScript_PidgeottoBlowPlayer
	msgbox Route14_Text_PidgeottoBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route14_EventScript_PidgeottoBlowPlayer
	fadescreen FADE_TO_BLACK
	special Bag_ChooseBerry
	waitstate
	removeitem VAR_ITEM_ID, 1
	goto_if_ne VAR_ITEM_ID, ITEM_QUALOT_BERRY, Route14_EventScript_PidgeottoDislikedBerry
	msgbox Route14_Text_PidgeottoAteBerry, MSGBOX_DEFAULT
	giveitem ITEM_TM_AERIAL_ACE
	setflag FLAG_GOT_ROUTE_14_AERIAL_ACE
Route14_EventScript_PidgeottoBlowPlayer::
	closemessage
	playse SE_M_TWISTER
	call_if_eq VAR_FACING, DIR_EAST, Route14_EventScript_PidgeottoBlowPlayerLeft
	releaseall
	end
Route14_EventScript_PidgeottoDislikedBerry::
	msgbox Route14_Text_PidgeottoTurnedAway, MSGBOX_DEFAULT
	goto Route14_EventScript_PidgeottoBlowPlayer

Route14_EventScript_PidgeottoBlowPlayerLeft::
	applymovement LOCALID_ROUTE14_PIDGEOTTO, Route14_Movement_JumpLeft
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_Player_BlownLeft
	waitmovement 0
	return

Route14_Movement_Player_BlownUp:
	lock_facing_direction
	walk_up
	walk_up
	unlock_facing_direction
	step_end

Route14_Movement_Player_BlownLeft:
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	lock_facing_direction
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Route14_Movement_JumpUp:
	jump_in_place_up
	step_end

Route14_Movement_JumpLeft:
	jump_in_place_left
	step_end

Route14_Movement_StuckPidgeottoJump0:
	jump_in_place_up
	step_end

Route14_Movement_StuckPidgeottoJump:
	jump_2_up
	jump_in_place_left_right
	jump_in_place_left_right
	face_left
	step_end

Route14_Text_Pidgeotto:
	.string "比比鸟：嘎啊啊--！$"
Route14_Text_PidgeottoBerry:
	.string "要给比比鸟树果吗？$"
Route14_Text_PidgeottoAteBerry:
	.string "比比鸟很开心地吃了蜜柚果！$"
Route14_Text_PidgeottoTurnedAway:
	.string "比比鸟不喜欢这个！$"

