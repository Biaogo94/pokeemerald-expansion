SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_SEEDOT
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_LOTAD
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "你知道宝可梦橡实果吗？在琉璃市这\n"
	.string "里很难见到。\p"
	.string "我喜欢大型橡实果，越大越好。\p"
	.string "但我弟弟说莲叶童子更大一些。\p"
	.string "真是傻瓜。橡实果比那大多了！\p"
	.string "嗯？你有橡实果吗？拜——拜—拜托\n"
	.string "，给我看看！$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2}厘米！啊呀\n"
	.string "，真大！\p"
	.string "它肯定比弟弟见过的大莲叶童子还要\n"
	.string "大！\p"
	.string "谢谢你给我看，这是我的谢礼！$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER}收到了伤药。$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "嗯？你的背包已经塞满了。$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2}厘米是吗？\p"
	.string "唔……我见过比这更大的橡实果。$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "哎，这看上去不错……但它不是橡实\n"
	.string "果！$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "你没有大的橡实果？真糟糕……\p"
	.string "如果你有大橡实果，就拿给我看看吧\n"
	.string "。$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "史上最大的橡实果！\n"
	.string "{STR_VAR_2}的\l"
	.string "{STR_VAR_3}厘米大的巨\l"
	.string "物！\p"
	.string "比莲叶童子更大的橡实果总是人们追\n"
	.string "寻的东西！$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "你知道宝可梦莲叶童子吗？在琉璃市\n"
	.string "这里很难见到。\p"
	.string "我非常非常喜欢大型莲叶童子！\p"
	.string "哥哥说橡实果更大，\p"
	.string "但那肯定不对！所有人都知道莲叶童\n"
	.string "子更大。\p"
	.string "嗯？你有莲叶童子吗？拜——拜—拜\n"
	.string "托给我看看！$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2}厘米！哇，\n"
	.string "这么大！\p"
	.string "它肯定比哥哥看过的巨型橡实果更大\n"
	.string "。\p"
	.string "谢谢你给我看！收下我的谢意吧！$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER}收到了伤药。$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "嗯？你的背包已经塞满了。$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2}厘米？\p"
	.string "唔……我还见过比它更大的莲叶童子\n"
	.string "。$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "哎，这个不错！但不是莲叶童子！$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "你没有大的莲叶童子？真可惜……\p"
	.string "如果你得到了大莲叶童子，一定要给\n"
	.string "我看看！$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "史上最大的莲叶童子！\n"
	.string "{STR_VAR_2}的\l"
	.string "{STR_VAR_3}厘米大的巨\l"
	.string "物！\p"
	.string "比橡实果更大的莲叶童子总是人们追\n"
	.string "寻的东西！$"

