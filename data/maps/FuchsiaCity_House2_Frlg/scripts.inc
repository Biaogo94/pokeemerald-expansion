FuchsiaCity_House2_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
	.string "我是钓鱼大师的哥哥。\p"
	.string "我非常喜欢钓鱼！没有钓鱼的生活我\n"
	.string "真难以想象。\p"
	.string "告诉我，你喜欢钓鱼吗？$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
	.string "漂亮！我喜欢你的态度！我认为我们\n"
	.string "可以成为朋友。\p"
	.string "拿着它去钓鱼吧，年轻的朋友！$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
	.string "{PLAYER}从钓鱼大师的哥哥\n"
	.string "那里得到了好钓竿。$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
	.string "钓鱼是一种生活方式！就像是最优美\n"
	.string "的诗歌。\p"
	.string "寒酸的破钓竿只能够钓到鲤鱼王，对\n"
	.string "吗？\p"
	.string "但是有了好钓竿之后，你可以钓到更\n"
	.string "多更强的宝可梦。$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
	.string "喔……真没劲儿……$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
	.string "你好，{PLAYER}！\p"
	.string "钓鱼钓得怎么样啦？$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
	.string "喔不，\p"
	.string "我有一个礼物要给你，但是你背包放\n"
	.string "不下了了！$"

