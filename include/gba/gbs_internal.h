/*
 * gbs_internal.h
 *
 *  Created on: 21 May 2018
 *      Author: CoolerMaster
 */

#ifndef INCLUDE_GBA_GBS_INTERNAL_H_
#define INCLUDE_GBA_GBS_INTERNAL_H_

#include "gba/gba.h"

enum SoundEngineCommands
{
	SetOctave7 = 0xD0,
	SetOctave6,
	SetOctave5,
	SetOctave4,
	SetOctave3,
	SetOctave2,
	SetOctave1,
	SetOctave0,
	SetNoteAttributesAndLength,
	SetKeyShift,
	SetTempo,
	SetDutyCycle,
	SetNoteAttributes,
	Arpeggiate,
	SetDutyCyclePattern,
	Portamento,
	PitchBend,
	SetModulation,
	E2,
	NoiseSet,
	E4,
	SetChannelVolume,
	SetTone,
	E7,
	E8,
	E9,
	EA,
	EB,
	EC,
	ED,
	EE,
	Pan,
	F0,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	SetHostTempo,
	JumpIf,
	Jump,
	Loop,
	Call,
	End
};

enum GBPStatusFlags
{
	ModulationActivation,
	ModulationDir,
	PortamentoActivation,
	PitchBendActivation,
	PitchBendDir,
	ArpeggiationActivation,
	ArpeggiationStatus,
	NumGBPEngineFlags
};

enum CGBChannels
{
	CGBCHANNEL_TONE1,
	CGBCHANNEL_TONE2,
	CGBCHANNEL_WAVE,
	CGBCHANNEL_NOISE,
	NUM_CGBCHANNELS
};

struct GBSTrack
{
	u8 flags;
	u8 noteLength1;
	u8 patternLevel:4;
	u8 trackID:4;
	u8 loopCounter;
	u8 noteLength2;
	u8 currentOctave;
	u8 velocity;
	u8 loopCounter2;
	u16 pitch;
	s8 keyShift;
	u8 frameDelay;
	u16 tone;
	s8 pitchBendRate;
	u8 currentVoice;
	u8 volMR;
	u8 volML;
	u8 vol;
	u8 volX;
	u8 pan;
	u8 modulationDelayCountdown;
	u8 modulationDelay;
	u8 modulationMode;
	u8 modulationDepth;
	u8 modulationCountdown;
	u8 modulationSpeed;
	u8 arpeggiationDelayCountdown;
	u8 arpeggiationCountdown;
	u8 portamentoCountdown;
	u8 portamentoDelay;
	u8 portamentoTarget;
    struct SoundChannel *chan;
	u8 portamentoSpeedDelay;
	u8 portamentoSpeed;
	bool8 statusFlags[NumGBPEngineFlags];
	u8 fadeDirection;
	u8 channelVolume;
	u8 fadeSpeed;
	const u8 *samplePointer;
	bool8 noiseActive; // 0x1C
	u8 noiseFrameDelay;
	u16 pitchBendTarget;
	u8 pitchBendDuration;
	u8 pitchBendAmount;
	u8 pitchBendFraction;
	u8 pitchBendFractionAccumulator;
	u8 arpeggiationVoice;
	u8 padding[3];
	u8* nextInstruction;
	u8* returnLocation;
	u8 secondaryPadding[8];
};

#endif /* INCLUDE_GBA_GBS_INTERNAL_H_ */
