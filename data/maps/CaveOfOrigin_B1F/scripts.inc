CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "啊，你就是{PLAYER}\n"
	.string "{KUN}吗？你的活跃表现我早有\l"
	.string "耳闻。\p"
	.string "我的名字是米可利。\p"
	.string "曾经是琉璃市的道馆馆主，不过因为\n"
	.string "某些原因，\p"
	.string "现在我把管理道馆的事情托付给我的\n"
	.string "老师亚当了。\p"
	.string "…… …… ……\n"
	.string "…… …… ……\p"
	.string "在这里肆虐的2只宝可梦——固拉多和\n"
	.string "盖欧卡，被称为超古代宝可梦，\p"
	.string "然而，超古代宝可梦并不止这2只……\p"
	.string "在世界的某处还存在着第3只——\p"
	.string "没错，那就是被称为烈空坐的超古代\n"
	.string "宝可梦。\p"
	.string "传说在远古时期，正是烈空坐平息了\n"
	.string "那2只宝可梦的的斗争。\p"
	.string "可就连我也不清楚它如今究竟身在何\n"
	.string "处……$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "米可利：{PLAYER}\n"
	.string "{KUN}，莫非你知晓如今烈空坐\l"
	.string "的下落？\p"
	.string "可以的话，请务必告诉我。$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "米可利：觉醒神殿？\p"
	.string "那不就是这里吗！拜托你再认真点！\p"
	.string "请你帮我再想想烈空坐现在究竟可能\n"
	.string "会在哪里。$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "米可利：送神山？\p"
	.string "但在我之前去见那里的老婆婆时，她\n"
	.string "并未提及此事。\p"
	.string "我不认为她会刻意地隐瞒什么……\p"
	.string "{PLAYER}{KUN}，能请\n"
	.string "你再认真想想吗？$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "米可利：哎？不记得了？唔……这就难\n"
	.string "办了……\p"
	.string "真的什么也回想不起来了吗？$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "米可利：天空之柱？\p"
	.string "没错！一定就是那里！\p"
	.string "{PLAYER}{KUN}，事不\n"
	.string "宜迟！我们这就出发去天空之柱！$"

