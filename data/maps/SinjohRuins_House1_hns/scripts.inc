SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
   	.string "大吾：嗯？$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
	.string "大吾：{PLAYER}！\p"
	.string "无论在哪里，我都认得你那坚毅的目\n"
	.string "光。\p"
	.string "你怎么会来到这么遥远的北方？\p"
	.string "............\p"
	.string "原来如此，新神都的舞姬们派你来协\n"
	.string "助我们的调查啊。\p"
	.string "既然如此，那就让我来向你说明一下\n"
	.string "目前的进展吧。$"

SinjohRuins_Lab_Text_StevenIntroCutscene3:
	.string "大吾：当我第一次听说这处遗迹时，\n"
	.string "就决定无论如何都要亲自来看看。\p"
	.string "我从德文公司召集了一支队伍，展开\n"
	.string "了这次调查探险。\p"
	.string "谁也不知道这里究竟埋藏着什么。\p"
	.string "不过目前，我们已经掌握了不少线索\n"
	.string "。$"

SinjohRuins_Lab_Text_StevenIntroCutscene4:
	.string "语言学家：虽然遗迹周围发现的古代\n"
	.string "文字还未能全部破译，但我已经辨认\l"
	.string "出了一部分内容。\p"
	.string "这里一共有17块奇特的石板。\p"
	.string "它们对遗迹而言有着非同寻常的意义\n"
	.string "，但目前我们只找到了1块。\p"
	.string "据说其余的石板，正由拥有强大力量\n"
	.string "的宝可梦与训练家守护着。$"

SinjohRuins_Lab_Text_StevenIntroCutscene5:
	.string "大吾：情况就是这样，\n"
	.string "{PLAYER}。\p"
	.string "守护其余石板的王宝可梦实力太过强\n"
	.string "横，恐怕我的队伍难以招架。\p"
	.string "而且我必须留在这里主持调查工作。\p"
	.string "但我相信你一定能做到。你愿意帮助\n"
	.string "我们吗？$"

SinjohRuins_Lab_Text_StevenIntroCutscene6:
	.string "太好了。\p"
	.string "石碑上的文字显示，那些石板散布在\n"
	.string "神都各地，由王宝可梦以及强大的训\l"
	.string "练家持有。\p"
	.string "一旦我们有新的发现，我会通过宝可\n"
	.string "梦齿轮联系你。\p"
	.string "拜托你了，{PLAYER}。$"

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
	.string "你确定吗？\p"
	.string "谁也不知道这里究竟埋藏着什么。\p"
	.string "你不再考虑一下吗？$"

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
	.string "大吾：{PLAYER}！\p"
	.string "我想我知道集齐全部17块石板后会\n"
	.string "发生什么了。\p"
	.string "我感受到了……\n"
	.string ".......$"

SinjohRuins_Lab_Text_FinalPlateScene2:
	.string "大吾：我一定要亲眼见识一下！\p"
	.string "到外面去，{PLAYER}！$"

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
	.string "大吾：啊，{PLAYER}。\p"
	.string "目前已经收集到\n"
	.string "{STR_VAR_1}块石板了啊\l"
	.string "。真不错。\p"
	.string "不得不说，我非常好奇把它们全部集\n"
	.string "齐后会发生什么。\p"
	.string "好，期待你的新发现。$"

SinjohRuins_Lab_Text_StevenFindPlates3:
	.string "大吾：啊，{PLAYER}。\p"
	.string "目前已经收集到\n"
	.string "{STR_VAR_1}块石板了啊\l"
	.string "。真不错。\p"
	.string "你调查过那个石室了吗？那里处处都\n"
	.string "透着神秘呢。$"

SinjohRuins_Lab_Text_StevenFindPlates9:
	.string "大吾：啊，{PLAYER}。\p"
	.string "目前已经收集到\n"
	.string "{STR_VAR_1}块石板了啊\l"
	.string "。进展相当顺利。\p"
	.string "那些开启的石室，与丰缘地区的一系\n"
	.string "列石室有着惊人的相似之处。\p"
	.string "丰缘的那些石室中，每一处也都沉睡\n"
	.string "着传说的宝可梦。\p"
	.string "但即便是在丰缘，也仅仅发现了3处\n"
	.string "。\p"
	.string "而在这里，至少有6处之多。\p"
	.string "真不知道接下来还会发现什么。$"

SinjohRuins_Lab_Text_StevenAfterAll:
	.string "大吾：{PLAYER}！\p"
	.string "这次探险真是一段令我终生难忘的经\n"
	.string "历。\p"
	.string "自从听说这处遗迹起，我心中就一直\n"
	.string "有种预感。\p"
	.string "我觉得我们一定会发现不得了的惊世\n"
	.string "秘密。\p"
	.string "而且我的预感向来都很准。\p"
	.string "非常感谢你的一路相助，冠军。\p"
	.string "接下来你打算去哪里？\p"
	.string "期待我们日后有缘再会。$"

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
    .string "探地雷达显示在这个山谷里有6处地\n"
    .string "下石室。\p"
    .string "其中5处似乎更接近地表，还有1处\n"
    .string "埋藏得更深。$"
SinjohRuins_Lab_Text_GeologistDuring:
	.string "我一直都把设备对着下方，去探测地\n"
	.string "底的构造。\p"
	.string "但显然我早该把它对准上方的！$"
SinjohRuins_Lab_Text_GeologistAfter:
	.string "那些石板竟然和最强大的宝可梦有关\n"
	.string "联吗？？\p"
	.string "真希望能有更多时间去研究它们啊。$"

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
    .string "唔……要解读的古代文字也\n"
    .string "太多了吧……\p"
    .string "在丰缘地区可没有这种东西啊。$"
SinjohRuins_Lab_Text_LinguistDuring:
    .string "你可以想象我解读出古代文字时有多\n"
    .string "么吃惊！\p"
    .string "在告诉大吾先生之前，我反复核对了\n"
    .string "三四遍！\p"
    .string "我是说，真的存在所谓宝可梦的创造\n"
    .string "神吗？\p"
    .string "这太不可思议了。$"
SinjohRuins_Lab_Text_LinguistAfter:
    .string "这次调查真是一趟愉快的旅程，\n"
    .string "{PLAYER}。\p"
    .string "多亏你帮忙搞定了所有的实地调查。$"

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
	.string "这个地区曾经存在过的文明，彻底改\n"
	.string "变了我们对历史的认知。\p"
	.string "我们发现的许多出土文物都有一千多\n"
	.string "年的历史了。\p"
	.string "碳十四测年结果与在神奥地区发现的\n"
	.string "文物完全吻合。\p"
	.string "不过，你找到的那支笛子……\n"
	.string ".似乎年代还要久远得多。$"
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "那些石板……与神奥地区的\n"
	.string "关联……还有那支笛子..\l"
	.string "……一切都开始串连起来了。$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
	.string "你协助我们在这里发掘出的成果，其\n"
	.string "历史价值无论怎么估量都不为过，\l"
	.string "{PLAYER}。\p"
	.string "真的很感谢你。$"

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
    .string "汪呜--！！$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
    .string "这看起来是卡蒂狗的玩具球……\n"
    .string "..还是不要碰它吧。$"

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
    .string "快看这个绝妙的样本！\p"
    .string "这种卡蒂狗与世界上任何地方见到的\n"
    .string "都截然不同。\p"
    .string "DNA分析表明，它与在其他地区发\n"
    .string "现的卡蒂狗有着共同的祖先。\p"
    .string "然而，它的习性与属性却有着极大的\n"
    .string "差异。\p"
    .string "它似乎与古代神奥文献中关于卡蒂狗\n"
    .string "的记载完全吻合。\p"
    .string "也许这个物种曾经占据了广袤的领地\n"
    .string "，一路向北延伸至古代神奥。$"
SinjohRuins_Lab_Text_BiologistDuring:
	.string "如果位于阶梯顶端的那只生物真的是\n"
	.string "所有宝可梦的创造神，那是否意味着\l"
	.string "它就是最初的共同始祖？$"
SinjohRuins_Lab_Text_BiologistAfter:
	.string "通过这次考察，我收集到了大量关于\n"
	.string "地区形态与趋异进化的数据。太感谢\l"
	.string "你了，{PLAYER}。$"

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
   	.string "在这片荒野里，我徒步了十年。\p"
   	.string "不，应该说是二十年了。\p"
   	.string "直到有一天，我发现了那些巨大的石\n"
   	.string "柱和那座不祥的神殿。\p"
   	.string "那就是神都遗迹。我听别人都是这么\n"
   	.string "叫的。\p"
   	.string "那时我还不知道这附近有村落。\p"
   	.string "我只是跟几个朋友随口提了提，谁知\n"
   	.string "道一传十，十传百。\p"
   	.string "我真没想到这会让这片地方引来这么\n"
   	.string "多的关注。\p"
   	.string "感觉还挺微妙的。你懂吧？$"
SinjohRuins_Lab_Text_HikerDuringAfter:
   	.string "别告诉任何人哦，{PLAYER}\n"
   	.string "，其实我第一次发现这里的时候，就\l"
   	.string "在山顶上看到那座神殿了。\p"
   	.string "不过我把它藏在心底，谁都没说。\p"
   	.string "关于这处遗迹，我多嘴说出去的已经\n"
   	.string "够多的了。\p"
   	.string "不过至少，现在看起来一切顺利。$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
    .string "调查日志1：1975年5月3日\p"
    .string "我们已经抵达了遗迹所在地。\p"
    .string "就连在这么深的谷底，也能感受到白\n"
    .string "银山的刺骨严寒……\p"
    .string "不久之后主力发掘队就会打通山道赶\n"
    .string "来……我真迫不及待想看看\l"
    .string "我们的脚下究竟隐藏着什么了！$"

SinjohRuins_Lab_Text_Note2:
    .string "调查日志2：1975年5月10日\p"
    .string "挖掘进行了一周，毫无所获。\p"
    .string "这里的冰层厚得匪夷所思，坚硬的岩\n"
    .string "石把我们的设备全都崩坏了。\p"
    .string "就连怪力也无法对其造成丝毫损伤。\p"
    .string "这里到底是什么地方？\p"
    .string "我们一定要查个水落石出。$"

SinjohRuins_Lab_Text_Note3:
    .string "调查日志3：1975年5月14日\p"
    .string "坐以待毙可成不了事。\p"
    .string "虽然我只是个普通工人，\p"
    .string "但我想到了一个突破冰层的办法。\p"
    .string "或者应该说，融化它的办法。\p"
    .string "我们需要火属性宝可梦，而且需要很\n"
    .string "多。\p"
    .string "但我们要怎么把它们从远在天边的神\n"
    .string "奥运送过来呢？$"

SinjohRuins_Lab_Text_Note4:
    .string "调查日志4：1975年5月21日\p"
    .string "我们忙得不可开交。\p"
    .string "我的办法起效了，我们突破了冰层。\n"
    .string "只不过火属性宝可梦并不是从老家运\l"
    .string "来的。\p"
    .string "队长坚持要在当地就地取材。\p"
    .string "我们在附近村子旁的一处温泉...\n"
    .string "...\p"
    .string "强行带走了我们需要的目标……\n"
    .string "..\p"
    .string "我为此感到羞愧。但为了发展，有时\n"
    .string "牺牲是不可避免的。\p"
    .string "总之，冰层融化了。\p"
    .string "这里有6处石室，中央矗立着一座被\n"
    .string "封印的神殿。\p"
    .string "主体结构的建筑风格表明，它可能出\n"
    .string "自古代神阖之民之手……\p"
    .string "也就是我们北迁之前的先祖。\p"
    .string "队长希望尽快打开那座神殿……\n"
    .string "..$"

SinjohRuins_Lab_Text_Note5:
    .string "调查日志5：1975年6月2日\p"
    .string "我们终于把它打开了……\p"
    .string "我本以为自己会欣喜若狂……\n"
    .string ".\p"
    .string "但从神殿中喷涌而出的能量冲击，夺\n"
    .string "走了许多优秀同伴的生命。\p"
    .string "更别提那些帮我们开门的宝可梦了。\n"
    .string "愿它们的灵魂得以安息……\p"
    .string "..................\p"
    .string "不论如何。\p"
    .string "神殿是打开了，但留给我们的只有更\n"
    .string "多的疑问。\p"
    .string "里面根本没有传说中的宝可梦，也没\n"
    .string "有宝藏。\p"
    .string "我们的补给快要耗尽了，而我们的付\n"
    .string "出却一无所获……$"

SinjohRuins_Lab_Text_Note6:
  	.string "调查日志6：1975年6月10日\p"
  	.string "调查结束了。其他人正在收拾行装。\p"
  	.string "但我不能走。\p"
  	.string "我无法放弃这项任务。在付出了如此\n"
  	.string "惨痛的代价之后。\p"
  	.string "我决定留下来。$"

SinjohRuins_Lab_Text_Note7:
  	.string "调查日志7：1975年9月10日\p"
  	.string "距离我们来到这里已经过去了几个月\n"
  	.string "。或者说，自我独自留在这里算起。\p"
  	.string "其他人都已经离开了。\p"
  	.string "现在这里只剩下我和那些为了干活而\n"
  	.string "抓来的宝可梦。\p"
  	.string "我一直在训练它们变强。\p"
  	.string "尤其是我的火暴兽。\p"
  	.string "我们必须查清神殿底下到底有什么。$"

SinjohRuins_Lab_Text_Note8:
  	.string "调查日志8：1975年9月15日\p"
  	.string "失败了。\p"
  	.string "..................\p"
  	.string "我的宝可梦们……\p"
  	.string "在我的全部6只宝可梦齐心协力下，\n"
  	.string "终于击碎了神殿里的一堵暗墙。\p"
  	.string "但它就在那里等着我们……\p"
  	.string "一个形同巨神般的怪物……\p"
  	.string "它释放出的能量与上次如出一辙。\p"
  	.string "它们全军覆没了……\p"
  	.string "最可怕的是，那只怪物把暗墙重新封\n"
  	.string "印了起来。\p"
  	.string "我回不去了。大家再也认不出我了。\n"
  	.string ".....\p"
  	.string "这个地方彻底改变了我……\p"
  	.string "我打算去和村民们谈谈。\p"
  	.string "他们并不知道我都做了些什么。\p"
  	.string "既然其他人早就离开了，他们只会以\n"
  	.string "为我是一个迷路的登山者。\p"
  	.string "除了这里，我已无处可去。$"

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
    .string "这是一个陈列柜，里面整整齐齐地摆\n"
    .string "满了样本与文物！$"

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
   .string "X光与冲印研究室。$"


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
   .string "这是在遗迹内部发现的文物！$"


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
	.string "天界之笛有了反应。要吹响笛子吗？$"

SinjohRuins_Lab_Text_DropedItem:
	.string "高贵的{STR_VAR_1}掉落\n"
	.string "了道具……$"

SinjohRuins_Lab_Text_StevenName:
	.string "大吾$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
	.string "大吾：{PLAYER}。\p"
	.string "刚刚遗迹这里发生了震动。\p"
	.string "大家都没事，别担心。\p"
	.string "非常有意思的是，遗迹地下的其中一\n"
	.string "间石室突然打开了。\p"
	.string "里面的刻印让我想起了丰缘地区的某\n"
	.string "些东西。\p"
	.string "你有空的话，不妨过来看一看。$"

SinjohRuins_Lab_Text_StevenCall6Plates:
	.string "大吾：{PLAYER}。\p"
	.string "调查进展得如何了？\p"
	.string "我们这里又发生了一次震动。这次打\n"
	.string "开了第二间石室。\p"
	.string "我已经让地质学家把仪器准备好，以\n"
	.string "防再次发生震动。\p"
	.string "挖掘得越深……未解之谜反\n"
	.string "而越多了。$"

SinjohRuins_Lab_Text_StevenCall9Plates:
	.string "大吾：{PLAYER}。\p"
	.string "遗迹这里又发生了一次震动。\p"
	.string "根据监测数据，情况非常有趣。\p"
	.string "这根本就不是地震。\p"
	.string "某种积聚在地底的能量，由内而外破\n"
	.string "开了岩石。\p"
	.string "究竟是什么引起的呢……老\n"
	.string "实说，我也不清楚。$"

SinjohRuins_Lab_Text_StevenCall12Plates:
	.string "大吾：{PLAYER}。\p"
	.string "又是一次震动。又有石室被打开了。\p"
	.string "我们到现在还没能找出其中的规律。\p"
	.string "话说回来，{PLAYER}..\n"
	.string "……引发这一切的，该不会是你\l"
	.string "在做什么吧？\p"
	.string "不，应该不可能吧。$"

SinjohRuins_Lab_Text_StevenCall15Plates:
	.string "大吾：{PLAYER}。\p"
	.string "你刚才是不是又找到了石板？\p"
	.string "..................\p"
	.string "果然如此。\p"
	.string "长眠于这座遗迹中的传说的宝可梦\n"
	.string "……是在回应你，对吧？\p"
	.string "就好像希望被你找到一样。\p"
	.string "我的直觉通常很准。真不该怀疑你\n"
	.string "的。$"

SinjohRuins_Lab_Text_StevenCall16Plates:
	.string "大吾：{PLAYER}。\p"
	.string "我们离真相非常接近了。我能感觉得\n"
	.string "到。\p"
	.string "..................\p"
	.string "你最好亲自过来看看。$"

