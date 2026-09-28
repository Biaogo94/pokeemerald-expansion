SSAqua_RoomNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND_HNS, SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_HNS, SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "你是一个人吗？那就来对战吧！$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "根本招架不住啊！$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "不知道关都有没有值得一爬的名山呢\n"
    .string "？$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "你知道莉莉吗？她是关都当红的DJ\n"
    .string "哦。$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "哇啊啊啊！$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "莉莉固然不错，但玛丽才是最棒的！\n"
    .string "好想听听看城都那边的广播节目啊！$"
