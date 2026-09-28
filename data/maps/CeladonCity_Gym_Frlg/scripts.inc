CeladonCity_Gym_Frlg_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
	famechecker FAMECHECKER_ERIKA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
	famechecker FAMECHECKER_ERIKA, 4
	msgbox CeladonCity_Gym_Text_ErikaPostBattle
	release
	end

CeladonCity_Gym_EventScript_DefeatedErika::
	famechecker FAMECHECKER_ERIKA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_DEFEATED_ERIKA
	setflag FLAG_BADGE04_GET
	set_gym_trainers_frlg 4
	goto CeladonCity_Gym_EventScript_GiveTM19
	end

CeladonCity_Gym_EventScript_GiveTM19::
	msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis
	checkitemspace ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM19
	giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
	setflag FLAG_GOT_TM19_FROM_ERIKA
	msgbox CeladonCity_Gym_Text_ExplainTM19
	release
	end

CeladonCity_Gym_EventScript_NoRoomForTM19::
	msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	famechecker FAMECHECKER_ERIKA, 2
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	famechecker FAMECHECKER_ERIKA, 3
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_ErikaIntro::
	.string "Hello…\n"
	.string "Lovely weather, isn't it?\l"
	.string "It's so pleasant…\p"
	.string "…Oh, dear…\n"
	.string "I must have dozed off. Welcome.\p"
	.string "My name is ERIKA.\n"
	.string "I am the LEADER of CELADON GYM.\p"
	.string "I am a student of the art of\n"
	.string "flower arranging.\p"
	.string "My POKéMON are solely of the\n"
	.string "GRASS type.\p"
	.string "…Oh, I'm sorry, I had no idea that\n"
	.string "you wished to challenge me.\p"
	.string "Very well, but I shall not lose.{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeladonCity_Gym_Text_ErikaDefeat::
	.string "啊！我认输了。你真是太强了。\p"
	.string "我必须授予你彩虹徽章。$"

CeladonCity_Gym_Text_ErikaPostBattle::
	.string "你在收集宝可梦？真是一项了不起的\n"
	.string "工程啊！\p"
	.string "我从不收集不可爱的宝可梦。$"

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
	.string "彩虹徽章可以让50级以下的宝可梦\n"
	.string "听从你的指挥。\p"
	.string "它也可以让你的宝可梦在战斗中和战\n"
	.string "斗外都能使用怪力。\p"
	.string "也请你收下这个。$"

CeladonCity_Gym_Text_ReceivedTM19FromErika::
	.string "{PLAYER}从莉佳那里获得了\n"
	.string "TM19。$"

CeladonCity_Gym_Text_ExplainTM19::
	.string "TM19是终极吸取。\p"
	.string "这个技能造成伤害的一半会被你的宝\n"
	.string "可梦吸收过来回复体力。\p"
	.string "难道你不认为这是个非常棒的技能吗\n"
	.string "？$"

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
	.string "你的背包满了。$"

CeladonCity_Gym_Text_KayIntro::
	.string "我要给你介绍一下这个道馆。\p"
	.string "只有真正的淑女才被允许进入！$"

CeladonCity_Gym_Text_KayDefeat::
	.string "你太粗鲁了！$"

CeladonCity_Gym_Text_KayPostBattle::
	.string "啊啊！我真希望莉佳好好教训你一下\n"
	.string "！$"

CeladonCity_Gym_Text_BridgetIntro::
	.string "唔，你好。我正无聊呢。$"

CeladonCity_Gym_Text_BridgetDefeat::
	.string "我化的妆！$"

CeladonCity_Gym_Text_BridgetPostBattle::
	.string "草属性宝可梦对水属性很有优势。\p"
	.string "它们对岩石属性和地面属性宝可梦也\n"
	.string "是强大的存在。$"

CeladonCity_Gym_Text_TinaIntro::
	.string "……你之前是在偷看这里吗？$"

CeladonCity_Gym_Text_TinaDefeat::
	.string "你让我大开眼界！$"

CeladonCity_Gym_Text_TinaPostBattle::
	.string "啊，你是在看莉佳……不是看我……$"

CeladonCity_Gym_Text_TamiaIntro::
	.string "喂，喂！看看我的宝可梦！\p"
	.string "我喜欢草属性。它们培育起来很容易\n"
	.string "。$"

CeladonCity_Gym_Text_TamiaDefeat::
	.string "不！$"

CeladonCity_Gym_Text_TamiaPostBattle::
	.string "我们在道馆里只使用草属性宝可梦。\p"
	.string "至于为什么嘛，我们也用它们来插花\n"
	.string "的！$"

CeladonCity_Gym_Text_LisaIntro::
	.string "嘿，你好！\p"
	.string "我们不欢迎虫属性和火属性宝可梦！$"

CeladonCity_Gym_Text_LisaDefeat::
	.string "啊！你！$"

CeladonCity_Gym_Text_LisaPostBattle::
	.string "我们的馆主莉佳很文静，她在这一带\n"
	.string "可非常出名。$"

CeladonCity_Gym_Text_LoriIntro::
	.string "很高兴见到你。我的兴趣是训练宝可\n"
	.string "梦。$"

CeladonCity_Gym_Text_LoriDefeat::
	.string "啊！棒极了！$"

CeladonCity_Gym_Text_LoriPostBattle::
	.string "我马上要去相亲。所以必须得保持礼\n"
	.string "貌，特别是要对战的时候。$"

CeladonCity_Gym_Text_MaryIntro::
	.string "欢迎来到玉虹道馆！\p"
	.string "你最好不要小瞧了这里的小姐们。$"

CeladonCity_Gym_Text_MaryDefeat::
	.string "啊！输了！$"

CeladonCity_Gym_Text_MaryPostBattle::
	.string "我没带上我最厉害的宝可梦。下次等\n"
	.string "着瞧！$"

CeladonCity_Gym_Text_GymStatue::
	.string "玉虹宝可梦道馆馆主：莉佳\p"
	.string "获胜训练家：{RIVAL}$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
	.string "玉虹宝可梦道馆馆主：莉佳\p"
	.string "获胜训练家：{RIVAL}，\n"
	.string "{PLAYER}$"

