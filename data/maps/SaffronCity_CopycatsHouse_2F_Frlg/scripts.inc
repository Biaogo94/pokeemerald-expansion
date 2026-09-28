SaffronCity_CopycatsHouse_2F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, EventScript_MimicTutor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, FEMALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
	.string "{PLAYER}：嗨！你喜欢宝可\n"
	.string "梦吗？\p"
	.string "{PLAYER}：喔，不，我只是\n"
	.string "问问你罢了。\p"
	.string "{PLAYER}：嗯？你确实很厉\n"
	.string "害！\p"
	.string "模仿少女：嗯？快速模仿？对，那是\n"
	.string "我的爱好！$"

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
	.string "{PLAYER}：嗨。你一定热爱\n"
	.string "着宝可梦\p"
	.string "{PLAYER}：不，不是问我。\n"
	.string "我是在问你。\p"
	.string "{PLAYER}：再说一遍？你真\n"
	.string "古怪！模仿少女：嗯？快速模仿？那\l"
	.string "是我的最爱！$"

Text_MimicTeach::
	.string "哇塞！皮皮玩偶\p"
	.string "给我的？谢谢你！\p"
	.string "你想要什么？我能教给你模仿这个技\n"
	.string "能。$"

Text_MimicDeclined::
	.string "你不喜欢模仿？$"

Text_MimicWhichMon::
	.string "我真的很喜欢模仿！谁想要来学会这\n"
	.string "个技能？$"

Text_MimicTaughtMale::
	.string "{PLAYER}：嗨！首先要谢谢\n"
	.string "你！\p"
	.string "{PLAYER}：再说一遍？\p"
	.string "{PLAYER}：模仿我的动作很\n"
	.string "有意思吗？\p"
	.string "模仿少女：你敢打赌的吧！那真是太\n"
	.string "有意思了！$"

Text_MimicTaughtFemale::
	.string "{PLAYER}：嗨谢谢你为我做\n"
	.string "的一切！\p"
	.string "{PLAYER}：再说一遍？\p"
	.string "{PLAYER}：学我说话很有意\n"
	.string "思吗？\p"
	.string "模仿达人：你敢打赌吗？那真是太有\n"
	.string "意思了！$"

SaffronCity_CopycatsHouse_2F_Text_Doduo::
	.string "嘟嘟：嘻嘻！\p"
	.string "魔镜魔镜告诉我，谁是这个世界上最\n"
	.string "漂亮的人？$"

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
	.string "这真是少见的宝可梦啊！嗯？这只是\n"
	.string "个玩偶！$"

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
	.string "游戏里马力欧正在用头顶蘑菇！$"

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
	.string "……\p"
	.string "我的秘密！\p"
	.string "我的特长：模仿！我的爱好：收集玩\n"
	.string "偶！我最喜欢的宝可梦：皮皮！$"

