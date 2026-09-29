NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "看！瞧瞧我的包包！\p"
	.string "我从宝可梦图鉴打印出喜欢的宝可\n"
	.string "梦，把它们全贴在包上了。$"

NationalPark_Normal_Text_PokefanF:
	.string "这是我女儿寄来的邮件。读了就让我\n"
	.string "精神百倍。$"

NationalPark_Normal_Text_Teacher1:
	.string "请注意听讲！\p"
	.string "……哎呀，职业病又犯了，\n"
	.string "总觉得自己还在当老师呢。\p"
	.string "你一定是一位宝可梦训练家吧。\p"
	.string "看你这么努力，这个就送给你吧。$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "让宝可梦携带那个“先制之爪”吧。\p"
	.string "在战斗中有时能够先发制人哦。$"

NationalPark_Normal_Text_Youngster1:
	.string "我在玩从宝可梦图鉴里打印出来的贴\n"
	.string "纸呢。$"

NationalPark_Normal_Text_Youngster2:
	.string "如果我赢了，就能拿走对方的图鉴贴\n"
	.string "纸。$"

NationalPark_Normal_Text_Teacher2:
	.string "我常在公园里散步，但从不走进草\n"
	.string "丛。\p"
	.string "因为训练家们总想着找人对战..\n"
	.string "....\p"
	.string "你一路走来经历了不少战斗吧？让我\n"
	.string "来为你的宝可梦恢复一下吧。$"

NationalPark_Normal_Text_Persian:
	.string "猫老大：呜喵--！$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "宝可梦的世界可是奥妙无穷的。\p"
	.string "还有很多很多我们不知道的事情呢。\p"
	.string "不过，我知道的肯定比你多！$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "什、什、什么？！$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "要学习的东西还多着呢。\p"
	.string "比如说……\p"
	.string "招式学习器一共有92种。\p"
	.string "通过连接交换来的宝可梦升级更快。$"

NationalPark_Normal_Text_JackRegister:
	.string "要学习的东西还多着呢。\p"
	.string "比如说……\p"
	.string "招式学习器一共有92种。\p"
	.string "通过连接交换来的宝可梦升级更快。$"

NationalPark_Normal_Text_JackRematchIntro:
	.string "上次对战后，我学到了不少！再来一\n"
	.string "场吧！$"

NationalPark_Normal_Text_JackRematchDefeat:
	.string "什、什、什么？！$"

NationalPark_Normal_Text_JackPostRematch:
	.string "要学习的东西还多着呢。\p"
	.string "比如说……\p"
	.string "招式学习器一共有92种。\p"
	.string "通过连接交换来的宝可梦升级更快。$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "我的宝可梦简直是小天使。\p"
	.string "我要好好跟你说说，它们有多让我骄\n"
	.string "傲！$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "论骄傲，我可不会输给你，但是……$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "话说回来，你的宝可梦也挺可爱的。$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "哪怕宝可梦不喜欢我们，我们也一样\n"
	.string "疼爱它们。\p"
	.string "这才是真正的爱好者！$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "我、我的宝可梦！$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "对战虽然输了，但要论可爱，我的宝\n"
	.string "可梦绝对是第一名！$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "咦？你干吗一直盯着我看？\p"
	.string "哦，原来是想对战？$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "……唔……$"

NationalPark_Normal_Text_LassKrise_After:
	.string "我还以为你一直看我，是因为我长得\n"
	.string "可爱呢！$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "休闲广场自然公园$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "这是什么告示？\p"
	.string "“宝可梦对战请只在草丛中进行。”\p"
	.string "--自然公园管理处$"

NationalPark_Normal_Text_TrainerTips:
	.string "训练家心得\p"
	.string "打开邮件后按START键，就能把\n"
	.string "内容打印出来。$"

NationalPark_Normal_Text_BeverlyRegister:
	.string "话说回来，你的宝可梦也挺可爱的。$"

NationalPark_Normal_Text_BeverlyHasItem:
	.string "啊，你好！我有东西要给你。\p"
	.string "收下吧，就当是我的一份谢意！$"

NationalPark_Normal_Text_BeverlyGaveItem:
	.string "我和心爱的宝可梦会一直为你加油\n"
	.string "的！$"

NationalPark_Normal_Text_BeverlyNoRoom:
	.string "嗯，你的包包装满了。\p"
	.string "腾出地方再来找我吧。$"
