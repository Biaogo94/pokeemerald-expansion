AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "文：在寻宝的途中，我们发现了一位\n"
	.string "训练家！$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "文：即使我们联手也没能打过他……$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "文：我们什么宝藏也没找到……是不\n"
	.string "是已经被挖走了？$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "文：你连2只宝可梦都没有，这样肯\n"
	.string "定赢不了我们。$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "夏：哦？我们一直在寻宝，结果却找\n"
	.string "到一位训练家！$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "夏：哦，太强了！$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "夏：宝藏究竟在哪里？\p"
	.string "我都已经想好挖到宝以后买什么了！$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "夏：哦，你没有2只宝可梦？那以后\n"
	.string "再战吧！$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "夏：哦，你把我惹火了！我要登记你\n"
	.string "！$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "文：我们一直在寻找宝藏。\p"
	.string "我们的宝可梦也变强了，给你展示一\n"
	.string "下吧？$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "文：你还是那么强！$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "文：我们没找到宝藏，还输了宝可梦\n"
	.string "对战……\p"
	.string "我要回家……不过要是我真的说出来\n"
	.string "，她肯定会生气的……$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "文：你连2只宝可梦都没有，这样你\n"
	.string "是赢不了我们的。$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "夏：哦？我们又见面了！\p"
	.string "你和我们一样，还在寻找宝藏，对不\n"
	.string "对？\p"
	.string "不如来场对战吧，输的人放弃寻宝。$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "夏：哦，我们又输了……$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "夏：不把宝可梦练得强一些，不找到\n"
	.string "宝藏，我们绝不回去！$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "夏：哦，你没有2只宝可梦？那只好\n"
	.string "以后再战了！$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "我不擅长游泳，但我擅长对战！$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "哎呀，不对头啊。$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "赤脚在这艘船上走还真有些难受。$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "力量与体贴……这就是训练家的宝藏\n"
	.string "！$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "啊，没想到你还真有两下子。$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "我在某个船舱中，看到有什么东西在\n"
	.string "闪光。$"
