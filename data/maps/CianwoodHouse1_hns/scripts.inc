CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "我都记不清上一次有人来拜访我是什\n"
	.string "么时候了。\p"
	.string "年轻时，我也曾是一名宝可梦训练家\n"
	.string "。登过巍峨高塔，也潜过浩瀚深海。\p"
	.string "凡事都倾注了无数心血。\p"
	.string "不过现在嘛，我在这片海滩上听听风\n"
	.string "浪声，过着清闲日子，倒也乐得自在\l"
	.string "。$"

CianwoodCity_Text_BellTowerStory:
	.string "你听说过缘朱市的铃铛塔吗？\p"
	.string "据说在塔顶上挂着被称为“透明铃\n"
	.string "铛”的东西。\p"
	.string "即使狂风呼啸，它们也不会发出半点\n"
	.string "声响。\p"
	.string "要想让它们鸣响，只有一个办法。\p"
	.string "那就是拿到另一枚与塔顶一模一样的\n"
	.string "透明铃铛。\p"
	.string "我年轻时也曾追寻过它，可惜最终一\n"
	.string "无所获……$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "你听说过漩涡列岛吗？\p"
	.string "据说在瀑布潭深处，挂着被称为“海\n"
	.string "潮铃铛”的东西。\p"
	.string "即使巨浪翻滚，它们也不会发出半点\n"
	.string "声响。\p"
	.string "要想让它们鸣响，只有一个办法。\p"
	.string "那就是拿到另一枚与瀑布潭一模一样\n"
	.string "的海潮铃铛。\p"
	.string "我年轻时也曾追寻过它，可惜最终一\n"
	.string "无所获……$"

CianwoodCity_Text_ClearBellReaction:
	.string "噢！你居然拿到了透明铃铛？！\p"
	.string "那可是我当年的梦想啊……\n"
	.string "原来如此……\p"
	.string "你真的做到了……\n"
	.string "……我听到了！\p"
	.string "乘着微风，从铃铛塔的方向传来了清\n"
	.string "脆悠扬的铃声……$"

CianwoodCity_Text_TidalBellReaction:
	.string "噢！你居然拿到了海潮铃铛？！\p"
	.string "那可是我当年的梦想啊……\n"
	.string "原来如此……\p"
	.string "你真的做到了……\n"
	.string "……我听到了！\p"
	.string "乘着海风，从漩涡列岛的方向传来了\n"
	.string "清脆悠扬的铃声……$"
