RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "那坚定的表情……敏捷的行动……还有训\n"
	.string "练有素的宝可梦……\p"
	.string "你肯定是个经验丰富的训练家！\p"
	.string "不，别急，不用说，我知道你想要什\n"
	.string "么。\p"
	.string "我想你会善加利用这个秘传学习器\n"
	.string "的。\p"
	.string "不用谦虚，这是你的了！$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "那个秘传学习器的内容是居合劈。\p"
	.string "秘传招式是可以让宝可梦在战斗外也\n"
	.string "能使用的招式。\p"
	.string "如果训练家得到了岩石徽章，那么学\n"
	.string "会居合劈的宝可梦就能砍倒小树。\p"
	.string "而且，和招式学习器不同的是，秘传\n"
	.string "学习器可以使用很多次。$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "当初扩建卡那兹市时，我爸爸也帮了\n"
	.string "忙。\p"
	.string "他让宝可梦使用居合劈砍掉树木，清\n"
	.string "出了土地。$"

