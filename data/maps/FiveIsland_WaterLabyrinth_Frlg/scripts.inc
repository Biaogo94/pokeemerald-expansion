FiveIsland_WaterLabyrinth_Frlg_MapScripts::
	.byte 0

FiveIsland_WaterLabyrinth_EventScript_EggGentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg
	msgbox FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons
	specialvar VAR_RESULT, GetLeadMonFriendship
	goto_if_eq VAR_RESULT, 6, FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship
	msgbox FiveIsland_WaterLabyrinth_Text_HmmISeeIsee
	release
	end

FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment::
	famechecker FAMECHECKER_DAISY, 2
	msgbox FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy
	release
	end

FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship::
	msgbox FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg
	setflag FLAG_GOT_TOGEPI_EGG
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	call EventScript_RestorePrevTextColor
	goto FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
FiveIsland_WaterLabyrinth_EventScript_PostEggComment::
	bufferspeciesname STR_VAR_2, SPECIES_TOGEPI
	setvar VAR_0x8004, SPECIES_TOGEPI
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	bufferspeciesname STR_VAR_2, SPECIES_TOGETIC
	setvar VAR_0x8004, SPECIES_TOGETIC
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	msgbox FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou
	release
	end

FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
	msgbox FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty
	release
	end

FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg::
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons::
	.string "你在各地旅行，是吗？\p"
	.string "你没有对你的宝可梦太严厉吧？\p"
	.string "让我瞧一瞧。……………………$"

FiveIsland_WaterLabyrinth_Text_HmmISeeIsee::
	.string "啊，嗯……我看到了，我明白了……$"

FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis::
	.string "噢，太感人了。你的宝可梦被照顾的\n"
	.string "很周到。\p"
	.string "我想我能委托你做这件事了。\p"
	.string "拜托了，请收下这个。$"

FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan::
	.string "{PLAYER}从这个人手里得到\n"
	.string "了一个蛋！$"

FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty::
	.string "很不幸，你的队伍已经满了。\p"
	.string "你最好再找个时间回来拿它吧。$"

@ Unused
FiveIsland_WaterLabyrinth_Text_YouveComeBackForTheEgg::
	.string "やあタマゴを　もらいにきて　くれ\n"
	.string "たんだね$"

FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
	.string "我旅行的时候得到了那个蛋。\p"
	.string "我很高兴遇到了你这样的人。$"

FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy::
	.string "噢，你好。真是可爱的\n"
	.string "{STR_VAR_2}。\p"
	.string "看见它我就想起了我在旅行中遇到的\n"
	.string "一个可爱的女孩。\p"
	.string "她很温柔地照料着宝可梦……她真是一\n"
	.string "个小天使。\p"
	.string "那个小姑娘的名字好像是……她好像叫\n"
	.string "奈奈美。$"

FiveIsland_WaterLabyrinth_Text_AlizeIntro::
	.string "这真是一个培育宝可梦的绝佳环境。$"

FiveIsland_WaterLabyrinth_Text_AlizeDefeat::
	.string "你的宝可梦成长得很出色！$"

FiveIsland_WaterLabyrinth_Text_AlizePostBattle::
	.string "我想你有天赋成为一个很棒的饲育\n"
	.string "家。$"
