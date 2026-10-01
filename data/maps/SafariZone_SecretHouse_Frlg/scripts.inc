SafariZone_SecretHouse_Frlg_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM03, SafariZone_SecretHouse_EventScript_ExplainSurf
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	giveitem_msg SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant, ITEM_HM03
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_GOT_HM03
	release
	end

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_EventScript_ExplainSurf::
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
	.string "啊！终于！\p"
	.string "你是来到神秘小屋的第一个人！\p"
	.string "虽然我为我们这个比赛制订了周密的\n"
	.string "计划，\p"
	.string "但我还是很担心会没有人能赢走我们\n"
	.string "的比赛奖品。\p"
	.string "祝贺你！你赢了！$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
	.string "{PLAYER}从服务员那里得到\n"
	.string "了HM03！$"

SafariZone_SecretHouse_Text_ExplainSurf::
	.string "HM03是冲浪。\p"
	.string "宝可梦能够使用它载着你在水面上前\n"
	.string "进。\p"
	.string "还有，这个HM不是一次性的，所以你\n"
	.string "可以反复使用它。\p"
	.string "你非常幸运，赢得了这个令人难以置\n"
	.string "信的奖品！$"

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
	.string "你没有空间来接受这份这巨大的奖\n"
	.string "品！$"

