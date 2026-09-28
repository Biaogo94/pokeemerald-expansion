Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "你是我所见过的训练家中指挥宝可梦\n"
	.string "最纯熟的。\p"
	.string "但是，我要告诉你——我的儿子比你\n"
	.string "还要厉害。\p"
	.string "他甚至成为了宝可梦联盟挑战者，你\n"
	.string "知道吗。$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "我们使用强制锻炼器有效提高宝可梦\n"
	.string "的力量。\p"
	.string "你战胜了我们所有人，我不知道你是\n"
	.string "否需要这个请收下我们给你的强制锻\l"
	.string "炼器。$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "当进行宝可梦对战时，我们变得很激\n"
	.string "情。$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "妈妈比爸爸厉害。\p"
	.string "我比妈妈厉害。\p"
	.string "奶奶比我厉害！\p"
	.string "但是我的哥哥比奶奶还要厉害哟。$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "显然你很厉害。\p"
	.string "但是如果你和我的孙子对战你一定会\n"
	.string "输到哭泣的。\p"
	.string "他比我们所知道的训练家都要厉害。\p"
	.string "他现在一定在挑战联盟冠军吧。\p"
	.string "你会认识我的孙子的，他应该已经是\n"
	.string "冠军了！$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "我的孙子现在一定在挑战联盟冠军。\p"
	.string "你会认识我的孙子的，他应该已经是\n"
	.string "冠军了！$"

