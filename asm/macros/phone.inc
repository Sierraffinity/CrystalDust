	@ Does nothing.
	.macro phone_nop
	.byte 0x00
	.endm

	@ Ends the phone script.
	.macro phone_end
	.byte 0x01
	.endm

	@ Inits the phone script window and phone call sound.  Also includes the ellipses text and "out of range"
	@ or "go talk to that person" text if the player is the one initiating the phone call.
	.macro phone_initcall
	.byte 0x02
	.endm

	@ Displays a phone message.
	.macro phone_message text:req
	.byte 0x03
	.4byte \text
	.endm

	@ Hangs up the phone. Destroys the text window and plays the hang-up sound effect.
	.macro phone_hangup
	.byte 0x04
	.endm

	@ Sets flag.
	.macro phone_setflag flag:req
	.byte 0x05
	.2byte \flag
	.endm

	@ Clears flag.
	.macro phone_clearflag flag:req
	.byte 0x06
	.2byte \flag
	.endm

	@ Checks if flag is set.
	.macro phone_checkflag flag:req
	.byte 0x07
	.2byte \flag
	.endm

	@ Changes the value of destination to value.
	.macro phone_setvar destination:req, value:req
	.byte 0x08
	.2byte \destination
	.2byte \value
	.endm

	@ Changes the value of destination by adding value to it. Overflow is not prevented (0xFFFF + 1 = 0x0000).
	.macro phone_addvar destination:req, value:req
	.byte 0x09
	.2byte \destination
	.2byte \value
	.endm

	@ Changes the value of destination by subtracting value to it. Overflow is not prevented (0x0000 - 1 = 0xFFFF).
	.macro phone_subvar destination:req, value:req
	.byte 0x0A
	.2byte \destination
	.2byte \value
	.endm

	@ Copies the value of source into destination.
	.macro phone_copyvar destination:req, source:req
	.byte 0x0B
	.2byte \destination
	.2byte \source
	.endm

	@ Stores a random integer between 0 and limit in variable 0x800D (LASTRESULT).
	.macro phone_random limit:req
	.byte 0x0C
	.2byte \limit
	.endm

	@ Adds a quantity amount of item index to the player's PC. Both arguments can be variables.
	.macro phone_givepcitem index:req, quantity:req
	.byte 0x0D
	.2byte \index
	.2byte \quantity
	.endm

	@ Checks for quantity amount of item index in the player's PC. Both arguments can be variables.
	.macro phone_checkpcitem index:req, quantity:req
	.byte 0x0E
	.2byte \index
	.2byte \quantity
	.endm

	@ Adds decoration to the player's PC. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro phone_givedecoration decoration:req
	.byte 0x0F
	.2byte \decoration
	.endm

	@ Removes a decoration from the player's PC. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro phone_takedecoration decoration:req
	.byte 0x10
	.2byte \decoration
	.endm

	@ Checks for decoration in the player's PC. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro phone_checkdecor decoration:req
	.byte 0x11
	.2byte \decoration
	.endm

	@ Checks if the player has enough space in their PC to hold decoration. Sets variable 0x800D (LASTRESULT) to 0x0001 if there is room, or 0x0000 is there is no room. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro phone_checkdecorspace decoration:req
	.byte 0x12
	.2byte \decoration
	.endm

	@ Blocks script execution for duration (frames)
	.macro phone_delay frames:req
	.byte 0x13
	.2byte \frames
	.endm

	@ Jumps to destination and continues script execution from there.
	.macro phone_goto destination:req
	.byte 0x14
	.4byte \destination
	.endm

	@ Jumps to destination and continues script execution from there. The location of the calling script is remembered and can be returned to later.
	.macro phone_call destination:req
	.byte 0x15
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), jumps to destination and continues script execution from there.
	.macro phone_goto_if condition:req, destination:req
	.byte 0x16
	.byte \condition
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), calls destination.
	.macro phone_call_if condition:req, destination:req
	.byte 0x17
	.byte \condition
	.4byte \destination
	.endm

	@ Jumps back to after the last-executed call statement, and continues script execution from there.
	.macro phone_return
	.byte 0x18
	.endm

	@ Sets the values of variables 0x8000, 0x8001, and 0x8002 to the current hour, minute, and second. In FRLG, this command sets those variables to zero.
	.macro phone_gettime
	.byte 0x19
	.endm

	@ Blocks script execution until the player presses A or B button.
	.macro phone_waitbuttonpress
	.byte 0x1A
	.endm

	@ Ends the phone script if phone_init was unsuccessful, due to the phone contact not being available for call.
	.macro phone_end_if_not_available
	.byte 0x1B
	.endm

	@ Calls a native C function.
	.macro phone_callnativecontext func:req
	.byte 0x1C
	.4byte \func
	.endm

	@ Shows a yes/no box.
	.macro phone_yesnobox
	.byte 0x1D
	.endm

	@ Compares the values of script banks a and b, after forcing the values to bytes.
	.macro phone_compare_local_to_local byte1:req, byte2:req
	.byte 0x1E
	.byte \byte1
	.byte \byte2
	.endm

	@ Compares the least-significant byte of the value of script bank a to a fixed byte value (b).
	.macro phone_compare_local_to_value a:req, b:req
	.byte 0x1F
	.byte \a
	.byte \b
	.endm

	@ Compares the least-significant byte of the value of script bank a to the byte located at offset b.
	.macro phone_compare_local_to_addr a:req, b:req
	.byte 0x20
	.byte \a
	.4byte \b
	.endm

	@ Compares the byte located at offset a to the least-significant byte of the value of script bank b.
	.macro phone_compare_addr_to_local a:req, b:req
	.byte 0x21
	.4byte \a
	.byte \b
	.endm

	@ Compares the byte located at offset a to a fixed byte value (b).
	.macro phone_compare_addr_to_value a:req, b:req
	.byte 0x22
	.4byte \a
	.byte \b
	.endm

	@ Compares the byte located at offset a to the byte located at offset b.
	.macro phone_compare_addr_to_addr a:req, b:req
	.byte 0x23
	.4byte \a
	.4byte \b
	.endm

	@ Compares the value of `var` to a fixed word value (b).
	.macro phone_compare_var_to_value var:req, value:req
	.byte 0x24
	.2byte \var
	.2byte \value
	.endm

	@ Compares the value of `var1` to the value of `var2`.
	.macro phone_compare_var_to_var var1:req, var2:req
	.byte 0x25
	.2byte \var1
	.2byte \var2
	.endm

	@ Generic compare macro which attempts to deduce argument types based on their values
	@ Any values between 0x4000 to 0x4FFF and 0x8000 to 0x8FFF are considered event variable identifiers
	.macro phone_compare arg1:req, arg2:req
		.if ((\arg1 >> 12) == 4 || (\arg1 >> 12) == 8) && ((\arg2 >> 12) == 4 || (\arg2 >> 12) == 8)
			phone_compare_var_to_var \arg1, \arg2
		.elseif ((\arg1 >> 12) == 4 || (\arg1 >> 12) == 8) && (\arg2 >= 0 && \arg2 <= 0xFFFF)
			phone_compare_var_to_value \arg1, \arg2
		.else
			.error "Invalid arguments for 'phone_compare'"
		.endif
	.endm

	@ Gets the current map type and mapsec and stores them into VAR_0x8004 and VAR_0x8005.
	.macro phone_getmapinfo
	.byte 0x26
	.endm

	@ Gets a map name and stores it into a string variable.
	.macro phone_buffermapsecname out:req, mapsec:req
	.byte 0x27
	.byte \out
	.2byte \mapsec
	.endm

	@ This command will check if the player has money >= value; VAR_RESULT is set to TRUE if the player has enough money, or FALSE if they do not.
	.macro phone_checkbankedmoney value:req
	.byte 0x28
	.4byte \value
	.endm

	@ Converts the value of banked money to a decimal string, and writes that string to the specified buffer.
	.macro phone_bufferbankedmoney out:req
	.byte 0x29
	.byte \out
	.endm

	@ Converts the value of input to a decimal string, and writes that string to the specified buffer.
	.macro phone_buffernumberstring out:req, input:req
	.byte 0x2a
	.byte \out
	.2byte \input
	.endm

	@ Writes the name of the specified (box) PC box to the specified buffer.
	.macro phone_bufferboxname out:req, box:req
	.byte 0x2b
	.byte \out
	.2byte \box
	.endm

	

@ Supplementary

	.macro phone_goto_if_unset flag:req, dest:req
	phone_checkflag \flag
	phone_goto_if 0, \dest
	.endm

	.macro phone_goto_if_set flag:req, dest:req
	phone_checkflag \flag
	phone_goto_if 1, \dest
	.endm

	.macro phone_goto_if_lt dest:req @ LESS THAN
	phone_goto_if 0, \dest
	.endm	

	.macro phone_goto_if_eq dest:req @ EQUAL
	phone_goto_if 1, \dest
	.endm

	.macro phone_goto_if_gt dest:req @ GREATER THAN
	phone_goto_if 2, \dest
	.endm

	.macro phone_goto_if_le dest:req @ LESS THAN OR EQUAL
	phone_goto_if 3, \dest
	.endm

	.macro phone_goto_if_ge dest:req @ GREATER THAN OR EQUAL
	phone_goto_if 4, \dest
	.endm

	.macro phone_goto_if_ne dest:req @ NOT EQUAL
	phone_goto_if 5, \dest
	.endm

	.macro phone_call_if_unset flag:req, dest:req
	phone_checkflag \flag
	phone_call_if 0, \dest
	.endm

	.macro phone_call_if_set flag:req, dest:req
	phone_checkflag \flag
	phone_call_if 1, \dest
	.endm

	.macro phone_call_if_lt dest:req @ LESS THAN
	phone_call_if 0, \dest
	.endm	

	.macro phone_call_if_eq dest:req @ EQUAL
	phone_call_if 1, \dest
	.endm

	.macro phone_call_if_gt dest:req @ GREATER THAN
	phone_call_if 2, \dest
	.endm

	.macro phone_call_if_le dest:req @ LESS THAN OR EQUAL
	phone_call_if 3, \dest
	.endm

	.macro phone_call_if_ge dest:req @ GREATER THAN OR EQUAL
	phone_call_if 4, \dest
	.endm

	.macro phone_call_if_ne dest:req @ NOT EQUAL
	phone_call_if 5, \dest
	.endm

	.macro phone_switch var:req
	phone_copyvar VAR_0x8000, \var
	.endm

	.macro phone_case condition:req, dest:req
	phone_compare VAR_0x8000, \condition
	phone_goto_if_eq \dest
	.endm

	.macro phone_stdcall text:req
	phone_initcall
	phone_end_if_not_available
	phone_message \text
	phone_waitbuttonpress
	phone_hangup
	.endm
