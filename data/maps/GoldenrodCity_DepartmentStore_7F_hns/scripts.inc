GoldenrodCity_DepartmentStore_7F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT_HNS
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F_HNS
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROOF_NERD
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
    .string "呼，好累啊。\p"
    .string "我有时会跑到顶楼来，在逛街的间隙\n"
    .string "歇上一会儿。$"

GoldenrodDeptStore_Text_RoofFisher:
    .string "你说什么？谁规定大人就不能玩这个\n"
    .string "啦？\p"
    .string "我每天都要来，一定要把所有的玩偶\n"
    .string "都集齐！$"

GoldenrodDeptStore_Text_RoofTwin:
    .string "这里隔三差五就会举办大减价特卖会\n"
    .string "呢。$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
    .string "哇，太棒了！$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
    .string "你能不能别来烦我了？$"

GoldenrodDeptStore_Text_RoofPokefanM:
    .string "有件东西我特别想买，可是手头的钱\n"
    .string "不够……\p"
    .string "也许我该把采到的树果拿去卖掉...\n"
    .string "...$"

GoldenrodDeptStore_Text_RoofTeacher:
    .string "哇，所有东西都好便宜啊！\p"
    .string "我买得太多，背包都塞得满满当当\n"
    .string "了！$"

GoldenrodDeptStore_Text_RoofBugCatcher:
    .string "我的宝可梦每到关键时刻总会陷入麻\n"
    .string "痹或者中毒……\p"
    .string "所以我来买点万灵药。\p"
    .string "不知道还有没有存货呢？$"
