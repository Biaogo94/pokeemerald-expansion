CeruleanCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 1
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
	.string "那个正辉！\p"
	.string "我听说他会不择手段地去取得珍贵的\n"
	.string "宝可梦。\p"
	.string "除此之外，他不做任何与之无关的\n"
	.string "事。$"

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
	.string "你听说过正辉吗？\p"
	.string "人们都叫他怪兽狂！\p"
	.string "但我觉得这是人们嫉妒正辉。\p"
	.string "谁不想炫耀一下他们的宝可梦？$"

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
	.string "正辉有很多的宝可梦！他也收集珍贵\n"
	.string "的宝可梦！$"

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
	.string "你问什么不上楼去试着和你的朋友交\n"
	.string "换宝可梦？\p"
	.string "通过交换你会获得更多的种类。\p"
	.string "通过交换得来的宝可梦也成长得很\n"
	.string "快。$"

