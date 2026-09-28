OlivineCity_House2_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "去往湛蓝市的路上，有四座荒岛。\p"
	.string "不听话的坏孩子会被带去那些岛上受\n"
	.string "惩罚呢！$"

OlivineCity_Text_PunishmentBoy:
	.string "只要我一闯祸，哥哥就会拿这个吓唬\n"
	.string "我。$"
