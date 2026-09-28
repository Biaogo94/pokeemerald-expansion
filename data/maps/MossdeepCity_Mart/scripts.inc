MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "活力碎片太神奇了！\p"
	.string "把它给昏厥的宝可梦的话，宝可梦就\n"
	.string "会醒来。\p"
	.string "但要小心，活力碎片并不能恢复招式\n"
	.string "被用掉的PP。$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "黄金喷雾能赶走所有弱小的宝可梦。\p"
	.string "所有的喷雾器之中，它的持续时间最\n"
	.string "久。$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "捕网球和潜水球是只有绿岭市才卖的\n"
	.string "稀有精灵球。\p"
	.string "捕网球捉虫属性和水属性宝可梦很有\n"
	.string "效，\p"
	.string "潜水球则容易捉海底的宝可梦。$"

