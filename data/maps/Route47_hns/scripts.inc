Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "想念别人......也就那样吧。\p"
	.string "但对战就是对战，放马过来吧！$"

Route47_Text_HikerBeaten::
	.string "哇哈哈！$"

Route47_Text_HikerAfter::
	.string "对战结束后，就该潇洒地大笑着道别\n"
	.string "嘛！$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "我不擅长应付人多的地方，所以才和\n"
	.string "宝可梦在这里露营！$"

Route47_Text_CamperBeaten::
	.string "我想我该往更深的山里走走了...\n"
	.string "...$"

Route47_Text_CamperAfter::
	.string "回见啦！$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "汤姆：1加1等于2，但只要\n"
	.string "我们两人联手，就会变得更强！\p"
	.string "凯：我们可不是什么普普通通\n"
	.string "的组合哦！$"

Route47_Text_Couple1Beaten::
	.string "汤姆：这可真出乎我的意料。\n"
	.string "凯：你也太不按常理出牌了！$"

Route47_Text_Couple1After1::
	.string "汤姆：看来你的实力真是难以\n"
	.string "预测啊！$"

Route47_Text_Couple1After2::
	.string "凯：我还以为你只是个普通的\n"
	.string "独行训练家，真是看走眼了！$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "达夫：守护着我的女朋友，我\n"
	.string "的心情就会激动澎湃！\p"
	.string "艾达：我对男朋友的爱意，比大\n"
	.string "海还要辽阔深沉！$"

Route47_Text_Couple2Beaten::
	.string "达夫：完全不是你的对手……\n"
	.string "艾达：你真是不简单啊\l"
	.string "……$"

Route47_Text_Couple2After1::
	.string "达夫：感谢你带来如此精彩的\n"
	.string "对战！再见啦！$"

Route47_Text_Couple2After2::
	.string "艾达：你也一定要找一个绝妙的\n"
	.string "伴侣哦！$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "你好呀！\p"
	.string "据说穿过这个洞穴，以前曾耸立着一\n"
	.string "座直插云霄的高大巨塔。\p"
	.string "他们说那是一座非常奇特的塔，有半\n"
	.string "截甚至嵌在悬崖之中。\p"
	.string "它不仅是一座高耸入云的巨塔，更是\n"
	.string "深潜入地底之下！\p"
	.string "甚至有传闻说它一路延伸到了海底的\n"
	.string "最深处！\p"
	.string "简而言之，那处遗迹曾经将天空、大\n"
	.string "地与海洋彼此连接在一起.....\l"
	.string ".\p"
	.string "如今巨塔的大部分都已坍塌，残留的\n"
	.string "只有入口与内部，在那里能看到一些\l"
	.string "奇异的纹路。$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "灯笼鱼：啾--！$"
