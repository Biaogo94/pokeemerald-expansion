MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "嗨，怎么样，向冠军目标冲刺的\n"
	.string "{PLAYER}？\p"
	.string "这里的道馆馆主使用的是超能力属性\n"
	.string "宝可梦，\p"
	.string "如果用格斗属性或毒属性对付它们，\n"
	.string "会受到很大伤害！\p"
	.string "另外，她们会使用强大的组合攻击，\p"
	.string "想要赢的话，就给她们看看你与你的\n"
	.string "宝可梦之间紧密的联系吧。加油！$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "哇，你让我大吃一惊！你是个优秀的\n"
	.string "训练家！$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "战斗取决于你的精神力量！心灵弱小\n"
	.string "的人永远不会赢！$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "我输了！我必须重新调整我的精神！$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "优柔寡断的人会输掉战斗，这是我对\n"
	.string "你的忠告。$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "让我看看你的天赋吧！$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "你拥有非凡的天赋！$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "如果世上真的有天才，那么就是我们\n"
	.string "的道馆馆主！\p"
	.string "但你说不定拥有比他们更高的天赋……$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "嘿嘿嘿……看我用心灵感应让精灵球浮\n"
	.string "起来！\p"
	.string "呜啊啊啊啊啊啊啊！…… …… …… ……\p"
	.string "有时我还是不能同步……$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "我的宝可梦战斗技术也不能同步了！$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "要用精神力举起精灵球还是困难了\n"
	.string "点，但这么小的灰尘的话……\p"
	.string "呜啊啊啊啊啊啊啊！…… …… ……\p"
	.string "不不，我没骗人！我没吹牛！真的！$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "输给我的话，也不要太责怪自己。\p"
	.string "不是你弱小——而是我太强了！$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "你太强了！$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "我失败了，但我不会气馁。我只是需\n"
	.string "要更严格的训练。\p"
	.string "总是乐观看待事情——这是我的优势"
	.string "！$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "看到了……你的未来……\p"
	.string "你能打败我的话，我就告诉你未来！$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "我投降！$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "你和我们的道馆馆主之间会有一场激\n"
	.string "烈的战斗……\p"
	.string "结果……我不会告诉你的！$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "你走过的路……你经历过的事……\p"
	.string "用你所学会的一切全力攻击吧！$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "你走过的路可谓非凡！$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "勤奋的人们拥有光明的前途，\p"
	.string "而懒惰的人所面对的惟有绝望的终\n"
	.string "点。\p"
	.string "种下什么因，就得到什么果……$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "即使有生命危险，我也会赢得胜利！$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "你所做的……吓倒了我……$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "你竟敢打败我……\p"
	.string "若有厄运降临于你，不要怪我……$"

MossdeepCity_Gym_Text_NateIntro:
	.string "呵呵呵。\p"
	.string "让我给你看看超能力属性的执着。$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "啊，天哪，天哪！你的战斗无与伦\n"
	.string "比！$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "我……我不会被任——任何失败吓——吓\n"
	.string "倒。$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "体会一下完全绝望的恐怖吧！$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "不——！$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "你的活力感染了我！快点离开吧！$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "我也许已过盛年，但我建议你不要小\n"
	.string "觑我。$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "啊，你身上散发着年轻的活力！$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "看来我无法胜过你的活力。$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "休想走到最后！只要我在就绝无可\n"
	.string "能！$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "怎么可能强得这么离谱？$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "哼！就算你实力不错，也根本不适合\n"
	.string "超能力属性！\p"
	.string "你的对战方式实在太粗暴了！$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "呜啊啊啊！尝尝我的宝可梦超级对战\n"
	.string "力量吧！$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "啊！完了！$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "好吧！接下来我要修炼出一种无敌的\n"
	.string "宝可梦力量！$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "小枫：嘿嘿嘿……你惊讶吗？\p"
	.string "小南：呵呵呵……你惊讶吧？\p"
	.string "小枫：这里有两个道馆馆主？小南：\n"
	.string "这里有两个道馆馆主？\p"
	.string "小枫：我们是双胞胎！小南：我们是\n"
	.string "双胞胎！\p"
	.string "小枫：我们无需言语，因为……小南：\n"
	.string "我们可以感知……\p"
	.string "小枫：彼此心中所想……小南：仅凭意\n"
	.string "念相通！\p"
	.string "小枫：这样的组合……小南：你能战胜\n"
	.string "吗？$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "小枫：什么？！我们的组合……小南：\n"
	.string "被瓦解了！\p"
	.string "小枫：没办法，是你赢了……小南：作\n"
	.string "为证明，请收下这个。$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER}从小枫与小南那里\n"
	.string "得到了心灵徽章。$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "小枫：心灵徽章能提升宝可梦的特攻\n"
	.string "和特防。\p"
	.string "小南：有了它，你也能在对战外使用\n"
	.string "秘传招式潜水了。\p"
	.string "小枫：也请你收下这个。$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "小枫：那个招式学习器04里面是……小\n"
	.string "南：冥想！\p"
	.string "小枫：它能提升特攻……小南：还能提\n"
	.string "升特防！\p"
	.string "小枫：对于超能力属性宝可梦而言……\n"
	.string "小南：这是最完美的招式！\p"
	.string "…… …… ……$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "把道馆馆主小枫与小南登记到宝可导\n"
	.string "航里了。$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "小枫：看起来你和你的宝可梦之间的\n"
	.string "牵绊比我们双胞胎之间的牵绊还要\l"
	.string "强。\p"
	.string "小南：你们会变得更强！我们和你对\n"
	.string "战过，所以我们知道。$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "小枫：嘿嘿嘿……你惊讶吗？\p"
	.string "小南：这里有两个道馆馆主？\p"
	.string "小枫：哎，你只有1只……小南：能对\n"
	.string "战的宝可梦。\p"
	.string "小枫：我们不能这样对战！\p"
	.string "小南：要和我们对战，再多带几只宝\n"
	.string "可梦来吧。$"

MossdeepCity_Gym_Text_GymStatue:
	.string "绿岭市宝可梦道馆$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "绿岭市宝可梦道馆\p"
	.string "小枫与小南认可的训练家：\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "小枫：宝可梦……小南：宝可梦……\p"
	.string "小枫：改变队伍组合的话……小南：战\n"
	.string "斗风格也会随之改变。\p"
	.string "小枫：但是我……小南：但是我……\p"
	.string "小枫：会一直跟小南在一起！小南：\n"
	.string "会一直跟小枫在一起！\p"
	.string "小枫：我们会向你一次次……小南：展\n"
	.string "现我们的组合！$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "小枫：你和你的宝可梦……小南：简直\n"
	.string "像亲兄弟姐妹！$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "小枫：你可以将我们击倒，但我们不\n"
	.string "会停滞不前！\p"
	.string "小南：因为我们两个，会永远互相支\n"
	.string "持！$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "小枫：你又回来……小南：你又回来……\p"
	.string "小枫：跟我们再次对战。小南：跟我\n"
	.string "们再次对战。\p"
	.string "小枫：但是……小南：向我们挑战……\p"
	.string "小枫：你却只带来了1只宝可梦！小\n"
	.string "南：你却只带来了1只宝可梦！\p"
	.string "小枫：你再来时要带来……小南：至少\n"
	.string "2只宝可梦。$"
