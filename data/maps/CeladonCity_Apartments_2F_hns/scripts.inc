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
	.string "我们正致力于在\n"
	.string "pokeemerald\l"
	.string "expansion项目中\l"
	.string "重构这款游戏！$"

CeladonMansion2F_Text_TixoRebel:
	.string "你听说过“蛋化危机”吗？那是测试\n"
	.string "阶段的一个漏洞，会随机把宝可梦变\l"
	.string "成蛋！\p"
	.string "修复这个漏洞的补丁就是我写的！$"

CeladonMansion2F_Text_Phant:
	.string "我最喜欢降级移植版了！\p"
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
	.string "嗨！\p"
	.string "我挺擅长找BUG的，也能修点小毛\n"
	.string "病。\p"
	.string "想听个笑话吗？\p"
	.string "阿渡想教快龙学会“龙息”招式。\p"
	.string "可是快龙使出“神速”跑得太快，根\n"
	.string "本接不上这口气(学不会)！$"
