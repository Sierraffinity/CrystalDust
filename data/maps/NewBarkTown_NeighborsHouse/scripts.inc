NewBarkTown_NeighborsHouse_MapScripts:: @ 81F9296
	.byte 0

NewBarkTown_NeighborsHouse_EventScript_Girl::
	msgbox NewBarkTown_NeighborsHouse_Text_Girl, MSGBOX_NPC
	end

NewBarkTown_NeighborsHouse_EventScript_Woman::
	msgbox NewBarkTown_NeighborsHouse_Text_Woman, MSGBOX_NPC
	end

NewBarkTown_NeighborsHouse_Text_Girl:
	.string "PIKACHU is an evolved POKéMON. I\n"
	.string "was amazed by PROF. ELM's findings.\p"
	.string "He's so famous for his research on\n"
	.string "POKéMON evolution.\p"
	.string "…sigh…\p"
	.string "I wish I could be a researcher like\n"
	.string "him…$"

NewBarkTown_NeighborsHouse_Text_Woman:
	.string "{PLAYER}, have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF. ELM's assistant.\l"
	.string "She really loves POKéMON!\p"
	.string "But then, so do I!$"
