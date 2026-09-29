TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "据传说……当宝可梦与人类\n"
	.string "的心灵\p"
	.string "产生共鸣之时，彩虹色的宝可梦便会\n"
	.string "从天而降……\p"
	.string "难道说传说的宝可梦，是在试炼我们\n"
	.string "人类吗？$"

TinTower_1F_Sage2_Text:
	.string "钟之塔被烧毁之时，据说有三只无名\n"
	.string "宝可梦丧生其中。真是场悲剧啊。\p"
	.string "然而……\p"
	.string "一只彩虹色的宝可梦……换\n"
	.string "句话说……\p"
	.string "凤王从天而降，赋予了那三只宝可梦\n"
	.string "新的生命。\p"
	.string "它们就是……水君、炎帝和\n"
	.string "雷公。\p"
	.string "传说就是这么流传的。$"

TinTower_1F_Sage3_Text:
	.string "据说这两座塔的建造，是为了寄托宝\n"
	.string "可梦与人类之间的\p"
	.string "友谊与希望。虽然那是700年前的\n"
	.string "事了，但这份信念\p"
	.string "在今天依然至关重要。$"

TinTower_1F_Sage4_Text1:
	.string "凤王似乎已经降临到了这座铃铛塔上\n"
	.string "！$"

TinTower_1F_Sage4_Text2:
	.string "据说传说的宝可梦化身为了三种力量\n"
	.string "......\p"
	.string "击中塔的雷电、燃烧塔的烈火，\p"
	.string "以及浇灭烈火的风雨……$"

TinTower_1F_Sage6_Text2:
	.string "在传说的宝可梦中，据说水君与凤王\n"
	.string "之间的关系最为紧密。\p"
	.string "我还听说它可能与一种名为未知图腾\n"
	.string "的宝可梦有所关联。\p"
	.string "未知图腾必定与水君有着同舟共济的\n"
	.string "羁绊。$"

TinTower_1F_EusineHoOh_Text:
	.string "我就知道！\p"
	.string "我就知道你一定会见到那只彩虹色的\n"
	.string "宝可梦，<PLAYER>。\p"
	.string "一切正如我所料。我的研究还是蛮厉\n"
	.string "害的吧！\p"
	.string "为了成为著名的宝可梦狂，我要继续\n"
	.string "努力研究宝可梦！$"

TinTower_1F_EusineSuicune_Text:
	.string "米那君：太精彩了！简直太不可思议\n"
	.string "了！我从未见过如此精彩的对战。\p"
	.string "真是一场令人深受震撼的对决。水君\n"
	.string "固然强大，但你更是\p"
	.string "令人叹服，<PLAYER>。我听\n"
	.string "说水君不可思议的力量\p"
	.string "能唤来彩虹色的宝可梦。也许，只是\n"
	.string "也许，今天的经历\p"
	.string "会让那只宝可梦显现身姿。我要去更\n"
	.string "加深入地钻研传说了。\p"
	.string "谢谢你让我见识了这么精彩的对决。\p"
	.string "后会有期，<PLAYER>！$"
