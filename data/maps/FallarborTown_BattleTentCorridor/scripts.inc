FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "我们在预选赛中确实做得很好，但是\n"
	.string "我们丝毫没有赢得吸引力……\p"
	.string "也许这意味着我不得不去观看其他对\n"
	.string "手是如何做的……$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "看吧！我的宝可梦赢得了所有的奖章\n"
	.string "！\p"
	.string "你的宝可梦赢到过奖章吗？你可以在\n"
	.string "你的宝可导航中查看。$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "我赢不了道馆馆主……\p"
	.string "我赢不了任何华丽大赛……\p"
	.string "我去过这里，那里和所有地方，但这\n"
	.string "都是徒劳的……$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "宝可梦华丽大赛超级会场！$"

