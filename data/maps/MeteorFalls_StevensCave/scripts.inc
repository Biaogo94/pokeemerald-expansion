MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "大吾：咦，{PLAYER}\n"
	.string "{KUN}，你知道我在这里啊。\p"
	.string "你会不会……认为我只是个普通的石头\n"
	.string "狂人？\p"
	.string "……不。\p"
	.string "我们在绿岭市宇宙中心共同战斗过，\p"
	.string "我拥有怎样的实力你应该很清楚了\n"
	.string "吧。\p"
	.string "好吧，{PLAYER}\n"
	.string "{KUN}，如果你想和我对战的\l"
	.string "话，做好觉悟吧！$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "你……没想到你已经变得这么强了……$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "大吾：说起来……从在武斗镇的石之洞\n"
	.string "窟第一次遇到你，我就有种感觉，\p"
	.string "感觉你最终将会成为冠军。\p"
	.string "我的预感通常都很准确吧。\p"
	.string "那么……接下来你要去的地方是……\p"
	.string "…… …… ……\n"
	.string "…… …… ……\p"
	.string "呵呵呵，即使是我也不知道呀。$"

