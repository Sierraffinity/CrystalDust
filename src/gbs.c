/*
 * gbs.c
 *
 *  Created on: 21 May 2018
 *      Author: Jambo51
 *  Revised for M4A integration in: February 2020
 *      Author: huderlem
 */

#include "global.h"
#include "gba/m4a_internal.h"
#include "gba/gbs_internal.h"
#include "m4a.h"

bool8 gShouldReloadWavePattern;

const u16 CGBFreq[] = {
	8013, 7566, 7144, 6742,
	6362, 6005, 5666, 5346,
	5048, 4766, 4499, 4246
};

inline u32 LoadUInt(u8 *source, u32 offset)
{
	return *(source + offset) | (*(source + offset + 1) << 8) | (*(source + offset + 2) << 16) | (*(source + offset + 3) << 24);
}

inline u8 *LoadUIntPointer(u8 *source, u32 offset)
{
	return (u8 *)LoadUInt(source, offset);
}

inline u16 LoadUShortNumber(u8 *source, u32 offset)
{
	return *(source + offset) | (*(source + offset + 1) << 8);
}

inline u16 U16LittleEndianToBigEndian(u16 input)
{
	u16 temp = (input & 0xFF) << 8;
	return (input >> 8) | temp;
}

inline vu16 *ToneTrackControl()
{
	return (vu16 *)(REG_ADDR_NR10);
}

inline vu16 *WaveTrackControl()
{
	return (vu16 *)(REG_ADDR_NR30);
}

inline vu16 *NoiseTrackControl()
{
	return (vu16 *)(REG_ADDR_NR41);
}

inline vu16 *SoundControl()
{
	return (vu16 *)(REG_ADDR_NR50);
}

inline bool32 ShouldRenderSound(int trackID)
{
	return gUsedGBChannels[trackID] == FALSE;
}

inline bool32 ShouldRenderWaveChannel()
{
	return ShouldRenderSound(2);
}

inline bool32 ShouldRenderNoiseChannel()
{
	return ShouldRenderSound(3);
}

void SetMasterVolumeFromFade(u32 volX)
{
	// Respect the master M4A fade control.
	u32 masterVolume;
	vu16 *control = SoundControl();
	if (volX != 0)
		masterVolume = volX / 8;
	else
		masterVolume = 7;

	if (masterVolume > 7)
		masterVolume = 7;

	if ((control[0] & 0x7) != masterVolume)
	{
		control[0] &= 0xFF00;
		control[0] |= (masterVolume << 4) | masterVolume;
	}
}

u16 CalculateLength(u8 frameDelay, u16 tempo, u8 bitLength, u16 previousLeftover)
{
	return ((frameDelay * (bitLength + 1)) * tempo) + previousLeftover;
}

u16 ToneTrackCalculatePitch(u8 commandID, s8 keyShift, u8 octave, u16 tone)
{
	s16 note = ((commandID & 0xF0) >> 4) - 1;
	note += keyShift;
	while (note < 0)
	{
		note += 12;
		octave--;
	}
	while (note > 11)
	{
		note -= 12;
		octave++;
	}
	return (u16)((2048 - (CGBFreq[note] >> (2 + octave))) + tone);
}

void ExecuteToneModifications(u8 commandID, u16 tempo, struct ToneTrack *track)
{
	u16 pitch = 0;
	u16 activationValue = 0;
	u16 secondValue = 0;
	u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);
	track->noteLength1 = (noteLength & 0xFF00) >> 8;
	track->noteLength2 = noteLength & 0xFF;
	if ((commandID & 0xF0) != 0)
	{
		pitch = ToneTrackCalculatePitch(commandID, track->keyShift, track->currentOctave, track->tone);
		activationValue = pitch | 0x8000;
		secondValue = (track->currentVoice << 6) | (track->fadeSpeed << 8) | (((track->fadeSpeed == 0) ? 0 : track->fadeDirection) << 11) | (track->velocity << 12);
	}
	track->pitch = pitch;
	track->nextInstruction++;
	if (ShouldRenderSound(track->trackID - 1))
	{
		vu16 *control = ToneTrackControl();
		if (track->trackID == 2)
			control[4] = secondValue;
		else
			control[1] = secondValue;

		control[((track->trackID - 1) * 4) + 2] = activationValue;

	}
}

u8 ToneExecuteCommands(u8 commandID, struct MusicPlayerInfo *info, struct ToneTrack *track)
{
	u8 commandLength = 1;
	u8 byte2 = 0;
	if (commandID >= SetOctave7 && commandID < SetOctave0)
	{
		track->currentOctave = 7 - (commandID & 7);
	}
	else
	{
		commandID -= SetOctave0;
		switch (commandID)
		{
			case SetNoteAttributesAndLength:
			{
				byte2 = track->nextInstruction[1];
				track->frameDelay = ((byte2 == 0 || byte2 > 0xF) ? 0xC : byte2);
				byte2 = track->nextInstruction[2];
				track->velocity = (byte2 & 0xF0) >> 4;
				track->fadeSpeed = byte2 & 0x7;
				track->fadeDirection = (byte2 & 0x8) >> 3;
				commandLength = 3;
				break;
			}
			case SetKeyShift:
			{
				s8 thisKeyShift = track->nextInstruction[1];
				track->keyShift = (-12 * ((thisKeyShift & 0x10) >> 4)) + (thisKeyShift & 0xF);
				commandLength = 2;
				break;
			}
			case SetTempo:
				if (track->trackID == 1)
				{
					// Artificially subtract 2 from the real tempo value to account for engine differences.
					// Using the BGB emulator as a source of truth, Subtracting 2 will run about 0.2 seconds fast
					// after a minute of playback.  Subtracting 1 will run about 0.2 seconds slow.
					info->gbsTempo = U16LittleEndianToBigEndian(LoadUShortNumber(track->nextInstruction, 1)) - 2;
				}
				commandLength = 3;
				break;
			case SetDutyCycle: case SetDutyCycle2:
				track->currentVoice = track->nextInstruction[1];
				commandLength = 2;
				break;
			case SetNoteAttributes:
			{
				byte2 = track->nextInstruction[1];
				track->velocity = (byte2 & 0xF0) >> 4;
				track->fadeSpeed = byte2 & 0x7;
				track->fadeDirection = (byte2 & 0x8) >> 3;
				commandLength = 2;
				break;
			}
			case Arpeggiate:
			{
				byte2 = track->nextInstruction[1];
				if (byte2 != 0)
				{
					track->statusFlags[ArpeggiationActivation] = TRUE;
					track->arpeggiationDelayCount = (byte2 & 0xF0) >> 4;
					track->arpeggiationCountdown = track->arpeggiationDelayCount;
					track->statusFlags[ArpeggiationStatus] = FALSE;
					track->arpeggiationVoice = byte2 & 0x3;
				}
				else
				{
					track->statusFlags[ArpeggiationActivation] = FALSE;
				}
				commandLength = 2;
				break;
			}
			case PitchBend:
				track->statusFlags[PitchBendActivation] = TRUE;
				// Note that this is incomplete and requires research into how pitch
				// bends are handled in the original engine
				//u8 byte = nextInstruction[2];
				commandLength = 3;
				break;
			case Portamento:
				// No data for this as yet as it is a completely custom effect
				// At least it is in terms of this engine, since the
				// portamento effect is not present in RBY or GSC
				track->statusFlags[PortamentoActivation] = TRUE;
				track->portamentoDelay = track->nextInstruction[1];
				track->portamentoSpeed = track->nextInstruction[2];
				track->portamentoTarget = ToneTrackCalculatePitch(track->nextInstruction[3], track->keyShift, track->currentOctave, track->tone);
				commandLength = 4;
				break;
			case SetModulation:
			{
				byte2 = track->nextInstruction[2];
				if (byte2 != 0)
				{
					track->modulationDelay = track->nextInstruction[1] & 0x3F;
					track->modulationMode = (track->nextInstruction[1] & 0xC0) >> 6;
					track->modulationDepth = (byte2 & 0xF0) >> 4;
					track->modulationSpeed = byte2 & 0xF;
					track->statusFlags[ModulationActivation] = TRUE;
				}
				else
				{
					track->statusFlags[ModulationActivation] = FALSE;
				}
				commandLength = 3;
				break;
			}
			case SetChannelVolume:
				if (track->channelVolume != track->nextInstruction[1])
				{
					track->channelVolume = track->nextInstruction[1];
					if (ShouldRenderSound(track->trackID - 1))
					{
						vu16 *control = SoundControl();
						control[0] = (control[0] & 0xFF00) | track->channelVolume;
					}
				}
				commandLength = 2;
				break;
			case SetTone:
				track->tone = U16LittleEndianToBigEndian(LoadUShortNumber(track->nextInstruction, 1));
				commandLength = 3;
				break;
			case Pan:
			{
				u8 byte = track->nextInstruction[1];
				track->pan = (byte == 0) ? 0xFF : byte;
				commandLength = 2;
				break;
			}
			case SetHostTempo:
			{
				// It is advised that this function not be used since it could mess with
				// playback in unexpected ways, however, I felt it would be fun
				// to include it all the same. The GBS Tempo should always be 150
				if (track->trackID == 1)
				{
					u32 tempo = track->nextInstruction[1] << 1;
					info->tempoD = tempo;
					tempo *= info->tempoU;
					tempo >>= 8;
					info->tempoI = tempo;
				}
				commandLength = 2;
				break;
			}
			case JumpIf:
				commandLength = 6;
				break;
			case Jump:
				track->nextInstruction = LoadUIntPointer(track->nextInstruction, 1);
				commandLength = 0;
				break;
			case Goto:
				if (track->returnLocation == 0)
				{
					if (track->nextInstruction[1] == 0 || track->nextInstruction[1] - 1 > track->loopCounter)
					{
						if (track->nextInstruction[1] != 0)
						{
							track->loopCounter++;
						}
						track->nextInstruction = LoadUIntPointer(track->nextInstruction, 2);
						commandLength = 0;
					}
					else if (track->nextInstruction[1] != 0 && track->loopCounter != 0)
					{
						track->loopCounter = 0;
						commandLength = 6;
					}
				}
				else
				{
					if (track->nextInstruction[1] == 0 || track->nextInstruction[1] - 1 > track->loopCounter2)
					{
						if (track->nextInstruction[1] != 0)
						{
							track->loopCounter2++;
						}
						track->nextInstruction = LoadUIntPointer(track->nextInstruction, 2);
						commandLength = 0;
					}
					else if (track->nextInstruction[1] != 0 && track->loopCounter2 != 0)
					{
						track->loopCounter2 = 0;
						commandLength = 6;
					}
				}
				break;
			case Call:
				if (track->returnLocation == 0)
				{
					track->returnLocation = track->nextInstruction + 5;
					track->nextInstruction = LoadUIntPointer(track->nextInstruction, 1);
				}
				commandLength = 0;
				break;
			case End:
				commandLength = 0;
				if (track->returnLocation == 0)
				{
					return 0xFF;
				}
				else
				{
					track->nextInstruction = track->returnLocation;
					track->returnLocation = 0;
				}
				break;
		}
	}
	track->nextInstruction += commandLength;
	return track->nextInstruction[0];
}

u16 GetToneModulationPitch(struct ToneTrack *track)
{
	u8 theValue = 0;
	u16 newPitch = track->pitch;
	bool8 flagResult = track->statusFlags[ModulationStatus];
	track->modulationSpeedDelay = track->modulationSpeed;
	switch (track->modulationMode)
	{
		case 0:
		{
			u8 halfValue = track->modulationDepth >> 1;
			if (!flagResult)
			{
				theValue = 1;
				newPitch += (track->modulationDepth - halfValue);
			}
			else
			{
				newPitch -= halfValue;
			}
			break;
		}
		case 1:
			if (!flagResult)
			{
				theValue = 1;
			}
			else
			{
				newPitch -= track->modulationDepth;
			}
			break;
		case 2:
			if (!flagResult)
			{
				theValue = 1;
			}
			else
			{
				newPitch += track->modulationDepth;
			}
			break;
	}
	track->statusFlags[ModulationStatus] = !track->statusFlags[ModulationStatus];
	return newPitch;
}

void ToneModulateTrack(struct ToneTrack *track)
{
	if (track->statusFlags[PitchBendActivation])
	{
		track->pitch += track->pitchBendRate;
	}
	if (track->statusFlags[PortamentoActivation])
	{
		if (track->portamentoCountdown == 0)
		{
			if (track->portamentoTarget != track->pitch)
			{
				if (track->portamentoTarget > track->pitch)
				{
					track->pitch++;
				}
				else
				{
					track->pitch--;
				}
			}
			else
			{
				track->statusFlags[PortamentoActivation] = FALSE;
			}
		}
		else
		{
			track->portamentoCountdown--;
		}
	}
	if (track->modulationCountdown > 0)
	{
		track->modulationCountdown--;
	}
	if (track->statusFlags[ModulationActivation])
	{
		if (track->modulationCountdown == 0)
		{
			if (track->modulationSpeedDelay == 0 && track->pitch != 0 && ShouldRenderSound(track->trackID - 1))
			{
				vu16 *control = ToneTrackControl();
				u16 location = 2 + ((track->trackID - 1) * 4);
				control[location] &= 0x8000;
				control[location] |= GetToneModulationPitch(track);
			}
			else
			{
				track->modulationSpeedDelay--;
			}
		}
	}
}

void ResetModulationArpeggiationCounters(struct ToneTrack *track)
{
	track->modulationCountdown = track->modulationDelay;
	track->statusFlags[ModulationStatus] = FALSE;
	track->modulationSpeedDelay = track->modulationSpeed;
	if (track->modulationCountdown == 0)
	{
		ToneModulateTrack(track);
	}
	track->arpeggiationCountdown = (track->statusFlags[ArpeggiationActivation]) ? track->arpeggiationDelayCount : 0;
	track->statusFlags[ArpeggiationStatus] = FALSE;
	track->statusFlags[PortamentoActivation] = FALSE;
	track->statusFlags[PitchBendActivation] = FALSE;
}

void ArpeggiateTrack(struct ToneTrack *track)
{
	if (track->statusFlags[ArpeggiationActivation])
	{
		if (track->arpeggiationCountdown > 0)
		{
			track->arpeggiationCountdown--;
		}
		else
		{
			u16 location = (track->trackID == 1) ? 1 : 4;
			track->arpeggiationCountdown = track->arpeggiationDelayCount;
			if (ShouldRenderSound(track->trackID - 1))
			{
				vu16 *control = ToneTrackControl();
				control[location] = (control[location] & 0xFF00) | (((track->statusFlags[ArpeggiationStatus]) ? track->currentVoice : track->arpeggiationVoice) << 6);
			}
			track->statusFlags[ArpeggiationStatus] = !track->statusFlags[ArpeggiationStatus];
		}
	}
}

bool16 ToneTrackUpdate(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
	struct ToneTrack *toneTrack = (struct ToneTrack *)track;
	if (toneTrack->noteLength1 < 2)
	{
		u32 commandID = *track->cmdPtr;
		while (commandID >= 0xD0)
		{
			commandID = ToneExecuteCommands(commandID, info, toneTrack);
			if (commandID == 0xFF && toneTrack->returnLocation == 0)
			{
				ExecuteToneModifications(0, info->gbsTempo, toneTrack);
				return FALSE;
			}
		}
		if (commandID != 0xFF)
		{
			ExecuteToneModifications(commandID, info->gbsTempo, toneTrack);
			ResetModulationArpeggiationCounters(toneTrack);
		}
	}
	else
	{
		toneTrack->noteLength1--;
		ToneModulateTrack(toneTrack);
		ArpeggiateTrack(toneTrack);
	}

	if (toneTrack->trackID == 1)
	{
		if (ShouldRenderSound(toneTrack->trackID - 1))
		{
			// TODO: This should be removed when pitch bend is implemented.
			// This code is ensuring no pitch slide values are set, since no
			// pokecrystal engine feature uses pitch slide except pitch bend.
			vu16 *control = ToneTrackControl();
			control[0] = 0;
		}

		SetMasterVolumeFromFade(toneTrack->volX);
	}

	return TRUE;
}

const u16 freq[75] = {
	44,		// C3
	156,
	262,
	363,
	457,
	547,
	631,
	710,
	786,
	854,
	923,
	986,
	1046,	// C4
	1102,
	1155,
	1205,
	1253,
	1297,
	1339,
	1379,
	1417,
	1452,
	1486,
	1517,
	1546,	// C5
	1575,
	1602,
	1627,
	1650,
	1673,
	1694,
	1714,
	1732,
	1750,
	1767,
	1783,
	1798,	// C6
	1812,
	1825,
	1837,
	1849,
	1860,
	1871,
	1881,
	1890,
	1899,
	1907,
	1915,
	1923,	// C7
	1930,
	1936,
	1943,
	1949,
	1954,
	1959,
	1964,
	1969,
	1974,
	1978,
	1982,
	1985,	// C8
	1988,
	1992,
	1995,
	1998,
	2001,
	2004,
	2006,
	2009,
	2011,
	2013,
	2015,
	2017,
	2019,
	2020 // 74898
};

static const u32 wavePatterns[][4] = {
	{ 0xCE8A4602, 0xDCEDFEFF, 0x6587A9CB, 0x11223344 },
	{ 0xCE8A4602, 0xEEFEFFEF, 0x87A9CBDD, 0x11224365 },
	{ 0xEEBD6913, 0xEDFFFFEE, 0xEEFFFFDE, 0x3196DBEE },
	{ 0xCD8A4602, 0xFFDEFEEF, 0x98BADCEE, 0x10325476 },
	{ 0x67452301, 0xF7EECD8A, 0xA8DCEE7F, 0x10325476 },
	{ 0x33221100, 0x11223344, 0xAACCEEFF, 0xEECCAA88 },
	{ 0xCE8A4602, 0x6587A9CB, 0xDCEDFEFF, 0x11223344 },
	{ 0xF587A9C0, 0xDCEDFEFF, 0xF1223344, 0xCE8A4602 },
	{ 0x1F223344, 0xCE8A4600, 0xDCEDFEF8, 0x6587A9CB },
	{ 0x08000011, 0x9A571300, 0x98A9BAB4, 0x21436587 },
	{ 0x2833E221, 0xEAFF22E1, 0x10DC1410, 0x735141E3 },
	{ 0x000000FF, 0x00000000, 0x000000FF, 0x00000000 },
	{ 0x0000FFFF, 0x00000000, 0x0000FFFF, 0x00000000 },
	{ 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000 },
	{ 0xFFFFFFFF, 0x0000FFFF, 0xFFFFFFFF, 0x0000FFFF }
};

void SwitchWavePattern(int patternID)
{
	int i;
	vu16* control = WaveTrackControl();
	if (patternID < ARRAY_COUNT(wavePatterns))
	{
		u32* mainPattern = (u32 *)(REG_ADDR_WAVE_RAM0);
		control[0] = 0x40;
		for (i = 0; i < 4; i++)
			mainPattern[i] = wavePatterns[patternID][i];
		control[0] = 0x0;
	}
}

u16 CalculateWavePitch(u8 commandID, s8 keyShift, u8 octave, u16 tone)
{
	s16 note = (((commandID & 0xF0) >> 4) - 1);
	note += (12 * octave);
	note += keyShift;
	if (note > 75)
	{
		note = 75;
	}
	return (u16)(freq[note] + tone);
}

void ExecuteWaveModifications(u8 commandID, u16 tempo, struct WaveTrack *track)
{
	u16 thisVelocity = 0;
	u16 thisPitch = 0;
	u16 activationValue = 0;
	u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);
	track->noteLength1 = (noteLength & 0xFF00) >> 8;
	track->noteLength2 = noteLength & 0xFF;
	if (commandID & 0xF0)
	{
		track->pitch = CalculateWavePitch(commandID, track->keyShift, track->currentOctave, track->tone);
		thisVelocity = track->velocity << 13;
		thisPitch = track->pitch | 0x8000;
		activationValue = 0x80;
	}
	if (ShouldRenderWaveChannel())
	{
		vu16 *control = WaveTrackControl();
		control[0] = activationValue;
		control[1] = thisVelocity;
		control[2] = thisPitch;
	}
}

void ModulateWaveTrack(struct WaveTrack *track)
{
	if (track->statusFlags[PitchBendActivation])
	{
		track->pitch += track->pitchBendRate;
	}
	if (track->modulationCountdown > 0)
	{
		track->modulationCountdown--;
	}
	if (track->statusFlags[ModulationActivation])
	{
		if (track->modulationCountdown == 0)
		{
			if (track->modulationSpeedDelay == 0 && track->pitch != 0)
			{
				u16 outPitch = track->pitch;
				bool8 flagCheck = track->statusFlags[ModulationStatus];
				track->modulationSpeedDelay = track->modulationSpeed;
				switch (track->modulationMode)
				{
					case 0:
					{
						u8 halfValue = track->modulationDepth >> 1;
						if (flagCheck)
						{
							outPitch += (track->modulationDepth - halfValue);
						}
						else
						{
							outPitch -= halfValue;
						}
						break;
					}
					case 1:
						if (flagCheck)
						{
							outPitch -= track->modulationDepth;
						}
						break;
					case 2:
						if (flagCheck)
						{
							outPitch += track->modulationDepth;
						}
						break;
				}
				track->statusFlags[ModulationStatus] = !track->statusFlags[ModulationStatus];
				if (ShouldRenderWaveChannel())
				{
					vu16 *control = WaveTrackControl();
					control[2] &= 0x8000;
					control[2] |= outPitch;
				}
			}
			else
			{
				track->modulationSpeedDelay--;
			}
		}
	}
}

bool16 ExecuteWaveCommands(u8 commandID, struct WaveTrack *track)
{
	u8 newVoice;
	u8 commandLength = 1;
	if (commandID >= SetOctave7 && commandID < SetOctave0)
	{
		track->currentOctave = 7 - (commandID & 7);
	}
	else
	{
		commandID -= 0xD8;
		switch (commandID)
		{
			case 0:
			{
				u8 theValue = track->nextInstruction[1];
				u8 byte2 = track->nextInstruction[2];
				u8 newVelocity = (byte2 & 0x70) >> 4;
				track->frameDelay = ((theValue == 0 || theValue > 0xF) ? 0xC : theValue);
				if (newVelocity > 4)
				{
					newVelocity = 1;
				}
				track->velocity = newVelocity;
				newVoice = byte2 & 0xF;
				if (track->currentVoice != newVoice && ShouldRenderWaveChannel())
				{
					SwitchWavePattern(newVoice);
				}
				track->currentVoice = newVoice;
				commandLength = 3;
				break;
			}
			case 1:
			{
				s8 thisKeyShift = track->nextInstruction[1];
				track->keyShift = (-12 * ((thisKeyShift & 0x10) >> 4)) + (thisKeyShift & 0xF);
				commandLength = 2;
				break;
			}
			case 3: case 6:
				track->currentVoice = track->nextInstruction[1];
				commandLength = 2;
				break;
			case 4:
			{
				u8 byte2 = track->nextInstruction[1];
				u8 newVelocity = (byte2 & 0x70) >> 4;
				if (newVelocity > 4)
				{
					newVelocity = 1;
				}
				track->velocity = newVelocity;
				newVoice = byte2 & 0xF;
				if (track->currentVoice != newVoice && ShouldRenderWaveChannel())
				{
					SwitchWavePattern(newVoice);
				}
				track->currentVoice = newVoice;
				commandLength = 2;
				break;
			}
			case Arpeggiate:
			{
				commandLength = 2;
				break;
			}
			case 8:
				commandLength = 3;
				break;
			case 9:
			{
				u8 theByte = track->nextInstruction[2];
				if (theByte != 0)
				{
					track->modulationDelay = track->nextInstruction[1] & 0x3F;
					track->modulationMode = (track->nextInstruction[1] & 0xC0) >> 6;
					track->modulationDepth = (theByte & 0xF0) >> 4;
					track->modulationSpeed = theByte & 0xF;
					track->statusFlags[ModulationActivation] = TRUE;
				}
				else
				{
					track->statusFlags[ModulationActivation] = FALSE;
				}
				commandLength = 3;
				break;
			}
			case 14:
				track->tone = U16LittleEndianToBigEndian(LoadUShortNumber(track->nextInstruction, 1));
				commandLength = 3;
				break;
			case 23:
			{
				u8 byte = track->nextInstruction[1];
				track->pan = (byte == 0) ? 0xFF : byte;
				commandLength = 2;
				break;
			}
			case 35:
				commandLength = 6;
				break;
			case 36:
				track->nextInstruction = LoadUIntPointer(track->nextInstruction, 1);
				commandLength = 0;
				break;
			case 37:
				if (track->returnLocation == 0)
				{
					if (track->nextInstruction[1] == 0 || track->nextInstruction[1] - 1 > track->loopCounter)
					{
						if (track->nextInstruction[1] != 0)
						{
							track->loopCounter++;
						}
						track->nextInstruction = LoadUIntPointer(track->nextInstruction, 2);
						commandLength = 0;
					}
					else if (track->nextInstruction[1] != 0 && track->loopCounter != 0)
					{
						track->loopCounter = 0;
						commandLength = 6;
					}
				}
				else
				{
					if (track->nextInstruction[1] == 0 || track->nextInstruction[1] - 1 > track->loopCounter2)
					{
						if (track->nextInstruction[1] != 0)
						{
							track->loopCounter2++;
						}
						track->nextInstruction = LoadUIntPointer(track->nextInstruction, 2);
						commandLength = 0;
					}
					else if (track->nextInstruction[1] != 0 && track->loopCounter2 != 0)
					{
						track->loopCounter2 = 0;
						commandLength = 6;
					}
				}
				break;
			case 38:
				if (track->returnLocation == 0)
				{
					track->returnLocation = track->nextInstruction + 5;
					track->nextInstruction = LoadUIntPointer(track->nextInstruction, 1);
				}
				commandLength = 0;
				break;
			case 39:
				commandLength = 0;
				if (track->returnLocation == 0)
				{
					return 0xFF;
				}
				else
				{
					track->nextInstruction = track->returnLocation;
					track->returnLocation = 0;
				}
				break;
		}
	}
	track->nextInstruction += commandLength;
	return track->nextInstruction[0];
}

bool16 WaveTrackUpdate(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
	struct WaveTrack *waveTrack = (struct WaveTrack *)track;

	// The M4A sound effects can change the wave pattern.
	// We want to reload the correct wave pattern for this track when
	// control is returned to GBS from M4A.
	if (!ShouldRenderWaveChannel())
	{
		gShouldReloadWavePattern = TRUE;
	}
	else if (gShouldReloadWavePattern)
	{
		SwitchWavePattern(waveTrack->currentVoice);
		gShouldReloadWavePattern = FALSE;
	}

	if (waveTrack->noteLength1 < 2)
	{
		u32 commandID = waveTrack->nextInstruction[0];
		while (commandID >= 0xD0)
		{
			commandID = ExecuteWaveCommands(commandID, waveTrack);
			if (commandID == 0xFF && waveTrack->returnLocation == 0)
			{
				ExecuteWaveModifications(commandID, info->gbsTempo, waveTrack);
				return FALSE;
			}
		}
		if (commandID != 0xFF)
		{
			ExecuteWaveModifications(commandID, info->gbsTempo, waveTrack);
			waveTrack->nextInstruction++;
			waveTrack->modulationCountdown = waveTrack->modulationDelay;
			waveTrack->statusFlags[ModulationStatus] = FALSE;
			waveTrack->modulationSpeedDelay = waveTrack->modulationSpeed;
			if (waveTrack->modulationCountdown == 0)
			{
				ModulateWaveTrack(waveTrack);
			}
		}
	}
	else
	{
		waveTrack->noteLength1--;
		ModulateWaveTrack(waveTrack);
	}

	return TRUE;
}

// Individual noise samples. Arranged into groups of 3 bytes, with 0xFF terminating the array when in the 1st of 3 slots

const u8 noiseData00[] = { 0x20, 0x11, 0x00, 0xFF };
const u8 noiseData01[] = { 0x20, 0xC1, 0x33, 0xFF };
const u8 noiseData02[] = { 0x20, 0xB1, 0x33, 0xFF };
const u8 noiseData03[] = { 0x20, 0xA1, 0x33, 0xFF };
const u8 noiseData04[] = { 0x20, 0x81, 0x33, 0xFF };
const u8 noiseData05[] = { 0x27, 0x84, 0x37, 0x26, 0x84, 0x36, 0x25, 0x83, 0x35, 0x24, 0x83, 0x34, 0x23, 0x82, 0x33, 0x22, 0x81, 0x32, 0xFF };
const u8 noiseData06[] = { 0x20, 0x51, 0x2A, 0xFF };
const u8 noiseData07[] = { 0x21, 0x41, 0x2B, 0x20, 0x61, 0x2A, 0xFF };
const u8 noiseData08[] = { 0x20, 0x81, 0x10, 0xFF };
const u8 noiseData09[] = { 0x20, 0x82, 0x23, 0xFF };
const u8 noiseData010[] = { 0x20, 0x82, 0x25, 0xFF };
const u8 noiseData011[] = { 0x20, 0x82, 0x26, 0xFF };
const u8 noiseData012[] = { 0x20, 0xA1, 0x10, 0xFF };
const u8 noiseData16[] = { 0x20, 0xA2, 0x11, 0xFF };
const u8 noiseData17[] = { 0x20, 0xA2, 0x50, 0xFF };
const u8 noiseData18[] = { 0x20, 0xA1, 0x18, 0x20, 0x31, 0x33, 0xFF };
const u8 noiseData19[] = { 0x22, 0x91, 0x28, 0x20, 0x71, 0x18, 0xFF };
const u8 noiseData110[] = { 0x20, 0x91, 0x22, 0xFF };
const u8 noiseData111[] = { 0x20, 0x71, 0x22, 0xFF };
const u8 noiseData112[] = { 0x20, 0x61, 0x22, 0xFF };
const u8 noiseData30[] = { 0xFF };
const u8 noiseData31[] = { 0x20, 0x91, 0x33, 0xFF };
const u8 noiseData32[] = { 0x20, 0x51, 0x32, 0xFF };
const u8 noiseData33[] = { 0x20, 0x81, 0x31, 0xFF };
const u8 noiseData34[] = { 0x20, 0x88, 0x6B, 0x20, 0x71, 0x00, 0xFF };
const u8 noiseData35[] = { 0x30, 0x91, 0x18, 0xFF };
const u8 noiseData36[] = { 0x20, 0x11, 0x11, 0xFF };
const u8 noiseData37[] = { 0x27, 0x92, 0x10, 0xFF };
const u8 noiseData38[] = { 0x33, 0x91, 0x00, 0x33, 0x11, 0x00, 0xFF };
const u8 noiseData39[] = { 0x33, 0x91, 0x11, 0x33, 0x11, 0x00, 0xFF };
const u8 noiseData311[] = { 0x20, 0xA8, 0x6B, 0x20, 0x71, 0x00, 0xFF };
const u8 noiseData312[] = { 0x20, 0x84, 0x12, 0xFF };
const u8 noiseData45[] = { 0x20, 0xA1, 0x31, 0xFF };
const u8 noiseData47[] = { 0x33, 0x81, 0x00, 0x33, 0x11, 0x00, 0xFF };
const u8 noiseData48[] = { 0x33, 0x51, 0x21, 0x33, 0x11, 0x11, 0xFF };
const u8 noiseData49[] = { 0x33, 0x51, 0x50, 0x33, 0x11, 0x11, 0xFF };
const u8 noiseData410[] = { 0x33, 0x81, 0x21, 0x33, 0x11, 0x11, 0xFF };
const u8 noiseData412[] = { 0x33, 0x88, 0x15, 0x20, 0x65, 0x12, 0xFF };

// Groups the separate samples into sample groups

const u8* const noiseDataPointers0[] = { (u8*)(&noiseData00), (u8*)(&noiseData01),  (u8*)(&noiseData02),  (u8*)(&noiseData03),  (u8*)(&noiseData04),  (u8*)(&noiseData05),  (u8*)(&noiseData06), (u8*)(&noiseData07), (u8*)(&noiseData08), (u8*)(&noiseData09),  (u8*)(&noiseData010), (u8*)(&noiseData011), (u8*)(&noiseData012) };
const u8* const noiseDataPointers1[] = { (u8*)(&noiseData00), (u8*)(&noiseData08),  (u8*)(&noiseData09),  (u8*)(&noiseData010), (u8*)(&noiseData011), (u8*)(&noiseData012), (u8*)(&noiseData16), (u8*)(&noiseData17), (u8*)(&noiseData18), (u8*)(&noiseData19),  (u8*)(&noiseData110), (u8*)(&noiseData111), (u8*)(&noiseData112) };
const u8* const noiseDataPointers2[] = { (u8*)(&noiseData00), (u8*)(&noiseData01),  (u8*)(&noiseData110), (u8*)(&noiseData111), (u8*)(&noiseData112), (u8*)(&noiseData05),  (u8*)(&noiseData06), (u8*)(&noiseData07), (u8*)(&noiseData08), (u8*)(&noiseData09),  (u8*)(&noiseData010), (u8*)(&noiseData011), (u8*)(&noiseData012) };
const u8* const noiseDataPointers3[] = { (u8*)(&noiseData30), (u8*)(&noiseData31),  (u8*)(&noiseData32),  (u8*)(&noiseData33),  (u8*)(&noiseData34),  (u8*)(&noiseData35),  (u8*)(&noiseData36), (u8*)(&noiseData37), (u8*)(&noiseData38), (u8*)(&noiseData39),  (u8*)(&noiseData30),  (u8*)(&noiseData311), (u8*)(&noiseData312) };
const u8* const noiseDataPointers4[] = { (u8*)(&noiseData30), (u8*)(&noiseData36),  (u8*)(&noiseData32),  (u8*)(&noiseData33),  (u8*)(&noiseData34),  (u8*)(&noiseData45),  (u8*)(&noiseData35), (u8*)(&noiseData47), (u8*)(&noiseData48), (u8*)(&noiseData49),  (u8*)(&noiseData410), (u8*)(&noiseData311), (u8*)(&noiseData412) };
const u8* const noiseDataPointers5[] = { (u8*)(&noiseData00), (u8*)(&noiseData110), (u8*)(&noiseData111), (u8*)(&noiseData112), (u8*)(&noiseData37),  (u8*)(&noiseData38),  (u8*)(&noiseData39), (u8*)(&noiseData05), (u8*)(&noiseData06), (u8*)(&noiseData412), (u8*)(&noiseData33),  (u8*)(&noiseData32),  (u8*)(&noiseData311) };

// A simple table pointing to each of the sample groups

const void* const noiseDataPointers[] = { &noiseDataPointers0, &noiseDataPointers1, &noiseDataPointers2, &noiseDataPointers3, &noiseDataPointers4, &noiseDataPointers5 };

u8 ExecuteNoiseCommands(u8 commandID, struct NoiseTrack *track)
{
	u8 commandLength = 2;
	commandID -= 0xD8;
	if (commandID == 0)
	{
		u8 theValue = track->nextInstruction[1];
		track->frameDelay = ((theValue == 0 || theValue > 0xF) ? 0xC : theValue);
	}
	else if (commandID == 11)
	{
		track->noiseSet = track->nextInstruction[1];
	}
	else if (commandID == 23)
	{
		u8 byte = track->nextInstruction[1];
		track->pan = (byte == 0) ? 0xFF : byte;
	}
	else if (commandID == 37)
	{
		if (track->nextInstruction[1] == 0 || track->nextInstruction[1] - 1 > track->loopCounter)
		{
			if (track->nextInstruction[1] != 0)
			{
				track->loopCounter++;
			}
			track->nextInstruction = LoadUIntPointer(track->nextInstruction, 2);
			commandLength = 0;
		}
		else if (track->nextInstruction[1] != 0 && track->loopCounter != 0)
		{
			track->loopCounter = 0;
			commandLength = 6;
		}
	}
	else if (commandID == 38)
	{
		if (track->returnLocation == 0)
		{
			track->returnLocation = track->nextInstruction + 5;
			track->nextInstruction = LoadUIntPointer(track->nextInstruction, 1);
		}
		commandLength = 0;
	}
	else if (commandID == 39)
	{
		commandLength = 0;
		if (track->returnLocation == 0)
		{
			return 0xFF;
		}
		else
		{
			track->nextInstruction = track->returnLocation;
			track->returnLocation = 0;
		}
	}
	else
	{
		commandLength = 1;
	}
	track->nextInstruction += commandLength;
	return track->nextInstruction[0];
}

void WriteNoisePattern(struct NoiseTrack *track)
{
	u16 value1 = (track->samplePointer[0] & 0xF);
	u16 value2 = (track->samplePointer[1] << 8) | 0x3F;
	u16 value3 = track->samplePointer[2] | 0x8000;
	track->noiseFrameDelay = value1;
	track->samplePointer += 3;
	if (ShouldRenderNoiseChannel())
	{
		vu16 *control = NoiseTrackControl();
		control[0] = value2;
		control[2] = value3;
	}
}

void ExecuteNoiseModifications(u8 commandID, u16 tempo, struct NoiseTrack *track)
{
	u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);
	track->noteLength1 = (noteLength & 0xFF00) >> 8;
	track->noteLength2 = noteLength & 0xFF;
	gCgbChans[3].panMask = (FALSE) ? track->pan & 0x88 : 0x88;
	if (commandID & 0xF0)
	{
		u32 engineSet = track->noiseSet;
		u32* location = (u32*)((u32*)noiseDataPointers)[engineSet];
		location = (u32*)(location[(commandID & 0xF0) >> 4]);
		track->samplePointer = (u8*)location;
		track->noiseActive = 1;
		WriteNoisePattern(track);
	}
	else if (ShouldRenderNoiseChannel())
	{
		vu16 *control = NoiseTrackControl();
		control[0] = 0;
		control[2] = 0;
	}
}

bool16 NoiseTrackUpdate(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
	struct NoiseTrack *noiseTrack = (struct NoiseTrack *)track;
	if (noiseTrack->noteLength1 < 2)
	{
		u32 commandID = noiseTrack->nextInstruction[0];
		while (commandID >= 0xD0)
		{
			commandID = ExecuteNoiseCommands(commandID, noiseTrack);
			if (commandID == 0xFF && noiseTrack->returnLocation == 0)
			{
				ExecuteNoiseModifications(0, info->gbsTempo, noiseTrack);
				return FALSE;
			}
		}
		if (commandID != 0xFF)
		{
			ExecuteNoiseModifications(commandID, info->gbsTempo, noiseTrack);
			noiseTrack->nextInstruction++;
		}
		else
		{
			noiseTrack->noiseActive = 0;
			noiseTrack->noiseFrameDelay = 0;
		}
	}
	else
	{
		noiseTrack->noteLength1--;
		if (noiseTrack->noiseActive == 1)
		{
			if (noiseTrack->noiseFrameDelay == 0 && noiseTrack->samplePointer[0] != 0xFF)
			{
				WriteNoisePattern(noiseTrack);
			}
			else if (noiseTrack->samplePointer[0] == 0xFF)
			{
				noiseTrack->noiseActive = 0;
				noiseTrack->noiseFrameDelay = 0;
			}
			else
			{
				noiseTrack->noiseFrameDelay--;
			}
		}
	}

	return TRUE;
}

bool16 GBSChannelUpdate(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
	bool16 success = FALSE;
	switch (track->gbsIdentifier - 1)
	{
		case 2:
			// Wave Track Update
			success = WaveTrackUpdate(info, track);
			break;
		case 3:
			// Noise Track Update
			success = NoiseTrackUpdate(info, track);
			break;
		default:
			// Tone Track Update
			success = ToneTrackUpdate(info, track);
			break;
	}

	return success;
}

void ResetToneTrack(int trackID)
{
	vu16 *control = ToneTrackControl();
	if (trackID == 0)
	{
		control[0] = 0;
		control[1] = 0;
		control[2] = 0;
	}
	else
	{
		control[4] = 0;
		control[6] = 0;
	}
}

void ResetWaveTrack()
{
	vu16 *control = WaveTrackControl();
	control[0] = 0;
	control[1] = 0;
	control[2] = 0;
}

void ResetNoiseTrack()
{
	vu16 *control = NoiseTrackControl();
	control[0] = 0;
	control[2] = 0;
}

void GBSInitSong(struct MusicPlayerInfo *mplayInfo, struct SongHeader *header)
{
	int i;
	vu16 *control = SoundControl();

	for (i = 0; i < header->trackCount; i++)
	{
		struct MusicPlayerTrack *track = &mplayInfo->tracks[i];
	}

	control[0] = 0;
	ResetToneTrack(0);
	ResetToneTrack(1);
	ResetWaveTrack();
	ResetNoiseTrack();
	SwitchWavePattern(0);
	gShouldReloadWavePattern = FALSE;
	control[0] |= 0xFF00;
}

void GBSTrackStop(struct MusicPlayerTrack *track)
{
	if (track->gbsIdentifier == 0)
		return;

	switch (track->gbsIdentifier - 1)
	{
		case 2:
			ResetWaveTrack();
			break;
		case 3:
			ResetNoiseTrack();
			break;
		default:
			if (track->gbsIdentifier == 1)
			{
				// Restore the master volume of the GB Channels when a GBS song finishes.
				vu16 *control = SoundControl();
				control[0] |= 0x77;
			}

			ResetToneTrack(track->gbsIdentifier - 1);
			break;
	}
}
