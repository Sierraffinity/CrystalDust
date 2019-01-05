PetalburgCity_MapBorder::
	.incbin "data/layouts/PetalburgCity/border.bin"

PetalburgCity_MapBlockdata::
	.incbin "data/layouts/PetalburgCity/map.bin"

	.align 2
PetalburgCity_Layout::
	.4byte 48
	.4byte 40
	.4byte PetalburgCity_MapBorder
	.4byte PetalburgCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Dewford

