Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "我听说有一个洞窟叫做觉醒神殿，\p"
	.string "传说宝可梦的灵魂会在那里复生。这\n"
	.string "样的事情真的有可能发生吗？$"

Route119_House_Text_Wingull:
	.string "长翅鸥：欧雷！$"

