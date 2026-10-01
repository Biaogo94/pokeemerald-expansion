LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "小遥：{PLAYER}\n"
	.string "{KUN}！好久不见！\p"
	.string "哦？看来我去温泉的时候你已经拿到\n"
	.string "釜炎镇道馆徽章了。\p"
	.string "你一定得到了不少优秀的宝可梦……\n"
	.string "不，我想还是因为你培育得好。\p"
	.string "我想我可以把这个给你。$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "小遥：有这个GOGO护目镜的话，就能\n"
	.string "穿越111号道路上的沙漠了。\p"
	.string "不过，{PLAYER}{KUN}\n"
	.string "居然在挑战道馆……\p"
	.string "是不想输给我吧？你为此真的很努力\n"
	.string "呢！\p"
	.string "{PLAYER}{KUN}，我现\n"
	.string "在打算去橙华市道馆挑战你爸爸了！\p"
	.string "回头见！$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "小悠：{PLAYER}，好久不见\n"
	.string "了，还顺利吗？\p"
	.string "唔……你收集了不少徽章了啊。\p"
	.string "那好，这个也给你吧。$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "小悠：如果要去111号道路上的沙漠\n"
	.string "就带上它吧。\p"
	.string "那里应该也有一些沙漠特有的宝可\n"
	.string "梦，你可以去找找看。\p"
	.string "至于我……我打算去挑战橙华市的道馆\n"
	.string "馆主千里。\p"
	.string "{PLAYER}，你爸爸和你不一\n"
	.string "样，他看上去相当厉害！\p"
	.string "再见啦！$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "我这儿有个蛋。\p"
	.string "我本来指望用温泉边温暖的沙子盖起\n"
	.string "它来会孵化的，但看来这样还不够……\p"
	.string "听说最好能让它跟宝可梦在一起。\p"
	.string "你是个训练家对吗？而且你的宝可梦\n"
	.string "看上去活力十足。\p"
	.string "怎么样？你愿意带上这个蛋孵化它\n"
	.string "吗？$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "好！希望你能带上这个蛋一起旅行！$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER}得到蛋。$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "嗯？你带了太多宝可梦，没法再带上\n"
	.string "这个蛋了……$"

LavaridgeTown_Text_AsYouWishThen:
	.string "那么请便吧……\p"
	.string "如果你改变主意了，再来这儿找我。$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "有时宝可梦培育屋里会发现蛋，\p"
	.string "至少传闻中是这样。$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "我们不断地汲取热水，但温泉却从未\n"
	.string "干涸，\p"
	.string "很神奇不是吗？\p"
	.string "这些温泉都很接近活火山，地下水脉\n"
	.string "被岩浆加热，从地表冒出来，就形成\l"
	.string "了温泉。$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "埋在沙里的感觉……哎……\p"
	.string "说不出的温暖美妙……\p"
	.string "呃？呀！啊噢！\p"
	.string "有宝可梦咬了我！$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "你喜欢温泉吗？\p"
	.string "对像你这样的年轻人来说还真是少\n"
	.string "见。$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "我每天都泡温泉。\p"
	.string "我想成为像亚莎那样又美丽又强大的\n"
	.string "道馆馆主。$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "如果把宝可梦放进温泉，它就会变得\n"
	.string "很奇怪。\p"
	.string "哈，有时候可能变成电气浴，或者泡\n"
	.string "沫浴，甚至岩浆浴……$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "据说温泉可以放松紧张的神经，减轻\n"
	.string "身体的疲劳，解决感情问题，还能增\l"
	.string "加财运……$"

LavaridgeTown_Text_TownSign:
	.string "釜炎镇\p"
	.string "“宝可梦中心温泉放松身心的绝佳去\n"
	.string "处！”$"

LavaridgeTown_Text_GymSign:
	.string "釜炎镇宝可梦道馆馆主：亚莎“热情\n"
	.string "似火的女性！”$"

LavaridgeTown_Text_HerbShopSign:
	.string "宝可梦中药店“良药苦口。”$"

