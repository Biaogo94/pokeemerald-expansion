SproutTower_1F_hns_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW_HNS, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "We stand guard in this tower.\p"
	.string "Here, we express our gratitude\n"
	.string "to honor all POKéMON.$"

SproutTower_Text_SageChow_Beaten:
	.string "多、多谢指教！$"

SproutTower_Text_SageChow_AfterBattle:
	.string "All living beings coexist\n"
	.string "through cooperation.\p"
	.string "We must always be thankful\n"
	.string "for this.$"

SproutTower_Text_1F_Sage1:
	.string "Only if you reach the top will\n"
	.string "you obtain an HM.$"

SproutTower_Text_1F_Sage2:
	.string "SPROUT TOWER was built long ago\n"
	.string "as a place for POKéMON training.$"

SproutTower_Text_1F_Granny:
	.string "高达100英尺的喇叭芽.....\n"
	.string ".\p"
	.string "人们都说它化作了这里的中心支柱。$"

SproutTower_Text_1F_Teacher:
	.string "看到柱子在摇晃了吗？\p"
	.string "有人正在楼上修行呢。$"

SproutTower_Text_1F_Statue:
	.string "宝可梦的雕像......\p"
	.string "看起来非常庄严气派。$"
