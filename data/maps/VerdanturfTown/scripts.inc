VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "我爸爸告诉我的。\p"
	.string "他说这条隧道里全是\n"
	.string "胆小的宝可梦。\p"
	.string "它们一听到大的声响\n"
	.string "就会吓得大吵大闹。\p"
	.string "所以隧道的大工程\n"
	.string "只好停了下来。\p"
	.string "但有一个人，正靠自己的力量\n"
	.string "挖掘这条隧道！$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "听说那人挖隧道是为了心爱的姑娘。\p"
	.string "虽然不太懂，但真浪漫啊！$"

VerdanturfTown_Text_AirCleanHere:
	.string "因风向关系，火山灰永远吹不到这里\n"
	.string "，\p"
	.string "所以这里空气非常清新。住在这里，\n"
	.string "就算是体弱多病的人也可能有奇迹般\l"
	.string "的好转。$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "我和我的宝可梦一路连胜，\n"
	.string "势头正旺。\p"
	.string "所以我决定在这座城镇的\n"
	.string "对战帐篷初次亮相。$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "你看到友好商店旁边的洞窟了吗？\p"
	.string "里面有个人在努力打碎岩石来打通隧\n"
	.string "道。\p"
	.string "要是隧道能打通就太好了……这样我\n"
	.string "们去卡那兹市就更容易了。$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "友好商店旁的洞穴已经是连通两地的\n"
	.string "隧道啦！\p"
	.string "太棒了——现在去卡那兹市买得文的\n"
	.string "新产品方便多了。$"

VerdanturfTown_Text_TownSign:
	.string "绿荫镇\p"
	.string "“风吹拂的高地，\n"
	.string "飘着青草的甜香。”$"

VerdanturfTown_Text_WandasHouse:
	.string "满盈的家$"

VerdanturfTown_Text_BattleTentSign:
	.string "对战帐篷绿茵镇分址“精彩对战，尽\n"
	.string "收眼底！”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "卡绿隧道“连接卡那兹市和绿茵镇\p"
	.string "隧道工程现已终止施工。”$"

