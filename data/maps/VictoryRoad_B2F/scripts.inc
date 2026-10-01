VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "我和我的家人一起训练，整个一个大\n"
	.string "家族啊！我不会输给任何人的！$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "比我的家人更强？！这可能吗？！$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "我比我家里的任何一个人都强，我之\n"
	.string "前从没输过的……\p"
	.string "我失去信心了……回家好了……$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "听说这附近来了一个很强的小孩，说\n"
	.string "的是你吗？$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "你这小鬼竟然这么强！$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "传言说那个很强的小孩来自橙华市。$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "你一定有点累了吧。$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "一点也看不出累来！$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "冠军之路和宝可梦联盟的挑战都会很\n"
	.string "累人的，作好准备吧！$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "有了很多道馆徽章就自大起来可不\n"
	.string "行，\p"
	.string "没听说过山外有山吗！$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "看来你比我还强！$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "看着自己收集的徽章，回忆一下那些\n"
	.string "曾与自己相逢的训练家们吧。$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "我做了这么多努力，但是紧张让我的\n"
	.string "肚子疼得厉害……$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "哦……痛死了……$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "一想到宝可梦联盟已经近在咫尺了我\n"
	.string "就紧张得不行。\p"
	.string "我只是假装冷静而已。$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "这个洞穴里聚集着精英中的精英。\p"
	.string "你有什么感觉？$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "一点都不紧张！$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "有胆量！我喜欢！加油吧！$"

