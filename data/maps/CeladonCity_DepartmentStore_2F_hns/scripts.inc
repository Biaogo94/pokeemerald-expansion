CeladonCity_DepartmentStore_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "我最近才成为宝可梦训练家。\p"
	.string "是我儿子鼓励我这么做的。\p"
	.string "这里的便利道具琳琅满目，真让我大\n"
	.string "开眼界啊。$"

CeladonDeptStore2F_Text_Youngster:
	.string "我爸爸老是记不住道具的名字，也搞\n"
	.string "不懂该怎么用，可伤脑筋了……\l"
	.string "..$"

CeladonDeptStore2F_Text_Directory:
	.string "训练家必备的顶级道具！\p"
	.string "2F：训练家市场$"

