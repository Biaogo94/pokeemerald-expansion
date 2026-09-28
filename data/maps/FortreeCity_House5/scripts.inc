FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "茵郁市的树屋很棒！\p"
	.string "我想这里是和宝可梦共同生活的最好\n"
	.string "的地方。$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "为了生存，人类和宝可梦适应了自然\n"
	.string "，\p"
	.string "因此我们没必要让自然遵循我们的规\n"
	.string "则。$"

FortreeCity_House5_Text_Zigzagoon:
	.string "蛇纹熊：噗噗噗！$"

