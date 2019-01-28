NewBarkTown_NeighborsHouse_MapBorder::
	.incbin "data/layouts/NewBarkTown_NeighborsHouse/border.bin"

NewBarkTown_NeighborsHouse_MapBlockdata::
	.incbin "data/layouts/NewBarkTown_NeighborsHouse/map.bin"

	.align 2
NewBarkTown_NeighborsHouse_Layout::
	.4byte 11
	.4byte 9
	.4byte NewBarkTown_NeighborsHouse_MapBorder
	.4byte NewBarkTown_NeighborsHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BrendansMaysHouse

