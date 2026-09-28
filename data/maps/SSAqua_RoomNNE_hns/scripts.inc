SSAqua_RoomNNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN_HNS, SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL_HNS, SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "我正要去关都检验自己的实力。$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "好想赢啊！$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "来自城都的训练家也可以挑战关都的\n"
    .string "道馆馆主呢。$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "我正为了成为冠军而努力修行！$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "我们之间的差距到底在哪里？$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "总有一天我会打败你的！$"
