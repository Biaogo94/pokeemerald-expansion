FourIsland_LoreleisHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_LoreleisHouse_OnTransition
	.byte 0

FourIsland_LoreleisHouse_OnTransition::
	special UpdateLoreleiDollCollection
	end

FourIsland_LoreleisHouse_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei3
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei2
	msgbox FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei2::
	setflag FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE
	msgbox FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei3::
	msgbox FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow
	release
	end

FourIsland_LoreleisHouse_EventScript_Doll::
	lock
	msgbox FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore
	release
	end

FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland::
	.string "科拿：在我的脑海里，有件事一直令\n"
	.string "我放不下心。\p"
	.string "如果在我所出生的岛上发生了什么事\n"
	.string "情……\p"
	.string "而在宝可梦联盟的我是全然不知的。\p"
	.string "我想知道……我会不会为了这样的原\n"
	.string "因不负责任地跑回家……$"

FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile::
	.string "科拿：那么，你会在这儿设法解决掉\n"
	.string "所有的问题？\p"
	.string "那真是太好了。\p"
	.string "那也就是说我已经没有理由一直呆在\n"
	.string "这儿了。\p"
	.string "真是谢谢你……\p"
	.string "我过一会儿就回宝可梦联盟。$"

FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow::
	.string "我不知道未来会怎样……\p"
	.string "但是，我会尽全力做我所能做的。那\n"
	.string "也是我唯一能做的了。$"

FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore::
	.string "胖嘟嘟的宝可梦娃娃被打扮得很漂亮\n"
	.string "！$"

