NewBarkTown_HirosHouse_2F_MapBorder::
	.incbin "data/layouts/NewBarkTown_HirosHouse_2F/border.bin"

NewBarkTown_HirosHouse_2F_MapBlockdata::
	.incbin "data/layouts/NewBarkTown_HirosHouse_2F/map.bin"

	.align 2
NewBarkTown_HirosHouse_2F_Layout::
	.4byte 11
	.4byte 9
	.4byte NewBarkTown_HirosHouse_2F_MapBorder
	.4byte NewBarkTown_HirosHouse_2F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BrendansMaysHouse

