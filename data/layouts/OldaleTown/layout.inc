OldaleTown_MapBorder::
	.incbin "data/layouts/OldaleTown/border.bin"

OldaleTown_MapBlockdata::
	.incbin "data/layouts/OldaleTown/map.bin"

	.align 2
OldaleTown_Layout::
	.4byte 60
	.4byte 30
	.4byte OldaleTown_MapBorder
	.4byte OldaleTown_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Petalburg

