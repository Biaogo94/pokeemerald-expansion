EcruteakCity_Gym_hns_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "圆朱市宝可梦道馆$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "圆朱市宝可梦道馆\p"
	.string "小松认可的训练家：\n"
	.string "{PLAYER}$"

MortyIntroText:
	.string "欢迎你的到来。\p"
	.string "在圆朱市，宝可梦自古以来就一直受\n"
	.string "到人们的崇敬。\p"
	.string "传说中，彩虹色的宝可梦会降临在真\n"
	.string "正的训练家面前。\p"
	.string "我坚信着这个传说，并一直在此隐秘\n"
	.string "修行。\p"
	.string "其结果，便是我如今能看见常人所看\n"
	.string "不见的东西。\p"
	.string "还差一点点……\p"
	.string "只要再精进一点，我就能预见到与那\n"
	.string "只彩虹色宝可梦相遇的未来。\p"
	.string "就由你来助我达到那个境界吧！$"

MortyWinLossText:
	.string "我还修行得不够啊……\p"
	.string "好吧。这枚徽章就归你了。$"

Text_ReceivedFogBadge:
	.string "{PLAYER}获得了魅影徽章。$"

MortyText_FogBadgeSpeech:
	.string "有了魅影徽章，50级以内的宝可梦\n"
	.string "都会听从你的指挥。\p"
	.string "此外，学会了“冲浪”的宝可梦，也\n"
	.string "可以在任何时候使出冲浪了。\p"
	.string "这个也请你收下吧。$"

MortyText_ShadowBallSpeech:
	.string "那是“暗影球”。在造成伤害的同\n"
	.string "时，还有可能降低对手的特防。\p"
	.string "合适的话就拿去用吧。$"

MortyFightDoneText:
	.string "原来如此……\p"
	.string "你的旅途引领你走过了许许多多遥远\n"
	.string "的地方。\p"
	.string "你所见证过的天地远胜于我。\p"
	.string "这可真让我羡慕啊……$"

MortyRematchText:
	.string "啊，城都的冠军！欢迎你的到来。\p"
	.string "你展现过非凡的实力与身手，但不知\n"
	.string "自从上次对战以来，你是否又有所成\l"
	.string "长？\p"
	.string "在那之后，我也一直与我的幽灵属性\n"
	.string "宝可梦共同修行。\p"
	.string "就让我看看，你是否还能再次驱散眼\n"
	.string "前的阴影吧。\p"
	.string "要再来切磋一场吗？$"

Morty_RematchDefeatText:
	.string "我还修行得不够啊……\p"
	.string "你所见证过的天地远胜于我。\p"
	.string "这可真让我羡慕啊……$"

SageJeffreySeenText:
	.string "我和我的宝可梦一起度过了春天。\p"
	.string "接着是夏天、秋天和冬天……\n"
	.string ".\p"
	.string "然后春天又一次来临。我们已经相伴\n"
	.string "了许久。$"

SageJeffreyBeatenText:
	.string "胜利与失败--我皆已历经。$"

SageJeffreyAfterBattleText:
	.string "宝可梦究竟是从何而来的呢？$"

SagePingSeenText:
	.string "你能对我们的宝可梦造成哪怕一点伤\n"
	.string "害吗？$"

SagePingBeatenText:
	.string "啊！干得漂亮！$"

SagePingAfterBattleText:
	.string "我们使用的是幽灵属性宝可梦。\p"
	.string "一般属性的攻击可是伤不到它们分毫\n"
	.string "的！$"

MediumMarthaSeenText:
	.string "胜者必将是我！$"

MediumMarthaBeatenText:
	.string "我……我……我输\n"
	.string "了！$"

MediumMarthaAfterBattleText:
	.string "求胜心最强烈的人，才是最终的赢家\n"
	.string "！$"

MediumGraceSeenText:
	.string "被我们这里的黑暗走廊难住了吗？想\n"
	.string "得到提示的话，就先打赢我吧！$"

MediumGraceBeatenText:
	.string "怎、怎么会？！$"

MediumGraceAfterBattleText:
	.string "好吧。我就告诉你暗影的秘密。\p"
	.string "真正的道路，就在你的眼前！$"

EcruteakCity_GymGuideText:
	.string "嗨，未来的冠军！你的旅程差不多已\n"
	.string "经走完一半了！\p"
	.string "这里的训练家使用的是幽灵属性和恶\n"
	.string "属性的宝可梦。\p"
	.string "虽然松叶是幽灵属性的专家，但也要\n"
	.string "当心他那只神秘的鹿。\p"
	.string "据说那只宝可梦能引发诡异的噩梦。\n"
	.string ".....$"

EcruteakCity_GymGuideWinText:
	.string "呼，{PLAYER}。你干得太棒\n"
	.string "了！\p"
	.string "我刚才可是吓得缩在角落里瑟瑟发抖\n"
	.string "呢！$"

EcruteakCity_GymClosedText:
	.string "道馆馆主松叶现在不在。\p"
	.string "很抱歉，请你先回吧。\p"
	.string "呵呵呵呵。$"
