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
	.string "在过去，夜晚浅葱市周围的海面全靠\n"
	.string "宝可梦们来照亮。\p"
	.string "这座灯塔就是为了纪念那些崇高的宝\n"
	.string "可梦而建造的。$"

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
	.string "大海的男儿随时都渴望来一场痛快的\n"
	.string "战斗！$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "唔呃！我认输！$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "好强的力量！你愿意和我一起扬帆出\n"
	.string "海吗？$"

OlivineLighthouse_Text_HueyRegister:
	.string "好强的力量！你愿意和我一起扬帆出\n"
	.string "海吗？$"

OlivineLighthouse_Text_HueyRematchIntro:
	.string "大海的男儿随时都渴望来一场痛快的\n"
	.string "战斗！$"

OlivineLighthouse_Text_HueyRematchDefeat:
	.string "唔呃！我认输！$"

OlivineLighthouse_Text_HueyPostRematch:
	.string "好强的力量！你愿意和我一起扬帆出\n"
	.string "海吗？$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "嗯？这里可不是小孩子玩耍的地方。$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "啊！看来你是认真的啊。$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "灯塔顶上有一只宝可梦在维持着灯火\n"
	.string "长明。\p"
	.string "但我听说它现在病倒了，普通的药物\n"
	.string "根本治不好它。$"

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
	.string "你来这儿干什么？纯粹来看热闹的\n"
	.string "吗？我劝你还是赶紧离开吧！$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "原来你真的很担心那只生病的宝可梦\n"
	.string "啊......$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "到底要怎么才能爬上去啊？\p"
	.string "我想去探望那只生病的宝可梦，可怎\n"
	.string "么也上不去......$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "水手既温柔又强壮。那你呢？$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "你也是既温柔又强大啊......$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "每次回到浅葱市，我都会去拜访道\n"
	.string "馆。\p"
	.string "没想到在我没留意的时候，馆主擅长\n"
	.string "的属性都已经变了。$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "我周游世界来训练宝可梦。我想和你\n"
	.string "对战一场。$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "......唉......我还得\n"
	.string "再多加修行......$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "阿蜜以前使用的是大岩蛇之类的岩石\n"
	.string "属性宝可梦。$"

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
	.string "说起生病，我听说湛蓝市有一家很棒\n"
	.string "的药房。$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "阿蜜是这座城市的道馆馆主。\p"
	.string "我打算把她劝回道馆去。\p"
	.string "谁也别想来碍我的事！$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "啊啊啊！我的宝可梦！$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "说得也是。如果是自己的宝可梦生病\n"
	.string "了，任谁都会心急如焚的。\p"
	.string "我会为这里的宝可梦祈祷的，好让阿\n"
	.string "蜜能早日重返道馆。$"

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
	.string "道馆馆主可不仅仅只要实力强大。\p"
	.string "馆主同时还要拥有一颗体贴温柔的心\n"
	.string "才行。$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "这里地势挺高的呢。我的鸟宝可梦状\n"
	.string "态正佳！$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "哎呀......掉下来了....\n"
	.string "..$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "我的宝可梦是在湛蓝市学会“飞翔”\n"
	.string "的。\p"
	.string "唉，既然输了，那我就“飞翔”渡海\n"
	.string "回去吧......$"

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


