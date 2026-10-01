ThreeIsland_House2_Frlg_MapScripts::
	.byte 0

ThreeIsland_House2_EventScript_Man::
	lock
	faceplayer
	famechecker FAMECHECKER_SABRINA, 1
	msgbox ThreeIsland_House2_Text_IAdmireSabrina
	release
	end

ThreeIsland_House2_EventScript_Rocker::
	msgbox ThreeIsland_House2_Text_CantMakeThisSpoonBend, MSGBOX_NPC
	end

ThreeIsland_House2_Text_CantMakeThisSpoonBend::
	.string "嗯……………呃……！\p"
	.string "……不行啊！我不可能用我的意念把这\n"
	.string "个勺子弄弯啊！\p"
	.string "也许我根本没有超能力。$"

ThreeIsland_House2_Text_IAdmireSabrina::
	.string "你认识金黄市的道馆馆主吗？\p"
	.string "她擅长使用超能力属性的宝可梦，没\n"
	.string "错吧？\p"
	.string "我喜欢她，真的很喜欢！\p"
	.string "我听说她也来过这里旅游！$"

