GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "只要在背包里登记好自行车，按一个\n"
	.string "键就能轻松骑上了。\p"
	.string "如果你想骑得更快，就得先停下来才\n"
	.string "行！\p"
	.string "这听起来可能有点奇怪，但自行车的\n"
	.string "变速档位只有在停下时才能切换。\p"
	.string "停下时按下R键，再次蹬车时就能达\n"
	.string "到更快的速度！$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "……唉……虽然搬\n"
    .string "到了这里，但自行车却一台都卖不出\l"
    .string "去。怎么会这样呢？\p"
    .string "你能骑上自行车，帮我做做宣传吗？$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "真的吗？太好了！\p"
    .string "告诉我你的名字和电话号码，我就借\n"
    .string "你一台自行车。$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER}借到了自行车。$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "自从从关都搬过来之后，生意一直很\n"
	.string "难做。真的很感谢你的帮忙！\p"
	.string "请务必向大家展示我们专利的变速技\n"
	.string "术哦！\p"
	.string "停下自行车时按一下R键就行，非常\n"
	.string "简单。\p"
	.string "注意哦！接下来速度会变得更快！$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "……唉……人心的\n"
    .string "温暖啊……$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "全新发售！\p"
    .string "一流的折叠式自行车！$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "是一台崭新的自行车！$"
