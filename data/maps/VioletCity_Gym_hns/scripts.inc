VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "我叫阿速，是桔梗市宝可梦道馆的馆\n"
	.string "主！\p"
	.string "有人说用电击就能让飞行属性宝可梦\p"
	.string "折翼……这种话，我可不能忍！\p"
	.string "看好了！让我用鸟宝可梦向你展示真\n"
	.string "正的力量！$"

VioletGym_Text_Falkner_WinLoss:
	.string "......可恶！父亲悉心培育的\n"
	.string "鸟宝可梦居然......\p"
	.string "好吧。拿去吧。\p"
	.string "这是宝可梦联盟公认的飞翼徽章。$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER}获得了飞翼徽章。$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "拥有飞翼徽章后，宝可梦的攻击力就\n"
	.string "会提升。\p"
	.string "而且只要是能学会闪光的宝可梦，随\n"
	.string "时都可以使用它。\p"
	.string "还有这个--你也一起收下吧。$"

VioletGym_Text_Falkner_TMExplain:
	.string "使用招式学习器，可以让宝可梦立刻\n"
	.string "学会新的招式。\p"
	.string "这个学习器里记录的是羽栖。\p"
	.string "它可以为宝可梦回复最大HP的一\n"
	.string "半。\p"
	.string "换句话说，能够治疗你的宝可梦。$"

VioletGym_Text_Falkner_AfterFight:
	.string "前方的城镇里还有许多宝可梦道馆。\p"
	.string "你也应该去那些道馆里检验一下自己\n"
	.string "的实力。\p"
	.string "为了成为最顶尖的飞鸟大师，我也要\n"
	.string "加倍修行！$"

VioletGym_Text_Falkner_Rematch:
	.string "恭喜你击败了四天王！\p"
	.string "我更加刻苦地特训了我的飞行属性宝\n"
	.string "可梦。\p"
	.string "你觉得自己还能再次对抗来自天空的\n"
	.string "力量吗？$"

VioletGym_Text_Falkner_RematchLoss:
	.string "哇......我又输给你了。\p"
	.string "我会更加努力修行，成为最出色的鸟\n"
	.string "使者！$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "关键词就是骨气！\p"
	.string "在这里修行的人，日日夜夜都在为成\n"
	.string "为鸟宝可梦大师而努力。\p"
	.string "来吧！$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "哇啊啊！$"

VioletGym_Text_BirdKeeperRod_After:
	.string "阿速馆主的实力可是名不虚传！\p"
	.string "别以为赢了我就能得意忘形！$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "让我来看看你够不够格挑战阿速馆主\n"
	.string "吧！$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "这不可能！$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "居然输给了一个新手训练家，真是太\n"
	.string "丢脸了......$"

VioletGym_Text_GymGuide_Intro:
	.string "哟！近来如何？虽然我不是训练家，\n"
	.string "但我能给你提点建议！\p"
	.string "相信我！只要坚信，冠军的梦想就一\n"
	.string "定能实现。\p"
	.string "相信了吗？那就仔细听好。\p"
	.string "阿速的王牌是一只非常耐打的猫头\n"
	.string "鹰，而且特别爱吃树果。\p"
	.string "虽然攻击力不算最强，但特别经打。\p"
	.string "你可以用电属性和岩石属性招式痛击\n"
	.string "它，不过要小心它的掷泥！\p"
	.string "如果还想了解更多技巧，就去逛逛宝\n"
	.string "可梦学院吧。\p"
	.string "那里的学生可懂行了！$"

VioletGym_Text_GymGuide_Win:
	.string "精彩的对战！保持这个势头，用不了\n"
	.string "多久你就能成为冠军了！$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "桔梗市宝可梦道馆$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "桔梗市宝可梦道馆\p"
	.string "馆主阿速认证的训练家：\n"
	.string "{PLAYER}$"
