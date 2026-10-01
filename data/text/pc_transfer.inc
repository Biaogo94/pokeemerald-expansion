gText_PkmnTransferredSomeonesPC::
	.string "已将{STR_VAR_2}传送到\n"
	.string "某人的电脑上，\p"
	.string "位于盒子“{STR_VAR_1}”\n"
	.string "里。$"

gText_PkmnTransferredLanettesPC::
	.string "已将{STR_VAR_2}传送到"
#if IS_FRLG || IS_HNS
	.string "正辉的电脑上，\p"
#else
	.string "真由美的电脑上，\p"
#endif
	.string "位于盒子“\n"
	.string "{STR_VAR_1}”里。“$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "某人的电脑上的盒子\n"
	.string "“{STR_VAR_3}”已满，\p"
	.string "{STR_VAR_2}传送到盒子\n"
	.string "“{STR_VAR_1}”里。$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "盒子“{STR_VAR_3}”("
#if IS_FRLG || IS_HNS
	.string "正辉的电脑)已经满了。\p"
#else
	.string "真由美的电脑)已经满了。\p"
#endif
	.string "{STR_VAR_2}被传送到了\n"
	.string "盒子“{STR_VAR_1}”。$"

gText_PkmnSentToPCAfterCatch::
	.string "已将{STR_VAR_2}传送到\n"
	.string "{B_PC_CREATOR_NAME}\l"
	.string "的电脑上。\p"
	.string "位于盒子“{STR_VAR_1}”\n"
	.string "里。$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER}获得了\n"
	.string "{STR_VAR_1}！$"

gText_NoMoreRoomForPokemon::
	.string "没有寄存宝可梦的空间了！\p"
	.string "所有宝可梦盒子都已放满，无法容纳\n"
	.string "新的宝可梦！$"

gText_NicknameThisPokemon::
	.string "要给{STR_VAR_1}起昵称\n"
	.string "吗？$"
