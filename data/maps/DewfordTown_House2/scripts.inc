DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "来一饱眼福吧！\p"
	.string "这是丝绸围巾，是正流行的款式！\p"
	.string "啊，你的眼睛兴奋地发光了！你欣赏\n"
	.string "我这眩目的款式！\p"
	.string "啊，真高兴！给你吧，送给你了！$"

DewfordTown_House2_Text_NoRoom:
	.string "呀，你没地方装了？\p"
	.string "那，听好，这个围巾是你的必备品！\n"
	.string "哎，我要是你，我会卖掉我的一切来\l"
	.string "得到它！$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "丝绸围巾能提升一般属性招式的威\n"
	.string "力，\p"
	.string "是对几乎所有宝可梦都有极大用处的\n"
	.string "头巾！$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "哇，你是渡海来到武斗镇的吗？\p"
	.string "是因为听说藤树而来的吗？\p"
	.string "他真的很棒……大家都很崇敬他。$"

