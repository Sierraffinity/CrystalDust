NewBarkTown_PlayersHouse_2F_MapScripts:: @ 81F83E3
	map_script 3, NewBarkTown_PlayersHouse_2F_MapScript1_1F83EE
	map_script 4, NewBarkTown_PlayersHouse_2F_MapScript2_1F846A
	.byte 0

NewBarkTown_PlayersHouse_2F_MapScript1_1F83EE: @ 81F83EE
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

NewBarkTown_PlayersHouse_2F_MapScript2_1F846A: @ 81F846A
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

EventScript_PlayerPC:: @ 81F860D
	lockall
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

NewBarkTown_PlayersHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F863F
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

Common_Text_LookCloserAtMap: @ 81F8820
	.string "It's the TOWN MAP.$"

NewBarkTown_PlayersHouse_2F_Radio::
	goto_if_set FLAG_SYS_POKEMON_GET, EventScript_Radio1
	goto_if_set FLAG_LISTENED_TO_INITIAL_RADIO, NewBarkTown_PlayersHouse_2F_Radio_AlreadyListened
	playbgm MUS_OAKS_LAB 0
	message NewBarkTown_PlayersHouse_2F_Text_RadioText1
	waitmessage
	delay 90
	message NewBarkTown_PlayersHouse_2F_Text_RadioText2
	waitmessage
	delay 90
	message NewBarkTown_PlayersHouse_2F_Text_RadioText3
	waitmessage
	delay 90
	fadedefaultbgm
	setflag FLAG_LISTENED_TO_INITIAL_RADIO
	message NewBarkTown_PlayersHouse_2F_Text_RadioText4
	waitmessage
	delay 90
	closemessage
	end

NewBarkTown_PlayersHouse_2F_Radio_AlreadyListened:
	msgbox NewBarkTown_PlayersHouse_2F_Text_RadioText4, MSGBOX_SIGN
	end

NewBarkTown_PlayersHouse_2F_Text_RadioText1:
	.string "This was PROF. OAK'S POKéMON TALK!\n"
	.string "Please tune in next time!$"

NewBarkTown_PlayersHouse_2F_Text_RadioText2:
	.string "POKéMON CHANNEL!$"

NewBarkTown_PlayersHouse_2F_Text_RadioText3:
	.string "This is DJ MARY, your co-host,\n"
	.string "signing off!$"

NewBarkTown_PlayersHouse_2F_Text_RadioText4:
	.string "POKéMON!\n"
	.string "POKéMON CHANNEL…$"
