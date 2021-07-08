Route26_House2_MapScripts::
	.byte 0


Route26_House2_Eventscript_Book::
	msgbox Route26_House2_Eventscript_Book_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route26_House2_Eventscript_Book_2
	release
	end

Route26_House2_Eventscript_Book_2:
	msgbox Route26_House2_Eventscript_Book_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route26_House2_Eventscript_Book_5
	release
	end

Route26_House2_Eventscript_Book_5:
	msgbox Route26_House2_Eventscript_Book_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Route26_House2_Eventscript_Book_Text_0:
	.string "There's something written here.\nRead it?$"

Route26_House2_Eventscript_Book_Text_1:
	.string "To my brothers and sisters:\pWe take pride in serving POKéMON\nTRAINERS.\pWhen TRAINERS talk to you, give them\nsomething useful.\pLove,\nMONICA\pKeep reading?$"

Route26_House2_Eventscript_Book_Text_2:
	.string "MONDAY, MONICA\nROUTE 40\pTUESDAY, TUSCANY\nROUTE 29\pWEDNESDAY, WESLEY\nLAKE OF RAGE\pTHURSDAY, ARTHUR\nROUTE 36\pFRIDAY, FRIEDA\nROUTE 32\pSATURDAY, SANTOS\nBLACKTHORN CITY\pSUNDAY, SUNNY\nROUTE 37$"
