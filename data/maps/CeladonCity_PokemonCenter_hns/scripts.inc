CeladonCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY_HNS
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "莉佳精通草属性宝可梦。\p"
	.string "要是大意的话，可是会吃大亏的哦。$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "火箭队的秘密基地就在游戏城地下。\p"
	.string "......啊，等等。那是三年前\n"
	.string "的事了。$"

Celadon_Text_Eusine1:
	.string "米那君：嗨！\p"
	.string "我回故乡来看看。\p"
	.string "真是有段日子没回来了。$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}，你听说了吗？\p"
	.string "最近又有传闻说有彩虹色的宝可梦出\n"
	.string "现在铃铛塔。\p"
	.string "我刚给同行宝可梦恢复了体力，现在\n"
	.string "正打算前往缘朱市。\p"
	.string "回头见啦，{PLAYER}！$"

Celadon_Text_NoBeasts:
	.string "顺便问一下，{PLAYER}。\p"
	.string "你捉到传说中的宝可梦雷公和炎帝了\n"
	.string "吗？\p"
	.string "<......><......><......>\p"
	.string "这样啊......\p"
	.string "如果你捉到了哪怕其中一只，也请一\n"
	.string "定要告诉我啊。\p"
	.string "拜托你啦，{PLAYER}！$"
