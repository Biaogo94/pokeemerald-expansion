OlivineCity_Mart_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "你的宝可梦已经学会带人渡海的招式\n"
	.string "了吗？$"

OlivineCity_Text_MartLass:
	.string "我的巴大蝶是我在海外的男朋友送给\n"
	.string "我的。\p"
	.string "它还带来了他写的信呢。\p"
	.string "想知道上面写了什么吗？\p"
	.string "让我想想……不行！这是秘\n"
	.string "密！$"
