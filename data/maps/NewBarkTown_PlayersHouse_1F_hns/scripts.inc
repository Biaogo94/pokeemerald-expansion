NewBarkTown_PlayersHouse_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_PlayersHouse_1F_OnTransition
	.byte 0

NewBarkTown_PlayersHouse_1F_OnTransition::
	call_if_eq VAR_NEWBARK_TOWN_STATE, 1, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	end

NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT

	@add to newgame later
	clearflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_MOM_VISITED
	return

NewBarkTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_MOM_VISITED, NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular
	goto_if_set FLAG_ADVENTURE_STARTED, NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MovementFaceLeft
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsFriend::
	lock
	faceplayer
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomsFriend, MSGBOX_DEFAULT
	applymovement LOCALID_MOMS_FRIEND, NewBarkTown_PlayersHouse_1F_MovementFaceRight
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck::
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomLeaving, MSGBOX_DEFAULT
	setflag FLAG_MOM_VISITED
	clearflag FLAG_HIDE_ROUTE_30_NPCS
	setvar VAR_NEWBARK_TOWN_STATE, 5
	fadedefaultbgm
	release
	end


NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular::
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_PlayersHouse_1F_EventScript_Mom_PokecenterChallenge
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	call NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	fadedefaultbgm
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_Mom_PokecenterChallenge::
	msgbox PlayersHouse_1F_Text_YouShouldRestABit_PokecenterChallenge, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	fadedefaultbgm
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu::
	special Special_MomEnsureInitialized
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomAnythingElse, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MOM_MENU, FALSE
	switch VAR_RESULT
	case 0, NewBarkTown_PlayersHouse_1F_EventScript_CheckSavings
	case 1, NewBarkTown_PlayersHouse_1F_EventScript_Deposit
	case 2, NewBarkTown_PlayersHouse_1F_EventScript_Withdraw
	case 3, NewBarkTown_PlayersHouse_1F_EventScript_ToggleSaving
	case 4, NewBarkTown_PlayersHouse_1F_EventScript_ExitSavings
	case MULTI_B_PRESSED, NewBarkTown_PlayersHouse_1F_EventScript_ExitSavings
	end

NewBarkTown_PlayersHouse_1F_EventScript_CheckSavings::
	special Special_MomGetBalance
	msgbox NewBarkTown_PlayersHouse_1F_Text_CurrentSavings, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_Deposit::
	checkmoney 1
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_DepositFailed
	closemessage
	special Special_MomOpenDepositInput
	waitstate
	compare VAR_0x8000, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	msgbox NewBarkTown_PlayersHouse_1F_Text_DepositSuccess, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_DepositFailed::
	msgbox NewBarkTown_PlayersHouse_1F_Text_NoMoneyToDeposit, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_Withdraw::
	special Special_MomGetBalance
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_WithdrawFailed
	closemessage
	special Special_MomOpenWithdrawInput
	waitstate
	compare VAR_0x8000, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	msgbox NewBarkTown_PlayersHouse_1F_Text_WithdrawSuccess, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_WithdrawFailed::
	msgbox NewBarkTown_PlayersHouse_1F_Text_NoMoneyToWithdraw, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ToggleSaving::
	special Special_MomIsSavingEnabled
	compare VAR_RESULT, TRUE
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_DisableSaving
	msgbox NewBarkTown_PlayersHouse_1F_Text_EnableSaving, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_ConfirmEnable
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ConfirmEnable::
	special Special_MomEnableSaving
	msgbox NewBarkTown_PlayersHouse_1F_Text_SavingEnabled, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_DisableSaving::
	msgbox NewBarkTown_PlayersHouse_1F_Text_DisableSaving, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_ConfirmDisable
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ConfirmDisable::
	special Special_MomDisableSaving
	msgbox NewBarkTown_PlayersHouse_1F_Text_SavingDisabled, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ExitSavings::
	msgbox NewBarkTown_PlayersHouse_1F_Text_Goodbye, MSGBOX_DEFAULT
	return

NewBarkTown_PlayersHouse_1F_Text_MomAnythingElse:
	.string "Is there anything else I can\n"
	.string "help you with, sweetie?$"

NewBarkTown_PlayersHouse_1F_Text_CurrentSavings:
	.string "I'm holding {STR_VAR_2}\n"
	.string "for you right now.$"

NewBarkTown_PlayersHouse_1F_Text_EnableSaving:
	.string "Do you want me to save some of the\n"
	.string "money you earn?$"

NewBarkTown_PlayersHouse_1F_Text_SavingEnabled:
	.string "Okay! I'll save 25% of\n"
	.string "the money you earn from battles.$"

NewBarkTown_PlayersHouse_1F_Text_DisableSaving:
	.string "Would you like me to stop\n"
	.string "saving for you?$"

NewBarkTown_PlayersHouse_1F_Text_SavingDisabled:
	.string "Okay, I'll stop saving for now.$"

NewBarkTown_PlayersHouse_1F_Text_Goodbye:
	.string "Take care, sweetie!$"

NewBarkTown_PlayersHouse_1F_Text_DepositSuccess:
	.string "MOM: Sounds good! I'll put that in\n"
	.string "savings for you.$"

NewBarkTown_PlayersHouse_1F_Text_WithdrawSuccess:
	.string "MOM: Here you go!$"

NewBarkTown_PlayersHouse_1F_Text_NoMoneyToDeposit:
	.string "MOM: You don't have any money to\n"
	.string "deposit right now, sweetie.$"

NewBarkTown_PlayersHouse_1F_Text_NoMoneyToWithdraw:
	.string "MOM: I haven't saved any money\n"
	.string "for you yet, honey.$"

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end


NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro::
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_MOM
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_1
	waitmovement 0
	msgbox NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear
	call NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_2
	waitmovement 0
	setvar VAR_NEWBARK_TOWN_STATE, 2
	setvar VAR_NEWBARKTOWN_LABSTATE, 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	setflag FLAG_VISITED_NEWBARK_TOWN

	@former flagheap location

	fadedefaultbgm
	releaseall
	end



NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear::
	playfanfare MUS_REGISTER_MATCH_CALL
	message NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	return
	
NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes::
	msgbox NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1:
	delay_8
	walk_down
	walk_right
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2:
	delay_8
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_1:
	face_right
	walk_right
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_2:
	face_left
	walk_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceRight:
	face_right
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceLeft:
	face_left
	step_end

NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou:
	.string "哎呀，{PLAYER}！邻居空木\n"
	.string "博士正在找你呢。\p"
	.string "他说有件事想拜托你帮个忙。\p"
	.string "啊！差点忘了！你的宝可梦齿轮已经\n"
	.string "从修理店送回来了。\p"
	.string "给你！$"

NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear:
	.string "{PLAYER}获得了宝可梦齿轮\n"
	.string "。$"

NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear:
	.string "妈妈：电话号码都储存在内存里面。\p"
	.string "只要选你想联系的名字就行。我已经\n"
	.string "把我的号码存进去了。\p"
	.string "哎呀，真是太方便了不是吗？$"

NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes:
	.string "哦，还有别忘了带上跑步鞋！$"

NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER}换上了跑步鞋。$"

NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes:
	.string "妈妈：{PLAYER}，穿上这双\n"
	.string "鞋按住B键就可以飞快地奔跑了！$"

NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting:
	.string "妈妈：空木博士还在等你呢。\p"
	.string "快去吧，宝贝！$"

NewBarkTown_PlayersHouse_1F_Text_MomsFriend:
	.string "Hi, {PLAYER}!\p"
	.string "I'm visiting!\p"
	.string "Have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF.ELM's assistant.\p"
	.string "She really loves POKéMON!$"

NewBarkTown_PlayersHouse_1F_Text_MomLeaving:
	.string "妈妈：哇，好可爱的宝可梦。是从哪\n"
	.string "里得到的？\p"
	.string "……\p"
	.string "所以，你准备出发去冒险了……听起\n"
	.string "来真的很有挑战性呢……\p"
	.string "路上一定要小心。\p"
	.string "宝可梦是你的伙伴。你们必须像团队\n"
	.string "一样互相合作。\p"
	.string "好了，快出发吧！妈妈会一直支持你\n"
	.string "的！$"
