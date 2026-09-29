Gate_SaffronCity_Route6_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "欢迎来到金黄市，磁悬浮列车之城！\p"
	.string "……平时我都会这么说的，\n"
	.string "但现在磁悬浮列车停运了。\p"
	.string "发电厂那边好像出了故障，没有电力\n"
	.string "送过来呢。$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "磁悬浮列车可是金黄市最出名的东西\n"
	.string "了。$"
