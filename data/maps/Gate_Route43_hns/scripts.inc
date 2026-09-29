Gate_Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Gate_Route43_Rocket_OnFrame
	.byte 0

Gate_Route43_Rocket_OnFrame::
	map_script_2 VAR_TEMP_0, 0, Gate_Route43_RocketChecker
	.2byte 0

Gate_Route43_RocketChecker::
	setvar VAR_TEMP_0, 1
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 1, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 2, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 4, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 5, Gate_Route43_Rocket_EventScript_Shakedown
	end

Gate_Route43_Rocket_EventScript_Shakedown::
	lock
	showmoneybox 0, 0
	msgbox Gate_Route43_Rocket_Text_TollFee, MSGBOX_DEFAULT
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_ShakedownBroke
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_ShakedownBroke::
	checkmoney 1
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_KickOut
	msgbox Gate_Route43_Rocket_Text_AllYouGot, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_KickOut::
	msgbox Gate_Route43_Rocket_Text_KickOut, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_Policeman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_FROM_MAHOGANY_COP, Gate_Route43_Rocket_EventScript_PolicemanAfter
	msgbox Route43Gate_Text_OfficerFoundTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	setflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_PolicemanAfter::
	msgbox Gate_Route43_Text_OfficerAvoidGrass, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_Rockets::
	msgbox Gate_Route43_Rocket_Text_MakingABundle, MSGBOX_NPC
	end

Gate_Route43_Rocket_Text_TollFee:
    .string "站住，小鬼！\p"
    .string "想从这里过，得交500日元的过路\n"
    .string "费！$"

Gate_Route43_Rocket_Text_ThankYou:
    .string "多谢惠顾啦！$"

Gate_Route43_Rocket_Text_AllYouGot:
    .string "那就把身上所有的钱都交出来吧。$"

Gate_Route43_Rocket_Text_KickOut:
	.string "哇哦！\p"
	.string "你居然身无分文啊！\p"
	.string "我都忍不住有点同情你了。\p"
	.string "行吧，放你过去……\p"
	.string "可千万别告诉另一个守卫，知道了吗\n"
	.string "？$"

Gate_Route43_Rocket_Text_MakingABundle:
    .string "嘿嘿嘿，这次可赚大发了。\p"
    .string "大家都想去愤怒之湖看热闹呢。$"

Route43Gate_Text_OfficerFoundTM:
    .string "我被那帮黑衣暴徒赶出了值班室。\p"
    .string "他们把这东西给落下了。\p"
    .string "看着怪渗人的。你能把它带走吗？$"

Gate_Route43_Text_ReceivedTM30:
    .string "{PLAYER}获得了招式学习器\n"
    .string "36。$"

Gate_Route43_Text_OfficerAvoidGrass:
    .string "走这个关卡就可以避免穿过草丛。$"
