MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "我年轻的时候，作为训练家在全世界\n"
	.string "旅游。\p"
	.string "现在我已经变成一个老头了，我现在\n"
	.string "唯一的乐趣就是观看年轻训练家的对\l"
	.string "战。$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "门锁上了。$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "名叫{STR_VAR_1}的训练\n"
	.string "家来我家拜访了。\p"
	.string "你想挑战{STR_VAR_1}吗\n"
	.string "？$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "你不想对战？看不到你的对战我好失\n"
	.string "望啊……$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "很好，很好！\p"
	.string "但是我的房子没那么结实。\p"
	.string "我们可不可以来场3对3的比赛？$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "在你们两个对战前可以先写入记录。$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "我希望看到一场好的比赛。$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "所以，这会是陷入僵局\p"
	.string "一场双方都没人让步的对战！$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "太优秀了！\p"
	.string "我彷佛又看到了我年轻的时候！$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "啊，太糟糕了！\p"
	.string "但是确实是场不错的对战。希望下次\n"
	.string "你可以赢。$"
