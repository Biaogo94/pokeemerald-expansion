SSAnne_Deck_Frlg_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_ShipDepartingSoon::
	.string "派对结束了。船很快就要离港了。$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
	.string "喔！洗甲板真是辛苦活！$"

SSAnne_Deck_Text_FeelSeasick::
	.string "呃……我不舒服……\p"
	.string "我晕船，所以我出来呼吸点新鲜空\n"
	.string "气……$"

SSAnne_Deck_Text_EdmondIntro::
	.string "嗨，朋友！\p"
	.string "我们来跳支舞吧！$"

SSAnne_Deck_Text_EdmondDefeat::
	.string "你给我留下了深刻的印象！$"

SSAnne_Deck_Text_EdmondPostBattle::
	.string "你认为这个世界上一共有多少种宝可\n"
	.string "梦？$"

SSAnne_Deck_Text_TrevorIntro::
	.string "喂，你！你晕船吗？$"

SSAnne_Deck_Text_TrevorDefeat::
	.string "我只是一时大意！$"

SSAnne_Deck_Text_TrevorPostBattle::
	.string "我老爸说一共有100种宝可梦。我感\n"
	.string "觉应该不止这么多。$"

