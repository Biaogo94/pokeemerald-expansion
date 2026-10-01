FuchsiaCity_House1_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 2
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
	.string "原野区的园长老了，但他仍然十分有\n"
	.string "活力，\p"
	.string "不过他的假牙丢了。$"

FuchsiaCity_House1_Text_BillIsMyGrandson::
	.string "嗯？你见过正辉了？\p"
	.string "他是我的孙子！\p"
	.string "他总是喜欢收藏东西，像个孩子一\n"
	.string "样！$"

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
	.string "正辉将他的宝可梦的资料登陆在了电\n"
	.string "脑。\p"
	.string "他向你展示过吗？$"

