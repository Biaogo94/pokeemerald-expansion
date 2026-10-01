Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "俺家的大奶罐挤不出奶来了。\p"
	.string "俺们农场的鲜奶可是很有名的，\p"
	.string "大家都争着想喝呢。\p"
	.string "俺琢磨着，要是喂它多多的树果，它\n"
	.string "肯定又能产出好多鲜奶了。$"

Route39_Text_FarmerMBuyMilk:
	.string "要来点俺家的哞哞鲜奶吗？\p"
	.string "这可是俺的骄傲啊。\p"
	.string "喂给宝可梦就能回复HP！\p"
	.string "只要500元，俺就卖给你一瓶。$"

Route39_Text_FarmerMGotMilk:
	.string "拿好喽！趁新鲜好好享用吧！$"

Route39_Text_FarmerMNoMoney:
	.string "抱歉啦。没钱可不能卖给你哦！$"

Route39_Text_FarmerMNoRoom:
	.string "看来你的背包已经满了啊。$"

Route39_Text_FarmerMNoSale:
	.string "不想要了吗？欢迎下次再来啊！$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "要不再来一瓶？$"

Route39_Text_GotMilk:
	.string "{PLAYER}获得了哞哞鲜奶。$"

Route39_Text_FarmerMMilking:
	.string "我得去挤奶啦。$"

Route39_Text_FarmerFInTrouble:
	.string "我们的牛奶甚至还运往关都呢。\p"
	.string "所以要是我们的大奶罐产不出奶，那\n"
	.string "麻烦可就大啦。$"

Route39_Text_FarmerFHealedMiltank:
	.string "你治好了我们的大奶罐，真是太感谢\n"
	.string "了。现在它又能产出哞哞鲜奶啦。\p"
	.string "这点心意请收下，辛苦你啦。$"

Route39_Text_FarmerFSnatchSpeech:
	.string "那个是“抢夺”。\p"
	.string "这招非常狡黠，可以让宝可梦在对手\n"
	.string "使出招式前将其抢先夺取过来。\p"
	.string "如果有不止一只宝可梦使用“抢夺”，\n"
	.string "只有速度最慢的那只才能成功抢到招\l"
	.string "式。\p"
	.string "聪明地使用它吧，时机就是一切。$"
