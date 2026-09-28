Route27_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	setspeaker Route27_Text_BaobaName
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_Text_BaobaName:
	.string "巴奥巴$"

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    setflag FLAG_VISITED_KANTO
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
    
    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_DragonClaw::
    finditem ITEM_TM_DRAGON_CLAW
    end

Route27_EventScript_Item_Destiny_Knot::
    finditem ITEM_DESTINY_KNOT
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE_HNS, Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN_HNS, Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA_HNS, Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten, Route27_EventScript_RegisterReena
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchReena
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterReena::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_ReenaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_REENA_HNS
	release
	end

Route27_EventScript_RematchReena::
	trainerbattle_rematch TRAINER_REENA_HNS, Route27_Text_ReenaRematchIntro, Route27_Text_ReenaRematchDefeat
	msgbox Route27_Text_ReenaPostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN_HNS, Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT_HNS, Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE_HNS, Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten, Route27_EventScript_RegisterJose
	goto_if_set FLAG_JOSE_HAS_ITEM_HNS, Route27_EventScript_JoseGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchJose
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterJose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_JoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOSE_HNS
	release
	end

Route27_EventScript_RematchJose::
	trainerbattle_rematch TRAINER_JOSE_HNS, Route27_Text_JoseRematchIntro, Route27_Text_JoseRematchDefeat
	msgbox Route27_Text_JosePostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseGiveItem::
	msgbox Route27_Text_JoseHasItem, MSGBOX_DEFAULT
	giveitem VAR_JOSE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route27_EventScript_JoseNoRoom
	clearflag FLAG_JOSE_HAS_ITEM_HNS
	msgbox Route27_Text_JoseGaveItem, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseNoRoom::
	msgbox Route27_Text_JoseNoRoom, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT_HNS, Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
    .string "喂！$"

Route27_Text_FisherMessage:
    .string "知道你刚刚做了什么吗？\p"
    .string "你已经踏进关都了！\p"
    .string "打开宝可梦齿轮的地图看看吧。$"

Route27_Text_CooltrainermBlakeSeen:
    .string "你看上去挺强的嘛。来和我对战一场\n"
    .string "吧！$"

Route27_Text_CooltrainermBlakeBeaten:
    .string "哇啊！$"

Route27_Text_CooltrainermBlakeAfter:
    .string "若你能挺过这严酷的旅程，真相终将\n"
    .string "大白！\p"
    .string "嘿嘿，不好意思，我只是想说句帅气\n"
    .string "的话而已。$"

Route27_Text_CooltrainermBrianSeen:
    .string "嗯？你挺厉害的嘛？$"

Route27_Text_CooltrainermBrianBeaten:
    .string "果然不出我所料！$"

Route27_Text_CooltrainermBrianAfter:
    .string "优秀的训练家一眼就能看出对方是不\n"
    .string "是顶尖高手。$"

Route27_Text_CooltrainerfReenaSeen:
    .string "你可千万别小看这一带的野生宝可梦\n"
    .string "啊。$"

Route27_Text_CooltrainerfReenaBeaten:
    .string "哎呀！你也太强了吧！$"

Route27_Text_CooltrainerfReenaAfter:
    .string "虽然你年纪还小，但也绝对是个不可\n"
    .string "小觑的对手啊。$"

Route27_Text_ReenaRegister:
    .string "虽然你年纪还小，但也绝对是个不可\n"
    .string "小觑的对手啊。$"

Route27_Text_ReenaRematchIntro:
    .string "你可千万别小看这一带的野生宝可梦\n"
    .string "啊。$"

Route27_Text_ReenaRematchDefeat:
    .string "哎呀！你也太强了吧！$"

Route27_Text_ReenaPostRematch:
    .string "虽然你年纪还小，但也绝对是个不可\n"
    .string "小觑的对手啊。$"

Route27_Text_CooltrainerfMeganSeen:
    .string "真少见有人会来这里呢。\p"
    .string "你是一个人在这里特训吗？$"

Route27_Text_CooltrainerfMeganBeaten:
    .string "哇！你真的好强！$"

Route27_Text_CooltrainerfMeganAfter:
    .string "我正在观察宝可梦进化前后的区别。\p"
    .string "进化确实能让宝可梦变得更强，\p"
    .string "但进化之后的宝可梦学会招式的等级\n"
    .string "也会变晚呢。$"

Route27_Text_PsychicGilbertSeen:
    .string "什么都别说！\p"
    .string "让我来猜猜你在想什么。\p"
    .string "嗯----......\p"
    .string "我知道了！你正在挑战宝可梦联盟吧\n"
    .string "！$"

Route27_Text_PsychicGilbertBeaten:
    .string "你也太强了吧！$"

Route27_Text_PsychicGilbertAfter:
    .string "凭你的实力，在联盟一定能大放异彩\n"
    .string "。\p"
    .string "我的预知就是这么说的。$"

Route27_Text_BirdKeeperJoseSeen:
    .string "啾！啾！啾啾啾！$"

Route27_Text_BirdKeeperJoseBeaten:
    .string "啾！$"

Route27_Text_BirdKeeperJoseAfter:
    .string "像我们养鸟人都是通过模仿真鸟鸣声\n"
    .string "来指挥宝可梦的。$"

Route27_Text_JoseRegister:
    .string "像我们养鸟人都是通过模仿真鸟鸣声\n"
    .string "来指挥宝可梦的。$"

Route27_Text_JoseRematchIntro:
    .string "啾！啾！啾啾啾！$"

Route27_Text_JoseRematchDefeat:
    .string "啾！$"

Route27_Text_JosePostRematch:
    .string "像我们养鸟人都是通过模仿真鸟鸣声\n"
    .string "来指挥宝可梦的。$"

Route27_Text_JoseHasItem:
    .string "嗨！我刚才观鸟的时候捡到了一个闪\n"
    .string "闪发亮的东西！\p"
    .string "喏，送给你吧！$"

Route27_Text_JoseGaveItem:
    .string "我在27号道路上总能捡到各种东西\n"
    .string "。\p"
    .string "要是再发现什么好东西，我会通知你\n"
    .string "的！$"

Route27_Text_JoseNoRoom:
    .string "嗯，你的包包装满了。\p"
    .string "腾出地方再来找我吧。$"

TohjoFalls_Text_Sign:
    .string "都城瀑布\p"
    .string "连接关都与城都之瀑布$"

Route27_Text_FisherScottSeen:
    .string "我今天状态绝佳！\p"
    .string "感觉就算是联盟冠军我也能一脚踹翻\n"
    .string "！$"

Route27_Text_FisherScottBeaten:
    .string "怎么会！居然输在这场对战！$"

Route27_Text_FisherScottAfter:
    .string "和钓鱼一样，宝可梦对战中一旦放弃\n"
    .string "就彻底完了。$"
