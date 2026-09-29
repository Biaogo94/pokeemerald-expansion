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
	.string "到了晚上，皮皮们会出来在月见山玩\n"
	.string "耍呢。\p"
	.string "不过并不是每天晚上都会出来。$"

PewterCity_Text_Gramps:
	.string "啊，你大老远从城都地区过来吗？\p"
	.string "真让人怀念啊。我年轻的时候，也去\n"
	.string "城都修行过呢。\p"
	.string "看到你，就让我想起自己年轻时的模\n"
	.string "样。\p"
	.string "来，这个给你。这是我在城都找到的\n"
	.string "道具。$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "去往未知的崭新之地，邂逅形形色色\n"
	.string "的人……\p"
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
	.string "深灰市坚若磐石的灰色之城$"

PewterCity_Text_GymSign:
	.string "深灰市宝可梦道馆馆主：小刚\p"
	.string "坚如磐石的宝可梦训练家$"

PewterCity_Text_MuseumSign:
	.string "这里贴着一张告示……\p"
	.string "深灰科学博物馆因进行内部改装，现\n"
	.string "暂停开放……$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "这里贴着一张告示……\p"
	.string "月见山纪念品商店现已开业！$"

PewterCity_Text_WelcomeSign:
	.string "欢迎来到深灰市！$"

