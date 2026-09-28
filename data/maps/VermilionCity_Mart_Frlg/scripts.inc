VermilionCity_Mart_Frlg_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_CooltrainerF::
	msgbox VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_BaldingMan::
	msgbox VermilionCity_Mart_Text_TeamRocketAreWickedPeople, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VermilionCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
VermilionCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

VermilionCity_Mart_Text_TeamRocketAreWickedPeople::
	.string "有一些邪恶的人们用宝可梦从事犯罪\n"
	.string "活动。\p"
	.string "比如说，火箭队非法交易珍贵的宝可\n"
	.string "梦。\p"
	.string "他们也遗弃那些他们认为不受欢迎的\n"
	.string "或没用了的宝可梦。\p"
	.string "我说的就是火箭队，他们真是一群可\n"
	.string "怕的人。$"

VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer::
	.string "我认为宝可梦品质是好是坏。完全取\n"
	.string "决于它的训练家。$"

