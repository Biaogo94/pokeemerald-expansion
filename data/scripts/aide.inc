Aide_EventScript_HaventCaughtEnough::
	msgbox Aide_Text_HaventCaughtEnoughMonsForItem
	release
	end

Aide_EventScript_NoRoomForItem::
	msgbox Aide_Text_DontHaveAnyRoomForItem
	release
	end

Aide_EventScript_DeclineCheckMons::
	msgbox Aide_Text_GetEnoughMonsComeBackForItem
	release
	end

Aide_Text_HaventCaughtEnoughMonsForItem::
	.string "我看看……哎呀！你才捉到了\n"
	.string "{STR_VAR_3}种宝可梦。\p"
	.string "想要{STR_VAR_2}，得先\n"
	.string "捉到{STR_VAR_1}种才\l"
	.string "行。$"

Aide_Text_GetEnoughMonsComeBackForItem::
	.string "……原来如此。\p"
	.string "等你捉到{STR_VAR_1}种\n"
	.string "宝可梦，再来拿\l"
	.string "{STR_VAR_2}吧。$"

Aide_Text_DontHaveAnyRoomForItem::
	.string "哎呀！你的包包好像装不下\n"
	.string "{STR_VAR_2}了。$"
