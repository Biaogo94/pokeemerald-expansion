EventScript_MomGiftCall_Item::
	lockall
	pokenavcall Mom_Text_GiftCall_Item
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Berry::
	lockall
	pokenavcall Mom_Text_GiftCall_Berry
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

Mom_Text_GiftCall_Item:
	.string "妈妈：嗨，宝贝！\p"
	.string "我用你存的钱买了样好东西！\p"
	.string "已经寄到你的电脑里了。要照顾好自\n"
	.string "己！$"

Mom_Text_GiftCall_Berry:
	.string "妈妈：嗨，宝贝！\p"
	.string "在商店看到好树果，就给你买了一\n"
	.string "些！\p"
	.string "已经寄到你的电脑里了。要照顾好自\n"
	.string "己！$"

Mom_Text_GiftCall_Decoration:
	.string "妈妈：嗨，宝贝！\p"
	.string "我给你的房间买了个可爱的宝可梦玩\n"
	.string "偶！\p"
	.string "回家记得看看装饰品哦。要照顾好自\n"
	.string "己！$"
