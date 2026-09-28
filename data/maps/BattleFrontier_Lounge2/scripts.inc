BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "嗨！我是对战开拓区消息最灵通的人\n"
	.string "，\p"
	.string "你可以叫我开拓区迷。\p"
	.string "只要看一眼我就知道你是个训练家，\n"
	.string "对不？\p"
	.string "我很高兴可以和你分享在对战开拓区\n"
	.string "收集的最新最热的新闻。$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "嗨！你来是想知道最新的消息吗？好\n"
	.string "吧！$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "哇喔？哇喔？哇喔？\p"
	.string "我的情报对你来说非常有用，是吧？$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "让我想想……\p"
	.string "现在好像{STR_VAR_1}是\n"
	.string "最热门的地方。$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "让我想想……\p"
	.string "现在好像对战塔\n"
	.string "{STR_VAR_1}是最热门的\l"
	.string "。$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "告诉你个秘密！\p"
	.string "被亚希达称作开拓区大脑的顶级训练\n"
	.string "家之一现在就在那里。\p"
	.string "那里就是由那个名叫对战塔大君的神\n"
	.string "秘的训练家所掌管的。$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "你跟对战塔大君交过手了吗？\p"
	.string "一开始她测试对手的实力的时候，通\n"
	.string "常都会用这些宝可梦：\p"
	.string "超能力属性的念力宝可梦，火属性的\n"
	.string "火山宝可梦，和一般属性的瞌睡宝可\l"
	.string "梦。$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "你跟认真起来的对战塔大君交过手了\n"
	.string "吗？\p"
	.string "她全力出手的时候，通常都会用这些\n"
	.string "宝可梦：\p"
	.string "龙和超能力属性的无限宝可梦，电属\n"
	.string "性的天雷宝可梦，还有一般属性的瞌\l"
	.string "睡宝可梦。$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "告诉你个秘密！\p"
	.string "被亚希达称作开拓之脑的顶级训练家\n"
	.string "之一现在就在那里。\p"
	.string "那里就是由那个名叫巨蛋超级巨星的\n"
	.string "华丽的训练家所掌管的。$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "你跟巨蛋超级巨星交过手了吗？\p"
	.string "他没认真起来的时候，通常都会用这\n"
	.string "些宝可梦：\p"
	.string "龙和飞行属性的龙宝可梦，水和地面\n"
	.string "属性的沼鱼宝可梦，还有火和飞行属\l"
	.string "性的火焰宝可梦。$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "你跟认真起来的巨蛋超级巨星交过手\n"
	.string "了吗？\p"
	.string "当他把自己的策略完全展示的时候，\n"
	.string "通常都会用这些宝可梦：\p"
	.string "龙和飞行属性的无限宝可梦，水和地\n"
	.string "面属性的沼鱼宝可梦，还有钢和超能\l"
	.string "力属性的铁足宝可梦。$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "告诉你个秘密！\p"
	.string "被亚希达称作开拓之脑的顶级训练家\n"
	.string "之一现在就在那里。\p"
	.string "那里就是由那个名叫工厂头目的奇怪\n"
	.string "的训练家所掌管的。$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "你跟工厂头目交过手了吗？\p"
	.string "我想想……他对战时，只是使用3只\n"
	.string "租借宝可梦。\p"
	.string "他和你在非常相似的条件下对战。$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "你跟认真起来的工厂头目交过手了吗\n"
	.string "？\p"
	.string "当他认真起来时，仍然是使用3只租\n"
	.string "借宝可梦。\p"
	.string "他是和你在完全相同的条件下对战。$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "告诉你个秘密！\p"
	.string "被亚希达称作开拓之脑的顶级训练家\n"
	.string "之一现在就在那里。\p"
	.string "那里就是由那个名叫管道皇后的可怕\n"
	.string "的训练家所掌管的。$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "你跟管道皇后交过手了吗？\p"
	.string "据说她心情好的时候，通常都会用这\n"
	.string "些宝可梦：\p"
	.string "毒属性的牙蛇宝可梦，虫和岩石属性\n"
	.string "的发酵宝可梦，还有水属性的慈爱宝\l"
	.string "可梦。$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "你跟认真起来的管道皇后交过手了吗\n"
	.string "？\p"
	.string "据说她非常生气的时候，通常都会用\n"
	.string "这些宝可梦：\p"
	.string "毒属性的牙蛇宝可梦，钢和地面属性\n"
	.string "的铁蛇宝可梦，还有水和飞行属性的\l"
	.string "凶恶宝可梦。$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "告诉你个秘密！\p"
	.string "被亚希达称作开拓之脑的顶级训练家\n"
	.string "之一现在就在那里。\p"
	.string "那里就是由那个名叫竞技场主将的可\n"
	.string "爱的训练家所掌管的。$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "你跟竞技场主将交过手了吗？\p"
	.string "一开始她估计对手实力的时候，大概\n"
	.string "会用这些宝可梦：\p"
	.string "虫和格斗属性的独角宝可梦，恶属性\n"
	.string "的月光宝可梦，还有虫和幽灵属性的\l"
	.string "空壳宝可梦。$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "你跟认真起来的竞技场主将交过手了\n"
	.string "吗？\p"
	.string "她在卫冕战里大概会用这些宝可梦：\p"
	.string "恶属性的月光宝可梦，幽灵和毒属性\n"
	.string "的影子宝可梦，还有草和格斗属性的\l"
	.string "蘑菇宝可梦。$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "告诉你个秘密！\p"
	.string "被亚希达称作开拓之脑的顶级训练家\n"
	.string "之一现在就在那里。\p"
	.string "那里就是由那个名叫宫殿守护者的凶\n"
	.string "险的训练家所掌管的。$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "你跟宫殿守护者交过手了吗？\p"
	.string "据说他测试对手的心灵的时候，通常\n"
	.string "会用这些宝可梦：\p"
	.string "毒和飞行属性的蝙蝠宝可梦，一般属\n"
	.string "性的怕麻烦宝可梦，还有水和冰属性\l"
	.string "的乘载宝可梦。$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "你跟认真起来的宫殿守护者交过手了\n"
	.string "吗？\p"
	.string "据说他把精力全部集中到对战的时候\n"
	.string "，通常会使用这些宝可梦：\p"
	.string "火属性的传说宝可梦，一般属性的怕\n"
	.string "麻烦宝可梦，还有水属性的极光宝可\l"
	.string "梦。$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "告诉你个秘密！\p"
	.string "被亚希达称作开拓之脑的顶级训练家\n"
	.string "之一现在就在那里。\p"
	.string "那里就是由那个名叫金字塔法老的火\n"
	.string "热的训练家所掌管的。$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "你跟金字塔法老交过手了吗？\p"
	.string "他检验对手实力的时候，通常都会用\n"
	.string "这些宝可梦：\p"
	.string "岩石属性的岩山宝可梦，冰属性的冰\n"
	.string "山宝可梦，还有钢属性的黑金宝可梦\l"
	.string "。$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "你跟认真起来的金字塔法老交过手了\n"
	.string "吗？\p"
	.string "他的热情燃烧起来的时候，通常都会\n"
	.string "用这些宝可梦：\p"
	.string "冰和飞行属性的冰冻宝可梦，电和飞\n"
	.string "行属性的电击宝可梦，还有火和飞行\l"
	.string "属性的火焰宝可梦。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "确实，有些地方也可以进行双打对战\n"
	.string "，\p"
	.string "不过在对战塔的双打对战间里，这可\n"
	.string "是最基本的！\p"
	.string "你可以在那里学习如何在对战开拓区\n"
	.string "进行双打对战。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "在这里对战不要大意。\p"
	.string "听说有些训练家可是专门为了双打对\n"
	.string "战而培育宝可梦的。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "当你熟悉了这里的双打对战之后，就\n"
	.string "去试着挑战其他地方的双打对战吧。$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "对战沙龙里聚集了各种各样的训练家\n"
	.string "。\p"
	.string "想想吧——你可能会遇到你的朋友或\n"
	.string "粉丝！要好好注意周围啊！$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "如果遇到了朋友，就去多人连线对战\n"
	.string "间吧。\p"
	.string "有一个很厉害的朋友在旁边的话，就\n"
	.string "有可能碰上很强的对手！$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "收集消息好厉害！老师果然非同一般\n"
	.string "！$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "调查资料好厉害！老师果然非同一般\n"
	.string "！$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "说服别人好厉害！老师果然非同一般\n"
	.string "！$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "……这里是哪儿？好可怕……$"

