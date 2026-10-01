LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllRegionalMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	specialvar VAR_RESULT, HasAllMons
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm
	specialvar VAR_RESULT, HasAllRegionalMons
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveOvalCharm
	special Special_ShowDiploma
	waitstate

	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveOvalCharm::
	checkitem ITEM_OVAL_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm::
	giveitem ITEM_OVAL_CHARM
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm::
	checkitem ITEM_SHINY_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveShinyCharm
	checkitem ITEM_OVAL_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveShinyCharm::
	giveitem ITEM_SHINY_CHARM
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "我是游戏设计师。\p"
	.string "哦，是吗？你在收集宝可梦图鉴？\p"
	.string "完成它并不容易，但也别放弃。\p"
	.string "如果你完成了，就来给我看看吧。$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "哇！太棒了！真的太棒了！\p"
	.string "这个宝可梦图鉴完成了！你一定很喜\n"
	.string "欢宝可梦！\p"
	.string "我好感动！\p"
	.string "我给你一件能彰显出你的成绩的东西\n"
	.string "吧！$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "我？你在跟我说话？我是程序员，\p"
	.string "我想知道这儿的老虎机是怎么样的。$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "我是美术设计师！丰缘地区的宝可梦\n"
	.string "很有趣吧？$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "泳圈女孩很可爱，不是吗？跟这么可\n"
	.string "爱的泳圈女孩对战……\p"
	.string "哇，太棒了！\p"
	.string "还有双胞胎！也很可爱不是吗？跟双\n"
	.string "胞胎2对2对战……\p"
	.string "哇，那是难以形容的快乐！$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "海风轻轻地挑逗着我的心。在这里的\n"
	.string "感觉真好！$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "你永远不知道什么时候会碰上挑战的\n"
	.string "人，\p"
	.string "所以我出门的时候从来都带着GBA"
	.string "。$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "亚希达： …… …… ………… …… ……Zzz……\p"
	.string "…… …… ……嗯？！哦，抱歉抱歉！我在\n"
	.string "打盹了！\p"
	.string "我是来看看宝可梦华丽大赛的。\p"
	.string "虽说看上去也确实挺有趣的，但是……\p"
	.string "像我这样的纯粹主义者——更钟爱对战\n"
	.string "与强大的训练家。\p"
	.string "但这只是就我而言。\p"
	.string "{PLAYER}{KUN}，希望\n"
	.string "你能享受一切，包括道馆，华丽大\l"
	.string "赛，对战帐篷，所有的一切！$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "亚希达：我想赢得华丽大赛也需要策\n"
	.string "略。\p"
	.string "要我说，制定华丽大赛的战略也是成\n"
	.string "为一个优秀训练家的途径之一。$"

