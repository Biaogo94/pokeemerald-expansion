EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "This happened when I was young.\p"
	.string "The sky suddenly turned black. A\n"
	.string "giant flying POKéMON was blocking\l"
	.string "out the sun.\p"
	.string "I wonder what that POKéMON was?\p"
	.string "It was like a bird and a dragon.$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "真的有那么巨大的宝可梦吗？\p"
	.string "如果真有的话，那它一定非常强大。$"
