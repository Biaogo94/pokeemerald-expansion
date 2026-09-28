VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
	.string "你应该为自己感到骄傲，你已经在这\n"
	.string "条冠军之路上勇敢的杀出了属于自己\l"
	.string "的路。\p"
	.string "作为对你成绩的认可我会教你舍身冲\n"
	.string "撞。\p"
	.string "你想要我教你学这个技能吗？$"

Text_DoubleEdgeDeclined::
	.string "我随时都能教你这个技能的。$"

Text_DoubleEdgeWhichMon::
	.string "我要教哪个宝可梦舍身冲撞$"

Text_DoubleEdgeTaught::
	.string "保持那股动力，去参加宝可梦联盟吧\n"
	.string "！\p"
	.string "去会会他们并将他们通通击败吧！$"

VictoryRoad_3F_Text_GeorgeIntro::
	.string "我听说关于一个神童的传闻。$"

VictoryRoad_3F_Text_GeorgeDefeat::
	.string "传闻是真的！$"

VictoryRoad_3F_Text_GeorgePostBattle::
	.string "莫非，就是你击败了火箭队的坂木吗\n"
	.string "？$"

VictoryRoad_3F_Text_AlexaIntro::
	.string "训练家的人生就是去寻找更强的对手\n"
	.string "。$"

VictoryRoad_3F_Text_AlexaDefeat::
	.string "啊！这么强！$"

VictoryRoad_3F_Text_AlexaPostBattle::
	.string "在艰难的战斗中，你会变得更强。$"

VictoryRoad_3F_Text_CarolineIntro::
	.string "我会让你看看你到底有多强……还是\n"
	.string "多弱！$"

VictoryRoad_3F_Text_CarolineDefeat::
	.string "我很气愤！$"

VictoryRoad_3F_Text_CarolinePostBattle::
	.string "你只不过证明了我有多强……$"

VictoryRoad_3F_Text_ColbyIntro::
	.string "只有被选中的人可以通过这里！$"

VictoryRoad_3F_Text_ColbyDefeat::
	.string "我不相信！$"

VictoryRoad_3F_Text_ColbyPostBattle::
	.string "这里所有的训练家都以宝可梦联盟为\n"
	.string "目标。\p"
	.string "不要放松警惕。$"

VictoryRoad_3F_Text_RayIntro::
	.string "阿新：我们俩在一起会更强大！$"

VictoryRoad_3F_Text_RayDefeat::
	.string "阿新：真可笑！这是不可能的！$"

VictoryRoad_3F_Text_RayPostBattle::
	.string "阿新：你打败了我们。强大的人总是\n"
	.string "难以捉摸……$"

VictoryRoad_3F_Text_RayNotEnoughMons::
	.string "阿新：我们俩一起着向冠军努力。\p"
	.string "请你带上两只宝可梦来跟我们战斗。$"

VictoryRoad_3F_Text_TyraIntro::
	.string "佳代：我们正试着一起变成冠军。$"

VictoryRoad_3F_Text_TyraDefeat::
	.string "佳代：哦，但是……$"

VictoryRoad_3F_Text_TyraPostBattle::
	.string "佳代：你教会了我，实力有无数种形\n"
	.string "式和形态。$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
	.string "佳代：如果你只有一只宝可梦，就不\n"
	.string "能和我们战斗。$"

