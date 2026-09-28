OneIsland_KindleRoad_EmberSpa_Frlg_MapScripts::
	.byte 0

OneIsland_KindleRoad_EmberSpa_EventScript_OldMan::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan1::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan2::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_OldWoman::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BlackBelt::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 3
	msgbox OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_RockSmashMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM06, OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa
	giveitem ITEM_HM06
	setflag FLAG_GOT_HM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_SpaHeal::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed
	setvar VAR_TEMP_1, 1
	releaseall
	end

OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore::
	.string "嗯！哈哈！\p"
	.string "真是天堂般的感受！这些温暖的水涌\n"
	.string "入我的心！\p"
	.string "你也应该跳进来的。\p"
	.string "到中间去，放松，去体会温暖和美好\n"
	.string "！$"

OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder::
	.string "马上要进行的是沐浴中我最喜欢的一\n"
	.string "个环节。\p"
	.string "我也喜欢吃下一碗大杂烩，享受从身\n"
	.string "体内部涌出温暖的感觉。$"

OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed::
	.string "水非常温暖。有一种绝妙的感觉……\p"
	.string "{PLAYER}的宝可梦完全恢复\n"
	.string "精神了！$"

OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic::
	.string "据说，泡温泉有益于身体健康。$"

OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs::
	.string "看看我的脸。我的皮肤是不是很光滑\n"
	.string "？\p"
	.string "泡温泉使我看起来更年轻。$"

OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion::
	.string "在经过一天辛苦的训练之后，没有比\n"
	.string "泡温泉更让人惬意的事了。\p"
	.string "我的一个前辈叫做希巴。有时会他会\n"
	.string "和他的宝可梦\p"
	.string "一起来到这个温泉，在这里做水疗。$"

OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa::
	.string "温泉是伴随着火山而产生的。\p"
	.string "几年前，我在这里建造了灯火温泉。\p"
	.string "我从一堆巨大的岩石中，亲手开辟出\n"
	.string "了这个池子。\p"
	.string "那时我使用了这招，我想我是时候该\n"
	.string "放开它了。$"

OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06::
	.string "就像它们是用饼干做的一样，我用这\n"
	.string "招砸碎了巨石。$"

