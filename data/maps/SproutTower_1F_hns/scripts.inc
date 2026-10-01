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
	.string "我们在塔中修行守护。\p"
	.string "在这里，我们向所有的宝可梦表达感\n"
	.string "激与崇敬之情。$"

SproutTower_Text_SageChow_Beaten:
	.string "多、多谢指教！$"

SproutTower_Text_SageChow_AfterBattle:
	.string "所有的生灵都是在互相扶持中共存。\p"
	.string "我们必须时刻对此心怀感激。$"

SproutTower_Text_1F_Sage1:
	.string "只有登上塔顶，才能获得秘传学习\n"
	.string "器。$"

SproutTower_Text_1F_Sage2:
	.string "喇叭芽之塔是很久以前为了修行宝可\n"
	.string "梦而建造的。$"

SproutTower_Text_1F_Granny:
	.string "高达100英尺的喇叭芽…….\p"
	.string "人们都说它化作了这里的中心支柱。$"

SproutTower_Text_1F_Teacher:
	.string "看到柱子在摇晃了吗？\p"
	.string "有人正在楼上修行呢。$"

SproutTower_Text_1F_Statue:
	.string "宝可梦的雕像……\p"
	.string "看起来非常庄严气派。$"
