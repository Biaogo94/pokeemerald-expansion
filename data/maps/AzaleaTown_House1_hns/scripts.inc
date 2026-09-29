AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "镇上的呆呆兽全都消失了。\p"
	.string "森林的守护神可能在生我们的气..\n"
	.string "....\p"
	.string "这恐怕是不祥之兆。我们还是待在屋\n"
	.string "里吧。$"

CharcoalKiln_Text_Boss2:
	.string "呆呆兽们回来了……$"

CharcoalKiln_Text_Boss3:
	.string "呆呆兽们回来了……\p"
	.string "但我那学徒还没从桐树林回来。\p"
	.string "那个懒鬼到底跑哪儿去了？$"

CharcoalKiln_Text_Boss4:
	.string "你赶跑了火箭队，还独自一人去了桐\n"
	.string "树林？\p"
	.string "真有种！我喜欢。来和我们一起修行\n"
	.string "吧。$"

CharcoalKiln_Text_Apprentice1:
	.string "呆呆兽们都去哪儿了？\p"
	.string "是去哪里玩了吗？$"

CharcoalKiln_Text_Apprentice2:
	.string "呆呆兽们回来了！$"

CharcoalKiln_Text_Apprentice3:
	.string "不好意思--我都忘了向你道谢。\p"
	.string "这是我自己烧制的木炭。\p"
	.string "让火属性的宝可梦携带，它一定会很\n"
	.string "高兴的。$"

CharcoalKiln_Text_Apprentice4:
	.string "呆呆兽们回来了，你甚至还找回了大\n"
	.string "葱鸭。\p"
	.string "你太帅了，伙计！$"

CharcoalKiln_Text_Farfetchd:
	.string "大葱鸭：嘎啊！$"
