Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end
	
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "等等！急急忙忙的干什么去呀？$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "你是{PLAYER}对吧？刚才有\n"
	.string "个戴眼镜的男的\p"
	.string "一直在找你呢。\p"
	.string "你自己去瞧瞧吧。他正在宝可梦中心\n"
	.string "等你呢。$"

Route32_Text_CooltrainerM_SproutTower:
	.string "你去过喇叭芽之塔了吗？既然来到了\n"
	.string "桔梗市，\p"
	.string "大家都会期待你在那里修行呢。这对\n"
	.string "训练家来说可是基本功哦。\p"
	.string "快去喇叭芽之塔吧！$"

Route32_Text_CooltrainerM_VioletGym:
	.string "Have you gone to the POKéMON GYM?\n"
	.string "You can test your POKéMON and\p"
	.string "yourself there.\n"
	.string "It's a rite of passage for all\p"
	.string "trainers!$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "You have some good POKéMON there.\n"
	.string "It must be from the training you\p"
	.string "gave them around VIOLET CITY.\n"
	.string "The training at the GYM must have\p"
	.string "been especially helpful. As a\n"
	.string "souvenir of VIOLET CITY, take this.\p"
	.string "It increases the power of GRASS-\n"
	.string "type moves.$"

Route32_Text_CooltrainerM_Experiences:
	.string "在桔梗市积累的经验，一定会对你的\n"
	.string "旅程大有帮助的。$"

Route32_Text_SlowpokeTailOffer:
	.string "要不要来一根美味又有营养的呆呆兽\n"
	.string "之尾？\p"
	.string "现在算你的话，只要¥1,000,\n"
	.string "000！\p"
	.string "你肯定很想买吧！$"

Route32_Text_ThoughtKidsLoaded:
	.string "切！我还以为现在的小鬼都很有钱呢\n"
	.string "......$"

Route32_Text_RefusedSlowpokeTail:
	.string "不买？那就闪一边去。走走走！$"

Route32_Text_FisherJustin_Seen:
	.string "哇啊！\p"
	.string "你害我把上钩的鱼放跑了！$"

Route32_Text_FisherJustin_Beaten:
	.string "噗通！$"

Route32_Text_FisherJustin_After:
	.string "沉着、冷静......钓鱼和宝可\n"
	.string "梦对战的精髓是相通的。$"

Route32_Text_FisherRalph1_Seen:
	.string "不管是钓鱼还是宝可梦对战，我都非\n"
	.string "常拿手。\p"
	.string "我才不会输给毛头小孩呢！$"

Route32_Text_FisherRalph1_Beaten:
	.string "切！太操之过急了......$"

Route32_Text_FisherRalph1_After:
	.string "钓鱼是一生的热爱。\p"
	.string "宝可梦是一生的挚友！$"

Route32_Text_RalphRegister:
	.string "钓鱼是一生的热爱。\p"
	.string "宝可梦是一生的挚友！$"

Route32_Text_RalphRematchIntro:
	.string "不管是钓鱼还是宝可梦对战，我都非\n"
	.string "常拿手。\p"
	.string "我才不会输给毛头小孩呢！$"

Route32_Text_RalphRematchDefeat:
	.string "切！太操之过急了......$"

Route32_Text_RalphPostRematch:
	.string "钓鱼是一生的热爱。\p"
	.string "宝可梦是一生的挚友！$"

Route32_Text_FisherHenry_Seen:
	.string "我的宝可梦？刚钓上来的！$"

Route32_Text_FisherHenry_Beaten:
	.string "跃起？！$"

Route32_Text_FisherHenry_After:
	.string "Freshly caught POKéMON are\n"
	.string "no match for properly raised ones.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "I haven't seen you around before.\n"
	.string "So you think you are pretty tough?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "你好强！$"

Route32_Text_YoungsterAlbert_After:
	.string "我要带着自己最喜欢的宝可梦争当第\n"
	.string "一。\p"
	.string "我才不要和大家一样用那些千篇一律\n"
	.string "的强力宝可梦呢。$"

Route32_Text_YoungsterGordon_Seen:
	.string "我在草丛里抓到了挺不错的宝可梦！\p"
	.string "我觉得有它们在一定没问题！$"

Route32_Text_YoungsterGordon_Beaten:
	.string "可恶，我还以为能赢的。$"

Route32_Text_YoungsterGordon_After:
	.string "草丛里粘了好多甩不掉的草刺。$"

Route32_Text_CamperRoland_Seen:
	.string "刚才那个眼神......真让人在\n"
	.string "意啊。$"

Route32_Text_CamperRoland_Beaten:
	.string "唔......真让人扫兴。$"

Route32_Text_CamperRoland_After:
	.string "If you don't want to battle,\n"
	.string "just avoid eye contact.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Uh-huh. Yeah, and you know…\p"
	.string "Pardon? Battle? I'm on the phone.\n"
	.string "Oh, all right. But make it fast.$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "哎呀！气死我了，我得发泄一下！$"

Route32_Text_PicnickerLiz1_After:
	.string "我刚才明明聊得很开心呢。$"

Route32_Text_LizRegister:
	.string "我刚才明明聊得很开心呢。$"

Route32_Text_LizRematchIntro:
	.string "Uh-huh. Yeah, and you know…\p"
	.string "Pardon? Battle? I'm on the phone.\n"
	.string "Oh, all right. But make it fast.$"

Route32_Text_LizRematchDefeat:
	.string "哎呀！气死我了，我得发泄一下！$"

Route32_Text_LizPostRematch:
	.string "我刚才明明聊得很开心呢。$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "That BADGE! It's from VIOLET CITY!\n"
	.string "You beat FALKNER?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "我知道自己的弱点在哪了。$"

Route32_Text_BirdKeeperPeter_After:
	.string "我应该回桔梗市的道馆重新修行了。$"

Route32_Text_RoarIntro:
	.string "WROOOOAR! PEOPLE RUN WHEN I\n"
	.string "ROAR! BUT YOU CAME LOOKING!\p"
	.string "THAT PLEASES ME! NOW TAKE THIS!$"

Route32_Text_RoarOutro:
	.string "WROOOOAR! IT'S ROAR!\p"
	.string "EVEN POKéMON RUN FROM A GOOD\n"
	.string "ROAR!$"

Route32_Text_MeetFrieda:
	.string "FRIEDA: Yahoo!\p"
	.string "I'm FRIEDA of the WEEKDAY FAMILY!\n"
	.string "Nice to meet you!\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route32_Text_FriedaGivesGift:
	.string "Here's a POISON BARB for you!$"

Route32_Text_FriedaGaveGift:
	.string "金美：让学会毒属性招式的宝可梦携\n"
	.string "带吧。\p"
	.string "哇！\p"
	.string "超厉害的！\p"
	.string "毒属性招式的威力会强到让你大吃一\n"
	.string "惊哦！$"

Route32_Text_FriedaFriday:
	.string "金美：嗨！你喜欢星期几？\p"
	.string "我最喜欢星期五了！毫无疑问！\p"
	.string "你不觉得星期五很棒吗？$"

Route32_Text_FriedaNope:
	.string "金美：不是那个啦！$"

Route32_Text_Sign1:
	.string "32号道路\p"
	.string "桔梗市 - 桧皮镇$"

Route32_Text_Sign2:
	.string "阿露福遗迹东侧入口$"

Route32_Text_Sign3:
	.string "前方是互连洞$"
