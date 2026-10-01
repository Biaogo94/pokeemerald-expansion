MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "不！熔岩队的家伙们赶在我们前头\n"
	.string "了！\p"
	.string "我们不能落后！$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "我还以为是熔岩队的人折回来找事……$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "哼，算你厉害……可我们人多势众！$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "哈！你来得真不巧！\p"
	.string "要是早点来，你只要对付熔岩队那群\n"
	.string "软脚虾就行了！\p"
	.string "但现在，你遇到的可是我们精英部\n"
	.string "队！$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "呃……我应该等你先对付熔岩队的……$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "你明明什么也不知道！为什么总是要\n"
	.string "来阻挠我们？$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "你……我们在烟囱山见过你。\p"
	.string "你不属于任何一个组织，那你为什么\n"
	.string "会在这里？$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "如果你想阻挠谁的话，找熔岩队去\n"
	.string "啊……$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "呵，无所谓！至少我们争取到了时\n"
	.string "间！\p"
	.string "老大肯定已经拿到想要的东西了！$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "啊，我明白了！你想加入熔岩队，但\n"
	.string "是他们不要你！\p"
	.string "哼，也别以为我们会让你加入我们海\n"
	.string "洋队！$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "要是你那么想加入海洋队，我们也可\n"
	.string "以考虑考虑……$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "老大和我们手下之间可是紧密相连\n"
	.string "的。$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "水梧桐：虽然被熔岩队的赤焰松抢先\n"
	.string "了一步，但我们想要的东西也到手\l"
	.string "了！\p"
	.string "在送神山上所供奉的朱红色宝珠……如\n"
	.string "今已在我水梧桐手中！\p"
	.string "呵呵呵……如今我们可以实现我们的最\n"
	.string "终目标了！\p"
	.string "好了，伙计们！我们撤！$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "不……怎么会这样……\p"
	.string "不光是靛蓝色宝珠，连朱红色宝珠都\n"
	.string "被抢走了……\p"
	.string "靛蓝色宝珠和朱红色宝珠绝不能分\n"
	.string "离。它们是一体的。\p"
	.string "那些人抢走两块宝珠想要干什么？\p"
	.string "…… …… ……\n"
	.string "…… …… ……\p"
	.string "啊，对了，先到这里拿走靛蓝色宝珠\n"
	.string "的是不是熔岩队？\p"
	.string "看来他们在匆忙之中把这个落下了。\p"
	.string "我不知道这东西究竟是什么，\p"
	.string "还是交给你保管吧，或许能派上些用\n"
	.string "场。$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "靛蓝色宝珠和朱红色宝珠被那些恶棍\n"
	.string "抢走了……\p"
	.string "它们绝不能分离……我有种不祥的预\n"
	.string "感……$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "天啊……\p"
	.string "你说固拉多和盖欧卡都已经苏醒了？\p"
	.string "据说靛蓝色宝珠和朱红色宝珠能够平\n"
	.string "息那两只宝可梦的怒火……\p"
	.string "还有传说称两块宝珠的真正拥有者依\n"
	.string "然存在。\p"
	.string "不过，谁也不知道宝珠到底属于谁。\p"
	.string "可能是一个人，也可能是宝可梦，但\n"
	.string "没人知道真相。$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "那两个抢走宝珠的人主动回来归还了\n"
	.string "它们。\p"
	.string "那两个人……或许终究并非那么邪恶……$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "大地，海洋，还有天空的化身……\p"
	.string "据说这就是那些超古代宝可梦的身\n"
	.string "份……\p"
	.string "我们人类与宝可梦的生命都是一样\n"
	.string "的，而我们的世界也拥有着生命……\p"
	.string "超古代宝可梦是这么告诉过我们的……$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "送神山是逝去宝可梦们的灵魂安息的\n"
	.string "地方……\p"
	.string "在这里可以俯瞰整个丰缘地区……\p"
	.string "宝可梦游离的灵魂必能在此得到安\n"
	.string "息……\p"
	.string "你的到来会是巧合吗……\p"
	.string "想听个故事吗？一个关于丰缘地区的\n"
	.string "古老传说？$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "很久很久以前……\p"
	.string "由于大地之宝可梦和海洋之宝可梦的\n"
	.string "激烈冲突，世界陷入了混乱之中……\p"
	.string "大地之宝可梦召唤高山，创造大陆……\p"
	.string "海洋之宝可梦掀起巨浪，开辟海洋……\p"
	.string "它们无休止的激战持续肆虐。\p"
	.string "世界被无情的烈焰与残酷的风暴所吞\n"
	.string "没。\p"
	.string "直到最后靛蓝色宝珠和朱红色宝珠使\n"
	.string "灾难走向了终结。\p"
	.string "耀眼的光芒从宝珠里迸发而出，平息\n"
	.string "了两只暴怒的宿敌。\p"
	.string "平静下来的它们遁入深渊，从此消失\n"
	.string "得无影无踪……$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "原来如此……也罢，这样也好……$"

MtPyre_Summit_Text_MaxieSilence:
	.string "赤焰松：{PLAYER}……\p"
	.string "…… …… ……\n"
	.string "…… …… ……$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "我的使命就是把丰缘地区的传说一代\n"
	.string "代传承下去。\p"
	.string "而刚刚在那琉璃市终结的危机已改写\n"
	.string "了新的篇章……\p"
	.string "那么，你有没有时间听听丰缘地区的\n"
	.string "新传说呢？$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "很久很久以前……\p"
	.string "由于大地之宝可梦和海洋之宝可梦的\n"
	.string "激烈冲突，世界陷入了混乱之中……\p"
	.string "大地之宝可梦召唤高山，创造大陆……\p"
	.string "海洋之宝可梦掀起巨浪，开辟海洋……\p"
	.string "它们无休止的激战持续肆虐。\p"
	.string "世界被无情的烈焰与残酷的风暴所吞\n"
	.string "没。\p"
	.string "就在此刻，天空之宝可梦自风暴中降\n"
	.string "临。\p"
	.string "这只闪耀翠绿光芒的宝可梦平息了两\n"
	.string "只暴怒宝可梦的争斗。\p"
	.string "完成使命后，这只绿色的宝可梦向着\n"
	.string "苍茫蔚蓝的远方翱翔而去……$"

