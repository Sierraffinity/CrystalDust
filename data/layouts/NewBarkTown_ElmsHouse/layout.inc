NewBarkTown_ElmsHouse_MapBorder::
	.incbin "data/layouts/NewBarkTown_ElmsHouse/border.bin"

NewBarkTown_ElmsHouse_MapBlockdata::
	.incbin "data/layouts/NewBarkTown_ElmsHouse/map.bin"

	.align 2
NewBarkTown_ElmsHouse_Layout::
	.4byte 0xb
	.4byte 0x9
	.4byte NewBarkTown_ElmsHouse_MapBorder
	.4byte NewBarkTown_ElmsHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BrendansMaysHouse

