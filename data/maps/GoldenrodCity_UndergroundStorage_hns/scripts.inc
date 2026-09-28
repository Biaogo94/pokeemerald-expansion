GoldenrodCity_UndergroundStorage_hns_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19_HNS, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12_HNS, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3_HNS, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
    .string "你怎么闯到这里来的？\p"
    .string "看来没办法了。就由我来把你解决掉\n"
    .string "！$"

RadioTowerBasement_Text_GruntM24Beaten:
    .string "被解决掉的反倒是我......$"

RadioTowerBasement_Text_GruntM24After:
    .string "火箭队会一直坚持下去，等待坂木老\n"
    .string "大的归来。\p"
    .string "为了这个目标，我们不择手段！$"

RadioTowerBasement_Text_GruntM14Seen:
    .string "休想再前进一步！\p"
    .string "面对敌人我绝不会手下留情，哪怕对\n"
    .string "方是个小鬼头！$"

RadioTowerBasement_Text_GruntM14Beaten:
    .string "可恶啊！$"

RadioTowerBasement_Text_GruntM14After:
    .string "我输了......\p"
    .string "坂木老大，请原谅我！$"

RadioTowerBasement_Text_GruntM15Seen:
    .string "嘎哈哈哈！瞧瞧是谁来了！\p"
    .string "准备好了吗？现在的我可是很强的！$"

RadioTowerBasement_Text_GruntM15Beaten:
    .string "嘎哈哈哈！你真厉害！\p"
    .string "虽然加入火箭队只是一份糊口的工\n"
    .string "作，但我看得出来这伤害了很多人。\p"
    .string "算了，我不干了。\p"
    .string "太感谢你了。对不起啦，坂木老大！$"

RadioTowerBasement_Text_GruntM15After:
    .string "嘎哈哈哈！真痛快！我记住你了！$"

RadioTowerBasement_Text_DirectorIntro:
    .string "局长：谁？什么？你是来救我的吗？\p"
    .string "太谢谢你了！\p"
    .string "广播电台！\p"
    .string "那里现在怎么样了？\p"
    .string "已经被火箭队占领了吗？\p"
    .string "给。把这把钥匙卡拿去吧。$"

RadioTowerBasement_Text_DirectorCardKey:
    .string "局长：用那个就能打开3楼的卷帘门\n"
    .string "了。$"

RadioTowerBasement_Text_DirectorAfter:
    .string "拜托你帮帮大家了。\p"
    .string "要是被他们控制了发射台，谁知道会\n"
    .string "干出什么坏事来。\p"
    .string "他们甚至可能用特殊的电波来操纵宝\n"
    .string "可梦！\p"
    .string "我现在只能求助于你了。\p"
    .string "求求你救救广播电台......\p"
    .string "还有全国所有的宝可梦吧！$"
