GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "我对战老是输，宝可梦总是陷入濒死\n"
    .string "......\p"
    .string "也许就是因为这样，我的宝可梦才不\n"
    .string "太亲近我吧……$"

GoldenrodHappinessRater_Text_Twin:
    .string "我对宝可梦使用道具的时候，它看起\n"
    .string "来特别高兴呢！$"
