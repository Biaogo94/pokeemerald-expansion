Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "真由美：哦！{PLAYER}\n"
	.string "{KUN}！\p"
	.string "对不起这里太乱了……当我全神贯注于\n"
	.string "研究时东西就会这样了……\p"
	.string "这很难为情……请帮我保守秘密作为交\n"
	.string "换给你这个。$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "关于宝可梦寄放系统给你一些建议吧\p"
	.string "你只需要整理下盒子就可以分辨出宝\n"
	.string "可梦存在哪。$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "真由美的研究注释。关于盒子的信\n"
	.string "息。\p"
	.string "每个盒子可以保管30只宝可梦。\p"
	.string "每个训练家可以在电脑系统里保管420只\n"
	.string "宝可梦。\p"
	.string "继续阅读吗？$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "标记系统是为了用来使宝可梦更容易\n"
	.string "被管理。\p"
	.string "每个盒子的壁纸和名字都是用来使被\n"
	.string "保管的宝可梦更开心。\p"
	.string "继续阅读吗？$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "当存放宝可梦时，它会被送往你最后\n"
	.string "所使用的盒子里。\p"
	.string "如果那个盒子满了的话宝可梦就会被\n"
	.string "送到下一个盒子。\p"
	.string "也就是说，检查盒子后系统会自动选\n"
	.string "择存放宝可梦的盒子。$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER}合上了笔记本。$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "通过电脑收到了某人发来的信件。\p"
	.string "“…… …… …… ……\p"
	.string "“你的寄放系统比我的更加方便。\p"
	.string "“而且它也有许多容易掌握的因素使\n"
	.string "得更有用有趣。\p"
	.string "“在它的发展中我起到了作用我感到\n"
	.string "很骄傲。\p"
	.string "“希望你会继续做出寄放系统方面的\n"
	.string "研究。\p"
	.string "“来自正辉…… …… …… ……"
	.string "”$"

