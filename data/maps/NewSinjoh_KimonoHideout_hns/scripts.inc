NewSinjoh_KimonoHideout_hns_MapScripts::
   map_script MAP_SCRIPT_ON_FRAME_TABLE, NewSinjoh_KimonoHideout_OnFrame
    .byte 0


NewSinjoh_KimonoHideout_OnFrame:
	map_script_2 VAR_SINJOH_STORYLINE, 4, NewSinjoh_KimonoHideout_EventScript_PlayerMeetsKimonos
	.2byte 0

@ ============INTRO CUTSCENE=====================================================================================

NewSinjoh_KimonoHideout_EventScript_PlayerMeetsKimonos::
	lock
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsKimonos, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, NewSinjoh_KimonoHideout_Movement_PlayerWalksIntoRoom
	waitmovement 0

	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_MIHARU, NewSinjoh_KimonoHideout_Movement_KimonoWalksDown
	waitmovement 0
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsMiharu, MSGBOX_AUTOCLOSE
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_MIHARU, NewSinjoh_KimonoHideout_Movement_KimonoWalksUp
	waitmovement 0

	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_SHIZUKO, NewSinjoh_KimonoHideout_Movement_KimonoWalksDown
	waitmovement 0
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsShizuko, MSGBOX_AUTOCLOSE
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_SHIZUKO, NewSinjoh_KimonoHideout_Movement_KimonoWalksUp
	waitmovement 0

	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_YOUKO, NewSinjoh_KimonoHideout_Movement_KimonoWalksDown
	waitmovement 0
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsYouko, MSGBOX_AUTOCLOSE
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_YOUKO, NewSinjoh_KimonoHideout_Movement_KimonoWalksUp
	waitmovement 0

	setvar VAR_SINJOH_STORYLINE, 5
	release
	end

NewSinjoh_KimonoHideout_Movement_PlayerWalksIntoRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewSinjoh_KimonoHideout_Movement_KimonoWalksDown:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	walk_down
	step_end

NewSinjoh_KimonoHideout_Movement_KimonoWalksUp:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	walk_up
	face_down
	step_end

NewSinjoh_KimonoHideout_Text_PlayerMeetsKimonos:
	.string "{PLAYER}。\p"
	.string "请到跟前来。$"

NewSinjoh_KimonoHideout_Text_PlayerMeetsMiharu:
    .string "美晴：欢迎来到新神都，\n"
    .string "{PLAYER}。\p"
    .string "世世代代以来，这个村落一直远离外\n"
    .string "界探寻的目光，与无比强大的宝可梦\l"
    .string "和平共处。\p"
    .string "然而最近神圣神殿中发生的事，以及\n"
    .string "随之涌入的不速之客，正威胁并打破\l"
    .string "着我们守护已久的脆弱平衡。$"

NewSinjoh_KimonoHideout_Text_PlayerMeetsShizuko:
	.string "静子：我们在圆朱市的姐妹们已经告\n"
	.string "诉我们，你与城都地区的传说中的宝\l"
	.string "可梦有着深厚羁绊，并且是一名身手\l"
	.string "不凡的训练家。\p"
	.string "我们相信，在这个多事之秋，你能够\n"
	.string "助我们一臂之力。$"

NewSinjoh_KimonoHideout_Text_PlayerMeetsYouko:
	.string "洋子：请前往50号道路以北的神都\n"
	.string "遗迹。\p"
	.string "去见见那里的研究员，并调查引发他\n"
	.string "们前来的事件。\p"
	.string "绝对不能让平庸之辈惊扰了那里的传\n"
	.string "说中的宝可梦。$"


@ ============KIMONO GIRL NPCs=====================================================================================

NewSinjoh_KimonoHideout_EventScript_Miharu::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_KimonoHideout_EventScript_MiharuFinal
	goto_if_defeated TRAINER_MIHARU_HNS, NewSinjoh_KimonoHideout_EventScript_MiharuAfter
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsMiharu, MSGBOX_AUTOCLOSE
	goto_if_not_defeated TRAINER_MIHARU_HNS, NewSinjoh_KimonoHideout_EventScript_TryMiharuBattle
	release
	end
NewSinjoh_KimonoHideout_EventScript_TryMiharuBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, NewSinjoh_KimonoHideout_EventScript_MiharuBattle
	release
	end
NewSinjoh_KimonoHideout_EventScript_MiharuBattle::
	msgbox NewSinjoh_KimonoHideout_Text_MiharuBeforeBattle, MSGBOX_DEFAULT
	closemessage
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 0, 0, 2, 0
	trainerbattle_no_intro TRAINER_MIHARU_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	giveitem ITEM_MEADOW_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox NewSinjoh_KimonoHideout_Text_MiharuAfter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
NewSinjoh_KimonoHideout_EventScript_MiharuAfter::
	msgbox NewSinjoh_KimonoHideout_Text_MiharuAfter, MSGBOX_AUTOCLOSE
	release
	end

NewSinjoh_KimonoHideout_Text_MiharuBeforeBattle:
	.string "美晴：正如我们所料。\p"
	.string "那位痴迷石头的冠军派你来收集石板\n"
	.string "对吧。\p"
	.string "我们一门数百年来看守着这些石板。\p"
	.string "可不会轻易就将它们拱手相让。$"

NewSinjoh_KimonoHideout_Text_MiharuAfter:
	.string "美晴：你确实有此资格。$"

NewSinjoh_KimonoHideout_EventScript_MiharuFinal::
	msgbox NewSinjoh_KimonoHideout_Text_MiharuFinal, MSGBOX_AUTOCLOSE
	end

NewSinjoh_KimonoHideout_Text_MiharuFinal:
	.string "美晴：你为我们的村子立下了大功，\n"
	.string "{PLAYER}。\p"
	.string "我们绝不会忘记这份恩情。$"

NewSinjoh_KimonoHideout_EventScript_Youko::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_KimonoHideout_EventScript_YoukoFinal
	goto_if_defeated TRAINER_YOUKO_HNS, NewSinjoh_KimonoHideout_EventScript_YoukoAfter
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsYouko, MSGBOX_AUTOCLOSE
	goto_if_not_defeated TRAINER_YOUKO_HNS, NewSinjoh_KimonoHideout_EventScript_TryYoukoBattle
	release
	end
NewSinjoh_KimonoHideout_EventScript_TryYoukoBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, NewSinjoh_KimonoHideout_EventScript_YoukoBattle
	release
	end
NewSinjoh_KimonoHideout_EventScript_YoukoBattle::
	msgbox NewSinjoh_KimonoHideout_Text_YoukoBeforeBattle, MSGBOX_DEFAULT
	closemessage
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 1, 2, 2, 2
	trainerbattle_no_intro TRAINER_YOUKO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	giveitem ITEM_ICICLE_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox NewSinjoh_KimonoHideout_Text_YoukoAfter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
NewSinjoh_KimonoHideout_EventScript_YoukoAfter::
	msgbox NewSinjoh_KimonoHideout_Text_YoukoAfter, MSGBOX_AUTOCLOSE
	release
	end

NewSinjoh_KimonoHideout_Text_YoukoBeforeBattle:
	.string "洋子：姐妹们把你夸得神乎其神。\p"
	.string "到底是不是真的呢？\p"
	.string "就让我亲自来见识一下吧。$"

NewSinjoh_KimonoHideout_Text_YoukoAfter:
	.string "洋子：姐妹们果然没有看错你。$"

NewSinjoh_KimonoHideout_EventScript_YoukoFinal::
	msgbox NewSinjoh_KimonoHideout_Text_YoukoFinal, MSGBOX_AUTOCLOSE
	end

NewSinjoh_KimonoHideout_Text_YoukoFinal:
	.string "洋子：起初我还有所怀疑。\p"
	.string "但看到你的所作所为，已经毋庸置疑\n"
	.string "了。$"

NewSinjoh_KimonoHideout_EventScript_Shizuko::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_KimonoHideout_EventScript_ShizukoFinal
	goto_if_defeated TRAINER_SHIZUKO_HNS, NewSinjoh_KimonoHideout_EventScript_ShizukoAfter
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsShizuko, MSGBOX_AUTOCLOSE
	goto_if_not_defeated TRAINER_SHIZUKO_HNS, NewSinjoh_KimonoHideout_EventScript_TryShizukoBattle
	release
	end
NewSinjoh_KimonoHideout_EventScript_TryShizukoBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, NewSinjoh_KimonoHideout_EventScript_ShizukoBattle
	release
	end
NewSinjoh_KimonoHideout_EventScript_ShizukoBattle::
	msgbox NewSinjoh_KimonoHideout_Text_ShizukoBeforeBattle, MSGBOX_DEFAULT
	closemessage
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 1, 0, 0, 1, 0
	trainerbattle_no_intro TRAINER_SHIZUKO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	giveitem ITEM_PIXIE_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox NewSinjoh_KimonoHideout_Text_ShizukoAfter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
NewSinjoh_KimonoHideout_EventScript_ShizukoAfter::
	msgbox NewSinjoh_KimonoHideout_Text_ShizukoAfter, MSGBOX_AUTOCLOSE
	release
	end

NewSinjoh_KimonoHideout_Text_ShizukoBeforeBattle:
	.string "静子：我们不仅精通舞蹈，在对战方\n"
	.string "面也受过严苛的训练。\p"
	.string "想要获得石板，必须具备强大的实力\n"
	.string "与坚定的意志。$"

NewSinjoh_KimonoHideout_Text_ShizukoAfter:
	.string "静子：你与宝可梦之间的羁绊十分深\n"
	.string "厚。\p"
	.string "这块石板你受之无愧。$"

NewSinjoh_KimonoHideout_EventScript_ShizukoFinal::
	msgbox NewSinjoh_KimonoHideout_Text_ShizukoFinal, MSGBOX_AUTOCLOSE
	end

NewSinjoh_KimonoHideout_Text_ShizukoFinal:
	.string "静子：在神都漫长的历史长河中，鲜\n"
	.string "有训练家能达成你这样的壮举。\p"
	.string "真是令人赞叹，{PLAYER}。$"

@ =================================================================================================

NewSinjoh_KimonoHideout_EventScript_OldMan::
	msgbox NewSinjoh_KimonoHideout_Text_OldMan, MSGBOX_NPC
	end

NewSinjoh_KimonoHideout_Text_OldMan:
    .string "舞姬们从建村之初就一直守护着我们\n"
    .string "的村落。\p"
    .string "她们付出了很多牺牲。\p"
    .string "受到神明眷顾的她们，所拥有的力量\n"
    .string "远超普通训练家！\p"
    .string "也就是说，年轻人，如果要和她们交\n"
    .string "手，一定要做好万全准备。$"

NewSinjoh_KimonoHideout_Text_OldManAfter:
    .string "你竟然击败了我们村子的守护者。\p"
    .string "年轻人，你究竟是何方神圣？$"
