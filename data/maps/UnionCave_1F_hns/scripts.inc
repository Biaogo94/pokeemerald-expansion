UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "你正准备前往桧皮镇，是吗？\p"
	.string "让我的宝可梦来试试看，你是否已经\n"
	.string "具备一战的实力吧。$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "哎呀，哎呀，哎呀！$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "好，决定了！\p"
	.string "我的宝可梦不变得更强，我就绝不离\n"
	.string "开这里！$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "我为了寻找宝可梦走遍了各地。\p"
	.string "你也是来寻找宝可梦的吗？\p"
	.string "那咱们就是收集劲敌了！$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "唔呃。我可怜的宝可梦……$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "有时候，能从洞窟深处听到宝可梦的\n"
	.string "叫声呢。$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "哇！吓我一跳！\p"
	.string "真没想到这里还会有人来！$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "哇！我输得彻彻底底啊！$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "我被人哄骗着买了根呆呆兽之尾。\p"
	.string "现在想想那只可怜的宝可梦真惨。$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "超音蝠的超音波老是让我宝可梦混\n"
	.string "乱。\p"
	.string "真是烦死人了！$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "我彻底熄火了！$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "每到周末，就能从洞窟深处听到奇怪\n"
	.string "的叫声呢。$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "如果光线够亮，洞窟就不可怕。\p"
	.string "如果你自身够强，宝可梦就不可怕。$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "闪光！$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "是我的宝可梦身上的火焰照亮了这座\n"
	.string "洞窟。$"
