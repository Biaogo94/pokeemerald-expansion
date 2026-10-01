ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
	.string "我和朋友们来这里收服虫属性的宝可\n"
	.string "梦。\p"
	.string "他们都渴望用自己的宝可梦去战斗！$"

ViridianForest_Text_RickIntro::
	.string "嘿！你有宝可梦啊！来吧！我们对\n"
	.string "战！$"

ViridianForest_Text_RickDefeat::
	.string "不！绿毛虫根本打不过它！$"

ViridianForest_Text_RickPostBattle::
	.string "嘘！你这样会把虫子吓跑的。下次再\n"
	.string "来打一场，怎么样？$"

ViridianForest_Text_DougIntro::
	.string "嗨！如果你是一个宝可梦训练家，就\n"
	.string "不能大意！$"

ViridianForest_Text_DougDefeat::
	.string "啥？我的宝可梦全倒下了！$"

ViridianForest_Text_DougPostBattle::
	.string "太糟了！我要去抓些更强大的！$"

ViridianForest_Text_SammyIntro::
	.string "嘿！等一下！怎么了？你跑这么快干\n"
	.string "嘛？$"

ViridianForest_Text_SammyDefeat::
	.string "我服了！你的确很强！$"

ViridianForest_Text_SammyPostBattle::
	.string "有的时候，你能找到一些掉在地上的\n"
	.string "东西。\p"
	.string "我正在找我掉了的东西。你能帮我找\n"
	.string "找吗？$"

ViridianForest_Text_AnthonyIntro::
	.string "我身材可能很矮小，但我可不希望你\n"
	.string "因此对我手下留情！$"

ViridianForest_Text_AnthonyDefeat::
	.string "唉，真不好。完全没照我的计划来。$"

ViridianForest_Text_AnthonyPostBattle::
	.string "我弄丢了一些零用钱……$"

ViridianForest_Text_CharlieIntro::
	.string "宝可梦的进化你知道多少？$"

ViridianForest_Text_CharlieDefeat::
	.string "噢！我输了！$"

ViridianForest_Text_CharliePostBattle::
	.string "虫属性宝可梦进化得很快。和它们在\n"
	.string "一起乐趣多多！$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "为了收服宝可梦我把精灵球都用光\n"
	.string "了。\p"
	.string "所以你需要常备一些精灵球在身边。$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "训练家贴士\p"
	.string "如果你的宝可梦很虚弱，而且你不想\n"
	.string "进行无谓的战斗的话，那么就避开草\l"
	.string "地吧！$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "如果中毒了，就用解毒药！你可以在\n"
	.string "宝可梦商店里买到！$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
	.string "训练家贴士\p"
	.string "通过电脑联系大木博士，让他给你的\n"
	.string "宝可梦图鉴做个评价！$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "训练家贴士\p"
	.string "你不可以收服别人的宝可梦。\p"
	.string "只有对野生的宝可梦才能用精灵球收\n"
	.string "服！$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "训练家贴士\p"
	.string "在收服宝可梦之前先削弱它们的体\n"
	.string "力！\p"
	.string "它们精力充沛时可能会逃跑！$"

ViridianForest_Text_LeavingViridianForest::
	.string "走出常青森林后深灰市就在前面$"

