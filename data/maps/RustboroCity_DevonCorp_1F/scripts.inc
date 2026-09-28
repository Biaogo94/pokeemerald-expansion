RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "您好，欢迎来到得文公司。\p"
	.string "我们公司发明改变人们生活的药品和\n"
	.string "道具。$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "我们的一个调查员被人把很重要的包\n"
	.string "裹抢走了。$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "哎，那是跑步鞋！那也是我们的产品\n"
	.string "！\p"
	.string "每次看到别人使用我们的发明，我都\n"
	.string "会很高兴。$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "被偷走的包裹……\p"
	.string "虽然确实很重要，但也不是所有人都\n"
	.string "会使用的东西。\p"
	.string "我看那个强盗没那么聪明。$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "听说被抢走的得文的物品找回来了。$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "对不起，无关人士请勿入内。$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "说什么傻话，谁会抢我们的东西？$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "您好！随时欢迎您来参观！$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "玻璃箱子里展示着岩石和金属的样品\n"
	.string "，\p"
	.string "上面有张卡片上写了些什么……\p"
	.string "“得文公司创立时仅仅是一家以采石\n"
	.string "为业的小公司，\p"
	.string "同时也利用沙子中的铁屑炼铁。\p"
	.string "得文从一个微小的原材料处理公司起\n"
	.string "家，\p"
	.string "现在已发展成为一个开发出的产品覆\n"
	.string "盖很多工业领域的大型制造商。”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "玻璃展示柜里放了些产品的原型和试\n"
	.string "验品。\p"
	.string "有张卡片上写着说明……\p"
	.string "“除工业产品外，得文如今也开发日\n"
	.string "常用品与药品。\p"
	.string "近年来，得文致力于为宝可梦训练家\n"
	.string "开发包括精灵球和宝可导航系统等一\l"
	.string "系列工具。”$"

