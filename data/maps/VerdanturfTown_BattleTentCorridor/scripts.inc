VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "你想要参加哪个部门？需要建议吗？\p"
	.string "在任一部门中，例如可爱部门我认为\n"
	.string "裁判不仅仅在第一回合中判定。\p"
	.string "你应该努力制定出更多方法来更好的\n"
	.string "培育你的宝可梦。$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "我培育宝可梦让它变得可爱。\p"
	.string "我发现你可以让宝可梦参加可爱部\n"
	.string "门！\p"
	.string "我很高兴我是用爱心来培育我的宝可\n"
	.string "梦。$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "我的宝可梦法则！\p"
	.string "它帅气、强壮、漂亮、可爱并且聪\n"
	.string "明。完美！\p"
	.string "我不妨赢得各项华丽大赛。$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "宝可梦华丽大赛一般级会场！$"

