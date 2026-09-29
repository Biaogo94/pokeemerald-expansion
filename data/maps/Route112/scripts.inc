Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing:
	.string "喂，我们老大真的打算唤醒那东西？$"

Route112_Text_YeahWeNeedMeteorite:
	.string "嗯，听上去是这样，但据说我们还需\n"
	.string "要一块陨石。$"

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.string "哦，我明白了，所以大家才会去秋叶\n"
	.string "镇。$"

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.string "说得没错。而且在他们回来前，我们\n"
	.string "不能让任何人通过这里。$"

Route112_Text_NotEasyToGetBackToLavaridge:
	.string "呃，我想去紫堇市，但如果我从这些\n"
	.string "岩脊上走下去，再回到釜炎镇就没那\l"
	.string "么容易了。$"

Route112_Text_MtChimneyCableCarSign:
	.string "烟突山缆车\n"
	.string "“步行{UP_ARROW}一小段路即到！”$"

Route112_Text_MtChimneySign:
	.string "烟囱山\p"
	.string "“去釜炎镇或山顶，请乘坐缆车。”$"

Route112_Text_RouteSignLavaridge:
	.string "112号道路\n"
	.string "{LEFT_ARROW}釜炎镇$"

