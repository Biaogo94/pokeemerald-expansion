VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "一想到我离宝可梦联盟越来越近了…\n"
	.string "…\p"
	.string "我开始有些怯场的感觉了……$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "我什么也做不了……$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "宝可梦联盟又变得遥远了……好失望\n"
	.string "……$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "想要通过宝可梦联盟的考验，你必须\n"
	.string "信任你的宝可梦。$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "是你们之间的信赖将你们紧紧联系在\n"
	.string "一起。$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "形影不离，患难与共，宝可梦和训练\n"
	.string "家的信任会逐渐增强。$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "这里不是终点，这只是通向宝可梦联\n"
	.string "盟的道路上的一个小站。$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "就是这样！$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "你一定会干得很好的！你的宝可梦都\n"
	.string "那么渴望着胜利！$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "我的宝可梦的士气已经达到了顶点！$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "我从来没见过像你这样的人。$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "就算在战斗之外，我也能感受到从你\n"
	.string "和你的宝可梦身上散发出的力量。$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "好了，别那么紧张！放松，放松一点\n"
	.string "！$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "哇啊！漂亮！$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "尽管这里的确是冠军之路，\p"
	.string "但它与你之前所经过的道路并无太大\n"
	.string "不同。\p"
	.string "试着去享受你之后将会遇到的一切吧\n"
	.string "！$"

