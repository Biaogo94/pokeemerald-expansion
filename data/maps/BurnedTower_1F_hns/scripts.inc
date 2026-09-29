BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "米纳君：我叫米纳君。\p"
	.string "我一直在追踪一只名叫水君的宝可梦\n"
	.string "。\p"
	.string "那么你呢……？\p"
	.string "{PLAYER}？很高兴认识你！\p"
	.string "听说水君可能会出现在这座烧焦塔里\n"
	.string "，所以我赶来看看。\p"
	.string "但它究竟会在哪里呢？$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "米纳君：听说水君可能会出现在这座\n"
	.string "烧焦塔里，所以我赶来看看。\p"
	.string "但它究竟会在哪里呢？$"

BurnedTower_1FMortyText:
	.string "小松：身为圆朱道馆的馆主，我有责\n"
	.string "任去探究那些被称为传说的宝可梦-\l"
	.string "-水君、炎帝和雷公。\p"
	.string "既然米纳君在这里，我就决定和他一\n"
	.string "起调查这座塔。$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "..............................\p"
	.string "……哼，是你啊。\p"
	.string "听说这里有传说的宝可梦筑巢，我就\n"
	.string "特地过来看看。\p"
	.string "可这里根本什么都没有嘛！\p"
	.string "本少爷费了半天劲才来到这种破地方\n"
	.string "，结果什么都没有？开什么玩笑！\p"
	.string "全都是你的错！$"

BurnedTowerSilver_WinText:
	.string "……哼！\p"
	.string "我之所以会输，全是因为我的宝可梦\n"
	.string "实在太弱了。\p"
	.string "真没用。$"

BurnedTowerSilver_AfterText1:
	.string "……嘁，无所谓了。\p"
	.string "反正像你这种家伙，根本不可能抓得\n"
	.string "到传说的宝可梦。$"

BurnedTowerSilver_LossText:
	.string "……哼！\p"
	.string "所以我才讨厌跟软蛋对战。纯粹是浪\n"
	.string "费时间。$"

BurnedTowerSilver_AfterText2:
	.string "哼！\p"
	.string "你怎么掉到洞里去了？真是个天才！\p"
	.string "活该！$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "别担心！\p"
	.string "我们喷火者比任何人都更清楚火的真\n"
	.string "正力量！$"
BurnedTower_Text_NardBeaten:
	.string "多谢你带来这么火热的对战！$"
BurnedTower_Text_NardAfter:
	.string "这座塔之所以被烧毁，是因为遭到了\n"
	.string "雷击。\p"
	.string "跟我吐出的这点小火苗比起来，根本\n"
	.string "不可同日而语啊……$"

BurnedTower_Text_RichardoSeen:
	.string "我正在烧焦塔里练习偷盗技巧呢！好\n"
	.string "孩子可千万别模仿哦！$"
BurnedTower_Text_RichardoBeaten:
	.string "噗------。$"
BurnedTower_Text_RichardoAfter:
	.string "也许犯罪这份职业并不适合我...\n"
	.string "...$"
