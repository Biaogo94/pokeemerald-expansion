CeladonCity_Apartments_2F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER}打开了电脑。\p"
	.string "......\p"
	.string "有人正在写一封电子邮件。\p"
	.string "......真希望你能来关都看看\n"
	.string "。\p"
	.string "我想这里的巨大变化一定会让你大吃\n"
	.string "一惊。\p"
	.string "你还会看到许多城都地区没有的宝可\n"
	.string "梦。\p"
	.string "致 制作人\p"
	.string "......$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "心金・魂银 开发室$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "嗨大家好，补丁15--\p"
	.string "抱歉，口误了......\p"
	.string "你好呀，我是游戏总监！\p"
	.string "地图、图块集、脚本以及许多内容都\n"
	.string "是由我制作的。\p"
	.string "但如果没有其他开发者和测试员的帮\n"
	.string "助，我一个人是绝对完成不了的。\p"
	.string "感谢你的游玩！希望你能喜欢《宝可\n"
	.string "梦 心金・魂银》。$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "我们正致力于在 pokeemer\n"
	.string "ald expansion项目中\l"
	.string "重构这款游戏！$"

CeladonMansion2F_Text_TixoRebel:
	.string "Have you heard of THE EGGENING?\n"
	.string "It was a bug from the playtest\l"
	.string "that randomly changed POKéMON into\l"
	.string "EGGs!\p"
	.string "I developed the fix for it!$"

CeladonMansion2F_Text_Phant:
	.string "我最喜欢降级移植版(DEMAKE\n"
	.string ")了！\p"
	.string "你玩过《宝可梦 剑/盾终极增强版\n"
	.string " 英文版》吗？就是我翻译的哦！\p"
	.string "至于下一个降级版，我想做阿罗拉地\n"
	.string "区的！$"

CeladonMansion2F_Text_Exclsior:
	.string "我为每只宝可梦都实装了专属的冲浪\n"
	.string "贴图！\p"
	.string "因为这个项目是开源的，你也可以添\n"
	.string "加属于你自己的功能哦！$"

CeladonMansion2F_Text_DaniRaibow:
	.string "Hi!\p"
	.string "I am pretty good at finding problems,\n"
	.string "and can fix little ones.\p"
    .string "Wanna hear a joke?\p"
    .string "Lance tried to teach DRAGONITE the\n"
    .string "move DRAGON BREATH.\p"
    .string "However, DRAGONITE was moving too\n"
    .string "fast from EXTREMESPEED; it couldn't\l"
    .string "catch it!$"
