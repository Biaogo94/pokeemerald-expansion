Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "嗯？你问我在做什么？\p"
	.string "我想用宝可梦的招式，在这里造一间\n"
	.string "自己的房间。\p"
	.string "对了！这个招式学习器送你。你也试\n"
	.string "着造间房间吗？$"

Route111_Text_ExplainSecretPower:
	.string "找一棵看起来会垂下藤蔓的大树。\p"
	.string "在树前使用秘密之力，藤蔓就会垂下\n"
	.string "来。\p"
	.string "顺着藤蔓爬上去，里面有很大的空\n"
	.string "间！\p"
	.string "摆上你喜欢的东西，那里就是属于你\n"
	.string "的秘密基地。\p"
	.string "你也来建一个吧！\p"
	.string "秘密基地不只能建在树上。\p"
	.string "岩壁上的小凹洞也可以试试。\p"
	.string "我要继续去找别的地方了。再见！$"

Route111_Text_DontWantThis:
	.string "啊？你不想要吗？\n"
	.string "改变主意了随时找我呀！$"

Route111_Text_DontHaveAnyRoom:
	.string "啊，你的背包好像满了！\p"
	.string "我先帮你拿着，等下次背包\n"
	.string "空出来了，再过来拿吧！$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
