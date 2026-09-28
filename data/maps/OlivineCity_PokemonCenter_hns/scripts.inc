OlivineCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "隔壁浅黄咖啡馆的水手大叔人可大方\n"
	.string "了。\p"
	.string "他教了我的宝可梦“劲力”。\p"
	.string "现在它轻轻松松就能推动大圆石了。$"

OlivineCity_Text_PokecenterTeacher:
	.string "大海对面的湛蓝市有个人，\p"
	.string "听说他整天到处吹嘘自己拥有稀有的\n"
	.string "宝可梦呢。$"
