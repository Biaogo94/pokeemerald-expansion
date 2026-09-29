Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN_HNS, Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT_HNS, Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten, Route43_EventScript_RegisterBrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchBrent
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterBrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_BrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRENT_HNS
	release
	end

Route43_EventScript_RematchBrent::
	trainerbattle_rematch TRAINER_BRENT_HNS, Route43_Text_BrentRematchIntro, Route43_Text_BrentRematchDefeat
	msgbox Route43_Text_BrentPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON_HNS, Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN_HNS, Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER_HNS, Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY_HNS, Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten, Route43_EventScript_RegisterTiffany
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchTiffany
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterTiffany::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_TiffanyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIFFANY_HNS
	release
	end

Route43_EventScript_RematchTiffany::
	trainerbattle_rematch TRAINER_TIFFANY_HNS, Route43_Text_TiffanyRematchIntro, Route43_Text_TiffanyRematchDefeat
	msgbox Route43_Text_TiffanyPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
    .string "我最喜欢宝可梦了！\p"
    .string "正因如此我才开始收集，而且以后也\n"
    .string "会一直收集下去！$"

Route43_Text_PokemaniacBenBeaten:
    .string "你怎么能这样对我？！$"

Route43_Text_PokemaniacBenAfter:
    .string "除了宝可梦我还喜欢什么？\p"
    .string "当然是收音机里的玛丽啦。她一定超\n"
    .string "级可爱！$"

Route43_Text_PokemaniacBrentSeen:
    .string "嘿！你有稀有的宝可梦吗？$"

Route43_Text_PokemaniacBrentBeaten:
    .string "噢，我可怜的宝可梦！宝贝们！$"

Route43_Text_PokemaniacBrentAfter:
    .string "哪怕只要有一只稀有的宝可梦，我就\n"
    .string "心满意足了。$"

Route43_Text_BrentRegister:
    .string "哪怕只要有一只稀有的宝可梦，我就\n"
    .string "心满意足了。$"

Route43_Text_BrentRematchIntro:
    .string "嘿！你有稀有的宝可梦吗？$"

Route43_Text_BrentRematchDefeat:
    .string "噢，我可怜的宝可梦！宝贝们！$"

Route43_Text_BrentPostRematch:
    .string "哪怕只要有一只稀有的宝可梦，我就\n"
    .string "心满意足了。$"

Route43_Text_PokemaniacRonSeen:
    .string "你能相信吗？\p"
    .string "有个叫{RIVAL}的家伙居然嘲\n"
    .string "笑我的宝可梦！\p"
    .string "可恶！我的宝可梦明明很棒！$"

Route43_Text_PokemaniacRonBeaten:
    .string "我的尼多王表现得棒极了！$"

Route43_Text_PokemaniacRonAfter:
    .string "每个人喜欢不同类型的宝可梦，这本\n"
    .string "来就很正常。\p"
    .string "宝可梦可不仅仅是看谁最厉害而已。$"

Route43_Text_FisherMarvinSeen:
    .string "我最近状态低迷。\p"
    .string "也许是钓具的问题吧。\p"
    .string "来对战一场换换心情吧！$"

Route43_Text_FisherMarvinBeaten:
    .string "虽然输了，但我感觉心情好多啦。$"

Route43_Text_FisherMarvinAfter:
    .string "钢铁先生制作的诱饵球最适合用来捕\n"
    .string "捉钓上来的宝可梦了。\p"
    .string "它比高级球还要有效得多呢。$"

Route43_Text_CamperSpencerSeen:
    .string "我和我的宝可梦能一起做好多事--\n"
    .string "真是太开心啦！$"

Route43_Text_CamperSpencerBeaten:
    .string "输掉可一点都不好玩……$"

Route43_Text_CamperSpencerAfter:
    .string "愤怒之湖到底出什么事了？\p"
    .string "我们本来还打算在那儿露营呢。$"

Route43_Text_PicnickerTiffanySeen:
    .string "你也是要去愤怒之湖吗？\p"
    .string "先来陪我玩一会儿吧！$"

Route43_Text_PicnickerTiffanyBeaten:
    .string "玩得太过火啦！$"

Route43_Text_PicnickerTiffanyWantsPicnic:
    .string "我正和宝可梦野餐呢。\p"
    .string "你要不要也加入我们？$"

Route43_Text_TiffanyRegister:
    .string "我正和宝可梦野餐呢。\p"
    .string "你要不要也加入我们？$"

Route43_Text_TiffanyRematchIntro:
    .string "你也是要去愤怒之湖吗？\p"
    .string "先来陪我玩一会儿吧！$"

Route43_Text_TiffanyRematchDefeat:
    .string "玩得太过火啦！$"

Route43_Text_TiffanyPostRematch:
    .string "我正和宝可梦野餐呢。\p"
    .string "你要不要也加入我们？$"

Route43_Sign1:
    .string "43号道路\p"
    .string "愤怒之湖 - 卡吉镇$"

Route43_Sign2:
    .string "43号道路\p"
    .string "愤怒之湖 - 卡吉镇$"

Route43_TrainerTips:
    .string "宝可梦指南\p"
    .string "所有宝可梦的属性不同，各有优缺\n"
    .string "点。\p"
    .string "如果属性被克制，即使是等级高的宝\n"
    .string "可梦也可能会在对战中落败。\p"
    .string "熟记与自己的宝可梦属性相生相克的\n"
    .string "克制关系吧！$"
