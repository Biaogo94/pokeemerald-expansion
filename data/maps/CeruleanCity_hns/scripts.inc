CeruleanCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "这里是华蓝洞窟。\p"
    .string "里面住着实力惊人的宝可梦。\p"
    .string "只有极少数训练家能获准进入。\p"
    .string "首先，你必须强到足以成为关都宝可\n"
    .string "梦联盟的冠军。\p"
    .string "此外，还得立下了不起的功绩。$"

CeruleanCity_Text_CooltrainerM1:
	.string "关都的发电厂？\p"
	.string "从这里往东走的9号道路尽头附近就\n"
	.string "是了。\p"
	.string "听说那里好像出了什么事故。$"

CeruleanCity_Text_CooltrainerM2:
	.string "你正在收集所有种类的宝可梦吗？\p"
	.string "那一定是个相当大的挑战，但听起来\n"
	.string "也挺有趣的呢。$"

CeruleanCity_Text_SuperNerd:
	.string "北边的海角是个约会的好地方。\p"
	.string "女孩子们都很喜欢那里！$"

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "呆壳兽：呀啦？$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_CITY_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_CITY_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "我和我的呆壳兽可是绝妙的搭档！$"

CeruleanCity_Text_CooltrainerF2:
	.string "呆壳兽，快使出念力！$"

CeruleanCity_Text_CooltrainerF3:
	.string "…$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "我是华蓝道馆小霞的超级粉丝！$"

CeruleanCity_Text_Fisher_RocketTip:
	.string "我看到一个形迹可疑的家伙往华蓝海\n"
	.string "角走去了。$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "城镇北边的洞窟里，栖息着极其强大\n"
	.string "的宝可梦。$"

CeruleanCity_Text_Youngster2:
	.string "哎呀？\p"
	.string "我的探宝器有反应了……$"

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "华蓝市\p"
	.string "笼罩在神秘蓝色光芒中的城市$"

CeruleanCity_Text_GymSign:
	.string "华蓝市宝可梦道馆馆主：小霞\p"
	.string "调皮俏丽的人鱼姑娘$"

CeruleanCity_Text_BikeShopSign:
	.string "这里贴着一张告示……\p"
	.string "自行车店已搬迁至城都地区的满金\n"
	.string "市......$"

CeruleanCity_Text_PoliceSign:
	.string "这里贴着一张告示……\p"
	.string "杜绝盗窃，让我们把城市建设成更加\n"
	.string "亲切、充满朝气的地方！\p"
	.string "华蓝警察署$"

CeruleanCity_Text_CapeSign:
	.string "前方华蓝海角$"

CeruleanCity_Text_LockedDoor:
	.string "门锁着……$"

