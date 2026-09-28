SSAnne_1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
	.string "我爱宝可梦！你呢？$"

SSAnne_1F_Room2_Text_TylerDefeat::
	.string "哇！你真棒！$"

SSAnne_1F_Room2_Text_TylerPostBattle::
	.string "听着，听着！让我做你的朋友好吗？\p"
	.string "然后我们就可以交换宝可梦，以及做\n"
	.string "各种各样的事情。$"

SSAnne_1F_Room2_Text_AnnIntro::
	.string "我从世界各地收集到了这些宝可梦！$"

SSAnne_1F_Room2_Text_AnnDefeat::
	.string "哦，不！我可是为了它们才环游世界\n"
	.string "！$"

SSAnne_1F_Room2_Text_AnnPostBattle::
	.string "你伤害了我可怜的宝可梦！\p"
	.string "我要求你在宝可梦中心治疗他们！$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
	.string "我和我的孩子在周游世界。$"

