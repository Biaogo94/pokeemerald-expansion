SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "欢迎来到海洋科学博物馆。\p"
	.string "参观费是¥50。您要参观吗？$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "祝您愉快。$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "嗯？很抱歉，您似乎没有带够钱。$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "哦？您和刚刚离开的那些人是一起的\n"
	.string "吗？\p"
	.string "只剩下您一个了，您最好快些赶上他\n"
	.string "们！$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "我们海洋队永远站在正义的一方！$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "上面要我们在这儿集合，所以我们都\n"
	.string "来了，但是……\p"
	.string "老大还没来。$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "如果偷走这儿的东西，能让我一夜暴\n"
	.string "富吗？$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "我觉得在这里我会做出些坏事来……$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "如果不是那些蠢货在卡那兹市搞砸\n"
	.string "了，我们怎么会到这儿来！$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "我没带够¥50，从接待员那儿混进来\n"
	.string "花了不少时间。$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "我想了解大海，把那些知识融入我的\n"
	.string "对战中。$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "一看到大海我就会感到头晕！\p"
	.string "对我来说，楠木馆长是最大的榜样！$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "大海一望无际，无限深沉……\p"
	.string "里面一定还有很多我们所不知道的宝\n"
	.string "可梦。$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "我想要只海中的宝可梦。\p"
	.string "抱着它们的感觉一定很奇妙。$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "哎呀！你在这儿干什么？\p"
	.string "我？我是之前被你狠狠教训过的海洋\n"
	.string "队队员，记得吗？就在卡绿隧道那\l"
	.string "里？\p"
	.string "这个给你！原谅我吧！$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "比起我来，这个招式学习器更适合\n"
	.string "你。\p"
	.string "希望下次不要再见面了！啊哈哈哈！$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "啊噢，拜托了！拿着这个，放我走\n"
	.string "吧！$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "蓝色的液体在玻璃容器中盘旋着。\p"
	.string "“利用风力人工制造漩涡的实验”。$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "一个红色的球在玻璃容器里上下跳\n"
	.string "动。\p"
	.string "“利用球的浮力模拟攀瀑的实验”。$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "海底土壤的样品。\p"
	.string "“生物遗骸沉到海洋底部，经过多年\n"
	.string "形成沉积层。\p"
	.string "研究这些地层，能够揭示出远古的历\n"
	.string "史”。$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "海滩沙子的样品。\p"
	.string "“河流冲下高山上的石块，在颠簸中\n"
	.string "粉碎成小石子，\p"
	.string "最后成为海滩上松散的沙粒”。$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“海洋小常识 1为什么海水是蓝的"
	.string "？\p"
	.string "光分成多种颜色。\p"
	.string "穿过海水时，大部分光失去了颜色。\p"
	.string "但蓝色光能留住颜色，所以海水看上\n"
	.string "去就成了蓝色。”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“海洋小常识 2为什么海水是咸的"
	.string "？\p"
	.string "“海水中溶解的盐以钠离子和氯离子\n"
	.string "的形式存在。\p"
	.string "这些离子由礁石分离，被雨水冲进大\n"
	.string "海。\p"
	.string "溶解的盐慢慢聚集，使海水变咸。”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“海洋小常识 3大陆和海洋哪个更\n"
	.string "大？\p"
	.string "海洋占据星球上70%的地表，剩下的\n"
	.string "是大陆。\p"
	.string "因此海洋的面积是大陆的两倍以上"
	.string "。”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "有波浪形突起的化石。\p"
	.string "“洋底的泥土经过潮汐的冲刷，\p"
	.string "表面留下了凹凸不平的痕迹。\p"
	.string "泥土变成化石后，就形成了波纹石"
	.string "。”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "半球型的玻璃罩下面有奇怪的机器在\n"
	.string "运转。\p"
	.string "也许是用来测量什么东西的深度的……$"

