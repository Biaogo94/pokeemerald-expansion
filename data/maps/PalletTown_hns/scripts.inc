PalletTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "我也在培育宝可梦呢。\p"
	.string "它们是我的私人保镖。$"

PalletTown_Text_Fisher:
	.string "科技的力量真厉害！\p"
	.string "现在的宝可梦竟然能像发电子邮件一\n"
	.string "样跨越时空进行交换！$"

PalletTown_Text_Sign:
	.string "真新镇\p"
	.string "象征和平与纯净的静谧之地$"

PalletTown_Text_RedsHouseSign:
	.string "赤红的家$"

PalletTown_Text_OaksLabSign:
	.string "大木宝可梦研究所$"

PalletTown_Text_BluesHouseSign:
	.string "青绿的家$"
