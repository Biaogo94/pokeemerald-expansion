CeladonCity_Apartments_3F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "是这样吗？\p"
	.string "我是游戏设计师！\p"
	.string "填满宝可梦图鉴可不容易，不过千万\n"
	.string "别放弃！$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "哇！太棒了！你集齐了宝可梦图鉴！\p"
	.string "恭喜你！$"

GameFreak_Text_GraphicArtist:
	.string "我是美术设计师。\p"
	.string "你也是我画出来的哦！$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "我是美工设计师。\p"
	.string "哎呀，你集齐宝可梦图鉴了吗？\p"
	.string "想要我把奖状打印出来吗？$"

GameFreak_Text_GraphicArtistRefused:
	.string "如果想要打印奖状，随时叫我一声。$"

GameFreak_Text_GraphicArtistError:
	.string "好像出问题了。只好取消打印了。$"

GameFreak_Text_Programmer:
	.string "咦，我吗？我是程序员。\p"
	.string "去玩玩老虎机吧！$"

GameFreak_Text_CharacterDesigner:
	.string "那对双胞胎真可爱，对吧？\p"
	.string "阿蜜也很可爱。\p"
	.string "哎呀，我真喜欢她们！$"

CeladonMansion3F_Text_DevRoomSign:
	.string "GAME FREAK 开发室$"

CeladonMansion3F_Text_Drawing:
	.string "这是一张画得很精细的漂亮美少女画\n"
	.string "像。$"

CeladonMansion3F_Text_GameProgram:
	.string "这是游戏的程序代码。乱动的话说不\n"
	.string "定会让游戏出现BUG！$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "堆满了各种参考资料。甚至还有一个\n"
	.string "宝可梦玩偶。$"
