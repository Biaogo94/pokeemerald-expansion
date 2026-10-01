PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
	.string "妈妈：……好吧。电视上说过。每一个\n"
	.string "男孩子都有离开家的那一天。\p"
	.string "对了，隔壁的大木博士正在找你呢。$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
	.string "妈妈 ……好吧。电视上说过，每一个\n"
	.string "女孩子都梦想着去旅行。\p"
	.string "对了，隔壁的大木博士正在找你呢。$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
	.string "妈妈 {PLAYER}！你应该稍\n"
	.string "微休息一下。$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
	.string "妈妈：嗯，很好！你和你的宝可梦看\n"
	.string "起来精力十足。路上小心！$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
	.string "电视上播放着一部电影。四个男孩沿\n"
	.string "着铁轨步行着开始了旅行。\p"
	.string "……我也该走了。$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
	.string "电视上播放着一部电影。一个扎着马\n"
	.string "尾的女孩沿着砖块砌成的路开始了旅\l"
	.string "行。\p"
	.string "……我也该走了。$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
	.string "哎哟，方向错了……$"
