Gate_MahoganyTown_Route43_hns_MapScripts::
	.byte 0

Gate_MahoganyTown_Route43_EventScript_Cop::
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, Gate_MahoganyTown_Route43_EventScript_CopAfter
	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_NPC
	end

Gate_MahoganyTown_Route43_EventScript_CopAfter::
	msgbox Route43MahoganyGate_Text_Officer_RocketsCleared, MSGBOX_NPC
	end

Route43MahoganyGate_Text_Officer:
    .string "最近从这里经过的，就只有去愤怒之\n"
    .string "湖的人了。$"

Route43MahoganyGate_Text_Officer_RocketsCleared:
    .string "现在已经没有人会去愤怒之湖了。$"

