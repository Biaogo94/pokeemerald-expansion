OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "大家都会在这座灯塔里特训。\p"
	.string "里面有那么多训练家等着发起挑战，\n"
	.string "想登上去可不容易呢。$"

OlivineLighthouse_Text_1FPokefanF:
	.string "In the past, POKéMON used to light\n"
	.string "the sea around OLIVINE at night.\p"
	.string "The LIGHTHOUSE was built in honor\n"
	.string "of those noble POKéMON.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "Men of the sea are always\n"
	.string "spoiling for a good fight!$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "Urf!\n"
	.string "I lose!$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "What power! How would you like\n"
	.string "to sail the seas with me?$"

OlivineLighthouse_Text_HueyRegister:
	.string "What power! How would you like\n"
	.string "to sail the seas with me?$"

OlivineLighthouse_Text_HueyRematchIntro:
	.string "Men of the sea are always\n"
	.string "spoiling for a good fight!$"

OlivineLighthouse_Text_HueyRematchDefeat:
	.string "Urf!\n"
	.string "I lose!$"

OlivineLighthouse_Text_HueyPostRematch:
	.string "What power! How would you like\n"
	.string "to sail the seas with me?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "Hm? This is no place\n"
	.string "for playing.$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "Ah! I can see that you're\n"
	.string "serious.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Up top is a POKéMON that keeps\n"
	.string "the LIGHTHOUSE lit.\p"
	.string "But I hear that it's sick now,\n"
	.string "and can't be cured normally.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "Why are you here? Are you just\n"
	.string "going to gawk? I suggest you leave!$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "You really are concerned about\n"
	.string "the sick POKéMON…$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "How the heck do you go up?\p"
	.string "I want to visit the sick POKéMON,\n"
	.string "but I can't get up there…$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Sailors are both kind and strong.\n"
	.string "How about you?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "你也是既温柔又强大啊......$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Every time I return to OLIVINE,\n"
	.string "I visit the GYM.\p"
	.string "The GYM LEADER’s POKéMON type\n"
	.string "changed without me noticing.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "I travel the world to train my\n"
	.string "POKéMON. I wish to battle you.$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "......唉......我还得\n"
	.string "再多加修行......$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "JASMINE used to use ROCK-type\n"
	.string "POKéMON like ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "阿蜜现在一定非常担心这里的宝可梦\n"
	.string "吧。\p"
	.string "她这几天连笑容都见不到了。$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "我也完全笑不出来了......$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "Speaking of sick, I've heard there's\n"
	.string "a good PHARMACY in CIANWOOD.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "阿蜜是这座城市的道馆馆主。\p"
	.string "我打算把她劝回道馆去。\p"
	.string "谁也别想来碍我的事！$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "啊啊啊！我的宝可梦！$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "Right. Anybody would be worried if\n"
	.string "his or her own POKéMON were hurt.\p"
	.string "I'll pray for the POKéMON here, so\n"
	.string "JASMINE can come back to the GYM.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "我本想找阿蜜挑战，但她现在完全没\n"
	.string "那份心思。\p"
	.string "那么，换你来陪我过两招怎么样？$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "哇啊，哇啊。你的实力简直深不可测\n"
	.string "！$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "A GYM LEADER isn't just about being\n"
	.string "strong.\p"
	.string "A LEADER also needs to be\n"
	.string "compassionate.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "这里地势挺高的呢。我的鸟宝可梦状\n"
	.string "态正佳！$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "哎呀......掉下来了....\n"
	.string "..$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "My POKéMON learned how to use FLY in\n"
	.string "CIANWOOD.\p"
	.string "Well, since I'm a loser, I'll FLY\n"
	.string "across the sea…$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "阿蜜：......这只宝可梦每到\n"
	.string "夜晚，都会照亮海面。\p"
	.string "......可是它突然病倒了..\n"
	.string "....现在呼吸非常微弱痛苦..\l"
	.string "....\p"
	.string "......我听说湛蓝市有一家很\n"
	.string "棒的药房......\p"
	.string "可是那边隔着大海......我又\n"
	.string "不能丢下阿利不管......$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "......能拜托你替我去取一些\n"
	.string "药来吗？求求你了。$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "湛蓝市有一家很棒的药房.....\n"
	.string ".\p"
	.string "可是那边隔着大海......我又\n"
	.string "不能丢下阿利不管......\p"
	.string "......能拜托你替我去取一些\n"
	.string "药来吗？求求你了。$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "阿蜜：......那种药能治好阿\n"
	.string "利吗？$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER}把秘传药交给了阿\n"
	.string "蜜。$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "阿蜜：......那个，请不要见\n"
	.string "怪......\p"
	.string "......阿利除了我给的东西，\n"
	.string "谁喂的都不肯吃......$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "阿蜜：......\p"
	.string "阿利，感觉好些了吗？$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "阿蜜：......太好了，真是松\n"
	.string "了一口气......\p"
	.string "这真是太好了......\p"
	.string "真的、非常感谢你。\p"
	.string "......我要回道馆去了...\n"
	.string "...\p"
	.string "顺便提醒你一句，钢属性可是很厉害\n"
	.string "的哦。$"

OlivineLighthouse_Text_JasmineISee:
	.string "阿蜜：......这样啊....\n"
	.string "........阿利，坚持住！$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "阿利：............帕\n"
	.string "......帕噜......$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "它的呼吸看起来非常痛苦.....\n"
	.string ".$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "阿利：帕噜！帕噜噜！$"


