RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "哟，怎么样？\p"
	.string "听好，朋友！你想成为冠军吗？\p"
	.string "我不是训练家，但我可以给你一些取\n"
	.string "胜的建议。\p"
	.string "那么说定了！我们一起朝着宝可梦冠\n"
	.string "军的目标前进！\p"
	.string "作为训练家，任务之一就是收集道馆\n"
	.string "徽章，对吗？\p"
	.string "但击败道馆馆主并没那么容易！\p"
	.string "因此我才会在这里！我会给你专业的\n"
	.string "建议！\p"
	.string "道馆馆主杜娟使用岩石属性宝可梦。\p"
	.string "岩石属性非常坚固，但它抵挡不了水\n"
	.string "属性和草属性招式。\p"
	.string "你打败道馆馆主之后再来找我吧。\p"
	.string "好了，加油！$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "哇！令人心驰的胜利！看来我的鼓励\n"
	.string "派上了用场！\p"
	.string "太好了！看看你的训练家卡，\p"
	.string "你得到的岩石徽章就记录在上面。\p"
	.string "换句话说……\p"
	.string "你踏上了通向冠军之路的第一级阶梯\n"
	.string "！\p"
	.string "感觉不错！$"

RustboroCity_Gym_Text_JoshIntro:
	.string "别小看我们道馆训练家！我会告诉你\n"
	.string "为什么我是最好的！$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "你比我厉害多了……$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "你还没有体会过岩石属性的可怕力量\n"
	.string "！$"

RustboroCity_Gym_Text_TommyIntro:
	.string "如果你不能打败我，就不可能打败杜\n"
	.string "娟！$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "哇！你的潜力很大！$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "杜娟可比我厉害好几倍。\p"
	.string "你最好提高警惕！$"

RustboroCity_Gym_Text_MarcIntro:
	.string "虽然这里是城镇中心，但那又如何？\p"
	.string "我的岩石宝可梦可需要大闹一场的空\n"
	.string "间！$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "哦，天哪！我们的挑战者这么强大！$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "只有交给我们的馆主了。\p"
	.string "这么年轻就培育岩石属性，真是辛苦\n"
	.string "她了。$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "您好，我是卡那兹市宝可梦道馆的馆\n"
	.string "主杜娟。\p"
	.string "我想要把在宝可梦训练家学校中所学\n"
	.string "到的东西都运用到宝可梦对战里面，\l"
	.string "所以才成为了道馆馆主。\p"
	.string "您要使用哪种宝可梦，如何对战，可\n"
	.string "以告诉我吗？$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "啊……是我输了……\p"
	.string "看来我还有许多东西要学……\p"
	.string "我知道了。\p"
	.string "宝可梦联盟规定战胜道馆馆主的训练\n"
	.string "家可以得到这个。\p"
	.string "请收下这枚宝可梦联盟公认的岩石徽\n"
	.string "章。$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER}从杜娟那里得到了\n"
	.string "岩石徽章。$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "岩石徽章能提高您的宝可梦的攻击力\n"
	.string "。\p"
	.string "有了它，您的宝可梦也能在对战外使\n"
	.string "用秘传招式居合劈了。\p"
	.string "然后……请您也收下这个。$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "那个招式学习器39中装着岩石封锁\n"
	.string "。\p"
	.string "用落石攻击对手的同时也能降低对手\n"
	.string "的速度。\p"
	.string "如果您使用招式学习器，宝可梦能立\n"
	.string "刻学会其中的招式。\p"
	.string "但一个招式学习器使用后就会消失，\n"
	.string "所以使用前要仔细考虑才行呢。$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "像您这么强的训练家为什么不去其他\n"
	.string "道馆挑战看看呢？\p"
	.string "通过和许许多多的训练家对战，您能\n"
	.string "够学到很多知识哟。$"

RustboroCity_Gym_Text_GymStatue:
	.string "卡那兹市宝可梦道馆$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "卡那兹市宝可梦道馆\p"
	.string "杜娟认可的训练家：\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "…… …… ………… …… ……\n"
	.string "哔！\p"
	.string "杜娟：哦，您好，是\n"
	.string "{PLAYER}吗？我是卡那兹市\l"
	.string "的杜娟。\p"
	.string "我从藤树那儿听说您已经是个小有名\n"
	.string "气的训练家了。\p"
	.string "但是，我认为我不会再输给您了。\p"
	.string "我保证，我会提升道馆的实力，您可\n"
	.string "以再来挑战我们。\p"
	.string "我希望您会像我一样期待那个时刻的\n"
	.string "到来！\p"
	.string "…… …… ………… ……咔哒！$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "把道馆馆主杜娟登记到宝可导航里了\n"
	.string "。$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "杜娟：我真高兴能再见到您。我是这\n"
	.string "个道馆的馆主杜娟。\p"
	.string "我相信我们可以再享受很多场像上次\n"
	.string "那样精彩的对战。\p"
	.string "我想看看我们彼此都变强了多少。让\n"
	.string "我们开始吧！$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "呃……我又输了……$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "杜娟：关于宝可梦对战，我还有许多\n"
	.string "事要学习。\p"
	.string "察觉到了这一点，让我更喜欢宝可梦\n"
	.string "对战了！$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "杜娟：我真高兴能再见到您。我是这\n"
	.string "个道馆的馆主杜娟。\p"
	.string "我相信我们可以再享受很多场像上次\n"
	.string "那样精彩的对战。\p"
	.string "我想看看我们彼此都变强了……\p"
	.string "哎，不……您只带了1只宝可梦？\p"
	.string "带至少2只宝可梦回来吧。$"
