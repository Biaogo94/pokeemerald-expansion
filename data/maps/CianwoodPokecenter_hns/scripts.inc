CianwoodPokecenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	@callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "说到水属性宝可梦，玛瑙水母绝对是\n"
	.string "最棒的！$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "你看起来好像需要水属性宝可梦。\p"
	.string "来，这只送给你，我这里多得是。$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "你见过那个宝可梦狂了吗？\p"
	.string "他总是到处吹嘘自己拥有的稀有宝可\n"
	.string "梦。$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "这里的道馆训练家全是一群肌肉壮汉\n"
	.string "。\p"
	.string "我如果一直待在这儿，说不定会被他\n"
	.string "们盯上。\p"
	.string "给你提个建议吧：道馆馆主使用的是\n"
	.string "格斗属性宝可梦。\p"
	.string "所以你应该用超能力属性宝可梦把他\n"
	.string "们弄得团团转。\p"
	.string "在他们发挥蛮力之前，一口气将他们\n"
	.string "解决掉吧。\p"
	.string "还有道馆中间的那些岩石？\p"
	.string "如果不按正确的方法推动，是见不到\n"
	.string "道馆馆主的。\p"
	.string "如果卡住了，就先到外面去吧。$"

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER}！你赢了吧！我光\n"
	.string "是看你的表情就知道了！$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "我最喜欢炫耀自己培育的宝可梦了。\p"
	.string "你难道不是吗？\p"
	.string "我要去打好多场对战，好好炫耀我的\n"
	.string "宝可梦！$"
