FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "嗨，怎么样，向冠军的目标冲刺的\n"
	.string "{PLAYER}？\p"
	.string "茵郁市道馆馆主娜琪是飞行属性宝可\n"
	.string "梦大师，\p"
	.string "她在道馆的旋转门后面等着，\p"
	.string "等待着想要飞翔的挑战者！\p"
	.string "好了，加油吧！$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "你做到了！你飞上了天空！$"

FortreeCity_Gym_Text_JaredIntro:
	.string "观赏一下鸟类宝可梦优雅的战斗吧！$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "你……你真强……$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "训练家必须有面对意料之外的转变的\n"
	.string "智慧，\p"
	.string "你有足够的智慧到达我们的馆主那儿\n"
	.string "吗？$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "所有鸟类宝可梦爱好者都渴望进入这\n"
	.string "道馆，\p"
	.string "作为茵郁市道馆的一员，我不能输！$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "这对我来说压力太大了……$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "世界如此广大，在其中有数不清的优\n"
	.string "秀训练家。\p"
	.string "我得继续训练，让自己变得更强。$"

FortreeCity_Gym_Text_FlintIntro:
	.string "根本不需要我们馆主娜琪大人出手！\p"
	.string "由我对付你绰绰有余！$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "娜琪，我……我输了！$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "娜琪很可爱，也很强。她是最棒的馆\n"
	.string "主！\p"
	.string "脸红……$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "娜琪单独教过我！我不会轻易输给你\n"
	.string "的！$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "我败了……$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "多亏了娜琪，住在茵郁市的人们才能\n"
	.string "安居乐业。$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "当娜琪对战的时候，她的脸上闪耀着\n"
	.string "坚定的决心……\p"
	.string "我不会让你看到她那可爱的一幕！$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "哎！我阻止不了你。$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "你最好小心！别分心盯着娜琪看，否\n"
	.string "则你会败得一塌糊涂！$"

FortreeCity_Gym_Text_DariusIntro:
	.string "你最好知道世界上有多种多样的飞行\n"
	.string "属性宝可梦。\p"
	.string "你知道的，是吗？$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "看来你很清楚自己的实力！$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "你确实打败了我，但你最好小心点！\n"
	.string "我们的馆主娜琪的宝可梦都不好对付\l"
	.string "。$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "我是娜琪，茵郁道馆的道馆馆主。\p"
	.string "我和鸟宝可梦一起翱翔天际……\p"
	.string "无论对战多么艰辛，我们都会优雅地\n"
	.string "赢得胜利……\p"
	.string "见证我和鸟宝可梦的优美舞步吧！$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "我从没见过能比我更优雅地指挥宝可\n"
	.string "梦的训练家……\p"
	.string "为了表示对你那非凡才能的认可，我\n"
	.string "颁发这枚道馆徽章给你。$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER}从娜琪那里得到白\n"
	.string "羽徽章。$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "With the FEATHER BADGE, all POKéMON up\n"
	.string "to LV 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move FLY outside of battle.\p"
	.string "And this…\n"
	.string "This is a gift from me.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "招式学习器40的里面是燕返，\p"
	.string "它的速度……没有任何宝可梦能侥幸\n"
	.string "躲过。\p"
	.string "…… …… ……$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "把道馆馆主娜琪登记到宝可导航里了\n"
	.string "。$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "虽然我输给了你，但我仍会专注于鸟\n"
	.string "类宝可梦。$"

FortreeCity_Gym_Text_GymStatue:
	.string "茵郁市宝可梦道馆$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "茵郁市宝可梦道馆\p"
	.string "娜琪认可的训练家：\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "娜琪：我们人类永远无法逃离地心引\n"
	.string "力的束缚，\p"
	.string "但通过不断地完善自我，我们能拥有\n"
	.string "展翅高飞的力量！\p"
	.string "身为现任冠军，你已经拥有训练家中\n"
	.string "最顶尖的实力。\p"
	.string "拜托你，请允许我见识一下你那登峰\n"
	.string "造极的实力吧！$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "我还是没能触及你的高度……$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "娜琪：即便我败下阵来，心中的羽翼\n"
	.string "也绝不会折断。\p"
	.string "我依然可以一次又一次地展翅高飞。\p"
	.string "我对此坚信不疑！$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "娜琪：我们人类永远无法逃离地心引\n"
	.string "力的束缚，\p"
	.string "但通过不断地完善自我，我们能拥有\n"
	.string "展翅高飞的力量！\p"
	.string "身为现任冠军，你已经拥有训练家中\n"
	.string "最顶尖的实力。\p"
	.string "拜托你，请允许我见识一下你那登峰\n"
	.string "造极的实力吧！\p"
	.string "哎，不……你只带了1只宝可梦吗？\p"
	.string "至少带2只宝可梦再回来吧。$"
