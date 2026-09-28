OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "哎呀......你好啊，\n"
	.string "{PLAYER}。\p"
	.string "我面前的这些空盘子，其实不全是我\n"
	.string "吃剩下的啦......\p"
	.string "呃......\p"
	.string "其实是之前坐在这里的人吃得太多了\n"
	.string "......\p"
	.string "如果你还想再和我对战的话，请来金\n"
	.string "黄市的格斗道场找我吧。$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "哈哈！你的宝可梦看起来身板还挺轻\n"
	.string "飘飘的嘛！\p"
	.string "凭这种力气可推不动路上的大石头\n"
	.string "哦。\p"
	.string "来，拿上这个，让它们学会“怪力”\n"
	.string "吧！$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "在茫茫大海上，唯一能依靠的就只有\n"
	.string "你自己！\p"
	.string "我这身结实的肌肉可是我的骄傲！你\n"
	.string "也该像我一样好好锻炼！$"

OlivineCity_Text_CafeFishingGuru:
	.string "浅葱咖啡馆的菜单上，满是为我们这\n"
	.string "种健壮的水手量身准备的丰盛大餐！$"

OlivineCity_Text_CafeSailor:
	.string "每次来到这个城镇，我都一定要光顾\n"
	.string "浅葱咖啡馆。\p"
	.string "菜单上的每道菜都能让我精神百倍。\n"
	.string "根本停不下来啊！$"

