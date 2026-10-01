GoldenrodCity_DepartmentStore_6F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "{PLAYER}！真巧，居然在这\n"
	.string "儿碰到你！\p"
	.string "我正在给我的大奶罐挑东西呢。\p"
	.string "要是还想跟我对战的话，就来金黄市\n"
	.string "的格斗道馆吧！$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MACHOP, GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon, GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "我正在收集宝可梦！你有\n"
	.string "{STR_VAR_1}吗？\p"
	.string "想用它来交换我的\n"
	.string "{STR_VAR_2}吗？$"

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "太好啦！我得到\n"
	.string "{STR_VAR_1}了！\p"
	.string "{STR_VAR_2}，你要保重\n"
	.string "哦！$"

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "呃，不对吧。这并不是\n"
	.string "{STR_VAR_1}啊。$"

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "不想交换吗？好吧……$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "嗨，我以前那只腕力过得还好吗？$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
    .string "你收听幸运号码频道吗？\p"
    .string "据说要想中奖，就得尽可能多和别人\n"
    .string "交换宝可梦，来收集不同的ID编号"
    .string "。\p"
    .string "不过，现在通信交换可没以前那么方\n"
    .string "便普及了呢。$"

GoldenrodDeptStore_Text_6FSuperNerd:
    .string "要是累了，就去自动售货机买点饮料\n"
    .string "吧。\p"
    .string "你的宝可梦也会喜欢的。$"

GoldenrodDeptStore_Text_6FDirectory:
    .string "购物之余歇歇脚！\p"
    .string "6F 舒心广场$"
