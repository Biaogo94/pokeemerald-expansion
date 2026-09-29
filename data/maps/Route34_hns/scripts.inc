Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
	
Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
	.string "喂！我正在找猴怪呢！$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "竟然输给路过的人了！$"

Route34_Text_YoungsterSamuel_After:
	.string "我要加倍努力修行才行。\p"
	.string "毕竟我的目标可是成为道馆馆主啊。$"

Route34_Text_YoungsterIan_Seen:
	.string "在班上我和宝可梦是最强的！$"

Route34_Text_YoungsterIan_Beaten:
	.string "怎么会！还有更厉害的训练家...\n"
	.string "...$"

Route34_Text_YoungsterIan_After:
	.string "我一直在努力，为了能成为班里的明\n"
	.string "星人物。$"

Route34_Text_CamperTodd_Seen:
	.string "我对培育宝可梦的能力很有自信。\p"
	.string "想瞧瞧看吗？$"

Route34_Text_CamperTodd_Beaten:
	.string "难道是我的培育方法搞错了？$"

Route34_Text_CamperTodd_After:
	.string "也许我该寄存在培育屋一只，或者用\n"
	.string "些道具什么的……$"

Route34_Text_ToddRegister:
	.string "也许我该寄存在培育屋一只，或者用\n"
	.string "些道具什么的……$"

Route34_Text_ToddRematchIntro:
	.string "我对培育宝可梦的能力很有自信。\p"
	.string "想瞧瞧看吗？$"

Route34_Text_ToddRematchDefeat:
	.string "难道是我的培育方法搞错了？$"

Route34_Text_ToddPostRematch:
	.string "也许我该寄存在培育屋一只，或者用\n"
	.string "些道具什么的……$"

Route34_Text_GinaRegister:
	.string "作为练习对手，你强得过头了啦。$"

Route34_Text_PicnickerGina_Seen:
	.string "你是训练家吗？\p"
	.string "来打一场练习赛吧。$"

Route34_Text_PicnickerGina_Beaten:
	.string "哎呀！完全赢不了啊……$"

Route34_Text_PicnickerGina_After:
	.string "作为练习对手，你强得过头了啦。$"

Route34_Text_OfficerKeith_Seen:
	.string "什么人？鬼鬼祟祟的想干什么？$"

Route34_Text_OfficerKeith_Win:
	.string "你这小家伙还挺厉害的。$"

Route34_Text_OfficerKeith_After:
	.string "嗯，今天一切正常。\p"
	.string "乖乖的，别惹麻烦哦。$"

Route34_Text_OfficerKeith_Daytime:
	.string "我正在巡逻，搜查可疑人员。$"

Route34_Text_PokefanBrandon_Seen:
	.string "我刚从培育屋领回了宝可梦。\p"
	.string "来看看它变得有多强吧！$"

Route34_Text_PokefanBrandon_Beaten:
	.string "怎么会变成这样？$"

Route34_Text_PokefanBrandon_After:
	.string "我的宝可梦领回来时学会了新招式。\p"
	.string "搞得我都不知道该怎么出招了！$"

Route34_Text_Sign_IlexForest:
	.string "穿过大门即是栎树林$"

Route34_Text_Sign_Route34:
	.string "34号道路满金市 - 桧皮镇\p"
	.string "栎树林位于其间$"

Route34_Text_TrainerTips:
	.string "训练家小贴士\p"
	.string "树果树每天都会多次结出新的树果。\p"
	.string "记下哪棵树结哪种树果吧。$"

Route34_Text_CooltrainerIrene_Seen:
	.string "艾琳：你是谁啊？！$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "艾琳：呜哇！你也太强了吧！$"

Route34_Text_CooltrainerIrene_After1:
	.string "艾琳：我姐姐凯特会帮我报仇的！$"

Route34_Text_CooltrainerIrene_After2:
	.string "艾琳：这片海滩很棒吧？\p"
	.string "这是我们小小的秘密度假胜地！$"

Route34_Text_CooltrainerJenn_Seen:
	.string "珍恩：搞什么啊……？你到\n"
	.string "底在干嘛？$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "珍恩：对不起，艾琳！亲爱的妹妹！$"

Route34_Text_CooltrainerJenn_After1:
	.string "珍恩：别得意！我们的大姐凯特可是\n"
	.string "很厉害的！$"

Route34_Text_CooltrainerJenn_After2:
	.string "珍恩：多晒晒太阳能让身体变得更棒\n"
	.string "。$"

Route34_Text_CooltrainerKate_Seen:
	.string "凯特：居然敢欺负我的妹妹们，看我\n"
	.string "怎么收拾你！$"

Route34_Text_CooltrainerKate_Beaten:
	.string "凯特：怎么可能！我居然输了。$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "凯特：你真厉害。我们输得心服口\n"
	.string "服……\p"
	.string "来，把这个拿去吧！$"

Route34_Text_CooltrainerKate_After:
	.string "凯特：突然袭击你，真对不起。\p"
	.string "我们完全没想到会有人找到这里来。\n"
	.string "你可真把我们吓了一跳。$"


Route34_Text_Sign_DayCare:
	.string "培育屋\p"
	.string "让我们替您照料宝可梦！$"
