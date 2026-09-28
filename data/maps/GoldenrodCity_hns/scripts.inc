GoldenrodCity_hns_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SUNNY_DAY
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadenewbgm MUS_HG_ROCKET_TAKEOVER
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_Music2::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadedefaultbgm
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Trigger_MusicNotYet::
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	setspeaker GoldenrodCity_Text_ElmName
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROCKET_SCOUT
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "This is the GOLDENROD GYM!\p"
	.string "Our leader WHITNEY is not here\n"
	.string "right now. She might be at the\l"
	.string "RADIO TOWER.$"

GoldenrodCity_Text_Woman:
	.string "I used to train in WHITNEY's GYM,\n"
	.string "but all her crying gave me a\l"
	.string "headache.$"

GoldenrodCity_Text_HikerDay:
	.string "When I went into the GAME CORNER\n"
	.string "it was night time... How long was I\l"
	.string "in there?!$"

GoldenrodCity_Text_HikerNight:
	.string "When I went into the GAME CORNER\n"
	.string "it was day time... How long was I\l"
	.string "in there?!$"

GoldenrodCity_Text_Snubbull:
	.string "布鲁：布呜噜--！$"

GoldenrodCity_Text_MrMime:
	.string "............................$"

GoldenrodCity_Text_ElmName:
	.string "空木博士$"

GoldenrodCity_Text_ElmCall:
	.string "PROF.ELM: Hello, {PLAYER}?\n"
	.string "Has that EGG hatched yet?\p"
	.string "Once it hatches, don't forget to\n"
	.string "bring it by the lab! I need to\l"
	.string "see it!$"

GoldenrodCity_Text_PokefanM:
	.string "They built the new RADIO TOWER\n"
	.string "to replace the old creaky one.$"

GoldenrodCity_Text_Youngster1:
	.string "I know there's a new BIKE SHOP,\n"
	.string "but I can't find it anywhere.$"

GoldenrodCity_Text_CooltrainerF1:
	.string "Is that man in black dressed up\n"
	.string "like a TEAM ROCKET member?\p"
	.string "How silly!$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "Was that man in black really part\n"
	.string "of TEAM ROCKET? I can't believe it!$"

GoldenrodCity_Text_CooltrainerF2:
	.string "The RADIO TOWER in GOLDENROD CITY\n"
	.string "is quite the landmark.\p"
	.string "They're running a campaign now.\p"
	.string "They'll give you a shiny new\n"
	.string "RADIO if you can pass their quiz.$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "Oh, your POKéGEAR already works\n"
	.string "as a radio!$"

GoldenrodCity_Text_Youngster2:
	.string "E-he-he-he…\p"
	.string "I got in trouble for playing in\n"
	.string "the DEPT.STORE basement.$"

GoldenrodCity_Text_Lass:
	.string "That man inside rates your\n"
	.string "POKéMON nicknames.\p"
	.string "He can even rename them.$"

GoldenrodCity_Text_Gramps:
	.string "Whew! This town is so big,\n"
	.string "I can't find anything at all.$"

GoldenrodCity_Text_RocketScout1:
	.string "原来这就是广播电台啊......$"

GoldenrodCity_Text_RocketScout2:
	.string "What do you want, pest?\n"
	.string "Scram already!$"

GoldenrodCity_Text_Rocket1:
	.string "Stay out of the way!\n"
	.string "Beat it, kid!$"

GoldenrodCity_Text_Rocket2:
	.string "占领广播电台......\p"
	.string "看什么看？少多管闲事！$"

GoldenrodCity_Text_Rocket3:
	.string "宝可梦？那不过是我们用来赚钱的工\n"
	.string "具罢了！$"

GoldenrodCity_Text_Rocket4:
	.string "我们的梦想马上就要实现了....\n"
	.string "..\p"
	.string "这一路可真是一段漫长而艰辛的奋斗\n"
	.string "啊......$"

GoldenrodCity_Text_Rocket5:
	.string "喂，小鬼！这里可不是你该来的地方\n"
	.string "！赶紧滚一边去！$"

GoldenrodCity_Text_Rocket6:
	.string "来体会火箭队带来的恐怖吧！$"

GoldenrodCity_Text_StationSign:
	.string "满金市车站$"

GoldenrodCity_Text_RadioTowerSign:
	.string "满金广播电台$"

GoldenrodCity_Text_DeptStoreSign:
	.string "各类宝可梦周边一应俱全！\p"
	.string "满金百货公司$"

GoldenrodCity_Text_GymSign:
	.string "满金市宝可梦道馆馆主：小茜\p"
	.string "可爱到不可思议的美少女！$"

GoldenrodCity_Text_CitySign:
	.string "满金市\p"
	.string "热闹繁荣的魅力都市$"

GoldenrodCity_Text_BikeShopSign:
	.string "整个世界都是自行车道！自行车店$"

GoldenrodCity_Text_GameCornerSign:
	.string "属于你的游乐场！\p"
	.string "满金游戏城$"

GoldenrodCity_Text_NameRaterSign:
	.string "姓名鉴定师\p"
	.string "为你的宝可梦昵称进行鉴定$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "地下通路入口$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "地下通路入口$"


GoldenrodCity_Text_FlowerShopSign:
	.string "繁花盛开的花店$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "我可以传授给你的宝可梦非常厉害的\n"
	.string "招式哦！\p"
	.string "要让我教一个吗？$"

GoldenrodCity_Text_MoveTutorCost:
	.string "这需要花费1000枚代币。可以吗\n"
	.string "？$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "啊......可这些招式真的很棒\n"
	.string "呢！$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "哇哈哈！你绝不会后悔的！\p"
	.string "要学哪一个招式呢？$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "真遗憾。看来我得找家里要点零用钱\n"
	.string "了......$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "如果你能领悟这个招式，你就已经是\n"
	.string "一个合格的训练家了。$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "哇哈哈！再见啦，小鬼！$"

GoldenrodCity_Text_MoveTutorBut:
	.string "但、但是......$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "......你的代币不够哦...\n"
	.string "...$"
