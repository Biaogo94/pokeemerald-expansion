SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.string "虽说是组装交通工具，设计一条大船\n"
	.string "更像是建造大楼。$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.string "你觉得用沉重的铁制成的船能浮在水\n"
	.string "上很奇怪吗？\p"
	.string "它是因为浮力原理浮起来的。$"

