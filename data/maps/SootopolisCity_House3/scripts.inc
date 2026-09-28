SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "你是宝可梦训练家吗？\p"
	.string "有很多人喜欢琉璃市的亚当，甚至比\n"
	.string "喜欢米可利的还多！\p"
	.string "也有人喜欢你吗？$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "呀，那么你肯定很强。$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "哎呀……这样可有点寂寞。\p"
	.string "你得更努力些，那样才会有粉丝跟着\n"
	.string "你的。$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "追星的人们甚至都会从丰缘地区以外\n"
	.string "的地方赶来，\p"
	.string "我上次去水静市的训练家俱乐部时真\n"
	.string "正见识到了他们的狂热。$"

