CeladonCity_Condominiums_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special Special_ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
	.string "我？我是程序员！$"

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
	.string "我是做平面设计的！你就是我画出来\n"
	.string "的哦！$"

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
	.string "我写了这个故事！莉佳很可爱吧？\p"
	.string "我也很喜欢小霞！啊，还有娜姿，我\n"
	.string "很喜欢！$"

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
	.string "程序运行正常吗？\p"
	.string "我是游戏设计师！\p"
	.string "集齐宝可梦图鉴非常困难，但别放弃\n"
	.string "！\p"
	.string "如果你完成了图鉴，就来找我吧！$"

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
	.string "哇噢！棒极了！你完成了宝可梦图鉴\n"
	.string "！祝贺你！……$"

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
	.string "这是游戏程序！弄乱了的话游戏会出\n"
	.string "故障的！$"

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
	.string "有些人是在玩游戏，没在工作！$"

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
	.string "这是脚本！可别偷看结局哦！$"

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
	.string "GAME FREAK开发室$"

