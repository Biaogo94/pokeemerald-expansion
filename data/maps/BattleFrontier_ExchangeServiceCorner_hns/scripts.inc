BattleFrontier_ExchangeServiceCorner_hns_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokeBallClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPokeBallShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PowerClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF_hns::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns:
	.string "你好，这里是兑换服务处。\p"
	.string "我们可以将您收集的对战点数兑换成\n"
	.string "精美的奖品。\p"
	.string "请从这张清单中选择奖品。$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns:
	.string "哇，它们太棒了！真想全部拥有！可\n"
	.string "爱的靠垫！大毛绒玩偶！小毛绒玩\l"
	.string "偶！真希望我能全部带回家！$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns:
	.string "包在妈妈身上！\p"
	.string "只要是宝贝想要的，无论怎样妈妈都\n"
	.string "会给你弄到手的！$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns:
	.string "只要能拿到这里的道具，我的宝可梦\n"
	.string "就会变得更强。\p"
	.string "绝对会变强！毫无疑问！$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns:
	.string "哈？你发什么呆地看着我？\p"
	.string "我很讨厌你那样盯着我的毛绒玩偶\n"
	.string "看。\p"
	.string "想要的话，自己去拿一个啊！对吧，\n"
	.string "迷唇娃？$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns:
	.string "你知道吗？\p"
	.string "只要在任何对战设施里连胜延长纪\n"
	.string "录，他们给你的对战点数就会越来越\l"
	.string "多。$"
