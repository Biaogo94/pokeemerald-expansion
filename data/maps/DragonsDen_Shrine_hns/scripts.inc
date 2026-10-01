DragonsDen_Shrine_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Shrine_OnFrame
	.byte 0

DragonsDen_Shrine_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 2, DragonsDen_Shrine_Trigger_ElderQuizTop
	.2byte 0

DragonsDen_Shrine_EventScript_Elder::
	lock
	faceplayer
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, DragonsDen_Shrine_EventScript_ElderChooseDratini
	msgbox DragonsDen_Shrine_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Trigger_ElderQuizLeft::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderLeft
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizTop::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizRight::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderRight
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz


DragonsDen_Shrine_Movement_PlayerWalkToElderLeft:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_MonWalkToElderLeft:
	walk_left
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderRight:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
DragonsDen_Shrine_Movement_MonWalkToElderRight:
	walk_right
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_EventScript_ElderOfferQuiz::
	msgbox DragonsDen_Shrine_Text_ElderGreeting, MSGBOX_DEFAULT
	setvar VAR_DRAGONS_DEN_QUIZ, 0
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1::
	message DragonsDen_Shrine_Text_Question1
	multichoice 20, 6, MULTI_ELDERQUIIZ1, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz1
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2::
	message DragonsDen_Shrine_Text_Question2
	multichoice 20, 6, MULTI_ELDERQUIIZ2, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz2
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3::
	message DragonsDen_Shrine_Text_Question3
	multichoice 20, 6, MULTI_ELDERQUIIZ3, FALSE 
	switch VAR_RESULT
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz3
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4::
	message DragonsDen_Shrine_Text_Question4
	multichoice 20, 6, MULTI_ELDERQUIIZ4, FALSE 
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz4
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderQuiz5::
	message DragonsDen_Shrine_Text_Question5
	multichoice 20, 6, MULTI_ELDERQUIIZ5, FALSE 
	switch VAR_RESULT
	case 2, DragonsDen_Shrine_EventScript_ElderQuizFinish
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz5
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderWrong::
	msgbox DragonsDen_Shrine_Text_WrongAnswer1, MSGBOX_DEFAULT
	addvar VAR_DRAGONS_DEN_QUIZ, 1
	return

DragonsDen_Shrine_EventScript_ElderQuizFinish::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	delay 20
	msgbox DragonsDen_Shrine_Text_PassedTest, MSGBOX_DEFAULT
	closemessage
	goto DragonsDen_Shrine_EventScript_ClairEnter


DragonsDen_Shrine_Text_ElderGreeting:
    .string "唔……欢迎来到这里。\p"
    .string "不必说明你的来意。是小椿让你来\n"
    .string "的，对吧？\p"
    .string "那孩子真是让人操心……虽然很抱歉，\n"
    .string "但我必须测试一下你。\p"
    .string "别担心，只要回答几个问题就行。准\n"
    .string "备好了吗？$"

DragonsDen_Shrine_Text_Question1:
    .string "对你来说，宝可梦是什么？$"

DragonsDen_Shrine_Text_Question2:
    .string "在对战中取胜的关键是什么？$"

DragonsDen_Shrine_Text_Question3:
    .string "你想和怎样的训练家对战？$"

DragonsDen_Shrine_Text_Question4:
    .string "培育宝可梦最重要的是什么？$"

DragonsDen_Shrine_Text_Question5:
    .string "强的宝可梦。弱的宝可梦。哪一种才\n"
    .string "更重要？$"

DragonsDen_Shrine_Text_WrongAnswer1:
    .string "嗯？我没太听清楚……$"

DragonsDen_Shrine_Text_WrongAnswer2:
    .string "你刚才说什么？$"

DragonsDen_Shrine_Text_RightAnswer:
    .string "哦，我明白了……$"

DragonsDen_Shrine_Text_PassedTest:
    .string "嗯……我明白了…….\p"
    .string "你深深地关爱着宝可梦。\p"
    .string "非常值得赞赏。\p"
    .string "这份信念才是最重要的！\p"
    .string "{PLAYER}，绝不要丢掉这份\n"
    .string "信念。\p"
    .string "它会指引你在宝可梦联盟中勇往直\n"
    .string "前。$"

DragonsDen_Shrine_EventScript_ClairEnter::
	clearflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	addobject LOCALID_DRAGONSDEN3_CLAIR
	playbgm MUS_HG_CLAIR, FALSE
	playse SE_DOOR
	delay 40
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairEnter
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_ELDER, DIR_WEST	
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_ClairYouPassed, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup1
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_ClairThatCantBe, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup2
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_ClairYoureLying, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderWalkToClair
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_MustIInformLance, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, Common_Movement_ExclamationMark
	msgbox DragonsDen_Shrine_Text_IUnderstand, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairReturnToPlayer
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_HereRisingBadge, MSGBOX_DEFAULT

	message DragonsDen_Shrine_Text_PlayerReceivedRisingBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DragonsDen_Shrine_Text_RisingBadgeExplanation, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	addvar VAR_NUM_BADGES, 1

	applymovement2 LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderReturnToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_ElderScoldsClair, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox DragonsDen_Shrine_Text_Speechless, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairLeave
	waitmovement 0
	playse SE_EXIT
	fadedefaultbgm
	setflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	removeobject LOCALID_DRAGONSDEN3_CLAIR
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setvar VAR_BLACKTHORN_CITY_STATE, 3
	release
	end

DragonsDen_Shrine_Movement_ClairEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

DragonsDen_Shrine_Movement_ClairBackup1:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ClairBackup2:
	lock_facing_direction
	walk_slow_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ElderWalkToClair:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairReturnToPlayer:
	walk_right
	walk_right
	step_end

DragonsDen_Shrine_Movement_ElderReturnToPlayer:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

DragonsDen_Shrine_Text_ClairYouPassed:
    .string "怎么样了？\p"
    .string "不过我想问了也是白问。你失败了\n"
    .string "吧？\p"
    .string "................................................\p"
    .string "……什么？你合格了？！$"

DragonsDen_Shrine_Text_ClairThatCantBe:
    .string "这不可能！$"

DragonsDen_Shrine_Text_ClairYoureLying:
    .string "你骗人！\p"
    .string "连我都还没得到过认可呢！$"

DragonsDen_Shrine_Text_MustIInformLance:
    .string "小椿！\p"
    .string "这孩子无论在技术还是心灵上，都无\n"
    .string "可挑剔！\p"
    .string "认输吧，把升龙徽章交出来！\p"
    .string "……还是说，要我把这件事告诉阿渡？$"

DragonsDen_Shrine_Text_IUnderstand:
    .string "我、我知道了……$"

DragonsDen_Shrine_Text_HereRisingBadge:
    .string "给，这是升龙徽章……\p"
    .string "快点！拿去吧！$"

DragonsDen_Shrine_Text_PlayerReceivedRisingBadge:
    .string "{PLAYER}获得了升龙徽章。$"

DragonsDen_Shrine_Text_RisingBadgeExplanation:
    .string "有了升龙徽章，你的宝可梦就能使用\n"
    .string "攀瀑招式了。\p"
    .string "而且，所有的宝可梦都会认可你的实\n"
    .string "力，对你的任何指令都言听计从。$"

DragonsDen_Shrine_Text_ElderScoldsClair:
    .string "小椿……\p"
    .string "好好反省一下，这孩子所拥有的，而\n"
    .string "你所欠缺的究竟是什么吧。$"

DragonsDen_Shrine_Text_Speechless:
    .string "..................................$"

DragonsDen_Shrine_Text_ComeAgain:
    .string "若是想来，随时欢迎再来。$"

DragonsDen_Shrine_Text_SilverIsInTraining:
    .string "有个年纪和你相仿的少年正在这里修\n"
    .string "行。\p"
    .string "他很像小椿小时候的样子，真让人有\n"
    .string "点担心呢……$"

DragonsDen_Shrine_EventScript_Elder2::
	msgbox DragonsDen_Shrine_Text_Elder2, MSGBOX_NPC
	end

DragonsDen_Shrine_EventScript_Elder3::
	msgbox DragonsDen_Shrine_Text_Elder3, MSGBOX_NPC
	end

DragonsDen_Shrine_Text_Elder2:
    .string "已经很久没有训练家能够得到我们长\n"
    .string "老那难得的认可了。\p"
    .string "事实上，自从阿渡少爷之后就再没有\n"
    .string "过了。$"

DragonsDen_Shrine_Text_Elder3:
    .string "你认识年轻的阿渡少爷吗？\p"
    .string "他和长老年轻时的模样简直一模一\n"
    .string "样。\p"
    .string "真不愧是血脉相承啊。$"

DragonsDen_Shrine_EventScript_ElderChooseDratini::
	goto_if_eq VAR_DRAGONS_DEN_QUIZ, 0, DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini
	goto DragonsDen_Shrine_EventScript_ElderGiveBasicDratini

DragonsDen_Shrine_EventScript_ElderGiveBasicDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givemon SPECIES_DRATINI, 15
	call Common_EventScript_GiftMon

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givenamedmon 4
	call Common_EventScript_GiftMonNamed

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini::
	msgbox DragonsDen_Shrine_Text_ClairsGrandfather, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Text_TakeThisDratini:
    .string "嗯……很高兴能在这里见到你。\p"
    .string "你来得正好。\p"
    .string "我有样东西要交给你。\p"
    .string "收下这只迷你龙吧，就当作是我认可\n"
    .string "你的证明。$"

DragonsDen_Shrine_Text_SymbolicDragon:
    .string "龙属性宝可梦是我们一族的象征。\p"
    .string "你已经证明了自己值得被托付这样一\n"
    .string "只宝可梦。$"

DragonsDen_Shrine_Text_ClairsGrandfather:
    .string "小椿似乎从你身上学到了宝贵的一\n"
    .string "课。\p"
    .string "我作为她的祖父，向你表示感谢。$"
