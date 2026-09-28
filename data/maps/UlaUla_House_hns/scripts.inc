UlaUla_House_hns_MapScripts::
	.byte 0


Alola_Ulaula_House_Phant::
	lock
	faceplayer
	compare VAR_ALOLA_STATE, 4
	goto_if_eq Alola_Ulaula_House_Phant_1
	msgbox Alola_Ulaula_House_Phant_Text_7, MSGBOX_AUTOCLOSE
	release
	end

Alola_Ulaula_House_Phant_1:
	msgbox Alola_Ulaula_House_Phant_Text_0, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 5
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	compare VAR_TEMP_1, 8
	goto_if_eq Alola_Ulaula_House_Phant_9
Alola_Ulaula_House_Phant_7:
	compare VAR_TEMP_1, 9
	goto_if_eq Alola_Ulaula_House_Phant_14
Alola_Ulaula_House_Phant_12:
	compare VAR_TEMP_1, 8
	goto_if_eq Alola_Ulaula_House_Phant_19
Alola_Ulaula_House_Phant_17:
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Ulaula_House_Phant_Text_3
	compare VAR_TEMP_1, 8
	goto_if_eq Alola_Ulaula_House_Phant_24
Alola_Ulaula_House_Phant_22:
	compare VAR_TEMP_1, 9
	goto_if_eq Alola_Ulaula_House_Phant_29
Alola_Ulaula_House_Phant_27:
	compare VAR_TEMP_1, 8
	goto_if_eq Alola_Ulaula_House_Phant_34
Alola_Ulaula_House_Phant_32:
	giveegg SPECIES_NOIBAT
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Ulaula_House_Phant_Text_4
	waitfanfare
	msgbox Alola_Ulaula_House_Phant_Text_5, MSGBOX_AUTOCLOSE
	release
	end

Alola_Ulaula_House_Phant_8:
	applymovement Phantonomy, Alola_Ulaula_House_Phant_Movement_0
	goto Alola_Ulaula_House_Phant_7

Alola_Ulaula_House_Phant_9:
	compare VAR_TEMP_2, 10
	goto_if_eq Alola_Ulaula_House_Phant_8
	goto Alola_Ulaula_House_Phant_7

Alola_Ulaula_House_Phant_13:
	applymovement Phantonomy, Alola_Ulaula_House_Phant_Movement_1
	goto Alola_Ulaula_House_Phant_12

Alola_Ulaula_House_Phant_14:
	compare VAR_TEMP_2, 9
	goto_if_eq Alola_Ulaula_House_Phant_13
	goto Alola_Ulaula_House_Phant_12

Alola_Ulaula_House_Phant_18:
	applymovement Phantonomy, Alola_Ulaula_House_Phant_Movement_2
	goto Alola_Ulaula_House_Phant_17

Alola_Ulaula_House_Phant_19:
	compare VAR_TEMP_2, 8
	goto_if_eq Alola_Ulaula_House_Phant_18
	goto Alola_Ulaula_House_Phant_17

Alola_Ulaula_House_Phant_23:
	applymovement Phantonomy, Alola_Ulaula_House_Phant_Movement_3
	waitmovement 0
	delay 30
	goto Alola_Ulaula_House_Phant_22

Alola_Ulaula_House_Phant_24:
	compare VAR_TEMP_2, 10
	goto_if_eq Alola_Ulaula_House_Phant_23
	goto Alola_Ulaula_House_Phant_22

Alola_Ulaula_House_Phant_28:
	applymovement Phantonomy, Alola_Ulaula_House_Phant_Movement_4
	waitmovement 0
	delay 30
	goto Alola_Ulaula_House_Phant_27

Alola_Ulaula_House_Phant_29:
	compare VAR_TEMP_2, 9
	goto_if_eq Alola_Ulaula_House_Phant_28
	goto Alola_Ulaula_House_Phant_27

Alola_Ulaula_House_Phant_33:
	applymovement Phantonomy, Alola_Ulaula_House_Phant_Movement_5
	waitmovement 0
	delay 30
	goto Alola_Ulaula_House_Phant_32

Alola_Ulaula_House_Phant_34:
	compare VAR_TEMP_2, 8
	goto_if_eq Alola_Ulaula_House_Phant_33
	goto Alola_Ulaula_House_Phant_32


Alola_Ulaula_House_Noivern::
	lock
	faceplayer
	playmoncry SPECIES_NOIVERN, 0
	msgbox Alola_Ulaula_House_Noivern_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end


Alola_Ulaula_House_Typholosion::
	lock
	faceplayer
	playmoncry SPECIES_TYPHLOSION_HISUI, 0
	msgbox Alola_Ulaula_House_Typholosion_Text_0
	waitmoncry
	release
	end


Alola_Ulaula_House_Phant_Movement_0:
	jump_in_place_down
	jump_in_place_down
	step_end

Alola_Ulaula_House_Phant_Movement_1:
	jump_in_place_right
	jump_in_place_right
	step_end

Alola_Ulaula_House_Phant_Movement_2:
	jump_in_place_up
	jump_in_place_up
	step_end

Alola_Ulaula_House_Phant_Movement_3:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Ulaula_House_Phant_Movement_4:
	walk_in_place_right
	walk_in_place_right
	step_end

Alola_Ulaula_House_Phant_Movement_5:
	walk_in_place_up
	walk_in_place_up
	step_end

Alola_Ulaula_House_Phant_Text_0:
	.string "欢迎，{PLAYER}。\p"
	.string "再次感谢你游玩本作！$"

Alola_Ulaula_House_Phant_Text_1:
	.string "希望你已经做好了准备......\n"
	.string "祝你好运。$"

Alola_Ulaula_House_Phant_Text_2:
	.string "恭喜你，{PLAYER}！$"

Alola_Ulaula_House_Phant_Text_3:
	.string "这是你应得的奖励。$"

Alola_Ulaula_House_Phant_Text_4:
	.string "从PHANTONOMY那里获得了\n"
	.string "蛋！$"

Alola_Ulaula_House_Phant_Text_5:
	.string "那颗蛋里是我最喜欢的宝可梦。\p"
	.string "请一定要好好照顾它......$"

Alola_Ulaula_House_Phant_Text_6:
	.string "没关系的，{PLAYER}。等你\n"
	.string "准备好了再来吧......$"

Alola_Ulaula_House_Phant_Text_7:
	.string "希望你喜欢这次阿罗拉的小小体验。\p"
	.string "我目前正在制作阿罗拉地区的完整复\n"
	.string "古重制版，名为《究极日蚀》。$"

Alola_Ulaula_House_Noivern_Text_0:
	.string "嘶嘁--！$"

Alola_Ulaula_House_Typholosion_Text_0:
	.string "吼啊！$"
