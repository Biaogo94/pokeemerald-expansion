Route10_PowerPlantEntrance_hns_MapScripts::
	.byte 0

Route10_PowerPlantEntrance_EventScript_Cop::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopAfterDone
	msgbox Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopDuringRocket::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopAfterDone::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_Engineer1::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer1Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer1Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer2Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Cop2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Cop2Done
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious, MSGBOX_NPC
	end
Route10_PowerPlantEntrance_EventScript_Cop2Done::
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer3Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_Trigger_Cop::
	lock
	playse SE_POKENAV_CALL
	applymovement2 LOCALID_POWERPLANT_COP, Common_Movement_ExclamationMark
	waitse
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkToPlayer
	waitmovement 0
	turnobject LOCALID_POWERPLANT_ENGINEER, DIR_SOUTH
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_POWERPLANT_COP, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkBack
	waitmovement 0
	setvar VAR_KANTO_ROCKET_STORY_STATE, 2
	clearflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	release
	end

Route10_PowerPlantEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route10_PowerPlantEntrance_Movement_WalkBack:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn:
	.string "竟然有贼潜入了发电厂……\p"
	.string "这世道到底是怎么了？$"

Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter:
	.string "我刚收到来自华蓝市的消息。\p"
	.string "据说有个形迹可疑的家伙在那一带鬼\n"
	.string "鬼祟祟地游荡。$"

Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation:
	.string "能请你协助我们调查吗？$"

Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity:
	.string "看来我们必须加强安保力量了。$"

Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart:
	.string "有人偷走了发电机所必需的重要零\n"
	.string "件。\p"
	.string "要是没有那个，新发电机就根本无法\n"
	.string "运转！$"

Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning:
	.string "发电机已经顺利运转起来了。现在电\n"
	.string "力充沛，甚至绰绰有余呢。$"

Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning:
	.string "这座发电厂过去曾经被废弃过。\p"
	.string "为了给磁浮列车供电，我们才让它重\n"
	.string "新恢复运转。$"

Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain:
	.string "发电机又重新运转了！$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious:
	.string "发电厂的厂长在后面的发电机机房\n"
	.string "里。\p"
	.string "不过自从有人破坏了发电机之后，他\n"
	.string "就又伤心又愤怒……$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful:
	.string "自从发电机修好之后，厂长的心情就\n"
	.string "变得特别好。$"

Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity:
	.string "磁浮列车要消耗大量的电力。\p"
	.string "要是新发电机不运转的话，列车根本\n"
	.string "就动不了。$"

Route10_PowerPlantEntrance_EventScript_Lorenzo::
	lock
	faceplayer
	goto_if_set FLAG_POWERPLANT_NPC_TRADE_COMPLETED, Route10_PowerPlantEntrance_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MAGNETON, Route10_PowerPlantEntrance_Text_WantToTrade, Route10_PowerPlantEntrance_EventScript_DeclineTrade, Route10_PowerPlantEntrance_EventScript_NotRequestedMon, Route10_PowerPlantEntrance_Text_TakeCare
	setflag FLAG_POWERPLANT_NPC_TRADE_COMPLETED
	release
	end

Route10_PowerPlantEntrance_EventScript_DeclineTrade::
	msgbox Route10_PowerPlantEntrance_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route10_PowerPlantEntrance_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_TradeCompleted::
	msgbox Route10_PowerPlantEntrance_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_Text_WantToTrade:
	.string "我在这家发电厂工作。我的三合一磁\n"
	.string "怪伴随我好多年了。\p"
	.string "但我一直很想要一只\n"
	.string "{STR_VAR_1}。\p"
	.string "你愿意用它来交换我的\n"
	.string "{STR_VAR_2}吗？$"

Route10_PowerPlantEntrance_Text_TakeCare:
	.string "谢谢你！请替我好好照顾小磁！$"

Route10_PowerPlantEntrance_Text_DeclineTrade:
	.string "不行吗？那可真遗憾。我的三合一磁\n"
	.string "怪工作可卖力了。$"

Route10_PowerPlantEntrance_Text_NotRequestedMon:
	.string "唔，这不是{STR_VAR_1}\n"
	.string "呀。不是我想要的宝可梦呢。$"

Route10_PowerPlantEntrance_Text_TradeCompleted:
	.string "小磁过得还好吗？它可喜欢磁场了！$"

Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning:
	.string "太好了！磁浮列车终于可以重新运行\n"
	.string "了。$"
