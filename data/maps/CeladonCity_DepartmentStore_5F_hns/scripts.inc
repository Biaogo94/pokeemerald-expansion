CeladonCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FRUSTRATION, CeladonDeptStore5_EventScript_Receptionist_Already
	msgbox CeladonDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, FRIENDSHIP_50_TO_99, CeladonDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	msgbox CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_Already::
	msgbox CeladonDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore_Text_5FReceptionistOhYourMon:
    .string "你好呀。哎呀，你的宝可梦....\n"
    .string "..$"

CeladonDeptStore_Text_5FReceptionistWait:
    .string "等等，那个招式学习器我不是已经给\n"
    .string "你了吗！$"

CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "嗯......说不上差，但也谈不\n"
	.string "上好。\p"
	.string "作为训练家，你还需要再多加努力才\n"
	.string "行。$"

CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "它的眼神看起来好凶狠啊。给它用这\n"
    .string "个招式学习器怎么样？$"

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "{PLAYER}。没想到会在这里\n"
	.string "遇见你。\p"
	.string "我正在为我的鸟宝可梦挑选装备。\p"
	.string "如果你还想与我对战，就来金黄市的\n"
	.string "格斗道馆找我吧。$"

CeladonDeptStore5F_Text_Gentleman:
	.string "我想买些能提升宝可梦能力的道具，\n"
	.string "可是手头的钱不够......$"

CeladonDeptStore5F_Text_Sailor:
	.string "我好想买PP提升剂来增加招式的P\n"
	.string "P啊。可惜这东西根本没得卖...\l"
	.string "...$"

CeladonDeptStore5F_Text_Teacher:
	.string "给宝可梦使用道具会让它们开心。\p"
	.string "不过，有些道具它们其实很讨厌呢.\n"
	.string ".....$"

CeladonDeptStore5F_Text_Directory:
	.string "5F：药剂卖场$"
