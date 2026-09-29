SSAqua_CaptainsRoom_hns_MapScripts::
	.byte 0

SSAqua_CaptainsRoom_EventScript_Captain::
	goto_if_eq VAR_TEMP_0, 1, SSAqua_CaptainsRoom_EventScrip_CaptainAfter
	msgbox SSAqua_CaptainsRoom_Text_CaptainExhausting, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
SSAqua_CaptainsRoom_EventScrip_CaptainAfter::
	msgbox SSAqua_CaptainsRoom_Text_CaptainHowDoYouLike, MSGBOX_DEFAULT
	closemessage
	end

SSAqua_CaptainsRoom_EventScript_Granddaughter::
	lock
	applymovement LOCALID_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER, SSAqua_CaptainsRoom_Movement_Jump
	waitmovement 0
	msgbox SSAqua_CaptainsRoom_Text_GranddaughterCaptainPlayWithMe, MSGBOX_DEFAULT
	turnobject LOCALID_SSAQUA_CAPTAINS_ROOM_CAPTAIN, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SSAQUA_CAPTAINS_ROOM_CAPTAIN, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_SSAQUA_CAPTAINS_ROOM_CAPTAIN
	delay 60
	faceplayer
	msgbox SSAqua_CaptainsRoom_Text_GranddaughterHasToFindGrandpa, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER
	setvar VAR_SSAQUA_STATE, 4
	clearflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER
	warp MAP_SSAQUA_ROOM_SSE_HNS, 0
	waitstate
	release
	end

SSAqua_CaptainsRoom_Movement_Jump:
	jump_in_place_right
	jump_in_place_right
	jump_in_place_right
	step_end

SSAqua_CaptainsRoom_Text_GranddaughterCaptainPlayWithMe:
	.string "船长，陪我玩嘛，好不好？\p"
	.string "好无聊啊！我还想再玩一会儿！$"

SSAqua_CaptainsRoom_Text_GranddaughterHasToFindGrandpa:
	.string "嗨！你来陪我玩吗？\p"
	.string "……啊！\p"
	.string "爷爷在担心我吗？\p"
	.string "我得走了！\p"
	.string "我得快点去找爷爷才行！$"

SSAqua_CaptainsRoom_Text_CaptainExhausting:
	.string "呼！多亏你赶过来了。\p"
	.string "哄那个小姑娘开心真是累死我了。$"

SSAqua_CaptainsRoom_Text_CaptainHowDoYouLike:
	.string "坐水号的感觉如何？\p"
	.string "她简直就像在浪花上滑行一样呢。$"

