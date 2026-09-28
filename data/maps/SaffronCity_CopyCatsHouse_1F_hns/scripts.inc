SaffronCity_CopyCatsHouse_1F_hns_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "My daughter likes to mimic people.\p"
	.string "Her mimicry has earned her the\n"
	.string "nickname COPYCAT around here.$"

CopycatsHouse1F_Text_PokefanF:
	.string "我女儿太以自我为中心了.....\n"
	.string ".\p"
	.string "所以她朋友少得可怜。$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "她最近弄丢了三年前一个男孩子送给\n"
	.string "她的宝可梦玩偶。\p"
	.string "从那以后，她的模仿技术反而变得更\n"
	.string "加炉火纯青了......$"

CopycatsHouse1F_Text_Blissey:
	.string "幸福蛋：波哩嘻--！$"
