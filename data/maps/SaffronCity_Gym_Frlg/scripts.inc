SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
	.string "我能预感到你的到来。\p"
	.string "当我还是个小女孩的时候，我拥有了\n"
	.string "超能力。\p"
	.string "那个早上我拿起汤勺使它弯曲了过\n"
	.string "来。\p"
	.string "虽然我厌恶暴力，但如果你是认真\n"
	.string "的，我是不会手下留情的！\l"
	.string "{PLAY_BGM}\l"
	.string "{MUS_RG_ENCOUNTER_GYM_LEADER}$"

SaffronCity_Gym_Text_SabrinaDefeat::
	.string "真是惊讶，我竟然输了！不过，输了\n"
	.string "就是输了。\p"
	.string "我承认，我没有用尽全力来取得胜\n"
	.string "利。\p"
	.string "为了嘉奖你的胜利，给予你这枚金黄\n"
	.string "徽章。$"

SaffronCity_Gym_Text_SabrinaPostBattle::
	.string "超能力并不只是少数人的特异功能。\p"
	.string "每个人都拥有超能力。只是人们没有\n"
	.string "意识到这一点罢了。$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
	.string "金黄徽章能让70级以下的宝可梦听从\n"
	.string "你的命令。\p"
	.string "强大的宝可梦会更具有野性，会在战\n"
	.string "斗中无视你的命令。\p"
	.string "为了避免这个问题，就不要把你的宝\n"
	.string "可梦训练得过于强大。\p"
	.string "等等，这个TM是给你的。$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
	.string "{PLAYER}从娜姿那里得到了\n"
	.string "TM04。$"

SaffronCity_Gym_Text_ExplainTM04::
	.string "TM04是冥想。\p"
	.string "它能让宝可梦集中起精力把它们的特\n"
	.string "攻和特防一起提升。$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
	.string "你的背包装满了其它道具。$"

SaffronCity_Gym_Text_AmandaIntro::
	.string "娜姿比我更年轻。但是我依然尊敬\n"
	.string "她。$"

SaffronCity_Gym_Text_AmandaDefeat::
	.string "做得还不够好！$"

SaffronCity_Gym_Text_AmandaPostBattle::
	.string "在普通的战斗中，更强的那只将会成\n"
	.string "为赢家。\p"
	.string "如果你想打败娜姿，就集中精神祈祷\n"
	.string "你能够胜利吧。$"

SaffronCity_Gym_Text_JohanIntro::
	.string "我们隐藏的力量吓到你了吗？$"

SaffronCity_Gym_Text_JohanDefeat::
	.string "我根本没料到这种事！$"

SaffronCity_Gym_Text_JohanPostBattle::
	.string "超能力属性宝可梦只害怕幽灵和虫子\n"
	.string "们！$"

SaffronCity_Gym_Text_StacyIntro::
	.string "从宝可梦身上看得出它们训练家的样\n"
	.string "子。\p"
	.string "你的宝可梦一定是强大的那种！$"

SaffronCity_Gym_Text_StacyDefeat::
	.string "我知道！$"

SaffronCity_Gym_Text_StacyPostBattle::
	.string "我还有得学呢……\p"
	.string "我必须掌握好超能力，然后教给我的\n"
	.string "宝可梦……$"

SaffronCity_Gym_Text_TyronIntro::
	.string "你明白了吗？\p"
	.string "只靠蛮力并不足以在宝可梦的世界中\n"
	.string "获胜？$"

SaffronCity_Gym_Text_TyronDefeat::
	.string "我不相信！$"

SaffronCity_Gym_Text_TyronPostBattle::
	.string "娜姿轻松地打败了隔壁的空手大王。$"

SaffronCity_Gym_Text_TashaIntro::
	.string "你和我，我们的宝可梦必须战上一\n"
	.string "场！$"

SaffronCity_Gym_Text_TashaDefeat::
	.string "最终还是我败了！$"

SaffronCity_Gym_Text_TashaPostBattle::
	.string "我早就知道会结果会是这样。$"

SaffronCity_Gym_Text_CameronIntro::
	.string "虽然娜姿很年轻，但她也是我们本领\n"
	.string "高强的领袖。\p"
	.string "你要超越她很难！$"

SaffronCity_Gym_Text_CameronDefeat::
	.string "噢！出局了！$"

SaffronCity_Gym_Text_CameronPostBattle::
	.string "在金黄曾经有两个宝可梦道馆。\p"
	.string "不过隔壁的格斗道场不再是道馆了。\p"
	.string "当我们决定只保留一个道馆时，我们\n"
	.string "就把它们简单地合并了。$"

SaffronCity_Gym_Text_PrestonIntro::
	.string "金黄宝可梦道馆以超能力训练而闻\n"
	.string "名。\p"
	.string "你想见娜姿，对吗？我已经预感到\n"
	.string "了！$"

SaffronCity_Gym_Text_PrestonDefeat::
	.string "哇啊！$"

SaffronCity_Gym_Text_PrestonPostBattle::
	.string "我用读心术了解了你的想法！没错！$"

SaffronCity_Gym_Text_GymGuyAdvice::
	.string "唷！未来的冠军！\p"
	.string "娜姿的宝可梦用超能力来对抗暴力。\p"
	.string "超能力属性宝可梦对格斗属性宝可梦\n"
	.string "效果拔群。\p"
	.string "甚至在它们还没打出一拳之前，就被\n"
	.string "撂翻在地了。$"

SaffronCity_Gym_Text_GymGuyPostVictory::
	.string "超能力的力量，哈？\p"
	.string "如果我也有，我就能把力量萃集在一\n"
	.string "起。$"

SaffronCity_Gym_Text_GymStatue::
	.string "金黄宝可梦道馆馆主：娜姿\p"
	.string "优胜训练家：{RIVAL}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "金黄宝可梦道馆馆主：娜姿\p"
	.string "优胜训练家：{RIVAL}，\n"
	.string "{PLAYER}$"

