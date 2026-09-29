Route1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY_HNS, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN_HNS, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "训练家相遇，第一件事当然是对战！$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "呜呜……我的负场又增加了\n"
	.string "......$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "对于训练家来说，相遇即对战是理所\n"
	.string "当然的！$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "那边的！要不要来对战？$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "彻底被打垮了……$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "你真强。\p"
	.string "显然是经过了刻苦的特训吧。$"

Route1_Text_Sign:
	.string "1号道路\p"
	.string "真新镇 - 常青市$"
