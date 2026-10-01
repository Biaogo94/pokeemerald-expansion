OlivineCity_House3_hns_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "浅黄市临海！\p"
	.string "既然临海，那就少不了鱼！\p"
	.string "我在这里钓鱼钓了30年。\p"
	.string "怎么样？你也想面向大海，试试钓鱼\n"
	.string "的身手吗？$"

OlivineCity_Text_GiveGoodRod:
	.string "啊哈哈！看来又有一位新钓手诞生\n"
	.string "了！$"

OlivineCity_Text_GaveGoodRod:
	.string "鱼儿不仅生活在大海里--只要有水的\n"
	.string "地方就有它们。\p"
	.string "顺便一提，你的宝可梦图鉴会显示宝\n"
	.string "可梦的钓鱼分类群。\p"
	.string "不同的钓点可能会栖息着相似种类的\n"
	.string "鱼。$"

OlivineCity_Text_DontWantGoodRod:
	.string "什--么？你居然不喜欢钓鱼！？真不\n"
	.string "可理喻！$"

OlivineCity_Text_HaveGoodRod:
	.string "战况如何？钓到大鱼了吗？$"
