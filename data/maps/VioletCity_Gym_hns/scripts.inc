VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "I'm FALKNER, the VIOLET POKéMON\n"
	.string "GYM leader!\p"
	.string "People say you can clip\n"
	.string "FLYING-type POKéMON's wings\p"
	.string "with a jolt of electricity…\n"
	.string "I won't allow such insults to bird\l"
	.string "POKéMON!\p"
	.string "I'll show you the real power\n"
	.string "of the magnificent bird POKéMON!$"

VioletGym_Text_Falkner_WinLoss:
	.string "…Darn! My dad's cherished bird\n"
	.string "POKéMON…\p"
	.string "All right. Take this.\p"
	.string "It's the official POKéMON LEAGUE\n"
	.string "ZEPHYRBADGE.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER}获得了飞翼徽章。$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "ZEPHYRBADGE raises the ATTACK\n"
	.string "power of POKéMON.\p"
	.string "It also enables POKéMON to use\n"
	.string "FLASH, if they can learn it,\l"
	.string "anytime.\p"
	.string "Here--take this too.$"

VioletGym_Text_Falkner_TMExplain:
	.string "By using a TM, a POKéMON will\n"
	.string "instantly learn a new move.\p"
	.string "That TM contains ROOST.\p"
	.string "It restores HP up to half of your\n"
	.string "POKéMON's maximum.\p"
	.string "In other words, it heals your\n"
	.string "POKéMON.$"

VioletGym_Text_Falkner_AfterFight:
	.string "There are POKéMON GYMS in cities\n"
	.string "and towns ahead.\p"
	.string "You should test your skills at\n"
	.string "these GYMS.\p"
	.string "I'm going to train harder to\n"
	.string "become the greatest bird master!$"

VioletGym_Text_Falkner_Rematch:
	.string "恭喜你击败了四天王！\p"
	.string "我更加刻苦地特训了我的飞行属性宝\n"
	.string "可梦。\p"
	.string "你觉得自己还能再次对抗来自天空的\n"
	.string "力量吗？$"

VioletGym_Text_Falkner_RematchLoss:
	.string "哇......我又输给你了。\p"
	.string "我会更加努力修行，成为最出色的鸟\n"
	.string "使者！$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "The keyword is guts!\p"
	.string "Those here are training night and\n"
	.string "day to become bird POKéMON masters.\p"
	.string "Come on!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "哇啊啊！$"

VioletGym_Text_BirdKeeperRod_After:
	.string "阿速馆主的实力可是名不虚传！\p"
	.string "别以为赢了我就能得意忘形！$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "Let me see if you are good\n"
	.string "enough to face FALKNER!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "这不可能！$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "This is pathetic, losing to some\n"
	.string "rookie trainer…$"

VioletGym_Text_GymGuide_Intro:
	.string "Hey! What's up? I'm no trainer,\n"
	.string "but I can give some advice!\p"
	.string "Believe me! If you believe, a\n"
	.string "championship dream can come true.\p"
	.string "You believe? Then listen.\p"
	.string "FALKNER's ace is a bulky owl\n"
	.string "that loves to eat BERRIES.\p"
	.string "While it's not the strongest,\n"
	.string "it can take a lot of hits.\p"
	.string "You can hurt it with ELECTRIC \n"
	.string "and ROCK-type moves, but watch out\l"
	.string "for MUD-SLAP!\p"
	.string "If you want more help, go visit the\n"
	.string "POKéMON ACADEMY.\p"
	.string "The students there really know\n"
	.string "their stuff!$"

VioletGym_Text_GymGuide_Win:
	.string "精彩的对战！保持这个势头，用不了\n"
	.string "多久你就能成为冠军了！$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "桔梗市宝可梦道馆$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "VIOLET CITY POKéMON GYM\p"
	.string "FALKNER'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
