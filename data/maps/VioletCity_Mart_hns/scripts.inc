VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "刚收服宝可梦的时候，它可能还很弱\n"
	.string "小。\p"
	.string "但它终究会成长得越来越强大。\p"
	.string "用爱心去关怀宝可梦是非常重要的。$"

VioletCity_Mart_Text_CooltrainerM:
	.string "宝可梦可以携带伤药或解毒药之类的\n"
	.string "道具。\p"
	.string "不过它们好像不知道该怎么使用人造\n"
	.string "的道具呢。$"
