BattleFrontier_Mart_hns_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk_hns::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart_hns
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart_hns:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan_hns::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson_hns, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman_hns::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy_hns::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems_hns, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson_hns:
	.string "我们是陪孙子一起来的。\p"
	.string "不过既然都来了，就想着顺便买点纪\n"
	.string "念品回去。$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift_hns:
	.string "老头子，你觉得这个怎么样？拿来当\n"
	.string "礼物不是很棒吗？\p"
	.string "这是……蛋……白……质？听起来很好吃对\n"
	.string "吧？$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems_hns:
	.string "对战开拓区的许多设施在对战中都是\n"
	.string "禁止使用道具的。\p"
	.string "这一规则让挑战变得更加艰难了！$"

