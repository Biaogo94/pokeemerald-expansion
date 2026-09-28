VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	setflag FLAG_GOT_VS_SEEKER
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
	.string "即使是相同的等级，宝可梦能拥有非\n"
	.string "常不同的技能和力量。\p"
	.string "训练家培育的宝可梦要强于野生的。$"

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
	.string "我的宝可梦中毒了！我们走路的时候\n"
	.string "它会进入濒死状态！$"

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
	.string "确实一只等级高的宝可梦会更厉害…\n"
	.string "…\p"
	.string "但是，所有的宝可梦在对上特定的系\n"
	.string "的时候都会有弱点。\p"
	.string "所以，没有一只永远强大的宝可梦。$"

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
	.string "对曾经战斗过的人你有过……\p"
	.string "想要再次挑战的欲望吗？我想你肯定\n"
	.string "有过。\p"
	.string "我也想一次又一次地和从前的某些人\n"
	.string "战斗。\p"
	.string "我就是以这样的方式在战斗着。拿着\n"
	.string "这个吧！$"

VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches::
	.string "用这个装置你可以找到曾经战斗过的\n"
	.string "训练家再战。\p"
	.string "但是你在使用前得把电充好。$"

VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker::
	.string "你是怎样使用对战搜寻器的？这没什\n"
	.string "么困难的。\p"
	.string "使用时会发出哔-哔-嘟的声音，你\n"
	.string "再看看周围的训练家。\p"
	.string "如过任何训练家想再战，它会让你马\n"
	.string "上知道。\p"
	.string "当你在室外时，记得先充好电。$"
