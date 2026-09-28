RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "黑板上写着可能影响宝可梦战斗的状\n"
	.string "态变化。$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "想读哪一条？$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "宝可梦中毒后，会慢慢损失体力，\p"
	.string "此效果在战斗后依然残留。\p"
	.string "在探险中，中毒的宝可梦的体力P也\n"
	.string "会不断减少。\p"
	.string "使用解毒药可解毒。$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "宝可梦麻痹后，速度会降低，\p"
	.string "战斗中有可能无法使用招式。\p"
	.string "此效果战斗后依然残留。使用解麻药\n"
	.string "可治愈。$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "宝可梦睡着后，就无法攻击了。\p"
	.string "宝可梦有可能自己醒来，但如果战斗\n"
	.string "结束后它还在睡觉，那么它会一直睡\l"
	.string "着。\p"
	.string "用解眠药叫醒它。$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "灼伤会降低攻击，同时会降低伤者的\n"
	.string "体力。\p"
	.string "战斗后灼伤还会留下。用灼伤药可以\n"
	.string "治愈。$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "宝可梦被冰冻后，它完全无法反击，\p"
	.string "战斗后依然会保持冻结。用解冻药为\n"
	.string "它解冻。$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "对于偷懒的学生，我就让他们尝尝我\n"
	.string "的先制之爪。\p"
	.string "你是不是个好学生，只要看看你怎么\n"
	.string "用这件道具就能知道。$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "带着先制之爪的宝可梦偶尔会提高速\n"
	.string "度比对手先发动攻击。\p"
	.string "还有很多可以给宝可梦携带的东西，\p"
	.string "只是这一点就足够你学很久了！$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "我刚才在和朋友交换宝可梦。$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "我一直想要一只橡实果，现在终于有\n"
	.string "了！$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "宝可梦可以带一些道具，但它们不会\n"
	.string "使用伤药或解毒药这样的人造道具。$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "你知道某些宝可梦的招式可以使对手\n"
	.string "宝可梦混乱吗？\p"
	.string "混乱的宝可梦有时会不知为何攻击自\n"
	.string "己。\p"
	.string "但一旦它退出战斗，它就会恢复正常\n"
	.string "。$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "带着树果的宝可梦能够自我治疗……\p"
	.string "许多道具都可以让宝可梦携带……\p"
	.string "唉，及时记下笔记太难了……$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "这是这个学生的笔记本……\p"
	.string "用精灵球可以捕捉宝可梦。\p"
	.string "一个训练家最多可以同时携带6只宝\n"
	.string "可梦。\p"
	.string "训练家就是捕捉宝可梦，并培育它们\n"
	.string "，与它们共同战斗的人。\p"
	.string "训练家的任务是打败在宝可梦道馆中\n"
	.string "等待着的强大训练家。$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "你好，我们以前见过面吧？我想是在\n"
	.string "橙华市见过。\p"
	.string "我来自我介绍一下。我叫亚希达，\p"
	.string "正为了寻找出类拔萃的训练家而四处\n"
	.string "旅行，\p"
	.string "具体地说，就是寻找宝可梦对战专家\n"
	.string "。\p"
	.string "你为什么会来这所学校呢？你也是训\n"
	.string "练家吗？\p"
	.string "那你首先要做的就是拥有一只会居合\n"
	.string "劈的宝可梦。\p"
	.string "如果我没记错的话，这城镇里就有人\n"
	.string "拥有居合劈。$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "亚希达：嗯……\p"
	.string "这里的学生天赋还不明确，但潜力是\n"
	.string "有的。$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "亚希达：哦，那是什么？\p"
	.string "岩石徽章是吗？真令人吃惊。\p"
	.string "不过，我更想看看对战时的你。\p"
	.string "仅凭一枚联盟徽章很难看出训练家的\n"
	.string "水平高低。$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Hello? Didn't we meet before?\n"
	.string "I think back in PETALBURG CITY.\p"
	.string "Let me introduce myself.\n"
	.string "My name's SCOTT.\p"
	.string "I've been traveling everywhere in\n"
	.string "search of outstanding TRAINERS.\p"
	.string "More specifically, I'm looking for\n"
	.string "POKéMON battle experts.\p"
	.string "Oh, what's that?\n"
	.string "It's a STONE BADGE, isn't it?\p"
	.string "That's pretty impressive, I'd say, for\n"
	.string "a starting TRAINER like yourself.\p"
	.string "But, you know, I would've loved to see\n"
	.string "you in battle.\p"
	.string "It's hard to tell what you're like as\n"
	.string "a TRAINER from a LEAGUE BADGE.$"

