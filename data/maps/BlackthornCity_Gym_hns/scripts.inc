BlackthornCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY_HNS, BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN_HNS, BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL_HNS, BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_HNS, BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_HNS, BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1_HNS, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers_hns
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
    .string "我是小椿。\p"
    .string "世界第一的龙属性使者！\p"
    .string "哪怕是面对宝可梦联盟的四天王，我\n"
    .string "也绝不会落下风。\p"
    .string "即使如此，你还打算向我挑战吗？\p"
    .string "……好啊，那就来吧！\p"
    .string "身为道馆馆主，面对任何对手我都会\n"
    .string "全力以赴！$"

BlackthornGym_Text_ClairWinText:
    .string "我输了？\p"
    .string "难以置信。一定是有什么地方搞错了\n"
    .string "......$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
    .string "我才不承认呢。\p"
    .string "就算是我输了，但现在的你还是没资\n"
    .string "格挑战宝可梦联盟。\p"
    .string "对了，你去接受龙使者的考验吧。\p"
    .string "在道馆后面有一个叫龙穴的地方。\p"
    .string "其中心有一座小祠堂，去那里吧。\p"
    .string "只要你能证明自己没有怠惰虚浮的杂\n"
    .string "念，我就会认可你是有资格获得道馆\l"
    .string "徽章的训练家！$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
    .string "怎么了？\p"
    .string "难道是我对你抱的期望太高了吗？$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
    .string "让我好等啊！\p"
    .string "拿去！把这个收下！$"

BlackthornGym_Text_ClairText_DescribeTM:
    .string "里面装的是“龙爪”。\p"
    .string "效果你自己看看就明白了。$"

BlackthornGym_Text_ClairText_League:
    .string "怎么啦？\p"
    .string "你不是要去宝可梦联盟吗？\p"
    .string "不知道路怎么走吗？\p"
    .string "从这里先回若叶镇，\p"
    .string "然后向东冲浪过去。那条路可不好走\n"
    .string "呢。\p"
    .string "你可千万别在宝可梦联盟输掉啊！\p"
    .string "要是你输了，输给你的我岂不是更丢\n"
    .string "脸！\p"
    .string "给我全力以赴地上吧！$"

BlackthornGym_Text_ClairAfterLeague:
    .string "你做到了啊。\p"
    .string "现在你已经是城都的冠军了。$"

BlackthornGym_Text_ClairRematchText:
    .string "你做到了啊。\p"
    .string "现在你已经是城都的冠军了。\p"
    .string "你证明了自己的实力，但你还能赢得\n"
    .string "了我吗？\p"
    .string "身为龙之大师，我绝不会手下留情。\p"
    .string "这一次绝不放水。\p"
    .string "要跟我再来对战一场吗？$"

BlackthornGym_Text_ClairRematchDefeatText:
    .string "我输了？\p"
    .string "又输了？\p"
    .string "真不敢相信。一定是哪里搞错了..\n"
    .string "....$"

BlackthornGym_Text_CooltrainermCodySeenText:
    .string "我才刚被允许使用龙属性宝可梦呢！$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
    .string "可恶！要是我有一只快龙就好了！$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
    .string "我们驯龙一族的成员，只有在得到师\n"
    .string "父的许可后才能使用龙宝可梦。$"

BlackthornGym_Text_CooltrainerfFranSeenText:
    .string "我可不能让无名训练家从我这里过去\n"
    .string "！\p"
    .string "要是放你过去，小椿大人会暴跳如雷\n"
    .string "的！$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
    .string "呜呜……我输了……\n"
    .string ".$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
    .string "哎呀……小椿大人要生气了\n"
    .string "......$"

BlackthornGym_Text_CooltrainermPaulSeenText:
    .string "第一次跟龙交手吗？\p"
    .string "就让你见识一下它们有多强悍！$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
    .string "我的龙宝可梦竟然输了？$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
    .string "阿渡大人说想再见到你？\p"
    .string "怎么可能！$"

BlackthornGym_Text_CooltrainermMikeSeenText:
    .string "我输掉的几率？连百分之一都不到！$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
    .string "真奇怪。$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
    .string "我知道自己的不足了。\p"
    .string "谢谢你让我看清！$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
    .string "龙是神圣的宝可梦。\p"
    .string "它们体内充盈着生命能量。\p"
    .string "若是不动真格，你根本不可能赢得了\n"
    .string "它们。$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
    .string "干得漂亮！$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
    .string "龙宝可梦对龙属性招式很脆弱。$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_GymGuy3
	msgbox BlackthornGym_Text_GuideGotoDragonsDen, MSGBOX_DEFAULT
	release
	end

BlackthornGym_EventScript_GymGuy3::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
    .string "哟！未来的冠军！\p"
    .string "漫长的旅程终于快走到终点了！看我\n"
    .string "的吧！\p"
    .string "虽说小椿十分憧憬龙之大师阿渡，但\n"
    .string "她也凭借来自大海的龙系伙伴，组建\l"
    .string "起了自己独具风格的队伍。\p"
    .string "按理说龙宝可梦害怕冰属性招式，但\n"
    .string "要想拿下胜利，你自己最好也准备一\l"
    .string "些龙属性或妖精属性的招式。$"
    .string "加油，你行的！$"

BlackthornGym_Text_GuideGotoDragonsDen:
	.string "能打赢小椿，你真是太棒了！\p"
	.string "不过，她输了以后脾气有点倔...\n"
	.string "...\p"
	.string "看来要想拿到道馆徽章，你得去一趟\n"
	.string "龙穴才行了！$"

BlackthornGym_Text_GuideWinText:
    .string "你能打败小椿真是太厉害了！\p"
    .string "接下来就只剩下挑战宝可梦联盟了。\p"
    .string "你离成为宝可梦冠军只差一步之遥了\n"
    .string "！$"


BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "烟墨市宝可梦道馆$"

BlackthornGym_Text_GymStatueCertified:
	.string "烟墨市宝可梦道馆\p"
	.string "小椿认可的训练家：\n"
	.string "{PLAYER}$"
