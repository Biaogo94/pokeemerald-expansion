Route19_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD_HNS, Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER_HNS, Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN_HNS, Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME_HNS, Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_EventScript_Item_Brine::
    finditem ITEM_TM_BRINE
    end

Route19_Text_SwimmermHaroldSeen:
	.string "你曾在夜晚的大海里游过泳吗？$"

Route19_Text_SwimmermHaroldBeaten:
	.string "咕噜……$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "夜晚的大海漆黑一片，感觉就像要把\n"
	.string "人吞噬掉一样。$"

Route19_Text_SwimmermTuckerSeen:
	.string "哈、哈……还差……\n"
	.string ".一点……\p"
	.string "就能到……浅红市了...\n"
	.string "...$"

Route19_Text_SwimmermTuckerBeaten:
	.string "我要淹死啦！$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "我……提议跟女朋友一起游\n"
	.string "到浅红市……呼……\l"
	.string ".$"

Route19_Text_SwimmerfDawnSeen:
	.string "我最讨厌软弱无能的人了！$"

Route19_Text_SwimmerfDawnBeaten:
	.string "要是比游泳的话我可不会输……\n"
	.string "..$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "从浅红市游到双子岛明明很快的..\n"
	.string "....\p"
	.string "真是的，我男朋友算什么男子汉啊！\n"
	.string "真是个窝囊废！$"

Route19_Text_SwimmermJeromeSeen:
	.string "游泳？我根本游不好。\p"
	.string "我只是在这片浅滩里玩玩水而已。$"

Route19_Text_SwimmermJeromeBeaten:
	.string "我还以为能赢呢。$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "虽然我不太会游泳，但我很喜欢大海\n"
	.string "。$"

Route19_Text_Fisher1:
	.string "不好意思。这条路因为施工而封闭了\n"
	.string "。\p"
	.string "如果你想去红莲岛，最好从真新镇往\n"
	.string "南走。$"

Route19_Text_Kingler:
	.string "巨钳蟹：叽----！$"

Route19_Text_Fisher1_RocksCleared:
	.string "出了一身汗。该去游个泳啦！$"

Route19_Text_Fisher2:
	.string "真倒霉，巨钳蟹把海滩给堵住了。$"

Route19_Text_FisherBefore:
	.string "在这些巨钳蟹离开之前，没法钓鱼了\n"
	.string "。$"

Route19_Text_Fisher2_RocksCleared:
	.string "那些巨钳蟹终于走掉了！\p"
	.string "现在我又可以钓鱼啦。$"

Route19_Text_Sign:
	.string "19号道路\p"
	.string "浅红市 - 双子岛$"

Route19_Text_CarefulSwimmingSign:
	.string "游往双子岛时请务必注意安全。\p"
	.string "浅红警察局$"

