PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "暮水镇与凯那市之间的海流很急，\p"
	.string "如果你打算冲浪，最后恐怕会被冲到\n"
	.string "谁也不知道的地方。$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "看，很简单的镇子吧？房子都建在水\n"
	.string "上！\p"
	.string "我就是在这儿出生的！$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "天空之柱？\p"
	.string "……哦，你是说不远处那座高高的塔\n"
	.string "吧。\p"
	.string "别问我，我不会去爬的，登那么高太\n"
	.string "可怕了。\p"
	.string "对我来说，还是住在海平面上的暮水\n"
	.string "镇中更安心。$"

PacifidlogTown_Text_TownSign:
	.string "暮水镇\p"
	.string "“朝阳微笑着洒落水面的地方。”$"

