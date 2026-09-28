SSAqua_PlayersRoom_hns_MapScripts::
	.byte 0

SSAquaRooms_EventScript_Bed::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSAquaRooms_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox SSAquaRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

SSAquaRooms_EventScript_Bed_PokecenterChallenge::
	msgbox SSAquaRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	release
	end


SSAquaRooms_Text_TakeRestOnBed_PokecenterChallenge:
	.string "抱歉，你正在进行宝可梦中心挑战！$"

SSAquaRooms_Text_TakeRestOnBed:
	.string "这里有张床......好好休息一\n"
	.string "下吧。$"
