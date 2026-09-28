PalletTown_House2_hns_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "奈奈美：嗨！我弟弟是常青市的道馆\n"
	.string "馆主。\p"
	.string "但他总喜欢往外跑，让不少挑战的训\n"
	.string "练家都很困扰呢。$"

PalletTown_House2_Text_OfferGrooming:
	.string "奈奈美：嗨！来得正好，我正打算喝\n"
	.string "杯下午茶呢。\p"
	.string "要和我一起喝点吗？\p"
	.string "哎呀，你的宝可梦身上有点脏兮兮的\n"
	.string "呢。\p"
	.string "要让我帮你给其中一只梳毛美容一下\n"
	.string "吗？$"

PalletTown_House2_Text_WhichMon:
	.string "奈奈美：要给哪一只美容呢？$"

PalletTown_House2_Text_Alright:
	.string "奈奈美：好的，马上就把它打扮得漂\n"
	.string "漂亮亮的。$"

PalletTown_House2_Text_AllDone:
	.string "奈奈美：好啦！大功告成！\p"
	.string "你看，{STR_VAR_1}是不\n"
	.string "是变得漂亮多了？\p"
	.string "真是只可爱的宝可梦呢。$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "奈奈美：我每天这个时间都会喝下午\n"
	.string "茶。你也一起来吧。$"

PalletTown_House2_Text_Refused:
	.string "奈奈美：不需要美容吗？\p"
	.string "好的，那我们就只喝茶吧。$"

PalletTown_House2_Text_CantGroomEgg:
	.string "奈奈美：哎呀，抱歉呢。蛋实在没法\n"
	.string "梳毛美容啊。$"
