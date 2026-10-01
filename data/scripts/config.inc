Debug_FlagsAndVarNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsAndVarNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsAndVarNotSetBattleConfigMessage_Text:
	.string "该功能不可用，请在以下路径定义可\n"
	.string "用的flag或var'include/config/battle.h'!$"
