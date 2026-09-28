PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "千里是城镇里新来的道馆馆主，\p"
	.string "他带着全家从很远的地方搬过来了。$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "我曾经挑战过千里，但是，唉，他太\n"
	.string "强了。\p"
	.string "怎么说呢？\p"
	.string "我感觉他是为宝可梦而生的。$"

