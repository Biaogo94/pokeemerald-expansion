SafariZone_East_Frlg_MapScripts::
	.byte 0

SafariZone_East_EventScript_RestHouseSign::
	msgbox SafariZone_East_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_East_EventScript_TrainerTips::
	msgbox SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk, MSGBOX_SIGN
	end

SafariZone_East_EventScript_AreaSign::
	msgbox SafariZone_East_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_East_Text_RestHouse::
	.string "休息屋$"

SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk::
	.string "训练家贴士\p"
	.string "在你走路的时候剩余的时间会越来越\n"
	.string "少。$"

SafariZone_East_Text_AreaSign::
	.string "栖息地1往西：中部栖息地$"

