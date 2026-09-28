SevenIsland_TrainerTower_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_Text_DarioIntro::
	.string "我感觉到了你在靠近。$"

SevenIsland_TrainerTower_Text_DarioDefeat::
	.string "放弃了……$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
	.string "我感觉到在你的未来，你将会遇到许\n"
	.string "多人。\p"
	.string "你们会被一股奇异的力量互相联系在\n"
	.string "一起。$"

SevenIsland_TrainerTower_Text_RodetteIntro::
	.string "在这座岛上某个地方，有特别的宝可\n"
	.string "梦正在沉睡。$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
	.string "真是一个令人惊异的训练家！$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
	.string "在这座岛上的某个地方，沉睡着不同\n"
	.string "寻常的宝可梦。\p"
	.string "难道说，它们正在等待你的到来吗？$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
	.string "训练家之塔入口上去挑战，训练家！$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
	.string "前方是训练家之塔$"

