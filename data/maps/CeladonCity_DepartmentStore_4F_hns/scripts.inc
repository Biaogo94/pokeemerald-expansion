CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "我本来打算买封冲浪邮件寄给我女朋\n"
	.string "友的。\p"
	.string "等等，居然卖光断货了？$"

CeladonDeptStore4F_Text_Youngster:
	.string "全天下只有这里才能买到可爱邮件。\p"
	.string "至少以前是这样的。可他们居然说现\n"
	.string "在卖光了。$"

CeladonDeptStore4F_Text_Directory:
	.string "赠送礼品，传情达意！\p"
	.string "4F：智者礼品店$"
