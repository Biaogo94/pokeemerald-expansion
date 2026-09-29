GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "满金宝可梦道馆$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "满金市宝可梦道馆\p"
	.string "小茜认定的训练家：\n"
	.string "{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
    .string "你好呀！我是小茜！\p"
    .string "大家都在玩宝可梦，所以我也跟着玩\n"
    .string "啦！\p"
    .string "宝可梦真的是超级可爱呢！\p"
    .string "你想挑战我吗？我可先警告你--我\n"
    .string "超级厉害的哦！$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
    .string "呜呜……\p"
    .string "……哇啊啊啊！你好过分！\p"
    .string "干嘛那么认真嘛！你……你\n"
    .string "这个小屁孩！$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
    .string "哇啊啊啊！\p"
    .string "哇啊啊啊！\p"
    .string "……呜呜，嗝……\n"
    .string "……大坏蛋！$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
    .string "……吸鼻涕……\p"
    .string "怎么？你想要什么？徽章吗？\p"
    .string "啊，对哦。我给忘了。拿去吧，这是\n"
    .string "常规徽章。$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
    .string "{PLAYER}获得了常规徽章。$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
    .string "拥有常规徽章，你的宝可梦就能在战\n"
    .string "斗外使用“怪力”了。\p"
    .string "而且还能提升宝可梦的防御哦。\p"
    .string "对了，这个也送给你吧！$"

GoldenrodCity_Gym_Text_WhitneyAttract:
    .string "这是“着迷”！能充分发挥出宝可梦\n"
    .string "的魅力呢。\p"
    .string "是不是特别适合我这种可爱美少女？$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
    .string "呼，痛痛快快哭了一场真舒服！$"

GoldenrodCity_Gym_Text_WhitneyRematch:
    .string "嗨！是你呀！\p"
    .string "哇，你现在已经是城都冠军啦？\p"
    .string "真是太厉害了！\p"
    .string "我也想看看你到底有多强。\p"
    .string "要不要和我再来对战一场？$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "哇啊啊啊！\p"
    .string "哇啊啊啊！\p"
    .string "……呜呜，嗝……\n"
    .string "……大坏蛋！$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "可别被我宝可梦可爱的外表骗了。\p"
    .string "它们可是能把你打得落花流水呢！$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "可恶……我还以为你很弱呢\n"
    .string "......$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "我的宝可梦会觉得我很可爱吗？$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
    .string "比起强大的宝可梦，我更喜欢可爱的\n"
    .string "。\p"
    .string "不过我的宝可梦既强大又可爱！$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
    .string "哎呀，不行不行不行！$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
    .string "我想赢过小茜，可是……真\n"
    .string "打击人。\p"
    .string "不过我没事！就算输了，下次再加把\n"
    .string "劲就行了！$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
    .string "哎呀。你把小茜弄哭了。\p"
    .string "没事的。她一会儿就好了。她每次输\n"
    .string "掉都会哭鼻子的。$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
    .string "哎呀，你真是个可爱的小训练家！\p"
    .string "虽然我挺喜欢你，但我可不会手下留\n"
    .string "情！$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
    .string "等等看……哎呀，已经结束\n"
    .string "了？$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
    .string "哇，能打赢我，你还真有两下子！继\n"
    .string "续保持哦！$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
    .string "使出你的全力吧，否则我可不会手下\n"
    .string "留情！$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
    .string "怎么会！呜呜，喵喵，对不起啊！$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
    .string "我明明教了喵喵能够应对各种属性的\n"
    .string "招式……$"

GoldenrodCity_Gym_Text_GymGuide:
    .string "哟！未来的冠军！\p"
    .string "这里是满金道馆，馆主是精通一般属\n"
    .string "性宝可梦的小茜。\p"
    .string "千万要小心她那些可爱的宝可梦。\p"
    .string "这个道馆里的部分宝可梦，还拥有新\n"
    .string "发现的妖精属性呢。\p"
    .string "如果需要格斗属性或毒属性的宝可\n"
    .string "梦，不妨去34号道路看看吧。$"

GoldenrodCity_Gym_Text_GymGuideWin:
    .string "你赢啦？太棒了！我光顾着看这里的\n"
    .string "美女了。$"

