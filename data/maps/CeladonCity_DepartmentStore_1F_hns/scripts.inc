CeladonCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "您好！欢迎光临玉虹百货商场！\p"
    .string "楼层导览贴在墙上。$"

CeladonDeptStore_Text_1FGentleman:
    .string "这家百货商场和满金市的那家属于同\n"
    .string "一家连锁商场。\p"
    .string "两家商场是在同一时期重新装修的。$"

CeladonDeptStore_Text_1FTeacher:
    .string "我还是第一次来这里。\p"
    .string "这里好大啊......\p"
    .string "真怕自己会迷路。$"

CeladonDeptStore_Text_1FDirectory:
    .string "1F：综合服务台\p"
    .string "2F：训练家市场\p"
    .string "3F：招式学习器卖场\p"
    .string "4F：智者礼品店\p"
    .string "5F：药剂卖场\p"
    .string "6F：楼顶广场$"
