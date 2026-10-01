SSAqua_RoomSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE_HNS, SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE_HNS, SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "我想忘掉伤心事。来对战吧！$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "我的心在哭泣……$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "航海是治愈失恋最好的良药。\p"
    .string "但这高速船的旅途太短了，悲伤都还\n"
    .string "没来得及消散呢。$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "我要去满金电台为我的新歌试音呢。$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "哇哦！彻底跑调了！$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "我原本还打算在对战塔上出道呢...\n"
    .string "...\p"
    .string "看来我得先回枯叶市重新修行一番\n"
    .string "了......$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "说到广播电台，这周的幸运号码是多\n"
    .string "少啊？$"
