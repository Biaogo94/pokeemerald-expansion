EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "米可利：欢迎，{PLAYER}{KUN}。\p"
	.string "琉璃市的那起事件……\n"
	.string "你独自一人平息了那场危机，\l"
	.string "干得实在漂亮。\p"
	.string "哎呀！\p"
	.string "说你一个人平息了危机，\n"
	.string "这可不公平。\p"
	.string "你是与宝可梦齐心协力，\n"
	.string "才克服了那个艰难的局面。\p"
	.string "我们训练家通过赠送道具、\n"
	.string "传授新的对战技巧来培育宝可梦。\l"
	.string "但我们自己也在宝可梦身上\n"
	.string "学到许多东西。\p"
	.string "而在这里，你的成就将与其他\n"
	.string "志同道合者一较高下。\l"
	.string "现在！\p"
	.string "在丰缘地区，谁能与宝可梦\n"
	.string "舞出最优雅的姿态？\p"
	.string "现在就在这里展示给我看吧！$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "我，冠军，输了……\p"
	.string "美妙得令人赞叹！优雅得令人眼红！\n"
	.string "这实在是太～辉煌耀眼了！！\p"
	.string "光荣属于你，{PLAYER}\n"
	.string "{KUN}！\p"
	.string "你是一名真正高贵的宝可梦训练家！$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "米可利：你的宝可梦在对战中……\p"
	.string "时而轻柔如风，时而又迅猛如雷。\p"
	.string "还带着一丝，无疑是从你那里耳濡目\n"
	.string "染所得的，轻盈而坚定的优雅。\p"
	.string "甚至连我都为你出色的表现而深深地\n"
	.string "着迷！\p"
	.string "此刻你已站上宝可梦联盟光荣的顶峰\n"
	.string "，\p"
	.string "我宣布你已成为丰缘地区的新……$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "小遥：{PLAYER}{KUN}\n"
	.string "！\p"
	.string "挑战冠军前给你几个建议……$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "小遥：咦？什么？\p"
	.string "{PLAYER}{KUN}……难\n"
	.string "道说……已经结束了？$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "小悠：{PLAYER}！\p"
	.string "挑战冠军前需要建议吗……？$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "小悠：{PLAYER}……\p"
	.string "你该不会……已经打败冠军了？$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "小田卷博士：看吧？我说什么来着，\n"
	.string "{RIVAL}？\p"
	.string "早就告诉你{PLAYER}\n"
	.string "{KUN}不用我们担心！\p"
	.string "…… …… …… ……\n"
	.string "{PLAYER}{KUN}，你终\l"
	.string "于做到了。\p"
	.string "当我听说你在橙华道馆打败了你的父\n"
	.string "亲，我就预感你可能有机会……\p"
	.string "但是没想到你现在真的成为了冠军！\p"
	.string "啊，对了！\p"
	.string "你的图鉴完成得如何了？来，让我看\n"
	.string "一下。$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "小田卷博士：总之恭喜你！\p"
	.string "现在，昂首挺胸地走进最后的房间吧\n"
	.string "！$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "米可利：{PLAYER}\n"
	.string "{KUN}……\p"
	.string "不，请容我改口。\p"
	.string "新任冠军！\p"
	.string "跟我来。$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "米可利：我很抱歉，不过……\p"
	.string "从这里开始，只有成为冠军的训练家\n"
	.string "才能进入。\p"
	.string "请你和小田卷博士一起在外面等候吧\n"
	.string "。$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "小遥：哎……\p"
	.string "…… …… …… ……\n"
	.string "…… …… …… ……\p"
	.string "我开玩笑啦！没关系！毕竟是规定嘛\n"
	.string "！\p"
	.string "{PLAYER}{KUN}！真的\n"
	.string "恭喜你！$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "小悠：什么？！…… …… ………\n"
	.string "… …… …… ……\p"
	.string "既然是规定，那也没办法。\p"
	.string "{PLAYER}，去吧！恭喜你！$"

