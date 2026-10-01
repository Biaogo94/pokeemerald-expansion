Akala_Cave_hns_MapScripts::
	.byte 0


Alola_Melemele_BattleMarowak::
	lock
	faceplayer
	setflag FLAG_BATTLED_MAROWAK
	playmoncry SPECIES_MAROWAK_ALOLA, 0
	msgbox Alola_Melemele_BattleMarowak_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_MAROWAK_ALOLA, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Melemele_BattleMarowak_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_BattleMarowak_3
	release
	end

	release
	end

Alola_Melemele_BattleMarowak_2:
	setflag FLAG_HIDE_MAROWAK_ALOLA
	removeobject Alola_Melemele_Marowak
	release
	end

Alola_Melemele_BattleMarowak_3:
	setflag FLAG_HIDE_MAROWAK_ALOLA
	removeobject Alola_Melemele_Marowak
	release
	end


Alola_Melemele_BattleDugtrio::
	lock
	faceplayer
	setflag FLAG_BATTLED_DUGTRIO
	playmoncry SPECIES_DUGTRIO_ALOLA, 0
	msgbox Alola_Melemele_BattleDugtrio_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_DUGTRIO_ALOLA, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Melemele_BattleDugtrio_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_BattleDugtrio_3
	release
	end

	release
	end

Alola_Melemele_BattleDugtrio_2:
	setflag FLAG_HIDE_DUGTRIO_ALOLA
	removeobject Alola_Melemele_Dugtrio
	release
	end

Alola_Melemele_BattleDugtrio_3:
	setflag FLAG_HIDE_DUGTRIO_ALOLA
	removeobject Alola_Melemele_Dugtrio
	release
	end


Alola_Akala_Cave_FindItem1::
	finditem ITEM_CARBOS, 1
	end


Alola_Akala_Cave_FindItem2::
	finditem ITEM_HP_UP, 1
	end


Alola_AkalaCave_TrainerBattleHiker::
	trainerbattle_single TRAINER_AKALA_CAVE_HIKER_HNS, Alola_AkalaCave_TrainerBattleHiker_Text_0, Alola_AkalaCave_TrainerBattleHiker_Text_1
	msgbox Alola_AkalaCave_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaCave_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_AKALA_CAVE_PICNICKER_HNS, Alola_AkalaCave_TrainerBattlePicnicker_Text_0, Alola_AkalaCave_TrainerBattlePicnicker_Text_1
	msgbox Alola_AkalaCave_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaCave_TrainerBattleCamper::
	trainerbattle_single TRAINER_AKALA_CAVE_CAMPER_HNS, Alola_AkalaCave_TrainerBattleCamper_Text_0, Alola_AkalaCave_TrainerBattleCamper_Text_1
	msgbox Alola_AkalaCave_TrainerBattleCamper_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_BattleMarowak_Text_0:
	.string "吼--！$"

Alola_Melemele_BattleDugtrio_Text_0:
	.string "恰--恰！$"

Alola_AkalaCave_TrainerBattleHiker_Text_0:
	.string "能一路爬到这里，你一定很厉害吧！$"

Alola_AkalaCave_TrainerBattleHiker_Text_1:
	.string "比我还厉害！$"

Alola_AkalaCave_TrainerBattleHiker_Text_2:
	.string "太热了，我不得不放弃登山。\p"
	.string "山顶简直就像有人在生着大火一样"
	.string "。.....$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_0:
	.string "走了这么久我都累了，来场对战提提\n"
	.string "神吧！$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_1:
	.string "哎呀，真是神清气爽！$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_2:
	.string "我平时不会这么容易累的，可这个洞\n"
	.string "窟里的闷热实在让人吃不消！$"

Alola_AkalaCave_TrainerBattleCamper_Text_0:
	.string "瞧瞧我！我抓到了好厉害的宝可梦！$"

Alola_AkalaCave_TrainerBattleCamper_Text_1:
	.string "打得不错，但我还不够强！$"

Alola_AkalaCave_TrainerBattleCamper_Text_2:
	.string "这里真的很热，还是只有我这么觉\n"
	.string "得？$"
