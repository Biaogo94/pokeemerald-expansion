MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "卡吉镇宝可梦道馆$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "卡吉镇宝可梦道馆\p"
	.string "柳伯认可的训练家：\n"
	.string "{PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
    .string "宝可梦的一生中，也会和我们一样经\n"
    .string "历各种各样的事情。\p"
    .string "老夫在漫长的人生中，也经历过许多\n"
    .string "风浪与磨难。\p"
    .string "既然老夫年长于你，就让你见识一下\n"
    .string "其中的深意吧。\p"
    .string "早在你出生之前，老夫便一直与宝可\n"
    .string "梦相伴至今。\p"
    .string "老夫可不会轻易言败。\p"
    .string "就由我冬之训练家--柳伯，来向你\n"
    .string "展示我的实力！$"

MahoganyTown_Gym_Text_PryceImpressed:
    .string "嗯，你的精湛实力让老夫深感佩服。\p"
    .string "凭借你那坚强的意志，定能跨越人生\n"
    .string "中的所有阻碍。\p"
    .string "这枚徽章非你莫属！$"

MahoganyTown_Gym_Text_ReceivedBadge:
    .string "{PLAYER}获得了冰之徽章！$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
    .string "那枚徽章能提高宝可梦的特攻。\p"
    .string "它还能让你的宝可梦使用“潮旋”，\n"
    .string "穿过现实中的旋涡。\p"
    .string "还有这个……这是老夫送你\n"
    .string "的礼物！$"

MahoganyTown_Gym_Text_HailSpeech:
    .string "那张招式学习器里面是“冰雹”。\p"
    .string "它能在5回合内，每回合都对对手造\n"
    .string "成伤害。\p"
    .string "充分展现了冬天的严苛与无情。$"

MahoganyTown_Gym_Text_CherishPokemon:
    .string "当冰雪消融，春天就会来临。\p"
    .string "你和你的宝可梦在未来的漫长岁月里\n"
    .string "，也将一直相伴相随。\p"
    .string "好好珍惜你们在一起的时光吧！$"

MahoganyTown_Gym_Text_PryceRematch:
    .string "啊，城都的冠军！\p"
    .string "你的实力的确非同凡响。\p"
    .string "令老夫深感钦佩。\p"
    .string "不过即使到了现在，我们彼此之间也\n"
    .string "仍有许多可以切磋学习的地方。\p"
    .string "老夫柳伯--这位冬之训练家--可\n"
    .string "还有几手绝活没亮出来呢。\p"
    .string "要和老夫再战一场吗？$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
    .string "啊，老夫又一次被你的高超实力所折\n"
    .string "服。\p"
    .string "凭着你那坚强的意志，必定能克服人\n"
    .string "生中的一切艰难险阻。$"

MahoganyTown_Gym_Text_Guide:
    .string "柳伯是位培育宝可梦长达50年之久\n"
    .string "的泰斗级老将。\p"
    .string "无论你派出怎样的宝可梦，他都有万\n"
    .string "全的阵容来应对。\p"
    .string "虽然火属性是不错的突破口，但千万\n"
    .string "要当心下雨天哦！$"

MahoganyTown_Gym_Text_GuideWin:
    .string "柳伯实力非凡，但你更是技高一筹！\p"
    .string "那场跨越世代代沟的对决，真是让人\n"
    .string "热血沸腾啊！$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
    .string "我要把你的宝可梦冻成冰块，让你动\n"
    .string "弹不得！$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
    .string "可恶，动弹不得的反而是我。$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
    .string "我记得宝可梦就算被冻住了，好像也\n"
    .string "有招式可以使用呢。$"

MahoganyTown_Gym_Text_BoarderBradSeen:
    .string "这家道馆的地面很滑吧。\p"
    .string "滑起来很过瘾，对不对？\p"
    .string "不过听好了--我们可不是在闹着玩\n"
    .string "的！$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
    .string "见识到我们有多认真了吧？$"

MahoganyTown_Gym_Text_BoarderBradAfter:
    .string "这家道馆太棒了。我最喜欢和我的宝\n"
    .string "可梦一起滑雪板了！$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
    .string "我知道柳伯的秘密哦。$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
    .string "好吧，我就把柳伯的秘密告诉你。$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
    .string "柳伯强大的秘密就是……\p"
    .string "他每天都会在瀑布下冥想，以此来锻\n"
    .string "炼自己的身心。$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
    .string "想见到我们的道馆馆主柳伯，滑冰前\n"
    .string "可得先动动脑筋。$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
    .string "要是比滑雪，我才不会输给你！$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
    .string "滑冰时如果不精准掌控方向，在这家\n"
    .string "道馆可寸步难行哦。$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
    .string "来见识一下我的平行转弯吧！$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
    .string "哇啊！你害我摔了个大跟头！$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
    .string "我真不该吹嘘自己的滑雪技术...\n"
    .string "...$"

