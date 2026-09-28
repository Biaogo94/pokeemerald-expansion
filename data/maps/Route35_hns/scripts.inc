Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "我一直在收听收音机里的宝可梦情\n"
	.string "报。我觉得我已经很强了。$"

Route35_Text_CamperIvanBeaten:
	.string "我认输！$"

Route35_Text_CamperIvanAfter:
	.string "收音机里的音乐能改变野生宝可梦的\n"
	.string "心情。$"

Route35_Text_CamperElliotSeen:
	.string "我要让我女朋友看看，我有多帅气！$"

Route35_Text_CamperElliotBeaten:
	.string "真希望你能故意输给我啊.....\n"
	.string ".$"

Route35_Text_CamperElliotAfter:
	.string "在女朋友面前丢大人了......$"

Route35_Text_PicnickerBrookeSeen:
	.string "我男朋友太弱了，根本靠不住。$"

Route35_Text_PicnickerBrookeBeaten:
	.string "哎呀！你好强啊！$"

Route35_Text_PicnickerBrookeAfter:
	.string "比起我男朋友，还是我的宝可梦更靠\n"
	.string "得住。$"

Route35_Text_PicnickerKimSeen:
	.string "你也是要去道馆吗？我也是！$"

Route35_Text_PicnickerKimBeaten:
	.string "哎呀。没赢过呢......$"

Route35_Text_PicnickerKimAfter:
	.string "道馆徽章真好看，我一直在收集呢。$"

Route35_Text_BirdKeeperBryanSeen:
	.string "你平时都用些什么球呀？$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "呀！速度还不够快！$"

Route35_Text_BirdKeeperBryanAfter:
	.string "有的宝可梦一转眼就逃跑了。\p"
	.string "用钢铁先生做的速度球试试看吧。\p"
	.string "我只要一找到生梨果，就会拿去给钢\n"
	.string "铁先生。\p"
	.string "他会帮我做成特制的球哦。$"

Route35_Text_JugglerIrwinSeen:
	.string "见识见识我优雅的控球杂耍吧！$"

Route35_Text_JugglerIrwinBeaten:
	.string "呼！真是被震撼到了！$"

Route35_Text_JugglerIrwinAfter:
	.string "我本想用我得意的宝可梦让你大开眼\n"
	.string "界的，\p"
	.string "结果却被你的实力彻底震撼到了！$"

Route35_Text_BugCatcherArnieSeen:
	.string "只要有虫宝可梦出现，天涯海角我都\n"
	.string "去！$"

Route35_Text_BugCatcherArnieBeaten:
	.string "咦？我不该输的呀......$"

Route35_Text_BugCatcherArnieAfter:
	.string "我的毛球曾在自然公园的捕虫大赛上\n"
	.string "拿过优胜呢。$"

Route35_Text_IrwinRegister:
	.string "我本想用我得意的宝可梦让你大开眼\n"
	.string "界的，\p"
	.string "结果却被你的实力彻底震撼到了！$"

Route35_Text_ArnieRegister:
	.string "我的毛球曾在自然公园的捕虫大赛上\n"
	.string "拿过优胜呢。$"

Route35_Text_ArnieRematchIntro:
	.string "只要有虫宝可梦出现，天涯海角我都\n"
	.string "去！$"

Route35_Text_ArnieRematchDefeat:
	.string "咦？我不该输的呀......$"

Route35_Text_ArniePostRematch:
	.string "我的毛球曾在自然公园的捕虫大赛上\n"
	.string "拿过优胜呢。$"

Route35_Text_BugCatcherArnieYanma:
	.string "哇......看那些蜻蜻蜓！\p"
	.string "太震撼了，我都看呆了。$"

Route35_Text_FirebreatherWaltSeen:
	.string "我正在练习喷火呢。$"

Route35_Text_FirebreatherWaltBeaten:
	.string "好烫！把鼻尖给烧到了！$"

Route35_Text_FirebreatherWaltAfter:
	.string "收音机里的宝可梦进行曲能把野生宝\n"
	.string "可梦引出来哦。$"

Route35_Text_OfficerDirkSeen:
	.string "夜晚可是危机四伏的！$"

Route35_Text_OfficerDirkBeaten:
	.string "哎呀！$"

Route35_Text_OfficerDirkAfter:
	.string "夜晚其实也有别样的乐趣。\p"
	.string "但可别玩得太疯了，好吗？$"

Route35_Text_OfficerDirkTough:
	.string "你的宝可梦看起来挺强悍的嘛。\p"
	.string "去哪儿应该都很安全。$"

Route35_Text_Sign:
	.string "35号道路$"

Route35_Text_Sign2:
	.string "自然公园 大门$"
