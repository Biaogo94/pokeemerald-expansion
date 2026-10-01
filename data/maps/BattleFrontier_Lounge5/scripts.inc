BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "呵呵！我能看出宝可梦在想什么哦！\p"
	.string "来吧！让我看看你的宝可梦！$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "砰！咔嚓！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "嗯嗯……\p"
	.string "它说它想去战斗！它说无论会受什么\n"
	.string "伤，它都想去战斗！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "嗯嗯……\p"
	.string "它说它想去战斗！但如果它受伤太\n"
	.string "重，它会更多照顾自己的！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "嗯嗯……\p"
	.string "它说它想去战斗！但如果它受伤太\n"
	.string "重，它会避开战斗的！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "嗯嗯……\p"
	.string "它说它会照顾自己更多一些！但如果\n"
	.string "它受伤太重，它还是会报复！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "嗯嗯……\p"
	.string "它说它会照顾自己更多一些！它说就\n"
	.string "算受伤很重，它还是会更多照顾自\l"
	.string "己！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "嗯嗯……\p"
	.string "它说它会照顾自己更多一些！但如果\n"
	.string "它受伤太重，它会避开战斗的！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "嗯嗯……\p"
	.string "它说它会小心躲开战斗的！但如果它\n"
	.string "受伤太重，它还是会报复！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "嗯嗯……\p"
	.string "它说它会小心躲开战斗的！但如果它\n"
	.string "受伤太重，它会更多照顾自己！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "嗯嗯……\p"
	.string "它说它会小心躲开战斗的！它说就算\n"
	.string "受伤很重，它还是想避开战斗！$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "你在说什么傻话！蛋可在沉睡啊！我\n"
	.string "怎么跟它交谈呢！$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "好像魔法一样啊！那边那位小女孩说\n"
	.string "她能懂得宝可梦在说什么！$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "我感觉那个小女孩好像在说什么很晦\n"
	.string "涩难懂的话。$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "我知道我知道！\p"
	.string "那个小女孩经常在红色的房子里玩！$"

