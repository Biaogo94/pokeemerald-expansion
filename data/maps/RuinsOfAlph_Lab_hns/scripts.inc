RuinsOfAlph_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

RuinsOfAlph_Lab_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RuinsOfAlph_Lab_EventScript_Scientist1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Lab_Text_Scientist1, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_Lab_EventScript_Scientist2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Lab_Text_Scientist2, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_Lab_EventScript_Fossils::
	lock
	msgbox RuinsOfAlph_Lab_Text_Fossils, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Lab_Text_Scientist1:
	.string "这处遗迹大约有1500年的历史。\p"
	.string "但至今仍不清楚是因何而建，又是由\n"
	.string "谁建造的。$"

RuinsOfAlph_Lab_Text_Scientist2:
	.string "遗迹的墙上画着奇怪的图案。\p"
	.string "那一定就是解开遗迹之谜的关键。$"

RuinsOfAlph_Lab_Text_Fossils:
	.string "在遗迹内部发现的化石。也许在其他\n"
	.string "地方还能找到更多……$"


RuinsOfAlph_Lab_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RuinsOfAlph_Lab_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RuinsOfAlph_Lab_EventScript_StillRegenerating
	msgbox RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeClawFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeHelixFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeDomeFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeOldAmber
	release
	end

@ This whole section has needless duplication and could be condensed considerably
RuinsOfAlph_Lab_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveRootFossil
	end

RuinsOfAlph_Lab_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeClawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveClawFossil
	end

RuinsOfAlph_Lab_EventScript_GiveClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeHelixFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveHelixFossil
	end

RuinsOfAlph_Lab_EventScript_GiveHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeDomeFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveDomeFossil
	end

RuinsOfAlph_Lab_EventScript_GiveDomeFossil::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_DOME_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeOldAmber::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveOldAmber
	end

RuinsOfAlph_Lab_EventScript_GiveOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_OLD_AMBER
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
	release
	end

RuinsOfAlph_Lab_EventScript_DeclineGiveFossil::
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2::
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo2, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_StillRegenerating::
	msgbox RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RuinsOfAlph_Lab_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RuinsOfAlph_Lab_EventScript_AnorithReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, RuinsOfAlph_Lab_EventScript_OmanyteReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, RuinsOfAlph_Lab_EventScript_KabutoReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, RuinsOfAlph_Lab_EventScript_AeroReady
	end

RuinsOfAlph_Lab_EventScript_LileepReady::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveLileep
	end

RuinsOfAlph_Lab_EventScript_AnorithReady::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveAnorith
	end

RuinsOfAlph_Lab_EventScript_OmanyteReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveOmanyte
	end

RuinsOfAlph_Lab_EventScript_KabutoReady::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveKabuto
	end

RuinsOfAlph_Lab_EventScript_AeroReady::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileep::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveLileepParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveLileepPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingLileep::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorith::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
	end

RuinsOfAlph_Lab_EventScript_TransferAnorithToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	end

RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC::
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	call_if_unset FLAG_BADGE04_GET, RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto
	call_if_set FLAG_BADGE04_GET, RuinsOfAlph_Lab_EventScript_GiveLateKabuto
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto::
	givemon SPECIES_KABUTO, 5
	return

RuinsOfAlph_Lab_EventScript_GiveLateKabuto::
	givemon SPECIES_KABUTO, 20
	return

RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferKabutoToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveAero::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAeroParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAeroPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveAeroParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveAeroPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferAeroToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingAero::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end


RuinsOfAlph_Lab_EventScript_ChooseFossil::
	message RuinsOfAlph_Lab_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_HNS, FALSE
	switch VAR_RESULT
	case 0, RuinsOfAlph_Lab_EventScript_ChooseClawFossil
	case 1, RuinsOfAlph_Lab_EventScript_ChooseRootFossil
	case 2, RuinsOfAlph_Lab_EventScript_ChooseHelixFossil
	case 3, RuinsOfAlph_Lab_EventScript_ChooseDomeFossil
	case 4, RuinsOfAlph_Lab_EventScript_ChooseOldAmber
	case 5, RuinsOfAlph_Lab_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RuinsOfAlph_Lab_EventScript_CancelFossilSelect
	end

RuinsOfAlph_Lab_EventScript_ChooseClawFossil::
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveClawFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseRootFossil::
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveRootFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseHelixFossil::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveHelixFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseDomeFossil::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveDomeFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseOldAmber::
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveOldAmber
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_CancelFossilSelect::
	release
	end

RuinsOfAlph_Lab_EventScript_WorkOnNext::
	msgbox RuinsOfAlph_Lab_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_Text_DeviceForTalkingToPokemon:
	.string "我们正在开发一种能与宝可梦交谈的\n"
	.string "装置。\p"
	.string "不过目前还没什么进展……$"

RuinsOfAlph_Lab_Text_DevelopingNewBalls:
	.string "我正在开发新型的精灵球…….\p"
	.string "不过进展不太顺利……$"

RuinsOfAlph_Lab_Text_WeFinallyMadeNewBalls:
	.string "我们终于做出了新型的精灵球！\p"
	.string "“重复球”能更容易捕捉到曾经捉到过\n"
	.string "的宝可梦。\p"
	.string "战斗回合数越久，“时间球”就越容易\n"
	.string "捉到宝可梦。\p"
	.string "这两款都是由得文公司引以为傲研发\n"
	.string "出的产品。\p"
	.string "请一定要买来试试看哦！$"

RuinsOfAlph_Lab_Text_IMadePokenav:
	.string "是我做出了宝可梦领航员！\p"
	.string "作为一名工程师，能做出这么棒的杰\n"
	.string "作，真是无比自豪啊！$"

RuinsOfAlph_Lab_Text_WowThatsAPokenav:
	.string "哇啊！那是宝可梦领航员吧！\p"
	.string "那是我们社长为了了解宝可梦的心\n"
	.string "情，倾注心血研发出来的成果。\p"
	.string "需要我为你详细介绍它的各项功能\n"
	.string "吗？\p"
	.string "不用不用，我想只要你亲自用一用宝\n"
	.string "可梦领航员，就全明白了。$"

RuinsOfAlph_Lab_Text_DeviceToVisualizePokemonDreams:
	.string "我正试着开发一种能把宝可梦的梦境\n"
	.string "具象化呈现出来的装置……\p"
	.string "不过进展并不顺利。$"

RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils:
	.string "我一直在尝试开发能让宝可梦从化石\n"
	.string "中复活的装置……\p"
	.string "而且，它成功运转了！$"

RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife:
	.string "等等！你手上的那个东西……..难道是\n"
	.string "宝可梦的化石？！\p"
	.string "你想让那只宝可梦重获新生吗？\p"
	.string "用我最新研发的“化石复原机”，就能\n"
	.string "做到哦。$"

RuinsOfAlph_Lab_Text_OhIsThatSo:
	.string "哦，是这样吗？\p"
	.string "不过我敢说，我的技术水平可是出类\n"
	.string "拔萃的。$"

RuinsOfAlph_Lab_Text_OhIsThatSo2:
	.string "哎呀，你身上没有化石呢。如果找到\n"
	.string "了，欢迎随时再来。$"

RuinsOfAlph_Lab_Text_TwoFossilsPickOne:
	.string "哎呀，真令人惊讶！你身上带了不止\n"
	.string "一块化石？\p"
	.string "遗憾的是，我的机器一次只能复活一\n"
	.string "只宝可梦。\p"
	.string "你想复原哪一块化石呢？$"

RuinsOfAlph_Lab_Text_HandedFossilToResearcher:
	.string "太棒了！我们马上开始吧。\p"
	.string "{PLAYER}将\n"
	.string "{STR_VAR_1}交给了遗迹\l"
	.string "研究员。$"

RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime:
	.string "我制造的“化石复原机”可是非常了不\n"
	.string "起的。\p"
	.string "但它有一个缺点--复原运转需要花相\n"
	.string "当长的一段时间。\p"
	.string "所以，呃……不如你在附近散散步，四\n"
	.string "处逛逛消磨一下时间吧？$"

RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife:
	.string "让你久等了！\p"
	.string "你的化石宝可梦已经顺利复活了！\p"
	.string "从化石里复活的是古代宝可梦，它的\n"
	.string "名字是{STR_VAR_2}！$"

RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher:
	.string "{PLAYER}从研究员那里得到\n"
	.string "了{STR_VAR_2}。$"

@ Unused
RuinsOfAlph_Lab_Text_TooManyPokemon:
	.string "哎呀，你带的宝可梦已经满了。同行\n"
	.string "队伍里没有它的位置了。$"

RuinsOfAlph_Lab_Text_DevelopNewPokenavFeature:
	.string "我正试着为宝可梦领航员开发一项新\n"
	.string "功能……\p"
	.string "不过目前进展不太顺利。$"

RuinsOfAlph_Lab_Text_WhatToWorkOnNext:
	.string "好啦，接下来该研发点什么呢？\p"
	.string "在我们的公司，只要有灵感就能将其\n"
	.string "变为现实。\p"
	.string "作为一名工程师，没有比这里更棒的\n"
	.string "工作环境了。$"


