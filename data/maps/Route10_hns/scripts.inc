Route10_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route10_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route10_EventScript_Surge::
    lock
    faceplayer
    msgbox Route10_Text_Surge, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_PLANT_SURGE
    removeobject LOCALID_ROUTE10_SURGE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SURGE
    release
    end

Route10_Text_Surge:
    .string "嘿，小鬼！\p"
    .string "在这儿可别放松警惕，这地方正噼里\n"
    .string "啪啦地充满着电劲呢！\p"
    .string "如果想和我再打一场，就去格斗道馆\n"
    .string "找我吧！$"

Route10_EventScript_Item_Rock_Polish::
    finditem ITEM_TM_ROCK_POLISH
    end

Route10_EventScript_Jim::
	trainerbattle_single TRAINER_JIM_HNS, Route10_Text_HikerJimSeen, Route10_Text_HikerJimBeaten
	msgbox Route10_Text_HikerJimAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT_HNS, Route10_Text_PokefanmRobertSeen, Route10_Text_PokefanmRobertBeaten
	msgbox Route10_Text_PokefanmRobertAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	end

Route10_EventScript_PPSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_Zapdos::
	lock
	faceplayer
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ZAPDOS, 50
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route10_EventScript_ZapdosRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE10_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Route10_EventScript_ZapdosRan::
	release
	end


Route10_Text_HikerJimSeen:
	.string "哈哈哈哈！$"

Route10_Text_HikerJimBeaten:
	.string "哈哈哈哈--阿嚏！$"

Route10_Text_HikerJimAfter:
	.string "花粉症让我喷嚏打个不停！啊哈哈-\n"
	.string "-阿嚏！$"

Route10_Text_PokefanmRobertSeen:
	.string "你很喜欢宝可梦，对吧？\p"
	.string "我也喜欢！$"

Route10_Text_PokefanmRobertBeaten:
	.string "不得不承认是我输了。$"

Route10_Text_PokefanmRobertAfter:
	.string "看你把我的宝可梦伤成什么样了..\n"
	.string "....\p"
	.string "我可不会忘记这笔账的......$"

Route10_Text_PowerPlant:
	.string "发电厂$"

Route10_Text_Sign:
	.string "10号道路\p"
	.string "华蓝市 - 紫苑镇$"
