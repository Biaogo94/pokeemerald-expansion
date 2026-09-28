EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "啊，你正带着宝可梦到处冒险吗？\p"
	.string "话说回来，冒险怎么能少得了寻宝呢\n"
	.string "？\p"
	.string "你说对不对，嗯？$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "太好了！你很懂得冒险的真正意义嘛\n"
	.string "。\p"
	.string "我喜欢你这样的孩子！把这个带上吧\n"
	.string "。$"

Ecruteak_Text_ItemfinderExplanation:
	.string "There are many items lying about\n"
	.string "that aren't obvious.\p"
	.string "Use DOWSING MACHINE to check if there\n"
	.string "is an item on the ground near you.\p"
	.string "It doesn't show the exact spot,\n"
	.string "so you'll have to look yourself.\p"
	.string "Oh yeah--I heard there are items\n"
	.string "in ECRUTEAK's BURNED TOWER.$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "哎......真是人各有志呢..\n"
	.string "....$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "圆朱市是一座历史悠久的城市。许多\n"
	.string "世代的人们都把历史记录在这样的书\l"
	.string "籍中代代相传。$"

Ecruteak_Text_HistoryBook:
	.string "《圆朱市的历史》\p"
	.string "要阅读吗？$"

Ecruteak_Text_TwoTowers:
	.string "圆朱市曾经耸立着两座高塔。\p"
	.string "两座塔分别是两只强大的飞翔宝可梦\n"
	.string "的栖居之所。\p"
	.string "但其中一座塔被大火烧毁殆尽。\p"
	.string "自那以后，这两只宝可梦便再也没有\n"
	.string "现身过......\p"
	.string "要继续阅读吗？$"

Ecruteak_Text_ThreeMon:
	.string "在圆朱市，还曾有三只宝可梦在此疾\n"
	.string "驰奔跑。\p"
	.string "据说它们分别诞生于水、雷电与烈火\n"
	.string "之中。\p"
	.string "但它们无法抑制体内过于庞大的力量\n"
	.string "。\p"
	.string "因此据说这三只宝可梦如同疾风一般\n"
	.string "奔向了草原深处。$"
