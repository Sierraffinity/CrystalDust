Route29_MapBorder::
	.incbin "data/layouts/Route29/border.bin"

Route29_MapBlockdata::
	.incbin "data/layouts/Route29/map.bin"

	.align 2
Route29_Layout::
	.4byte 72
	.4byte 24
	.4byte Route29_MapBorder
	.4byte Route29_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Petalburg

