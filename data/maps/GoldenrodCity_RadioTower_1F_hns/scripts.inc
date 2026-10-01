GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "小茜：嗨！\p"
	.string "我叫小茜！\p"
	.string "我听说这里有答题赢取广播卡的活\n"
	.string "动，就赶过来参加了……\p"
	.string "但这问答也太难了吧！$"

RadioTower1F_Text_Whitney2::
	.string "小茜：哇，你居然答对了！\p"
	.string "我还以为第三题的答案肯定是圆柑\n"
	.string "呢！哎呀！\p"
	.string "我也差不多该回道馆去啦！$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "欢迎光临！$"

RadioTower1F_Text_ReceptionistNoTours:
    .string "您好。真是不好意思，我们今天不提\n"
    .string "供参观导览。$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "我们现在正在举办答题特别活动。\p"
    .string "只要连续答对5道题，就能赢得宝可\n"
    .string "梦齿轮的广播卡。\p"
    .string "这样你和宝可梦无论何时何地都能收\n"
    .string "听美妙的音乐了。\p"
    .string "你要挑战一下答题吗？$"

RadioTower1F_Text_QuizQuestion1:
    .string "第1题：\p"
    .string "有没有只在白天出现的宝可梦？$"

RadioTower1F_Text_QuizQuestion2:
    .string "回答正确！第2题：\p"
    .string "下面这句话是对是错？\p"
    .string "友好商店里买不到树果。$"

RadioTower1F_Text_QuizQuestion3:
    .string "正中靶心！第3题：\p"
    .string "制作精灵球的钢铁先生，是用圆柑作\n"
    .string "为原料的吗？$"

RadioTower1F_Text_QuizQuestion4:
    .string "势头很棒哦！第4题：\p"
    .string "桔梗道馆的馆主阿速，使用的是鸟宝\n"
    .string "可梦吗？$"

RadioTower1F_Text_QuizQuestion5:
    .string "哇！又答对了！最后一道题：\p"
    .string "满金游戏城的摇奖机图案上有小火龙\n"
    .string "吗？$"

RadioTower1F_Text_QuizWin:
    .string "宾果！完全正确！恭喜你！\p"
    .string "这是你的奖品，广播卡！$"

RadioTower1F_Text_PokegearRadio:
    .string "{PLAYER}的宝可梦齿轮现在\n"
    .string "可以收听广播了！$"

RadioTower1F_Text_TuneIn:
    .string "请务必收听我们的广播节目哦。$"

RadioTower1F_Text_WrongAnswer:
    .string "哎呀。很遗憾，你回答错误。\p"
    .string "欢迎下次再来挑战！$"

RadioTower1F_Text_DeclineQuiz:
    .string "哎，这样啊。如果改变主意了，随时\n"
    .string "欢迎再来找我。$"

RadioTower1F_Text_Lass:
    .string "阿勉是一位超棒的DJ。\p"
    .string "他那甜美的嗓音简直让我融化了！$"

RadioTower1F_Text_Youngster:
    .string "我最喜欢《宝可梦讲座》的胡桃了。\p"
    .string "不过我也只听过她的声音而已啦。$"

RadioTower1F_Text_GruntM3Seen:
    .string "我们终于占领广播电塔了！\p"
    .string "现在所有人都会见识到火箭队真正的\n"
    .string "恐怖！\p"
    .string "就让你们见识一下我们的厉害！$"

RadioTower1F_Text_GruntM3Beaten:
    .string "太强了！老大，对不起……$"

RadioTower1F_Text_GruntM3After:
    .string "你太强了……\p"
    .string "这样下去我们的计划会被破坏的。我\n"
    .string "得去警告其他人……$"

RadioTower1F_Text_Directory:
    .string "1楼 前台2楼 营业部\p"
    .string "3楼 人事部4楼 制作部\p"
    .string "5楼 台长室$"

RadioTower1F_Text_GotRadio:
	.string "{PLAYER}的宝可梦齿轮装上\n"
	.string "了收音机卡！$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "这里是宝可梦彩票角。\p"
	.string "要是抽出的彩票号码和你拥有的宝可\n"
	.string "梦ID编号一致的话，就能获得豪华的\l"
	.string "奖品哦。\p"
	.string "要抽取今天的宝可梦彩票吗？$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "请明天再来吧。$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "欢迎下次再来。$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "请选一张彩票吧。......\n"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}......\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}......\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}\l"
	.string "{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "抽到的彩票号码是\n"
	.string "{STR_VAR_1}。\p"
	.string "现在为您核对同行或盒子里是否有符\n"
	.string "合该ID编号的宝可梦。请稍候片刻"
	.string "。$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "恭喜你！\p"
	.string "你同行的{STR_VAR_1}的\n"
	.string "ID编号与彩票号码一致！$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "恭喜你！\p"
	.string "你电脑盒子里的\n"
	.string "{STR_VAR_1}的ID编号与\l"
	.string "彩票号码一致！$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "很遗憾，没有相符的号码。$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "末尾2位数相符，恭喜获得三等奖！\n"
	.string "奖品是{STR_VAR_1}！$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "末尾3位数相符，恭喜获得二等奖！\n"
	.string "奖品是{STR_VAR_1}！$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "末尾4位数相符，恭喜获得一等奖！\n"
	.string "奖品是{STR_VAR_1}！$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "天哪，5位数全部相符！\p"
	.string "恭喜你获得特等大奖！奖品是\n"
	.string "{STR_VAR_1}！$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "哎呀？你的背包好像已经装不下了。\p"
	.string "请整理好背包的空间后再来找我吧。$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{PLAYER}对吧？好的，我正\n"
	.string "等您呢。\p"
	.string "这是为您保管的奖品。$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "欢迎下次再来。$"


