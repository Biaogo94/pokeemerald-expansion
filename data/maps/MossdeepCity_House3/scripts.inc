MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "喂，那边那位训练家！厉害钓竿真的\n"
	.string "非常妙！\p"
	.string "即使你想要海底的宝可梦，它也能把\n"
	.string "它们钓出来！\p"
	.string "你觉得呢？你想要是吧？$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "当然，当然！毕竟，厉害钓竿真的非\n"
	.string "常妙！$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "只要有水，就甩出你的钓竿来钓鱼吧\n"
	.string "！$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "哎？你不喜欢钓鱼吗？$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "用你的厉害钓竿寻找海底的宝可梦吧\n"
	.string "。$"

