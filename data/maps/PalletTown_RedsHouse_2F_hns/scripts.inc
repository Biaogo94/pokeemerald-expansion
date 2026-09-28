PalletTown_RedsHouse_2F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER}玩了一会儿FC游\n"
	.string "戏机。\p"
	.string "该出发了--可没时间磨蹭了！$"

RedsHouse_Text_PC:
	.string "看来已经很久没有人用过了....\n"
	.string "..$"
