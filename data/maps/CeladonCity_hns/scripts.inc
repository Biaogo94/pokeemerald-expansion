CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "哎呀，{PLAYER}。今天的喷\n"
    .string "泉真漂亮啊。\p"
    .string "如果你还想与我切磋的话，我会在格\n"
    .string "斗道场恭候。$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
	.string "这只快泳蛙是我的搭档。\p"
	.string "不知道它还会不会进化成青蛙宝可梦\n"
	.string "呢。$"

CeladonCity_Text_Poliwrath:
	.string "快泳蛙：呱！$"

CeladonCity_Text_Teacher1:
	.string "老虎机又输光了……\p"
	.string "现在我们女孩子也玩这个呢。\p"
	.string "你也应该去试试看嘛。$"

CeladonCity_Text_Gramps1:
	.string "最近臭泥老是冒出来。\p"
	.string "看见房子前面的水池了吗？现在臭泥\n"
	.string "都住在那里了。\p"
	.string "它们到底是从哪里来的啊？这可真是\n"
	.string "个严重的问题……$"

CeladonCity_Text_Gramps2:
	.string "嘻嘻嘻！这个道馆太棒了！这里只有\n"
	.string "女孩子能进呢！$"

CeladonCity_Text_Youngster1:
	.string "想知道一个秘密吗？\p"
	.string "玉虹大厦其实有个隐蔽的后门哦。$"

CeladonCity_Text_Youngster2:
	.string "餐厅里正在举办大胃王比赛呢。\p"
	.string "光是看着他们狼吞虎咽，我都觉得肚\n"
	.string "子撑了……$"

CeladonCity_Text_Teacher2:
	.string "玉虹百货公司的商品种类最齐全、最\n"
	.string "丰富了。\p"
	.string "如果那里都买不到，别的地方就更买\n"
	.string "不到了。\p"
	.string "哎呀……我听起来真像个店\n"
	.string "员。$"

CeladonCity_Text_Lass:
	.string "边走边看着地面，感觉头好晕。$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "玉虹市\p"
	.string "描绘彩虹梦想之城$"

CeladonGym_Text_Sign:
	.string "玉虹市宝可梦道馆 馆主：莉佳\p"
	.string "喜爱大自然的大小姐$"

CeladonCity_Text_DeptStoreSign:
	.string "应有尽有的玉虹百货大楼！$"

CeladonCity_Text_MansionSign:
	.string "玉虹大厦$"

CeladonCity_Text_GameCornerSign:
	.string "人人畅玩的游乐场--玉虹游戏城$"

CeladonCity_Text_TrainerTips:
	.string "训练家贴士\p"
	.string "“效果防护”能保护宝可梦免受如\n"
	.string "“喷射火焰”与“冲浪”等特殊招式\l"
	.string "的影响。\p"
	.string "快来玉虹百货大楼选购吧！$"
