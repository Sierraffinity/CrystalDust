GoldenrodCity_MagnetTrainStation_MapScripts::
	.byte 0


GoldenrodCity_MagnetTrainStation_Officer::
	lock
	faceplayer
	msgbox GoldenrodCity_MagnetTrainStation_Officer_Text_0
	release
	return


GoldenrodCity_MagnetTrainStation_Gentleman::
	msgbox GoldenrodCity_MagnetTrainStation_Gentleman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_MagnetTrainStation_Officer_Text_0:
	.string "The train hasn't come in…\p"
	.string "I know! I'll carry the passengers\n"
	.string "on my back!\p"
	.string "…That won't work.$"

GoldenrodCity_MagnetTrainStation_Gentleman_Text_0:
	.string "I'm the PRESIDENT.\p"
	.string "My dream was to build a train that\n"
	.string "is faster than any POKéMON.\p"
	.string "It really brings JOHTO much closer\n"
	.string "to KANTO.$"
