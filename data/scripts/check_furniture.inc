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

EventScript_PictureBookShelf::
	msgbox Text_PictureBookShelf, MSGBOX_SIGN
	end

EventScript_BookShelf::
	msgbox Text_BookShelf, MSGBOX_SIGN
	end

EventScript_PokemonCenterBookShelf::
	msgbox Text_PokemonCenterBookShelf, MSGBOX_SIGN
	end

EventScript_Vase::
	msgbox Text_Vase, MSGBOX_SIGN
	end

EventScript_EmptyTrashCan::
	msgbox Text_EmptyTrashCan, MSGBOX_SIGN
	end

EventScript_ShopShelf::
	msgbox Text_ShopShelf, MSGBOX_SIGN
	end

EventScript_Blueprint::
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
