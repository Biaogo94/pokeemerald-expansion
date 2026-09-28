BattleFrontier_Lounge2_hns_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice_hns::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews_hns
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews_hns::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle_hns::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble_hns::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns::
	.string "你好！说到关于对战开拓区的情报，\n"
	.string "我可是首屈一指的。\p"
	.string "你可以称呼我为开拓区狂人。\p"
	.string "顺便确认一下，你也是训练家对吧？\p"
	.string "我很乐意和你分享我收集到的对战开\n"
	.string "拓区最新情报。$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns::
	.string "你好！你是顺道过来向我打听最新消\n"
	.string "息的吗？好吧，没问题！$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight_hns::
	.string "怎么样？怎么样？怎么样？\p"
	.string "我的情报对你肯定超级有帮助吧？$"

BattleFrontier_Lounge2_Text_FacilityIsHottest_hns::
	.string "让我想想......\p"
	.string "听起来现在最热门的设施是\n"
	.string "{STR_VAR_1}。$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns::
	.string "让我想想......\p"
	.string "听起来对战塔的\n"
	.string "{STR_VAR_1}最受瞩目。$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere_hns::
	.string "你一定不知道这个吧！\p"
	.string "被亚希达先生称为开拓之脑的顶尖训\n"
	.string "练家就在那里。\p"
	.string "掌管那里的，是被称为大君的神秘训\n"
	.string "练家。$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons_hns::
	.string "你和大君交过手了吗？\p"
	.string "她在试探对手实力时，据说会使用这\n"
	.string "几只宝可梦：\p"
	.string "超能力属性的念力宝可梦、火属性的\n"
	.string "火山宝可梦，以及一般属性的瞌睡宝\l"
	.string "可梦。$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons_hns::
	.string "你和大君认真对战过了吗？\p"
	.string "当她全力以赴战斗时，据说会使用这\n"
	.string "几只宝可梦：\p"
	.string "龙与超能力属性的无限宝可梦、电属\n"
	.string "性的雷电宝可梦，以及一般属性的瞌\l"
	.string "睡宝可梦。$"

BattleFrontier_Lounge2_Text_DomeAceIsThere_hns::
	.string "你一定不知道这个吧！\p"
	.string "被亚希达先生称为开拓之脑的顶尖训\n"
	.string "练家就在那里。\p"
	.string "掌管那里的，是被称为超巨星的华丽\n"
	.string "训练家。$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons_hns::
	.string "你和超巨星交过手了吗？\p"
	.string "当他不把对手放在心上时，会使用这\n"
	.string "三只宝可梦：\p"
	.string "龙与飞行属性的龙宝可梦、水与地面\n"
	.string "属性的沼鱼宝可梦，以及火与飞行属\l"
	.string "性的火焰宝可梦。$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons_hns::
	.string "你和认真的超巨星交过手了吗？\p"
	.string "当他展现真正的战术时，会使用这三\n"
	.string "只宝可梦：\p"
	.string "龙与飞行属性的无限宝可梦、水与地\n"
	.string "面属性的沼鱼宝可梦，以及钢与超能\l"
	.string "力属性的铁足宝可梦。$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere_hns::
	.string "你一定不知道这个吧！\p"
	.string "被亚希达先生称为开拓之脑的顶尖训\n"
	.string "练家就在那里。\p"
	.string "掌管那里的，是被称为工厂首领的怪\n"
	.string "人训练家。$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons_hns::
	.string "你已经和工厂首领交过手了吗？\p"
	.string "让我想想......他进行对战时\n"
	.string "，也只是获得三只租用的宝可梦。\p"
	.string "他的对战条件和你几乎完全相同。$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons_hns::
	.string "你和认真的工厂首领交过手了吗？\p"
	.string "即使他动真格去对战，也同样是获得\n"
	.string "三只租用的宝可梦。\p"
	.string "他的对战条件实质上和你完全相同。$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere_hns::
	.string "你一定不知道这个吧！\p"
	.string "被亚希达先生称为开拓之脑的顶尖训\n"
	.string "练家就在那里。\p"
	.string "掌管那里的，是被称为管道皇后的可\n"
	.string "怕训练家。$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons_hns::
	.string "你以前和管道皇后交过手吗？\p"
	.string "听说当她心情不错时，会使用这三只\n"
	.string "宝可梦：\p"
	.string "毒属性的牙蛇宝可梦、虫与岩石属性\n"
	.string "的发酵宝可梦，以及水属性的慈爱宝\l"
	.string "可梦。$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons_hns::
	.string "你和认真的管道皇后交过手了吗？\p"
	.string "听说当她真正动怒时，会使用这三只\n"
	.string "宝可梦：\p"
	.string "毒属性的牙蛇宝可梦、钢与地面属性\n"
	.string "的铁蛇宝可梦，以及水与飞行属性的\l"
	.string "凶恶宝可梦。$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere_hns::
	.string "你一定不知道这个吧！\p"
	.string "被亚希达先生称为开拓之脑的顶尖训\n"
	.string "练家就在那里。\p"
	.string "掌管那里的，是被称为竞技场主将的\n"
	.string "可爱训练家。$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons_hns::
	.string "你以前和竞技场主将交过手吗？\p"
	.string "她在试探对手的能力时，据说是使用\n"
	.string "这几只宝可梦：\p"
	.string "虫与格斗属性的独角宝可梦、恶属性\n"
	.string "的月光宝可梦，以及虫与幽灵属性的\l"
	.string "脱壳宝可梦。$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons_hns::
	.string "你和认真的竞技场主将交过手了吗？\p"
	.string "当她动真格战斗时，据说是使用这几\n"
	.string "只宝可梦：\p"
	.string "恶属性的月光宝可梦、幽灵与毒属性\n"
	.string "的影子宝可梦，以及草与格斗属性的\l"
	.string "蘑菇宝可梦。$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere_hns::
	.string "你一定不知道这个吧！\p"
	.string "被亚希达先生称为开拓之脑的顶尖训\n"
	.string "练家就在那里。\p"
	.string "掌管那里的，是被称为宫殿守护者的\n"
	.string "阴沉训练家。$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons_hns::
	.string "你以前和宫殿守护者交过手吗？\p"
	.string "当他试探对手的气魄时，据说会使用\n"
	.string "这几只宝可梦：\p"
	.string "毒与飞行属性的蝙蝠宝可梦、一般属\n"
	.string "性的偷懒宝可梦，以及水与冰属性的\l"
	.string "乘载宝可梦。$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons_hns::
	.string "你和认真的宫殿守护者交过手了吗？\p"
	.string "当他倾尽全力投入对战时，据说会使\n"
	.string "用这几只宝可梦：\p"
	.string "火属性的传说宝可梦、一般属性的偷\n"
	.string "懒宝可梦，以及水属性的极光宝可梦\l"
	.string "。$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere_hns::
	.string "你一定不知道这个吧！\p"
	.string "被亚希达先生称为开拓之脑的顶尖训\n"
	.string "练家就在那里。\p"
	.string "掌管那里的，是被称为金字塔法老的\n"
	.string "热血训练家。$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons_hns::
	.string "你以前和金字塔法老交过手吗？\p"
	.string "当他测试对手的力量时，据说会使用\n"
	.string "这几只宝可梦：\p"
	.string "岩石属性的岩峰宝可梦、冰属性的冰\n"
	.string "山宝可梦，以及钢属性的黑铁宝可梦\l"
	.string "。$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons_hns::
	.string "你和认真起来的金字塔法老对战过\n"
	.string "吗？\p"
	.string "当他充满热情的力量时，据说会使用\n"
	.string "这些宝可梦：\p"
	.string "冰与飞行属性的冻结宝可梦，电与飞\n"
	.string "行属性的电气宝可梦，以及火与飞行\l"
	.string "属性的火焰宝可梦。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1_hns::
	.string "确实，有几个地方可以进行双打对战\n"
	.string "。\p"
	.string "但对战塔的双打对战室，可以说是基\n"
	.string "础中的基础！\p"
	.string "你应该在那里学习对战开拓区的双打\n"
	.string "对战规则。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2_hns::
	.string "在这里对战要多加小心。\p"
	.string "听说有些训练家专门针对双打对战开\n"
	.string "发了战术。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3_hns::
	.string "只要你在这里的双打对战中积累了信\n"
	.string "心并游刃有余，就可以考虑去挑战其\l"
	.string "他提供双打对战的设施了。$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice_hns::
	.string "形形色色的训练家都会聚集在对战沙\n"
	.string "龙里。\p"
	.string "想想看--你可能会遇到你的朋友或\n"
	.string "崇拜者哦！仔细找找看吧！$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice_hns::
	.string "如果你和朋友在一起，就去通信多人\n"
	.string "对战室吧。\p"
	.string "要是和一个强大的朋友联手，就能遇\n"
	.string "到实力强劲的对手哦！$"

BattleFrontier_Lounge2_Text_NewsGatheringPower_hns::
	.string "多么惊人的情报收集能力！我师父真\n"
	.string "是无与伦比！$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns::
	.string "多么惊人的观察力！我师父真是无与\n"
	.string "伦比！$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns::
	.string "多么惊人的说服力！我师父真是无与\n"
	.string "伦比！$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns::
	.string "......这是什么地方啊？好可\n"
	.string "怕......$"

