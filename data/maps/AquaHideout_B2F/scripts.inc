AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "嘿嘿嘿……\p"
	.string "都已经到这儿了啊？真是小瞧你了！\p"
	.string "但是到此为止了！\p"
	.string "我可比前面那些杂兵们都要强得多。\p"
	.string "我可不是拖延时间的，我会将你捏成\n"
	.string "粉末的！$"

AquaHideout_B2F_Text_MattDefeat:
	.string "嘿嘿嘿……看来我也输了……$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "嘿嘿嘿！\p"
	.string "我陪你玩的时候，我们的老大已经完\n"
	.string "成准备了！$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "嘿嘿嘿！\p"
	.string "我们的老大已经在去海底洞窟的路上\n"
	.string "了！\p"
	.string "要是你想追的话，就去水静市那边宽\n"
	.string "广的大海来慢慢找吧。\p"
	.string "不过你能找到吗？嘿嘿嘿！$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "哇哈哈，我已经等烦了！你也欠我一\n"
	.string "场对战！$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "等烦了……也败得一塌糊涂……$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "老大……这样算合格了吗？$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "这里的传送地板可是基地的骄傲！\p"
	.string "你完全不知道自己身在何处了吧？\p"
	.string "先扰乱敌人再突袭——这就是我们的作\n"
	.string "战计划！$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "怎么回事？你居然一点都不累！$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "说起来……我忘了把大师球放在哪里\n"
	.string "了。\p"
	.string "要是弄丢了，会被老大骂死的……$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "我加入海洋队后，第一堂课就是记住\n"
	.string "这些传送地板都通向哪里。$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "脑子里全都是传送地板的事情了……$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "我想我必须学学对战的要诀了……$"
