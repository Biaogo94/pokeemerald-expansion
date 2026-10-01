Gate_NationalPark_hns_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "你好，训练家！捕虫大会今天正在举\n"
	.string "办哦。\p"
	.string "规则非常简单。\p"
	.string "只使用你的一只宝可梦，捕获虫属性\n"
	.string "宝可梦来进行评判。\p"
	.string "你要来参加挑战吗？$"

Route35NationalParkGate_Text_OfficerGiveSportBalls:
	.string "宝可梦在比赛期间获得的经验值，会\n"
	.string "在你离开时全部还原。\p"
	.string "这是比赛专用的竞赛球。$"

Route35NationalParkGate_Text_ReceivedSportBalls:
	.string "{PLAYER}获得了竞赛球。$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "捕获到最强虫属性宝可梦的人就是胜\n"
	.string "者。\p"
	.string "如果竞赛球用光了，比赛就结束了。\p"
	.string "你最多可以捕获5只宝可梦。但最终\n"
	.string "只能保留并评判最后抓到的那一只。\p"
	.string "去捕获你能找到的最强的虫属性宝可\n"
	.string "梦吧！$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "如果你携带了不止一只宝可梦，就只\n"
	.string "能使用同伴队伍里的第一只。\p"
	.string "这样可以吗？$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "好的，在比赛期间，我们会代为保管\n"
	.string "你的其他宝可梦。$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "{PLAYER}将宝可梦寄放在了\n"
	.string "大会服务人员那里。$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "请选好要参加比赛的宝可梦，然后再\n"
	.string "来找我吧。$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "好的。期待你下次的参与！$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "哎呀……你同行队伍排在首位的宝可梦\n"
	.string "无法战斗。\p"
	.string "请把它换成你想派出的宝可梦，然后\n"
	.string "再来找我吧。$"

Route35NationalParkGate_Text_MakeRoom:
	.string "哎呀……你的同行队伍和电脑盒子全都\n"
	.string "满了。\p"
	.string "这样就没有空间存放你捕获的虫属性\n"
	.string "宝可梦了。\p"
	.string "请整理出同行队伍或电脑盒子的空位\n"
	.string "后再来找我吧。$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "哎呀……你同行队伍排在首位的是一颗\n"
	.string "蛋呢。\p"
	.string "请把它换成你想派出的宝可梦，然后\n"
	.string "再来找我吧。$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "今天的比赛已经结束了。期待你下次\n"
	.string "再来参加。$"

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "我最喜欢鸟宝可梦了！昨晚我在公园\n"
	.string "里发现了一只恶属性的鸟呢！$"

Route35NationalParkGate_Text_BC2:
	.string "我抓到了一只超大的飞天螳螂！$"

Route35NationalParkGate_Text_Beauty:
	.string "每次比赛获胜的都是他！$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "公园里会定期举办比赛。你也该来挑\n"
	.string "战一下。$"

Route35NationalParkGate_Text_YoungsterWonders:
	.string "下一次捕虫大赛是什么时候呀？$"

Route35NationalParkGate_Text_ContestExplanation:
	.string "捕虫大赛会在周二、周四和周六举\n"
	.string "办。\p"
	.string "只要参加就能获得奖品，\p"
	.string "而且比赛结束时留下的虫属性宝可梦\n"
	.string "也能直接带走哦。$"
