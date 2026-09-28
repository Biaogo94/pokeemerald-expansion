BattleFrontier_ReceptionGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition_hns
	.byte 0

BattleFrontier_ReceptionGate_OnTransition_hns:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame_hns:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_FRONTIER_RECEPTION_GREETER
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene_hns
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene_hns::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter_hns
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit_hns
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter_hns:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit_hns:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike_hns
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall_hns
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode_hns::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_Level50_hns::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry_hns::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems_hns::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_Symbols_hns::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns:
	.string "您是第一次来这里吗？请往这边走！$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns:
	.string "宝可梦对战的最前线！欢迎来到对战\n"
	.string "开拓区！$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns:
	.string "我们会为初次来访的客人发放开拓通\n"
	.string "行证。\p"
	.string "它适用于对战开拓区内的所有设施。\p"
	.string "给您！$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns:
	.string "{PLAYER}获得了开拓通行证\n"
	.string "。$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns:
	.string "{PLAYER}将训练家卡放入了\n"
	.string "开拓区通行证。$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns:
	.string "希望您能尽情享受对战开拓区提供的\n"
	.string "一切乐趣！$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns:
	.string "？？？：哎呀，这不是\n"
	.string "{PLAYER}{KUN}吗！你\l"
	.string "果然来这里了啊！$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns:
	.string "向导：啊！亚希达先生！您好，先生\n"
	.string "！$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns:
	.string "亚希达：能在这里见到你，真是太棒\n"
	.string "了！\p"
	.string "希望你能慢慢逛，走遍这里的每一个\n"
	.string "角落。\p"
	.string "当然，我也希望你能体验到对战的最\n"
	.string "纯粹的魅力。\p"
	.string "我的住处也在这里，有空的话随时欢\n"
	.string "迎来坐坐。$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns:
	.string "我是对战开拓区各处设施的向导。$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns:
	.string "您想了解哪处设施呢？$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns:
	.string "那是被视为对战开拓区象征的巨大高\n"
	.string "塔。\p"
	.string "塔内有4种对战室，分别用于单打、\n"
	.string "双打、多人以及通信多人对战。$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns:
	.string "对战巨蛋是一座外形酷似巨蛋的大型\n"
	.string "建筑。\p"
	.string "在这里举办名为锦标赛的活动。\p"
	.string "锦标赛分为单打对战和双打对战两种\n"
	.string "比赛模式。$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns:
	.string "对战宫殿是对战开拓区右侧的红色建\n"
	.string "筑。\p"
	.string "里面设有单打对战和双打对战两种对\n"
	.string "战大厅。$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns:
	.string "对战竞技场是对战开拓区中右侧类似\n"
	.string "道场的建筑。\p"
	.string "对战竞技场举办名为胜负判定淘汰赛\n"
	.string "的活动。$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns:
	.string "对战工厂是离我们最近的一座大型建\n"
	.string "筑。\p"
	.string "那里举办名为交换对战的活动。\p"
	.string "交换对战活动分为单打对战和双打对\n"
	.string "战两种模式。$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns:
	.string "对战水管是对战开拓区中左侧外形似\n"
	.string "宝可梦的建筑。\p"
	.string "那里举办名为选择对战的活动。$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns:
	.string "对战金字塔是那座巨大的金字塔。\p"
	.string "那里举办名为探险对战的活动。$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns:
	.string "纪录大厅位于对战塔附近。\p"
	.string "在那里，你可以看到前来挑战对战开\n"
	.string "拓区诸多项目的训练家们所留下的辉\l"
	.string "煌纪录。$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns:
	.string "兑换服务角位于对战塔附近。\p"
	.string "你在对战开拓区获得的对战点数，可\n"
	.string "以在那里兑换丰厚的奖品。$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns:
	.string "我是为您介绍对战开拓区各设施共通\n"
	.string "基础规则的向导。$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns:
	.string "您想了解哪方面的规则？$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns:
	.string "对战开拓区所有设施的挑战都分为两\n"
	.string "种模式--50级与公开级别。$"

BattleFrontier_ReceptionGate_Text_Level50Info_hns:
	.string "50级模式允许不超过50级的宝可\n"
	.string "梦参加挑战。\p"
	.string "但是请注意，你面对的对手绝对不会\n"
	.string "派出低于50级的宝可梦。\p"
	.string "这个模式是对战开拓区的入门级别。\p"
	.string "建议您先从挑战这个模式开始。$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns:
	.string "公开级别模式对参赛宝可梦的等级没\n"
	.string "有任何限制。\p"
	.string "对手的宝可梦等级会调整为与你出战\n"
	.string "的宝可梦等级相同。\p"
	.string "但是，你面对的对手绝对不会派出低\n"
	.string "于60级的宝可梦。$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns:
	.string "几乎所有的宝可梦都可以参加所有设\n"
	.string "施的挑战。\p"
	.string "但是，蛋以及某些特定的宝可梦是不\n"
	.string "能参加的。\p"
	.string "挑战所需的宝可梦数量因设施而异。\p"
	.string "但是，所有设施都禁止携带两只或以\n"
	.string "上同种类的宝可梦参加。$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns:
	.string "参加对战开拓区设施的挑战时，宝可\n"
	.string "梦不能携带同一种道具。\p"
	.string "请确保所有参赛的宝可梦携带的道具\n"
	.string "各不相同。$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns:
	.string "我是开拓区通行证的向导。$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns:
	.string "您想了解哪处设施呢？$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns:
	.string "对战开拓区一共有7处设施。\p"
	.string "实力得到认可的训练家可以在各个设\n"
	.string "施中获得象征。\p"
	.string "想要获得象征，训练家需要连续击败\n"
	.string "其他训练家，并且可能需要多次赢得\l"
	.string "比赛。\p"
	.string "获得象征绝非易事。祝您好运！$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns:
	.string "在开拓区通行证上可以记录一场对战\n"
	.string "。\p"
	.string "你可以记录一场与朋友进行的对战。\p"
	.string "或者记录在对战开拓区进行的对战，\n"
	.string "但对战管道和对战金字塔的比赛除外\l"
	.string "。\p"
	.string "你可以在对战结束后选择保存比赛录\n"
	.string "像。$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns:
	.string "对战点数是奖励给在对战开拓区表现\n"
	.string "出色的训练家的报酬。\p"
	.string "你可以在兑换服务角用对战点数兑换\n"
	.string "奖品。$"

