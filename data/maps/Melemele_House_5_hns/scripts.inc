Melemele_House_5_hns_MapScripts::
	.byte 0


Melemele_House5_Mom::
	lock
	faceplayer
	msgbox Melemele_House5_Mom_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House5_Son::
	lock
	faceplayer
	msgbox Melemele_House5_Son_Text_0
	applymovement melemele_elio Melemele_House5_Son_Movement
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement
	msgbox Melemele_House5_Son_Text_1, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_MEOWTH, 0
	waitmoncry
	release
	end


Melemele_House5_Cat::
	lock
	faceplayer
	playmoncry SPECIES_MEOWTH, 0
	msgbox Melemele_House5_Cat_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

Melemele_House5_Son_Movement:
	jump_in_place_down
	jump_in_place_down
	step_end

Melemele_House5_Mom_Text_0:
	.string "我正考虑带我儿子朗日搬去阿罗拉地\n"
	.string "区。\p"
	.string "我们先在这座群岛上提前体验一下！$"

Melemele_House5_Son_Text_0:
	.string "嘿嘿……抓人游戏太好玩啦"
	.string "！$"

Melemele_House5_Son_Text_1:
	.string "来抓我呀，喵喵！$"

Melemele_House5_Cat_Text_0:
	.string "喵嗷呜呜呜呜呜！！！$"
