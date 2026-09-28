GoldenrodCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodCity_PokemonCenter_hns_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoldenrodCity_PokemonCenter_hns_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY_HNS
	end

GoldenrodCity_PokemonCenter_hns_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	.2byte 0

GoldenrodCity_PokemonCenter_hns_OnWarp_Nop::
	end

GoldenrodCity_PokemonCenter_hns_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	.2byte 0

GoldenrodCity_PokemonCenter_hns_ExitLinkRoom::
	lockall
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	erasebox 0, 0, 29, 19
	releaseall
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc::
	lock
	faceplayer
	copyvar VAR_0x8007, VAR_LAST_TALKED
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_LINK_SERVICES_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_ChooseTrade
	case 1, GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseTrade::
	helpwindow HELP_TRADE_WINDOW
	delay 30
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom::
	setvar VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_TRADE_CENTER_HNS, 5, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseBattle::
	helpwindow HELP_TRADE_WINDOW
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_BATTLE_MODE_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_SingleBattle
	case 1, GoldenrodCity_PokemonCenter_EventScript_DoubleBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_SingleBattle::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_DoubleBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	end

GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

GoldenrodCity_PokemonCenter_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_BATTLE_COLOSSEUM_2P_HNS, 6, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline::
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End::
	release
	end

GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro:
	.string "通信角\p"
	.string "请选择通信方式。$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode:
	.string "请选择对战模式。$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye:
	.string "再见。$"

GoldenrodCity_PokemonCenter_EventScript_LinkExplainerNpc::
	msgbox GoldenrodCity_PokemonCenter_Text_LinkExplainer, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_Text_LinkExplainer:
	.string "你可以用这台机器和附近的其他玩家\n"
	.string "进行交换或对战。\p"
	.string "科技的力量真是太了不起了！$"

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "我最喜欢在大城市生活了！我像你这\n"
    .string "么年轻时，也是个到处旅行的训练家\l"
    .string "呢！$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "这里可是一座特别的宝可梦中心。屋\n"
    .string "顶是用黄金做的哦！$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "我跟我弟弟说这屋顶是用真金做的。\n"
    .string "他可真好骗，什么都信！$"

GoldenrodCity_PokemonCenter_LassText:
    .string "等级高的宝可梦不一定会赢。\p"
    .string "毕竟在属性上可能会处于劣势。\p"
    .string "我觉得根本不存在什么绝对最强的宝\n"
    .string "可梦。$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "是{PLAYER}对吧？\p"
    .string "恭喜你！\p"
    .string "作为特别赠礼，这颗GS球是专门送\n"
    .string "给你的！\p"
    .string "请收下吧！$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "欢迎再次光临！$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "哎呀，你的背包看起来好沉呀！\p"
    .string "哎！你身上该不会碰巧有一种叫做梦\n"
    .string "幻邮件的东西吧？\p"
    .string "我女儿一直在找它呢。\p"
    .string "你能割爱送我一份吗？$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "要送出梦幻邮件吗？$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "哎呀，太棒了！谢谢你，小家伙！\p"
    .string "来，这个是给你的回礼！$"

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "我女儿一定会高兴坏的！$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "哎？你没有吗？真遗憾。$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "哎......好吧，那下次再说吧\n"
    .string "。$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{PLAYER}送出了梦幻邮件。$"
