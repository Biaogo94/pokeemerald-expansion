BattleFrontier_Lounge5_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns::
	.string "嘿嘿！我能知道宝可梦心里在想什么\n"
	.string "哦！\p"
	.string "拜托！能让我看看你的宝可梦吗？$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns::
	.string "切--！小气鬼！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow_hns::
	.string "嗯嗯……\p"
	.string "它说它喜欢战斗！即使受了很痛很痛\n"
	.string "的伤，它也还是会继续战斗！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow_hns::
	.string "嗯嗯……\p"
	.string "它说它喜欢战斗！但要是受了很痛很\n"
	.string "痛的伤，它就会先顾着保护自己！$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow_hns::
	.string "嗯嗯……\p"
	.string "它说它喜欢战斗！但要是受了很痛很\n"
	.string "痛的伤，它就会变得爱耍小花招！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow_hns::
	.string "嗯嗯……\p"
	.string "它说它很懂得照顾自己！但要是受了\n"
	.string "很痛很痛的伤，它就会全力反击回\l"
	.string "去！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow_hns::
	.string "嗯嗯……\p"
	.string "它说它很懂得照顾自己！它说不管受\n"
	.string "没受很痛的伤，它都总是在担心自\l"
	.string "己！$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow_hns::
	.string "嗯嗯……\p"
	.string "它说它很懂得照顾自己！但要是受了\n"
	.string "很痛很痛的伤，它就会变得爱耍小花\l"
	.string "招！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow_hns::
	.string "嗯嗯……\p"
	.string "它说它喜欢耍小花招！但要是受了很\n"
	.string "痛很痛的伤，它就会全力反击回去！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow_hns::
	.string "嗯嗯……\p"
	.string "它说它喜欢耍小花招！但要是受了很\n"
	.string "痛很痛的伤，它就会先顾着保护自\l"
	.string "己！$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow_hns::
	.string "嗯嗯……\p"
	.string "它说它喜欢耍小花招！它说即使受了\n"
	.string "很痛很痛的伤，它也还是最喜欢耍小\l"
	.string "花招！$"

BattleFrontier_Lounge5_Text_NatureGirlEgg_hns::
	.string "真傻！蛋还在睡觉呢！我没法跟它说\n"
	.string "话！$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns::
	.string "真有意思！那个小女孩竟然声称自己\n"
	.string "能听懂宝可梦的心声！$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns::
	.string "我总觉得那个小女孩说的话其实大有\n"
	.string "深意。$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns::
	.string "我知道一个秘密！\p"
	.string "那个小女孩经常在那座红色的房子里\n"
	.string "玩！$"

