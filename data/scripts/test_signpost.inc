Text_ThisIsATestSignpostMsg::
	.string "This is a test message.\n"
	.string "This is a signpost.$"

EventScript_TestSignpostMsg::
	msgbox Text_ThisIsATestSignpostMsg, MSGBOX_SIGN
	end
Text_ObjectEventMsg::
	.string "Object event.$"

EventScript_TestObjectEventMsg:: @ 82C8436
	msgbox Text_ObjectEventMsg, MSGBOX_NPC
	end
