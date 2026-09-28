LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE_HNS
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_HNS
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
    .string "{PLAYER}。\p"
    .string "即使是在这里，严寒也能让我保持清\n"
    .string "醒。\p"
    .string "如果你想再次对战，就来格斗道场找\n"
    .string "我吧。$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE_HNS, LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND_HNS, LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON_HNS, LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS_HNS, LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Secret_Power::
    finditem ITEM_TM_SECRET_POWER
    end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "快龙：嘎吼--！$"

LakeOfRage_Text_LanceForcedToEvolve:
    .string "这座湖里除了暴鲤龙就再没有别的宝\n"
    .string "可梦了......\p"
    .string "看来是鲤鱼王被强迫进化了啊...\n"
    .string "...$"

LakeOfRage_Text_LanceIntro1:
    .string "你也是因为听到了传闻才来这里的吗\n"
    .string "？\p"
    .string "你是{PLAYER}？我是阿渡，\n"
    .string "和你一样是个宝可梦训练家。$"

LakeOfRage_Text_LanceIntro2:
    .string "这位男士把传闻告诉了我。\p"
    .string "所以我们才来调查一番......$"

LakeOfRage_Text_LanceIntro3:
    .string "{PLAYER}，我刚才看到你战\n"
    .string "斗的样子了。\p"
    .string "看得出来，你是个身手相当了得的训\n"
    .string "练家。\p"
    .string "如果你不介意的话，能协助我们一起\n"
    .string "调查吗？$"

LakeOfRage_Text_LanceRadioSignal:
    .string "阿渡：太好了！\p"
    .string "看来愤怒之湖的鲤鱼王是被强行促使\n"
    .string "进化的。\p"
    .string "罪魁祸首是来自卡吉镇的神秘电波。\p"
    .string "我们在那里等你，{PLAYER}\n"
    .string "。$"

LakeOfRage_Text_LanceRefused:
    .string "这样啊......好吧，如果你改\n"
    .string "变了主意，请一定要来帮帮我们。$"

LakeOfRage_Text_LanceAskHelp:
    .string "阿渡：嗯？你决定来帮我们了吗？$"

LakeOfRage_Text_GyaradosCry:
    .string "暴鲤龙：吼嗷--！$"

LakeOfRage_Text_Gramps:
    .string "暴鲤龙们发怒了！\p"
    .string "这是不祥的凶兆啊！$"

LakeOfRage_Text_GrampsCleared:
    .string "哈哈！鲤鱼王上钩啦！$"

LakeOfRage_Text_SuperNerd:
    .string "听说这个湖是以前暴怒的暴鲤龙群冲\n"
    .string "撞形成的。\p"
    .string "不知道和现在暴鲤龙大量出现有没有\n"
    .string "什么关联呢？$"

LakeOfRage_Text_CooltrainerF:
    .string "我眼花了吗？我刚才在湖里看到了一\n"
    .string "只红色的暴鲤龙......\p"
    .string "可是暴鲤龙通常不都是蓝色的吗？$"


LakeOfRage_Text_FisherAndreSeen:
    .string "用我刚钓上来的宝可梦跟你对战吧！$"

LakeOfRage_Text_FisherAndreBeaten:
    .string "我也许是个钓鱼高手，但作为宝可梦\n"
    .string "训练家还差得远呢......$"

LakeOfRage_Text_FisherAndreAfter:
    .string "作为钓客我可不会输！我成天都在钓\n"
    .string "宝可梦呢。$"


LakeOfRage_Text_FisherRaymondSeen:
    .string "不管怎么钓，上钩的都是同一种宝可\n"
    .string "梦啊......$"

LakeOfRage_Text_FisherRaymondBeaten:
    .string "我的鱼线全缠在一起了......$"

LakeOfRage_Text_FisherRaymondAfter:
    .string "为什么我就钓不到厉害的宝可梦呢？$"

LakeOfRage_Text_CooltrainermAaronSeen:
    .string "只要目光相撞，训练家之间就必须展\n"
    .string "开对战。\p"
    .string "这就是我们的宿命。$"

LakeOfRage_Text_CooltrainermAaronBeaten:
    .string "呼......精彩的对战。$"

LakeOfRage_Text_CooltrainermAaronAfter:
    .string "宝可梦和训练家是在不断战斗中变得\n"
    .string "强大的。$"

LakeOfRage_Text_CooltrainerfLoisSeen:
    .string "那只红色的暴鲤龙怎么了？\p"
    .string "已经不在了吗？\p"
    .string "哎呀，真倒霉。那我岂不是白跑一趟\n"
    .string "了？\p"
    .string "有了--来对战吧！$"

LakeOfRage_Text_CooltrainerfLoisBeaten:
    .string "真有一手！$"

LakeOfRage_Text_CooltrainerfLoisAfter:
    .string "话说回来，我以前还见过粉红色的巴\n"
    .string "大蝶呢。$"



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
    .string "卫利：哎呀，你好啊！\p"
    .string "我是星期兄弟姐妹中的一员！你能猜\n"
    .string "到我最喜欢哪一天吗？$"

LakeOfRage_Text_WesleyGivesGift:
    .string "很高兴认识你。请收下这个纪念品吧\n"
    .string "。$"

LakeOfRage_Text_WesleyGaveGift:
    .string "卫利：黑带可以增强格斗属性招式的\n"
    .string "威力。$"

LakeOfRage_Text_WesleyWednesday:
    .string "卫利：既然你能找到我，一定已经见\n"
    .string "过我的兄弟姐妹了吧。\p"
    .string "还是说，你只是运气好碰巧撞上的？$"

LakeOfRage_Text_WesleyNotWednesday:
    .string "卫斯：倒也不是这样......$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
    .string "LAKE OF RAGE,\n"
    .string "also known as GYARADOS LAKE.$"

LakeOfRage_Text_FishingGuruSign:
    .string "钓鱼大叔的家$"
