EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "咚！！$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL}：怎么会……\n"
	.string "这怎么可能？我怎么可能会输给\l"
	.string "区区的舞姬……？！$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL}：\n"
	.string "{PLAYER}……你一\l"
	.string "直在看着我吧……\p"
	.string "哼，你说得没错！\p"
	.string "我真没想到要打败那5个舞妓居然会\n"
	.string "这么难……\p"
	.string "我被彻底打得落花流水……\p"
	.string "......\p"
	.string "你也是为了同样的目的才来这里的\n"
	.string "吧？\p"
	.string "可别以为打倒了火箭队就能得意忘形\n"
	.string "了！\p"
	.string "那些舞妓可是强得离谱啊。\p"
	.string "有本事你就去试试看能不能赢她们。\p"
	.string "但我绝不会回去，我可不想看到你\n"
	.string "赢！$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "伊布：布咿！$"

EcruteakCity_Text_Vulpix:
	.string "六尾：呜呜--尾！$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "糟糕，这可怎么办……\p"
	.string "我的女儿不见了。\p"
	.string "不会吧……她总不可能跑到\n"
	.string "烧焦塔去了吧。\p"
	.string "我跟她说过绝对不能靠近那里的。\n"
	.string "……\p"
	.string "听说那里经常有人失踪啊……\n"
	.string "……\p"
	.string "唉，我到底该怎么办才好……\n"
	.string "……？$"

EcruteakCity_Text_Gramps1:
	.string "圆朱市过去曾有两座塔，东西各耸立\n"
	.string "着一座。$"

EcruteakCity_Text_Gramps2:
	.string "啊，孩子。你学会像舞妓那样跳舞了\n"
	.string "吗？\p"
	.string "听说如果你去她们的歌舞剧场，有个\n"
	.string "奇怪的老爷爷会送你一样好东西呢。$"

EcruteakCity_Text_Lass1:
	.string "我正要去歌舞剧场练习呢。要跟我一\n"
	.string "起去吗？$"

EcruteakCity_Text_Lass2:
	.string "曾经伫立在这里的塔……\p"
	.string "我奶奶说它过去可比现在高多了。\p"
	.string "听说现在里面到处都是幽灵呢。$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "3只巨大的宝可梦分别朝着不同的方\n"
	.string "向跑走了。它们到底是什么呢？$"

EcruteakCity_Text_Fisher:
	.string "我听到了关于浅黄灯塔的传闻。\p"
	.string "据说作为灯标的宝可梦生病了，看来\n"
	.string "他们遇到了大麻烦啊。$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "浅黄灯塔的宝可梦已经痊愈了。\p"
	.string "船只在夜晚也能重新安全地出海了。$"

EcruteakCity_Text_Youngster:
	.string "听说愤怒之湖有宝可梦在暴走呢。我\n"
	.string "真想亲眼去看一看。$"

EcruteakCity_Text_Gramps3:
	.string "在很久很久以前……\p"
	.string "这座塔遭遇了一场大火，有3只无名\n"
	.string "的宝可梦在火灾中丧命了。\p"
	.string "一只彩虹色的宝可梦从天而降，赋予\n"
	.string "了它们新生……\p"
	.string "这是圆朱道馆馆主代代相传的传说。\p"
	.string "你问我？\p"
	.string "老夫年轻时也曾是一名训练家呢。吼\n"
	.string "吼吼！$"

EcruteakCity_Text_SageGym:
	.string "道馆馆主小松现在不在这里。你或许\n"
	.string "能在烧焦塔找到他。$"

EcruteakCity_Text_Sign:
	.string "圆朱市历史悠久的城镇\p"
	.string "过去与现在交汇之处$"

EcruteakCity_Text_TinTowerSign:
	.string "铃铛塔\p"
	.string "相传有传说的宝可梦栖息于此。$"

EcruteakCity_Text_OfficeSign:
	.string "铃铛塔关卡\p"
	.string "无资格者严禁入内。$"

EcruteakCity_Text_GymSign:
	.string "圆朱市宝可梦道馆馆主：小松\p"
	.string "能够看透未来的千里眼$"

EcruteakCity_Text_DanceTheaterSign:
	.string "圆朱歌舞剧场$"

EcruteakCity_Text_BurnedTowerSign:
	.string "烧焦塔\p"
	.string "因一场神秘的大火而烧毁。\p"
	.string "此处危险，请勿靠近。$"
