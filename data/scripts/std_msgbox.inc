Std_MsgboxNPC: @ 8271315
	lock
	faceplayer
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSign: @ 8271320
	lockall
	message 0x0
	waitmessage
	waitbuttonpress
	releaseall
	return

Std_MsgboxDefault: @ 827132A
	message 0x0
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo: @ 8271332
	message 0x0
	waitmessage
	yesnobox 20, 8
	return

Std_MsgboxGetPoints: @ 827133C
	message 0x0
	playfanfare MUS_ME_POINTGET
	waitfanfare
	waitmessage
	return

Std_10: @ 8271347
	pokegearcall 0x0, 0x0
	waitmessage
	return

Std_PutItemAway::
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferPocketName
	msgbox gText_PutItemInPocket
	return

EventScript_BufferPocketName::
	switch VAR_RESULT
	case POCKET_ITEMS, EventScript_BufferItemsPocket2
	case POCKET_KEY_ITEMS, EventScript_BufferKeyItemsPocket2
	case POCKET_POKE_BALLS, EventScript_BufferPokeballsPocket2
	case POCKET_TM_HM, EventScript_BufferTMHMsPocket2
	case POCKET_BERRIES, EventScript_BufferBerriesPocket2
	end

EventScript_BufferItemsPocket2::
	bufferstdstring 2, STDSTRING_ITEMS
	return

EventScript_BufferKeyItemsPocket2::
	bufferstdstring 2, STDSTRING_KEYITEMS
	return

EventScript_BufferPokeballsPocket2::
	bufferstdstring 2, STDSTRING_POKEBALLS
	return

EventScript_BufferTMHMsPocket2::
	bufferstdstring 2, STDSTRING_TMHMS
	return

EventScript_BufferBerriesPocket2::
	bufferstdstring 2, STDSTRING_BERRIES
	return

Std_ReceivedItem::
	textcolor MSG_COLOR_SYS
	playfanfare VAR_0x8002
	message 0x0
	waitmessage
	waitfanfare
	compare VAR_0x8002, MUS_FANFA4
	call_if_eq EventScript_ReceivedItemWaitFanfare
	putitemaway VAR_0x8000, VAR_0x8001
	call EventScript_RestorePrevTextColor
	return

EventScript_ReceivedItemWaitFanfare::
	delay 50
	return

EventScript_UnusedReturn: @ 827134E
	return

Common_EventScript_SaveGame:: @ 827134F
	special SaveGame
	waitstate
	return
