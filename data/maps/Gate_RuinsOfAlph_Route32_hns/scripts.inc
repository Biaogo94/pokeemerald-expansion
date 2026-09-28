Gate_RuinsOfAlph_Route32_hns_MapScripts::
	.byte 0


Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_Text_PokefanM:
	.string "你正在调查遗迹吗？看来是个未来的\n"
	.string "科学家呢。$"

Gate_RuinsOfAlph_Route32_Text_Youngster:
	.string "石板上刻着图案。\p"
	.string "我试着移动了一下，不知道到底是什\n"
	.string "么意思呢。$"
