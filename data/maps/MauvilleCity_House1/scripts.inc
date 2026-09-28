MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "呀嗬！\p"
	.string "人们叫我碎岩大叔，但我不喜欢被这\n"
	.string "么叫，\p"
	.string "我应该有个更棒的称呼，比如碎岩小\n"
	.string "哥什么的。\p"
	.string "呀嗬！\p"
	.string "不管怎样，你的宝可梦似乎很强。\p"
	.string "我喜欢！那，这个秘传学习器给你！$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "那个秘传学习器的内容是碎岩，\p"
	.string "如果你碰到有巨石挡了你的路……\p"
	.string "那么，就用这秘传学习器把它们打得\n"
	.string "粉碎！\p"
	.string "是的！我说，把巨岩打碎！呀嗬！$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "哦，对了，如果你打碎了岩石，藏在\n"
	.string "里面的宝可梦可能会跳出来。\p"
	.string "呀嗬！$"

