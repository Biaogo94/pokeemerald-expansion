SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "巴奥巴$"

SaffronCity_Text_Baoba:
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "I'm calling to tell you that the\n"
	.string "SAFARI ZONE has expanded again!\p"
	.string "Finally, my SAFARI ZONE has been\n"
	.string "fully realized!\p"
	.string "You remember where it is, right?\p"
	.string "Just west of CIANWOOD CITY!\n"
	.string "see you soon!$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "我最喜欢六尾了！:D$"

SaffronCity_Text_Lass1:
	.string "A little girl who is an expert at\n"
	.string "mimicking people lives here.\p"
	.string "She even mimics the people she's\n"
	.string "conversing with. It's confusing.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "The COPYCAT girl looked unhappy.\p"
	.string "She said she lost her favorite\n"
	.string "POKé DOLL--CLEFAIRY.$"

SaffronCity_Text_PokefanM:
	.string "You came out from JOHTO?\p"
	.string "You can zip back home if the\n"
	.string "MAGNET TRAIN's running.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "You came out from JOHTO?\p"
	.string "You can zip back home by hopping\n"
	.string "on the MAGNET TRAIN.$"

SaffronCity_Text_CooltrainerM:
	.string "I went to the GYM, raring for\n"
	.string "battles against trainers…\p"
	.string "It turns out, I stumbled into the\n"
	.string "unused GYM next door.\p"
	.string "Boy, I was pretty embarrassed.$"

SaffronCity_Text_CooltrainerF:
	.string "This is SILPH CO., famous for\n"
	.string "POKéMON merchandise.\p"
	.string "In the past, TEAM ROCKET wanted\n"
	.string "the company because of that.$"

SaffronCity_Text_Fisher:
	.string "Chew… Chew…\p"
	.string "I hear there's big trouble brewing\n"
	.string "at the POWER PLANT.\p"
	.string "Chew… Chew…$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "Chew… Chew…\p"
	.string "I hear there was big trouble at the\n"
	.string "POWER PLANT.\p"
	.string "Chew… Chew… Haaah, I'm full!$"

SaffronCity_Text_Youngster1:
	.string "Going into an alley for the first\n"
	.string "time makes me sorta anxious.$"

SaffronCity_Text_Youngster2:
	.string "There's a place called the CONTEST\n"
	.string "HALL in VIRIDIAN where trainers\l"
	.string "gather from all over the place.$"

SaffronCity_Text_Lass2:
	.string "Our city was featured on a radio\n"
	.string "program.\p"
	.string "It's nice to hear praise for your\n"
	.string "city, but it's a bit embarrassing\l"
	.string "too.$"

SaffronCity_Text_Sign:
	.string "金黄市\p"
	.string "闪耀黄金光芒的商业之都$"

SaffronCity_Text_GymSign:
	.string "金黄市宝可梦道馆馆主：娜姿\p"
	.string "超能力宝可梦的大师！$"

SaffronCity_Text_FightingDojoSign:
	.string "欢迎任何人挑战！格斗道场$"

SaffronCity_Text_SilphCoSign:
	.string "西尔佛公司办公大楼$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "超能力大叔的家$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "金黄市磁浮列车站$"
