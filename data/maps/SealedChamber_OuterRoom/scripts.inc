SealedChamber_OuterRoom_MapScripts:: @ 8239106
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_OnLoad
	.byte 0

SealedChamber_OuterRoom_OnResume: @ 8239116
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
	end

SealedChamber_OuterRoom_OnTransition: @ 8239127
	setflag FLAG_LANDMARK_SEALED_CHAMBER
	end

SealedChamber_OuterRoom_OnLoad: @ 823912B
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance
	end

SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance:: @ 8239135
	setmetatile 9, 1, METATILE_Cave_EntranceCover, 1
	setmetatile 10, 1, METATILE_Cave_EntranceCover, 1
	setmetatile 11, 1, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 10, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 11, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

SealedChamber_OuterRoom_EventScript_BrailleABC:: @ 823916C
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_ABC
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleGHI:: @ 8239176
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_GHI
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleMNO:: @ 8239180
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_MNO
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleTUV:: @ 823918A
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_TUV
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDEF:: @ 8239194
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_DEF
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleJKL:: @ 823919E
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_JKL
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePQRS:: @ 82391A8
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_PQRS
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePeriod:: @ 82391B2
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_Period
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleWXYZ:: @ 82391BC
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_WXYZ
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleComma:: @ 82391C6
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_Comma
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_InnerRoomEntranceWall:: @ 82391D0
	lockall
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_HoleInWall
	unownmessage SealedChamber_OuterRoom_Braille_DigHere
	waitbuttonpress
	closeunownmessage
	releaseall
	end

SealedChamber_OuterRoom_EventScript_HoleInWall:: @ 82391E3
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDigHere:: @ 82391ED
	lockall
	unownmessage SealedChamber_OuterRoom_Braille_DigHere
	waitbuttonpress
	closeunownmessage
	releaseall
	end

