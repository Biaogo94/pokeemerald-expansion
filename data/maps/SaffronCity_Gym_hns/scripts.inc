SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "娜姿：我知道你会来……\p"
	.string "早在三年前，我就预见到了你的到来\n"
	.string "。\p"
	.string "你是为了得到我的徽章吧。\p"
	.string "我并不喜欢对战，但作为馆主，把徽\n"
	.string "章授予证明了自身实力的挑战者是我\l"
	.string "的职责所在。\p"
	.string "既然这是你的愿望，那就让你见识一\n"
	.string "下我的超能力吧！$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "娜姿：你的力量……\p"
	.string "远远超出了我的预见……\p"
	.string "也许，要彻底看透未来是不可能的吧\n"
	.string "......\p"
	.string "好吧，你赢了。这是你应得的金黄徽\n"
	.string "章。$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER}获得了金黄徽章！$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "娜姿：金黄徽章能激发出你的潜在能\n"
	.string "力……\p"
	.string "虽然我没能准确预见出你的力量，但\n"
	.string "唯有这一点我深信不疑。\p"
	.string "你定会成为一位受人爱戴的顶尖冠军\n"
	.string "！$"

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "来，把这个也收下吧。$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "里面记录着特性互换。\p"
	.string "它能将对手的特性夺走，并与自己的\n"
	.string "特性进行交换。\p"
	.string "要好好运用它……$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "娜姿：你对宝可梦的爱，压倒了我的\n"
	.string "超能力……\p"
	.string "我想，爱的力量也是一种超能力吧。\n"
	.string ".....$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "娜姿：啊，关都的冠军。\p"
	.string "我感应到你的归来了。\p"
	.string "你的力量大幅增长了呢。\p"
	.string "即便现在，我也能感受到你的气场。\p"
	.string "想和我再对战一场吗？$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "娜姿：你对宝可梦的爱，再次压倒了\n"
	.string "我的超能力……$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "被你打倒的那些人的力量，都汇聚到\n"
	.string "我这里了！$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "好强……实在太强了...\n"
	.string "...$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "你力量的源泉究竟是什么？$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "超能力就是心灵的力量。$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "你心灵的力量在我之上！$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "你变强的不仅仅是实力，还有你的灵\n"
	.string "魂。$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "呵呵呵呵……我看得很清楚\n"
	.string "。\p"
	.string "我能看透你的灵魂！$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "虽然读懂了你的心思，我还是输了。\n"
	.string ".....$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "哎呀！我都忘了我之前预知到自己会\n"
	.string "输给你了。$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "隔壁的格斗道馆曾经也是这个城市的\n"
	.string "官方道馆呢。$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "我完全不是对手……$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "格斗道馆的首领空手道大王，刚才被\n"
	.string "娜姿打得落花流水呢。$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "哟，未来的冠军！\p"
	.string "像你这么优秀的训练家，应该不需要\n"
	.string "我教你该怎么对付超能力属性的宝可\l"
	.string "梦了吧？\p"
	.string "我对你可是寄予厚望哦！\p"
	.string "祝你好运！$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "刚才那场对战也很精彩啊！$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "金黄宝可梦道馆馆主：娜姿\p"
    .string "胜出训练家：青绿、赤红$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "金黄宝可梦道馆馆主：娜姿\p"
    .string "胜出训练家：青绿、赤红、\n"
    .string "{PLAYER}$"
