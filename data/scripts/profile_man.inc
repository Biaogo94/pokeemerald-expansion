ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "嘿，训练家！\n"
	.string "你的笑容很灿烂。\p"
	.string "我有个爱好——收集宝可梦训练家\n"
	.string "的个人信息档案。$"

ProfileMan_Text_MayISeeYourProfile:
	.string "怎么样？\n"
	.string "我可以看看你的档案吗？$"

ProfileMan_Text_EasyChatExplanation:
	.string "你可以用4个单词或短语\n"
	.string "组合起来创建自己的个人资料。\p"
	.string "我先在这里给你展示一个\n"
	.string "用4个文本组成的档案的例子。\p"
	.string "你可以把里面的文本换成\n"
	.string "你自己喜欢的文本\l"
	.string "来构成你自己的档案。\p"
	.string "这里有很多的文本可以\n"
	.string "供你选择使用。\p"
	.string "它们根据类型分组排列，\n"
	.string "例如宝可梦，生活方式，或是爱好，\l"
	.string "以便你查找。\p"
	.string "所以你可以先选择分组\n"
	.string "来显示其中的文本选项。\p"
	.string "然后再从中选出你要的文本。\p"
	.string "如此反复选择好所有文本，这样\n"
	.string "你就拥有一个你自己的个人档案了。$"

ProfileMan_Text_LetsSeeItThen:
	.string "好的！谢谢！\n"
	.string "那么，我们来看看吧。$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "哦，真的不要吗？\p"
	.string "我认为像你这样的人\n"
	.string "个人档案肯定会很棒……$"

ProfileMan_Text_NotIntoItRightNow:
	.string "啊？你现在还不想编辑？\p"
	.string "好吧，那随时来找我！$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "你好呀，训练家！\n"
	.string "你的笑容很灿烂。$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "我能看看你的新档案吗？$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "好的！谢谢！\p"
	.string "我希望这份档案比之前\n"
	.string "那份还要更好。$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "啊，你喜欢现在的个人档案呀。\p"
	.string "不怪你——现在的个人档案\n"
	.string "已经非常棒了。$"

ProfileMan_Text_FantasticProfile:
	.string "太，太棒了！\p"
	.string "你的档案，太棒了！\n"
	.string "它完美地展现了你的个性。\p"
	.string "任何看到这份档案的人\n"
	.string "都会被你迷住的！\p"
	.string "谢谢！$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "哦？\n"
	.string "你明白这句话的含义了！\p"
	.string "你现在是神秘事件\n"
	.string "俱乐部的一员了！$"
