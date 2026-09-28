CianwoodGym_hns_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "湛蓝市宝可梦道馆$"

CianwoodGym_Text_GymStatueCertified:
	.string "湛蓝市宝可梦道馆\p"
	.string "阿四所认可的训练家：\n"
	.string "{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "哇哈哈哈哈，{PLAYER}！我\n"
	.string "正在特训中呢！\p"
	.string "如果还想和我对战，就来金黄市的格\n"
	.string "斗道场吧！$"

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "我们在道场见吧！哇哈哈哈哈哈哈！$"

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "哇哈哈哈！\p"
	.string "你竟然闯到了这里！\p"
	.string "实话告诉你，我可是很强硬的！\p"
	.string "我的宝可梦不仅能粉碎岩石，还能击\n"
	.string "碎骨头！\p"
	.string "看招！$"

CianwoodGym_Text_ChuckIntro2:
	.string "阿四：呃啊啊！......\p"
	.string "喔嗷嗷啊！$"

CianwoodGym_Text_ChuckIntro3:
	.string "怎么样！吓到了吧？\p"
	.string "什么？这跟宝可梦毫无关系？\p"
	.string "说得也是！\p"
	.string "放马过来吧，我们来对战！$"

CianwoodGym_Text_ChuckLoss:
	.string "什么？咦？我输了？\p"
	.string "真了不起！你配得上打击徽章！$"

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER}获得了打击徽章。$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "拥有打击徽章，等级70以内的宝可\n"
	.string "梦包括交换来的都会听你的话。\p"
	.string "而且在战斗外也可以让宝可梦使用\n"
	.string "“飞翔”招式了。\p"
	.string "来，把这个也收下吧！$"

CianwoodGym_Text_ChuckTMSpeech:
	.string "那是“真气拳”。\p"
	.string "虽然出手慢，但威力巨大。关键是千\n"
	.string "万别在出招前被打中！$"

CianwoodGym_Text_ChuckAfter:
	.string "哇哈哈哈！和你对战真是痛快！\p"
	.string "不过输了就是输了！\p"
	.string "从现在起，我要进行一天24小时不\n"
	.string "间断的特训！$"

CianwoodGym_Text_ChuckRematch:
	.string "哇哈哈哈！城都的冠军！\p"
	.string "你又来找我挑战了吗！\p"
	.string "看得出你的身手更上一层楼了！\p"
	.string "准备好看看谁更强了吗？$"

CianwoodGym_Text_ChuckRematchDefeat:
	.string "什么？咦？我又输了？又输了？！$"

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI_HNS, CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "我和我的宝可梦被友谊紧密相连。\p"
	.string "我们的羁绊绝不会被斩断！$"

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "这不是真的！$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "看来你和你的宝可梦之间也有着深厚\n"
	.string "的羁绊啊！$"

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_HNS, CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "我们武道家无所畏惧！$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "太令人震惊了！$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "格斗属性宝可梦很怕超能力....\n"
	.string "..$"


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_HNS, CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "多说无益。用你的拳头来说话吧！$"

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "我输了！简直无话可说！$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG_HNS, CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "看我愤怒的铁拳粉碎你的宝可梦！$"

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "被粉碎的居然是我？！$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "我的宝可梦输了......我..\n"
	.string "....我的自尊心全碎了....\l"
	.string "..$"

