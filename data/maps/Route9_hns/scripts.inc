Route9_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN_HNS, Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI_HNS, Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA_HNS, Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID_HNS, Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM_HNS, Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY_HNS, Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_EventScript_Item_Flash_Cannon::
    finditem ITEM_TM_FLASH_CANNON
    end

Route9_Text_CamperDeanSeen:
	.string "我是来岩山隧道探险的。$"

Route9_Text_CamperDeanBeaten:
	.string "哇！真危险啊，伙计。$"

Route9_Text_CamperDeanAfter:
	.string "还没进岩山隧道，我的宝可梦就受伤\n"
	.string "了。\p"
	.string "我得赶紧带它们去宝可梦中心才行。$"

Route9_Text_PicnickerHeidiSeen:
	.string "你去野餐过吗？\p"
	.string "野餐可好玩了！$"

Route9_Text_PicnickerHeidiBeaten:
	.string "哎呀呀！$"

Route9_Text_PicnickerHeidiAfter:
	.string "我们烤了好多好吃的点心分给大家。\p"
	.string "味道好极了！$"

Route9_Text_CamperSidSeen:
	.string "喂，你！不要随地乱扔垃圾！$"

Route9_Text_CamperSidBeaten:
	.string "我只是想提醒一下......$"

Route9_Text_CamperSidAfter:
	.string "抱歉，你并没有乱扔垃圾呀。是我搞\n"
	.string "错了。$"

Route9_Text_PicnickerEdnaSeen:
	.string "大家都不应该把垃圾留在这里。$"

Route9_Text_PicnickerEdnaBeaten:
	.string "呜呜......我输了.....\n"
	.string ".$"

Route9_Text_PicnickerEdnaAfter:
	.string "节约能源固然重要，但保护环境更加\n"
	.string "不可或缺。$"

Route9_Text_HikerTimSeen:
	.string "她翻过白银山走过来，当她走过来.\n"
	.string ".....\p"
	.string "白银山是在城都对吧？$"

Route9_Text_HikerTimBeaten:
	.string "我光顾着唱歌了......$"

Route9_Text_HikerTimAfter:
	.string "对战最重要的就是集中精神。$"

Route9_Text_HikerSidneySeen:
	.string "我来告诉你一个秘密。\p"
	.string "不过得先对战一场！$"

Route9_Text_HikerSidneyBeaten:
	.string "哎呀，糟了！居然输了......$"

Route9_Text_HikerSidneyAfter:
	.string "发电厂就在那条小河的对岸。$"

Route9_Text_Sign:
	.string "9号道路\p"
	.string "华蓝市 - 岩山隧道$"
