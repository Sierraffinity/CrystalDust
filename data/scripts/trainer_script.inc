Std_RegisteredInMatchCall::
	waitse
	playfanfare MUS_REGISTER_PHONE
	textcolor MSG_COLOR_SYS
	msgbox EventScript_Text_Trainer_Registered
	waitfanfare
	closemessage
	textcolor MSG_COLOR_PREV
	return

EventScript_TryGetTrainerScript::
	special ShouldTryGetTrainerScript
	compare VAR_RESULT, 1
	goto_if_eq EventScript_GotoTrainerScript
	releaseall
	end

EventScript_GotoTrainerScript::
	gotobeatenscript
	releaseall
	end

EventScript_Text_Trainer_Registered:
	.string "{PLAYER} registered {STR_VAR_1}'s\n"
	.string "phone number!$"
