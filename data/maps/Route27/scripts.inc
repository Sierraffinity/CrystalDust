Route27_MapScripts::
	.byte 0


Route27_Eventscript_TohjoFallsSign::
	msgbox Route27_Eventscript_TohjoFallsSign_Text_0, MSGBOX_SIGN
	end


Route27_Eventscript_CooltrainerMegan::
	trainerbattle_single TRAINER_MEGAN, Route27_Eventscript_CooltrainerMegan_Text_0, Route27_Eventscript_CooltrainerMegan_Text_1
	msgbox Route27_Eventscript_CooltrainerMegan_Text_2, MSGBOX_AUTOCLOSE
	end


Route27_Eventscript_CooltrainerBlake::
	trainerbattle_single TRAINER_BLAKE, Route27_Eventscript_CooltrainerBlake_Text_0, Route27_Eventscript_CooltrainerBlake_Text_1
	msgbox Route27_Eventscript_CooltrainerBlake_Text_2, MSGBOX_AUTOCLOSE
	end


Route27_Eventscript_CooltrainerBrian::
	trainerbattle_single TRAINER_BRIAN, Route27_Eventscript_CooltrainerBrian_Text_0, Route27_Eventscript_CooltrainerBrian_Text_1
	msgbox Route27_Eventscript_CooltrainerBrian_Text_2, MSGBOX_AUTOCLOSE
	end


Route27_Eventscript_BirdKeeperJose::
	trainerbattle_single TRAINER_JOSE_1, Route27_Eventscript_BirdKeeperJose_Text_0, Route27_Eventscript_BirdKeeperJose_Text_1
	msgbox Route27_Eventscript_BirdKeeperJose_Text_2, MSGBOX_AUTOCLOSE
	end


Route27_Eventscript_PsychicGilbert::
	trainerbattle_single TRAINER_GILBERT, Route27_Eventscript_PsychicGilbert_Text_0, Route27_Eventscript_PsychicGilbert_Text_1
	msgbox Route27_Eventscript_PsychicGilbert_Text_2, MSGBOX_AUTOCLOSE
	end


Route27_Eventscript_CooltrainerReena::
	trainerbattle_single TRAINER_REENA_1, Route27_Eventscript_CooltrainerReena_Text_0, Route27_Eventscript_CooltrainerReena_Text_1
	msgbox Route27_Eventscript_CooltrainerReena_Text_2, MSGBOX_AUTOCLOSE
	end


Route27_Eventscript_TohjoFallsSign_Text_0:
	.string "TOHJO FALLS\nTHE LINK BETWEEN KANTO AND JOHTO$"

Route27_Eventscript_CooltrainerMegan_Text_0:
	.string "It's rare to see anyone come here.\nAre you training on your own?$"

Route27_Eventscript_CooltrainerMegan_Text_1:
	.string "Oh! You're really strong!$"

Route27_Eventscript_CooltrainerMegan_Text_2:
	.string "I'm checking out pre- and post-\nevolution POKéMON.\pEvolution really does make POKéMON\nstronger.\pBut evolved forms also learn moves\nlater on.$"

Route27_Eventscript_CooltrainerBlake_Text_0:
	.string "You look pretty strong.\nLet me battle you!$"

Route27_Eventscript_CooltrainerBlake_Text_1:
	.string "Yow!$"

Route27_Eventscript_CooltrainerBlake_Text_2:
	.string "If you prevail on this harsh trek,\nthe truth will be revealed!\pHeh, sorry. I just wanted to say\nsomething cool.$"

Route27_Eventscript_CooltrainerBrian_Text_0:
	.string "Hm? You're good, aren't you?$"

Route27_Eventscript_CooltrainerBrian_Text_1:
	.string "Just as I thought!$"

Route27_Eventscript_CooltrainerBrian_Text_2:
	.string "A good TRAINER can recognize other\ngood TRAINERS.$"

Route27_Eventscript_BirdKeeperJose_Text_0:
	.string "Tweet! Tweet! Tetweet!$"

Route27_Eventscript_BirdKeeperJose_Text_1:
	.string "Tweet!$"

Route27_Eventscript_BirdKeeperJose_Text_2:
	.string "BIRD KEEPERS like me mimic bird\nwhistles to command POKéMON.$"

Route27_Eventscript_PsychicGilbert_Text_0:
	.string "Don't say a thing!\nLet me guess what you're thinking.\pMmmmmmm…\pI got it! You're on the POKéMON\nLEAGUE challenge!$"

Route27_Eventscript_PsychicGilbert_Text_1:
	.string "You're too much!$"

Route27_Eventscript_PsychicGilbert_Text_2:
	.string "With your skills, you'll do well at\nthe LEAGUE.\pThat's what my premonition says.$"

Route27_Eventscript_CooltrainerReena_Text_0:
	.string "You shouldn't underestimate the wild\nPOKéMON in these parts.$"

Route27_Eventscript_CooltrainerReena_Text_1:
	.string "Oh! You're much too strong!$"

Route27_Eventscript_CooltrainerReena_Text_2:
	.string "You're just a kid, but you're not to\nbe underestimated either.$"
