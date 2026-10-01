GoldenrodCity_FlowerShop_hns_MapScripts::
	.byte 0


GoldenrodCity_FlowerShop_EventScript_MintClerk::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodCity_FlowerShop_Mints
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady::
	msgbox GoldenrodCity_FlowerShop_Text_MintClerkNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_MintClerkNotReady:
	.string "目前商品已售罄。\p"
	.string "请您过段时间再来吧。$"

	.align 2
GoldenrodCity_FlowerShop_Mints:
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	pokemartlistend


GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "我把那棵会摇晃的树告诉姐姐后，她\n"
	.string "说太危险了。\p"
	.string "如果我能打败小茜，不知道她会不会\n"
	.string "把水壶借给我呢……$"

GoldenrodCity_FlowerShop_Text_Owner1:
	.string "听说36号道路上有棵奇怪的树。\p"
	.string "有人说要是给它浇水，它就会跳起舞\n"
	.string "来……\p"
	.string "啊，想都别想！\p"
	.string "虽然这里是花店，也确实有浇水壶"
	.string "。.....\p"
	.string "但我可不能借给你！那太危险了！\p"
	.string "嗯……不过要是你能打败道馆馆主小茜\n"
	.string "的话，说不定还可以考虑一下。$"

GoldenrodCity_FlowerShop_Text_Owner2:
	.string "听说36号道路上有棵奇怪的树。\p"
	.string "有人说要是给它浇水，它就会跳起舞\n"
	.string "来……\p"
	.string "啊，那是满金道馆的常规徽章！\p"
	.string "你打败了小茜吗？！\p"
	.string "既然这样，那就没什么好担心的了，\n"
	.string "对吧？\p"
	.string "那这个杰尼龟喷壶就先借给你用用\n"
	.string "吧。......\p"
	.string "哎呀，算了。直接送给你啦！$"

GoldenrodCity_FlowerShop_Text_Owner3:
	.string "那棵奇怪的树就在36号道路上。请一\n"
	.string "定要小心哦！$"

GoldenrodCity_FlowerShop_Text_Owner4:
    .string "啦啦啦，啦啦啦。可爱的花儿，多喝\n"
    .string "点水吧！$"

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
    .string "哇，你打败了小茜？太帅了！$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
    .string "原来那真的就是宝可梦啊！$"


GoldenrodCity_FlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS, GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

