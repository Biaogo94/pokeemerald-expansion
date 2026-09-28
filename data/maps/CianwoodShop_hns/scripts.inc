CianwoodShop_hns_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::	
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
	.string "你的宝可梦看起来很有活力啊。\p"
	.string "是有什么烦心事吗？\p"
	.string "......\p"
	.string "灯塔里的宝可梦病了？\p"
	.string "包在我身上！\p"
	.string "这个肯定能派上用场。$"

CianwoodCity_Text_ReceivedSecretpotion:
	.string "{PLAYER}获得了秘传药。$"

CianwoodCity_Text_PharmacistDescribePotion:
	.string "我的秘传药药效有点太强了，所以只\n"
	.string "有在紧急关头我才会拿出来。$"
