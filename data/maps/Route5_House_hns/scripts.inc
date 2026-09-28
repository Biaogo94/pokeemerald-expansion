Route5_House_hns_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "噫呀啊啊啊！\p"
	.string "我感应到一团不祥的阴影正笼罩在你\n"
	.string "的身上。收下这个驱除它吧！$"

Route5_House_Text_Granny2:
	.string "你刚才可是命悬一线，不过现在有它\n"
	.string "保佑你了。$"

Route5_House_Text_Woman:
	.string "我奶奶特别热衷于驱除她自认为的恶\n"
	.string "灵。\p"
	.string "吓到你了真是不好意思。$"
