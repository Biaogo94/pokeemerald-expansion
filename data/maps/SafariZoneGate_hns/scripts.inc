SafariZoneGate_hns_MapScripts::
	.byte 0

SafariZoneGate_EventScript_Trigger::
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
	setvar VAR_SAFARI_ZONE_GATE_STATE, 3
	end

SafariZoneGate_EventScript_BackupTrigger::
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
	setvar VAR_TEMP_0, 1
	end

SafariZoneGate_EventScript_WorkerM::
	lock
	faceplayer
	msgbox SafariZone_Text_ForeignFeeling, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Silent::
	lock
	faceplayer
	msgbox SafariZone_Text_SilentNPC, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Kangaskhan::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	msgbox SafariZone_Text_Kangaskhan, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SafariZoneGate_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZone_Text_JigglypuffTrainer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Girl::
	lock
	faceplayer
	msgbox SafariZone_Text_FirstCatch, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_SlowpokeLady::
	lock
	faceplayer
	msgbox SafariZone_Text_SlowpokeFan, MSGBOX_DEFAULT
	closemessage
	release
	end


SafariZone_Text_ForeignFeeling:
	.string "狩猎地带……让我感觉就像来到了异国\n"
	.string "他乡一样。\p"
	.string "真是一种奇妙的感觉呢。$"

SafariZone_Text_SilentNPC:
	.string "..................\p"
	.string "(我不太爱说话。)$"

SafariZone_Text_Kangaskhan:
	.string "袋兽：..................$"

SafariZone_Text_JigglypuffTrainer:
	.string "这里的狩猎地带太棒了！我只顾着追\n"
	.string "宝可梦了！\p"
	.string "结果惹得我的胖丁不高兴了。$"

SafariZone_Text_FirstCatch:
	.string "我一直都想在狩猎地带收服我的第一\n"
	.string "只宝可梦呢。$"

SafariZone_Text_SlowpokeFan:
	.string "这里有很多宝可梦可以选，但哪只都\n"
	.string "比不上呆呆兽可爱！\p"
	.string "大家都说我长得很像呆呆兽呢！$"

SafariZone_Text_CustomSystem:
	.string "你可能会觉得自定义狩猎地带背后有\n"
	.string "什么复杂的系统，对吧？\p"
	.string "但其实真相是……$"

SafariZone_Text_Sign:
	.string "狩猎地带处处充满刺激与惊喜！\p"
	.string "欢迎随时前来体验大自然的原野！$"


SafariZoneGate_EventScript_IncenseClerk::
	goto_if_set FLAG_FINITE_TMS, SafariZoneGate_EventScript_IncenseClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_EventScript_IncenseClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SafariZoneGate_EventScript_VitaminGuru::
	lock
	faceplayer
	message SafariZoneGate_Text_VitaminGuruSellWhatYouNeed
	waitmessage
	pokemart SafariZoneGate_Pokemart_VitaminGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_VitaminGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_Text_VitaminGuruSellWhatYouNeed:
	.string "我是能量大叔！豁出去了，你需要什\n"
	.string "么我都卖给你！$"

