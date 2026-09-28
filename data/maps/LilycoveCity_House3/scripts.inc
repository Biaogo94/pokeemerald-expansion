LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "哎呀呀！你一个人在旅行吗？年纪轻\n"
	.string "轻真了不起！好样的！\p"
	.string "我家那几个孩子真该向你好好学学！\p"
	.string "我？我可是个\n"
	.string "{POKEBLOCK}达人。\p"
	.string "只要我稍微认真一点，就能调配出绝\n"
	.string "妙的{POKEBLOCK}哦。\p"
	.string "要不要向我这个\n"
	.string "{POKEBLOCK}达人讨教两\l"
	.string "招呀？$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "哦？是吗？\p"
	.string "不要总是试图独自面对一切，亲爱的\n"
	.string "！$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "哎呀，太好了！你真机灵！话有点长\n"
	.string "，可要听仔细咯！\p"
	.string "准备好了吗？\p"
	.string "查看{POKEBLOCK}时，你\n"
	.string "应该能看到上面标有光滑度。\p"
	.string "光滑度数值越低，品质就越好。可千\n"
	.string "万别忘了这点！\p"
	.string "优秀的{POKEBLOCK}，光\n"
	.string "滑度低，而等级高。\p"
	.string "而且相比普通的，宝可梦能吃下更多\n"
	.string "优秀的{POKEBLOCK}。\p"
	.string "接下来这句很关键。\p"
	.string "如果你想做出更细腻的\n"
	.string "{POKEBLOCK}，就要使用\l"
	.string "不同种类的树果。\p"
	.string "可别舍不得--树果的种类会直接影\n"
	.string "响{POKEBLOCK}的光滑度\l"
	.string "。\p"
	.string "还有一件事。\p"
	.string "一起混合树果的人越多，做出来的\n"
	.string "{POKEBLOCK}就越细腻。\p"
	.string "所以呀，去多找其他人聊聊，大家一\n"
	.string "起制作{POKEBLOCK}吧。\p"
	.string "制作优质{POKEBLOCK}的\n"
	.string "诀窍，差不多就这些啦。\p"
	.string "如果大家都有心爱的宝可梦、细腻的\n"
	.string "{POKEBLOCK}和温馨的家\l"
	.string "庭，这个世界一定会变得更加幸福吧\l"
	.string "。\p"
	.string "加油哦，孩子！$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "妻子生下四胞胎的时候，我真的吓了\n"
	.string "一跳。\p"
	.string "但现在看着他们一起玩耍，我觉得很\n"
	.string "幸福。$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "我们在进行多人对战，我肯定会赢的\n"
	.string "。$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "我们喜欢在记录角进行混合了，\p"
	.string "不过到底混合的是什么呢？$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "我们要用树果混合器做出超棒的\n"
	.string "{POKEBLOCK}！$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "我要让大家看看我的宝可梦有多强壮\n"
	.string "，所以我们打算一起参加华丽大赛。$"

