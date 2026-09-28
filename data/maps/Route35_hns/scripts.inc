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
	.string "I've been getting POKéMON data off\n"
	.string "my radio. I think I'm good.$"

Route35_Text_CamperIvanBeaten:
	.string "我认输！$"

Route35_Text_CamperIvanAfter:
	.string "Music on the radio changes the\n"
	.string "moods of wild POKéMON.$"

Route35_Text_CamperElliotSeen:
	.string "I'm gonna show my girlfriend I'm\n"
	.string "hot stuff!$"

Route35_Text_CamperElliotBeaten:
	.string "真希望你能故意输给我啊.....\n"
	.string ".$"

Route35_Text_CamperElliotAfter:
	.string "在女朋友面前丢大人了......$"

Route35_Text_PicnickerBrookeSeen:
	.string "My boyfriend's weak, so I can't rely\n"
	.string "on him.$"

Route35_Text_PicnickerBrookeBeaten:
	.string "哎呀！你好强啊！$"

Route35_Text_PicnickerBrookeAfter:
	.string "I can count on my POKéMON more than\n"
	.string "my boyfriend.$"

Route35_Text_PicnickerKimSeen:
	.string "你也是要去道馆吗？我也是！$"

Route35_Text_PicnickerKimBeaten:
	.string "哎呀。没赢过呢......$"

Route35_Text_PicnickerKimAfter:
	.string "The GYM BADGES are pretty. I collect\n"
	.string "them.$"

Route35_Text_BirdKeeperBryanSeen:
	.string "你平时都用些什么球呀？$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "呀！速度还不够快！$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Some POKéMON flee right away.\p"
	.string "Try catching them with KURT's\n"
	.string "FAST BALL.\p"
	.string "Whenever I find a ASPEAR BERRY, I\n"
	.string "take it to KURT.\p"
	.string "He turns it into a custom BALL.$"

Route35_Text_JugglerIrwinSeen:
	.string "见识见识我优雅的控球杂耍吧！$"

Route35_Text_JugglerIrwinBeaten:
	.string "呼！真是被震撼到了！$"

Route35_Text_JugglerIrwinAfter:
	.string "I was going to dazzle you with my\n"
	.string "prize POKéMON.\p"
	.string "But your prowess electrified me!$"

Route35_Text_BugCatcherArnieSeen:
	.string "I'll go anywhere if bug POKéMON\n"
	.string "appear there.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "咦？我不该输的呀......$"

Route35_Text_BugCatcherArnieAfter:
	.string "My VENONAT won me the Bug-Catching\n"
	.string "Contest at the NATIONAL PARK.$"

Route35_Text_IrwinRegister:
	.string "I was going to dazzle you with my\n"
	.string "prize POKéMON.\p"
	.string "But your prowess electrified me!$"

Route35_Text_ArnieRegister:
	.string "My VENONAT won me the Bug-Catching\n"
	.string "Contest at the NATIONAL PARK.$"

Route35_Text_ArnieRematchIntro:
	.string "I'll go anywhere if bug POKéMON\n"
	.string "appear there.$"

Route35_Text_ArnieRematchDefeat:
	.string "咦？我不该输的呀......$"

Route35_Text_ArniePostRematch:
	.string "My VENONAT won me the Bug-Catching\n"
	.string "Contest at the NATIONAL PARK.$"

Route35_Text_BugCatcherArnieYanma:
	.string "哇......看那些蜻蜻蜓！\p"
	.string "太震撼了，我都看呆了。$"

Route35_Text_FirebreatherWaltSeen:
	.string "我正在练习喷火呢。$"

Route35_Text_FirebreatherWaltBeaten:
	.string "好烫！把鼻尖给烧到了！$"

Route35_Text_FirebreatherWaltAfter:
	.string "The POKéMON March on the radio\n"
	.string "lures wild POKéMON.$"

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
