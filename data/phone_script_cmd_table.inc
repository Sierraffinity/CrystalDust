	.align 2
gPhoneScriptCmdTable::
	.4byte PhoneScrCmd_nop
	.4byte PhoneScrCmd_end
	.4byte PhoneScrCmd_initcall
	.4byte PhoneScrCmd_message
	.4byte PhoneScrCmd_hangup
	.4byte PhoneScrCmd_setflag
	.4byte PhoneScrCmd_clearflag
	.4byte PhoneScrCmd_checkflag
	.4byte PhoneScrCmd_setvar
	.4byte PhoneScrCmd_addvar
	.4byte PhoneScrCmd_subvar
	.4byte PhoneScrCmd_copyvar
	.4byte PhoneScrCmd_random
	.4byte PhoneScrCmd_givepcitem
	.4byte PhoneScrCmd_checkpcitem
	.4byte PhoneScrCmd_givedecoration
	.4byte PhoneScrCmd_takedecoration
	.4byte PhoneScrCmd_checkdecorspace
	.4byte PhoneScrCmd_checkdecor
	.4byte PhoneScrCmd_delay
	.4byte PhoneScrCmd_goto
	.4byte PhoneScrCmd_call
	.4byte PhoneScrCmd_goto_if
	.4byte PhoneScrCmd_call_if
	.4byte PhoneScrCmd_return
	.4byte PhoneScrCmd_gettime
	.4byte PhoneScrCmd_waitbuttonpress
	.4byte PhoneScrCmd_end_if_not_available
	.4byte PhoneScrCmd_callnativecontext

gPhoneScriptCmdTableEnd::
	.4byte PhoneScrCmd_nop
