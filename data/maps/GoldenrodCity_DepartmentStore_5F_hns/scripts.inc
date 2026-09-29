GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "你好呀。哎呀，你的宝可梦……\n"
    .string "..$"

GoldenrodDeptStore_Text_5FReceptionistWait:
    .string "等等，那个招式学习器我不是已经给\n"
    .string "你了吗！$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "嗯……说不上差，但也谈不\n"
	.string "上好。\p"
	.string "作为训练家，你还需要再多加努力才\n"
	.string "行。$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "它非常依恋你呢。\p"
    .string "这个招式最适合像你们这样亲密无间\n"
    .string "的组合了。$"

GoldenrodDeptStore_Text_5FLass:
    .string "白天的时候，会有一位女士过来观察\n"
    .string "宝可梦的情况。\p"
    .string "她甚至还会赠送招式学习器呢！$"

GoldenrodDeptStore_Text_5FPokefanM:
    .string "交换得来的宝可梦是不能改名的。\p"
    .string "因为那个名字寄托了原训练家对它的\n"
    .string "感情。$"

GoldenrodDeptStore_Text_Girl:
	.string "那位女士送了我“报恩”！我的宝可\n"
	.string "梦一定超级喜欢我！$"

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
    .string "打造独一无二的宝可梦\p"
    .string "5F 招式学习器专柜$"
