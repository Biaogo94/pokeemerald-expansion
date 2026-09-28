Route42_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route42_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route42_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route42_MapScript_HideTrigger::
	setvar VAR_TEMP_0, 1
	return

Route42_EventScript_Suicune_Trigger::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune3
	applymovement OBJ_EVENT_ID_PLAYER, Route42_Movement_Player
	playse SE_LEDGE
	delay 60
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE42_SUICUNE
	waitmovement 0
	delay 60
	removeobject LOCALID_ROUTE42_SUICUNE
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_HIDE_ROUTE42_EUSINE
	addobject LOCALID_ROUTE42_EUSINE
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine1
	waitmovement 0
	msgbox Route42_Text_EusineAdmireSuicune, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE42_EUSINE, DIR_WEST
	msgbox Route42_Text_EusineJealous, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE42_EUSINE, DIR_EAST
	msgbox Route42_Text_EusineWontGiveUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine2
	waitmovement 0
	setflag FLAG_HIDE_ROUTE42_EUSINE
	removeobject LOCALID_ROUTE42_EUSINE
	setvar VAR_TEMP_0, 1
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 2, Route42_EventScript_DoneJohtoSuicune
	release
	end

Route42_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

Route42_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	step_end

Route42_Movement_Suicune2:
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_up
	step_end

Route42_Movement_Suicune3:
	jump_in_place_up
	delay_2
	face_up
	jump_2_up
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

Route42_Movement_Player:
	lock_facing_direction
	delay_2
	jump_2_up
	unlock_facing_direction
	step_end

Route42_Movement_Eusine1:
	walk_down
	walk_down
	walk_left
	face_right
	step_end

Route42_Movement_Eusine2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route42_Text_EusineAdmireSuicune:
	.string "米那君：水君......它是多么\n"
	.string "英武！\p"
	.string "它是多么清澈！它是多么美丽！\p"
	.string "而且它的身姿是何等迅捷！$"

Route42_Text_EusineJealous:
	.string "{PLAYER}！\p"
	.string "只要是水君出现的地方，似乎总能看\n"
	.string "到你的身影呢。\p"
	.string "不过，这也无所谓。我对追求水君的\n"
	.string "那份执着，可是远远超越你的..\l"
	.string "....\p"
	.string "我爷爷曾经......对神话传说\n"
	.string "非常痴迷。\p"
	.string "我从小就从他那里听过许多关于水君\n"
	.string "的故事。$"

Route42_Text_EusineWontGiveUp:
	.string "水君......在查明你的真正目\n"
	.string "的之前，我是绝对不会放弃追踪你的\l"
	.string "......\p"
	.string "你听到了吗！$"


Route42_EventScript_Tully::
	trainerbattle_single TRAINER_TULLY_HNS, Route42_Text_FisherTullySeen, Route42_Text_FisherTullyBeaten, Route42_EventScript_RegisterTully
	goto_if_set FLAG_TULLY_HAS_ITEM_HNS, Route42_EventScript_TullyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route42_EventScript_RematchTully
	msgbox Route42_Text_FisherTullyAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_RegisterTully::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route42_Text_TullyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TULLY_HNS
	release
	end

Route42_EventScript_RematchTully::
	trainerbattle_rematch TRAINER_TULLY_HNS, Route42_Text_TullyRematchIntro, Route42_Text_TullyRematchDefeat
	msgbox Route42_Text_TullyPostRematch, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_TullyGiveItem::
	msgbox Route42_Text_TullyHasItem, MSGBOX_DEFAULT
	giveitem VAR_TULLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route42_EventScript_TullyNoRoom
	clearflag FLAG_TULLY_HAS_ITEM_HNS
	msgbox Route42_Text_TullyGaveItem, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_TullyNoRoom::
	msgbox Route42_Text_TullyNoRoom, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Ben::
	trainerbattle_single TRAINER_BENJAMIN_HNS, Route42_Text_HikerBenjaminSeen, Route42_Text_HikerBenjaminBeaten
	msgbox Route42_Text_HikerBenjaminAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE_HNS, Route42_Text_PokemaniacShaneSeen, Route42_Text_PokemaniacShaneBeaten
	msgbox Route42_Text_PokemaniacShaneAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign::
	lock
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_MortarSign::
	lock
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end
Route42_EventScript_Item_Shadow_Claw::
    finditem ITEM_TM_SHADOW_CLAW
    end
Route42_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route42_Text_FisherTullySeen:
	.string "就让你见识一下我亲手钓到的宝可梦\n"
	.string "有多强吧！$"

Route42_Text_FisherTullyBeaten:
	.string "怎么会？这不对劲啊。真不敢相信！$"

Route42_Text_FisherTullyAfter:
	.string "我想用自己钓到的宝可梦成为冠军训\n"
	.string "练家。\p"
	.string "这才是钓鱼最棒的地方！$"

Route42_Text_HikerBenjaminSeen:
	.string "啊，在户外真是舒服！感觉好自由啊\n"
	.string "！$"

Route42_Text_HikerBenjaminBeaten:
	.string "嘎哈哈！打得真痛快！$"

Route42_Text_HikerBenjaminAfter:
	.string "抬头望望辽阔的天空，输掉比赛也就\n"
	.string "微不足道了！$"

Route42_Text_PokemaniacShaneSeen:
	.string "喂！\p"
	.string "这里是我的秘密基地！闲杂人等快走\n"
	.string "开！$"

Route42_Text_PokemaniacShaneBeaten:
	.string "早知道就用月之石了......$"

Route42_Text_PokemaniacShaneAfter:
	.string "你在收集宝可梦图鉴吗？\p"
	.string "哇，那你一定认识很多稀有的宝可梦\n"
	.string "吧！\p"
	.string "能让我看看吗？求求你了！$"

Route42_Text_Sign1:
	.string "42号道路\p"
	.string "圆朱市 - 卡吉镇$"

Route42_Text_MtMortarSign1:
	.string "擂钵山\p"
	.string "内有瀑布洞窟$"

Route42_Text_TullyRegister:
	.string "我想用自己钓到的宝可梦成为冠军训\n"
	.string "练家。\p"
	.string "这才是钓鱼最棒的地方！$"

Route42_Text_TullyRematchIntro:
	.string "就让你见识一下我亲手钓到的宝可梦\n"
	.string "有多强吧！$"

Route42_Text_TullyRematchDefeat:
	.string "怎么会？这不对劲啊。真不敢相信！$"

Route42_Text_TullyPostRematch:
	.string "我想用自己钓到的宝可梦成为冠军训\n"
	.string "练家。\p"
	.string "这才是钓鱼最棒的地方！$"

Route42_Text_TullyHasItem:
	.string "嘿！我钓鱼的时候捡到了好东西！\p"
	.string "给，这个送你了！$"

Route42_Text_TullyGaveItem:
	.string "要是再钓到什么好东西，我会通知你\n"
	.string "的！$"

Route42_Text_TullyNoRoom:
	.string "嗯，你的包包装满了。\p"
	.string "腾出地方再来找我吧。$"
