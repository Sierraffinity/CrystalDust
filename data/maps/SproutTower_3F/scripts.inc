SproutTower_3F_MapScripts:: @ 8237A92
	.byte 0

SproutTower_3F_EventScript_Gentleman:: @ 8237A93
	msgbox SproutTower_3F_Text_TakingALookAround, MSGBOX_NPC
	end

SproutTower_3F_EventScript_Demetrius:: @ 8237A9C
	trainerbattle_single TRAINER_DEMETRIUS, SproutTower_3F_Text_DemetriusIntro, SproutTower_3F_Text_DemetriusDefeat
	msgbox SproutTower_3F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Thalia:: @ 8237AB3
	trainerbattle_single TRAINER_THALIA_1, SproutTower_3F_Text_ThaliaIntro, SproutTower_3F_Text_ThaliaDefeat, SproutTower_3F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq SproutTower_3F_EventScript_ThaliaRematch
	msgbox SproutTower_3F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

SproutTower_3F_EventScript_RegisterThalia:: @ 8237ADF
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox SproutTower_3F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

SproutTower_3F_EventScript_ThaliaRematch:: @ 8237AFE
	trainerbattle_rematch TRAINER_THALIA_1, SproutTower_3F_Text_ThaliaRematchIntro, SproutTower_3F_Text_ThaliaRematchDefeat
	msgbox SproutTower_3F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_Text_TakingALookAround: @ 8237B15
	.string "Ships of this sort are rare, so I'm\n"
	.string "taking a look around.\p"
	.string "Hmhm…\n"
	.string "There appear to be other cabins…$"

SproutTower_3F_Text_ThaliaIntro: @ 8237B76
	.string "What on earth would compel you to\n"
	.string "come here? You must be curious!$"

SproutTower_3F_Text_ThaliaDefeat: @ 8237BB8
	.string "Not just curious, but also strong…$"

SproutTower_3F_Text_ThaliaPostBattle: @ 8237BDB
	.string "The man next door…\p"
	.string "He says he's just sightseeing,\n"
	.string "but I don't know about that.$"

SproutTower_3F_Text_ThaliaRegister: @ 8237C2A
	.string "You're such a tough TRAINER!\n"
	.string "Let me register you as a memento!$"

SproutTower_3F_Text_ThaliaRematchIntro: @ 8237C69
	.string "What on earth would compel you to\n"
	.string "come back? You must really be curious!$"

SproutTower_3F_Text_ThaliaRematchDefeat: @ 8237CB2
	.string "Aren't you too strong?$"

SproutTower_3F_Text_ThaliaPostRematch: @ 8237CC9
	.string "I'm sure that man's up to something!\n"
	.string "He just acts so suspiciously!$"

SproutTower_3F_Text_DemetriusIntro: @ 8237D0C
	.string "Waaah!\n"
	.string "I've been found! …Huh?$"

SproutTower_3F_Text_DemetriusDefeat: @ 8237D2A
	.string "Oh, you're not my mom.$"

SproutTower_3F_Text_DemetriusPostBattle: @ 8237D41
	.string "I'm in trouble with my mom, so I ran.\n"
	.string "Keep it a secret where I am!$"

