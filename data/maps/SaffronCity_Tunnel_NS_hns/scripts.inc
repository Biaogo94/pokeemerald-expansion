SaffronCity_Tunnel_NS_hns_MapScripts::
	.byte 0

SaffronCity_Tunnel_NS_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION, SaffronCity_Tunnel_NS_EventScript_BaldingManAfter
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Tunnel_NS_EventScript_BaldingManDetected
	closemessage
	release
	end

SaffronCity_Tunnel_NS_EventScript_BaldingManDetected::
	playse SE_PIN
	applymovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected, MSGBOX_DEFAULT
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION
SaffronCity_Tunnel_NS_EventScript_BaldingManAfter::
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveTm, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Tunnel_NS_Text_BaldingManIntro:
	.string "别害怕，我不是什么坏人。\p"
	.string "像这种地方......总会引来心\n"
	.string "术不正的家伙。\p"
	.string "他们早晚会惹出麻烦来......\p"
	.string "光是想想就让我火大。$"

SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected:
	.string "啊哈！那是愤怒馒头吧！\p"
	.string "能给我吗？拜托了！$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar:
	.string "{PLAYER}把愤怒馒头交给了\n"
	.string "地下通道的男人。\p"
	.string "吧唧！\p"
	.string "真是气死我了！\p"
	.string "可是好好吃啊！\p"
	.string "吧唧吧唧！\p"
	.string "啊啊！真是火大！\p"
	.string "吧唧吧唧！\p"
	.string "啊啊......\p"
	.string "................\n"
	.string "........呼！\p"
	.string "感觉心情舒畅多了！谢谢你的馒头！\n"
	.string "这个送给你！$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveTm:
	.string "招式学习器64里面装的是....\n"
	.string "..\p"
	.string "滴--            答\n"
	.string "滴--            答\l"
	.string "滴--            答\l"
	.string "滴--            答\l"
	.string "滴...............\l"
	.string "................\l"
	.string "................\l"
	.string ".......轰隆--！！！$"

