FourIsland_Mart_Frlg_MapScripts::
	.byte 0

FourIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FourIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FourIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FourIsland_Mart_EventScript_Camper::
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end

FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland::
	.string "在这座岛上有一个伟大的训练家在这\n"
	.string "里长大。\p"
	.string "我猜你已经知道她是谁了。没错，她\n"
	.string "就是四天王的科拿！\p"
	.string "当科拿还是一个小孩子的时候，我教\n"
	.string "过她宝可梦的战斗。$"

FourIsland_Mart_Text_IcefallCaveIsFrigid::
	.string "七岛整体来说是个非常温暖的地区。\p"
	.string "不过有个例外你可得先了解一下。\p"
	.string "冻瀑洞窟由于生活着许多冰属性宝可\n"
	.string "梦，所以那里格外寒冷。$"

