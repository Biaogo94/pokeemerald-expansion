SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano:
	.string "海底火山爆发后，从深海中升起，\p"
	.string "火山口露出海面，被雨水填满。\p"
	.string "琉璃市的历史就由此开端。$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething:
	.string "连接琉璃市和外界的洞窟……\p"
	.string "就好像那洞窟是为了防止什么离开而\n"
	.string "建造的。\p"
	.string "这只是我的想象吗？$"

