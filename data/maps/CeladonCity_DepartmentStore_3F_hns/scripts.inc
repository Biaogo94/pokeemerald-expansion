CeladonCity_DepartmentStore_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept3_EventScript_Youngster::
	msgbox CeladonDeptStore3F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid1::
	msgbox CeladonDeptStore3F_Text_GameboyKid1, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid2::
	msgbox CeladonDeptStore3F_Text_GameboyKid2, MSGBOX_NPC
	end
CeladonDept3_EventScript_SuperNerd::
	msgbox CeladonDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept3_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonDept3_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeladonDept3_Pokemart:
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_CAPTIVATE
	.2byte ITEM_TM_STEALTH_ROCK
	.2byte ITEM_TM_BRINE
	.2byte ITEM_TM_AVALANCHE
	.2byte ITEM_TM_DARK_PULSE
	.2byte ITEM_TM_GYRO_BALL
	.2byte ITEM_TM_DREAM_EATER
	.2byte ITEM_TM_GIGA_IMPACT
	.2byte ITEM_TM_ENDURE
	pokemartlistend

CeladonDept3_EventScript_Directory::
	msgbox CeladonDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore3F_Text_Youngster:
	.string "真纠结，该把这个招式学习器给哪只\n"
	.string "宝可梦用好呢......$"

CeladonDeptStore3F_Text_GameboyKid1:
	.string "哎呀！我刚才把宝可梦交换出去了，\n"
	.string "忘记把“升级数据”取下来了！$"

CeladonDeptStore3F_Text_GameboyKid2:
	.string "太棒了！我终于拿到多边兽了！\p"
	.string "我不太擅长玩老虎机，以前代币总是\n"
	.string "攒不够......\p"
	.string "......咦？\p"
	.string "换过来的多边兽变成了另一种宝可梦\n"
	.string "！？$"

CeladonDeptStore3F_Text_SuperNerd:
	.string "招式学习器专柜售卖一些罕见的招式\n"
	.string "呢。$"

CeladonDeptStore3F_Text_Directory:
	.string "3F：招式学习器卖场\p"
	.string "让你的宝可梦变得更强！$"

