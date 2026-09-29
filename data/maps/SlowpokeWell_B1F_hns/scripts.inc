SlowpokeWell_B1F_hns_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "钢铁：哎呀，{PLAYER}！\p"
	.string "我在上面吼了一嗓子，看守的家伙就\n"
	.string "逃跑了。\p"
	.string "可是我一不留神摔进了井里。\p"
	.string "把腰给狠狠摔到了，现在动弹不得。\p"
	.string "可恶！如果我的腰没事，我的宝可梦\n"
	.string "早就把他们揍扁了……\p"
	.string "唉，真拿它没办法。\p"
	.string "{PLAYER}，替我好好教训他\n"
	.string "们，让他们见识一下你的骨气！$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "钢铁：干得漂亮，\n"
	.string "{PLAYER}！\p"
	.string "火箭队全都逃跑了。\p"
	.string "我的腰也好多了。我们赶紧离开这里\n"
	.string "吧。$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "可恶！我本来在上面看守，结果一个\n"
	.string "怪老头冲着我大吼大叫。\p"
	.string "吓得我一失足摔到了这里。\p"
	.string "看来我只能把这股火气撒在你的身上\n"
	.string "了！$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "啊啊啊！今天真是不走运！$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "没错，我们砍下呆呆兽的尾巴拿去\n"
	.string "卖。\p"
	.string "我们做什么都是为了赚钱！\p"
	.string "对！我们就是火箭队，为了钱什么都\n"
	.string "干得出来！$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "你想干什么？\p"
	.string "敢来妨碍我们干活，可别指望我们会\n"
	.string "手下留情！$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "今天算你厉害，下次可就没这么走运\n"
	.string "了！$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "没错，火箭队在3年前就解散了。\p"
	.string "老大也隐姓埋名躲了起来。\p"
	.string "但我们一直在地下秘密活动！\p"
	.string "像你这样的小绊脚石，对我们的任务\n"
	.string "根本构不成威胁。\p"
	.string "我劝你最好好好害怕一下接下来要发\n"
	.string "生的事吧！$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "嗬嗬嗬！叫我们别再割呆呆兽之尾？\p"
	.string "你脑子坏掉了吧！要是听了你的话，\n"
	.string "火箭队的名声可就全毁了！$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "嗬……太强了……$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "虽然我们需要钱，但居然沦落到卖呆\n"
	.string "呆兽之尾……\p"
	.string "当个火箭队手下还真不容易啊！$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "不要割尾巴？\p"
	.string "行啊，有本事把我们全都打倒试试看\n"
	.string "！$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "你这个臭小鬼！$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "呆呆兽之尾很快就会长出来的！\p"
	.string "拿来卖又有什么关系嘛！$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "尾巴被割掉的呆呆兽……\p"
	.string "嗯？它携带着邮件。要阅读吗？$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER}读了邮件。\p"
	.string "要乖乖听话，和爷爷还有呆呆兽一起\n"
	.string "看家哦。\p"
	.string "--爱你的爸爸上$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "尾巴被割掉的呆呆兽……$"
