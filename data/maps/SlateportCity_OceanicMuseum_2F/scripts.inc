SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_PARTS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "嗯，你找楠木吗？我就是。\p"
	.string "啊！那就是我向得文的兹伏奇社长订\n"
	.string "购的部件吧？\p"
	.string "非常感谢！这样我们就能开始为勘探\n"
	.string "做准备了。$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "嘿嘿嘿，别急！那些部件归我们了！$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "楠木馆长：什——什么？你们是什么\n"
	.string "人？$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "我们是海洋队！\p"
	.string "我们老大想要那些部件！闭上嘴，乖\n"
	.string "乖把东西交出来！$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "啊啊！竟然被小孩打败了！$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "完了，惨了……老大会大发雷霆的……$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "哼，没用的家伙！放着我来！$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "什么？！连我也输了！$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "这下怎么办？要是不拿到部件，我们\n"
	.string "可就麻烦大了！\p"
	.string "可恶，想不到会栽在多管闲事的小鬼\n"
	.string "手里！$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "我来看看你们抢个部件怎么能磨蹭那\n"
	.string "么久——结果你们几个废物被个小鬼头\l"
	.string "给拦住了？$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "我们是热爱大海的海洋队！\p"
	.string "而我就是海洋队的首领水梧桐！\p"
	.string "你为什么妨碍我们？\p"
	.string "……难，难道说！你是熔岩队的人？\p"
	.string "等等，不对，你穿得和他们不一样。\p"
	.string "…… …… ……\n"
	.string "…… …… ……\p"
	.string "宝可梦、人类……所有的生命都源自海\n"
	.string "洋，\p"
	.string "因此我们海洋队致力于扩张海洋。\p"
	.string "你不觉得吗？我们在进行着一项崇高\n"
	.string "的事业。\p"
	.string "算了……以你这个年纪还没法理解我们\n"
	.string "的伟大理想。\p"
	.string "但我警告你，如果敢再妨碍我们的计\n"
	.string "划，\p"
	.string "我决不会轻易放过你！\p"
	.string "给我好好记住！$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "楠木馆长：你是……啊，对了，你是\n"
	.string "{PLAYER}{KUN}……\p"
	.string "刚才真是千钧一发！多亏你救了我！\p"
	.string "噢，对了，我差点忘了你还带着得文\n"
	.string "送来的零件！$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "楠木馆长：糟糕！没时间耽搁了！\p"
	.string "我们得赶快开始我们的海底勘探了。\p"
	.string "再次谢谢你，不过我得先失陪了！\p"
	.string "随便参观一下我们的展品吧。$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "我在这儿看到了一艘模型船，\p"
	.string "这让我想起了武斗镇附近的那艘被遗\n"
	.string "弃的海船……$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "别在博物馆里面到处乱跑！$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "哇，潜水艇真棒！我也想进里面看一\n"
	.string "看！$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "牌子上写着“水质样本 1”。\p"
	.string "海洋是连成一片的，但不同地域的海\n"
	.string "水并不相同。$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "牌子上写着“水质样本 2”。\p"
	.string "不同地域的海水含盐量也不同吗？$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "一个橡皮球不断地收缩，扩张。\p"
	.string "“在大海中，水由于自身重量形成内\n"
	.string "部的压力。\p"
	.string "浅水中这一压力并不明显，\p"
	.string "但在非常深的水里，一小片地方的水\n"
	.string "压甚至可以达到上万吨。”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“丰缘地区模型”\p"
	.string "是丰缘地区的微缩景观。\p"
	.string "未白镇在哪儿呢？$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "海水循环的演示。\p"
	.string "“在海地附近，海水由于温度和含盐\n"
	.string "量的不同，形成了环流。”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "海水循环的演示。\p"
	.string "“在洋面上，海水被风吹动，形成洋\n"
	.string "流。”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“正在楠木造船厂建造的\p"
	.string "破浪号渡轮的等比例模型。”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“潜艇海渊1号\p"
	.string "洋底勘探用高级潜水艇的模型。”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“潜水者\p"
	.string "海底勘探用的坚固的无人探测器的模\n"
	.string "型。”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“环游世界的\p"
	.string "豪华定期船圣特安努号的模型。”$"
