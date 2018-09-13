STD_REVERB = 50
sound/songs/example.s:  %.s: %.mid
	cd $(@D) && ../../$(MID) $(<F) -G000 -R$(STD_REVERB)
