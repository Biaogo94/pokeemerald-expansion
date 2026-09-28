SSAnne_B1F_Room1_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
	.string "伙计，如果你输了的话就得走从甲板\n"
	.string "上跳下去！$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
	.string "啊！居然被一个孩子打败了！$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
	.string "当我们在出海时，水母宝可梦有时会\n"
	.string "漂过去。$"

SSAnne_B1F_Room1_Text_BarnyIntro::
	.string "你好，陌生人！\p"
	.string "我不知道你是来自海洋还是山林，但\n"
	.string "请停下来和我聊聊吧。\p"
	.string "我所有的宝可梦都来自大海。$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
	.string "该死！让它跑掉了！$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
	.string "我本来也打算让你当我的助手！$"

