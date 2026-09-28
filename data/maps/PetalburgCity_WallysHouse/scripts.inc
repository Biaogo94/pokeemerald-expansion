PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "你是……啊，你一定就是\n"
	.string "{PLAYER}{KUN}吧？\p"
	.string "谢谢你刚才能和满充一起玩。\p"
	.string "他从小就体弱多病。\p"
	.string "我们打算送他到绿茵镇的亲戚家去，\p"
	.string "那里的空气比这儿洁净。\p"
	.string "什么？满充在哪儿？我们家满充已经\n"
	.string "出发了。\p"
	.string "不知道现在该到哪儿了呢？$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "不知道我家满充在做什么？$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}！原谅\n"
	.string "我们这样拉你过来，\p"
	.string "但是，自从我家满充去了绿茵镇之后\n"
	.string "，他的身体好多了。\p"
	.string "我们都欠你的情！\p"
	.string "满充离开镇子前，是你陪他捕捉了一\n"
	.string "只宝可梦对吗？\p"
	.string "我想那让满充非常开心。\p"
	.string "实际上，不只是满充，作为父亲的我\n"
	.string "也很开心，\p"
	.string "很开心他能交上你这样的好朋友。\p"
	.string "这点礼物虽然不算什么但还是请你收\n"
	.string "下。$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "如果你的宝可梦会冲浪，你就可以去\n"
	.string "很多地方了。$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "满充很快就会回家了，真想快点见到\n"
	.string "他。$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "哦？你在彩悠市遇到了满充？\p"
	.string "哎，{PLAYER}{KUN}，\n"
	.string "别闹了。\p"
	.string "他可能健康多了，但它不可能一个人\n"
	.string "到那么远的地方去。$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "满充非常兴奋地告诉我们他捕捉到了\n"
	.string "一只宝可梦。\p"
	.string "已经有很多年没看到过他那快乐的笑\n"
	.string "容了。$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "有件事你一定要对我丈夫保密……\p"
	.string "我们的满充没跟任何人说就离开了绿\n"
	.string "茵镇。\p"
	.string "你知道，尽管满充身体很弱，但他的\n"
	.string "意志很坚强。\p"
	.string "我知道他总有一天会平安无事地回家\n"
	.string "的！$"

