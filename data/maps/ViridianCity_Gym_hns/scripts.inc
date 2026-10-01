ViridianCity_Gym_hns_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE_HNS, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	msgbox ViridianCity_Gym_Text_LeaderBlue_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_TRICK_ROOM
	msgbox ViridianCity_Gym_Text_LeaderBlue_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	setvar VAR_OAK_MT_SILVER_CALL, 1
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "青绿：这么快就皮痒了，又想找虐？\p"
	.string "如果还想挑战我的话，就来格斗道场\n"
	.string "吧！$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "青绿：哟！总算到这了啊？\p"
	.string "在红莲岛时我可没那个心情，\p"
	.string "但现在我已经准备好和你对战了。\p"
	.string "......\p"
	.string "你说你称霸了城都的所有道馆？\p"
	.string "哼！那城都的道馆水平肯定挺差劲的\n"
	.string "吧。\p"
	.string "喂，别放在心上。\p"
	.string "只要现在和你打一场，我就知道你有\n"
	.string "几斤几两了。\p"
	.string "准备好了吗，城都的冠军？$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "青绿：什么？！\p"
	.string "我到底怎么会输给你啊？！\p"
	.string "......\p"
	.string "切，好吧……拿去吧--这是绿色徽章。$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER}获得了绿色徽章。$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "青绿：......\p"
	.string "好吧，是我看走眼了。你确实名副其\n"
	.string "实，是个出色的训练家。\p"
	.string "不过总有一天我会赢回来的。\p"
	.string "你可别忘了！$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "把这个也带上吧。$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "那是“戏法空间”。\p"
	.string "场上所有宝可梦的速度都会发生颠\n"
	.string "倒。速度慢的先行动，速度快的后行\l"
	.string "动。\p"
	.string "用它来彻底逆转战局吧。$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "青绿：听好了，\p"
	.string "在我打赢你之前，你可不准输给别\n"
	.string "人。听明白了没？$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "哟，未来的冠军！\p"
	.string "最近怎么样？看起来势头很猛嘛！\p"
	.string "这里的道馆馆主可是三年前和冠军交\n"
	.string "过手的人物哦。\p"
	.string "他可绝不是省油的灯。\p"
	.string "使出你的浑身解数上吧！$"

ViridianCity_Gym_Text_Guide_Win:
	.string "天哪，你可真厉害……\p"
	.string "那场对战太令人热血沸腾了，感动得\n"
	.string "我眼泪都要掉下来了。$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "常青宝可梦道馆馆主：青绿\p"
    .string "胜出训练家：青绿、赤红$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "常青宝可梦道馆馆主：青绿\p"
    .string "胜出训练家：青绿、赤红、\n"
    .string "{PLAYER}$"

