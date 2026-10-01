SafariZoneGate_SafariZoneEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZoneGate_SafariZoneEntrance_OnFrame
	.byte 0

SafariZoneGate_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 3, SafariZoneGate_SafariZoneEntrance_MeetBaoba
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	warp MAP_SAFARI_ZONE_ENTERANCE_HNS, 0
	delay 120
	end

SafariZoneGate_SafariZoneEntrance_MeetBaoba::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEGATE_BAOBA
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEGATE_BAOBA
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome, MSGBOX_DEFAULT
	closemessage
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_SAFARI_ZONE_GATE_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Baoba::
	lock
	faceplayer
	goto_if_eq VAR_BAOBA_QUEST_STATE, 1, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach
	goto_if_eq VAR_BAOBA_QUEST_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush
	goto_if_eq VAR_BAOBA_QUEST_STATE, 3, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain
	goto_if_eq VAR_BAOBA_QUEST_STATE, 4, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave
	goto_if_ge VAR_BAOBA_QUEST_STATE, 5, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Baoba, MSGBOX_DEFAULT 
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 1
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 200000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 2
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 2
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 300000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 3
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 3
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 4
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 20
	playse SE_SHOP
	updatemoneybox
	delay 20
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 5
	release
	end

SafarioneEntrance_EventScript_BaobaWrong::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined:
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDone, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Test::
	givemon SPECIES_BELDUM, 5
	givemon SPECIES_CASTFORM, 5
	givemon SPECIES_MEDICHAM, 5
	givemon SPECIES_BAGON, 5
	end

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone:
	.string "谢谢你，{PLAYER}！来，收\n"
	.string "下这笔钱去提升你的狩猎地带等级，\l"
	.string "接下来再去灌木区抓一只稀有的宝可\l"
	.string "梦给我瞧瞧吧！$"
	
SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone:
	.string "谢谢你，{PLAYER}！来，收\n"
	.string "下这笔钱去提升你的狩猎地带等级，\l"
	.string "接下来再去山岳区抓一只稀有的宝可\l"
	.string "梦给我瞧瞧吧！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone:
	.string "谢谢你，{PLAYER}！来，收\n"
	.string "下这笔钱去提升你的狩猎地带等级，\l"
	.string "接下来再去洞窟区抓一只稀有的宝可\l"
	.string "梦给我瞧瞧吧！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone:
	.string "谢谢你，{PLAYER}！我想看\n"
	.string "的全都看到了。\p"
	.string "既然知道了得文公司的打算，我就能\n"
	.string "让我的狩猎地带保持竞争力了。来，\l"
	.string "拿上这个当作酬谢吧。$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong:
	.string "这怎么可能！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach:
	.string "啊，{PLAYER}！\p"
	.string "你从浅红市狩猎地带的沙滩区带回稀\n"
	.string "有的宝可梦给我看了吗？$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush:
	.string "啊，{PLAYER}！\p"
	.string "你从浅红市狩猎地带的灌木区带回稀\n"
	.string "有的宝可梦给我看了吗？$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain:
	.string "啊，{PLAYER}！\p"
	.string "你从浅红市狩猎地带的山岳区带回稀\n"
	.string "有的宝可梦给我看了吗？$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaCave:
	.string "啊，{PLAYER}！\p"
	.string "你从浅红市狩猎地带的洞窟区带回稀\n"
	.string "有的宝可梦给我看了吗？$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined:
	.string "我现在该怎么办？我们根本赶不上得\n"
	.string "文公司啊！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaLastMon:
	.string "我不能拿走你最后一只宝可梦！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaDone:
	.string "啊，{PLAYER}！\p"
	.string "多亏了你，狩猎地带现在蒸蒸日上！\p"
	.string "也许我该任命你为狩猎地带的园长"
	.string "。.....\p"
	.string "不，那也太荒唐了。哈哈哈哈！$"

SafariZoneGate_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase
	call SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney
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
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_ENTERANCE_HNS, 0
	waitstate
	end

SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Chart1::
	lock
	helpwindow HELP_POKEBLOCK_WINDOW
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Chart2::
	lock
	helpwindow HELP_GOLD_POKEBLOCK_WINDOW
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Boy::
	lock
	faceplayer
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BoyGiveExtraPokeblockCase
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BoyGiveExtraPokeblockCase::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BoyGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome:
	.string "嗨，{PLAYER}！我等你很久\n"
	.string "了。你觉得这里怎么样？\p"
	.string "顺便说一句，这是个全新的狩猎地\n"
	.string "带......\p"
	.string "而且还在扩建中呢！\p"
	.string "目前我们已经开放了两个区域，还有\n"
	.string "另外4个区域正在筹备中！\p"
	.string "尽情享受狩猎地带吧！等其他区域准\n"
	.string "备就绪，我会给你打电话的！$"

SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks:
	.string "哎呀！我差点忘了。\p"
	.string "宝可方块是我这狩猎地带的一大特\n"
	.string "色，也是不可或缺的，所以你最好带\l"
	.string "上这个！$"

SafariZoneGate_SafariZoneEntrance_Text_Baoba:
	.string "嗨，{PLAYER}！\p"
	.string "狩猎地带玩得开心吗？$"

SafariZoneGate_SafariZoneEntrance_Text_Boy:
	.string "你知道宝可方块喂食器吗？\p"
	.string "只要把宝可方块放进喂食器里，就能\n"
	.string "引出拥有隐藏特性的宝可梦哦！\p"
	.string "宝可方块的种类还会影响宝可梦的性\n"
	.string "格。\p"
	.string "更棒的是，根据使用的宝可方块种\n"
	.string "类，还能吸引到满个体值的宝可梦\l"
	.string "呢！\p"
	.string "墙上的图表写满了详细信息。$"

SafariZoneGate_SafariZoneEntrance_Text_BoyGiveCase:
	.string "来，这个你好像用得上。$"

SafariZoneGate_SafariZoneEntrance_Text_Engineer:
	.string "训练家，抱歉啦！这里还在施工中\n"
	.string "呢。过一阵子再来看看吧！$"
