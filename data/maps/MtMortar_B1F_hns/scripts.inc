MtMortar_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO_HNS, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "嘿！\p"
	.string "我就是空手道大王！在这黑暗中独自\n"
	.string "修行！\p"
	.string "你！跟我对决吧！哇啊啊啊！$"

MountMortar4_Text_KiyoWin:
	.string "哇啊啊啊！我甘拜下风！$"

MountMortar4_Text_KiyoTyrogueReward:
	.string "我......我居然输得这么彻\n"
	.string "底......\p"
	.string "看来我的修行还远远不够....\n"
	.string "..\p"
	.string "但输了就是输了，我认输。\p"
	.string "作为击败我的证明，我送你一只稀有\n"
	.string "的格斗属性宝可梦吧。$"

MountMortar4_Text_ReceiveTyrogue:
	.string "{PLAYER}收到了无畏小子。$"

MountMortar4_Text_KiyoGotTyrogue:
	.string "无畏小子是格斗属性的。\p"
	.string "它能进化成更强劲的宝可梦。\p"
	.string "继续努力吧，我也要继续修行了。\p"
	.string "后会有期！$"

MountMortar4_Text_KiyoFullParty:
	.string "你的同行宝可梦已经满了！$"
