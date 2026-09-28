Route10_PowerPlantBackRoom_hns_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDER
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	setvar VAR_VERMILION_CITY_SAMSON, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "所长：我、我、我现在气得快要爆炸\n"
	.string "了！\p"
	.string "到底是谁敢破坏我的发电机？！\p"
	.string "那可是我花了好多心血造出来的！\p"
	.string "要是让我逮到那家伙，一定要让他尝\n"
	.string "尝我电磁炮的厉害！$"

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "所长：我绝不饶他！\p"
	.string "就算那个犯人哭着向我赔礼道歉，\p"
	.string "我也要狠狠痛扁他一顿！\p"
	.string "嘎哈哈哈哈！$"

Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "所长：啊！没错！\p"
	.string "这就是我心爱的发电机上缺少的零件\n"
	.string "！被你找到了吗？$"

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "哇哈哈！太感谢了！\p"
	.string "来！收下这个招式学习器作为谢礼吧\n"
	.string "！$"

Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "所长：那个招式学习器是“打雷”。\p"
	.string "威力相当惊人哦！\p"
	.string "虽说命中率稍微差了点，但砸下去的\n"
	.string "威力可是非同小可的！$"

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "所长：我心爱的发电机啊！\p"
	.string "继续源源不断地产出电力吧！$"

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "在没有通电的情况下，这扇门很不安\n"
	.string "全。$"

