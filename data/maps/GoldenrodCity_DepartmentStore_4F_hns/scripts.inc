GoldenrodCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "嗨。我最喜欢强壮的宝可梦了。\p"
    .string "我经常喂它们吃攻击增强剂来提高它\n"
    .string "们的攻击。$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "防御增强剂可以提升宝可梦的防御。$"

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "曾有传言说，有些宝可梦只能通过连\n"
    .string "接线通信交换才能进化。\p"
    .string "哼……\p"
    .string "真是道听途说。\p"
    .string "我知道传言中的几种宝可梦：豪力、\n"
    .string "勇基拉、鬼斯通，还有……呃，隆隆\l"
    .string "石，其实它们只要提升等级就能进化\l"
    .string "了。$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FDirectory:
    .string "让我们来强健您的宝可梦！\p"
    .string "4F 药剂专柜$"
