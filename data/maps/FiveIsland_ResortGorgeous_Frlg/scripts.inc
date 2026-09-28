FiveIsland_ResortGorgeous_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
	.byte 0

FiveIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FiveIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

FiveIsland_ResortGorgeous_Text_DaisyIntro::
	.string "用这双手，我要创造我的胜利！$"

FiveIsland_ResortGorgeous_Text_DaisyDefeat::
	.string "真是羞愧死了……我脸红了……$"

FiveIsland_ResortGorgeous_Text_DaisyPostBattle::
	.string "噢，我的涂料管散乱得到处都是！$"

FiveIsland_ResortGorgeous_Text_CelinaIntro::
	.string "不好意思！我正忙着画画。请你别挡\n"
	.string "我的视线！$"

FiveIsland_ResortGorgeous_Text_CelinaDefeat::
	.string "输了……我觉得我出局了……$"

FiveIsland_ResortGorgeous_Text_CelinaPostBattle::
	.string "雪野？请稍微倾斜一下你的头部……\n"
	.string "好了！这就是我想要的姿势！$"

FiveIsland_ResortGorgeous_Text_RaynaIntro::
	.string "唔……这鱼钓的，这儿真不安静……$"

FiveIsland_ResortGorgeous_Text_RaynaDefeat::
	.string "呃……我的感觉，太烦闷了……$"

FiveIsland_ResortGorgeous_Text_RaynaPostBattle::
	.string "天空和海洋……它们都是变幻无常的\n"
	.string "。\p"
	.string "它们的这种特性使得人们很难征服它\n"
	.string "们。$"

FiveIsland_ResortGorgeous_Text_JackiIntro::
	.string "如果你一定要知道，我正打算拜访我\n"
	.string "朋友隐居的地方。$"

FiveIsland_ResortGorgeous_Text_JackiDefeat::
	.string "噢，太强大了。$"

FiveIsland_ResortGorgeous_Text_JackiPostBattle::
	.string "在海边和煦的微风之中，来一场从容\n"
	.string "的战斗真是令人惬意。$"

FiveIsland_ResortGorgeous_Text_GillianIntro::
	.string "我正在想着专门为宝可梦建一个游泳\n"
	.string "池。$"

FiveIsland_ResortGorgeous_Text_GillianDefeat::
	.string "噢，我的天啊！$"

FiveIsland_ResortGorgeous_Text_GillianPostBattle::
	.string "一个游泳池是很好，但是我要说，一\n"
	.string "个日光浴室也许更令人赞叹。$"

FiveIsland_ResortGorgeous_Text_DestinIntro::
	.string "我很擅长跑步。我速度可是很快的！$"

FiveIsland_ResortGorgeous_Text_DestinDefeat::
	.string "哎哟！我撞到东西了！$"

FiveIsland_ResortGorgeous_Text_DestinPostBattle::
	.string "当我迎着风奔跑时，我感觉我能飞起\n"
	.string "来！$"

FiveIsland_ResortGorgeous_Text_TobyIntro::
	.string "我发现这个度假胜地之中这些海上生\n"
	.string "物跟我很合拍。$"

FiveIsland_ResortGorgeous_Text_TobyDefeat::
	.string "这太震惊了！你一定在开玩笑。$"

FiveIsland_ResortGorgeous_Text_TobyPostBattle::
	.string "变得这么严重……多么荒谬啊。$"

FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
	.string "秋穗：谢谢你。\p"
	.string "你可以走了。$"

FiveIsland_ResortGorgeous_Text_SelphysHouse::
	.string "秋穗的家$"

