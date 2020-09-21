PokedexRating_EventScript_ShowRatingMessage:: @ 8272179
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	compare VAR_RESULT, FALSE
	call_if_eq PokedexRating_EventScript_NormalFanfare
	compare VAR_RESULT, TRUE
	call_if_eq PokedexRating_EventScript_DexCompleteFanfare
	waitfanfare
	waitbuttonpress
	return

PokedexRating_EventScript_NormalFanfare:: @ 81A73D8
	playfanfare MUS_RG_DEX_RATING
	return

PokedexRating_EventScript_DexCompleteFanfare:: @ 81A73DC
	playfanfare MUS_EVOLVED
	return

PokedexRating_EventScript_RatePokedex:: @ 8272184
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring 0, VAR_0x8008  @ Num Johto seen
	buffernumberstring 1, VAR_0x8009  @ Num Johto caught
	msgbox gPokedexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call PokedexRating_EventScript_ShowRatingMessage
	compare VAR_0x800A, FALSE
	goto_if_eq Common_EventScript_NopReturn  @ National dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring 0, VAR_0x8008  @ Num National seen
	buffernumberstring 1, VAR_0x8009  @ Num National caught
	msgbox gPokedexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAllMons
	compare VAR_RESULT, FALSE
	goto_if_eq PokedexRating_EventScript_DexIncomplete
	compare VAR_RESULT, TRUE
	goto_if_eq PokedexRating_EventScript_DexComplete
	return

PokedexRating_EventScript_SetTextColor:: @ 81A746D
	textcolor MSG_COLOR_BLUE
	return

PokedexRating_EventScript_DexIncomplete:: @ 81A7470
	msgbox PokedexRating_Text_LookForwardToFilledNationalDex
	return

PokedexRating_EventScript_DexComplete:: @ 81A747E
	@setflag FLAG_OAK_SAW_DEX_COMPLETION
	msgbox PokedexRating_Text_YouveCompletedDex
	return
