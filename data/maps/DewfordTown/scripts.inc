DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0

DewfordTown_OnTransition:
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

DewfordTown_EventScript_Briney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_ReturnToPetalburgPrompt
	message DewfordTown_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_ChoosePetalburg
	case 1, DewfordTown_EventScript_ChooseSlateport
	case 2, DewfordTown_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect
	end

DewfordTown_EventScript_ChoosePetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	release
	end

DewfordTown_EventScript_ChooseSlateport::
	msgbox DewfordTown_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToSlateport
	release
	end

DewfordTown_EventScript_CancelSailSelect::
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_ReturnToPetalburgPrompt::
	msgbox DewfordTown_Text_SetSailBackToPetalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_SailBackToPetalburg
	msgbox DewfordTown_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailBackToPetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail2, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	end

DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	end

DewfordTown_EventScript_GiveOldRod::
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_HowsFishing::
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_FishingExcellent::
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_FishingNotSoGood::
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailToPetalburg::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_DEWFORD_BRINEY, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_DEWFORD_BRINEY
	applymovement LOCALID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_DEWFORD_BOAT, DewfordTown_Movement_SailToPetalburg
	applymovement LOCALID_PLAYER, DewfordTown_Movement_SailToPetalburg
	waitmovement 0
	showobjectat LOCALID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement LOCALID_PLAYER, DewfordTown_Movement_ExitBoatPetalburg
	waitmovement 0
	showobjectat LOCALID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_DEWFORD_BOAT, MAP_DEWFORD_TOWN
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	resetobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_SailToSlateport::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement LOCALID_DEWFORD_BRINEY, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_DEWFORD_BRINEY
	applymovement LOCALID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_DEWFORD_BOAT, DewfordTown_Movement_SailToSlateport
	applymovement LOCALID_PLAYER, DewfordTown_Movement_SailToSlateport
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat LOCALID_PLAYER, MAP_ROUTE109
	applymovement LOCALID_PLAYER, DewfordTown_Movement_ExitBoatSlateport
	waitmovement 0
	setobjectxyperm LOCALID_ROUTE109_BRINEY, 21, 26
	addobject LOCALID_ROUTE109_BRINEY
	setobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_ROUTE109, 0
	applymovement LOCALID_ROUTE109_BRINEY, DewfordTown_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	addobject LOCALID_ROUTE109_BOAT
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_DEWFORD_BOAT, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateportDeliverGoods
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateport
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_ROUTE109
	copyobjectxytoperm LOCALID_ROUTE109_BRINEY
	release
	end

DewfordTown_EventScript_LandedSlateportDeliverGoods::
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_LandedSlateport::
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

DewfordTown_Movement_SailToPetalburg:
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_SailToSlateport:
	walk_right
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_PlayerBoardBoat:
	walk_right
	walk_up
	step_end

DewfordTown_Movement_ExitBoatPetalburg:
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_ExitBoatSlateport:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

DewfordTown_Movement_BrineyBoardBoat:
	walk_up
	step_end

DewfordTown_Movement_BrineyExitBoat:
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
	end

DewfordTown_EventScript_ConfirmTrendyPhrase::
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_RejectTrendyPhrase::
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
	end

DewfordTown_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_CancelNewTrendyPhrase::
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_PhraseNotTrendyEnough::
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_TinyIslandCommunity:
	.string "武斗镇是个很小的岛镇，如果什么在\n"
	.string "这儿流行起来，很快所有人都会开始\l"
	.string "谈论。$"

DewfordTown_Text_TownSign:
	.string "这里是武斗镇。“漂浮在蓝海上的小\n"
	.string "岛。”$"

DewfordTown_Text_GymSign:
	.string "武斗镇宝可梦道馆馆主：藤树“格斗\n"
	.string "浪潮！”$"

DewfordTown_Text_HallSign:
	.string "武斗镇大厅“信息交换处！”$"

Route104_Text_LandedInDewfordDeliverLetter:
	.string "哈奇：喂！我们到武斗镇啦！\p"
	.string "我想你要去给那个……大吾，送信是\n"
	.string "吧！$"

DewfordTown_Text_SetSailBackToPetalburg:
	.string "哈奇：你已经送完信了吗？\p"
	.string "还是你想回橙华市去？$"

DewfordTown_Text_PetalburgWereSettingSail2:
	.string "哈奇：目标，橙华市！\p"
	.string "起锚！小皮，亲爱的，出海了！$"

DewfordTown_Text_GoDeliverIllBeWaiting:
	.string "哈奇：那你去送信吧，我就在这儿等\n"
	.string "着。$"

DewfordTown_Text_BrineyLandedInDewford:
	.string "哈奇：喂！我们到武斗镇了！\p"
	.string "想再出海随时叫我！$"

DewfordTown_Text_WhereAreWeBound:
	.string "哈奇：喂！为了你我随时都能出海！\p"
	.string "说吧朋友，这次想去哪儿？$"

DewfordTown_Text_PetalburgWereSettingSail:
	.string "哈奇：橙华市是吗？\p"
	.string "起锚！小皮，亲爱的，出海了！$"

DewfordTown_Text_SlateportWereSettingSail:
	.string "哈奇：凯那市是吗？\p"
	.string "起锚！小皮，亲爱的，出海了！$"

DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
	.string "哈奇：想再出海随时叫我！$"

DewfordTown_Text_GettingItchToFish:
	.string "这里是著名的钓场。你渴望钓鱼吗？$"

DewfordTown_Text_GiveYouOneOfMyRods:
	.string "我听到了，我真高兴你能这么说！\p"
	.string "我就把我的钓竿给你一支吧。$"

DewfordTown_Text_ThrowInFishingAdvice:
	.string "作为附送，我给你几条钓鱼的建议\n"
	.string "吧！\p"
	.string "首先，面对水面，甩出钓竿。\p"
	.string "集中精神……鱼咬钩的时候，拉起钓\n"
	.string "竿。\p"
	.string "有时你马上就能钓到什么，但想钓大\n"
	.string "家伙的话，你就得计算好钓的晃动次\l"
	.string "数才能拖它们上来。$"

DewfordTown_Text_ThatsTooBadThen:
	.string "哦，是吗？真遗憾。$"

DewfordTown_Text_HowsYourFishing:
	.string "哟！鱼钓得怎么样了？$"

DewfordTown_Text_GreatHaulInSomeBigOnes:
	.string "是吗！太好了！继续钓更大的鱼吧！$"

DewfordTown_Text_FishingAdvice:
	.string "好了，别沮丧，！我给你点钓鱼的建\n"
	.string "议。\p"
	.string "首先，面对水面，甩出钓竿。\p"
	.string "集中精神……鱼咬钩的时候，拉起钓\n"
	.string "竿。\p"
	.string "有时你马上就能钓到什么，但想钓大\n"
	.string "家伙的话，你就得计算好钓竿的晃动\l"
	.string "次数才能拖它们上来。$"

DewfordTown_Text_XIsTheBiggestHappeningThingRight:
	.string "我知道什么在发生，什么最时髦，我\n"
	.string "一直在调查。\p"
	.string "你听说过这个新词\n"
	.string "“{STR_VAR_1}”吗？\p"
	.string "没错！你当然知道！\p"
	.string "我是说，嘘\n"
	.string "“{STR_VAR_1}”……是现在\l"
	.string "最新最热的词！\p"
	.string "无论你从哪儿来，\n"
	.string "“{STR_VAR_1}”都是最重\l"
	.string "要的事，对吗？$"

DewfordTown_Text_TellMeWhatsNewAndIn:
	.string "嗯？这不是现在最流行的吗？\p"
	.string "哎，那么，你得告诉我，现在最流行\n"
	.string "的是什么？$"

DewfordTown_Text_OfCourseIKnowAboutThat:
	.string "呃？“{STR_VAR_2}”？\p"
	.string "……\p"
	.string "……呃……对！没错！我知道！一直都知\n"
	.string "道！\p"
	.string "我当然知道！\n"
	.string "“{STR_VAR_2}”，对吗？\p"
	.string "对，是它，就是它！\n"
	.string "“{STR_VAR_2}”不就是最\l"
	.string "酷的词吗？\p"
	.string "不就是在潮流最尖端的词吗？你以为\n"
	.string "我不知道吗？\p"
	.string "“{STR_VAR_1}”……那只\n"
	.string "是，呃，五分钟前的事了，\p"
	.string "现在，“{STR_VAR_2}”才\n"
	.string "是最重要最时兴的！$"

DewfordTown_Text_XHuhIThinkYIsCool:
	.string "唔……“{STR_VAR_2}”？\p"
	.string "但我觉得，\n"
	.string "“{STR_VAR_1}”才是最棒\l"
	.string "的。$"

DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
	.string "那，如果你听说了什么新的流行词，\n"
	.string "来跟我说说好吗？$"

DewfordTown_Text_YeahDefinitionOfInRightNow:
	.string "没错，完全正确！\p"
	.string "现在“{STR_VAR_1}”就是\n"
	.string "流行！$"
