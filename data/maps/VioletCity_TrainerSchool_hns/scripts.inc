VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "我虽然不是玩GBA长大的那一辈，\n"
	.string "但我超级喜欢玩宝可梦游戏！\p"
	.string "在过去的老游戏里，你得跟大量的野\n"
	.string "生宝可梦对战才能攒够经验值。\p"
	.string "而在较新的游戏里，学习装置又会让\n"
	.string "宝可梦升级得太快。\p"
	.string "在这个游戏里，学习装置经过了平衡\n"
	.string "调整，能让你的宝可梦刚好保持在合\l"
	.string "适的等级，或者稍微高一点，取决于\l"
	.string "你打了多少场对战。\p"
	.string "如果你想要传统的第1至4世代体\n"
	.string "验，可以关掉学习装置。如果你想要\l"
	.string "现代的游玩体验，那就开启学习装\l"
	.string "置。\p"
	.string "怎么玩完全由你来决定！$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "杜利，是在下！\p"
	.string "绝妙无比，宝可梦正是！\p"
	.string "传授于你，让你成为更优秀的训练\n"
	.string "家！$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "有些宝可梦刚开始很弱小，而且需要\n"
	.string "比其他宝可梦多得多的经验值才能变\l"
	.string "强。\p"
	.string "比如幼基拉斯虽然十分弱小，但耗费\n"
	.string "大量经验值培育后，最终会蜕变为强\l"
	.string "大的班基拉斯。\p"
	.string "只有最有毅力的训练家，才能坚持培\n"
	.string "育这样的宝可梦。$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "甚好！传授于你，在下会！\p"
	.string "在对战中，队伍最上方的宝可梦会最\n"
	.string "先登场！\p"
	.string "调换队伍顺序，对战变得轻松，也许\n"
	.string "就会！\p"
	.string "还想听在下，继续讲吗？$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "那么，想知道如何好好培育宝可梦\n"
	.string "吗？$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "好！我来教你！\p"
	.string "就算只让宝可梦在对战中露面，也能\n"
	.string "获得\p"
	.string "经验值。把弱小的宝可梦放在队伍最\n"
	.string "前面！\p"
	.string "对战时马上换下它！这样一来，它就\n"
	.string "会渐渐\p"
	.string "变强！$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "哦！聪明的学生，正是你！在下已经\n"
	.string "没什么可教的了！\p"
	.string "若是还想了解，不妨去问问那些学生\n"
	.string "们！$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "以前以为必须通信交换才能进化的宝\n"
	.string "可梦，\p"
	.string "现在升级也能进化了。豪力和隆隆石\p"
	.string "在38级进化，勇基拉和鬼斯通则在\n"
	.string "42级进化。\p"
	.string "有些宝可梦还能携带金属膜等道具，\p"
	.string "通过升级来进化。$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "在地图各处可以直接看到该区域出没\n"
	.string "的代表性宝可梦！\p"
	.string "不过别忘了在白天和夜晚分别去各个\n"
	.string "道路查看哦！$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "城都地区的树果非常适合用来治疗和\n"
	.string "制作精灵球。\p"
	.string "而关都地区的树果则适合用来降低宝\n"
	.string "可梦的基础点数。\p"
	.string "关都的道场还能帮助宝可梦将各项个\n"
	.string "体值提升到完美。$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "请留意，如今对手们的队伍属性打击\n"
	.string "面都更加全面了，因此接下来的旅途\l"
	.string "将会极具挑战性。$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "黑板上写着关于宝可梦秘传招式的说\n"
	.string "明。\p"
	.string "秘传招式一旦解锁，不需要让宝可梦\n"
	.string "学会就能直接使用。$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "这是这个孩子的笔记本……\p"
	.string "使用精灵球来捕捉宝可梦。\p"
	.string "同行宝可梦最多可以携带6只。\p"
	.string "要继续阅读吗？$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "在投掷精灵球之前，要先削弱目标的\n"
	.string "体力。\p"
	.string "陷入中毒或灼伤状态的宝可梦会更容\n"
	.string "易捕捉。\p"
	.string "要继续阅读吗？$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "有些招式可能会导致混乱。\p"
	.string "处于混乱状态的宝可梦可能会攻击自\n"
	.string "己。\p"
	.string "只要脱离战斗就能解除混乱状态。\p"
	.string "要继续阅读吗？$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "捕捉宝可梦并带着它们对战的人，被\n"
	.string "称为宝可梦训练家。\p"
	.string "他们的目标通常是巡回各个宝可梦道\n"
	.string "馆，击败各地的训练家。\p"
	.string "下一页是……一片空白！\p"
	.string "男孩：嘿嘿嘿……\p"
	.string "后面的我还没写呢……$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "这台超级机器可以把数据打印成贴\n"
	.string "纸！$"
