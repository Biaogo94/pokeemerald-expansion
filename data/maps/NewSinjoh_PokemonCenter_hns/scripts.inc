NewSinjoh_PokemonCenter_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_PokemonCenter_OnTransition
    .byte 0

NewSinjoh_PokemonCenter_OnTransition: 
    setrespawn HEAL_LOCATION_NEW_SINJOH_HNS
    end

NewSinjoh_EventScript_Artist::
	lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT, NewSinjoh_EventScript_ZoomLens_Gotten
	msgbox NewSinjoh_Text_Artist, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_EventScript_ZoomLens_No
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	giveitem ITEM_ZOOM_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT
	release
	end

NewSinjoh_PokemonCenter_EventScript_Skiier::
	lock
	faceplayer
	msgbox NewSinjoh_PokemonCenter_Text_Skiier, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_POKEMONCENTER_SKIIER, DIR_NORTH
	release
	end

NewSinjoh_PokemonCenter_hns_Map::
	lockall
	setvar VAR_0x8000, 1 @ SCREENSHOT_SINJOH_MAP
	msgbox NewSinjoh_PokemonCenter_hns_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

NewSinjoh_PokemonCenter_Text_Skiier:
	.string "大雪让人很难在这里辨别方向。\p"
	.string "到处看起来都一模一样。\p"
	.string "所以这幅地图帮了大忙！\p"
	.string "这真是一片美丽的地区啊！$"

NewSinjoh_Text_Artist:
	.string "我在这座隐秘的城镇里获得了极大的\n"
	.string "灵感！\p"
	.string "你不觉得这里的景色美得令人屏息\n"
	.string "吗？$"

Text_ItemGiveaway:
	.string "原来如此！你肯定也是一名艺术家\n"
	.string "吧！\p"
	.string "我刚好有多余的东西，可以帮你捕捉\n"
	.string "生活中微小的细节！$"

NewSinjoh_Text_Artist_No:
    .string "你该不会是那种排斥游客的人吧？美\n"
    .string "丽的事物本就该与人分享嘛。$"

NewSinjoh_EventScript_ZoomLens_No::
	msgbox NewSinjoh_Text_Artist_No, MSGBOX_DEFAULT
	release
	end

NewSinjoh_EventScript_ZoomLens_Gotten::
	msgbox Text_WasGiven_ZoomLensAlready, MSGBOX_DEFAULT
	release
	end

Text_WasGiven_ZoomLensAlready:
	.string "希望你能喜欢那个镜片！$"

NewSinjoh_EventScript_FemAce::
	msgbox NewSinjoh_Text_FemAce, MSGBOX_NPC
	end

NewSinjoh_Text_FemAce:
	.string "在新神都并没有多少现代化的便利设\n"
	.string "施。\p"
	.string "但好在至少还有这家宝可梦中心。$"


NewSinjoh_PokemonCenter_hns_Text_0:
	.string "{PLAYER}仔细端详了神都地\n"
	.string "图。$"
