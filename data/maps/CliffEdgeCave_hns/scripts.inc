CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "在洞窟里要是遇到岔路，通常一条是\n"
	.string "正路，另一条则是死胡同。\p"
	.string "但人就是会忍不住两条都想走走看。$"
