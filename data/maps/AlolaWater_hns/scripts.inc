AlolaWater_hns_MapScripts::
	.byte 0


Alola_MelemeleSea_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_2_HNS, Alola_MelemeleSea_TrainerBattleSwimmer_Text_0, Alola_MelemeleSea_TrainerBattleSwimmer_Text_1
	msgbox Alola_MelemeleSea_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_MelemeleSea_TrainerBattleSwimmer_Text_0:
	.string "这里的水域好开阔啊！$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_1:
	.string "哎哟，大腿抽筋了……$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_2:
	.string "这里的激流很急。我觉得会吸引来强\n"
	.string "大的宝可梦！$"
