SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "唔……如果这个放这里，那个放那里\n"
	.string "……\p"
	.string "那么这个东西放哪里？那个装置又该\n"
	.string "怎么办？\p"
	.string "啊啊啊！完全理不清头绪！$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "嗯？你好，我是津贺。\p"
	.string "楠木馆长雇我来设计一艘渡轮。\p"
	.string "啊！那个……那是得文的物品吗？\p"
	.string "但是，呃……这样不行……\p"
	.string "楠木馆长出去了，他说有些事要处理\n"
	.string "。\p"
	.string "可以请你帮忙找找楠木馆长，把包裹\n"
	.string "交给他吗？$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "津贺：楠木馆长去哪儿了呢？\p"
	.string "可以请你帮忙找找楠木馆长，把包裹\n"
	.string "交给他吗？$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "津贺：造船是一门艺术。\p"
	.string "很多东西并不是只靠计算就能够知道\n"
	.string "的。\p"
	.string "真希望能向哪位熟悉大海的资深老水\n"
	.string "手请教一下……$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "津贺：嗨！哈奇老人也来帮我们的忙\n"
	.string "了。\p"
	.string "多亏了这位资深老水手，渡轮的组装\n"
	.string "正在顺利进行中。$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "津贺：渡轮终于造好了！\p"
	.string "这崭新的破浪号是工业技术的奇迹！\p"
	.string "但我觉得我们甚至还能做得更好。\p"
	.string "要知道，技术的进步永无止境。$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "哈奇：啊，{PLAYER}\n"
	.string "{KUN}！好久不见！\p"
	.string "自从我遇见了你，我这个老水手又焕\n"
	.string "发青春啦！\p"
	.string "所以我决定来帮津贺造渡轮。\p"
	.string "毕竟你看，渡轮上可以载很多人呢。\p"
	.string "那个津贺也真不简单。\p"
	.string "有他的技术和我的经验，我敢肯定我\n"
	.string "们一定能造出一了不起的船！$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "季节，天气，月亮在天空中的位置…\n"
	.string "…\p"
	.string "这些，还有其他很多东西都会对大海\n"
	.string "产生影响。\p"
	.string "是的！大海就好像生物一样！$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "我很容易晕船，所以我只能到这儿来\n"
	.string "帮忙。$"

