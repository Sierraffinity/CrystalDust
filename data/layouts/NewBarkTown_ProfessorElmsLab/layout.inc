NewBarkTown_ProfessorElmsLab_MapBorder::
	.incbin "data/layouts/NewBarkTown_ProfessorElmsLab/border.bin"

NewBarkTown_ProfessorElmsLab_MapBlockdata::
	.incbin "data/layouts/NewBarkTown_ProfessorElmsLab/map.bin"

	.align 2
NewBarkTown_ProfessorElmsLab_Layout::
	.4byte 13
	.4byte 14
	.4byte NewBarkTown_ProfessorElmsLab_MapBorder
	.4byte NewBarkTown_ProfessorElmsLab_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Lab

