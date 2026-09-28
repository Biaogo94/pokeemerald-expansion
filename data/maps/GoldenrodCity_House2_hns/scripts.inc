GoldenrodCity_House2_hns_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "有一次对战时，我的宝可梦使不出任\n"
    .string "何招式了。\p"
    .string "原来是招式的动力点数，也就是PP\n"
    .string "全都用光了。$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "有时候，即使宝可梦很健康，也可能\n"
    .string "会使不出招式。\p"
    .string "遇到这种情况，就去宝可梦中心治疗\n"
    .string "，或者使用道具吧。$"
