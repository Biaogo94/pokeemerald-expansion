CianwoodHouse3_hns_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "我、我吓坏了！\p"
	.string "刚才闯进来一个跟你年纪相仿、眼神\n"
	.string "凶狠还留着长头发的家伙。\p"
	.string "他恶狠狠地威胁我，抢走了我珍爱的\n"
	.string "宝可梦！\p"
	.string "我虽然还留有一只，可要是他又折回\n"
	.string "来怎么办？\p"
	.string "你看上去挺厉害的。能不能帮我照看\n"
	.string "一阵子宝可梦？$"

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "太感谢你了！\p"
	.string "请一定要好好待它啊！$"

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER}获得了宝可梦。$"

CianwoodCity_Text_ManiacPartyFull:
	.string "同行的宝可梦已经满了。$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "怎么会这样……要是他又找上门来，我\n"
	.string "该怎么办啊？$"

CianwoodCity_Text_ManiacHowsdoing:
	.string "嗨！我的宝可梦过得还好吗？$"

CianwoodCity_Text_ManiacAskReturn:
	.string "嗨！我的宝可梦过得还好吗？\p"
	.string "我想现在应该安全了，能不能把它还\n"
	.string "给我呢？$"

CianwoodCity_Text_ManiacThankYou:
	.string "太谢谢你了！$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "咦，你身上没有带着我的宝可梦啊。$"

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "我的宝可梦看起来非常喜欢你呢。\p"
	.string "好吧，就由你继续照顾它吧。\p"
	.string "不过一定要答应我，要好好待它哦！$"

CianwoodCity_Text_ManiacRobbed:
	.string "咦，好像哪里有点不对劲。$"

CianwoodCity_Text_ManiacRobbed2:
	.string "呜哇，不要啊……你这样跟明抢有什么\n"
	.string "区别嘛。$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "对宝可梦而言，能和善待自己的人在\n"
	.string "一起才是最大的幸福。$"

CianwoodCity_Text_ManiacLastMon:
	.string "如果我把宝可梦要回来的话，你在对\n"
	.string "战时要用哪只宝可梦啊？$"


CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER}归还了小壶。$"
