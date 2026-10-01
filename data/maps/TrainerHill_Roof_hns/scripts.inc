TrainerHill_Roof_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Roof_hns_OnLoad
	.byte 0

TrainerHill_Roof_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

TrainerHill_Roof_hns_EventScript_Owner::
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_Arrived
	case 1, TrainerHill_Roof_hns_EventScript_GivePrize
	case 2, TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_hns_EventScript_Arrived::
	msgbox TrainerHill_Roof_hns_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_hns_EventScript_GivePrize::
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_hns_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_hns_EventScript_CheckFinalTime
TrainerHill_Roof_hns_EventScript_ReceivePrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_NoRoomForPrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_CheckFinalTime::
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_NewRecord
	case 1, TrainerHill_Roof_hns_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
TrainerHill_Roof_hns_EventScript_NewRecord::
	msgbox TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_NoNewRecord::
	msgbox TrainerHill_Roof_hns_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_EndSpeakToOwner::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_Text_YouFinallyCameBravo:
	.string "嗯！嗯！\p"
	.string "你终于来了！没错，你到了！\p"
	.string "等等！别说！我知道你一个人千里迢\n"
	.string "迢跑到这里来是为了什么！\p"
	.string "你想见我，训练家之丘的主人，是因\n"
	.string "为……\p"
	.string "你想和我组队双打对吧！哇呼--！\p"
	.string "……咦？不是吗？\p"
	.string "不管怎样，你一路打上来的英姿我都\n"
	.string "看到了。真是精彩绝伦的对战！太棒\l"
	.string "了！$"

TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift:
	.string "献给如此出色的你，我准备了一份极\n"
	.string "其绝妙的礼物，另外还有一些奖金作\l"
	.string "为酬谢！$"

TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis:
	.string "哎呀，你的背包已经装得满满当当\n"
	.string "了！等整理好了再来拿吧！$"

TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly:
	.string "哎呀，等等！难道你用极快的速度赶\n"
	.string "到这里了吗？\p"
	.string "太精彩了！其实您完全不用为了见我\n"
	.string "而这么匆忙的！\p"
	.string "真是太令人高兴了。我会让前台更新\n"
	.string "计时板上的成绩！$"

TrainerHill_Roof_hns_Text_YouWerentVeryQuick:
	.string "不过，哎呀……你赶到这里的时间并不\n"
	.string "算快呢。$"

TrainerHill_Roof_hns_Text_ArriveZippierNextTime:
	.string "要是你下次能来得更快些，我想我会\n"
	.string "更加开心的。\p"
	.string "到那时，我很乐意与你组成双打拍\n"
	.string "档！\p"
	.string "期待下次再会，朋友！$"
