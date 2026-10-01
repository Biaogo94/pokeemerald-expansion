GoldenrodCity_UndergroundTunnel_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end
	
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
	.string "穿黑衣服的火箭队到处乱窜……..\p"
	.string "我还纳闷发生什么事了呢。原来是你\n"
	.string "击退了火箭队？真了不起！\p"
	.string "如果是你的话，说不定能够面对传说\n"
	.string "的宝可……$"

GoldenrodCity_UndergroundTunnel_Text_Kimono2:
	.string "哈哈！没什么。我得先走了。$"

GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC_HNS, GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU_HNS, GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC_HNS, GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD_HNS, GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother2
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
    .string "欢迎光临宝可梦美容沙龙！\p"
    .string "我是理发兄弟里的弟弟，价格更实惠\n"
    .string "哦。\p"
    .string "只要¥300，我就能把你的宝可梦打扮\n"
    .string "得精神抖擞。\p"
    .string "怎么样？要试试看吗？$"

GoldenrodUnderground_Text_YoungerBrotherAskWhich:
    .string "好嘞，要给哪只宝可梦打理呢？$"

GoldenrodUnderground_Text_YoungerBrotherLookCool:
    .string "好！我会把它打扮得帅帅的！$"

GoldenrodUnderground_Text_YoungerBrotherAllDone:
    .string "好啦！大功告成！$"

GoldenrodUnderground_Text_YoungerBrotherDisappointed:
    .string "不要吗？真遗憾！$"

GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
    .string "你的钱好像不够呢。$"

GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
    .string "我一天只理一次发。\p"
    .string "不好意思，今天已经打烊啦。$"



GoldenrodUnderground_Text_OlderBrotherOffer:
    .string "欢迎光临！\p"
    .string "这里是宝可梦美容沙龙！\p"
    .string "我是理发兄弟里的哥哥，手艺更胜一\n"
    .string "筹哦。\p"
    .string "只要¥500，我就能让你的宝可梦变得\n"
    .string "漂漂亮亮。\p"
    .string "要来试一试吗？$"

GoldenrodUnderground_Text_OlderBrotherAskWhich:
    .string "要给哪只宝可梦做美容呢？$"

GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
    .string "好嘞！看我把它打扮得漂漂亮亮的！$"

GoldenrodUnderground_Text_OlderBrotherAllDone:
    .string "好啦！大功告成！$"

GoldenrodUnderground_Text_OlderBrotherThatsAShame:
    .string "这样啊？那可真遗憾！$"

GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
    .string "这点钱可不够哦。$"

GoldenrodUnderground_Text_OlderBrotherOnePerDay:
    .string "我一天只理一次发。今天已经收工\n"
    .string "啦。$"

GoldenrodUnderground_Text_SupernerdEricSeen:
    .string "我被游戏城轰出来了。\p"
    .string "因为我刚才想用宝可梦来作弊......$"

GoldenrodUnderground_Text_SupernerdEricBeaten:
    .string "……咕哝……$"

GoldenrodUnderground_Text_SupernerdEricAfterBattle:
    .string "看来还是得堂堂正正地玩啊……..$"

GoldenrodUnderground_Text_SupernerdTeruSeen:
    .string "对战时你考虑过属性克制吗？\p"
    .string "掌握了属性相克关系，对战就会轻松\n"
    .string "许多哦。$"

GoldenrodUnderground_Text_SupernerdTeruBeaten:
    .string "哎哟哟！$"

GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
    .string "我也懂宝可梦的属性克制啊。\p"
    .string "但我只培育单属性的宝可梦。$"

GoldenrodUnderground_Text_PokemaniacIssacSeen:
    .string "我的宝可梦刚理过发！\p"
    .string "让你见识见识它有多强！$"

GoldenrodUnderground_Text_PokemaniacIssacBeaten:
    .string "哎呀呀--！$"

GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
    .string "帮宝可梦理发的话，它们会变得更加\n"
    .string "亲近你哦。$"

GoldenrodUnderground_Text_PokemaniacDonaldSeen:
    .string "你身上一定带着稀有的宝可梦吧。\p"
    .string "快让我开开眼界！$"

GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
    .string "哇啊！居然输了！气死我了！$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "昨晚我在脚踏车店附近散步时，总感\n"
	.string "觉屋顶上有人在悄悄盯着我......$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
    .string "你正在收集宝可梦图鉴吗？告诉你个\n"
    .string "小道消息。\p"
    .string "33号道路上的登山男太郎是个大好\n"
    .string "人。\p"
    .string "他要是发现了稀有的宝可梦，就会打\n"
    .string "电话通知你的。$"

GoldenrodUnderground_Text_DoorsLocked:
    .string "门上着锁……$"

GoldenrodUnderground_Text_DoorIsOpen:
    .string "门已经开了。$"

GoldenrodUnderground_Text_KeyOpenedDoor:
    .string "用地下钥匙打开了门。$"

GoldenrodUnderground_Text_NoEntry:
    .string "此处禁止通行$"
