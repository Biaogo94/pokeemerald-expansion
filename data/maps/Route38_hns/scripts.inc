Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "向着天空高高飞翔吧，我心爱的鸟宝\n"
	.string "可梦！$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "现在我也想直接飞走算了。$"

Route38_Text_BirdKeeperTobyAfter:
	.string "我打算去湛蓝市修行，去教会我的宝\n"
	.string "可梦“飞翔”。$"

Route38_Text_SchoolboyChad1Seen:
	.string "让我来试试今天学到的东西吧。$"

Route38_Text_SchoolboyChad1Beaten:
	.string "看来我的学习还不够充分啊。$"

Route38_Text_SchoolboyChadAfter:
	.string "我得应付好多考试，所以没有太多时\n"
	.string "间留给宝可梦。\p"
	.string "因此每次有机会玩的时候，我都格外\n"
	.string "专注。$"

Route38_Text_ChadRegister:
	.string "我得应付好多考试，所以没有太多时\n"
	.string "间留给宝可梦。\p"
	.string "因此每次有机会玩的时候，我都格外\n"
	.string "专注。$"

Route38_Text_ChadRematchIntro:
	.string "让我来试试今天学到的东西吧。$"

Route38_Text_ChadRematchDefeat:
	.string "看来我的学习还不够充分啊。$"

Route38_Text_ChadPostRematch:
	.string "我得应付好多考试，所以没有太多时\n"
	.string "间留给宝可梦。\p"
	.string "因此每次有机会玩的时候，我都格外\n"
	.string "专注。$"

Route38_Text_LassDana1Seen:
	.string "你好像很擅长宝可梦对战呢。\p"
	.string "既然如此，能不能给我点建议呀？$"

Route38_Text_LassDana1Beaten:
	.string "原来如此。也可以用那种方式战斗\n"
	.string "呀。$"

Route38_Text_LassDanaAfter:
	.string "我知道一件好事哦！\p"
	.string "哞哞牧场的鲜奶可是出了名的美味。$"

Route38_Text_BeautyValerieSeen:
	.string "你好！你可真是个可爱的小训练家！\p"
	.string "能让我看看你的宝可梦吗？$"

Route38_Text_BeautyValerieBeaten:
	.string "能看到你的宝可梦，我真高兴！$"

Route38_Text_BeautyValerieAfter:
	.string "看到宝可梦，感觉心情都放松下来\n"
	.string "了。$"

Route38_Text_SailorHarrySeen:
	.string "我去过国外，所以认识各种各样的宝\n"
	.string "可梦哦！$"

Route38_Text_SailorHarryBeaten:
	.string "你的实力堪称世界级！$"

Route38_Text_SailorHarryAfter:
	.string "全世界形形色色的人们都与宝可梦快\n"
	.string "乐地生活在一起。$"

Route38_Text_BeautyOliviaSeen:
	.string "你不觉得我和我的宝可梦都很美吗？$"

Route38_Text_BeautyOliviaBeaten:
	.string "我们每天都喝哞哞鲜奶呢。$"

Route38_Text_BeautyOliviaAfter:
	.string "哞哞鲜奶不仅美容还对健康有益，\p"
	.string "不过不太方便的是，他们一次只卖一\n"
	.string "瓶。$"

Route38_Text_Sign:
	.string "38号道路\p"
	.string "浅黄市 - 圆朱市$"

Route38_Text_TrainerTips:
	.string "宝可梦指南\p"
	.string "宝可梦开始进化时是可以阻止它的。\p"
	.string "在进化过程中按下B键就能取消进\n"
	.string "化。\p"
	.string "宝可梦会吓一跳并停止进化。$"


Route38_Text_WaterSign:
	.string "禁止游泳与垂钓。本水域仅供农业灌\n"
	.string "溉使用。\p"
	.string "--圆朱市管理委员会$"

Route38_Text_DanaRegister:
	.string "我知道一件好事哦！\p"
	.string "哞哞牧场的鲜奶可是出了名的美味。$"

Route38_Text_DanaRematchIntro:
	.string "你好像很擅长宝可梦对战呢。\p"
	.string "既然如此，能不能给我点建议呀？$"

Route38_Text_DanaRematchDefeat:
	.string "原来如此。也可以用那种方式战斗\n"
	.string "呀。$"

Route38_Text_DanaPostRematch:
	.string "我知道一件好事哦！\p"
	.string "哞哞牧场的鲜奶可是出了名的美味。$"

Route38_Text_DanaHasItem:
	.string "喂！我发现了好玩的东西！\p"
	.string "诺，这个送给你！$"

Route38_Text_DanaGaveItem:
	.string "如果再找到别的东西，我还会通知你\n"
	.string "的！$"

Route38_Text_DanaNoRoom:
	.string "嗯，你的包包装满了。\p"
	.string "腾出地方再来找我吧。$"
