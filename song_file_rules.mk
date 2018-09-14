STD_REVERB = 50
sound/songs/mus_kantorival.s: %.s: %.mid
	cd $(@D) && ../../$(MID) $(<F) -G 509 -R $(STD_REVERB)
