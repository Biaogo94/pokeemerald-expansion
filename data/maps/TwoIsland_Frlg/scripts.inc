TwoIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_OnTransition
	.byte 0

TwoIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_VISITED_TWO_ISLAND
	call TwoIsland_EventScript_SetShopState
	end

TwoIsland_EventScript_SetShopState::
	goto_if_set FLAG_IS_CHAMPION, TwoIsland_EventScript_SetShopStateAfterHoennLink
	goto_if_set FLAG_SYS_GAME_CLEAR, TwoIsland_EventScript_SetShopStateAfterChampion
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopStateAfterLostelleRescue
	goto TwoIsland_EventScript_SetShopStateDefault
	end

TwoIsland_EventScript_SetShopStateAfterHoennLink::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_SetShopExpanded2
	goto TwoIsland_EventScript_SetShopExpanded3
	end

TwoIsland_EventScript_SetShopStateAfterChampion::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto TwoIsland_EventScript_SetShopExpanded2
	end

TwoIsland_EventScript_SetShopStateAfterLostelleRescue::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto TwoIsland_EventScript_SetShopExpanded1
	end

TwoIsland_EventScript_SetShopStateDefault::
	goto TwoIsland_EventScript_SetShopInitial
	end

TwoIsland_EventScript_SetShopInitial::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 1
	return

TwoIsland_EventScript_SetShopExpanded1::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 2
	clearflag FLAG_HIDE_TWO_ISLAND_WOMAN
	return

TwoIsland_EventScript_SetShopExpanded2::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 3
	clearflag FLAG_HIDE_TWO_ISLAND_BEAUTY
	return

TwoIsland_EventScript_SetShopExpanded3::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 4
	clearflag FLAG_HIDE_TWO_ISLAND_SUPER_NERD
	return

TwoIsland_EventScript_Clerk::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ClerkShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ClerkShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ClerkShopExpanded1
	goto TwoIsland_EventScript_ClerkShopInitial
	end

TwoIsland_EventScript_ClerkShopExpanded3::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_3, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_3
	message TwoIsland_Text_BringingItemsFromDistantLands
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded3
	end

TwoIsland_EventScript_ClerkShopExpanded2::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_2
	message TwoIsland_Text_HopeYouGiveItYourBest
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded2
	end

TwoIsland_EventScript_ClerkShopExpanded1::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_1
	message TwoIsland_Text_AddedMerchandiseForLostelle
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded1
	end

TwoIsland_EventScript_ClerkShopInitial::
	goto_if_set FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_INTRODUCED
	message TwoIsland_Text_WelcomeToShopMerchandiseLimited
	waitmessage
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ClerkShopSkipIntro::
	message gText_HowMayIServeYou
	waitmessage
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ShopExpanded1
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ShopInitial::
	pokemart TwoIsland_Items_ShopInitial
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopInitial::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded1::
	pokemart TwoIsland_Items_ShopExpanded1
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded1::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded2::
	pokemart TwoIsland_Items_ShopExpanded2
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded2::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded3::
	pokemart TwoIsland_Items_ShopExpanded3
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded3::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_Sailor::
	msgbox TwoIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
	end

TwoIsland_EventScript_Woman::
	msgbox TwoIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
	end

TwoIsland_EventScript_Beauty::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 4
	msgbox TwoIsland_Text_BrunoCameToIslandWhileBack
	release
	end

TwoIsland_EventScript_SuperNerd::
	msgbox TwoIsland_Text_BuyRareItemsHere, MSGBOX_NPC
	end

TwoIsland_EventScript_Boy::
	msgbox TwoIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_EventScript_LittleBoy::
	msgbox TwoIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
	end

TwoIsland_EventScript_IslandSign::
	msgbox TwoIsland_Text_IslandSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_JoyfulGameCornerSign::
	msgbox TwoIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_FastCurrentSign::
	msgbox TwoIsland_Text_DangerFastCurrent, MSGBOX_SIGN
	end

TwoIsland_Text_IslandSign::
	.string "二之岛又叫友谊岛$"

TwoIsland_Text_JoyfulGameCornerSign::
	.string "跳绳和树果！欢乐的游戏厅$"

TwoIsland_Text_DangerFastCurrent::
	.string "危险！水流湍急！禁止钓鱼和冲浪！$"

TwoIsland_Text_WelcomeToShopMerchandiseLimited::
	.string "啊！你好，欢迎来我的小店！\p"
	.string "小店最近才开张。\p"
	.string "买的东西还不多，希望能有你需要\n"
	.string "的。$"

TwoIsland_Text_AddedMerchandiseForLostelle::
	.string "我不知道该怎么感谢你才好，你救了\n"
	.string "小迷。\p"
	.string "多亏了你的壮举，让三之岛的人改变\n"
	.string "了对关都人的看法。\p"
	.string "你要知道，我就一个是关都人。\p"
	.string "三之岛的人们帮我添置了很多新货\n"
	.string "品。$"

TwoIsland_Text_HopeYouGiveItYourBest::
	.string "嗨！我拿出了最好的东西在这里卖。\n"
	.string "希望{PLAYER}你也拿出最好\l"
	.string "的状态来买。$"

TwoIsland_Text_BringingItemsFromDistantLands::
	.string "嗨，你好，{PLAYER}！欢迎\n"
	.string "光临！\p"
	.string "我从远方的岛上运来新货品了。\p"
	.string "我现在也开始卖些稀有物品了。请随\n"
	.string "便看看！$"

TwoIsland_Text_FellowMovedFromCeladonCity::
	.string "那边那个小伙子，他是从玉虹市过来\n"
	.string "的。\p"
	.string "他和他弟弟开了个店。\p"
	.string "你也许会怀疑他到底懂不懂怎么开\n"
	.string "店。$"

TwoIsland_Text_ShopkeepersBrotherWorksGameCorner::
	.string "店主的弟弟在游戏厅找了个工作。\p"
	.string "他想多攒点钱，这样就能进更多货\n"
	.string "了。$"

TwoIsland_Text_BrunoCameToIslandWhileBack::
	.string "喂，喂。你知道吗？\p"
	.string "有个著名的训练家来岛上没多久就走\n"
	.string "了。\p"
	.string "据说他叫希巴。还是四天王之一。\p"
	.string "他得知兄弟俩的愤怒馒头卖完后就失\n"
	.string "望地离开了。$"

TwoIsland_Text_BuyRareItemsHere::
	.string "有眼光的顾客都会来这里买稀有物\n"
	.string "品！$"

TwoIsland_Text_OldWomanLivesOutOnCape::
	.string "远方的小屋里住着个老太太。\p"
	.string "她能用她的眼睛对宝可梦做出判断。\n"
	.string "这有点令人不安呢。$"

TwoIsland_Text_HaveYouTriedJumpingGame::
	.string "卟卟卟！卟卟卟！你试过越野赛吗？\p"
	.string "能参加的宝可梦是……卟卟卟！\p"
	.string "有些速度慢，卟卟卟！\p"
	.string "有些速度超级快，卟卟卟卟卟卟！\p"
	.string "你听懂了吗？卟卟卟！$"

