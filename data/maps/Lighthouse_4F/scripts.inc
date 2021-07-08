Lighthouse_4F_MapScripts::
	.byte 0


Lighthouse_4F_EventScript_LassConnie::
	trainerbattle_single TRAINER_CONNIE, Lighthouse_4F_EventScript_LassConnie_Text_0, Lighthouse_4F_EventScript_LassConnie_Text_1
	msgbox Lighthouse_4F_EventScript_LassConnie_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_4F_Eventscript_SailorKent::
	trainerbattle_single TRAINER_KENT, Lighthouse_4F_Eventscript_SailorKent_Text_0, Lighthouse_4F_Eventscript_SailorKent_Text_1
	msgbox Lighthouse_4F_Eventscript_SailorKent_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_4F_EventScript_LassConnie_Text_0:
	.string "JASMINE is this city's GYM LEADER.\nI mean to bring her back with me.\pNobody had better get in my way!$"

Lighthouse_4F_EventScript_LassConnie_Text_1:
	.string "Aaack! My POKéMON!$"

Lighthouse_4F_EventScript_LassConnie_Text_2:
	.string "Right. Anybody would be worried if\nhis or her own POKéMON were hurt.\pI'll pray for the POKéMON here, so\nJASMINE can come back to the GYM.$"

Lighthouse_4F_Eventscript_SailorKent_Text_0:
	.string "JASMINE must be worried sick about\nthe POKéMON here.\pShe won't even smile these days.$"

Lighthouse_4F_Eventscript_SailorKent_Text_1:
	.string "I can't manage a smile either…$"

Lighthouse_4F_Eventscript_SailorKent_Text_2:
	.string "Speaking of sick, I've heard there's\na good PHARMACY in CIANWOOD.$"
