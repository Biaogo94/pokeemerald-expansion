PewterCity_Gym_hns_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_HNS, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK_HNS, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_SLIDE
	msgbox PewterCity_Gym_Text_Brock_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_BROCK, PewterCity_Gym_EventScript_Brock_Trade
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "小刚：哎呀，来自城都的挑战者还真\n"
	.string "是少见呢。\p"
	.string "我是深灰道馆的馆主小刚。\p"
	.string "我是岩石属性宝可梦的专家。\p"
	.string "我的宝可梦对大多数物理攻击都不屑\n"
	.string "一顾。你可很难给它们造成伤害哦。\p"
	.string "放马过来吧！$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "小刚：你的宝可梦用强力的攻击突破\n"
	.string "了我如岩石般坚固的防御....\l"
	.string "..\p"
	.string "你比我想象的还要强......\p"
	.string "收下吧--这是你的徽章。$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER}获得了灰色徽章。$"

PewterCity_Gym_Text_Brock_GiveTM:
	.string "来，把这个招式学习器也带上吧。$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "里面是“岩崩”。\p"
	.string "将岩石砸向对手，有时还能使对手畏\n"
	.string "缩。\p"
	.string "用它来让对手寸步难行吧。$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "小刚：{PLAYER}，谢谢你。\n"
	.string "虽然有点不甘心，但我很享受这场对\l"
	.string "战。\p"
	.string "有了灰色徽章，你的宝可梦会变得更\n"
	.string "加强大。$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "小刚：世界真的很宽广。还有很多像\n"
	.string "你一样强大的训练家。\p"
	.string "走着瞧吧，我也会变得更加强大的。$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "这个道馆的训练家都使用岩石属性宝\n"
	.string "可梦。\p"
	.string "岩石属性的防御力很高。\p"
	.string "对战可能会演变成持久战。你准备好\n"
	.string "了吗？$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "我一定要赢下这些对战才行....\n"
	.string "..$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "喂，你！城都来的训练家！小刚馆主\n"
	.string "可强着呢。你要是不认真对待，可有\l"
	.string "你吃苦头的！$"

PewterCity_Gym_Text_Guide:
	.string "哟！未来的冠军！你真是势不可挡\n"
	.string "啊。\p"
	.string "你正在挑战关都的道馆馆主吗？\p"
	.string "他们和城都的道馆馆主一样，既强大\n"
	.string "又全心全意投入哦。$"

PewterCity_Gym_Text_Guide_Win:
	.string "哟！未来的冠军！这个道馆对你来说\n"
	.string "根本不在话下嘛。\p"
	.string "你掌控全局的英姿真是太让人振奋\n"
	.string "了。我这话可是认真的哦。$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "深灰宝可梦道馆馆主：小刚\p"
    .string "胜出训练家：青绿、赤红$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "深灰宝可梦道馆馆主：小刚\p"
    .string "胜出训练家：青绿、赤红、\n"
    .string "{PLAYER}$"

PewterCity_Gym_EventScript_Brock_Trade::
	goto_if_set FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED, PewterCity_Gym_EventScript_BrockTradeCompleted
	ingame_trade INGAME_TRADE_BONSLY, PewterCity_Gym_Text_BrockWantToTrade, PewterCity_Gym_EventScript_BrockDeclineTrade, PewterCity_Gym_EventScript_BrockNotRequestedMon, PewterCity_Gym_Text_BrockTakeCare
	setflag FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED
	release
	end

PewterCity_Gym_EventScript_BrockDeclineTrade::
	msgbox PewterCity_Gym_Text_BrockDeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_Gym_Text_BrockNotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockTradeCompleted::
	msgbox PewterCity_Gym_Text_BrockTradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_BrockWantToTrade:
	.string "小刚：嗨，{PLAYER}。我在\n"
	.string "深山修行的时候遇到了这只小小的盆\l"
	.string "才怪。\p"
	.string "它很可爱，但我觉得它需要另一种风\n"
	.string "格的训练家。\p"
	.string "你愿意用{STR_VAR_1}来\n"
	.string "交换我的{STR_VAR_2}\l"
	.string "吗？$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "小刚：谢谢你！要替我好好照顾伍迪\n"
	.string "哦！$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "小刚：不愿意吗？没关系。我和伍迪\n"
	.string "会继续修行的。$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "小刚：那不是\n"
	.string "{STR_VAR_1}。不是我要\l"
	.string "找的那只宝可梦。$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "小刚：小树最近过得怎么样？盆才怪\n"
	.string "可比看起来结实多啦！$"
