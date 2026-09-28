SproutTower_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO_HNS, SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND_HNS, SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "无论对战多么激烈，这座高塔都会屹\n"
	.string "立不倒。$"

SproutTower_Text_SageNico_Beaten:
	.string "我拼尽了全力，但还是太弱了。$"

SproutTower_Text_SageNico_AfterBattle:
	.string "柔软而富有弹性的支柱保护着高塔，\n"
	.string "即使面对地震也安然无恙。$"

SproutTower_Text_SageEdmond_Seen:
	.string "......如风中落叶般摇曳..\n"
	.string "....$"

SproutTower_Text_SageEdmond_Beaten:
	.string "哎呀，是我太弱了！$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "我试图模仿喇叭芽柔软的动作来进行\n"
	.string "对战......\p"
	.string "但我的修行还远远不够。$"

SproutTower_Text_2F_Statue:
	.string "宝可梦的雕像......\p"
	.string "看起来非常庄严气派。$"
