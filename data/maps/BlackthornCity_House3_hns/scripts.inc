BlackthornCity_House3_hns_MapScripts::
	.byte 0

BlackthornCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox BlackthornCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "呃……噢，对了，我是招式\n"
	.string "遗忘爷爷。\p"
	.string "我能让宝可梦忘记它们学会的招式。\p"
	.string "需要我帮忙吗？$"

BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "要让哪只宝可梦遗忘招式呢？$"

BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "要遗忘哪个招式呢？$"

BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1}只学会了一\n"
	.string "个招式，所以无法遗忘……$"

BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "嗯！要让{STR_VAR_1}遗\n"
	.string "忘{STR_VAR_2}这个招式\l"
	.string "吗？$"

BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "非常成功！\p"
	.string "{STR_VAR_1}已经把\n"
	.string "{STR_VAR_2}彻底忘记了\l"
	.string "。$"

BlackthornCity_MoveDeletersHouse_Text_ComeAgain:
	.string "如果还有需要遗忘的招式，随时再来\n"
	.string "找我。$"

BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "什么？蛋怎么可能会招式呢。$"

BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "嗯！\p"
	.string "你的{STR_VAR_1}似乎不\n"
	.string "太情愿忘记冲浪呢。$"

BlackthornCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	faceplayer
	specialvar VAR_RESULT, IsRandomMovesActivated
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer
	goto_if_set FLAG_TEMP_1, BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp:
	.string "抱歉，我帮不上你。$"

BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "我是招式教学狂。\p"
	.string "宝可梦能学会的招式--每一个--\n"
	.string "我全都知道，而且我能把这些招式传\l"
	.string "授给宝可梦。\p"
	.string "只要你愿意，我可以教你的宝可梦学\n"
	.string "会招式。\p"
	.string "不过你得给我一片心之鳞片。我最近\n"
	.string "正在收集那个呢。$"

BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "噢！就是这个！货真价实的心之鳞片\n"
	.string "！\p"
	.string "让我猜猜，你是想让我传授招式，对\n"
	.string "吧？$"

BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "想让哪只宝可梦学招式呢？$"

BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "要传授哪个招式呢？$"

BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "抱歉……\p"
	.string "看来我没有能传授给这只宝可梦的招\n"
	.string "式。$"

BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER}交出了一片心之鳞\n"
	.string "片作为交换。$"

BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "如果你的宝可梦需要学招式，就带上\n"
	.string "心之鳞片再来找我吧。$"

BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "啊？我可没法教蛋学会任何招式啊。$"



