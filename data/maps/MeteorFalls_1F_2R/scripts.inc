MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "这里是我们龙使者训练的地方。\p"
	.string "冠军也来过。你看得出这里有什么特\n"
	.string "别吗？$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "呃！没想到你那么强！$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "前方的路还很曲折。\p"
	.string "何时我和我的宝可梦会成为最强？$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "我想更多了解你的力量。把你登记到\n"
	.string "宝可导航里吧。$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "自从上次相遇，我们一直为第一的目\n"
	.string "标而努力训练。\p"
	.string "帮忙见识一下我们成长得有多强大吧\n"
	.string "！$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "呃！没想到你那么强！$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "很显然你和宝可梦一直都在锻炼。\p"
	.string "只要你变强，我也会变得更强！$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "源：我们一直是两人一起战斗的。我\n"
	.string "们对自己充满信心。$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "源：哦，天。我们输了，亲爱的老婆\n"
	.string "。$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "源：我们结婚50年了。\p"
	.string "想想看，我都没有击败过我亲爱的老\n"
	.string "婆。$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "源：多么年轻的训练家！\p"
	.string "想和我们对战吗？想的话就带来更多\n"
	.string "的宝可梦。$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "源：年轻的训练家，如果有机会的话\n"
	.string "，你还会和我们对战吗？$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "初：我们结婚50年了。\p"
	.string "我们作为夫妻的牵绊永远不会解除。$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "初：哦，亲爱的。我们输了，我亲爱\n"
	.string "的老公。$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "初：结婚50年了……\p"
	.string "每当我们吵架，我们都是通过宝可梦\n"
	.string "对战来解决……$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "初：好啦，好啦，你难道不是年轻的\n"
	.string "训练家？\p"
	.string "如果你想和我们对战，就得拿来更多\n"
	.string "的宝可梦。$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "源：我们一直是两人一起战斗的。我\n"
	.string "们对自己充满信心。$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "源：天啊。我们输了，亲爱的老婆。$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "源：结婚50年了……\p"
	.string "仔细想想，我和亲爱的老婆每天都是\n"
	.string "在战斗的……$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "源：多么年轻的训练家！\p"
	.string "想和我们战斗吗？想的话就带来更多\n"
	.string "的宝可梦。$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "初：我们结婚50年了。\p"
	.string "我们一直互相支持我们会让自己变得\n"
	.string "更强。$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "初：哦，亲爱的。我们输了，我亲爱\n"
	.string "的老公。$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "初：结婚50年了……发生过太多事\n"
	.string "。\p"
	.string "我希望我们可以继续一起创造快乐的\n"
	.string "记忆。$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "初：好啦，好啦，你难道不是年轻的\n"
	.string "训练家？\p"
	.string "如果你想和我们战斗，就得拿来更多\n"
	.string "的宝可梦。$"

