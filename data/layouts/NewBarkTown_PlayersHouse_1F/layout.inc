NewBarkTown_PlayersHouse_1F_MapBorder::
	.incbin "data/layouts/NewBarkTown_PlayersHouse_1F/border.bin"

NewBarkTown_PlayersHouse_1F_MapBlockdata::
	.incbin "data/layouts/NewBarkTown_PlayersHouse_1F/map.bin"

	.align 2
NewBarkTown_PlayersHouse_1F_Layout::
	.4byte 12
	.4byte 10
	.4byte NewBarkTown_PlayersHouse_1F_MapBorder
	.4byte NewBarkTown_PlayersHouse_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BrendansMaysHouse

