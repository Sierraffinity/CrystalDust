NewBarkTown_PlayersHouse_2F_MapScripts:: @ 81F83E3
	@map_script 3, NewBarkTown_PlayersHouse_2F_MapScript1_1F83EE
	map_script 4, NewBarkTown_PlayersHouse_2F_MapScript2_1F846A
	.byte 0

NewBarkTown_PlayersHouse_2F_MapScript2_1F846A: @ 81F846A
	map_script_2 VAR_0x4089, 0, EventScript_275D0C
	.2byte 0

EventScript_PlayerPC:: @ 81F860D
	lockall
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gUnknown_08272D87, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

NewBarkTown_PlayersHouse_2F_EventScript_1F863F:: @ 81F863F
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

NewBarkTown_PlayersHouse_2F_Text_1F8820: @ 81F8820
	.string "It's the TOWN MAP.$"
