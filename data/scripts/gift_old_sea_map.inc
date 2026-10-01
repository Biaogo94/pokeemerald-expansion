MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "感谢使用神秘礼物系统。\p"
	.string "让我确认一下……你是\n"
	.string "{PLAYER}吧？\p"
	.string "这里有一张寄给你的古航海图。$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "这个看起来是可以在水静市港口使用\n"
	.string "的。\p"
	.string "为什么不试一下看看它到底是什么？$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "感谢使用神秘礼物系统。$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "哦，抱歉，{PLAYER}。您的\n"
	.string "背包里放重要物品的口袋满了。\p"
	.string "请存一些东西到电脑然后回来拿这个\n"
	.string "吧。$"
