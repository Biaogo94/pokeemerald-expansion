SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_Blaine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	msgbox SeafoamIslands_Gym_Text_Blaine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "红莲宝可梦道馆馆主：夏伯\p"
    .string "获胜训练家：青绿、赤红$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "红莲宝可梦道馆馆主：夏伯\p"
    .string "获胜训练家：青绿、赤红、\n"
    .string "{PLAYER}$"

SeafoamIslands_Gym_Text_Blaine_GiveTM:
	.string "这个也给你！$"

SeafoamIslands_Gym_Text_Blaine_ExplainTM:
	.string "这个招式学习器里面是超厉害的“过\n"
	.string "热”！\p"
	.string "虽然能用压倒性的热量烧焦对手，但\n"
	.string "也会让自己的威力下降。\p"
	.string "希望你的下一个对手带够了灼伤药！\n"
	.string "哇哈哈！$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "夏伯：哇哈哈！\p"
	.string "我红莲镇的道馆全烧没了。\p"
	.string "托那座火山的福，我和喷火的宝可梦\n"
	.string "们都无家可归了。\p"
	.string "哇哈哈！\p"
	.string "不过我在这山洞里重开了道馆馆主的\n"
	.string "营生。\p"
	.string "你要是能打赢我，我就把徽章给你。\p"
	.string "哈！你最好备好灼伤药！$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "夏伯：太棒了。我已经完全燃尽了.\n"
	.string ".....\p"
	.string "深红徽章归你了！$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER}获得了深红徽章。$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "夏伯：虽然这次是我输了，但下次赢\n"
	.string "的会是我。\p"
	.string "等我重建了红莲道馆，咱们一定要再\n"
	.string "较量一次。$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "夏伯：我的火属性宝可梦会变得更强\n"
	.string "。\p"
	.string "你就走着瞧吧！$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "夏伯：噢！\p"
	.string "看来你已经成为关都冠军了啊！\p"
	.string "真是太炽热了！\p"
	.string "你的实力无可挑剔。\p"
	.string "我随时都乐意奉陪。\p"
	.string "要和我再来一场对战吗？$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "夏伯：你的实力真如烈火般炽热！\p"
	.string "竟然彻底突破了我的防线。$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "哟！\p"
	.string "......咦？已经结束了吗？\p"
	.string "抱歉抱歉！\p"
	.string "红莲道馆没了，我不知道去哪里找你\n"
	.string "。\p"
	.string "不过嘛，就算没有我的建议，你也足\n"
	.string "够强了。我就知道你会赢！$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "只要有道馆馆主在，哪里都可以是宝\n"
	.string "可梦道馆。\p"
	.string "根本不需要拘泥于建筑嘛。$"
