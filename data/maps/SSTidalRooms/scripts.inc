SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "有一张床……休息一下吧。$"

SSTidalRooms_Text_ColtonIntro:
	.string "我经常坐船去水静市。\p"
	.string "那是因为我喜欢参加那里的华丽大赛\n"
	.string "。$"

SSTidalRooms_Text_ColtonDefeat:
	.string "真是一场痛快的对战！$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "只要想想在下次的华丽大赛中能看见\n"
	.string "什么样的宝可梦，我就会兴奋起来。\l"
	.string "真是无比期待啊！$"

SSTidalRooms_Text_MicahIntro:
	.string "你的朋友很强吗？$"

SSTidalRooms_Text_MicahDefeat:
	.string "你的朋友确实很强。$"

SSTidalRooms_Text_MicahPostBattle:
	.string "朋友不一定非要是人类，对我来说，\n"
	.string "宝可梦是我的挚友！$"

SSTidalRooms_Text_ThomasIntro:
	.string "孩子……你敲门了吗？$"

SSTidalRooms_Text_ThomasDefeat:
	.string "即使输了也不可焦躁惊慌。$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "在任何情况下都能泰然自若是绅士的\n"
	.string "行为准则。$"

SSTidalRooms_Text_JedIntro:
	.string "阿新：说起来真有些不好意思……我\n"
	.string "们会展示给你爱情的力量！$"

SSTidalRooms_Text_JedDefeat:
	.string "阿新：唉……$"

SSTidalRooms_Text_JedPostBattle:
	.string "阿新：我们爱情的力量头一回没能取\n"
	.string "胜！你肯定是一名很强的训练家！$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "阿新：你只有1只宝可梦？这是不是\n"
	.string "也太孤单了？$"

SSTidalRooms_Text_LeaIntro:
	.string "佳穗：说起来真有些傻……我们会展\n"
	.string "示给你爱情的力量！$"

SSTidalRooms_Text_LeaDefeat:
	.string "佳穗：哦，完了！$"

SSTidalRooms_Text_LeaPostBattle:
	.string "佳穗：真是难以置信！我们爱情的力\n"
	.string "量输了……你肯定是一名很强的训练\l"
	.string "家！$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "佳穗：我也想对战……但你连2只宝\n"
	.string "可梦都没有……$"

SSTidalRooms_Text_GarretIntro:
	.string "啊，你来的正好。\p"
	.string "我无聊死了，一块玩玩吧。$"

SSTidalRooms_Text_GarretDefeat:
	.string "……玩够了。$"

SSTidalRooms_Text_GarretPostBattle:
	.string "或许我应该叫爸爸给我弄艘快艇。属\n"
	.string "于我和宝可梦的快艇！$"

SSTidalRooms_Text_NaomiIntro:
	.string "哦，你真是个可爱的训练家。想来杯\n"
	.string "茶吗？还是想来一场对战？$"

SSTidalRooms_Text_NaomiDefeat:
	.string "我明白了，你是活跃型的。$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "坐着豪华客轮周游世界确实很吸引人\n"
	.string "……\p"
	.string "但必须承认，坐着渡轮周游丰缘也别\n"
	.string "有一番风味。$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "嗯……你好！我……我不是什么可疑\n"
	.string "的人！嗯……这个给你！免费的！\p"
	.string "这……真的，这不是我抢夺来的！我\n"
	.string "绝不会干这种事！这不是赃物！你放\l"
	.string "心用吧！$"

SSTidalRooms_Text_ExplainSnatch:
	.string "化为己用可以把对手或我方即将使用\n"
	.string "的某些招式抢夺过来化为己用。$"

