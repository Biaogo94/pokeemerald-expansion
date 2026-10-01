BattleFrontier_Lounge1_hns_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder_hns::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_Breeder_hnsIntro_hns
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder_hns
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder_hns
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect_hns
	end

BattleFrontier_Lounge1_EventScript_Breeder_hnsIntro_hns::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder_hns::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon_hns, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder_hns::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder_hns
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs_hns       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs_hns @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs_hns         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs_hns     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder_hns::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat_hns::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP_hns
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk_hns
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef_hns
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed_hns
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk_hns
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef_hns
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue_hns::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow_hns
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid_hns
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh_hns
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax_hns
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments_hns::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow_hns::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid_hns::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh_hns::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax_hns::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect_hns::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1_hns::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2_hns::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro_hns:
	.string "我培育宝可梦已有70年！我就是人们\n"
	.string "尊称为传说的顶级宝可梦培育家的\l"
	.string "人！\p"
	.string "只要到了我这个资历，一眼就能看穿\n"
	.string "宝可梦的能力。\p"
	.string "你也是个训练家，难道不想知道自己\n"
	.string "的宝可梦的能力吗？\p"
	.string "来吧！让我看看你的宝可梦！$"

BattleFrontier_Lounge1_Text_AverageAbility_hns:
	.string "……唔……\p"
	.string "这只总体来看，能力的评价算是比较\n"
	.string "普通。$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility_hns:
	.string "……唔……\p"
	.string "这只总体来看，能力的评价算是相当\n"
	.string "不错。$"

BattleFrontier_Lounge1_Text_ImpressiveAbility_hns:
	.string "……唔……\p"
	.string "这只总体来看，拥有相当出色的能\n"
	.string "力！$"

BattleFrontier_Lounge1_Text_OutstandingAbility_hns:
	.string "……唔……\p"
	.string "这只总体来看，拥有非常了不起的卓\n"
	.string "越能力！$"

BattleFrontier_Lounge1_Text_BestAspectHP_hns:
	.string "顺便一提，我觉得它最优秀的方面应\n"
	.string "该是HP......$"

BattleFrontier_Lounge1_Text_BestAspectAtk_hns:
	.string "顺便一提，我觉得它最优秀的方面应\n"
	.string "该是攻击……$"

BattleFrontier_Lounge1_Text_BestAspectDef_hns:
	.string "顺便一提，我觉得它最优秀的方面应\n"
	.string "该是防御……$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk_hns:
	.string "顺便一提，我觉得它最优秀的方面应\n"
	.string "该是特攻……$"

BattleFrontier_Lounge1_Text_BestAspectSpDef_hns:
	.string "顺便一提，我觉得它最优秀的方面应\n"
	.string "该是特防……$"

BattleFrontier_Lounge1_Text_BestAspectSpeed_hns:
	.string "顺便一提，我觉得它最优秀的方面应\n"
	.string "该是速度……$"

BattleFrontier_Lounge1_Text_StatRelativelyGood_hns:
	.string "这项能力挺不错的。……嗯……我是这么\n"
	.string "认为的。$"

BattleFrontier_Lounge1_Text_StatImpressive_hns:
	.string "这项能力相当出色。……嗯……我是这么\n"
	.string "认为的。$"

BattleFrontier_Lounge1_Text_StatOutstanding_hns:
	.string "这项能力极其优秀！……嗯……我是这么\n"
	.string "认为的。$"

BattleFrontier_Lounge1_Text_StatFlawless_hns:
	.string "简直无可挑剔！完美无瑕！......\n"
	.string "嗯……我是这么认为的。$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice_hns:
	.string "什么？你没时间听我的建议？\p"
	.string "你应该时刻虚心地向长辈学习经验才\n"
	.string "对！$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending_hns:
	.string "怎么，现在又有什么事？\p"
	.string "我手头还有正经事要忙呢！留到下次\n"
	.string "再说吧！$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon_hns:
	.string "啊，年轻人！对宝可梦的能力感兴趣\n"
	.string "了吗？\p"
	.string "来来来！让我看看你的宝可梦！$"

BattleFrontier_Lounge1_Text_EvenICantTell_hns:
	.string "我虽然是专家，但还没孵化的宝可梦\n"
	.string "我可看不出来！\p"
	.string "快拿宝可梦给我看！我要看的是宝可\n"
	.string "梦！$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding_hns:
	.string "他说我的宝可梦非常优秀！真高兴我\n"
	.string "平时悉心培育了它！$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt_hns:
	.string "他说我的宝可梦非常优秀！但我其实\n"
	.string "并没有特意做过什么培育啊……..$"

