FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "索蓝斯博士：唉……真后悔被熔岩队骗\n"
	.string "着说出了陨石的下落……\p"
	.string "流星瀑布的陨石……再也不会属于我\n"
	.string "了……$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "啊！咦？\p"
	.string "那个东西……\p"
	.string "难道是？\p"
	.string "那是熔岩队从流星瀑布抢走的陨石\n"
	.string "吗？\p"
	.string "拜托给我好吗？\p"
	.string "我不会白要的，用这个招式学习器跟\n"
	.string "你换好吗？$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "索蓝斯博士：这个招式学习器表示我\n"
	.string "的谢意。请好好使用吧！$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "索蓝斯博士：啊，简直不敢相信，真\n"
	.string "是太棒了！\p"
	.string "这对我的研究会有巨大帮助的！$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "索蓝斯博士：哎，可是……太让人绝望\n"
	.string "了……$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "索蓝斯博士：拜托了！把那个陨石给\n"
	.string "我好吗？\p"
	.string "我不会白要的，用这个招式学习器跟\n"
	.string "你换好吗？$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "索蓝斯博士和一些熔岩队的人去了114号\n"
	.string "道路上的流星瀑布。$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "可怜的索蓝斯博士……他一回来就很沮\n"
	.string "丧……真为他难过。$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "看看索蓝斯博士……他完全高兴起来\n"
	.string "了！那样子真可爱。$"

