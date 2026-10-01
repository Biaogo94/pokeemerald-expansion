Route7_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "这是什么告示？\p"
	.string "……由于粗暴的训练家们在地下通道内\n"
	.string "肆意对战，\p"
	.string "鉴于当地居民的抗议不断增加，地下\n"
	.string "通道将无限期封闭。\p"
	.string "玉虹警察署$"

Route7_Text_LockedDoor:
	.string "门锁着……$"

