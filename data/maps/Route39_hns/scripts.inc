Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitfanfare
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "巴奥巴：我的天哪！刚才那个影子是\n"
	.string "宝可梦吗？\p"
	.string "你看清楚了吗？我都看不出它是什么\n"
	.string "颜色的……$"

Route39_Text_BaobaIntro::
	.string "真是不可思议……\p"
	.string "……哦哦！你拿着的那个\n"
	.string "……难道就是……\l"
	.string "宝可梦图鉴吗！\p"
	.string "我真是好久都没见过了。\p"
	.string "我叫巴奥巴！我以前在浅红市经营狩\n"
	.string "猎地带，但随着各种新娱乐项目的出\l"
	.string "现，那里逐渐落伍了。\p"
	.string "于是我决定远渡重洋学习最新技术，\n"
	.string "在湛蓝市开辟一个最尖端的狩猎地\l"
	.string "带！\p"
	.string "能在这里和你相遇聊上几句，这或许\n"
	.string "是命中注定的缘分呢。\p"
	.string "不如我们在宝可梦齿轮里交换一下电\n"
	.string "话号码吧？\p"
	.string "等狩猎地带开业的时候，我第一个就\n"
	.string "打电话通知你！$"

Route39_Text_Registered:
	.string "{PLAYER}将巴奥巴登记到了\n"
	.string "宝可梦齿轮！$"


Route39_Text_WillCall:
	.string "巴奥巴：到时候我会立刻用宝可梦齿\n"
	.string "轮联系你的！$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "刚才那个影子……难道是只\n"
	.string "巨大的波波？$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "大奶罐：哞--！$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "我刚回到浅黄市。\p"
	.string "来一场宝可梦对战怎么样？$"

Route39_Text_SailorEugeneBeaten:
	.string "哇啊啊啊！$"

Route39_Text_SailorEugeneAfter:
	.string "我的宝可梦全都是在海外捕获并培育\n"
	.string "的。\p"
	.string "它们是我漫长航海旅途中的伙伴。$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "正好是夸耀我的皮卡丘的好时机！$"

Route39_Text_PokefanMDerekBeaten:
	.string "我连展示皮卡丘的机会都没有...\n"
	.string "...$"

Route39_Text_PokefanMDerekAfter:
	.string "我才不听你的吹嘘呢！\p"
	.string "我们宝可梦发烧友的原则，就是绝不\n"
	.string "听别人自夸！$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "多么可爱的宝可梦啊。\p"
	.string "让我们同时亮出各自的宝可梦吧。$"

Route39_Text_PokefanFRuthBeaten:
	.string "输了也没关系啦。$"

Route39_Text_PokefanFRuthAfter:
	.string "你知道幼年宝可梦吗？\p"
	.string "它们肯定超级可爱！$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "让我见识一下你的宝可梦有几分本事\n"
	.string "吧。$"

Route39_Text_PsychicNormanBeaten:
	.string "哦，你的宝可梦很有潜力嘛。$"

Route39_Text_PsychicNormanAfter:
	.string "你知道宝可梦各自拥有不同的能力\n"
	.string "吧？\p"
	.string "其实人也是一样的。每个人都有不同\n"
	.string "的潜力。$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "你来得正是时候。\p"
	.string "来对战吧。$"

Route39_Text_PokefanFJaimeBeaten:
	.string "哎，真让人失望……$"

Route39_Text_PokefanFJaimeAfter:
	.string "我就是在夜里的这条39号道路上遇\n"
	.string "见月亮伊布的。\p"
	.string "虽然不知道为什么，但它似乎很喜欢\n"
	.string "我在这里特训呢。\p"
	.string "比起在其他地方，在这里特训好像能\n"
	.string "让它更亲近我呢。$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "39号道路\p"
	.string "浅黄市 - 圆朱市$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "哞哞牧场\p"
	.string "请品尝新鲜美味的牛奶$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "训练家心得\p"
	.string "对着树木使出头锤，就能把宝可梦摇\n"
	.string "下来。\p"
	.string "不同种类的宝可梦会从树上掉下来。\p"
	.string "看见树就尽管使出头锤吧！$"

Route39_Text_DerekRegister:
	.string "我才不听你的吹嘘呢！\p"
	.string "我们宝可梦发烧友的原则，就是绝不\n"
	.string "听别人自夸！$"

Route39_Text_DerekHasItem:
	.string "嘿！我刚刚带着皮卡丘到处炫耀时捡\n"
	.string "到了这个东西。\p"
	.string "给你，送你啦！$"

Route39_Text_DerekGaveItem:
	.string "皮卡丘就是最棒的！你也是这么觉得\n"
	.string "的吧？$"

Route39_Text_DerekNoRoom:
	.string "嗯，你的包包装满了。\p"
	.string "腾出地方再来找我吧。$"
