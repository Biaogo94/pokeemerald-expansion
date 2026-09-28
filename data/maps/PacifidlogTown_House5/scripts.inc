PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "今天看不见幻之岛……$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "啊！哦，天哪！今天看见了幻之岛！$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "幻之岛……\p"
	.string "那大概是因为天气变化而不断隐现的\n"
	.string "幻影。\p"
	.string "还是说，它真的不停地消失或出现？$"

