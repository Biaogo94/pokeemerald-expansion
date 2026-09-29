PewterCity_Museum_2F_hns_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "据说曾有陨石坠落在诞生之岛。\p"
	.string "我们原本很想把它们陈列在博物馆\n"
	.string "里，可是……\p"
	.string "据说那些陨石散发着奇特的能量，根\n"
	.string "本无法搬走……$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "我想要一只皮卡丘！它太可爱啦！\p"
    .string "我已经让爸爸帮我抓一只了！$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "好好好，很快就给你抓皮卡丘，我保\n"
    .string "证！$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "航天飞机$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "落在月见山上的陨石。被认为是一块\n"
    .string "月之石。$"
