Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "我们是关都宝可梦联合！\p"
	.string "让你尝尝被车轮碾压的滋味！$"

Route8_Text_BikerDwayneBeaten:
	.string "对、对不起！$"

Route8_Text_BikerDwayneAfter:
	.string "关都宝可梦联合永不灭！$"

Route8_Text_BikerHarrisSeen:
	.string "条子居然封了我们的地下通道！\p"
	.string "真让人火大！$"

Route8_Text_BikerHarrisBeaten:
	.string "饶、饶了我吧！$"

Route8_Text_BikerHarrisAfter:
	.string "居然被城都来的小鬼给干翻了...\n"
	.string "...$"

Route8_Text_BikerZekeSeen:
	.string "我们是关都宝可梦联合！冲啊！$"

Route8_Text_BikerZekeBeaten:
	.string "哇啊！对不起！$"

Route8_Text_BikerZekeAfter:
	.string "我们以后尽量不去打扰别人了...\n"
	.string "...$"

Route8_Text_SupernerdSamSeen:
	.string "磁浮列车到底是怎么运行的呢？$"

Route8_Text_SupernerdSamBeaten:
	.string "我只是想看看磁浮列车……$"

Route8_Text_SupernerdSamAfter:
	.string "磁铁的力量太神奇了！$"

Route8_Text_SupernerdTomSeen:
	.string "嗯……你收集了不少道馆徽\n"
	.string "章嘛。$"

Route8_Text_SupernerdTomBeaten:
	.string "果然不出我所料……你很强\n"
	.string "！$"

Route8_Text_SupernerdTomAfter:
	.string "道馆徽章能让你在对战中占得优势。$"

Route8_Text_LockedDoor:
	.string "门锁着……$"

Route8_Text_UndergroundPathSign:
	.string "传单被撕破了。\p"
	.string "根本没法辨认上面的字……$"
