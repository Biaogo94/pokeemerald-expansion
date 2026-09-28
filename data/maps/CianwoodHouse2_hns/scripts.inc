CianwoodHouse2_hns_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "你是从浅黄市过来的吗？\p"
	.string "一路上看到的那四座岛屿，你还记得\n"
	.string "吗？\p"
	.string "听说有只神秘的海中生物就藏在里面\n"
	.string "。$"

CianwoodCity_Text_LugiaHouseLass:
	.string "听说只有持有银色之羽的人才能见到\n"
	.string "它。\p"
	.string "羽毛上一定带有和那只生物相同的气\n"
	.string "息吧。$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "听说岛屿周围的漩涡，全都是那只海\n"
	.string "中生物引起的。\p"
	.string "想通过那里的话，可能需要掌握特殊\n"
	.string "的招式才行。$"
