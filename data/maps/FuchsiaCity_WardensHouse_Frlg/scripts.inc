FuchsiaCity_WardensHouse_Frlg_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	call EventScript_RestorePrevTextColor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksMale
	call_if_eq VAR_RESULT, FEMALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale
	giveitem_msg FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden, ITEM_HM04
	setflag FLAG_GOT_HM04
	removeitem ITEM_GOLD_TEETH
	release
	end

FuchsiaCity_WardensHouse_EventScript_WardenThanksMale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
	.string "园长：哇伊嘿咻乎嘿\p"
	.string "乎哈希嘻嘿哇！哈希嘻呼！$"

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
	.string "啊活货嚯惑伙！诶夫咦嘿嗨活！$"

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
	.string "哈？他呵哈呵呵呵呵呵哈哈哈！$"

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
	.string "{PLAYER}将金假牙交给了园\n"
	.string "长。$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
	.string "园长戴上了他的假牙！$"

FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething::
	.string "园长：谢谢你，小朋友！你真是我的\n"
	.string "救命恩人！\p"
	.string "所有人都听不懂我说的话，一个都没\n"
	.string "有！\p"
	.string "我甚至都没脸去见我的那些员工了。\p"
	.string "让我给你点东西做为感谢吧。$"

FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething::
	.string "园长：谢谢你，小姑娘！你真是我的\n"
	.string "救命恩人！\p"
	.string "没有任何人听得懂我说的话，我是说\n"
	.string "，一个也没有！\p"
	.string "我甚至都没脸去见我的那些员工了。\p"
	.string "让我给你点东西做为感谢吧。$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
	.string "{PLAYER}从园长那里得到了\n"
	.string "HM04。$"

FuchsiaCity_WardensHouse_Text_ExplainStrength::
	.string "园长：通过HM04可以学会怪力。\p"
	.string "能让你在战斗以外的时候用宝可梦推\n"
	.string "动大石头。\p"
	.string "喔，对了你找到野生原野区里的神秘\n"
	.string "小屋了吗？$"

@ Unused
FuchsiaCity_WardensHouse_Text_YouHaveTooMuchStuff::
	.string "なんや　にもつ\n"
	.string "いっぱいやんけ！$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
	.string "宝可梦的照片和化石被陈列着。$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
	.string "陈列着古代宝可梦货物。$"

