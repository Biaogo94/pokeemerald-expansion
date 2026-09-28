Route2_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_RobRegister:
	.string "把你的电话号码告诉我吧！$"

Route2_Text_RobRematchIntro:
	.string "我又抓到了更多虫宝可梦！快来瞧瞧\n"
	.string "吧！$"

Route2_Text_RobRematchDefeat:
	.string "我需要更厉害的虫宝可梦！$"

Route2_Text_RobPostRematch:
	.string "我把常青森林里所有的虫宝可梦都抓\n"
	.string "遍了。哪里还有更好的森林吗？$"

Route2_Text_BugCatcherRob_Seen:
	.string "我的虫宝可梦可是很厉害的。做好认\n"
	.string "输的准备吧！$"

Route2_Text_BugCatcherRob_Beaten:
	.string "彻底输了......$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "我要去寻找更强的虫宝可梦。$"

Route2_Text_BugCatcherEd_Seen:
	.string "穿短裤走在草丛里，难道不会被划伤\n"
	.string "吗？$"

Route2_Text_BugCatcherEd_Beaten:
	.string "好疼、好疼、好疼！$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "洗澡的时候伤口会刺痛得不行呢。$"

Route2_Text_BugCatcherDoug_Seen:
	.string "为什么女孩子都不喜欢虫宝可梦呢？$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "完全不行啊！$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "捏捏虫宝可梦的肚子时，软绵绵的手\n"
	.string "感就像毛绒玩具一样。\p"
	.string "我最喜欢这种感觉了！$"

Route2_Text_Sign:
	.string "2号道路\p"
	.string "常青市 - 深灰市$"

Route2_Text_DiglettsCaveSign:
	.string "地鼠洞$"

