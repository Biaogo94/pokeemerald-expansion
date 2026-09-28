PewterCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "你去过深灰道馆了吗？\p"
	.string "馆主使用的是岩石属性的宝可梦。$"

PewterCity_Text_BugCatcher:
	.string "At night, CLEFAIRY come out to play at\n"
	.string "MT.MOON.\p"
	.string "But not every night.$"

PewterCity_Text_Gramps:
	.string "Ah, you came all the way out here from\n"
	.string "JOHTO?\p"
	.string "That brings back memories. When I was\n"
	.string "young, I went to JOHTO to train.\p"
	.string "You remind me so much of what I was like\n"
	.string "as a young man.\p"
	.string "Here. I want you to have this item I\n"
	.string "found in JOHTO.$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "去往未知的崭新之地，邂逅形形色色\n"
	.string "的人......\p"
	.string "这就是旅行的乐趣所在啊。$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "PEWTER CITY\n"
	.string "A Stone Gray City$"

PewterCity_Text_GymSign:
	.string "PEWTER CITY POKéMON GYM\n"
	.string "LEADER: BROCK\p"
	.string "The Rock Solid POKéMON Trainer$"

PewterCity_Text_MuseumSign:
	.string "There's a notice here…\p"
	.string "PEWTER MUSEUM OF SCIENCE is closed for\n"
	.string "renovations…$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "这里贴着一张告示......\p"
	.string "月见山纪念品商店现已开业！$"

PewterCity_Text_WelcomeSign:
	.string "欢迎来到深灰市！$"

