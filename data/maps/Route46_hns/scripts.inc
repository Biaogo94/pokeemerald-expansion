Route46_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY_HNS, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED_HNS, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_HNS, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten, Route46_EventScript_RegisterErin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route46_EventScript_RematchErin
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_RegisterErin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_ErinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERIN_HNS
	release
	end

Route46_EventScript_RematchErin::
	trainerbattle_rematch TRAINER_ERIN_HNS, Route46_Text_ErinRematchIntro, Route46_Text_ErinRematchDefeat
	msgbox Route46_Text_ErinPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "好咧！就让你见识一下大山里宝可梦\n"
	.string "的威力吧！$"

Route46_Text_HikerBaileyBeaten:
	.string "认输了！我见识到你的厉害了！$"

Route46_Text_HikerBaileyAfterBattle:
	.string "结束了啊。不过我不在意。我们登山\n"
	.string "男向来都是这么豁达。$"

Route46_Text_CamperTedSeen:
	.string "我也在培育宝可梦哦！\p"
	.string "能和我对战一场吗？$"

Route46_Text_CamperTedBeaten:
	.string "怎么会……？$"

Route46_Text_CamperTedAfterBattle:
	.string "我已经拼尽全力了，但还是棋差一招\n"
	.string "。\p"
	.string "不找借口--我承认是我输了。$"

Route46_Text_PicnickerErinSeen:
	.string "我也在培育宝可梦呢！\p"
	.string "能和我对战一场吗？$"

Route46_Text_PicnickerErinBeaten:
	.string "哎呀，真倒霉！$"

Route46_Text_PicnickerErinAfterBattle:
	.string "我去过很多道馆，但我最喜欢的还是\n"
	.string "满金市的道馆。\p"
	.string "因为那里到处都开满了漂亮的花！$"

Route46_Text_ErinRegister:
	.string "我去过很多道馆，但我最喜欢的还是\n"
	.string "满金市的道馆。\p"
	.string "因为那里到处都开满了漂亮的花！$"

Route46_Text_ErinRematchIntro:
	.string "我也在培育宝可梦呢！\p"
	.string "能和我对战一场吗？$"

Route46_Text_ErinRematchDefeat:
	.string "哎呀，真倒霉！$"

Route46_Text_ErinPostRematch:
	.string "我去过很多道馆，但我最喜欢的还是\n"
	.string "满金市的道馆。\p"
	.string "因为那里到处都开满了漂亮的花！$"

Route46_Text_PicnickerErin2Beaten:
	.string "呜……我怎么总是一直输啊\n"
	.string "！\p"
	.string "看来我必须更加努力才行！不管怎样\n"
	.string "，谢谢你一次又一次陪我对战。\p"
	.string "这是上次说好要送你的礼物。$"

Route46_Text_Sign:
	.string "46号道路前方山路$"
