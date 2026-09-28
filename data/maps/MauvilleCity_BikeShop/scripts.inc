MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "哎呀哎呀，看看是谁来了？一位充满\n"
	.string "活力的客人！\p"
	.string "我？你可以叫我风野，我是这家车店\n"
	.string "的店主。$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "风野：你的跑步鞋……看上去已经很\n"
	.string "脏了。\p"
	.string "你是从很远的地方来的吗？$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "风野：是吗？\p"
	.string "那么我想你不需要我的自行车。$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "风野：唔，唔…… ……\p"
	.string "你说你从未白镇一路来到这里？\p"
	.string "天啊！那么远的地方！\p"
	.string "如果你骑着我的自行车，你可以在感\n"
	.string "受轻风拂面的同时轻轻松松地到任何\l"
	.string "地方去！\p"
	.string "我跟你说！我给你辆自行车！\p"
	.string "啊，等等！\p"
	.string "忘了告诉你，我这儿有两种自行车！\p"
	.string "分别是音速自行车和越野自行车！\p"
	.string "音速自行车是为追风的单车一族而设\n"
	.string "计，\p"
	.string "而越野自行车则是给喜爱车技的人所\n"
	.string "准备！\p"
	.string "我是好心人，所以让你随便挑一种！\p"
	.string "你想要哪样？$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER}选择了音速自行车\n"
	.string "。$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER}选择了越野自行车\n"
	.string "。$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "风野：如果你想换一辆自行车，再回\n"
	.string "来找我！$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "风野：哦？你想换一辆车吗？$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "风野：好，没问题！我给你换一辆车\n"
	.string "！$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER}把音速自行车换成\n"
	.string "了越野自行车。$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER}把越野自行车换成\n"
	.string "了音速自行车。$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "风野：好，好！我很高兴你能喜欢它\n"
	.string "！$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "哎？我给你的自行车呢？\p"
	.string "啊，明白了，你把它存到电脑里面了\n"
	.string "。\p"
	.string "把它从电脑里拿出来吧，我很乐意为\n"
	.string "你换一辆！\p"
	.string "愿你在旅行中体会到追风的快乐！$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "我在这儿工作的时候学到了很多关于\n"
	.string "自行车的知识。\p"
	.string "如果你想知道怎么骑车，那边有几本\n"
	.string "说明书。$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "是音速自行车的说明书。\p"
	.string "想读哪一页？$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "按方向键可以使自行车向相应的方向\n"
	.string "移动。\p"
	.string "持续移动的话车会加速。\p"
	.string "若要停止，则松开方向键，自行车会\n"
	.string "慢慢减速停下。\p"
	.string "还要翻到其他页吗？$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "音速自行车速度很快，但并不容易停\n"
	.string "下，\p"
	.string "转弯的时候也有些麻烦，\p"
	.string "需要提前松开方向键减速。\p"
	.string "还要翻到其他页吗？$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "丰缘地区中某些地方有小沙坡，\p"
	.string "普通方法很难爬上这些松散细碎的斜\n"
	.string "坡，\p"
	.string "但如果骑着音速自行车就能冲上沙坡\n"
	.string "。\p"
	.string "还要翻到其他页吗？$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "是越野自行车的说明书。\p"
	.string "想读哪一页？$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "骑车时按住B键可以抬起前轮，\p"
	.string "此时按方向键能够抬着前轮移动。\p"
	.string "这叫做后轮特技。\p"
	.string "还要翻到其他页吗？$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "一直按住B键，自行车会原地跳跃。\p"
	.string "这叫做弹跳。\p"
	.string "弹跳时也可以继续骑车。\p"
	.string "还要翻到其他页吗？$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "同时按下方向键和B键进行侧跳。\p"
	.string "按方向键决定向哪一边侧跳。\p"
	.string "跳起时按反方向可以使自行车调头。\p"
	.string "还要翻到其他页吗？$"

