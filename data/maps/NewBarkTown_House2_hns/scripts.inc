NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "嗨，{PLAYER}！我丈夫总是\n"
	.string "那么忙，真希望他身体没事。\p"
	.string "只要一沉迷于宝可梦的研究，他甚至\n"
	.string "连饭都会忘记吃呢。$"

NewBarkTown_House2_Text_ElmsSon:
	.string "等我长大以后，我也要帮爸爸的忙！\p"
	.string "我要成为一名了不起的宝可梦博士！$"
