SSAqua_RoomSSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE_HNS, SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN_HNS, SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "我要去关都表演喷火特技！$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "扑哧……火苗太小了......$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "看来在海上火势会变弱啊。跟这没关\n"
    .string "系？真的假的？$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "我要去奶奶家抓虫宝可梦！$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "哇啊，你好厉害！$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "在城都的树上能找到好多宝可梦呢！$"
