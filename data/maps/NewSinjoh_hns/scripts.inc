NewSinjoh_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_On_Transition
	.byte 0

NewSinjoh_On_Transition:
    setflag FLAG_VISITED_NEW_SINJOH
	end

NewSinjoh_EventScript_TriggerNorthGate::
	lock
	msgbox NewSinjoh_Text_TriggerNorthGate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

NewSinjoh_Text_TriggerNorthGate:
	.string "最好别让艺裳少女们久等了。$"

NewSinjoh_EventScript_PetStantler::
    lock
	faceplayer
	playmoncry SPECIES_STANTLER, 0
	msgbox NewSinjoh_Text_Stantler_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Stantler_Cry:
    .string "嘞噜噜噜--！$"

NewSinjoh_EventScript_Steven::
	msgbox NewSinjoh_Text_Steven, MSGBOX_AUTOCLOSE
	end

NewSinjoh_Text_Steven:
	.string "大吾：这位女士，需要我带您去那边\n"
	.string "的温泉吗？\p"
	.string "那里看起来还有很多空位。$"

NewSinjoh_MilkMan_EventScript_Seller::
	lock
	faceplayer
	checkitem ITEM_MOOMOO_MILK, 99
	goto_if_eq VAR_RESULT, 1, MilkMan_EventScript_Battle
	showmoneybox 0, 0
	msgbox NewSinjoh_MilkMan_text_BuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk
	msgbox NewSinjoh_MilkMan_NoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_EventScript_MilkMan_BuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox NewSinjoh_MilkMan_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk

	msgbox NewSinjoh_MilkMan_GotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox NewSinjoh_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_BagFull::
	msgbox NewSinjoh_MilkMan_NoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_MilkMan_NotEnough::
	msgbox NewSinjoh_MilkMan_NoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_text_BuyMilk:
	.string "我是牛奶工。\p"
	.string "我的牛奶很美味。\p"
	.string "今天如果想来一瓶的话，只要500日\n"
	.string "元。$"

NewSinjoh_MilkMan_GotMilk:
	.string "拿好！里面添加了这个世界所渴求的\n"
	.string "滋味。$"

NewSinjoh_MilkMan_NoMoney:
	.string "抱歉啦。带够钱再来买吧！$"

NewSinjoh_MilkMan_NoRoom:
	.string "你的背包好像已经装满了。$"

NewSinjoh_MilkMan_NoSale:
	.string "你真的不想要吗？这里面可饱含了这\n"
	.string "个世界应得的一切。$"

NewSinjoh_MilkMan_Text_WouldYouLikeAnother:
	.string "要不再来一瓶？$"

NewSinjoh_Text_GotMilk:
	.string "{PLAYER}获得了哞哞鲜奶。$"

MilkMan_EventScript_Battle:: 
    msgbox MilkMan_Battle_text
    Trainerbattle_no_intro TRAINER_MILKMAN_HNS, NewSinjoh_MilkMan_text_Lose
    release
    end

MilkMan_Battle_text:
	.string "我是牛奶工，\p"
	.string "我的牛奶很美味。\p"
	.string "今天可是特别派送！$"

NewSinjoh_MilkMan_text_Lose:
	.string "这个世界很完美，不是吗？$"

NewSinjoh_Script_TravelMart::
	lock
	faceplayer
	message NewSinjoh_Text_TravelShopGreeting
	waitmessage
	pokemart NewSinjoh_Pokemart_TravelShop
	msgbox NewSinjoh_Text_TravelShopEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Pokemart_TravelShop:
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ELIXER
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_MAX_LURE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE

NewSinjoh_Text_TravelShopGreeting:
	.string "欢迎光临我的杂货小铺。请问有什么\n"
	.string "需要吗？$"

NewSinjoh_Text_TravelShopEnd:
	.string "欢迎下次光临。$"

Script_NewSinjoh_Traveler_Brother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_TravelBrother_Greeting
	release
	end

NewSinjoh_Text_TravelBrother_Greeting:
    .string "店里的所有商品都是纯手工制作和本\n"
    .string "地采摘的哦！\p"
    .string "我姐姐之所以开这家店，是因为友好\n"
    .string "商店根本不肯在离大城镇这么远的地\l"
    .string "方开分店。$"

NewSinjoh_EventScript_Josh::
	msgbox NewSinjoh_Text_Josh, MSGBOX_NPC
	end

NewSinjoh_Text_Josh:
	.string "这地方简直太棒了！\p"
	.string "这么好的温泉藏着不让世人知道，实\n"
	.string "在太暴殄天物了。\p"
	.string "我一定要把这里推荐给所有朋友！$"

NewSinjoh_EventScript_Janice::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_JaniceAfter
	msgbox NewSinjoh_Text_Janice, MSGBOX_NPC
	end
NewSinjoh_EventScript_JaniceAfter::
	msgbox NewSinjoh_Text_JaniceAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Janice:
	.string "这里的温泉太神奇了，但我总觉得当\n"
	.string "地人一直在用白眼瞪我们。$"
NewSinjoh_Text_JaniceAfter:
	.string "这里的温泉太神奇了，而且只要混熟\n"
	.string "了之后，就会发现当地人特别亲切！$"

NewSinjoh_EventScript_OldLady1::
	msgbox NewSinjoh_Text_OldLady1, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady1:
	.string "没什么比这绝美的风景更能让我这把\n"
	.string "老骨头焕发生机的了。$"

NewSinjoh_EventScript_OldLady2::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady2Steven
	msgbox NewSinjoh_Text_OldLady2, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady2Steven::
	msgbox NewSinjoh_Text_OldLady2Steven, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady2:
	.string "好极了，现在这帮游客把咱们的温泉\n"
	.string "给霸占了！\p"
	.string "最近真是一件顺心的事都没有！$"
NewSinjoh_Text_OldLady2Steven:
	.string "真是个俊俏的小伙子！\p"
	.string "看来这些游客倒也没那么讨厌嘛。$"

NewSinjoh_EventScript_OldLady3::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady3After
	msgbox NewSinjoh_Text_OldLady3, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady3After::
	msgbox NewSinjoh_Text_OldLady3After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady3:
	.string "那个女人怎么能对客人这么无礼呢？\p"
	.string "她真该去温泉里泡泡降降火。\p"
	.string "这池子这么大，完全容得下所有人\n"
	.string "呀。$"
NewSinjoh_Text_OldLady3After:
	.string "看来这里的大家都已经开始接纳彼此\n"
	.string "了。\p"
	.string "真好！$"

NewSinjoh_EventScript_SpringsSage::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_SpringsSageAfter
	msgbox NewSinjoh_Text_SpringsSage, MSGBOX_NPC
	end
NewSinjoh_EventScript_SpringsSageAfter::
	msgbox NewSinjoh_Text_SpringsSageAfter, MSGBOX_NPC
	end

NewSinjoh_Text_SpringsSage:
	.string "自从新居民来到之后，我们村落里就\n"
	.string "产生了很多隔阂与纷争。\p"
	.string "无论持何种立场，原有的平衡显然已\n"
	.string "经被打破了。\p"
	.string "请善待当地人，也请善待游客。$"
NewSinjoh_Text_SpringsSageAfter:
	.string "自从传说的宝可梦平息下来之后，情\n"
	.string "况就慢慢好转了。\p"
	.string "平衡又重新回到了神都。$"

NewSinjoh_EventScript_Sage2::
	msgbox NewSinjoh_Text_Sage2, MSGBOX_NPC
	end

NewSinjoh_Text_Sage2:
	.string "时代虽在变迁，但惊角鹿依然会在此\n"
	.string "聚集。光是这一点，就值得我们心怀\l"
	.string "感激了。$"

NewSinjoh_EventScript_Daughter::
	msgbox NewSinjoh_Text_Daughter, MSGBOX_NPC
	end

NewSinjoh_Text_Daughter:
    .string "哇咿--！！\p"
    .string "妈妈快看！我没用手扶哦！\p"
    .string "就和单板滑雪选手一样！$"

NewSinjoh_EventScript_Mother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_Mother, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_MOTHER, DIR_EAST
	release
	end

NewSinjoh_Text_Mother:
    .string "看我家宝贝滑得多棒呀！\p"
    .string "这个冰场代代相传至今，但在新居民\n"
    .string "搬来之前，孩子们可从没来这里玩过\l"
    .string "呢。$"

NewSinjoh_EventScript_Welcome_Sign::
	msgbox NewSinjoh_Text_Welcome_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Welcome_Sign:
	.string "新神都$"

NewSinjoh_EventScript_Resturant_Sign::
	msgbox NewSinjoh_Text_Resturant_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Resturant_Sign:
	.string "家庭咖啡馆$"

NewSinjoh_EventScript_Cave_Sign::
	msgbox NewSinjoh_Text_Cave_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Cave_Sign:
	.string "温泉洞窟$"

NewSinjoh_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_HikerAfter
	msgbox NewSinjoh_Text_Hiker, MSGBOX_NPC
	end
NewSinjoh_EventScript_HikerAfter::
	msgbox NewSinjoh_Text_HikerAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Hiker:
	.string "生意可红火了！不过自从城里人对我\n"
	.string "们这个小镇产生兴趣后，物价也跟着\l"
	.string "涨起来了。$"
NewSinjoh_Text_HikerAfter:
	.string "生意可红火了！\p"
	.string "而且那位银发先生给的小费特别丰\n"
	.string "厚，物价总算降下来啦！$"

NewSinjoh_EventScript_OldLady4::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady4After
	msgbox NewSinjoh_Text_OldLady4, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady4After::
	msgbox NewSinjoh_Text_OldLady4After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady4:
	.string "我只卖给本地人！$"
NewSinjoh_Text_OldLady4After:
	.string "我说了，依然只卖给本地人！$"

NewSinjoh_EventScript_Item_DuskBall::
	finditem ITEM_DUSK_BALL
    end


