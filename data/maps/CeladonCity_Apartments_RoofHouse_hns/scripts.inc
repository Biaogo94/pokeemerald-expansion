CeladonCity_Apartments_RoofHouse_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_SLEEP_TALK, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_SLEEP_TALK
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "让我来给你讲个可怕的故事吧...\n"
	.string "...$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "不过天还亮着的时候，听起来可没那\n"
	.string "么吓人。\p"
	.string "太阳落山之后再来吧，好吗？$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "很久很久以前，有个小男孩得到了一\n"
	.string "辆全新的自行车......\p"
	.string "他迫不及待地想骑上去试试....\n"
	.string "..\p"
	.string "他玩得太开心了，完全没注意到太阳\n"
	.string "已经落山......\p"
	.string "在漆黑一片的夜色中骑车回家时，车\n"
	.string "速突然慢了下来！\p"
	.string "脚踏板也变得沉重无比！\p"
	.string "当他停下不蹬时，自行车竟然开始往\n"
	.string "后滑！\p"
	.string "就好像自行车被诅咒了一样，要把他\n"
	.string "拖进无底的深渊！\p"
	.string "......\p"
	.string "......\p"
	.string "啊--！！！\p"
	.string "原来那个小男孩是在自行车道上逆行\n"
	.string "爬坡呢！\p"
	.string "......扑通扑通！(吓一跳吧\n"
	.string "！)\p"
	.string "谢谢你这么耐心地听完，这个招式学\n"
	.string "习器82就送给你吧！$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "TM82 is SLEEP TALK.\p"
	.string "It will allow your POKéMON to use\n"
	.string "a random move while asleep.\p"
	.string "But good luck sleeping after that\n"
	.string "terrifying tale!$"

