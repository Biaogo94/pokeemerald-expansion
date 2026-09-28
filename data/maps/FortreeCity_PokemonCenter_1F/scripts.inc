FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "孩子，我问你，你在收集宝可梦图鉴\n"
	.string "吗？\p"
	.string "唔……那么听我的，到狩猎地带去。$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "你去过记录角吗？\p"
	.string "那里超有意思的，可以混合训练家的\n"
	.string "记录。\p"
	.string "虽然搞不懂具体原理，但它很棒，甚\n"
	.string "至令人吃惊！$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "哇，你有宝可导航！就和我的一样！\p"
	.string "你知道宝可导航的对战寻呼系统吗？\p"
	.string "用它能随时跟登记的训练家联系，\p"
	.string "同时也能显示出哪个训练家想跟你对\n"
	.string "战。\p"
	.string "这太方便了！得文的人真的很优秀！$"

