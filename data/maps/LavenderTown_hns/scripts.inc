LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "那栋建筑真壮观，对吧？\p"
	.string "那是关都的广播电台塔。$"

LavenderTown_Text_Teacher:
	.string "关都有很多精彩的广播节目呢。$"

LavenderTown_Text_Gramps:
	.string "People come from all over to pay\n"
	.string "their respects to the departed\l"
	.string "souls of POKéMON.$"

LavenderTown_Text_Youngster:
	.string "要唤醒睡着的宝可梦，需要宝可梦之\n"
	.string "笛。\p"
	.string "这可是每位训练家都该知道的常识！$"

LavenderTown_Text_Sign:
	.string "紫苑镇\p"
	.string "高贵紫色的 安详小镇$"

LavenderTown_Text_KantoRadioStationSign:
	.string "KANTO RADIO STATION\p"
	.string "Your Favorite Programs On-Air\n"
	.string "Around the Clock!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "LAVENDER VOLUNTEER POKéMON\n"
	.string "HOUSE$"

LavenderTown_Text_SoulHouseSign:
	.string "灵魂之屋\p"
	.string "愿宝可梦的灵魂在此安息$"
