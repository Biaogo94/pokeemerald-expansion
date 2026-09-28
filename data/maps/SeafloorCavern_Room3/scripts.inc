SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "啊哈哈哈！\p"
	.string "没有潜水艇你是怎么追到这儿的？真\n"
	.string "是了不起的小家伙！\p"
	.string "不过……我可不会让你继续捣乱了，\p"
	.string "而且，天气研究所的账也该好好算算\n"
	.string "了……\p"
	.string "让你尝尝苦头吧！觉悟吧！$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "啊哈哈哈！\p"
	.string "好痛！$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "啊哈哈哈！强得离谱啊你。\p"
	.string "你不是海洋队的一员实在太遗憾了。\p"
	.string "本来你也能一起见证老大向我们承诺\n"
	.string "的那个美妙新世界的……$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "为了实现我们的梦想，我们需要宝可\n"
	.string "梦的力量。\p"
	.string "但是那些像你一样爱管闲事的人却总\n"
	.string "是用宝可梦的力量来碍事，甚至都追\l"
	.string "到了这里来！\p"
	.string "人生总是不能如我们所愿！$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "咕哇！$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "听着，我们从来不敢质疑老大想干的\n"
	.string "事。\p"
	.string "可你，一个小鬼头，竟然要对抗我们\n"
	.string "的老大。\p"
	.string "也许……你真是个人物。$"

