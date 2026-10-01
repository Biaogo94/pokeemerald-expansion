CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Teacher::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_FishingGuru::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_Fisher1::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Fisher2::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_GymGuide::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Gramps::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonGameCorner_Text_PokefanM:
	.string "这里的游戏机全都是最新型的呢。$"

CeladonGameCorner_Text_Teacher:
	.string "我就要玩这台机器。\p"
	.string "昨天它让我输得精光，今天总该吐币\n"
	.string "了吧。$"

CeladonGameCorner_Text_FishingGuru:
	.string "我觉得这台机器能中大奖…….\p"
	.string "每台机器的中奖概率都不一样呢。$"

CeladonGameCorner_Text_Fisher1:
	.string "嘎哈哈哈哈！\p"
	.string "代币一直掉个不停啊！\p"
	.string "嗯？怎么了，小朋友？你也想玩吗？\p"
	.string "那我就把我的好运分给你吧！$"

CeladonGameCorner_Text_Fisher2:
	.string "嘎哈哈哈哈！\p"
	.string "能帮到别人，感觉真是太爽快啦！$"

CeladonGameCorner_Text_GymGuide:
	.string "哟！未来的冠军！\p"
	.string "你也在玩老虎机吗？\p"
	.string "我想攒够代币换宝可梦奖品。\p"
	.string "不过代币还远远不够呢……$"

CeladonGameCorner_Text_PokefanF:
	.string "轮盘啊……\p"
	.string "比起老虎机，我更喜欢玩这个，因为\n"
	.string "赔率更容易算。\p"
	.string "不过中奖的报酬也低很多就是了。$"

CeladonGameCorner_Text_Gramps:
	.string "嗯……全部押在蓝色上的胜率肯定更\n"
	.string "高，但是……该怎么办呢？$"

CeladonGameCorner_Text_Woman:
	.string "赢个不停，根本停不下来！$"
