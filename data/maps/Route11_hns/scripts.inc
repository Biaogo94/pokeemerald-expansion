Route11_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN_HNS, Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON_HNS, Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN_HNS, Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL_HNS, Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_EventScript_Item_Grass_Knot::
    finditem ITEM_TM_GRASS_KNOT
    end

Route11_Text_Engineer:
	.string "我看见树上有只奇怪的宝可梦爬来爬\n"
	.string "去，不过看起来不像猴怪.....\l"
	.string ".$"

Route11_Text_YoungsterOwenSeen:
	.string "宝可梦对战中可不能耍小聪明。\p"
	.string "让我们堂堂正正地比一场吧！$"

Route11_Text_YoungsterOwenBeaten:
	.string "咦？怎么会这样？！$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "我光明磊落、问心无愧地战斗了。\p"
	.string "我一点都不后悔。$"

Route11_Text_YoungsterJasonSeen:
	.string "穿着短裤走在草丛里，腿上总是痒痒\n"
	.string "的。$"

Route11_Text_YoungsterJasonBeaten:
	.string "哎呀--！我被打得落花流水！$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "我要去草丛里捉更多宝可梦！$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "......\p"
	.string "我闭着眼睛的时候居然输了....\n"
	.string "..$"

Route11_Text_PsychicFidelSeen:
	.string "我看见了......\p"
	.string "关于你的一切，我都看透了....\n"
	.string "..$"

Route11_Text_PsychicFidelBeaten:
	.string "我竟然无法预见你的力量.....\n"
	.string ".$"

Route11_Text_PsychicFidelAfterBattle:
	.string "信念的力量......\p"
	.string "你之所以强大，是因为你全心信任着\n"
	.string "自己的宝可梦。$"

Route11_Text_Sign:
	.string "11号道路$"

