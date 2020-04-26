EventScript_TV::
	msgbox Text_ItsATV, MSGBOX_SIGN
	end

EventScript_Window::
	msgbox Text_MyReflection, MSGBOX_SIGN
	end

EventScript_AncientPokemonReplica::
	msgbox Text_AncientPokemonReplica, MSGBOX_SIGN
	end

EventScript_DistinguishedStatue::
	msgbox Text_DistinguishedStatue, MSGBOX_SIGN
	end

EventScript_PictureBookShelf:: @ 82725CE
	msgbox Text_PictureBookShelf, MSGBOX_SIGN
	end

EventScript_BookShelf:: @ 82725D7
	msgbox Text_BookShelf, MSGBOX_SIGN
	end

EventScript_DifficultBookShelf::
	msgbox Text_DifficultBooks, MSGBOX_SIGN
	end

EventScript_PokemonCenterBookShelf:: @ 82725E0
	msgbox Text_PokemonCenterBookShelf, MSGBOX_SIGN
	end

EventScript_Vase:: @ 82725E9
	msgbox Text_Vase, MSGBOX_SIGN
	end

EventScript_EmptyTrashCan:: @ 82725F2
	msgbox Text_EmptyTrashCan, MSGBOX_SIGN
	end

EventScript_ShopShelf:: @ 82725FB
	msgbox Text_ShopShelf, MSGBOX_SIGN
	end

EventScript_Blueprint:: @ 8272604
	msgbox Text_Blueprint, MSGBOX_SIGN
	end

EventScript_Radio1::
	lockall
	setvar VAR_0x8004, STATION_POKEMON_CHANNEL
	special FieldRadio
	waitstate
	releaseall
	end

EventScript_Radio2::
	lockall
	setvar VAR_0x8004, STATION_LUCKY_CHANNEL
	special FieldRadio
	waitstate
	releaseall
	end
