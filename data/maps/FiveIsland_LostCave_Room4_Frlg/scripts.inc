FiveIsland_LostCave_Room4_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room4_EventScript_Laura::
	trainerbattle_single TRAINER_PSYCHIC_LAURA, FiveIsland_LostCave_Room4_Text_LauraIntro, FiveIsland_LostCave_Room4_Text_LauraDefeat
	msgbox FiveIsland_LostCave_Room4_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room4_Text_LauraIntro::
	.string "我认为在这个洞穴里充斥着一股神秘\n"
	.string "的力量。$"

FiveIsland_LostCave_Room4_Text_LauraDefeat::
	.string "如果你走进错误的通道，你将无法前\n"
	.string "进。$"

FiveIsland_LostCave_Room4_Text_LauraPostBattle::
	.string "在早些时候，一位女士进入过这个洞\n"
	.string "穴。$"

