ReceptionGate_hns_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
    .string "阿杏：我正要去我老爸那里给他送午\n"
    .string "餐呢。\p"
    .string "四天王不分昼夜地忙碌，根本没有休\n"
    .string "息时间，真的很辛苦呢。\p"
    .string "如果你想再和我对战一场，我待会儿\n"
    .string "会去道场。$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_INDIGOJUNCTION_POLICEMAN
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "只有证明过自己实力的训练家方可通\n"
    .string "过。$"

VictoryRoadGate_Text_Kimono:
    .string "抱歉啊小朋友，在有人解决掉那只传\n"
    .string "说中的宝可梦之前，这里暂时封路了\l"
    .string "......$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "你还没有集齐城都地区的全部道馆徽\n"
    .string "章。\p"
    .string "很抱歉，我不能让你通过。$"

VictoryRoadGate_Text_EightBadges:
    .string "哦！城都地区的8枚徽章！\p"
    .string "请进，直接过去吧！$"

VictoryRoadGate_Text_LeftBlackBelt:
    .string "这条路通往白银山。\p"
    .string "那里的宝可梦可是强得吓人哦。$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "准备前往宝可梦联盟，对吗？\p"
    .string "四天王的实力可是强得吓人，他们已\n"
    .string "经严阵以待了！$"
