Route32_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32_HNS
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "这里是个绝佳的钓鱼点。\p"
	.string "你看到有人在钓鱼了吧？你觉得怎么\n"
	.string "样？\p"
	.string "想要一根我的钓竿吗？$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "嘿，听到你这么说真高兴。\p"
	.string "现在你也是钓鱼人啦！$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "钓鱼太棒了！\p"
	.string "只要有水，不管是大海还是小溪，都\n"
	.string "去试试你的钓竿吧。$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "哎呀。真让人失望啊……$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "哟，小朋友。鱼上钩了吗？$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "该让我的宝可梦携带什么好呢？\p"
	.string "也许是能提升攻击威力的道具...\n"
	.string "...$"

