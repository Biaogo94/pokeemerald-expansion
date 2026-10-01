FuchsiaCity_SafariZoneEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZoneEntrance_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_SafariZoneEntrance_OnTransition
	.byte 0

FuchsiaCity_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

FuchsiaCity_SafariZoneEntrance_OnTransition::
	call_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_FirstTime
	end

FuchsiaCity_SafariZoneEntrance_FirstTime::
	setobjectxyperm LOCALID_SAFARIZONEFUCHSIA_STEVEN, 4, 10
	setobjectmovementtype LOCALID_SAFARIZONEFUCHSIA_STEVEN, MOVEMENT_TYPE_FACE_LEFT
	end

FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	release
	end
 
FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 0
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN

	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase

	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	return

FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase:
	.string "哦，对了，你可能会需要这个。$"

FuchsiaCity_SafariZoneEntrance_Steven::
	lock
	faceplayer
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade
	goto_if_set FLAG_IS_KANTO_CHAMPION, FuchsiaCity_SafariZoneEntrance_StevenChamp
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Steven, MSGBOX_NPC
	release
	end

FuchsiaCity_SafariZoneEntrance_StevenChamp::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChamp, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenChamp:
	.string "哎呀，你好，{PLAYER}。或\n"
	.string "者说，该叫你关都冠军呢？\p"
	.string "其实在之前一段时间，我曾是丰缘地\n"
	.string "区的冠军哦。\p"
	.string "所以欢迎加入冠军的行列，\n"
	.string "{PLAYER}。\p"
	.string "正好，拿着这个吧。就当作是我的见\n"
	.string "面礼好了。$"

FuchsiaCity_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase
	call FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 4, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft
	call_if_eq VAR_TEMP_0, 6, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	setflag FLAG_IN_KANTO_SAFARI_ZONE
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 1
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome:
	.string "又见面了，{PLAYER}！\p"
	.string "欢迎来到德文原野区！\p"
	.string "这个特别设计的原野区拥有4种不同\n"
	.string "的生态环境，用以吸引并容纳来自丰\l"
	.string "缘地区的外来物种。\p"
	.string "我们鼓励训练家们尽可能多地捕捉它\n"
	.string "们，以此安全地将它们移出自然环\l"
	.string "境。\p"
	.string "你在这里会发现非常罕见的宝可梦。\n"
	.string "尤其是当你提升了原野区等级之后。\p"
	.string "随时都可以找这里的接待员来提升你\n"
	.string "的原野区等级。$"

FuchsiaCity_SafariZoneEntrance_UpgradeGuy::
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 1, FuchsiaCity_SafariZoneEntrance_UpgradeGuy1
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 2, FuchsiaCity_SafariZoneEntrance_UpgradeGuy2
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 3, FuchsiaCity_SafariZoneEntrance_UpgradeGuy3
	msgbox FuchsiaCity_SafariZoneEntrance_Text_MaxLevel, MSGBOX_NPC
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy1::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 200000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 200000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 2
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy2::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 300000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 300000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 3
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy3::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 400000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 400000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 4
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_Text_Steven:
	.string "哎呀，你好，{PLAYER}。\p"
	.string "原野区玩得还开心吗？\p"
	.string "你最近有没有见到什么罕见的石头？$"

FuchsiaCity_SafariZoneEntrance_Text_Level1:
	.string "你好，{PLAYER}，你想要将\n"
	.string "原野区等级提升到2级吗？费用是¥20,000。$"

FuchsiaCity_SafariZoneEntrance_Text_Level2:
	.string "你好，{PLAYER}，你想要将\n"
	.string "原野区等级提升到3级吗？费用是¥30,000。$"

FuchsiaCity_SafariZoneEntrance_Text_Level3:
	.string "你好，{PLAYER}，你想要将\n"
	.string "原野区等级提升到4级吗？费用是¥40,000。$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined:
	.string "哎呀，那可真是太遗憾了…….$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted:
	.string "祝您尽情享受原野区的高级会员体\n"
	.string "验！$"

FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade::
	goto_if_set FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED, FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted
	ingame_trade INGAME_TRADE_BELDUM, FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon, FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare
	setflag FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade:
	.string "那个，{PLAYER}......这只\n"
	.string "铁哑铃我培育有一段时间了。\p"
	.string "但我认为跟着像你这样的训练家，它\n"
	.string "能得到更好的成长。\p"
	.string "你愿意用你的\n"
	.string "{STR_VAR_1}来交换我的\l"
	.string "{STR_VAR_2}吗？$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare:
	.string "太好了！请好好照顾阿铁哦。$"

FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade:
	.string "没关系的。如果你改变了心意，随时\n"
	.string "都可以来找我。$"

FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon:
	.string "唔，这不是{STR_VAR_1}\n"
	.string "啊。这和我想要的有点不太一样呢。$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted:
	.string "阿铁过得还好吗？铁哑铃真是一种迷\n"
	.string "人的宝可梦。\p"
	.string "它们之间是通过磁脉冲来进行相互交\n"
	.string "流的。$"

FuchsiaCity_SafariZoneEntrance_Text_MaxLevel:
	.string "你好，{PLAYER}，感谢您一\n"
	.string "直作为浅红原野区的高级会员支持我\l"
	.string "们。$"
