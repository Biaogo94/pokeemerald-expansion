Route26_House2_hns_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "这里写着一些字。\p"
    .string "要读一下吗？$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "致我的兄弟姐妹们：\p"
    .string "能为各位宝可梦训练家提供帮助，我\n"
    .string "们倍感自豪。\p"
    .string "当有训练家和你们搭话时，送给他们\n"
    .string "一些有用的东西吧。\p"
    .string "爱你们的月美\p"
    .string "要接着往下读吗？$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "周一：月美40号水路\p"
    .string "周二：火美29号道路\p"
    .string "周三：水夫愤怒之湖\p"
    .string "周四：木夫36号道路\p"
    .string "周五：金美32号道路\p"
    .string "周六：土夫烟墨市\p"
    .string "周日：日夫37号道路$"
