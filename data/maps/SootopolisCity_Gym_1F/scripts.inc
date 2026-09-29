SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "嗨，怎么样，向冠军目标冲刺的\n"
	.string "{PLAYER}？\p"
	.string "琉璃市的道馆馆主亚当是使用水属性\n"
	.string "宝可梦的大师，\p"
	.string "但要走到他面前，还要先通过冰结成\n"
	.string "的地面……\p"
	.string "很抱歉，我只能给你这一点建议。\p"
	.string "这条路，你要凭自己的智慧通过！$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "哟，被誉为丰缘第一的亚当都输给你\n"
	.string "了！\p"
	.string "好了！检查一下你的训练家卡，\p"
	.string "如果你集齐了所有徽章，就向宝可梦\n"
	.string "联盟出发吧！$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "让我问你。你知道吗？\l"
	.string "唉，我不该这么拐弯抹角。\p"
	.string "教会米可利一切宝可梦知识的人，\n"
	.string "正是我。\p"
	.string "我曾一度卸下\n"
	.string "道馆馆主的职位。\p"
	.string "把道馆托付给了米可利。\p"
	.string "然而，一个迫使我\n"
	.string "复出的理由出现了。\p"
	.string "啊，闲话到此为止。\n"
	.string "让我们开始对战吧。\p"
	.string "请务必见证我们的技艺。\p"
	.string "由宝可梦与我共同演绎的\n"
	.string "水之大幻境！$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "啊哈哈哈，好，好极了！你是赢家！\p"
	.string "在你身上，我看到了能克服一切的技\n"
	.string "巧的华丽光耀。\p"
	.string "然而，与我甚至米可利相比，你还欠\n"
	.string "缺优雅。\p"
	.string "也许我该借你一套衣服？\p"
	.string "…… …… ……\n"
	.string "…… …… ……\p"
	.string "哈哈哈，我只是在说笑！\p"
	.string "比起我的衣服，我更该给你这个，雨\n"
	.string "滴徽章。$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER}从亚当那里得到了\n"
	.string "雨滴徽章。$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "有了雨滴徽章，你所有的宝可梦都会\n"
	.string "完全服从你的每个指示。\p"
	.string "你也能使用秘传招式攀瀑攀登瀑布了\n"
	.string "。\p"
	.string "然后，为了不让你忘记这场对战，收\n"
	.string "下这个……$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "我交给你的这个招式学习器里面是水\n"
	.string "之波动。\p"
	.string "使用它时偶尔会因为超声波使目标陷\n"
	.string "入混乱。\p"
	.string "…… …… ……$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "把道馆馆主亚当登记到宝可导航里了\n"
	.string "。$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "收集了丰缘地区所有的道馆徽章的训\n"
	.string "练家应该朝向最后的目的地前进，\p"
	.string "那就是宝可梦联盟。\p"
	.string "向着丰缘的最东方，前往那名为彩悠\n"
	.string "的岛屿吧。\p"
	.string "那里便是宝可梦联盟之所在。$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "在丰缘地区仅剩最后1枚徽章了。\p"
	.string "如果你想挑战宝可梦联盟，你必须先\n"
	.string "获得茵郁市道馆的徽章。$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "琉璃市宝可梦道馆$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "琉璃市宝可梦道馆\p"
	.string "亚当认可的训练家：\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "亚当：啊，这间道馆终于恢复了它往\n"
	.string "日的风和日丽……\p"
	.string "但我们年轻的台风又再度袭来考验我\n"
	.string "们了！\p"
	.string "好的，我的朋友，当然！\p"
	.string "只要你想，我随时愿意与你共舞一曲\n"
	.string "！$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "啊哈哈哈，你是赢家！你又一次打败\n"
	.string "我了！$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "亚当：如果我说要收你做徒弟，我想\n"
	.string "你绝对会拒绝。\p"
	.string "我想要把我的外衣作礼物送给你，\p"
	.string "但如果我没想错的话，你肯定也会拒\n"
	.string "绝。\p"
	.string "我的朋友，这正是你的高贵的表现啊\n"
	.string "！$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "阿丹：啊，道馆好不容易恢复了\n"
	.string "往日的宁静……\p"
	.string "可我们的小旋风又回来\n"
	.string "考验我们了！\p"
	.string "好吧，我的朋友，当然可以！\n"
	.string "我很乐意与你共舞……\p"
	.string "啊，不不不。\n"
	.string "你只带了一只宝可梦。\p"
	.string "希望你带上两只，或者更多的\n"
	.string "宝可梦再来吧。$"

