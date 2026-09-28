CeladonCity_DepartmentStore_RoofDay_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT_HNS
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY_HNS
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "是自动售货机！来看看有什么饮料吧\n"
	.string "。$"

CeladonDeptStore6F_Text_Clang:
	.string "匡啷！\p"
	.string "掉出了{STRING}。$"

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "哎呀，身上的钱不够......$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "背包里已经装不下更多东西了...\n"
	.string "...$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "带抽奖轮盘的自动售货机.....\n"
	.string ".\p"
	.string "现在已经见不到了呢。$"

CeladonDeptStore6F_Text_Youngster:
	.string "啊--！这里根本没有游戏机啊！\p"
	.string "我还想玩呢......$"

CeladonDeptStore6F_Text_Directory:
	.string "6楼：屋顶广场　自动售货机$"
