NewBarkTown_OtherHouse_MapBorder::
	.incbin "data/layouts/NewBarkTown_OtherHouse/border.bin"

NewBarkTown_OtherHouse_MapBlockdata::
	.incbin "data/layouts/NewBarkTown_OtherHouse/map.bin"

	.align 2
NewBarkTown_OtherHouse_Layout::
	.4byte 11
	.4byte 9
	.4byte NewBarkTown_OtherHouse_MapBorder
	.4byte NewBarkTown_OtherHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BrendansMaysHouse

