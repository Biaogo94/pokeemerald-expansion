BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "不知道今天会不会有关于强大训练家\n"
	.string "的电视采访？$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "在这儿开个饭馆的话肯定能挣大钱吧\n"
	.string "。$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "呼……\p"
	.string "那么紧张的对战之后，我得稍微休息\n"
	.string "一下了……\p"
	.string "但即使是现在，我脑子里也会一直设\n"
	.string "计着对战策略。$"

