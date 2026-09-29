VermilionCity_FanClub_hns_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "我是宝可梦发烧友俱乐部的会长。\p"
	.string "我已经培育过150多只宝可梦了。\p"
	.string "只要一谈到宝可梦，我可是非常挑剔\n"
	.string "的。\p"
	.string "你专程过来，是为了听我聊聊我的宝\n"
	.string "可梦吗？$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "太好了！那就仔细听好喽！\p"
	.string "话说……我最心爱的烈焰\n"
	.string "马……\p"
	.string "它……可爱……迷\n"
	.string "人……聪明……让\l"
	.string "人欲罢不能……而且..\l"
	.string "……太棒了……哦。\l"
	.string "……你也是这么觉得？..\l"
	.string "……简直太……狂野\l"
	.string "……美丽……温\l"
	.string "柔……我超爱它！\p"
	.string "睡觉的时候……抱抱它。\n"
	.string "……暖洋洋又毛茸茸的..\l"
	.string "……哦，还有……帅气\l"
	.string "逼人……令人陶醉...\l"
	.string "...简直宛如天神……\p"
	.string "哎呀！看看时间！我耽搁你太久了！$"

PokemonFanClub_Text_Chairman_Gift:
	.string "谢谢你愿意听我讲完。这个就送给你\n"
	.string "吧！$"

PokemonFanClub_Text_Chairman_Candy:
	.string "这是能让宝可梦变强的神奇糖果。\p"
	.string "比起用这个，我更喜欢通过对战来让\n"
	.string "宝可梦成长，所以送给你了。$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "你好呀，{PLAYER}！\p"
	.string "你又是来听我聊宝可梦的吗？\p"
	.string "不是吗？哎呀……我肚子里\n"
	.string "还有好多话想讲呢……$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "真令人失望……\p"
	.string "想听的时候随时再来找我吧。$"

PokemonFanClub_Text_Receptionist:
	.string "我们的会长只要一聊起宝可梦，就会\n"
	.string "滔滔不绝呢……$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "我最喜欢皮皮在使用挥指时，摇晃手\n"
	.string "指的样子了。\p"
	.string "简直太可爱了！$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "我很喜欢皮皮，可惜一直都抓不到。\p"
	.string "所以只能拿捡到的皮皮玩偶来凑合充\n"
	.string "数啦。$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "啊，原来是这样。弄丢这个皮皮玩偶\n"
	.string "的小女孩一定很难过吧……\p"
	.string "好吧。你能把这个皮皮玩偶送还给那\n"
	.string "个可怜的小女孩吗？\p"
	.string "不用担心我，总有一天我能凭自己的\n"
	.string "本事和真正的皮皮成为好朋友的！$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "你就瞧好吧。我一定要收服一只真正\n"
	.string "的皮皮做我的好朋友。$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "看看我心爱的月桂叶！\p"
	.string "它头上的那片叶子实在太可爱啦！$"

PokemonFanClub_Text_ClefairyDoll:
	.string "是一只皮皮！咦？\p"
	.string "啊，对了。原来只是个皮皮玩偶啊。$"

PokemonFanClub_Text_Bayleef:
	.string "月桂叶：哩哩--！$"

PokemonFanClub_Text_Listen:
	.string "大家都要礼貌地倾听其他训练家说话\n"
	.string "哦。$"

PokemonFanClub_Text_Bragging:
	.string "要是有人吹牛，那就吹回去！$"
