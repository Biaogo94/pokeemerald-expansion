CeladonCity_House1_hns_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "你好！\p"
	.string "我们现在正在举行大胃王比赛。\p"
	.string "目前无法为您提供服务，非常抱歉。$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "……呼噜，嚼嚼……\n"
	.string ".$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "别跟我说话！\p"
	.string "会让我分心的！$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "……咕嘟……嚼嚼\n"
	.string "......$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "比起品质，我更看重分量！\p"
	.string "只要吃饱就很幸福！$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "嚼嚼，嚼嚼……$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "这里的饭菜挺好吃，但要说哪里的美\n"
	.string "食天下第一，还得是满金市。$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "咯吱……咯吱……$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "这里可没人会给你代币盒。你应该去\n"
	.string "城都地区找找看。$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "咔嚓……咔嚓……\p"
	.string "我还能继续吃！\p"
	.string "老板，再来一份！$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "大胃王挑战赛！不限时间！\p"
	.string "永无止境的战斗！吃得最多的人全额\n"
	.string "免费！$"

