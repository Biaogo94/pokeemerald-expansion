Route13_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Route13_hns_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route13_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

Route13_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Route13_OnTransition
	return

Route13_hns_MapScripts_MAP_SCRIPT_ON_RESUME:
	call SetTimeEncounters
	return

Route13_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_TRAVEL, 2, Route13_GetOffBoat
	.2byte 0

Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_ALOLA_TRAVEL, 2, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	applymovement Route13_Alola_Captain, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	applymovement LOCALID_PLAYER, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return


Route13_OnTransition:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 77, Route13_OnTransitionBoat
	callnative SetTimeBasedEncounters
	end

Route13_OnTransitionBoat::
	@addobject LOCALID_ROUTE13_BOAT
	clearflag FLAG_HIDE_ROUTE13_BOAT
	setobjectxyperm LOCALID_ROUTE13_BOAT, 78, 28
	return

Route13_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX_HNS, Route13_Text_PokefanmAlexSeen, Route13_Text_PokefanmAlexBeaten, Route13_EventScript_RegisterAlex
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_RematchAlex
	msgbox Route13_Text_PokefanmAlexAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_RegisterAlex::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route13_Text_AlexRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALEX_HNS
	release
	end

Route13_EventScript_RematchAlex::
	trainerbattle_rematch TRAINER_ALEX_HNS, Route13_Text_AlexRematchIntro, Route13_Text_AlexRematchDefeat
	msgbox Route13_Text_AlexPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_ALEX_2_HNS, Route13_EventScript_RematchAlexTryGiveItem
	end

Route13_EventScript_RematchAlexTryGiveItem::
	checkitem ITEM_RED_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_RED_SHARD
	closemessage
	end

Route13_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA_HNS, Route13_Text_PokefanmJoshuaSeen, Route13_Text_PokefanmJoshuaBeaten
	msgbox Route13_Text_PokefanmJoshuaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY_HNS, Route13_Text_BirdKeeperPerrySeen, Route13_Text_BirdKeeperPerryBeaten
	msgbox Route13_Text_BirdKeeperPerryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Bret::
	trainerbattle_single TRAINER_BRET_HNS, Route13_Text_BirdKeeperBretSeen, Route13_Text_BirdKeeperBretBeaten
	msgbox Route13_Text_BirdKeeperBretAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY_HNS, Route13_Text_HikerKennySeen, Route13_Text_HikerKennyBeaten, Route13_EventScript_RegisterKenny
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_RematchKenny
	msgbox Route13_Text_HikerKennyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_RegisterKenny::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route13_Text_KennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENNY_HNS
	release
	end

Route13_EventScript_RematchKenny::
	trainerbattle_rematch TRAINER_KENNY_HNS, Route13_Text_KennyRematchIntro, Route13_Text_KennyRematchDefeat
	msgbox Route13_Text_KennyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KENNY_2_HNS, Route13_EventScript_RematchKennyTryGiveItem
	end

Route13_EventScript_RematchKennyTryGiveItem::
	checkitem ITEM_TM_STONE_EDGE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_STONE_EDGE
	closemessage
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_Text_PokefanmAlexSeen:
	.string "拜倒在我高贵的宝可梦面前吧！$"

Route13_Text_PokefanmAlexBeaten:
	.string "怎......怎么敢对王室无礼！$"

Route13_Text_PokefanmAlexAfterBattle:
	.string "难道不是每个人都梦想着有朝一日成\n"
	.string "为国王吗？$"

Route13_Text_AlexRegister:
	.string "虽然你不是王室，但实力确实很强。\n"
	.string "能把电话号码告诉我吗？$"

Route13_Text_AlexRematchIntro:
	.string "我的宫廷里又添了新的骑士！来对战\n"
	.string "吧！$"

Route13_Text_AlexRematchDefeat:
	.string "又被拉下王座了......$"

Route13_Text_AlexPostRematch:
	.string "或许我终究不过是一枚小卒罢了。$"

Route13_Text_PokefanmJoshuaSeen:
	.string "嘻嘻嘻！想挑战一下我的皮卡丘军团\n"
	.string "吗？$"

Route13_Text_PokefanmJoshuaBeaten:
	.string "皮--皮卡丘！$"

Route13_Text_PokefanmJoshuaAfterBattle:
	.string "虽然你的宝可梦看起来很多，但还是\n"
	.string "皮卡丘最棒了！$"

Route13_Text_BirdKeeperPerrySeen:
	.string "速度可是鸟宝可梦的关键属性！$"

Route13_Text_BirdKeeperPerryBeaten:
	.string "竟然在速度上输给了你......$"

Route13_Text_BirdKeeperPerryAfterBattle:
	.string "你的宝可梦训练得真出色。$"

Route13_Text_BirdKeeperBretSeen:
	.string "看看我的宝可梦吧。瞧瞧它们这鲜艳\n"
	.string "的色泽和美丽的羽毛！$"

Route13_Text_BirdKeeperBretBeaten:
	.string "可恶！还差得远呢！$"

Route13_Text_BirdKeeperBretAfterBattle:
	.string "只要好好梳理毛发，宝可梦就会很开\n"
	.string "心哦。$"

Route13_Text_HikerKennySeen:
	.string "我该去岩山隧道抓一只大岩蛇才对。$"

Route13_Text_HikerKennyBeaten:
	.string "我输了......$"

Route13_Text_HikerKennyAfterBattle:
	.string "地质地貌看起来毫无变化，\p"
	.string "但实际上，一直都在一点一点地改变\n"
	.string "呢。$"

Route13_Text_KennyRegister:
	.string "宝可梦或许也会随着岁月改变吧。改\n"
	.string "天再来对战吧！$"

Route13_Text_KennyRematchIntro:
	.string "我从地质学中领悟到了新战术！上吧\n"
	.string "！$"

Route13_Text_KennyRematchDefeat:
	.string "还是差了点吗......$"

Route13_Text_KennyPostRematch:
	.string "宝可梦的力量就如同流水侵蚀一般。\n"
	.string "我们绝不会放弃！$"

Route13_Text_TrainerTips:
	.string "训练家指南\p"
	.string "快看！就在路牌的左边。$"

Route13_Text_Sign:
	.string "13号道路\p"
	.string "北：静止桥$"

Route13_Text_DirectionsSign:
	.string "北：紫苑镇\p"
	.string "西：浅红市$"

Route13_GetOffBoat::
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 77
	goto_if_ne Route13_GetOffBoat_2
	compare VAR_TEMP_1, 26
	goto_if_ne Route13_GetOffBoat_2
	delay 30
	applymovement Route13_Alola_Captain, Route13_GetOffBoat_Movement_0
	applymovement LOCALID_PLAYER, Route13_GetOffBoat_Movement_1
	waitmovement 0
	msgbox Route13_GetOffBoat_Text_0, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_TRAVEL, 0
	applymovement LOCALID_ROUTE13_BOAT, Route13_TravelToAlola_Movement_2
	waitmovement 0
	setobjectxyperm LOCALID_ROUTE13_BOAT, 89, 28
	removeobject LOCALID_ROUTE13_BOAT
	applymovement LOCALID_PLAYER, Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	waitmovement 0
	release
	end

Route13_GetOffBoat_2:
	setvar VAR_ALOLA_TRAVEL, 0
	release
	end


Route13_TravelToAlola::
	lock
	faceplayer
	checkitem ITEM_STRANGE_SOUVENIR
	compare VAR_RESULT, 0
	goto_if_ne Route13_TravelToAlola_1
	msgbox Route13_TravelToAlola_Text_4, MSGBOX_AUTOCLOSE
	release
	end

Route13_TravelToAlola_1:
	goto_if_unset FLAG_VISITED_ALOLA, Route13_TravelToAlola_4
	msgbox Route13_TravelToAlola_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route13_TravelToAlola_10
	msgbox Route13_TravelToAlola_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Route13_TravelToAlola_4:
	msgbox Route13_TravelToAlola_Text_0, MSGBOX_DEFAULT
	closemessage
	helpwindow HELP_ALOLA_WINDOW
	msgbox Route13_TravelToAlola_Text_0_5, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route13_TravelToAlola_7
	msgbox Route13_TravelToAlola_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Route13_TravelToAlola_7:
	msgbox Route13_TravelToAlola_Text_1, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_FACING, DIR_SOUTH, Route13_TravelToAlola_14
Route13_TravelToAlola_13:
	addobject LOCALID_ROUTE13_BOAT
	clearflag FLAG_HIDE_ROUTE13_BOAT
	applymovement LOCALID_ROUTE13_BOAT, Route13_Movement_BoatArrive
	waitmovement 0
	applymovement Route13_Alola_Captain, Route13_TravelToAlola_Movement_1
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_1
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_ROUTE13_HNS
	hideobjectat Route13_Alola_Captain, MAP_ROUTE13_HNS
	applymovement OBJ_EVENT_ID_CAMERA, Route13_TravelToAlola_Movement_1
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN

	playse SE_M_SURF
	applymovement LOCALID_ROUTE13_BOAT, Route13_TravelToAlola_Movement_2
	setvar VAR_ALOLA_TRAVEL, 1
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_HIDE_AKALA_TOTEM
	setflag FLAG_HIDE_ULAULA_TOTEM
	setflag FLAG_HIDE_PONI_TOTEM
	setflag FLAG_HIDE_SAMSONOAK_INTRO
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_HIDE_TAPU_LELE
	setflag FLAG_HIDE_TAPU_BULU
	setflag FLAG_HIDE_TAPU_FINI
	setflag FLAG_HIDE_FLYOVER
	setflag FLAG_HIDE_PHANT_OUTSIDE
	setflag FLAG_HIDE_PHANT_INSIDE
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE13_BOAT
	special RemoveCameraObject
	warp MAP_MELEMELE_ISLE_HNS, 25, 33
	waitstate
	end

Route13_TravelToAlola_10:
	msgbox Route13_TravelToAlola_Text_1, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_FACING, DIR_SOUTH, Route13_TravelToAlola_17
Route13_TravelToAlola_16:
	addobject LOCALID_ROUTE13_BOAT
	clearflag FLAG_HIDE_ROUTE13_BOAT
	applymovement LOCALID_ROUTE13_BOAT, Route13_Movement_BoatArrive
	waitmovement 0
	applymovement Route13_Alola_Captain, Route13_TravelToAlola_Movement_1
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_1
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_ROUTE13_HNS
	hideobjectat Route13_Alola_Captain, MAP_ROUTE13_HNS
	applymovement OBJ_EVENT_ID_CAMERA, Route13_TravelToAlola_Movement_1
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN
	waitse
	playse SE_M_SURF
	applymovement LOCALID_ROUTE13_BOAT, Route13_TravelToAlola_Movement_2
	setvar VAR_ALOLA_TRAVEL, 1
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE13_BOAT
	special RemoveCameraObject
	warp MAP_MELEMELE_ISLE_HNS, 25, 33
	waitstate
	end

Route13_TravelToAlola_14:
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_0
	waitmovement 0
	goto Route13_TravelToAlola_13

Route13_TravelToAlola_17:
	applymovement LOCALID_PLAYER, Route13_TravelToAlola_Movement_0
	waitmovement 0
	goto Route13_TravelToAlola_16


Route13_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
	face_up
	step_end

Route13_GetOffBoat_Movement_0:
	face_left
	step_end

Route13_GetOffBoat_Movement_1:
	face_right
	step_end

Route13_TravelToAlola_Movement_0:
	walk_left
	walk_down
	step_end

Route13_TravelToAlola_Movement_1:
	walk_down
	step_end

Route13_TravelToAlola_Movement_2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route13_Movement_BoatArrive:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route13_GetOffBoat_Text_0:
	.string "欢迎回到关都大陆！\p"
	.string "如果还想去阿罗拉群岛旅行，随时欢\n"
	.string "迎再来哦！$"

Route13_TravelToAlola_Text_0:
	.string "嗨，你好啊！\p"
	.string "那可真是一个奇特的纪念品。你一定\n"
	.string "是从群岛来的吧！$"
Route13_TravelToAlola_Text_0_5:
	.string "你想乘下一班船吗？马上就要启航了\n"
	.string "哦！$"

Route13_TravelToAlola_Text_1:
	.string "嗨！这就带你上船！$"

Route13_TravelToAlola_Text_2:
	.string "嗨！想启航的时候随时再来。$"

Route13_TravelToAlola_Text_3:
	.string "啊，又是你呀！你想去阿罗拉群岛吗\n"
	.string "？$"

Route13_TravelToAlola_Text_4:
	.string "嗨！这个港口只限当地居民使用。\p"
	.string "这片群岛的所有居民都会随身带着一\n"
	.string "些......\l"
	.string "{PAUSE 30}奇特的纪念品\l"
	.string "。\p"
	.string "只要看那个就能一眼认出来，我连船\n"
	.string "票都用不着查呢！$"
