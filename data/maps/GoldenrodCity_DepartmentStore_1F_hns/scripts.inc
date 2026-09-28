GoldenrodCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "欢迎光临满金百货公司。$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "百货公司里的商品很丰富，\p"
    .string "不过有些道具只能在游戏城作为奖品\n"
    .string "换到。$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "今天我也跃跃欲试，准备大买一场！$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "妈妈很擅长淘便宜货，\p"
    .string "总是能以更优惠的价格买到东西。$"

GoldenrodDeptStore1_Text_Directory:
    .string "1F 服务柜台现在位置。\p"
    .string "2F 训练家卖场\p"
    .string "3F 对战专区\p"
    .string "4F 药品专区\p"
    .string "5F 招式学习器专区\p"
    .string "6F 恬静广场\p"
    .string "屋顶 展望台$"
