DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}……原来\n"
    .string "你在这里。\p"
    .string "觉得自己能跟得上我的话，就来金黄\n"
    .string "市的格斗道场吧。$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
    .string "小椿：等一下！\p"
    .string "刚才真是不好意思。呐，这个就当作\n"
    .string "是我的赔礼吧。$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
    .string "龙之波动就是一种呃……算\n"
    .string "了！\p"
    .string "总之就是某种强大的能量啦。\p"
    .string "你要是不想要的话，不拿也可以！$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "怎么啦？你不去宝可梦联盟吗？\p"
    .string "成为冠军之后，你可以找任何你想挑\n"
    .string "战的馆主再战。\p"
    .string "快去宝可梦联盟吧。\p"
    .string "你知道怎么去吗？\p"
    .string "从这里出发，先回到若叶镇。\p"
    .string "然后冲浪向东前往宝可梦联盟。\p"
    .string "去那里的路可是非常艰难的。\p"
    .string "你可千万别在宝可梦联盟输掉啊！\p"
    .string "要是输了，输给你的我岂不是更丢人\n"
    .string "！\p"
    .string "给我使出全力上吧！$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "龙之祠堂\p"
    .string "供奉着传说中曾经\p"
    .string "居住在龙穴的龙属性宝可梦。$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "……什么？是\n"
    .string "{PLAYER}吗？\p"
    .string "……算了，我现在不想跟你\n"
    .string "打……\p"
    .string "我的宝可梦还没做好战胜你的准备。\p"
    .string "我现在不能把它们逼得太紧。\p"
    .string "想要成为最强的宝可梦训练家，我必\n"
    .string "须严格自律才行……$"

DragonsDen_Cavern_Text_SilverTraining2:
    .string "......\p"
    .string "呼……\p"
    .string "别来碍我的事……$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "你！没有受到允许怎么敢擅自闯入！$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "好、好强！$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "前面的祠堂是我们驭龙一族的长老修\n"
    .string "行之所。\p"
    .string "绝对不能随随便便就进去！$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "你不能待在这里！$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "哎呀呀，输掉了！$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "我很快就能得到长老的许可，开始培\n"
    .string "育龙宝可梦了。\p"
    .string "到那时，我要成为一名优秀的龙属性\n"
    .string "训练家，赢得长老的认可！$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "是个不认识的陌生人呢。$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "好痛痛。$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "简直就像是在跟阿渡大人对战一样。$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "你是什么人呀？$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "大坏蛋。$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "我们要去告状。\p"
    .string "长老一定会对你生气的。$"
