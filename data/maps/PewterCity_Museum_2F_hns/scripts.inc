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
	.string "They say that meteorites struck\n"
	.string "BIRTH ISLAND.\p"
	.string "We would love to display them here\n"
	.string "in our museum, but...\p"
	.string "These meteorites are said to emit\n"
	.string "strange energy and cannot be\l"
	.string "carried away...$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "I want a PIKACHU!\n"
    .string "It's so cute!\p"
    .string "I asked my daddy to catch me one!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "好好好，很快就给你抓皮卡丘，我保\n"
    .string "证！$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "航天飞机$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "落在月见山上的陨石。被认为是一块\n"
    .string "月之石。$"
