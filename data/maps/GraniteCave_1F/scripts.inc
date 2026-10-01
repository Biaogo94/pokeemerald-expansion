GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "喂，那边的。前面黑得可怕，继续探\n"
	.string "索下去会很危险。\p"
	.string "先前有个人来过……我想应该是大吾。\p"
	.string "他会使用闪光，所以应该没事，可\n"
	.string "是……\p"
	.string "唔，对于我们登山男而言，帮助他人\n"
	.string "解决困难是我们的座右铭。\p"
	.string "给，这个送你了。$"

GraniteCave_1F_Text_ExplainFlash:
	.string "把闪光招式教给宝可梦，使用的时\n"
	.string "候，\p"
	.string "就能够照亮漆黑的山洞。\p"
	.string "但你必须先去武斗镇的宝可梦道馆取\n"
	.string "得道馆徽章。$"

