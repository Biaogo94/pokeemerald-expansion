FuchsiaCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Gym_OnTransition
	.byte 0

FuchsiaCity_Gym_OnTransition::
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_OnTransitionAfter
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_7
	call_if_defeated TRAINER_ALICE_HNS, FuchsiaCity_Gym_DefeatedAlice
	call_if_defeated TRAINER_LINDA_HNS, FuchsiaCity_Gym_DefeatedLinda
	call_if_defeated TRAINER_CINDY_HNS, FuchsiaCity_Gym_DefeatedCindy
	call_if_defeated TRAINER_BARRY_HNS, FuchsiaCity_Gym_DefeatedBarry
	end

FuchsiaCity_Gym_OnTransitionAfter::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	end

FuchsiaCity_Gym_DefeatedAlice::
	setflag FLAG_TEMP_2
	clearflag FLAG_TEMP_1
	return

FuchsiaCity_Gym_DefeatedLinda::
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_3
	return

FuchsiaCity_Gym_DefeatedCindy::
	setflag FLAG_TEMP_6
	clearflag FLAG_TEMP_5
	return

FuchsiaCity_Gym_DefeatedBarry::
	setflag FLAG_TEMP_8
	clearflag FLAG_TEMP_7
	return

FuchsiaCity_Gym_EventScript_Janine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_Janine_Defeated
	msgbox FuchsiaCity_Gym_Text_Janine_DisappointYou, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_JANINE_HNS, FuchsiaCity_Gym_Text_Janine_ToughOne
	message FuchsiaCity_Gym_Text_ReceivedSoulBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FuchsiaCity_Gym_Text_Janine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_POISON_JAB
	msgbox FuchsiaCity_Gym_Text_Janine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE14_GET
	setflag FLAG_DEFEATED_FUCHSIA_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 14
	call Common_EventScript_SetGymTrainers_hns
	removeobject LOCALID_FUCHSIAGYM_ALICE_J
	removeobject LOCALID_FUCHSIAGYM_CINDY_J
	removeobject LOCALID_FUCHSIAGYM_LINDA_J
	removeobject LOCALID_FUCHSIAGYM_BARRY_J
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	addobject LOCALID_FUCHSIAGYM_ALICE
	addobject LOCALID_FUCHSIAGYM_CINDY
	addobject LOCALID_FUCHSIAGYM_LINDA
	addobject LOCALID_FUCHSIAGYM_BARRY
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_3
	clearflag FLAG_TEMP_5
	clearflag FLAG_TEMP_7
	clearflag FLAG_HIDE_ROUTE22_JANINE
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Janine_Defeated::
	msgbox FuchsiaCity_Gym_Text_Janine_ApplyMyself, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_Text_Janine_DisappointYou:
	.string "呼呼呼呼……\p"
	.string "让你失望了呢……\p"
	.string "开玩笑的啦！\p"
	.string "本姑娘才是货真价实的！\p"
	.string "浅红道馆馆主阿杏，正是我！$"

FuchsiaCity_Gym_Text_Janine_ToughOne:
	.string "阿杏：你真厉害。毫无疑问，是你赢\n"
	.string "了……\p"
	.string "这是灵魂徽章。拿去吧。$"

FuchsiaCity_Gym_Text_ReceivedSoulBadge:
	.string "{PLAYER}获得了灵魂徽章。$"

FuchsiaCity_Gym_Text_Janine_GiveTM:
	.string "阿杏：你实力很强嘛！我有一份特别\n"
	.string "的礼物送你！$"

FuchsiaCity_Gym_Text_Janine_ExplainTM:
	.string "这是“毒击”，一记强力的毒属性招\n"
	.string "式，有时还能让对手陷入中毒状态。$"

FuchsiaCity_Gym_Text_Janine_ApplyMyself:
	.string "阿杏：我也要全力以赴，好好磨砺自\n"
	.string "己的本领。\p"
	.string "我要变得比父亲和你都更加强大！$"

FuchsiaCity_Gym_EventScript_Alice_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_ALICE_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_ALICE_J
	clearflag FLAG_TEMP_1
	addobject LOCALID_FUCHSIAGYM_ALICE
	applymovement LOCALID_FUCHSIAGYM_ALICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_ALICE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_LassAlice_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ALICE_HNS, FuchsiaCity_Gym_Text_LassAlice_Beaten
	msgbox FuchsiaCity_Gym_Text_LassAlice_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Alice::
	msgbox FuchsiaCity_Gym_Text_LassAlice_After, MSGBOX_NPC
	end


FuchsiaCity_Gym_EventScript_Linda_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_LINDA_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_LINDA_J
	clearflag FLAG_TEMP_3
	addobject LOCALID_FUCHSIAGYM_LINDA
	applymovement LOCALID_FUCHSIAGYM_LINDA, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_LINDA, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_LassLinda_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LINDA_HNS, FuchsiaCity_Gym_Text_LassLinda_Beaten
	msgbox FuchsiaCity_Gym_Text_LassLinda_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Linda::
	msgbox FuchsiaCity_Gym_Text_LassLinda_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_Cindy_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_CINDY_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_CINDY_J
	clearflag FLAG_TEMP_5
	addobject LOCALID_FUCHSIAGYM_CINDY
	applymovement LOCALID_FUCHSIAGYM_CINDY, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_CINDY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CINDY_HNS, FuchsiaCity_Gym_Text_PicnickerCindy_Beaten
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Cindy::
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_Barry_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_BARRY_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_BARRY_J
	clearflag FLAG_TEMP_7
	addobject LOCALID_FUCHSIAGYM_BARRY
	applymovement LOCALID_FUCHSIAGYM_BARRY, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_BARRY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_CamperBarry_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BARRY_HNS, FuchsiaCity_Gym_Text_CamperBarry_Beaten
	msgbox FuchsiaCity_Gym_Text_CamperBarry_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Barry::
	msgbox FuchsiaCity_Gym_Text_CamperBarry_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_Text_LassAlice_Before:
	.string "呼呼呼！\p"
	.string "我就是道馆馆主阿杏！\p"
	.string "--骗你的啦！上当了吧，笨蛋！$"

FuchsiaCity_Gym_Text_LassAlice_Beaten:
	.string "还以为把你骗到了呢……$"

FuchsiaCity_Gym_Text_LassAlice_After:
	.string "你能分辨出哪位才是我们真正的馆主\n"
	.string "吗？$"

FuchsiaCity_Gym_Text_LassLinda_Before:
	.string "上当了吧！哈哈哈！$"

FuchsiaCity_Gym_Text_LassLinda_Beaten:
	.string "呜呜……输了……\n"
	.string "你还挺有一手的嘛……$"

FuchsiaCity_Gym_Text_LassLinda_After:
	.string "怎么样？我的变装很完美吧？$"

FuchsiaCity_Gym_Text_PicnickerCindy_Before:
	.string "我就是阿杏！\p"
	.string "你是怎么看穿我是本尊的？\p"
	.string "来对战吧！$"

FuchsiaCity_Gym_Text_PicnickerCindy_Beaten:
	.string "可恶！真想赢一次啊！$"

FuchsiaCity_Gym_Text_PicnickerCindy_After:
	.string "你肯定已经晕头转向了吧。$"

FuchsiaCity_Gym_Text_CamperBarry_Before:
	.string "哇哈哈哈！\p"
	.string "被你猜中啦！我就是阿杏！$"

FuchsiaCity_Gym_Text_CamperBarry_Beaten:
	.string "我的变装明明惟妙惟肖！可恶！$"

FuchsiaCity_Gym_Text_CamperBarry_After:
	.string "喂，你瞧。我扮得可不可爱，嗯？$"

FuchsiaCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_GymGuyAfter
	msgbox FuchsiaCity_Gym_Text_Guide, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_GymGuyAfter::
	msgbox FuchsiaCity_Gym_Text_GuideWin, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_GymStatue::
    .string "浅红宝可梦道馆馆主：阿杏\p"
    .string "胜出训练家：青绿、赤红$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "浅红市宝可梦道馆馆主：阿杏\p"
    .string "胜出训练家：青绿、赤红、\n"
    .string "{PLAYER}$"

FuchsiaCity_Gym_Text_Guide:
	.string "哟，未来的冠军！\p"
	.string "哎呀！仔细看看你周围吧。\p"
	.string "这里的训练家全都打扮得和馆主阿杏\n"
	.string "一模一样。\p"
	.string "到底哪一个才是真正的阿杏呢？$"

FuchsiaCity_Gym_Text_GuideWin:
	.string "刚才的对战真精彩，来自城都的训练\n"
	.string "家！$"

