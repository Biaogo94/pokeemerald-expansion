Route6_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX_HNS, PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN_HNS, PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_EventScript_Item_Silver_Wind::
    finditem ITEM_TM_SILVER_WIND
    end

Route6_Text_PokefanM:
	.string "在发电厂的问题解决之前，这条道路\n"
	.string "一直处于封闭状态。$"

Route6_Text_UndergroundPathSign:
	.string "地下通道\p"
	.string "华蓝市~枯叶市$"

PokefanM_Text_RexSeen:
	.string "我的惊角鹿是世界上最可爱的。$"

PokefanM_Text_RexBeaten:
	.string "我的惊角鹿！$"

PokefanM_Text_RexAfter:
	.string "快看我的惊角鹿有多惹人喜爱！\p"
	.string "是不是可爱到心都要融化了？$"

PokefanM_Text_AllanSeen:
	.string "我的布鲁皇是世界上最可爱的。$"

PokefanM_Text_AllanBeaten:
	.string "我的布鲁皇！$"

PokefanM_Text_AllanAfter:
	.string "快看我的布鲁皇有多惹人喜爱！\p"
	.string "是不是可爱到心都要融化了？$"

