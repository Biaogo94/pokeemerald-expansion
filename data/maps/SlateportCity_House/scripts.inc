SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "我的宝可梦是急躁性格。\p"
	.string "比起我的其它宝可梦，它的速度比较\n"
	.string "快。\p"
	.string "也许宝可梦的性格也会影响到它们的\n"
	.string "成长。$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "你是个训练家对吧？\p"
	.string "你来凯那市一定是想去对战帐篷。$"

