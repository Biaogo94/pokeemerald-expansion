Gate_RuinsOfAlph_Route36_hns_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "阿露福遗迹\p"
	.string "触碰与探索的观光胜地\p"
	.string "试着滑动石板拼图吧！$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "你在调查遗迹吗？\p"
	.string "我看你很有当科学家的潜质呢。$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "石板上刻着图案。\p"
	.string "我试着移动了一下，不知道到底是什\n"
	.string "么意思呢。$"
