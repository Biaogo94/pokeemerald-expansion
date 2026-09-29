LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "欢迎光临！这一层的任何地方您都可\n"
	.string "以随意参观。$"

LavenderTown_RadioStation_Text_Officer:
	.string "很抱歉，这里只能参观一楼。\p"
	.string "自从城都的广播塔被犯罪团伙占领过\n"
	.string "之后，我们就不得不加强安保了。$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "许多人都在这座广播塔里努力工作\n"
	.string "着。\p"
	.string "他们一定是在竭尽全力为大家奉献精\n"
	.string "彩的节目吧。$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "哎呀，不，不，不行啊！\p"
	.string "自从发电厂停摆以来，我们就一直处\n"
	.string "于停播状态。\p"
	.string "要是不能广播，那我辛辛苦苦创办这\n"
	.string "家电台的心血全白费了。\p"
	.string "我可就要破产了！$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "啊！你就是解决了发电厂问题的\n"
	.string "{PLAYER}吗？\p"
	.string "多亏了你，我才保住了饭碗。\p"
	.string "说真的，你可是我的大救星啊！\p"
	.string "请收下这个作为谢礼吧。$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER}获得了扩展卡！$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "有了那个东西，你就能收听关都地区\n"
	.string "的广播节目了。\p"
	.string "嘎哈哈哈哈！$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "嗨，你好呀！\p"
	.string "我就是超级音乐总监！\p"
	.string "咦？你的" @POKéGEAR
	.string "收音机功能，\n收不到我的音乐节目。太遗憾了！\p"
	.string "只要弄到扩展卡，就能收听到了。你\n"
	.string "最好也去弄一张！$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "嗨，你好呀！\p"
	.string "我就是超级音乐总监！\p"
	.string "空中传播的美妙旋律可全都是由我负\n"
	.string "责的哦。\p"
	.string "别太老土啦。快打开收音机，尽情享\n"
	.string "受音乐吧！$"

LavenderTown_RadioStation_Text_Directory:
	.string "1楼 接待处  2楼 营业部\p"
	.string "3楼 人事部  4楼 制作部\p"
	.string "5楼 台长室$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "频道20用宝可梦之笛的悠扬旋律唤\n"
	.string "醒宝可梦吧！$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "哇！架子上摆满了宝可梦的CD和录\n"
	.string "像带。\p"
	.string "这里一定是资料室吧。$"

