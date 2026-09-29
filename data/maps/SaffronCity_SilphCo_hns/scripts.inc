SaffronCity_SilphCo_hns_MapScripts::
	.byte 0

SaffronCity_SilphCo_EventScript_Steven::
	lock 
	msgbox SaffronCity_SilphCo_Text_Steven1, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	delay 20
	playse SE_PIN
	applymovement LOCALID_SILPHCO_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SILPHCO_STEVEN
SaffronCity_SilphCo_EventScript_StevenChooseStone::
	message SaffronCity_SilphCo_Text_Steven2
	waitmessage
	multichoice 20, 0, MULTI_HOENN_STARTERS, FALSE
	switch VAR_RESULT
	case 0, SaffronCity_SilphCo_EventScript_TreeckoChosen
	case 1, SaffronCity_SilphCo_EventScript_TorchicChosen
	case 2, SaffronCity_SilphCo_EventScript_MudkipChosen
	case MULTI_B_PRESSED, SaffronCity_SilphCo_EventScript_Refused

SaffronCity_SilphCo_EventScript_Refused::
	msgbox SaffronCity_SilphCo_Text_Refused, MSGBOX_DEFAULT
	turnobject LOCALID_SILPHCO_STEVEN, DIR_NORTH
	closemessage
	release
	end

SaffronCity_SilphCo_Text_Refused:
	.string "哎呀……$"

SaffronCity_SilphCo_EventScript_TreeckoChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TREECKO, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_TorchicChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TORCHIC, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_MudkipChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_MUDKIP, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven

SaffronCity_SilphCo_EventScript_AfterStarterGiven::
	msgbox SaffronCity_SilphCo_Text_Steven4, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SaffronCity_SilphCo_EventScript_PlayerMove
	applymovement LOCALID_SILPHCO_STEVEN, SaffronCity_SilphCo_Movement_StevenLeave
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_GOT_HOENN_STARTER
	removeobject LOCALID_SILPHCO_STEVEN
	release
	end

SaffronCity_SilphCo_EventScript_PlayerMove:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

SaffronCity_SilphCo_Movement_StevenLeave:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


SaffronCity_SilphCo_Text_Steven1:
	.string "喂……信号不太好呢...\n"
	.string "...我想这得看我爸爸怎么决定了\l"
	.string "。我知道了……那我先出发\l"
	.string "了。回头见。$"
SaffronCity_SilphCo_Text_Steven2:
	.string "大吾：你是……我记得你的\n"
	.string "眼神。\p"
	.string "只要看到眼神澄澈闪烁的训练家，我\n"
	.string "就一定能记住。\p"
	.string "你带着宝可梦图鉴呢！这么说你也在\n"
	.string "四处探寻宝可梦吗！让我想想...\l"
	.string "...\p"
	.string "我想在这方面我能帮上你的忙。\p"
	.string "假设你的面前放着几块石头。你会选\n"
	.string "择哪种颜色呢？$"
SaffronCity_SilphCo_Text_Steven3:
	.string "选得好！那我就把\n"
	.string "{STR_VAR_1}送给你吧！$"
SaffronCity_SilphCo_Text_Steven4:
	.string "请好好珍惜它。如果你能疼爱它，我\n"
	.string "会非常高兴的。$"

SaffronCity_SilphCo_EventScript_Receptionist::
	msgbox SilphCo_Text_Receptionist, MSGBOX_NPC
	end
SaffronCity_SilphCo_EventScript_Officer::
	goto_if_set FLAG_GOT_UP_GRADE, SaffronCity_SilphCo_EventScript_OfficerAfter
	msgbox SilphCo_Text_Officer, MSGBOX_NPC
	giveitem ITEM_UP_GRADE
	setflag FLAG_GOT_UP_GRADE
SaffronCity_SilphCo_EventScript_OfficerAfter::
	msgbox SilphCo_Text_Officer_GotUpGrade, MSGBOX_NPC
	end

SaffronCity_SilphCo_EventScript_Sign1::
	msgbox SilphCo_Text_Sign1, MSGBOX_SIGN
	end

SaffronCity_SilphCo_EventScript_Sign2::
	msgbox SilphCo_Text_Sign2, MSGBOX_SIGN
	end

SilphCo_Text_Sign1:
	.string "西尔佛公司1F 接待处$"

SilphCo_Text_Sign2:
	.string "西尔佛公司电梯暂停使用$"

SilphCo_Text_Receptionist:
	.string "欢迎光临。这里是西尔佛公司的总公\n"
	.string "司大楼。$"

SilphCo_Text_Officer:
	.string "楼上仅限本公司员工进入。\p"
	.string "不过既然你远道而来，\p"
	.string "这个小纪念品就送给你吧。$"

SilphCo_Text_Officer_GotUpGrade:
	.string "这是西尔佛公司的最新产品。\p"
	.string "在别的地方可都还买不到呢。$"
