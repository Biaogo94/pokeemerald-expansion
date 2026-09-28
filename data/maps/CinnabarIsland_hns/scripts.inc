CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
    .string "夏伯：在红莲道馆重建成功之前，我\n"
    .string "是绝对不会放弃的！\p"
    .string "在那之前，我会一直待在格斗道场。$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "你是谁？\p"
	.string "哼，一眼就能看出你是个训练家..\n"
	.string "....\p"
	.string "本大爷叫青绿。\p"
	.string "虽然时间很短，不过我也曾是宝可梦\n"
	.string "联盟冠军......\p"
	.string "都怪那个爱管闲事的赤红.....\n"
	.string ".\p"
	.string "算了，你找我有什么事？难道是想挑\n"
	.string "战我吗？\p"
	.string "......虽然很遗憾，不过我现\n"
	.string "在可没心情对战。\p"
	.string "你仔细看看周围吧......\p"
	.string "火山一爆发，整座城镇眨眼间就化为\n"
	.string "乌有。\p"
	.string "宝可梦对战确实有胜有负。可大自然\n"
	.string "只要稍微动一动，我们瞬间就会输得\l"
	.string "一败涂地。\p"
	.string "......\p"
	.string "现实就是如此无情啊......\p"
	.string "不过话说回来，我好歹也是个训练家\n"
	.string "。\p"
	.string "一看到强大的对手，手脚就会忍不住\n"
	.string "发痒。\p"
	.string "要是你想挑战我，就先去集齐15枚\n"
	.string "徽章吧。\p"
	.string "到那时，我随时奉陪。$"

CinnabarIsland_Text_Blue:
	.string "你是谁？\p"
	.string "哼，一眼就能看出你是个训练家..\n"
	.string "....\p"
	.string "本大爷叫青绿。\p"
	.string "虽然时间很短，不过我也曾是宝可梦\n"
	.string "联盟冠军......\p"
	.string "都怪那个爱管闲事的赤红.....\n"
	.string ".\p"
	.string "算了，你找我有什么事？难道是想挑\n"
	.string "战我吗？\p"
	.string "......虽然很遗憾，不过我现\n"
	.string "在可没心情对战。\p"
	.string "你仔细看看周围吧......\p"
	.string "火山一爆发，整座城镇眨眼间就化为\n"
	.string "乌有。\p"
	.string "宝可梦对战确实有胜有负。可大自然\n"
	.string "只要稍微动一动，我们瞬间就会输得\l"
	.string "一败涂地。\p"
	.string "......\p"
	.string "现实就是如此无情啊......\p"
	.string "不过话说回来，我好歹也是个训练家\n"
	.string "。\p"
	.string "一看到强大的对手，手脚就会忍不住\n"
	.string "发痒。\p"
	.string "要是你想挑战我，就来常青道馆吧。\p"
	.string "到那时，我随时奉陪。$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "这里贴着一张告示......\p"
	.string "红莲道馆已搬迁至双子岛。\p"
	.string "夏伯$"

CinnabarIsland_Text_Sign:
	.string "红莲岛\p"
	.string "燃烧着热血的城镇$"

