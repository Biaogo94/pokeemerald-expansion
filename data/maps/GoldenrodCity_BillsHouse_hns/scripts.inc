GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
    .string "正辉：嗨，{PLAYER}！帮我\n"
    .string "个忙，收下这只伊布吧。\p"
    .string "这是我外出调整系统的时候，别人寄\n"
    .string "养在这里的。\p"
    .string "得有个人来照顾它才行，但我又不太\n"
    .string "喜欢出门。\p"
    .string "{PLAYER}，能拜托你多陪陪\n"
    .string "它玩吗？$"

BillHouse_Text_CountingOnYou:
    .string "正辉：我就知道你靠得住！\p"
    .string "太棒了！你真是帮了大忙！\p"
    .string "好，那就拜托你了。\p"
    .string "一定要好好照顾它哦！$"

BillHouse_Text_ReceivedEevee:
    .string "{PLAYER}得到了伊布！$"

BillHouse_Text_EeveeMayEvolve:
    .string "正辉：空木博士说，伊布可能存在全\n"
    .string "新且未知的进化方式。$"

BillHouse_Text_PartyFull:
    .string "哇，等等。你的同行宝可梦已经满\n"
    .string "了。$"

BillHouse_Text_NoEevee:
    .string "哎呀……这下该怎么办呢？$"

BillHouse_Text_PopWontWork:
    .string "正辉：我老爸他根本不工作，成天就\n"
    .string "只知道游手好闲。\p"
    .string "真是让人头疼啊……$"

BillHouse_Text_MomBeforeEcruteak:
    .string "哎呀，你在收集宝可梦吗？我儿子正\n"
    .string "辉可是这方面的专家。\p"
    .string "他刚刚被叫去圆朱市的宝可梦中心\n"
    .string "了。\p"
    .string "我丈夫则是不请自去，一溜烟跑去了\n"
    .string "满金游戏城……$"

BillHouse_Text_MomAfterEcruteak:
    .string "我丈夫以前被称为宝可梦狂人呢。\p"
    .string "正辉肯定也是随了他爸爸。$"

BillHouse_Text_SisterUsefulNumber:
    .string "你是训练家吗？\p"
    .string "我这有个对你很有用的电话号码哦。$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER}记录了正辉的电话\n"
    .string "号码。$"

BillHouse_Text_SisterRefusedNumber:
    .string "我哥哥制作了电脑的宝可梦存储系\n"
    .string "统。\p"
    .string "我本来还想把正辉的电话号码给你\n"
    .string "的……$"

BillHouse_Text_SisterPhoneFull:
    .string "无法记录更多的电话号码了。$"

BillHouse_Text_SisterStorageSystem:
    .string "我哥哥正辉制作了电脑里的宝可梦存\n"
    .string "储系统。$"
