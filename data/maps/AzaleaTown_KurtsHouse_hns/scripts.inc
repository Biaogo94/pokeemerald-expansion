AzaleaTown_KurtsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
	end

AzaleaTown_KurtsHouse_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
	.2byte 0

AzaleaTown_KurtsHouse_EventScript_KurtBefore::
	lock
	faceplayer
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	setvar VAR_AZALEA_TOWN_STATE, 2
	release
	end

AzaleaTown_KurtsHouse_EventScript_PlayerMove::
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl2::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5

	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl3::
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl4::
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_Girl5::
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_FAST_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	setvar VAR_AZALEA_TOWN_STATE, 4
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
	return

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
	msgbox KurtsHouse_Text_KurtAskYouHaveAnApricorn, MSGBOX_DEFAULT
	closemessage
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
AzaleaTown_KurtsHouse_EventScript_Kurt2::
	special CreateKurtBallShop
	waitstate
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_KurtCancel
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, AzaleaTown_KurtsHouse_EventScript_TurnWest
	call_if_eq VAR_FACING, DIR_WEST, AzaleaTown_KurtsHouse_EventScript_TurnEast
	call_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_TurnSouth
	goto_if_eq VAR_0x8005, 1, AzaleaTown_KurtsHouse_EventScript_SingularBall
	bufferitemname STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	msgbox KurtsHouse_Text_KurtFinishedPlural, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedPlural
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_TurnSouth::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_SOUTH
	return
AzaleaTown_KurtsHouse_EventScript_TurnWest::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_WEST
	return
AzaleaTown_KurtsHouse_EventScript_TurnEast::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_EAST
	return


AzaleaTown_KurtsHouse_EventScript_SingularBall::
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox KurtsHouse_Text_KurtFinishedSingular, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedSingular
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCancel::
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GS_BALL
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	playse SE_M_PETAL_DANCE
	waitse
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
	waitmovement 0
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 8
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
KurtsHouse_Text_BallAnyway:
	.string "话说回来，要我帮你做几个球吗？$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	closemessage
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	closemessage
	end

AzaleaTownKurt_Movement_Look_Around:
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	delay_8
	face_left
	step_end

AzaleaTownKurt_Movement_Making_Ball:
	face_up
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	step_end

AzaleaTown_KurtsHouse_Movement_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KurtsHouse_Text_KurtGetStarted:
	.string "钢铁：我马上开工！$"

KurtsHouse_Text_KurtMakingBallsMustWait:
	.string "嗯？你是谁？\p"
	.string "是{PLAYER}啊？你想让我帮\n"
	.string "你做几个球？\p"
	.string "抱歉，那得等一等了。\p"
	.string "你听说过火箭队吗？啊，不要紧。\p"
	.string "反正我也会告诉你的。\p"
	.string "火箭队是个利用宝可梦干尽坏事的邪\n"
	.string "恶组织。\p"
	.string "他们本应在3年前就解散了。\p"
	.string "可现在他们竟然在井里，割下呆呆兽\n"
	.string "之尾拿去卖！\p"
	.string "所以我要去给他们一点苦头尝尝！\p"
	.string "撑住啊，呆呆兽！钢铁老头马上就来\n"
	.string "！$"

KurtsHouse_Text_KurtHonoredToMakeBalls:
	.string "钢铁：嗨，{PLAYER}！\p"
	.string "你在井里的表现就像个真正的英雄。\p"
	.string "我很欣赏你的作风！\p"
	.string "能为你这样的训练家做球，是我的荣\n"
	.string "幸。\p"
	.string "虽然我现在只有这个，但也请收下吧\n"
	.string "。$"

KurtsHouse_Text_KurtBallsFromApricorns:
	.string "钢铁：我能用树果来制作球。\p"
	.string "从树上采摘下来带给我吧。\p"
	.string "我会用它们做成精灵球。$"

KurtsHouse_Text_KurtAskYouHaveAnApricorn:
	.string "钢铁：你有树果要给我吗？\p"
	.string "好！我会把它们做成精灵球。$"

KurtsHouse_Text_KurtThatsALetdown:
	.string "钢铁：我没看到有\n"
	.string "{STR_VAR_1}啊！$"

KurtsHouse_Text_KurtFinishedPlural:
	.string "钢铁：{PLAYER}！你的\n"
	.string "{STR_VAR_1}做好了。给\l"
	.string "你！$"

KurtsHouse_Text_KurtObtainedPlural:
	.string "{PLAYER}获得了\n"
	.string "{STR_VAR_2}个\l"
	.string "{STR_VAR_1}！$"

KurtsHouse_Text_KurtFinishedSingular:
	.string "钢铁：{PLAYER}！你的\n"
	.string "{STR_VAR_1}做好了。给\l"
	.string "你！$"

KurtsHouse_Text_KurtObtainedSingular:
	.string "{PLAYER}获得了\n"
	.string "{STR_VAR_1}！$"

KurtsHouse_Text_KurtTurnedOutGreat:
	.string "钢铁：成果相当不错。\p"
	.string "试着用它去捕捉宝可梦吧。$"

KurtsHouse_Text_KurtWhatIsThat:
	.string "这、这是什么？\p"
	.string "我以前从没见过这东西。\p"
	.string "虽然看起来像个精灵球，但似乎又有\n"
	.string "些不同。\p"
	.string "让我帮你检查一下吧。$"

KurtsHouse_Text_KurtImCheckingItNow:
	.string "我现在正在调查呢。$"

KurtsHouse_Text_KurtAhHaISee:
	.string "啊哈！原来如此！这么说……\n"
	.string ".$"

KurtsHouse_Text_KurtThisBallStartedToShake:
	.string "{PLAYER}！\p"
	.string "在我调查的时候，这个球突然摇晃了\n"
	.string "起来。\p"
	.string "这里面一定有什么秘密！$"

KurtsHouse_Text_Kurt_Whatwasthat:
	.string "刚才那是什么声音？！\p"
	.string "我们去外面看看吧！$"

KurtsHouse_Text_GranddaughterSlowpokeGone:
	.string "呆呆兽们都不见了……是被\n"
	.string "坏人抓走了吗？$"

KurtsHouse_Text_GranddaughterLonely:
	.string "爷爷不在家……好寂寞啊。\n"
	.string ".....$"

KurtsHouse_Text_GranddaughterSlowpokeBack:
	.string "爸爸送我的呆呆兽回来啦！\p"
	.string "它的尾巴也长回来了！$"

KurtsHouse_Text_GranddaughterDad:
	.string "爸爸在西尔佛公司研究精灵球。\p"
	.string "我要留在家里陪爷爷和呆呆兽。$"

KurtsHouse_Text_GranddaughterHelp:
	.string "我现在也可以帮爷爷的忙了！\p"
	.string "我们会为你制作好球的，请稍等一下\n"
	.string "哦！$"

KurtsHouse_Text_GranddaughterFun:
	.string "做球真好玩！$"

KurtsHouse_Text_GranddaughterSound:
	.string "刚才的声音是从栎树林传来的吗？？\n"
	.string "？？$"

KurtsHouse_Text_Forest:
	.string "你去栎树林看过了吗？听起来那边很\n"
	.string "不安宁。$"

KurtsHouse_Text_Slowpoke:
	.string "呆呆兽：……呀嗯？$"

KurtsHouse_Text_OakPhoto:
	.string "……年轻的大木博士？$"

KurtsHouse_Text_CelebiStatue:
	.string "这是森林守护神的石像。$"
