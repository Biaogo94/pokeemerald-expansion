SSAqua_RoomSE_hns_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN_HNS, SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
    .string "嘿，小鬼！想跟我对战吗？$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
    .string "你好强！$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
    .string "你一个人在旅行吗？妈妈不担心你\n"
    .string "吗？$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
    .string "你以为我是小宝宝吗？太不公平了！$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
    .string "哎呀！输掉了！$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
    .string "把我们女孩子叫做小宝宝，太没礼貌\n"
    .string "了！$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
    .string "我才不是小宝宝！对淑女这么说太失\n"
    .string "礼了！$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
    .string "哎呀！输掉了！$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
    .string "有时候，小孩子比大人还要聪明呢！$"
