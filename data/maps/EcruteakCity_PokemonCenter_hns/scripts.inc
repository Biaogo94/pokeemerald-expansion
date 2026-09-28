EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "嗨，我是正辉。你叫什么名字？\p"
	.string "唔，是{PLAYER}啊？你来得\n"
	.string "正好！$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "我刚刚完成了宝可梦储存系统的最终\n"
	.string "调整。\p"
	.string "你知道用来存放宝可梦的那台电脑吗\n"
	.string "？\p"
	.string "那可是我亲自开发的哦！\p"
	.string "现在这里的也安装好了，城都和关都\n"
	.string "的所有宝可梦中心都可以使用我的电\l"
	.string "脑系统了。\p"
	.string "我得赶回满金市去见我家人了。随时\n"
	.string "欢迎来我家玩哦！\p"
	.string "拜拜啦！$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "艺伎们的舞姿真是太美妙了。\p"
	.string "正如她们指挥宝可梦时那般优雅。$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "你一定很想和更多的人对战吧？\p"
	.string "听说有个训练家聚集的场所哦。\p"
	.string "你问在哪里？\p"
	.string "从浅黄市再往前走一点就是了。$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "道馆馆主松叶真是太--帅了！\p"
	.string "他的宝可梦也是强得没话说。$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "愤怒之湖......\p"
	.string "大量出现的暴鲤龙......\p"
	.string "我嗅到了阴谋的味道。绝对没错！$"

