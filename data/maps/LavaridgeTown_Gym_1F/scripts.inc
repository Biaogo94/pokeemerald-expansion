LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "嗨，怎么样，向冠军目标冲刺的\n"
	.string "{PLAYER}？\p"
	.string "釜炎镇的道馆馆主亚莎使用火属性宝\n"
	.string "可梦，\p"
	.string "她对宝可梦的激情比火山还要炙热。\p"
	.string "别太接近她——你会被烧焦的！用水浇\n"
	.string "灭她的火焰，加油吧！$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "异常火热的对战啊！$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "啊啊啊啊！呀，好烫！$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "汗水把眼睛都遮住了……$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "埋在热沙子里可以促进血液循环，\p"
	.string "对治疗关节疼痛有好处。$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "我在想办法减轻压力，别过来再给我\n"
	.string "施压！$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "我想看到你被亚莎的火焰燃烧！$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "哈啊……呼……\p"
	.string "埋在热沙子里太久，都没力气了……$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "到现在你一定很累了，想在热沙子里\n"
	.string "休息一下，是吗？\p"
	.string "但对训练家来说，坚强的毅力是一种\n"
	.string "非常重要的品质。$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "玩火自焚了……$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "你的技术不错……但我们的馆主亚莎很\n"
	.string "强，\p"
	.string "你不小心的话会被烧焦的。$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "你的宝可梦能抵挡392度的高温吗"
	.string "？$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "火还不够热……$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "岩浆的温度是392度。\p"
	.string "你的宝可梦打败了我，那么在岩浆中\n"
	.string "也应该能比较容易生存下来。$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "呃……好吧，我就和你对战吧。$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "呀，你太强了。$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "我要成为亚莎那样漂亮又强大的训练\n"
	.string "家。$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "来对战吧！别让我的热情冷却！$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "周围那么热，我的心却好像掉进了冰\n"
	.string "窟……$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "凭你心中燃烧的战斗热情，你也许有\n"
	.string "机会胜过我们的馆主。$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "看到这熊熊燃烧的烈焰了吗？这闪烁\n"
	.string "的是对我胜利的期盼！$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "有什么事搞错了。$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "那又怎么样？我说那又怎么样！我能\n"
	.string "光着脚在热炭上走！\p"
	.string "……不用试也知道你是不可能做到的"
	.string "！$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "我喜欢高山，尤其喜欢火山。$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "呃，看来我无可挽回地失败了。$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "我留在这儿是因为迷上了亚莎的力\n"
	.string "量。\p"
	.string "呵呵呵呵。$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "欢迎……哦不，\p"
	.string "微不足道的挑战者啊，真高兴能看见\n"
	.string "你坚持到这里！\p"
	.string "爷爷托付我……我是说，\p"
	.string "我是亚莎，是这个道馆的馆主！\p"
	.string "那个……虽然我不久前才刚上任，但你\n"
	.string "可别小看我！\p"
	.string "我有爷爷传授给我的技巧，我会，那\n"
	.string "个……让你见识一下我们在这片土地上\l"
	.string "磨砺而出的火辣招式！$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "唉……大概是我太用力了……\p"
	.string "我……我才刚当上道馆馆主没多久。\p"
	.string "我太想扮成另一个自己，反而适得其\n"
	.string "反。\p"
	.string "我得用我自己的方式来。不然宝可梦\n"
	.string "们也会不知所措。\p"
	.string "谢谢你教会我这个道理。为此，这个\n"
	.string "给你。$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER}从亚莎那里得到了\n"
	.string "烈焰徽章。$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "有了烈焰徽章，所有等级50以内的宝\n"
	.string "可梦，即使是从别人那儿交换得来的\l"
	.string "也会完全听你的。\p"
	.string "另外，宝可梦也能在对战外使用秘传\n"
	.string "招式怪力了。\p"
	.string "这是我的小小谢礼，请别客气，收下\n"
	.string "吧！$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "那个招式学习器50里装着的是过热"
	.string "，\p"
	.string "能对对手造成巨大的伤害。\p"
	.string "但同时，使用它的宝可梦特攻会急剧\n"
	.string "下降。这个招式不太适合持久战。$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "把道馆馆主亚莎登记到宝可导航里\n"
	.string "了。$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "你的实力让我想起了某个人……\p"
	.string "哦！对了！你的战斗方式很像橙华道\n"
	.string "馆的道馆馆主千里。$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "釜炎镇宝可梦道馆$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "釜炎镇宝可梦道馆\p"
	.string "亚莎认可的训练家：\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "亚莎：打输一次不会让我泄气。\p"
	.string "我爱宝可梦，我爱对战，而且……我爱\n"
	.string "这间道馆！\p"
	.string "让我们用炙热的招式开战吧！$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "哇！火山喷发也不过如此吧！$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "亚莎：我输了，但是我很满足。\p"
	.string "像这样激烈的对战可不是每天都有\n"
	.string "的。\p"
	.string "有空的话再来一场吧！$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "亚莎：打输一次不会让我泄气。\p"
	.string "我爱宝可梦，我爱对战，而且……我爱\n"
	.string "这间道馆！\p"
	.string "让我们用炙热的招式开战吧！\p"
	.string "啊，慢着，你只带了1只可以对战的\n"
	.string "宝可梦？\p"
	.string "你来找我时至少得带2只宝可梦吧。$"
