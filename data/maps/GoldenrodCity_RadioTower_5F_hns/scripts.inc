GoldenrodCity_RadioTower_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2_HNS, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "你、你是来救我的吗？$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "你以为我会这么说吗？\p"
	.string "大错特错！我是个冒牌货！\p"
	.string "我假扮成真正的台长，就是为了给占\n"
	.string "领这里做准备。\p"
	.string "想知道我们把真正的台长藏到哪里去\n"
	.string "了吗？\p"
	.string "好啊，告诉你也行。前提是你能打赢\n"
	.string "我！$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "好吧好吧。我告诉你他在哪。$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "老大把台长关进了地下仓库。\p"
	.string "就在地下通道最深处。\p"
	.string "我人好，通往地下仓库的地下钥匙就\n"
	.string "给你吧。\p"
	.string "不过，我看你也走不到那里。$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "首领把台长藏在地下仓库里了。\p"
	.string "就在地下通路的最深处。\p"
	.string "你可以用地下钥匙进入地下仓库。\p"
	.string "但我觉得你根本走不到那里。$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2_HNS GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER_HNS, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "还记得卡吉镇的秘密基地吗？\p"
	.string "虽然我被老大痛骂了一顿，但我变强\n"
	.string "了。\p"
	.string "上次是我输了，但这次可不会了！$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "怎么会这样！\p"
	.string "明明拼尽了全力，居然还是输了..\n"
	.string "....\p"
	.string "坂木老大，对不起……$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "你是叫{PLAYER}对吧？\p"
	.string "像你这种小毛孩，是不会理解火箭队\n"
	.string "的伟大的。\p"
	.string "真遗憾，我其实挺欣赏你的实力的。$"

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "哦？你居然能来到这里？\p"
	.string "看来你是个相当有本事的训练家啊。\p"
	.string "我们打算占领这座广播电台，向全世\n"
	.string "界宣告我们的复活。\p"
	.string "这样一来，独自修行的坂木老大就一\n"
	.string "定会回到我们身边。\p"
	.string "我们将重拾往昔的荣耀……\p"
	.string "我绝不会允许你妨碍我们周密的计划\n"
	.string "！$"

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "不！坂木老大，请原谅我！$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "怎么会这样……？\p"
	.string "我们的梦想化为泡影了。\p"
	.string "看来我终究还是难堪大任。\p"
	.string "就像当年的坂木老大一样，今天我就\n"
	.string "在此解散火箭队。\p"
	.string "永别了。$"

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "局长：{PLAYER}，太谢谢你\n"
	.string "了！\p"
	.string "你的英勇之举拯救了全国的宝可梦。\p"
	.string "虽然不成敬意，但这件礼物请你收下\n"
	.string "吧。$"

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "以前在满金市的这里，曾经立着一座\n"
	.string "塔。\p"
	.string "不过由于年久失修，摇摇欲坠，\p"
	.string "我们便把它拆除，建成了这座广播塔\n"
	.string "。\p"
	.string "这片羽毛是在施工时挖出来的。\p"
	.string "听说在很久以前，满金市生活着各种\n"
	.string "各样的宝可梦。\p"
	.string "也许……\p"
	.string "这片羽毛和缘朱市的铃铛塔有着什么\n"
	.string "关联也说不定……\p"
	.string "好了，我也该回局长室了。$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "以前在满金市的这里，曾经立着一座\n"
	.string "塔。\p"
	.string "不过由于年久失修，摇摇欲坠，\p"
	.string "我们便把它拆除，建成了这座广播塔\n"
	.string "。\p"
	.string "这片羽毛是在施工时挖出来的。\p"
	.string "听说在很久以前，满金市生活着各种\n"
	.string "各样的宝可梦。\p"
	.string "也许……\p"
	.string "这片羽毛和湛蓝市附近的漩涡列岛有\n"
	.string "着什么关联也说不定……\p"
	.string "好了，我也该回局长室了。$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "啊！\p"
	.string "想起来了……\p"
	.string "我给你的那片羽毛……似乎\n"
	.string "和传说的宝可梦有关。\p"
	.string "但是！光凭那片羽毛，传说的宝可梦\n"
	.string "是不会现身的……\p"
	.string "好像还需要别的什么东西……\n"
	.string ".大概是这样吧。\p"
	.string "到底是什么来着呢……\p"
	.string "我想不起来了。$"

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "你在期待什么吗？这就是所谓的“击\n"
	.string "掌奇袭”啦。\p"
	.string "这次我真的得回局长室了。拜拜啦！$"

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "局长：你好呀，{PLAYER}！\p"
	.string "不瞒你说，我非常喜爱宝可梦。\p"
	.string "建起这座广播塔，就是为了能表达我\n"
	.string "对宝可梦的爱。\p"
	.string "要是大家都能喜欢我们的节目就好了\n"
	.string "。$"

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "本：你听过我们的音乐节目吗？$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "5F 局长室$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5F 第1录音棚$"
