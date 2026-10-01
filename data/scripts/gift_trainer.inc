MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "感谢使用神秘礼物系统。\p"
	.string "持有这张神奇卡片，就能在友好商店\n"
	.string "参与调查。\p"
	.string "通过调查，可邀请训练家前往琉璃\n"
	.string "市。\p"
	.string "我再告诉你一句调查暗号：\p"
	.string "“给我一位厉害的训练家”\p"
	.string "在调查表中填上这句话，再通过无线\n"
	.string "通信发送出去。$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "感谢使用神秘礼物系统。\p"
	.string "一位训练家已经来到琉璃市寻找您。\p"
	.string "系统您可以享受与训练家的对战。\p"
	.string "您可以邀请其他训练家通过填写密\n"
	.string "码。\p"
	.string "试着找寻其他有用的密码吧。$"
