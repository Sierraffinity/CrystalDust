/*
 * gbs.c
 *
 *  Created on: 21 May 2018
 *      Author: Jambo51
 *  Revised for M4A integration in: February 2020
 *      Author: huderlem
 *  Integration finalized in: 2022
 *      Author: Sierraffinity
 */

#include "global.h"
#include "gba/m4a_internal.h"
#include "gba/gbs_internal.h"
#include "m4a.h"

bool8 gWaveTrackShouldReloadPattern;

static inline u16 UShortEndianSwap(u16 input)
{
    u16 temp = (input & 0xFF) << 8;
    return (input >> 8) | temp;
}

static inline vu16 *ToneTrackControl()
{
    return (vu16 *)(REG_ADDR_NR10);
}

static inline vu16 *WaveTrackControl()
{
    return (vu16 *)(REG_ADDR_NR30);
}

static inline vu16 *NoiseTrackControl()
{
    return (vu16 *)(REG_ADDR_NR41);
}

static inline vu8 *SoundControl()
{
    return (vu8 *)(REG_ADDR_NR50);
}

static inline bool32 IsM4AUsingCGBChannel(int channel)
{
    return gUsedCGBChannels & (1 << channel);
}

u32 GetMasterVolumeFromFade(u32 volX)
{
    // Respect the master M4A fade control.
    u32 masterVolume = 0;
    if (volX != 0)
    {
        masterVolume = volX / 8;
    }
    else
    {
        masterVolume = 7;
    }

    if (masterVolume > 7)
    {
        masterVolume = 7;
    }

    return (masterVolume << 4) | masterVolume;
}

u16 CalculateLength(u8 frameDelay, u16 tempo, u8 bitLength, u16 previousLeftover)
{
    return ((frameDelay * (bitLength + 1)) * tempo) + previousLeftover;
}

static const s16 sFrequencyTable[] =
{
    0x0000,
    0xF82C,
    0xF89D,
    0xF907,
    0xF96B,
    0xF9CA,
    0xFA23,
    0xFA77,
    0xFAC7,
    0xFB12,
    0xFB58,
    0xFB9B,
    0xFBDA,
    0xFC16,
    0xFC4E,
    0xFC83,
    0xFCB5,
    0xFCE5,
    0xFD11,
    0xFD3B,
    0xFD63,
    0xFD89,
    0xFDAC,
    0xFDCD,
    0xFDED
};

u16 CalculatePitch(u8 note, s8 keyShift, u8 octave, u16 tone)
{
    u8 octaveShifted = octave + ((keyShift & 0xF0) >> 4);
    u8 noteShifted = note + (keyShift & 0xF);
    s16 freq = (sFrequencyTable[noteShifted] >> (7 - octaveShifted)) & 0x7FF;
    return freq + tone;
}

void ToneTrack_Reset(int trackID)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu16 *control = ToneTrackControl() + (trackID * 4);
    vu8 *soundControl = SoundControl();

    soundControl[1] &= ~soundInfo->cgbChans[trackID].panMask;

    if (trackID == 1)
    {
        control[0] = 0x800;
    }
    else
    {
        control[0] = 0;
        control[1] = 0x800;
    }

    control[2] = 0x8000;
}

// Individual noise samples. Arranged into groups of 3 bytes, with 0xFF terminating the array when in the 1st of 3 slots

static const u8 sNoiseData00[] = { 0x20, 0x11, 0x00, 0xFF };
static const u8 sNoiseData01[] = { 0x20, 0xC1, 0x33, 0xFF };
static const u8 sNoiseData02[] = { 0x20, 0xB1, 0x33, 0xFF };
static const u8 sNoiseData03[] = { 0x20, 0xA1, 0x33, 0xFF };
static const u8 sNoiseData04[] = { 0x20, 0x81, 0x33, 0xFF };
static const u8 sNoiseData05[] = { 0x27, 0x84, 0x37, 0x26, 0x84, 0x36, 0x25, 0x83, 0x35, 0x24, 0x83, 0x34, 0x23, 0x82, 0x33, 0x22, 0x81, 0x32, 0xFF };
static const u8 sNoiseData06[] = { 0x20, 0x51, 0x2A, 0xFF };
static const u8 sNoiseData07[] = { 0x21, 0x41, 0x2B, 0x20, 0x61, 0x2A, 0xFF };
static const u8 sNoiseData08[] = { 0x20, 0x81, 0x10, 0xFF };
static const u8 sNoiseData09[] = { 0x20, 0x82, 0x23, 0xFF };
static const u8 sNoiseData010[] = { 0x20, 0x82, 0x25, 0xFF };
static const u8 sNoiseData011[] = { 0x20, 0x82, 0x26, 0xFF };
static const u8 sNoiseData012[] = { 0x20, 0xA1, 0x10, 0xFF };
static const u8 sNoiseData16[] = { 0x20, 0xA2, 0x11, 0xFF };
static const u8 sNoiseData17[] = { 0x20, 0xA2, 0x50, 0xFF };
static const u8 sNoiseData18[] = { 0x20, 0xA1, 0x18, 0x20, 0x31, 0x33, 0xFF };
static const u8 sNoiseData19[] = { 0x22, 0x91, 0x28, 0x20, 0x71, 0x18, 0xFF };
static const u8 sNoiseData110[] = { 0x20, 0x91, 0x22, 0xFF };
static const u8 sNoiseData111[] = { 0x20, 0x71, 0x22, 0xFF };
static const u8 sNoiseData112[] = { 0x20, 0x61, 0x22, 0xFF };
static const u8 sNoiseData30[] = { 0xFF };
static const u8 sNoiseData31[] = { 0x20, 0x91, 0x33, 0xFF };
static const u8 sNoiseData32[] = { 0x20, 0x51, 0x32, 0xFF };
static const u8 sNoiseData33[] = { 0x20, 0x81, 0x31, 0xFF };
static const u8 sNoiseData34[] = { 0x20, 0x88, 0x6B, 0x20, 0x71, 0x00, 0xFF };
static const u8 sNoiseData35[] = { 0x30, 0x91, 0x18, 0xFF };
static const u8 sNoiseData36[] = { 0x20, 0x11, 0x11, 0xFF };
static const u8 sNoiseData37[] = { 0x27, 0x92, 0x10, 0xFF };
static const u8 sNoiseData38[] = { 0x33, 0x91, 0x00, 0x33, 0x11, 0x00, 0xFF };
static const u8 sNoiseData39[] = { 0x33, 0x91, 0x11, 0x33, 0x11, 0x00, 0xFF };
static const u8 sNoiseData311[] = { 0x20, 0xA8, 0x6B, 0x20, 0x71, 0x00, 0xFF };
static const u8 sNoiseData312[] = { 0x20, 0x84, 0x12, 0xFF };
static const u8 sNoiseData45[] = { 0x20, 0xA1, 0x31, 0xFF };
static const u8 sNoiseData47[] = { 0x33, 0x81, 0x00, 0x33, 0x11, 0x00, 0xFF };
static const u8 sNoiseData48[] = { 0x33, 0x51, 0x21, 0x33, 0x11, 0x11, 0xFF };
static const u8 sNoiseData49[] = { 0x33, 0x51, 0x50, 0x33, 0x11, 0x11, 0xFF };
static const u8 sNoiseData410[] = { 0x33, 0x81, 0x21, 0x33, 0x11, 0x11, 0xFF };
static const u8 sNoiseData412[] = { 0x33, 0x88, 0x15, 0x20, 0x65, 0x12, 0xFF };

// Groups the separate samples into sample groups
static const u8 *const sNoiseDataGroup0[] =
{
    sNoiseData00,
    sNoiseData01,
    sNoiseData02,
    sNoiseData03,
    sNoiseData04,
    sNoiseData05,
    sNoiseData06,
    sNoiseData07,
    sNoiseData08,
    sNoiseData09,
    sNoiseData010,
    sNoiseData011,
    sNoiseData012
};

static const u8 *const sNoiseDataGroup1[] =
{
    sNoiseData00,
    sNoiseData08,
    sNoiseData09,
    sNoiseData010,
    sNoiseData011,
    sNoiseData012,
    sNoiseData16,
    sNoiseData17,
    sNoiseData18,
    sNoiseData19,
    sNoiseData110,
    sNoiseData111,
    sNoiseData112
};

static const u8 *const sNoiseDataGroup2[] =
{
    sNoiseData00,
    sNoiseData01,
    sNoiseData110,
    sNoiseData111,
    sNoiseData112,
    sNoiseData05,
    sNoiseData06,
    sNoiseData07,
    sNoiseData08,
    sNoiseData09,
    sNoiseData010,
    sNoiseData011,
    sNoiseData012
};

static const u8 *const sNoiseDataGroup3[] =
{
    sNoiseData30,
    sNoiseData31,
    sNoiseData32,
    sNoiseData33,
    sNoiseData34,
    sNoiseData35,
    sNoiseData36,
    sNoiseData37,
    sNoiseData38,
    sNoiseData39,
    sNoiseData30,
    sNoiseData311,
    sNoiseData312
};

static const u8 *const sNoiseDataGroup4[] =
{
    sNoiseData30,
    sNoiseData36,
    sNoiseData32,
    sNoiseData33,
    sNoiseData34,
    sNoiseData45,
    sNoiseData35,
    sNoiseData47,
    sNoiseData48,
    sNoiseData49,
    sNoiseData410,
    sNoiseData311,
    sNoiseData412
};

static const u8 *const sNoiseDataGroup5[] =
{
    sNoiseData00,
    sNoiseData110,
    sNoiseData111,
    sNoiseData112,
    sNoiseData37,
    sNoiseData38,
    sNoiseData39,
    sNoiseData05,
    sNoiseData06,
    sNoiseData412,
    sNoiseData33,
    sNoiseData32,
    sNoiseData311
};

// A simple table pointing to each of the sample groups
static const u8 *const *const sNoiseDataGroupTable[] =
{
    sNoiseDataGroup0,
    sNoiseDataGroup1,
    sNoiseDataGroup2,
    sNoiseDataGroup3,
    sNoiseDataGroup4,
    sNoiseDataGroup5
};

void ProcessNoteCommand(u8 commandID, u16 tempo, struct GBSTrack *track)
{
    u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);

    track->noteLength1 = (noteLength & 0xFF00) >> 8;
    track->noteLength2 = noteLength & 0xFF;

    if (track->noiseActive && ((track->trackID - 1) == CGBCHANNEL_NOISE))
    {
        if (commandID & 0xF0)
        {
            u32 engineSet = track->dutyCycle;
            const u8 *const *noiseGroup = sNoiseDataGroupTable[engineSet];
            const u8 *noiseData = NULL;
            
            noiseData = noiseGroup[(commandID & 0xF0) >> 4];
            track->samplePointer = noiseData;
            track->noiseFrameDelay = 0;
        }
    }
    else
    {
        if (commandID & 0xF0)
        {
            track->pitch = CalculatePitch((commandID & 0xF0) >> 4, track->keyShift, track->currentOctave, 0);
            track->noteNoiseSampling = TRUE;
            
            // Initialize pitch bend data from target and duration
            if (track->pitchBendActivation)
            {
                u32 distance = 0;
                if (track->noteLength1 <= track->pitchBendDuration)
                {
                    track->pitchBendDuration = 1;
                }
                else
                {
                    track->pitchBendDuration = track->noteLength1 - track->pitchBendDuration;
                }

                if (track->pitch < track->pitchBendTarget)
                {
                    track->pitchBendDir = TRUE;
                    distance = track->pitchBendTarget - track->pitch;
                }
                else
                {
                    track->pitchBendDir = FALSE;
                    distance = track->pitch - track->pitchBendTarget;
                }

                track->pitchBendAmount = distance / track->pitchBendDuration;
                track->pitchBendFraction = distance % track->pitchBendDuration;
                track->pitchBendFractionAccumulator = 0;
            }
        }
        else
        {
            track->noteRest = TRUE;
        }
    }
}

u8 ParseCommands(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    u8 commandID = *track->nextInstruction++; // grab next byte and increment pointer

    switch (commandID)
    {
        case SetOctave7 ... SetOctave0:
            track->currentOctave = commandID & 7;
            break;
        case SetNoteAttributesAndLength:
            track->frameDelay = *track->nextInstruction++;
            if ((track->trackID - 1) == CGBCHANNEL_NOISE)
            {
                break;
            }
            // fallthrough
        case SetNoteAttributes:
        {
            u8 velocityEnvelope = *track->nextInstruction++;
            track->velocity = (velocityEnvelope & 0xF0) >> 4;
            track->envelope = velocityEnvelope & 0xF;
            break;
        }
        case SetKeyShift:
            track->keyShift = *track->nextInstruction++;
            break;
        case SetTempo:
            info->gbsTempo = UShortEndianSwap(T1_READ_16(track->nextInstruction));
            track->nextInstruction += 2;
            break;
        case SetDutyCycle:
            track->dutyCycle = *track->nextInstruction++;
            break;
        case SetDutyCyclePattern:
            track->dutyCycleLoop = TRUE;
            track->dutyCyclePattern = *track->nextInstruction++;
            track->dutyCycle = track->dutyCyclePattern & 3;
            break;
        case PitchSweep:
            track->pitchSweep = *track->nextInstruction++;
            track->notePitchSweep = TRUE;
            break;
        case PitchBend:
        {
            u8 byte2 = 0;
            track->pitchBendDuration = *track->nextInstruction++;
            byte2 = *track->nextInstruction++;
            track->pitchBendTarget = CalculatePitch(byte2 & 0xF, track->keyShift, (byte2 & 0xF0) >> 4, 0);
            track->pitchBendActivation = TRUE;
            break;
        }
        case SetModulation:
        {
            u8 modulationDelay = *track->nextInstruction++;
            u8 byte2 = *track->nextInstruction++;
            if (byte2 != 0)
            {
                track->modulationActivation = TRUE;
                track->modulationDir = FALSE;
                track->modulationDelay = modulationDelay;
                track->modulationDelayCountdown = track->modulationDelay;
                track->modulationMode = 0;
                track->modulationDepth = (byte2 & 0xF0) >> 4;
                track->modulationSpeed = byte2 & 0xF;
                track->modulationCountdown = track->modulationSpeed;
            }
            else
            {
                track->modulationActivation = FALSE;
            }
            break;
        }
        case NoiseSet:
            if (track->noiseActive)
            {
                track->noiseActive = FALSE;
            }
            else
            {
                track->noiseActive = TRUE;
                track->dutyCycle = *track->nextInstruction++;
            }
            break;
        case SetChannelVolume:
            track->channelVolume = *track->nextInstruction++;
            track->volumeChange = TRUE;
            break;
        case SetTone:
            track->tone = UShortEndianSwap(T1_READ_16(track->nextInstruction));
            track->nextInstruction += 2;
            track->pitchOffset = TRUE;
            break;
        case Pan:
            track->pan = *track->nextInstruction++;
            break;
        case SetHostTempo:
        {
            // It is advised that this function not be used since it could mess with
            // playback in unexpected ways, however, I felt it would be fun
            // to include it all the same. The GBS Tempo should always be 150
            u32 tempo = *track->nextInstruction++ << 1;
            if (track->trackID == 1)
            {
                info->tempoD = tempo;
                tempo *= info->tempoU;
                tempo >>= 8;
                info->tempoI = tempo;
            }
            break;
        }
        case JumpIf:
            // Not implemented
            track->nextInstruction += 5;
            break;
        case Jump:
            track->nextInstruction = T1_READ_PTR(track->nextInstruction);
            break;
        case Loop:
        {
            u8 loopCount = *track->nextInstruction++;
            if (track->returnLocation == NULL)
            {
                if (loopCount == 0 || (loopCount - 1) > track->loopCounter)
                {
                    if (loopCount != 0)
                    {
                        track->loopCounter++;
                    }
                    track->nextInstruction = T1_READ_PTR(track->nextInstruction);
                }
                else if (loopCount != 0 && track->loopCounter != 0)
                {
                    track->loopCounter = 0;
                    track->nextInstruction += 4;
                }
            }
            else
            {
                if (loopCount == 0 || (loopCount - 1) > track->loopCounter2)
                {
                    if (loopCount != 0)
                    {
                        track->loopCounter2++;
                    }
                    track->nextInstruction = T1_READ_PTR(track->nextInstruction);
                }
                else if (loopCount != 0 && track->loopCounter2 != 0)
                {
                    track->loopCounter2 = 0;
                    track->nextInstruction += 4;
                }
            }
            break;
        }
        case Call:
            if (track->returnLocation == NULL)
            {
                track->returnLocation = track->nextInstruction + 4;
                track->nextInstruction = T1_READ_PTR(track->nextInstruction);
            }
            break;
        case End:
            if (track->returnLocation == NULL)
            {
                return End;
            }
            else
            {
                track->nextInstruction = track->returnLocation;
                track->returnLocation = NULL;
            }
            break;
        default:
            break;
    }
    return *track->nextInstruction;
}

void ApplyPitchBend(struct GBSTrack *track)
{
    if (track->pitchBendActivation)
    {
        if (track->pitchBendDir)
        {
            u32 fractionAccumulator = track->pitchBendFractionAccumulator;
            track->pitch += track->pitchBendAmount;
            fractionAccumulator += track->pitchBendFraction;
            if (fractionAccumulator >= 0x100)
            {
                // rollover
                track->pitch++;
            }
            track->pitchBendFractionAccumulator = fractionAccumulator & 0xFF;
            if (track->pitch < track->pitchBendTarget)
            {
                track->noteFreqOverride = TRUE;
            }
            else
            {
                track->pitchBendActivation = FALSE;
                track->pitchBendDir = FALSE;
            }
        }
        else
        {
            // TODO: Why does it calculate the fractional part like this?
            u32 fractionAccumulator = track->pitchBendFraction;
            track->pitch -= track->pitchBendAmount;
            fractionAccumulator *= 2;
            if (fractionAccumulator >= 0x100)
            {
                // rollover
                track->pitch--;
            }
            track->pitchBendFraction = fractionAccumulator & 0xFF;
            if (track->pitch > track->pitchBendTarget)
            {
                track->noteFreqOverride = TRUE;
            }
            else
            {
                track->pitchBendActivation = FALSE;
                track->pitchBendDir = FALSE;
            }
        }
    }
}

u16 GetModulationPitch(struct GBSTrack *track)
{
    u16 newPitch = track->pitch;
    track->modulationDir = !track->modulationDir;
    track->modulationCountdown = track->modulationSpeed;
    switch (track->modulationMode)
    {
        case 0:
        {
            u8 halfValue = track->modulationDepth >> 1;
            if (track->modulationDir)
            {
                newPitch += (track->modulationDepth - halfValue);
            }
            else
            {
                newPitch -= halfValue;
            }
            break;
        }
        case 1:
            if (track->modulationDir)
            {
                newPitch -= track->modulationDepth;
            }
            break;
        case 2:
            if (track->modulationDir)
            {
                newPitch += track->modulationDepth;
            }
            break;
    }
    return newPitch;
}

u16 HandleTrackDutyAndModulation(struct GBSTrack *track)
{
    u16 finalPitch = 0;

    if (track->trackID == 1)
    {
        ApplyPitchBend(track);
    }

    finalPitch = track->pitch;

    if (track->dutyCycleLoop)
    {
        track->dutyCycle = (track->dutyCyclePattern & 0xC0) >> 6;
        track->dutyCyclePattern = (track->dutyCyclePattern << 2) | track->dutyCycle;
        track->noteDutyOverride = TRUE;
    }

    if (track->pitchOffset)
    {
        // TODO: Should tone be signed?
        finalPitch += track->tone;
    }
    
    if (track->modulationActivation)
    {
        if (track->modulationDelayCountdown > 0)
        {
            track->modulationDelayCountdown--;
        }
        else if (track->modulationDepth != 0)
        {
            if (track->modulationCountdown > 0)
            {
                track->modulationCountdown--;
            }
            else if (track->pitch != 0)
            {
                track->modulationDir = !track->modulationDir;
                track->modulationCountdown = track->modulationSpeed;
                switch (track->modulationMode)
                {
                    case 0:
                    {
                        // Original engine chooses to clamp calculation at nearest multiple of 0x100
                        // Because of this, it only writes the lower byte if noteVibratoOverride is set
                        // Either we replicate both behaviors exactly or just store both bytes
                        u8 halfValue = track->modulationDepth >> 1;
                        if (track->modulationDir)
                        {
                            finalPitch += (track->modulationDepth - halfValue);
                        }
                        else
                        {
                            finalPitch -= halfValue;
                        }
                        break;
                    }
                    case 1:
                        if (track->modulationDir)
                        {
                            finalPitch -= track->modulationDepth;
                        }
                        break;
                    case 2:
                        if (track->modulationDir)
                        {
                            finalPitch += track->modulationDepth;
                        }
                        break;
                }
                track->noteVibratoOverride = TRUE;
            }
        }
    }

    return finalPitch;
}

void HandleNoise(struct GBSTrack *track)
{
    if (track->noiseActive)
    {
        if (track->noiseFrameDelay > 0)
        {
            track->noiseFrameDelay--;
        }
        else if (track->samplePointer != NULL && track->samplePointer[0] != 0xFF)
        {
            track->noiseFrameDelay = (*track->samplePointer++ & 0xF) + 1;
            track->envelope = *track->samplePointer++;
            track->pitch = *track->samplePointer++;
            track->noteNoiseSampling = TRUE;
        }
    }
}

void UpdateStereoPan(struct GBSTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu8 *soundControl = SoundControl();
    u8 thisPan = soundInfo->cgbChans[track->trackID - 1].panMask;

    if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
    {
        thisPan &= track->pan;
    }
    soundControl[1] = (soundControl[1] & ~soundInfo->cgbChans[track->trackID - 1].panMask) | thisPan;
}

void UpdateDutyEnvelopeVelocity(struct GBSTrack *track, vu16 *control)
{
    *control = 0x3F | (track->dutyCycle << 6) | (track->envelope << 8) | (track->velocity << 12);
}

void UpdateCGBTone1(struct GBSTrack *track, u16 pitch)
{
    vu16 *control = ToneTrackControl();

    if (track->notePitchSweep)
    {
        control[0] = (control[0] & 0xFF00) | track->pitchSweep;
    }

    if (track->noteRest)
    {
        ToneTrack_Reset(track->trackID - 1);
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        UpdateDutyEnvelopeVelocity(track, &control[1]);
        control[2] = pitch | 0x8000;
    }
    else
    {
        if (track->noteFreqOverride)
        {
            control[2] = pitch;
            track->noteDutyOverride = TRUE;
        }
        else if (track->noteVibratoOverride)
        {
            // Original engine chooses to clamp calculation at nearest multiple of 0x100
            // Because of this, it only writes the lower byte if noteVibratoOverride is set
            // Either we replicate both behaviors exactly or just store both bytes
            //control[2] = (control[2] & 0xFF00) | (pitch & 0xFF);
            control[2] = pitch;
            track->noteDutyOverride = TRUE;
        }

        if (track->noteDutyOverride)
        {
            control[1] = (control[1] & 0xFF3F) | (track->dutyCycle << 6);
        }
    }
}

void UpdateCGBTone2(struct GBSTrack *track, u16 pitch)
{
    vu16 *control = ToneTrackControl() + 4;
    
    if (track->noteRest)
    {
        ToneTrack_Reset(track->trackID - 1);
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        UpdateDutyEnvelopeVelocity(track, &control[0]);
        control[2] = pitch | 0x8000;
    }
    else
    {
        if (track->noteVibratoOverride)
        {
            // Original engine chooses to clamp calculation at nearest multiple of 0x100
            // Because of this, it only writes the lower byte if noteVibratoOverride is set
            // Either we replicate both behaviors exactly or just store both bytes
            //control[2] = (control[2] & 0xFF00) | (pitch & 0xFF);
            control[2] = pitch;
            track->noteDutyOverride = TRUE;
        }

        if (track->noteDutyOverride)
        {
            control[0] = (control[0] & 0xFF3F) | (track->dutyCycle << 6);
        }
    }
}

void WaveTrack_Reset()
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu16 *control = WaveTrackControl();
    vu8 *soundControl = SoundControl();

    soundControl[1] &= ~soundInfo->cgbChans[CGBCHANNEL_WAVE].panMask;

    control[0] = 0;
    control[1] = 0x800;
    control[2] = 0x8000;
}

static const u32 sWaveTrackPatterns[][4] = {
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

void LoadWavePattern(struct GBSTrack *track, int patternID)
{
    if (!IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
    {
        int i;
        struct SoundInfo *soundInfo = SOUND_INFO_PTR;
        vu16* control = WaveTrackControl();
        control[1] = (control[1] & 0xFF00) | 0x3F;
        control[0] = (control[0] & 0xFF00) | 0x40; // Choose other wave bank so we can write into the first one
        if (patternID < ARRAY_COUNT(sWaveTrackPatterns) && soundInfo->cgbChans[CGBCHANNEL_WAVE].cp != (u32)sWaveTrackPatterns[patternID])
        {
            u32* mainPattern = (u32 *)(REG_ADDR_WAVE_RAM0);
            for (i = 0; i < 4; i++)
                mainPattern[i] = sWaveTrackPatterns[patternID][i];
            soundInfo->cgbChans[CGBCHANNEL_WAVE].cp = (u32)sWaveTrackPatterns[patternID];
        }
        control[1] = (control[1] & 0x00FF) | track->velocity << 13;
        control[0] = (control[0] & 0xFF00) | 0x80; // Switch back to first wave bank
    }
    track->envelope = patternID;
    track->shouldReload = FALSE;
}

void UpdateCGBWave(struct GBSTrack *track, u16 pitch)
{
    vu16 *control = WaveTrackControl();
    
    if (track->noteRest)
    {
        WaveTrack_Reset();
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        LoadWavePattern(track, track->envelope);
        control[2] = pitch | 0x8000;
    }
    else if (track->noteVibratoOverride)
    {
        // Original engine chooses to clamp calculation at nearest multiple of 0x100
        // Because of this, it only writes the lower byte if noteVibratoOverride is set
        // Either we replicate both behaviors exactly or just store both bytes
        //control[2] = (control[2] & 0xFF00) | (pitch & 0xFF);
        control[2] = pitch;
    }
}

void NoiseTrack_Reset()
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu16 *control = NoiseTrackControl();
    vu8 *soundControl = SoundControl();

    soundControl[1] &= ~soundInfo->cgbChans[CGBCHANNEL_NOISE].panMask;

    control[0] = 0x800;
    control[2] = 0x8000;
}

void UpdateCGBNoise(struct GBSTrack *track)
{
    vu16 *control = NoiseTrackControl();

    if (track->noteRest)
    {
        NoiseTrack_Reset();
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        control[0] = (track->envelope << 8) | 0x3F;
        control[2] = (track->pitch & 0xFF) | 0x8000;
    }
}

void UpdateCGBChannel(struct GBSTrack *track, u16 pitch)
{
    if (!IsM4AUsingCGBChannel(track->trackID - 1))
    {
        switch (track->trackID - 1)
        {
            case CGBCHANNEL_TONE1:
                UpdateCGBTone1(track, pitch);
                break;
            case CGBCHANNEL_TONE2:
                UpdateCGBTone2(track, pitch);
                break;
            case CGBCHANNEL_WAVE:
                UpdateCGBWave(track, pitch);
                break;
            default: // CGBCHANNEL_NOISE
                UpdateCGBNoise(track);
                break;
        }
    }
}

bool32 ToneTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    bool32 trackActive = TRUE;
    u16 thisPitch = track->pitch;

    // The M4A sound effects can change instrument data out from under us.
    // We want to reload the correct values for this track when
    // control is returned to GBS from M4A.
    if (IsM4AUsingCGBChannel(track->trackID - 1))
    {
        track->shouldReload = TRUE;
    }
    else if (track->shouldReload)
    {
        track->notePitchSweep = TRUE;
        track->pitchSweep = 0;
        track->noteDutyOverride = TRUE;
        track->shouldReload = FALSE;
    }

    if (track->noteLength1 < 2)
    {
        u32 commandID = *track->nextInstruction;
        while (commandID >= SetOctave7)
        {
            commandID = ParseCommands(info, track);
            if (commandID == End && track->returnLocation == NULL)
            {
                ProcessNoteCommand(0, info->gbsTempo, track);
                track->noteRest = TRUE;
                trackActive = FALSE;
                break;
            }
        }

        if (commandID != End)
        {
            ProcessNoteCommand(commandID, info->gbsTempo, track);
            track->nextInstruction++;
            track->modulationDelayCountdown = track->modulationDelay;
        }
    }
    else
    {
        track->noteLength1--;
    }

    thisPitch = HandleTrackDutyAndModulation(track);
    HandleNoise(track);
    UpdateCGBChannel(track, thisPitch);

    return trackActive;
}

bool32 WaveTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    bool32 trackActive = TRUE;
    u16 thisPitch = track->pitch;

    // The M4A sound effects can change the wave pattern out from under us.
    // We want to reload the correct wave pattern for this track when
    // control is returned to GBS from M4A.
    if (IsM4AUsingCGBChannel(track->trackID - 1))
    {
        track->shouldReload = TRUE;
    }
    else if (track->shouldReload)
    {
        LoadWavePattern(track, track->envelope);
        track->shouldReload = FALSE;
    }

    if (track->noteLength1 < 2)
    {
        u32 commandID = *track->nextInstruction;
        while (commandID >= SetOctave7)
        {
            commandID = ParseCommands(info, track);
            if (commandID == End && track->returnLocation == NULL)
            {
                ProcessNoteCommand(0, info->gbsTempo, track);
                track->noteRest = TRUE;
                trackActive = FALSE;
                break;
            }
        }
        if (commandID != End)
        {
            ProcessNoteCommand(commandID, info->gbsTempo, track);
            track->nextInstruction++;
            track->modulationDelayCountdown = track->modulationDelay;
        }
    }
    else
    {
        track->noteLength1--;
    }

    thisPitch = HandleTrackDutyAndModulation(track);
    HandleNoise(track);
    UpdateCGBChannel(track, thisPitch);

    return trackActive;
}

bool16 NoiseTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    bool32 trackActive = TRUE;
    u16 thisPitch = track->pitch;

    // The M4A sound effects can change instrument data out from under us.
    // We want to reload the correct values for this track when
    // control is returned to GBS from M4A.
    if (IsM4AUsingCGBChannel(track->trackID - 1))
    {
        track->shouldReload = TRUE;
    }
    else if (track->shouldReload)
    {
        track->shouldReload = FALSE;
    }

    if (track->noteLength1 < 2)
    {
        u32 commandID = *track->nextInstruction;
        while (commandID >= SetOctave7)
        {
            commandID = ParseCommands(info, track);
            if (commandID == End && track->returnLocation == NULL)
            {
                ProcessNoteCommand(0, info->gbsTempo, track);
                track->noteRest = TRUE;
                trackActive = FALSE;
                break;
            }
        }
        if (commandID != End)
        {
            ProcessNoteCommand(commandID, info->gbsTempo, track);
            track->nextInstruction++;
            track->modulationDelayCountdown = track->modulationDelay;
        }
    }
    else
    {
        track->noteLength1--;
    }

    thisPitch = HandleTrackDutyAndModulation(track);
    HandleNoise(track);
    UpdateCGBChannel(track, thisPitch);

    return trackActive;
}

bool32 GBSTrack_Update(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    struct GBSTrack *gbsTrack = (struct GBSTrack *)track;
    vu8 *soundControl = SoundControl();
    bool32 success = FALSE;
    u32 masterVolume = 0;
    
    // Set bias level to 0 for less crunch
    // Always set here since m4a engine may have changed it
    // TODO: Now I can't tell the difference, was there ever one...?
    //REG_SOUNDBIAS = REG_SOUNDBIAS & 0xFC00;

    // Reset all note flags
    gbsTrack->noteDutyOverride = FALSE;
	gbsTrack->noteFreqOverride = FALSE;
	gbsTrack->notePitchSweep = FALSE;
	gbsTrack->noteNoiseSampling = FALSE;
	gbsTrack->noteRest = FALSE;
	gbsTrack->noteVibratoOverride = FALSE;

    switch (track->gbsIdentifier - 1)
    {
        case 2:
            // Wave Track Update
            success = WaveTrack_Update(info, gbsTrack);
            break;
        case 3:
            // Noise Track Update
            success = NoiseTrack_Update(info, gbsTrack);
            break;
        default:
            // Tone Track Update
            success = ToneTrack_Update(info, gbsTrack);
            break;
    }

    masterVolume = GetMasterVolumeFromFade(track->volX);
    // Ensure we're not stepping on m4a's toes by checking for default volume and channel usage
    if ((masterVolume == 0x77) && (gUsedCGBChannels == 0) && gbsTrack->volumeChange)
    {
        masterVolume = gbsTrack->channelVolume;
        gbsTrack->volumeChange = FALSE;
    }
    soundControl[0] = masterVolume;

    return success;
}

void ply_gbs_switch(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u8 *cmdPtrBackup = track->cmdPtr;
    u8 gbChannel = *cmdPtrBackup++;

    if (gbChannel < 4)
    {
        memset(track, 0, sizeof(*track));
        track->gbsIdentifier = gbChannel + 1;
        track->cmdPtr = cmdPtrBackup;
        track->pan = 0xFF;
        track->flags = MPT_FLG_EXIST;

        // Disable m4a control of CGB channel.
        soundInfo->cgbChans[gbChannel].sf = 0;
        // Clear used bit.
        gUsedCGBChannels &= ~(1 << gbChannel);
        
        switch (gbChannel)
        {
            case 0:
            case 1:
                ToneTrack_Reset(gbChannel);
                break;
            case 2:
                WaveTrack_Reset();
                LoadWavePattern((struct GBSTrack *)track, 0);
                break;
            case 3:
                NoiseTrack_Reset();
                break;
        }
    }
}

void GBSTrackStop(struct MusicPlayerTrack *track)
{
    if (track->gbsIdentifier == 0)
        return;

    switch (track->gbsIdentifier - 1)
    {
        case 2:
            WaveTrack_Reset();
            break;
        case 3:
            NoiseTrack_Reset();
            break;
        default:
            ToneTrack_Reset(track->gbsIdentifier - 1);
            break;
    }
}
