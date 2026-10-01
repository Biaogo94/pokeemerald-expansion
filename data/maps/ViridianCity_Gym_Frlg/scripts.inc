ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
	.string "哇哈哈哈！欢迎来到我的藏身之处！\p"
	.string "在我恢复火箭队往日的荣光前，我只\n"
	.string "能这么做。\p"
	.string "但是，你又找到了我。就这样吧。这\n"
	.string "一次，我不会再保留实力了！\p"
	.string "再一次，你将要面对坂木，那个最强\n"
	.string "大的训练家！{PLAY_BGM}\l"
	.string "{MUS_RG_ENCOUNTER_ROCKET}$"

ViridianCity_Gym_Text_GiovanniDefeat::
	.string "哈！真是激烈的战斗。你赢了！\p"
	.string "作为证据，这是绿色徽章！\n"
	.string "{PAUSE_MUSIC}\l"
	.string "{PLAY_BGM}\l"
	.string "{MUS_OBTAIN_BADGE}\l"
	.string "{PAUSE 0xFE}\l"
	.string "{PAUSE 0x56}\l"
	.string "{RESUME_MUSIC}$"

ViridianCity_Gym_Text_GiovanniPostBattle::
	.string "以这种方式落败，我没脸面对我的追\n"
	.string "随者。我背叛了他们对我的忠诚。\p"
	.string "在今天，火箭队永远地解散了。\p"
	.string "对我自己而言，我会倾其一生去再次\n"
	.string "修炼。\p"
	.string "也许我们将来可能会再见吧！永别\n"
	.string "了！$"

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
	.string "绿色徽章能使任何级别的宝可梦无理\n"
	.string "由地服从于你。\p"
	.string "这是你作为一个优秀的宝可梦训练家\n"
	.string "的证据。\p"
	.string "有了它，你就能挑战宝可梦联盟了。\p"
	.string "也带上这个技能。\p"
	.string "把它作为你挑战宝可梦联盟的礼物。$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
	.string "{PLAYER}从坂木那儿得到了\n"
	.string "TM26。$"

ViridianCity_Gym_Text_ExplainTM26::
	.string "TM26是地震。\p"
	.string "它能引起大地的震动，是一种强有力\n"
	.string "的攻击。\p"
	.string "很久以前我还在这儿开道馆时，我制\n"
	.string "造了这个技能……$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
	.string "你的背包满了！$"

ViridianCity_Gym_Text_YujiIntro::
	.string "嘿！现在喷雾一定用完了！$"

ViridianCity_Gym_Text_YujiDefeat::
	.string "我用完了喷雾！$"

ViridianCity_Gym_Text_YujiPostBattle::
	.string "要赶上我们的道馆馆主，你还需要更\n"
	.string "强大的力量。$"

ViridianCity_Gym_Text_AtsushiIntro::
	.string "嗷！我要暴走了！$"

ViridianCity_Gym_Text_AtsushiDefeat::
	.string "哇！$"

ViridianCity_Gym_Text_AtsushiPostBattle::
	.string "真是不值！$"

ViridianCity_Gym_Text_JasonIntro::
	.string "我和宝可梦，一起创造绝妙的音乐！$"

ViridianCity_Gym_Text_JasonDefeat::
	.string "你们相处得非常好！$"

ViridianCity_Gym_Text_JasonPostBattle::
	.string "你知道我们道馆馆主的身份吗？$"

ViridianCity_Gym_Text_KiyoIntro::
	.string "空手道是武术的究极形式！$"

ViridianCity_Gym_Text_KiyoDefeat::
	.string "啊哈！$"

ViridianCity_Gym_Text_KiyoPostBattle::
	.string "如果我的宝可梦像我一样擅长空手\n"
	.string "道……$"

ViridianCity_Gym_Text_WarrenIntro::
	.string "我的风格是靠真正的实力取胜。$"

ViridianCity_Gym_Text_WarrenDefeat::
	.string "我失去控制了！$"

ViridianCity_Gym_Text_WarrenPostBattle::
	.string "馆主会因为我就这样输了而责骂我\n"
	.string "的……$"

ViridianCity_Gym_Text_TakashiIntro::
	.string "我是空手道之王！你的命运取决于\n"
	.string "我！$"

ViridianCity_Gym_Text_TakashiDefeat::
	.string "啊！$"

ViridianCity_Gym_Text_TakashiPostBattle::
	.string "宝可梦联盟？你？别太狂妄了！$"

ViridianCity_Gym_Text_ColeIntro::
	.string "你的宝可梦会在我最重的打击之下颤\n"
	.string "抖！$"

ViridianCity_Gym_Text_ColeDefeat::
	.string "啊哒！啪！$"

ViridianCity_Gym_Text_ColePostBattle::
	.string "等着！我只是太不小心了！$"

ViridianCity_Gym_Text_SamuelIntro::
	.string "常青道馆关闭了很长时间。\p"
	.string "但是现在，我们的馆主回来了！$"

ViridianCity_Gym_Text_SamuelDefeat::
	.string "我输了！$"

ViridianCity_Gym_Text_SamuelPostBattle::
	.string "只有打败了我们的道馆馆主，你才有\n"
	.string "资格去宝可梦联盟！$"

ViridianCity_Gym_Text_GymGuyAdvice::
	.string "呦！未来的冠军！\p"
	.string "实际上连我也不知道常青馆主的身\n"
	.string "份。\p"
	.string "但是有件事情是确定的。他是所有道\n"
	.string "馆馆主之中最难对付的！\p"
	.string "而且，我听说这儿的训练家都喜欢使\n"
	.string "用地面属性宝可梦。$"

ViridianCity_Gym_Text_GymGuyPostVictory::
	.string "难以置信！坂木是常青的道馆馆主？$"

ViridianCity_Gym_Text_GymStatue::
	.string "常青宝可梦道馆馆主：？\p"
	.string "优胜训练家：{RIVAL}$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "常青宝可梦道馆馆主：坂木\p"
	.string "优胜训练家：{RIVAL}，\n"
	.string "{PLAYER}$"

