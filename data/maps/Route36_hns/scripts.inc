Route36_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK_HNS, Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN_HNS, Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten, Route36_EventScript_RegisterAlan
	goto_if_set FLAG_ALAN_HAS_ITEM_HNS, Route36_EventScript_AlanGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RematchAlan
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_RegisterAlan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route36_Text_AlanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALAN_HNS
	release
	end

Route36_EventScript_RematchAlan::
	trainerbattle_rematch TRAINER_ALAN_HNS, Route36_Text_AlanRematchIntro, Route36_Text_AlanRematchDefeat
	msgbox Route36_Text_AlanPostRematch, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanGiveItem::
	msgbox Route36_Text_AlanHasItem, MSGBOX_DEFAULT
	giveitem VAR_ALAN_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route36_EventScript_AlanNoRoom
	clearflag FLAG_ALAN_HAS_ITEM_HNS
	msgbox Route36_Text_AlanGaveItem, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanNoRoom::
	msgbox Route36_Text_AlanNoRoom, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "要使用杰尼龟喷壶吗？$"

Route36_Text_UsedSquirtbottle:
	.string "{PLAYER}使用了杰尼龟喷\n"
	.string "壶。$"

Route36_Text_SudowoodoAttacked:
	.string "奇怪的树好像很讨厌杰尼龟喷壶！\p"
	.string "奇怪的树袭击过来了！$"

Route36_Text_RockSmashGuy1:
	.string "哇啊！\p"
	.string "本想用我的直拳把那棵树给打断的。\p"
	.string "可我居然做不到！真是太失败了！$"

Route36_Text_RockSmashGuy2:
	.string "你把那棵讨厌的树搞定了吗？\p"
	.string "真令人佩服！这个就送给你吧。$"

Route36_Text_RockSmashGuy3:
	.string "那正是招式“碎岩”。\p"
	.string "只要看准了用力一击，就能把岩石打\n"
	.string "得粉碎。\p"
	.string "要是有岩石挡路，就尽管把它砸碎\n"
	.string "吧！$"

Route36_Text_OddTree:
	.string "一棵奇怪的树挡住了去路。$"

Route36_Text_Lass1:
	.string "晚上走这条路可要当心！\p"
	.string "我看到过一只长得像卡蒂狗的宝可\n"
	.string "梦，但它身上散发着非常恐怖的气\l"
	.string "息。$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "那棵奇怪的树消失得无影无踪了。\p"
	.string "咦！原来那棵树其实是宝可梦吗？$"

Route36_Text_PsychicMarkSeen:
	.string "我要读取你的心思！$"

Route36_Text_PsychicMarkBeaten:
	.string "居然读错了吗！$"

Route36_Text_PsychicMarkAfter:
	.string "要是能看透对手的心思，我就能所向\n"
	.string "披靡了。$"

Route36_Text_SchoolboyAlan1Seen:
	.string "经过刻苦用功，我对付什么宝可梦都\n"
	.string "胸有成竹！$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "糟糕！计算失误了吗？$"

Route36_Text_SchoolboyAlanAfter:
	.string "可恶，我明明每天苦读五个小时呢。\p"
	.string "看来光死读书还是远远不够的啊。$"

Route36_Text_MeetArthur:
	.string "阿木：你是谁？我是星期家族的阿\n"
	.string "木。\p"
	.string "要是你能猜出我最喜欢星期几，我就\n"
	.string "送你一件礼物。$"

Route36_Text_ArthurNope:
	.string "不对哦！$"

Route36_Text_ArthurGivesGift:
	.string "给，这个送给你。$"

Route36_Text_ArthurGaveGift:
	.string "阿木：让擅长使用岩石属性招式的宝\n"
	.string "可梦携带它吧。\p"
	.string "它能提升岩石属性招式的威力。$"

Route36_Text_ArthurThursday:
	.string "阿木：我是星期四的阿木。在七兄妹\n"
	.string "里排行老五。$"

Route36_Text_Sign:
	.string "36号道路$"

Route36_Text_Sign_RuinsNorth:
	.string "阿露福遗迹北侧入口$"

Route36_Text_Tips1:
	.string "宝可梦指南即便是同一种宝可梦，能\n"
	.string "力值也会有所不同。\p"
	.string "起初它们的能力可能相差无几。\p"
	.string "然而，随着宝可梦的成长，彼此间的\n"
	.string "差异会变得越发明显。$"

Route36_Text_Tips2:
	.string "宝可梦指南使用“挖洞”可以瞬间回到\n"
	.string "任何地方的入口。\p"
	.string "在探索洞窟等迷宫时非常方便。$"

Route36_Text_AlanRegister:
	.string "可恶，我明明每天苦读五个小时呢。\p"
	.string "看来光死读书还是远远不够的啊。$"

Route36_Text_AlanRematchIntro:
	.string "经过刻苦用功，我对付什么宝可梦都\n"
	.string "胸有成竹！$"

Route36_Text_AlanRematchDefeat:
	.string "糟糕！计算失误了吗？$"

Route36_Text_AlanPostRematch:
	.string "可恶，我明明每天苦读五个小时呢。\p"
	.string "看来光死读书还是远远不够的啊。$"

Route36_Text_AlanHasItem:
	.string "嘿！我在学习的时候捡到了这个！\p"
	.string "来，送给你吧！$"

Route36_Text_AlanGaveItem:
	.string "如果再找到别的东西，我还会通知你\n"
	.string "的！$"

Route36_Text_AlanNoRoom:
	.string "嗯，你的背包装满了。\p"
	.string "腾出地方再来找我吧。$"
