Route27_House_hns_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "你要带着宝可梦去哪儿？\p"
    .string "宝可梦联盟？\p"
    .string "它们对你够忠诚，能让你获胜吗？\p"
    .string "让我看看……$"

SandstormHouse_Text_LoyalMon:
    .string "啊！你的宝可梦非常信任你呢。\p"
    .string "能见到优秀的训练家真让人高兴。\p"
    .string "来，送你一件旅途的礼物。$"

SandstormHouse_Text_TM37Description:
    .string "招式学习器37是“沙暴”。\p"
    .string "这是个会对对战双方都造成伤害的招\n"
    .string "式。\p"
    .string "只有高水平的训练家才能驾驭它。\p"
    .string "有胆识的话就试试看吧。祝你好运！$"

SandstormHouse_Text_DisloyalMon:
    .string "如果它不能更信任你的话，接下来可\n"
    .string "就难办了。\p"
    .string "信任是维系宝可梦与训练家的纽带。$"


