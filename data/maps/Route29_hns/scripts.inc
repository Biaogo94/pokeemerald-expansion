Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "按A键或B键退出查看。$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "宝可梦就藏在草丛里。天知道它们什\n"
	.string "么时候会跳出来……$"

Route29_Text_OldMan2:
	.string "我见过你几次了呢。你抓到了多少只\n"
	.string "宝可梦？\p"
	.string "需要我教你怎么捕捉宝可梦吗？$"

Route29_Text_OldManExplanation:
	.string "如果先削弱它们的体力，宝可梦就会\n"
	.string "更容易被收服。\p"
	.string "接着从背包里对它们扔出精灵球！任\n"
	.string "何球都行。\p"
	.string "如果想了解更多技巧，就去桔梗市的\n"
	.string "学院看看吧！\p"
	.string "那里的学生们对宝可梦可了解了。$"

Route29_Text_OldManDeclined:
	.string "哦，那好吧。\p"
	.string "去不同的道路上探索，能发现各种各\n"
	.string "样的宝可梦哦。\p"
	.string "你的宝可梦图鉴上也会显示它们的栖\n"
	.string "息地！\p"
	.string "如果想了解更多技巧，就去桔梗市的\n"
	.string "学院看看吧！\p"
	.string "学生们对宝可梦可了解了。$"

Route29_Text_Youngster:
	.string "哟，你的宝可梦状态如何？\p"
	.string "要是它们体力不支，还没准备好战斗\n"
	.string "，就离草丛远一点。$"

Route29_Text_Lass:
	.string "看到那些台阶了吗？跳下去感觉还挺\n"
	.string "吓人的。\p"
	.string "不过这样你不用穿过草丛就能回到若\n"
	.string "叶镇了。$"

Route29_Text_Girl:
	.string "我想休息一下，所以存了个档记录冒\n"
	.string "险进度。$"

Route29_Text_Boy_WaitingForDay:
	.string "我在等那些只有在天色渐晚时才会出\n"
	.string "现的宝可梦。$"

Route29_Text_Boy_WaitingForNight:
	.string "我在等那些只有在夜晚才会出现的宝\n"
	.string "可梦。$"

Route29_Text_MeetTuscany:
	.string "蜜儿：我们应该是第一次见面吧？\p"
	.string "我是星期家族的蜜儿。\p"
	.string "要是你能猜出我最喜欢星期几，我就\n"
	.string "给你一份奖励。$"

Route29_Text_TuscanyNope:
	.string "不对哦！$"

Route29_Text_TuscanyGivesGift:
	.string "答对啦！初次见面，请收下这份礼物\n"
	.string "--丝绸围巾。$"

Route29_Text_TuscanyGaveGift:
	.string "蜜儿：你不觉得它非常可爱吗？\p"
	.string "它能增强一般属性招式的威力。\p"
	.string "我相信它一定能派上用场。$"

Route29_Text_TuscanyTuesday:
	.string "蜜儿：你见过我的姐姐月子了吗？\p"
	.string "还有我的弟弟水夫呢？\p"
	.string "我在七兄妹里排行第三哦。$"

Route29_Text_Sign1:
	.string "29号道路\p"
	.string "吉花市 - 若叶镇$"

