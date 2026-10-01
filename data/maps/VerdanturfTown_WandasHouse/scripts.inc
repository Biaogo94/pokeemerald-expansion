VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "满充：虽然我输给了你，\n"
	.string "{PLAYER}，但我不再消沉\l"
	.string "了，\p"
	.string "因为我有了新的目标——和拉鲁拉丝一\n"
	.string "起挑战宝可梦道馆，成为一名厉害的\l"
	.string "训练家！\p"
	.string "请看着我，{PLAYER}。总有\n"
	.string "一天我会比你更强！\p"
	.string "到那时，我会再次向你挑战！$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "满充：请看着我，\n"
	.string "{PLAYER}。总有一天我会比\l"
	.string "你更强！\p"
	.string "到那时，我会再次向你挑战！$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "叔叔：哦，{PLAYER}\n"
	.string "{KUN}！满充就在隔壁。\p"
	.string "但是，孩子，有些事我想告诉你，\p"
	.string "这里的自然环境对满充的身体有好\n"
	.string "处，\p"
	.string "但让他打起精神来的并不只是环境，\n"
	.string "是宝可梦给了那孩子希望。$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "满充不在……他一个人溜了出去……$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "叔叔：真的吗？满充自己一个人去了\n"
	.string "那么远的地方……\p"
	.string "我想我该称赞他一下——不愧是我弟弟\n"
	.string "的儿子。$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "满盈：你是？哦，我知道了！\p"
	.string "你就是满充常说的\n"
	.string "{PLAYER}。\p"
	.string "我是满充的堂姐，很高兴认识你！\p"
	.string "自从满充来这儿以后，他变得活泼开\n"
	.string "朗多了。$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "满盈：别担心满充，他没事。\p"
	.string "我了解我的堂弟，而且还有宝可梦在\n"
	.string "他的身边。$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "多亏了你，我可以天天跟我的女朋友\n"
	.string "相聚了。开心吗？当然！那还用说！$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "我女儿的男友是个充满热情和决心的\n"
	.string "人，\p"
	.string "他为了见我女儿每天都不停地挖隧\n"
	.string "道。\p"
	.string "女儿有些担心，所以经常跑到隧道\n"
	.string "去。$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "太令人吃惊了，女儿的男友徒手挖开\n"
	.string "了隧道！\p"
	.string "难以置信！$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "要是满充出了什么事，我怎么该和他\n"
	.string "住在橙华市的父母交代……$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "满充去过彩悠市？\p"
	.string "他那住在橙华市的父母一定会大吃一\n"
	.string "惊的！$"

