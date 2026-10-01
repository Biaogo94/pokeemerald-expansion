Route16_House_Frlg_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02
	goto_if_eq VAR_RESULT, FALSE, Route16_House_EventScript_NoRoomForHM02
	giveitem_msg Route16_House_Text_ReceivedHM02FromGirl, ITEM_HM02
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_GOT_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Fearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FEAROW, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Fearow
	waitmoncry
	release
	end

Route16_House_Text_FoundMySecretRetreat::
	.string "哦，天哪。你发现了我的秘密藏身\n"
	.string "处！\p"
	.string "请不要告诉任何人我在这里！如果你\n"
	.string "答应的话这个就给你！$"

Route16_House_Text_ReceivedHM02FromGirl::
	.string "{PLAYER}从女孩那儿获得了\n"
	.string "HM02。$"

Route16_House_Text_ExplainHM02::
	.string "HM02是技能飞翔。这是一个极为的方\n"
	.string "便技能。\p"
	.string "请好好利用它吧。$"

Route16_House_Text_DontHaveAnyRoomForThis::
	.string "你身上没有足够的空间存放它了。$"

Route16_House_Text_Fearow::
	.string "大嘴雀：法露$"

