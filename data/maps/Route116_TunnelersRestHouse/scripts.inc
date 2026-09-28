Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "那边的卡绿隧道啊……\p"
	.string "起初我们动用大型机械组织了庞大的\n"
	.string "施工队开凿岩层。但后来不得不停工\l"
	.string "了。\p"
	.string "因为发现这样会严重影响到野生宝可\n"
	.string "梦的栖息环境。\p"
	.string "所以现在我们只能无所事事地闲逛了\n"
	.string "。$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "有个男人正独自向绿茵镇方向挖掘。\n"
	.string "他急着想打通隧道。\p"
	.string "说是只要不用机械慢慢挖就不会惊扰\n"
	.string "宝可梦也能保护自然环境。\p"
	.string "不知道他现在挖通了没有？$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "要绕开隧道去绿茵镇的话，得先渡海\n"
	.string "到武斗镇，再坐船到凯那市，最后穿\l"
	.string "过紫堇市才行。$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "听到了吗？到绿茵镇的隧道已经打通\n"
	.string "了！\p"
	.string "看来只要怀抱足够强烈的愿望，梦想\n"
	.string "就真的能实现呢。$"

