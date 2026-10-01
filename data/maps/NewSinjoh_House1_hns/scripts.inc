NewSinjoh_House1_hns_MapScripts::
	.byte 0


NewSinjoh__House1_EventScripts_Elizabeth::
    lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER, NewSinjoh_House1_EventScript_Elizabeth_AfterGift
    msgbox NewSinjoh_House1_Text_Looking4Celebi MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_House1_EventScript_Decline
    checkspecies SPECIES_CELEBI
    goto_if_eq VAR_RESULT, TRUE, NewSinjoh_House1_EventScript_GiveWooperPaldea
	msgbox NewSinjoh_House1_Text_NicePokemonButNotCelebi, MSGBOX_DEFAULT
    release
    end

NewSinjoh_House1_EventScript_Decline::
	msgbox NewSinjoh_House1_Text_Decline, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_House1_EventScript_GiveWooperPaldea::
	playse SE_PIN
    applymovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH
    msgbox NewSinjoh_House1_OffersWooper MSGBOX_DEFAULT
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WOOPER_PALDEA
    bufferspeciesname STR_VAR_1, SPECIES_WOOPER_PALDEA
    givemon SPECIES_WOOPER_PALDEA, 5
	call Common_EventScript_GiftMon
	setflag FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER
	closemessage
    release
    end

NewSinjoh_House1_Text_Looking4Celebi:
    .string "训练家，你好呀！\p"
    .string "你是一路从若叶镇远道而来的吗？\p"
    .string "我有件事想拜托像你这样见多识广的\n"
    .string "旅行者。其实呢，我在这世界上最喜\l"
    .string "欢的宝可梦，正好就是被称为幻之宝\l"
    .string "可梦的时拉比。\p"
    .string "如果你正好收服了它，能不能借我瞧\n"
    .string "一眼呢？$"

NewSinjoh_House1_Text_NicePokemonButNotCelebi:
    .string "你的这只宝可梦真是太棒了，不过这\n"
    .string "并不是我想见的那一只呢…….$"

NewSinjoh_House1_OffersWooper:
    .string "就是它！是活生生的时拉比！！\p"
    .string "太感谢你了，居然特地把它带到遥远\n"
    .string "的北方来给我看。\p"
    .string "拿去吧，我女朋友去遥远地区旅行时\n"
    .string "抓了太多这种宝可梦……\p"
    .string "这个特别的乌波就送给你当做谢礼\n"
    .string "吧，{PLAYER}。$"

NewSinjoh_House1_Text_Decline:
	.string "真遗憾啊。我真的很想亲眼见见它\n"
	.string "呢。$"

NewSinjoh_House1_Text_TakeCareOfWooper:
    .string "一定要替我好好照顾那只乌波哦？$"

NewSinjoh_House1_EventScript_Elizabeth_AfterGift::
	msgbox NewSinjoh_House1_Text_GoodToSeeYouAgain MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Text_GoodToSeeYouAgain:
    .string "又见面了呢，{PLAYER}。\p"
    .string "你和那只乌波相处得怎么样了？$"

NewSinjoh_House1_Bookshelf::
    lock
	msgbox NewSinjoh_House1_Bookshelf_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Bookshelf_Text:
    .string "书架上塞满了电脑游戏和漫画书！$"

NewSinjoh_House1_Eevee::
    lock
	faceplayer
	playmoncry SPECIES_EEVEE, 0
	msgbox NewSinjoh_House1_Text_Eevee_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_House1_Text_Eevee_Cry:
    .string "咿--布？$"
