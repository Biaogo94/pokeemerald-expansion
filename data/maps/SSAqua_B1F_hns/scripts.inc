SSAqua_B1F_hns_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "Yuck!\n"
    .string "Shouldn't have looked!$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Hey, kid. Could I get you to\n"
	.string "look for my buddy?\p"
	.string "He's goofing off somewhere,\n"
	.string "that lazy bum!\p"
	.string "I want to go find him, but I'm\n"
	.string "on duty right now.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "哎呀，糟了......\p"
	.string "船长一定会大发雷霆的......$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "Thanks, kid! I chewed him out\n"
	.string "good so he'll quit slacking off!$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "小女孩？\p"
	.string "我好像看到她从这里经过了。$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "The dining room is up ahead.\p"
	.string "The stairs at the end lead to\n"
	.string "the CAPTAIN's cabin.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF_HNS, SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "Nothing beats a battle when\n"
	.string "I'm on my break.$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "输赢无所谓，我的休息时间结束了！$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "看来不认真起来的话，确实赢不了呢\n"
	.string "。$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA_HNS, SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "好无聊啊。要来对战吗？$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "哎呀！你也太强了吧！$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "SAFFRON, CELADON… I hear there\n"
	.string "are many big cities in KANTO.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ_HNS, SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "呃呕......我晕船了！$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "我已经一步也走不动了......$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "我再也不坐船了。下次，\p"
	.string "我一定要坐磁浮列车。$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT_HNS, SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "这里可是我们水手工作的地方！$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "在自己的主场居然输了......$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "从枯叶市到浅黄市之间，每次搭载的\n"
	.string "乘客都\p"
	.string "各不相同呢。$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH_HNS, SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "明明都出到海上了，却不能钓鱼！\p"
	.string "好无聊啊！来对战吧！$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "我......我现在不无聊了..\n"
	.string "....$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "我打算去枯叶市的码头上钓鱼。$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI_HNS, SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "我顶着船身的摇晃死撑着，以此\p"
	.string "来锻炼我的下盘呢！$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "彻底被晃翻了！$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "我在城都找不到空手道大王。\p"
	.string "听说他正在某个洞窟里修行呢。$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH_HNS, SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "我是一个水手！\p"
	.string "不过我也在训练宝可梦，为了能成为\n"
	.string "冠军！$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "显然是我欠缺修行啊......$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "8枚徽章！这肯定能证明你击败了\p"
	.string "道馆馆主们。\p"
	.string "怪不得你实力这么强！$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY_HNS, SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "休想碰我的学生一根手指！$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "啊呀！$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "我们是来桔梗市郊外的遗迹进行校外\n"
	.string "教学的。$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE_HNS, SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "你知道阿露福遗迹吗？$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "哇啊！$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "在遗迹里面，收音机会接收到奇怪的\n"
	.string "信号。$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_HNS, SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "阿露福遗迹里有一些奇怪的石板。$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "被打得落花流水！$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "我曾在书上读到过，那种石板一共有\n"
	.string "4处呢。$"

