SSAqua_RoomNW_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY_HNS, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD_HNS, SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY_HNS, SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "没错，我就是水手啦。\p"
	.string "我可没在偷懒哦！\p"
	.string "这间客舱正好空着，我只是稍微打了\n"
	.string "个盹！\p"
	.string "啊，算了！来对战吧！$"

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "对不起！都是我的错！$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "当水手净是些体力活，真是累死人了\n"
	.string "！$"

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "哎呀糟了，我把非常重要的东西给弄\n"
	.string "丢了。$"

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "找……找不到啊……\n"
	.string ".$"

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "我放弃了。你也不用找了。\p"
	.string "彻底忘掉这事吧！$"

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "哟嚯！运气真好！$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "真倒霉！输掉了！$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "我在这里捡到了一枚漂亮的硬币。\p"
	.string "一定是有人不小心弄丢的……\n"
	.string ".$"
