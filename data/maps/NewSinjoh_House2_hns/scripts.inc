NewSinjoh_House2_hns_MapScripts::
	.byte 0


NewSinjoh_House2_EventScripts_DeskLady::
    lock
	msgbox NewSinjoh_House2_DeskLady_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_DeskLady_Text::
    .string "你好啊，小朋友......\p"
    .string "欢迎来到新神都的......嗯，\n"
    .string "你可以称这里为图书馆。\p"
    .string "其实呢，这里保存着我们镇上所有的\n"
    .string "历史记录，以及从其他地区引进来的\l"
    .string "各类文献......$"

NewSinjoh_House2_EventScript_Torkoal::
	lock
	faceplayer
	playmoncry SPECIES_TORKOAL, 0
	msgbox NewSinjoh_Hosue2_Text_CryTorkoal, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Hosue2_Text_CryTorkoal:
	.string "托--？$"

NewSinjoh_House2_EventScript_BookShelf_North::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_North MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_North:
    .string "里面塞满了古老的皮革封面书籍。\p"
    .string "上面的文字完全无法辨认。$"

NewSinjoh_House2_EventScript_BookShelf_South::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_South MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_South:
    .string "里面塞满了宝可梦的书籍。\p"
    .string "这些看起来比较新，内容也更熟悉一\n"
    .string "些。$"
