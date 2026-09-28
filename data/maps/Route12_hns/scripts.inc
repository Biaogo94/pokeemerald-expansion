Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KYLE_2_HNS, Route12_EventScript_RematchKyleTryGiveItem
	end

Route12_EventScript_RematchKyleTryGiveItem::
	checkitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_BLUE_SHARD
	closemessage
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Magikarp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route12_Text_Magikarp, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_Magikarp:
	.string "鲤鱼王：咔噜--。$"

Route12_Text_NewFisher:
	.string "小心点，这片水域里可是生活着很凶\n"
	.string "暴的家伙。$"

Route12_Text_FisherMartinSeen:
	.string "无论是钓鱼还是培育宝可梦，耐心都\n"
	.string "是最关键的秘诀。$"

Route12_Text_FisherMartinBeaten:
	.string "哇啊--！$"

Route12_Text_FisherMartinAfterBattle:
	.string "我太性急了，果然不适合钓鱼...\n"
	.string "...$"

Route12_Text_FisherStephenSeen:
	.string "一边用收音机听着音乐，一边悠闲地\n"
	.string "钓鱼，真是太惬意了。$"

Route12_Text_FisherStephenBeaten:
	.string "都是这破收音机让我分心了！$"

Route12_Text_FisherStephenAfterBattle:
	.string "你收听过关都的广播节目吗？这里的\n"
	.string "节目类型可丰富了。$"

Route12_Text_FisherBarneySeen:
	.string "在我们日常生活中，最重要的东西是\n"
	.string "什么？$"

Route12_Text_FisherBarneyBeaten:
	.string "答案马上揭晓！$"

Route12_Text_FisherBarneyAfterBattle:
	.string "我觉得电力才是我们日常生活中最重\n"
	.string "要的东西。\p"
	.string "如果不是这样，之前发电厂发生故障\n"
	.string "停运的时候，大家也不会闹得那么沸\l"
	.string "沸扬扬了。$"

Route12_Text_KyleRegister:
	.string "我记住你了。把你的电话号码告诉我\n"
	.string "吧！$"

Route12_Text_KyleRematchIntro:
	.string "你忘了吗？让我瞧瞧！$"

Route12_Text_KyleRematchDefeat:
	.string "原来你还记得啊。$"

Route12_Text_KylePostRematch:
	.string "对战带来的刺激感，完全不亚于钓到\n"
	.string "大鱼呢！$"

Route12_Text_FisherKyleSeen:
	.string "你还记得吗？$"

Route12_Text_FisherKyleBeaten:
	.string "你真的记得吗？$"

Route12_Text_FisherKyleAfterBattle:
	.string "当宝可梦咬钩时，鱼竿上传来的那股\n"
	.string "拉力......\p"
	.string "对我们钓客来说，简直是世界上最棒\n"
	.string "的感觉了。$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "12号道路\p"
	.string "北至紫苑镇$"

Route12_Text_FishingSpotSign:
	.string "垂钓圣地$"

