Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "我哥哥是化石迷……他是喜欢化石的\n"
	.string "好人……\p"
	.string "他也喜欢挖洞……这个洞是他自己挖\n"
	.string "的……\p"
	.string "给你这个，你也可以挖洞就像我哥哥\n"
	.string "一样……$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "如果让你的宝可梦在山洞里挖洞你就\n"
	.string "会回到洞的入口……$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "不同形状的石头在这里展示……$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "地层的组成……雨后大陆的形状……\n"
	.string "石头，土壤，还有岩石是怎样的……\p"
	.string "这些全塞满了书。$"

