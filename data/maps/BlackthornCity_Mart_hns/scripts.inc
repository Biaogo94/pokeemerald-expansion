BlackthornCity_Mart_hns_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "活力块虽然买不到，但它能让陷入濒\n"
	.string "死的宝可梦完全恢复健康。\p"
	.string "不过要小心--它不能恢复PP，也就是\n"
	.string "使用招式所需的招式点数。$"

BlackthornMart_Text_BlackBelt:
	.string "黄金喷雾能让弱小的宝可梦远离你。\p"
	.string "它是所有喷雾中持续时间最长的。$"
