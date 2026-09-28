SixIsland_PatternBush_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PatternBush_OnTransition
	.byte 0

SixIsland_PatternBush_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, SixIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, SixIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

SixIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 64, 10
	return

SixIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 45, 10
	return

SixIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, SixIsland_PatternBush_Text_BethanyIntro, SixIsland_PatternBush_Text_BethanyDefeat
	msgbox SixIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, SixIsland_PatternBush_Text_AllisonIntro, SixIsland_PatternBush_Text_AllisonDefeat
	msgbox SixIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, SixIsland_PatternBush_Text_GarretIntro, SixIsland_PatternBush_Text_GarretDefeat
	msgbox SixIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, SixIsland_PatternBush_Text_JonahIntro, SixIsland_PatternBush_Text_JonahDefeat
	msgbox SixIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, SixIsland_PatternBush_Text_VanceIntro, SixIsland_PatternBush_Text_VanceDefeat
	msgbox SixIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, SixIsland_PatternBush_Text_NashIntro, SixIsland_PatternBush_Text_NashDefeat
	msgbox SixIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, SixIsland_PatternBush_Text_CordellIntro, SixIsland_PatternBush_Text_CordellDefeat
	msgbox SixIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, SixIsland_PatternBush_Text_DaliaIntro, SixIsland_PatternBush_Text_DaliaDefeat
	msgbox SixIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, SixIsland_PatternBush_Text_JoanaIntro, SixIsland_PatternBush_Text_JoanaDefeat
	msgbox SixIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, SixIsland_PatternBush_Text_RileyIntro, SixIsland_PatternBush_Text_RileyDefeat
	msgbox SixIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, SixIsland_PatternBush_Text_MarcyIntro, SixIsland_PatternBush_Text_MarcyDefeat
	msgbox SixIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, SixIsland_PatternBush_Text_LaytonIntro, SixIsland_PatternBush_Text_LaytonDefeat
	msgbox SixIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_Text_BethanyIntro::
	.string "我很好奇，你是如何养育宝可梦的？$"

SixIsland_PatternBush_Text_BethanyDefeat::
	.string "你用了全身心的爱来养育你的宝可梦\n"
	.string "！$"

SixIsland_PatternBush_Text_BethanyPostBattle::
	.string "要像你妈妈充满着爱养育你那样，养\n"
	.string "育好你的宝可梦。$"

SixIsland_PatternBush_Text_AllisonIntro::
	.string "我为了维护宝可梦的自然生态环境在\n"
	.string "这里努力工作。$"

SixIsland_PatternBush_Text_AllisonDefeat::
	.string "作为一个如此年轻的人，你真是太棒\n"
	.string "了！$"

SixIsland_PatternBush_Text_AllisonPostBattle::
	.string "我没有不准许人们收服宝可梦。\p"
	.string "我只是希望人们能好好培育它们。$"

SixIsland_PatternBush_Text_GarretIntro::
	.string "我收服了一只只生活在这周围的虫属\n"
	.string "性宝可梦！$"

SixIsland_PatternBush_Text_GarretDefeat::
	.string "哈哈……我的宝可梦是不是很棒？$"

SixIsland_PatternBush_Text_GarretPostBattle::
	.string "树林旁边的有个女孩替训练家测量他\n"
	.string "们的的赫拉克罗斯。$"

SixIsland_PatternBush_Text_JonahIntro::
	.string "你知道么，如果我不使用虫属性宝可\n"
	.string "梦，我就感觉浑身不对劲。$"

SixIsland_PatternBush_Text_JonahDefeat::
	.string "无所谓啦，战败也是宝可梦的吸引力\n"
	.string "之一。$"

SixIsland_PatternBush_Text_JonahPostBattle::
	.string "顺便说一下，“吸引力”像是一个奇\n"
	.string "怪的单词。\p"
	.string "就像是，它像一个橘子皮？或者像一\n"
	.string "个电铃？$"

SixIsland_PatternBush_Text_VanceIntro::
	.string "看看瞧瞧！看看这些虫属性宝可梦！$"

SixIsland_PatternBush_Text_VanceDefeat::
	.string "当我忙于庆祝时，我被袭击了！$"

SixIsland_PatternBush_Text_VancePostBattle::
	.string "我下次会把我弟弟带到这儿来。$"

SixIsland_PatternBush_Text_NashIntro::
	.string "快看！地上有一些有趣的花纹。$"

SixIsland_PatternBush_Text_NashDefeat::
	.string "超级棒！$"

SixIsland_PatternBush_Text_NashPostBattle::
	.string "地上这些有趣的花纹……\p"
	.string "和我奶奶衣服上的很像。$"

SixIsland_PatternBush_Text_CordellIntro::
	.string "我打赌，你认为我只是一个路人，对\n"
	.string "吗？嗯？$"

SixIsland_PatternBush_Text_CordellDefeat::
	.string "我打赌，你认为我很弱，对吗？嗯？$"

SixIsland_PatternBush_Text_CordellPostBattle::
	.string "你们城里人都穿得那么奢华还戴个花\n"
	.string "哨的帽子……\p"
	.string "把那个给我如何？$"

SixIsland_PatternBush_Text_DaliaIntro::
	.string "请深呼吸。空气很是清新怡人吧？$"

SixIsland_PatternBush_Text_DaliaDefeat::
	.string "如果你喜欢，我能教你怎样正确地呼\n"
	.string "吸。$"

SixIsland_PatternBush_Text_DaliaPostBattle::
	.string "首先，呼气。把所有的废气吐出。\p"
	.string "当你呼气到极限的时候，吸入新鲜空\n"
	.string "气！\p"
	.string "是不是有一种焕然一新的感觉？$"

SixIsland_PatternBush_Text_JoanaIntro::
	.string "我喜欢虫属性宝可梦。所以我一直都\n"
	.string "在这儿。\p"
	.string "我就是这样一个独一无二的女孩吗？$"

SixIsland_PatternBush_Text_JoanaDefeat::
	.string "我输了，但我依然很开心。我是唯一\n"
	.string "会这样的女孩吗？$"

SixIsland_PatternBush_Text_JoanaPostBattle::
	.string "我将继续收集虫属性宝可梦。\p"
	.string "我是唯一会这样的女孩吗？$"

SixIsland_PatternBush_Text_RileyIntro::
	.string "这是一个不错的地方。我要在这里扎\n"
	.string "营。$"

SixIsland_PatternBush_Text_RileyDefeat::
	.string "我真是没用……$"

SixIsland_PatternBush_Text_RileyPostBattle::
	.string "我要在这里观察夜晚的星空。$"

SixIsland_PatternBush_Text_MarcyIntro::
	.string "啊，讨厌！我感觉有个虫子蜇了我！$"

SixIsland_PatternBush_Text_MarcyDefeat::
	.string "那不是虫子。是我的小腿被草割伤了\n"
	.string "。$"

SixIsland_PatternBush_Text_MarcyPostBattle::
	.string "这样的小伤口……我弄一点唾沫就能\n"
	.string "治好它！$"

SixIsland_PatternBush_Text_LaytonIntro::
	.string "这周围有些奇怪，你注意到了吗？$"

SixIsland_PatternBush_Text_LaytonDefeat::
	.string "你好好观察过你周围了吗？$"

SixIsland_PatternBush_Text_LaytonPostBattle::
	.string "在标志之林周围有个寸草不生的地方\p"
	.string "是东西什么造成了这种现象？$"

