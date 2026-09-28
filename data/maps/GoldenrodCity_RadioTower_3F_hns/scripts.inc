GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "这是钥匙卡的插槽。$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER}插入了钥匙卡。$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "大门打开了。$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "3F 人事部$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "宝可梦音乐 主持人：DJ本$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "我们这里收录了所有已被发现的宝可\n"
	.string "梦的叫声。\p"
	.string "大概有400种呢。$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "对训练家来说，宝可梦是至亲的伙伴\n"
	.string "。\p"
	.string "火箭队居然妄图去操纵宝可梦，真是\n"
	.string "太差劲了。$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "为了播出有趣的节目，我们24小时\n"
	.string "全天候运转。\p"
	.string "我也要全力以赴全天候待命！$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "火箭队的老大把自己反锁在里面了。\p"
	.string "但是台长可以打开那扇门。\p"
	.string "他在5楼。\p"
	.string "请去救救他吧！$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "台长他平安无事吗？$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "太感谢你了！你真是我的大英雄！\p"
	.string "这是我的一点心意，请收下。$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "这是大晴天。\p"
	.string "能在一段时间内提高火属性招式的威\n"
	.string "力。$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "你刚才的表现简直太精彩了！$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "我收到了严令。\p"
	.string "必须消灭所有挑衅火箭队的家伙！$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "什么？！$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "我居然失职了......\p"
	.string "阿波罗大人一定会大发雷霆的...\n"
	.string "...$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "指挥宝可梦去犯罪，这种感觉真是爽\n"
	.string "翻了。$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "开什么玩笑！$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "输掉的感觉真不爽！\p"
	.string "可恶！没用的宝可梦最讨厌了！$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "卷帘门怎么开了？难道是你搞的鬼吗\n"
	.string "？$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "完蛋了！$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "什么？！你居然突破了我们在地下通\n"
	.string "道的防线？\p"
	.string "怎么可能？！$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "哪来的小鬼在这里乱晃？\p"
	.string "你是谁啊？$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "切！是我太小看你了！$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "哇哈哈哈......\p"
	.string "从这里想发射多强的信号，就能发射\n"
	.string "多强的信号。$"

