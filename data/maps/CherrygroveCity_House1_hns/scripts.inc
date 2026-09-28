CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "你想知道自己作为宝可梦训练家究竟\n"
	.string "有多少实力吗？\p"
	.string "那你最好去挑战城都各地的宝可梦道\n"
	.string "馆，收集徽章吧。$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "等我长大了，我要成为道馆馆主！\p"
	.string "现在我和朋友的宝可梦对战，就是为\n"
	.string "了让它们变得更强！$"
