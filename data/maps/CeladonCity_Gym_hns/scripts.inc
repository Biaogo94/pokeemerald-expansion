CeladonCity_Gym_hns_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA_HNS, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_Erika_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	msgbox CeladonCity_Gym_Text_Erika_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "莉佳：你好......天气真好呢\n"
	.string "，对吧？让人感觉好舒服.....\l"
	.string ".\p"
	.string "......我感觉自己都要打瞌睡\n"
	.string "了......\p"
	.string "我的名字叫莉佳。是玉虹道馆的馆主\n"
	.string "。\p"
	.string "......哎呀？你说你是一路从\n"
	.string "城都地区赶来的？真好呢.....\l"
	.string ".\p"
	.string "啊，对不起，我之前没察觉到你是想\n"
	.string "向我挑战呀。\p"
	.string "好吧，不过我可不会输给你哦。$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "莉佳：啊！我甘拜下风......\p"
	.string "你真是强得令人惊叹......\p"
	.string "这枚彩虹徽章就交给你吧.....\n"
	.string ".$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER}获得了彩虹徽章。$"

CeladonCity_Gym_Text_Erika_GiveTM:
	.string "莉佳：真是一场令人心情愉快的对战\n"
	.string "呢。\p"
	.string "让我深有感触。请收下这枚招式学习\n"
	.string "器吧。$"

CeladonCity_Gym_Text_Erika_ExplainTM:
	.string "这是“终极吸取”。\p"
	.string "这是一个非常神奇的招式，能将给予\n"
	.string "对手伤害的一半用来回复自己的\n"
	.string "HP。\p"
	.string "如果你喜欢的话，请务必用用看！$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "莉佳：输掉对战还是会让人有些心有\n"
	.string "不甘呢......\p"
	.string "但知道世上还有如此强大的训练家，\n"
	.string "也会激励我更加努力精进.....\l"
	.string ".$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "莉佳：哎呀，你好呀。\p"
	.string "真让人惊喜，关都的冠军！\p"
	.string "能再次见到你真是太高兴了。\p"
	.string "你的旅程一定非常精彩吧。\p"
	.string "就算是冠军，也会渴望挑战的吧。\p"
	.string "要和我再来一场对战吗？$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "莉佳：输掉对战果然还是会让人心有\n"
	.string "不甘呢......\p"
	.string "但知道世上还有如此强大的训练家，\n"
	.string "也会激励我更加努力精进.....\l"
	.string ".$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE_HNS, CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "你觉得只有女孩子的道馆很罕见吗？$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "啊，讨厌！$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "我只是一时大意罢了！$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA_HNS, CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "哎？要对战吗？虽然有点害怕，但没\n"
	.string "问题！$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "哎，这就结束了吗？$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "哇，看看你身上的徽章。难怪我赢不\n"
	.string "了呢！$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_HNS, CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "你刚才是在看这些花，还是在看我\n"
	.string "呢？$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "真讨厌！$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "要怎样才能变得像莉佳小姐那样淑女\n"
	.string "呢？$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "让你见识一下莉佳小姐传授给我们的\n"
	.string "宝可梦招式！$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "呜......输掉了......$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "莉佳小姐会替我们赢回来的！$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "我们要保护莉佳小姐！$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "还是赢不了啊......$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "莉佳小姐可要强得多得多呢！$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "玉虹市宝可梦道馆馆主：莉佳\p"
    .string "获胜训练家：青绿、赤红$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "玉虹市宝可梦道馆馆主：莉佳\p"
    .string "获胜训练家：青绿、赤红、\n"
    .string "{PLAYER}$"
