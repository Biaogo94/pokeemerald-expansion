MtMortar_1F_North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Protector::
    finditem ITEM_PROTECTOR
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER_HNS, MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS_HNS, MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "这次我可不会输！$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "我居然输给了一个小鬼……\n"
	.string "？$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "不久前，有个练空手道的家伙向我们\n"
	.string "发起挑战。\p"
	.string "他强得不可思议，把我们揍得落花流\n"
	.string "水。\p"
	.string "他说为了修行，又往更深处去了。\p"
	.string "不知道他现在怎么样了？$"

MountMortar2_Text_SupernerdMarkusSeen:
	.string "喂！修！$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "我认错人了……$"

MountMortar2_Text_SupernerdMarkusAfter:
	.string "我是来擂钵山探险的，但跟搭档走散\n"
	.string "了……\p"
	.string "你有没有碰到带着学会“攀瀑”的海\n"
	.string "刺龙的训练家？$"
