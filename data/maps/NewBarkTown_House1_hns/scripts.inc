NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "皮卡丘是进化后的宝可梦。\p"
	.string "空木博士的发现真是令我大吃一惊。\p"
	.string "他在宝可梦进化方面的研究非常出名\n"
	.string "。\p"
	.string "......唉......\p"
	.string "真希望我也能成为像他一样的研究员\n"
	.string "啊......$"


NewBarkTown_House1_Text_Neighbor:
	.string "我女儿铁了心要当空木博士的助手。\p"
	.string "她真的很喜欢宝可梦！\p"
	.string "不过话说回来，我也一样喜欢！$"

