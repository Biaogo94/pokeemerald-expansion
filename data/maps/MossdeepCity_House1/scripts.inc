MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "啊！你的{STR_VAR_1}…\n"
	.string "…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "它喜欢{STR_VAR_1}是吧\n"
	.string "？\p"
	.string "不，我肯定它就是喜欢\n"
	.string "{STR_VAR_1}！$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "它看起来对任何\n"
	.string "{POKEBLOCK}都无所谓喜\l"
	.string "不喜欢。$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "我丈夫只要看一眼，就能知道宝可梦\n"
	.string "喜欢什么样的\l"
	.string "{POKEBLOCK}。$"

