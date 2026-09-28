Route28_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route28_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route28_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route28_EventScript_Sign::
	msgbox Route28_Text_Sign, MSGBOX_SIGN
	end

Route28_EventScript_Item_Flamethrower::
    finditem ITEM_TM_FLAMETHROWER
    end

Route28_Text_Sign:
	.string "28号道路$"

Route28_EventScript_Trigger_Scientist::
	lock
	clearflag FLAG_HIDE_ROUTE28_SCIENTIST
	addobject LOCALID_ROUTE28_SCIENTIST
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Route28_Movement_CameraPanDown
	waitmovement OBJ_EVENT_ID_CAMERA
	playse SE_POKENAV_CALL
	waitse
	msgbox Route28_Text_Scientist, MSGBOX_DEFAULT
	playse SE_POKENAV_HANG_UP
	msgbox Route28_Text_Scientist2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE28_SCIENTIST, Route28_Movement_ScientistLeave
	waitmovement LOCALID_ROUTE28_SCIENTIST
	applymovement2 OBJ_EVENT_ID_CAMERA, Route28_Movement_CameraPanUp
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	setvar VAR_ROUTE28_SCIENTIST, 2
	setflag FLAG_HIDE_ROUTE28_SCIENTIST
	removeobject LOCALID_ROUTE28_SCIENTIST
	release
	end

Route28_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	walk_diag_southwest
	walk_diag_southwest
	step_end

Route28_Movement_CameraPanUp:
	walk_diag_northeast
	walk_diag_northeast
	walk_up
	walk_up
	walk_up
	step_end

Route28_Movement_ScientistLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route28_Text_Scientist:
	.string "喂，老大。\p"
	.string "是的，我找到了几件遗物，但完全没\n"
	.string "有天界之笛的踪影。\p"
	.string "它可能在山里面，不过这里的野生宝\n"
	.string "可梦实力很强，我的队伍需要休息一\l"
	.string "下......\p"
	.string "..................\p"
	.string "听不清你在说什么......老大\n"
	.string "......？\p"
	.string "我要去一趟宝可梦中心。\p"
	.string "等我找到笛子再打给您。$"

Route28_Text_Scientist2:
	.string "......嘟--\p"
	.string "神都的信号真是烂透了......$"

