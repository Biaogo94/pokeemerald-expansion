MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "感谢使用神秘礼物系统。\p"
	.string "您的对战积分卡保留着您和其他拥有\n"
	.string "相同卡的训练家对战录像。\p"
	.string "寻找并和拥有与您有相同卡的训练家\n"
	.string "进行对战吧。\p"
	.string "您可以检查最终排名通过阅读新闻。\p"
	.string "请一定要试试看！$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "感谢使用神秘礼物系统。\p"
	.string "恭喜！\p"
	.string "您获得了赢取3场对战的奖励！\p"
	.string "希望您再接再厉进行更多对战。$"
