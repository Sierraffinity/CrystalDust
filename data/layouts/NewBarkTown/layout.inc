NewBarkTown_MapBorder::
	.incbin "data/layouts/NewBarkTown/border.bin"

NewBarkTown_MapBlockdata::
	.incbin "data/layouts/NewBarkTown/map.bin"

	.align 2
NewBarkTown_Layout::
	.4byte 26
	.4byte 22
	.4byte NewBarkTown_MapBorder
	.4byte NewBarkTown_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Petalburg

