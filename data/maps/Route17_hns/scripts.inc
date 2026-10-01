Route17_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY_HNS, Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten, Route17_EventScript_RegisterRiley
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchRiley
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterRiley::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_RileyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RILEY_HNS
	release
	end

Route17_EventScript_RematchRiley::
	trainerbattle_rematch TRAINER_RILEY_HNS, Route17_Text_RileyRematchIntro, Route17_Text_RileyRematchDefeat
	msgbox Route17_Text_RileyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_RILEY_2_HNS, Route17_EventScript_RematchRileyTryGiveItem
	end

Route17_EventScript_RematchRileyTryGiveItem::
	checkitem ITEM_TM_TOXIC
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_TOXIC
	closemessage
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL_HNS, Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten, Route17_EventScript_RegisterJoel
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchJoel
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterJoel::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JoelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEL_HNS
	release
	end

Route17_EventScript_RematchJoel::
	trainerbattle_rematch TRAINER_JOEL_HNS, Route17_Text_JoelRematchIntro, Route17_Text_JoelRematchDefeat
	msgbox Route17_Text_JoelPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_JOEL_2_HNS, Route17_EventScript_RematchJoelTryGiveItem
	end

Route17_EventScript_RematchJoelTryGiveItem::
	checkitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BRICK_BREAK
	closemessage
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN_HNS, Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES_HNS, Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten, Route17_EventScript_RegisterCharles
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchCharles
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterCharles::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CharlesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHARLES_HNS
	release
	end

Route17_EventScript_RematchCharles::
	trainerbattle_rematch TRAINER_CHARLES_HNS, Route17_Text_CharlesRematchIntro, Route17_Text_CharlesRematchDefeat
	msgbox Route17_Text_CharlesPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CHARLES_2_HNS, Route17_EventScript_RematchCharlesTryGiveItem
	end

Route17_EventScript_RematchCharlesTryGiveItem::
	checkitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BULK_UP
	closemessage
	end

Route17_Text_BikerRileySeen:
	.string "喂，你！你是从城都来的吧？$"

Route17_Text_BikerRileyBeaten:
	.string "哇，真有两下子！$"

Route17_Text_BikerRileyAfterBattle:
	.string "别太得意了，你这城都来的小鬼！$"

Route17_Text_BikerJoelSeen:
	.string "哇，那辆自行车真帅！$"

Route17_Text_BikerJoelBeaten:
	.string "但你不光是看起来帅而已…….$"

Route17_Text_BikerJoelAfterBattle:
	.string "我看起来很酷，但实力太弱，所以根\n"
	.string "本算不上真帅。\p"
	.string "我必须更加努力特训才行…….$"

Route17_Text_BikerGlennSeen:
	.string "喂！想来一场速度的对决吗？$"

Route17_Text_BikerGlennBeaten:
	.string "哇呀！你的冲劲真猛！$"

Route17_Text_BikerGlennAfterBattle:
	.string "在自行车道上，双手脱把骑行才叫帅\n"
	.string "气。$"

Route17_Text_BikerCharlesSeen:
	.string "我们可是无所畏惧的公路之星！$"

Route17_Text_BikerCharlesBeaten:
	.string "啊啊啊！彻底翻车啦！$"

Route17_Text_BikerCharlesAfterBattle:
	.string "危险驾驶会导致事故的！骑慢点悠着\n"
	.string "点！$"

Route17_Text_RileyRegister:
	.string "对城都的小鬼来说，算不错了！$"

Route17_Text_RileyRematchIntro:
	.string "城都小鬼也就只能赢这么一回！$"

Route17_Text_RileyRematchDefeat:
	.string "我被打趴了……$"

Route17_Text_RileyPostRematch:
	.string "也许我也应该去城都修行一下了。$"

Route17_Text_JoelRegister:
	.string "你果然挺帅气的嘛！来交换电话号码\n"
	.string "吧！$"

Route17_Text_JoelRematchIntro:
	.string "来看看现在到底谁更帅！$"

Route17_Text_JoelRematchDefeat:
	.string "还是不够帅气啊……$"

Route17_Text_JoelPostRematch:
	.string "小鬼，为了能变得和你一样帅，我会\n"
	.string "继续特训的！$"

Route17_Text_CharlesRegister:
	.string "小鬼，你跟我一样是个芳心纵火犯\n"
	.string "啊！把你的号码告诉我吧！$"

Route17_Text_CharlesRematchIntro:
	.string "我可不仅是公路之星，还是个芳心纵\n"
	.string "火犯！$"

Route17_Text_CharlesRematchDefeat:
	.string "又彻底翻车了！$"

Route17_Text_CharlesPostRematch:
	.string "我在合众地区也遇到过像你这样的训\n"
	.string "练家。可别翻车咯！$"

