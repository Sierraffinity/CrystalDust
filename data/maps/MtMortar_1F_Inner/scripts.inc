MtMortar_1F_Inner_MapScripts::
	.byte 0


MtMortar_1F_Inner_Eventscript_SuperNerdMarkus::
	trainerbattle_single TRAINER_MARKUS, MtMortar_1F_Inner_Eventscript_SuperNerdMarkus_Text_0, MtMortar_1F_Inner_Eventscript_SuperNerdMarkus_Text_1
	msgbox MtMortar_1F_Inner_Eventscript_SuperNerdMarkus_Text_2, MSGBOX_AUTOCLOSE
	end


MtMortar_1F_Inner_Eventscript_PokemaniacMiller::
	trainerbattle_single TRAINER_MILLER, MtMortar_1F_Inner_Eventscript_PokemaniacMiller_Text_0, MtMortar_1F_Inner_Eventscript_PokemaniacMiller_Text_1
	msgbox MtMortar_1F_Inner_Eventscript_PokemaniacMiller_Text_2, MSGBOX_AUTOCLOSE
	end


MtMortar_1F_Inner_Eventscript_SuperNerdMarkus_Text_0:
	.string "Hey! HUGH!$"

MtMortar_1F_Inner_Eventscript_SuperNerdMarkus_Text_1:
	.string "I mistook you for someone else…$"

MtMortar_1F_Inner_Eventscript_SuperNerdMarkus_Text_2:
	.string "I came to explore MT. MORTAR, but I\ngot separated from my partner…\pDid you run into a TRAINER who uses\na SEADRA that knows WATERFALL?$"

MtMortar_1F_Inner_Eventscript_PokemaniacMiller_Text_0:
	.string "I'm not losing this time!$"

MtMortar_1F_Inner_Eventscript_PokemaniacMiller_Text_1:
	.string "I lost to some kid…?$"

MtMortar_1F_Inner_Eventscript_PokemaniacMiller_Text_2:
	.string "A while back, this karate dude wanted\nto battle. He was ridiculously good.\pHe just thrashed us silly.\pHe went in deeper saying it was for\nhis training. I wonder how he is?$"
