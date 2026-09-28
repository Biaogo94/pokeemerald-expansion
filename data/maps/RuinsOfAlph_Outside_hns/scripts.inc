RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "沼王：吧吧！吧吧！$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "Hm? That's a POKéDEX, isn't it?\n"
	.string "May I see it?\p"
	.string "There are so many kinds of\n"
	.string "POKéMON.\p"
	.string "Hm? What's this?\p"
	.string "What is this POKéMON?\p"
	.string "It looks like the strange\n"
	.string "writing on the walls of the\p"
	.string "RUINS.\p"
	.string "If those drawings are really\n"
	.string "POKéMON, there should be many\n"
	.string "more.\p"
	.string "I know! Let me upgrade your\n"
	.string "POKéDEX. Follow me.$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "你想干什么？我正在研究呢--别来\n"
	.string "打扰我！$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "对不起......我们对这里的真\n"
	.string "相一无所知，\p"
	.string "这实在让我太焦躁了......$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "这座遗迹大约建于1500年前。\p"
	.string "谁也不知道建造者究竟是谁。\p"
	.string "那些宝可梦石雕究竟有什么含义，至\n"
	.string "今也无从得知。\p"
	.string "这里的一切全都是个谜......$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "唔......这里真是个不可思议\n"
	.string "的地方。$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "我喜欢在这里思考。$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "神秘石板房间$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "阿露福遗迹欢迎游客参观$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "阿露福遗迹研究所\p"
	.string "阿露福遗迹的权威机构$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "我们在调查遗迹时，突然察觉到一股\n"
	.string "诡异的气息。\p"
	.string "大家都吓坏了，拔腿就跑。你也要多\n"
	.string "加小心啊。$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "遗迹里隐藏着一个巨大的秘密！\p"
	.string "......我是这么觉得的啦..\n"
	.string "....$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "未知图腾有好多不同的形态，所以我\n"
	.string "们把它们当作暗号来用呢。$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A… H… E… A… D… Hmm…\p"
	.string "What?\p"
	.string "I'm decoding this message!$"
