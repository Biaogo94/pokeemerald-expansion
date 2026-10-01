RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "唉，天天这样太难了……\p"
	.string "什么难？还用问吗？\p"
	.string "当然是考虑一天三餐该吃什么。\p"
	.string "每天都想着做什么饭也不容易。$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "哎，你好！欢迎来到箱神家。\p"
	.string "问你一个问题，你带过小孩吗？\p"
	.string "你看，我刚当上爸爸，抚养孩子什么\n"
	.string "的都得从头学。\p"
	.string "我现在有点麻烦，女儿文乃总是不爱\n"
	.string "笑。\p"
	.string "我想如果给她讲笑话她就会笑起来\n"
	.string "的。\p"
	.string "你知道什么有趣的故事或短语吗？$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "我最近试过说\n"
	.string "“{STR_VAR_1}”逗她笑，\p"
	.string "你还知道什么更好点的短语吗？$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "哎，不错，那就听你的，说给她听听\n"
	.string "吧。$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "唉，是吗？\p"
	.string "如果你想到什么好主意，我洗耳恭\n"
	.string "听。$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "啊，知道了。来试试吧？$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_1}\p"
	.string "啊，太好了，她笑了！啊，我也跟她\n"
	.string "一样开心！$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "啊，知道了。来试试吧？$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_1}\p"
	.string "唔……她根本不笑。也许文乃生来就很\n"
	.string "严肃……$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "唉，你也不知道什么好短语啊。那我\n"
	.string "只能自己想一个了。\p"
	.string "嗯……“{STR_VAR_1}”怎么\n"
	.string "样？我们试试看。$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_1}\p"
	.string "唔……她根本不笑。也许文乃生来就很\n"
	.string "严肃……$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "唉，你也不知道什么好短语啊。看来\n"
	.string "我只能用上次的短语逗她笑了。\p"
	.string "对了，如果你想到了什么，要赶快告\n"
	.string "诉我，好吗？$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "谢谢！\p"
	.string "多亏了你，我亲爱的文乃开始笑了！\p"
	.string "实际上，虽然我看起来很普通，但我\n"
	.string "是得文公司的主力研究员之一。\p"
	.string "我该做点什么报答你？\p"
	.string "对了，我给你的电脑宝可梦寄放系统\n"
	.string "里的盒子加些新的背景图片吧。\p"
	.string "在选择背景图案的菜单中选择“朋友"
	.string "”，\p"
	.string "就能连接到新的背景图片。$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "是宝可梦毛绒玩具！$"

