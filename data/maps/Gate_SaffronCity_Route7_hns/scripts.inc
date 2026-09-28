Gate_SaffronCity_Route7_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "你听说发电厂发生的事故了吗？\p"
	.string "它就在东边，离紫苑镇很近。$"

Route7_Text_SaffronGuard_Serious:
	.string "我可是很认真对待警卫工作的。\p"
	.string "嘿！你有宝可梦图鉴啊。\p"
	.string "行，你可以过去了。$"
