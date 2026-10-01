GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "葵：咦？今天的暗号？当然是“救命”\n"
	.string "啦！$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "不管在哪里都能收听广播哦。快调台\n"
	.string "听听看吧！$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "前方非工作人员禁止入内。$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "收音机播放的摇篮曲或许能让宝可梦\n"
	.string "睡着呢。$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "他们为什么要占领广播电台呢？$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "胖丁：波哩……$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "抱歉，前方非工作人员禁止入内。\p"
	.string "以前明明没有这种规定的。\p"
	.string "总觉得台长怪怪的……$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "请随意四处参观吧。\p"
	.string "台长又恢复成以往那副和蔼的样子\n"
	.string "了。$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "3年前，火箭队被迫解散。\p"
	.string "不过，我们就要在这里东山再起！$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "哇啊！少狂妄自大了！$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "我们绝不会让你妨碍我们东山再起的\n"
	.string "计划！$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "我们是火箭队，是尽情榨取宝可梦的\n"
	.string "人！\p"
	.string "我们最喜欢干坏事了！怕了吧？$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "你以为自己是大英雄啊？$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "我们也不是非要作恶不可。我们只是\n"
	.string "随心所欲而已。$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "喂，喂！别挡我们的道！$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "啊--我认输。$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "我们的干部正在占领这里。\p"
	.string "他们好像有个大计划。到底是什么计\n"
	.string "划呢？$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "哈哈哈哈！\p"
	.string "真无聊。占领这里简直太容易了！\p"
	.string "来吧，让我找点乐子！$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "你、你是谁啊？$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "你居然打赢了我，我绝不会忘记的！$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "葵：请收听我的暗号节目！\p"
	.string "听广播就能知道今天的暗号哦！$"

GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
	.string "葵：你好呀！\p"
	.string "那么，你知道今天的暗号吗？\p"
	.string "好！暗号是哪一个呢？$"

GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
	.string "葵：答对啦！\p"
	.string "来，这个{STR_VAR_1}就\n"
	.string "是给你的奖品！$"

GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
	.string "葵：哔--！真遗憾！\p"
	.string "明天再来试试吧！$"

GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
	.string "葵：猜不出来吗？想好了再来找我\n"
	.string "吧！$"

GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
	.string "葵：你今天已经答过暗号了！\p"
	.string "明天再来收听吧！$"

GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
	.string "葵：答对啦，可是你的背包已经满\n"
	.string "了！\p"
	.string "整理一下空间再来和我说话吧！$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "2F 营业部$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "大木博士的宝可梦讲座\p"
	.string "正在绝赞热播中！$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "随时随地，宝可梦广播$"
