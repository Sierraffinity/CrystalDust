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
	PitchSweep,
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
	u8 flags; // 0x0
	u8 noteLength1;
	u8 patternLevel:4;
	u8 trackID:4;
	u8 loopCounter;
	u8 noteLength2; // 0x4
	u8 currentOctave;
	u8 velocity;
	u8 loopCounter2;
	u16 pitch; // 0x8
	s8 keyShift;
	u8 frameDelay;
	u16 tone; // 0xC
	s8 pitchBendRate;
	u8 dutyCycle;
	u8 volMR; // 0x10
	u8 volML;
	u8 vol;
	u8 volX;
	u8 pan; // 0x14
	u8 modulationDelayCountdown;
	u8 modulationDelay;
	u8 modulationMode;
	u8 modulationDepth; // 0x18
	u8 modulationCountdown;
	u8 modulationSpeed;
	u8 portamentoCountdown;
	u8 portamentoDelay; // 0x1C
	u8 portamentoTarget;
	u8 portamentoSpeedDelay;
	u8 portamentoSpeed;
    struct SoundChannel *chan; // 0x20
	u8 arpeggiationDelayCountdown; // 0x24
	u8 arpeggiationCountdown;
	u8 arpeggiationVoice;
	u8 channelVolume;
	const u8 *samplePointer; // 0x28
	u8 noiseFrameDelay;
	u16 pitchBendTarget;
	u8 pitchBendDuration; // 0x30
	u8 pitchBendAmount;
	u8 pitchBendFraction;
	u8 pitchBendFractionAccumulator;

	bool8 pitchBendActivation:1; // 0x34
	bool8 pitchBendDir:1;
	bool8 portamentoActivation:1;
	bool8 modulationActivation:1;
	bool8 modulationDir:1;
	bool8 arpeggiationActivation:1;
	bool8 arpeggiationStatus:1;
	bool8 dutyCycleLoop:1;

	bool8 pitchOffset:1;
	bool8 noteDutyOverride:1;
	bool8 noteFreqOverride:1;
	bool8 notePitchSweep:1;
	bool8 noteNoiseSampling:1;
	bool8 noteRest:1;
	bool8 noteVibratoOverride:1;
	bool8 noiseActive:1;

	bool8 fadeDirection:1;
	bool8 shouldReload:1;
	bool8 volumeChange:1;

	u8 envelope;
	u8 dutyCyclePattern; // 0x38
	u8 pitchSweep;
	u8 padding[6];
	const u8 *nextInstruction; // 0x40
	const u8 *returnLocation; // 0x44
	u8 secondaryPadding[8]; // 0x48
};

#endif /* INCLUDE_GBA_GBS_INTERNAL_H_ */
