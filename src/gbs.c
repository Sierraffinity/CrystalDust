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
    return gUsedCGBChannels[channel];
}

void SetMasterVolumeFromFade(u32 volX)
{
    // Respect the master M4A fade control.
    u32 masterVolume;
    vu8 *control = SoundControl();
    if (volX != 0)
        masterVolume = volX / 8;
    else
        masterVolume = 7;

    if (masterVolume > 7)
        masterVolume = 7;

    if ((control[0] & 0x7) != masterVolume)
    {
        control[0] = (masterVolume << 4) | masterVolume;
    }
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
    s16 octaveShifted = octave + ((keyShift & 0xF0) >> 4);
    s16 noteShifted = note + (keyShift & 0xF);
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

void ToneTrack_ExecuteModifications(u8 commandID, u16 tempo, struct GBSTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u16 thisVoiceVolVelocity = 0;
    u16 thisPitch = 0;
    u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);

    track->noteLength1 = (noteLength & 0xFF00) >> 8;
    track->noteLength2 = noteLength & 0xFF;

    if (commandID & 0xF0)
    {
        track->pitch = CalculatePitch((commandID & 0xF0) >> 4, track->keyShift, track->currentOctave, track->tone);
        thisVoiceVolVelocity = (track->currentVoice << 6) | (track->fadeSpeed << 8) | (((track->fadeSpeed == 0) ? 0 : track->fadeDirection) << 11) | (track->velocity << 12) | 0x3F;
        thisPitch = track->pitch | 0x8000;
        
        if (!IsM4AUsingCGBChannel(track->trackID - 1))
        {
            vu16 *control = ToneTrackControl() + ((track->trackID - 1) * 4);
            vu8 *soundControl = SoundControl();
            u8 thisPan = soundInfo->cgbChans[track->trackID - 1].panMask;

            if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
                thisPan &= track->pan;
            soundControl[1] = (soundControl[1] & ~soundInfo->cgbChans[track->trackID - 1].panMask) | thisPan;

            if (track->trackID == 2)
                control[0] = thisVoiceVolVelocity;
            else
                control[1] = thisVoiceVolVelocity;

            control[2] = thisPitch;
        }
        
        if (track->statusFlags[PitchBendActivation])
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
            track->pitchBendUnk = 0;
        }
    }
    else if (!IsM4AUsingCGBChannel(track->trackID - 1))
    {
        ToneTrack_Reset(track->trackID - 1);
    }
}

u8 ToneTrack_ProcessCommands(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    u8 commandID = *track->nextInstruction++; // grab next byte and increment pointer

    switch (commandID)
    {
        case SetOctave7 ... SetOctave0:
            track->currentOctave = commandID & 7;
            break;
        case SetNoteAttributesAndLength:
        {
            u8 byte2 = *track->nextInstruction++;
            track->frameDelay = byte2;
            byte2 = *track->nextInstruction++;
            track->velocity = (byte2 & 0xF0) >> 4;
            track->fadeSpeed = byte2 & 0x7;
            track->fadeDirection = (byte2 & 0x8) >> 3;
            break;
        }
        case SetNoteAttributes:
        {
            u8 byte2 = *track->nextInstruction++;
            track->velocity = (byte2 & 0xF0) >> 4;
            track->fadeSpeed = byte2 & 0x7;
            track->fadeDirection = (byte2 & 0x8) >> 3;
            break;
        }
        case SetKeyShift:
        {
            track->keyShift = *track->nextInstruction++;
            break;
        }
        case SetTempo:
            // TODO: Should be settable from others
            info->gbsTempo = UShortEndianSwap(T1_READ_16(track->nextInstruction));
            track->nextInstruction += 2;
            break;
        case SetDutyCycle:
            track->currentVoice = *track->nextInstruction++;
            break;
        case SetDutyCyclePattern:
            // Not implemented
            track->nextInstruction++;
            break;
        case Arpeggiate:
        {
            // TODO: This is nothing like the command in the Crystal engine, investigate
            u8 byte2 = *track->nextInstruction++;
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
            break;
        }
        case PitchBend:
        {
            u8 byte2 = 0;
            track->pitchBendDuration = *track->nextInstruction++;
            byte2 = *track->nextInstruction++;
            track->pitchBendTarget = CalculatePitch(byte2 & 0xF, track->keyShift, (byte2 & 0xF0) >> 4, 0);
            track->statusFlags[PitchBendActivation] = TRUE;
            break;
        }
        case Portamento:
            // No data for this as yet as it is a completely custom effect
            // At least it is in terms of this engine, since the
            // portamento effect is not present in RBY or GSC
            track->statusFlags[PortamentoActivation] = TRUE;
            track->portamentoDelay = *track->nextInstruction++;
            track->portamentoSpeed = *track->nextInstruction++;
            track->portamentoTarget = CalculatePitch((*track->nextInstruction++ & 0xF0) >> 4, track->keyShift, track->currentOctave, track->tone);
            break;
        case SetModulation:
        {
            u8 modulationDelay = *track->nextInstruction++;
            u8 byte2 = *track->nextInstruction++;
            if (byte2 != 0)
            {
                track->statusFlags[ModulationActivation] = TRUE;
                track->statusFlags[ModulationDir] = FALSE;
                track->modulationDelay = modulationDelay;
                track->modulationDelayCount = track->modulationDelay;
                track->modulationMode = 0;
                track->modulationDepth = (byte2 & 0xF0) >> 4;
                track->modulationSpeed = byte2 & 0xF;
                track->modulationSpeedCount = track->modulationSpeed;
            }
            else
            {
                track->statusFlags[ModulationActivation] = FALSE;
            }
            break;
        }
        case SetChannelVolume:
        {
            // TODO: Should be global, not channel volume
            u8 volume = *track->nextInstruction++;
            if (track->channelVolume != volume)
            {
                track->channelVolume = volume;
                if (!IsM4AUsingCGBChannel(track->trackID - 1))
                {
                    vu8 *control = SoundControl();
                    control[0] = track->channelVolume;
                }
            }
            break;
        }
        case SetTone:
            track->tone = UShortEndianSwap(T1_READ_16(track->nextInstruction));
            track->nextInstruction += 2;
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
    }
    return *track->nextInstruction;
}

u16 GetModulationPitch(struct GBSTrack *track)
{
    u16 newPitch = track->pitch;
    track->statusFlags[ModulationDir] = !track->statusFlags[ModulationDir];
    track->modulationSpeedCount = track->modulationSpeed;
    switch (track->modulationMode)
    {
        case 0:
        {
            u8 halfValue = track->modulationDepth >> 1;
            if (track->statusFlags[ModulationDir])
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
            if (track->statusFlags[ModulationDir])
            {
                newPitch -= track->modulationDepth;
            }
            break;
        case 2:
            if (track->statusFlags[ModulationDir])
            {
                newPitch += track->modulationDepth;
            }
            break;
    }
    return newPitch;
}

void ToneTrack_ModulateTrack(struct GBSTrack *track)
{
    if (track->statusFlags[PitchBendActivation])
    {
        if (track->pitchBendDir)
        {
            u32 unk = track->pitchBendUnk;
            track->pitch += track->pitchBendAmount;
            unk += track->pitchBendFraction;
            if (unk >= 0x100)
            {
                // rollover
                track->pitch++;
            }
            track->pitchBendUnk = unk & 0xFF;
            if (track->pitch > track->pitchBendTarget)
            {
                track->statusFlags[PitchBendActivation] = FALSE;
                track->pitchBendDir = FALSE;
            }
        }
        else
        {
            u32 unk = track->pitchBendFraction;
            track->pitch -= track->pitchBendAmount;
            unk *= 2;
            if (unk >= 0x100)
            {
                // rollover
                track->pitch--;
            }
            track->pitchBendFraction = unk & 0xFF;
            if (track->pitch < track->pitchBendTarget)
            {
                track->statusFlags[PitchBendActivation] = FALSE;
                track->pitchBendDir = FALSE;
            }
        }
        if (!IsM4AUsingCGBChannel(track->trackID - 1))
        {
            vu16 *control = ToneTrackControl();
            u16 location = ((track->trackID - 1) * 4) + 2;
            control[location] = (control[location] & 0x8000) | track->pitch;
        }
    }

    if (track->statusFlags[PortamentoActivation])
    {
        if (track->portamentoCountdown > 0)
        {
            track->portamentoCountdown--;
        }
        else
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
    }
    
    if (track->statusFlags[ModulationActivation])
    {
        if (track->modulationDelayCount > 0)
        {
            track->modulationDelayCount--;
        }
        else if (track->modulationDepth != 0)
        {
            if (track->modulationSpeedCount > 0)
            {
                track->modulationSpeedCount--;
            }
            else if (track->pitch != 0)
            {
                u16 modulatedPitch = GetModulationPitch(track);
                if (!IsM4AUsingCGBChannel(track->trackID - 1))
                {
                    vu16 *control = ToneTrackControl();
                    u16 location = ((track->trackID - 1) * 4) + 2;
                    control[location] = (control[location] & 0x8000) | modulatedPitch;
                }
            }
        }
    }
}

void ToneTrack_ArpeggiateTrack(struct GBSTrack *track)
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
            if (!IsM4AUsingCGBChannel(track->trackID - 1))
            {
                vu16 *control = ToneTrackControl();
                control[location] = (control[location] & 0xFF00) | (((track->statusFlags[ArpeggiationStatus]) ? track->currentVoice : track->arpeggiationVoice) << 6);
            }
            track->statusFlags[ArpeggiationStatus] = !track->statusFlags[ArpeggiationStatus];
        }
    }
}

bool16 ToneTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    bool16 result = TRUE;

    if (track->noteLength1 < 2)
    {
        u32 commandID = *track->nextInstruction;
        while (commandID >= SetOctave7)
        {
            commandID = ToneTrack_ProcessCommands(info, track);
            if (commandID == End && track->returnLocation == NULL)
            {
                ToneTrack_ExecuteModifications(0, info->gbsTempo, track);
                result = FALSE;
                break;
            }
        }

        if (commandID != End)
        {
            ToneTrack_ExecuteModifications(commandID, info->gbsTempo, track);
            track->nextInstruction++;
            track->modulationDelayCount = track->modulationDelay;
            ToneTrack_ModulateTrack(track);

            track->arpeggiationCountdown = (track->statusFlags[ArpeggiationActivation]) ? track->arpeggiationDelayCount : 0;
            track->statusFlags[ArpeggiationStatus] = FALSE;
            track->statusFlags[PortamentoActivation] = FALSE;
        }
    }
    else
    {
        track->noteLength1--;
        ToneTrack_ModulateTrack(track);
        ToneTrack_ArpeggiateTrack(track);
    }

    if (track->trackID == 1)
    {
        if (!IsM4AUsingCGBChannel(track->trackID - 1))
        {
            // TODO: This should be removed when pitch bend is implemented.
            // This code is ensuring no pitch slide values are set, since no
            // pokecrystal engine feature uses pitch slide except pitch bend.
            vu16 *control = ToneTrackControl();
            control[0] = 0;
        }

        SetMasterVolumeFromFade(track->volX);
    }

    return result;
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

void WaveTrack_SwitchWavePattern(int patternID)
{
    int i;
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu16* control = WaveTrackControl();
    if (patternID < ARRAY_COUNT(sWaveTrackPatterns) && soundInfo->cgbChans[CGBCHANNEL_WAVE].cp != (u32)sWaveTrackPatterns[patternID])
    {
        u32* mainPattern = (u32 *)(REG_ADDR_WAVE_RAM0);
        control[0] = 0x40;
        for (i = 0; i < 4; i++)
            mainPattern[i] = sWaveTrackPatterns[patternID][i];
        soundInfo->cgbChans[CGBCHANNEL_WAVE].cp = (u32)sWaveTrackPatterns[patternID];
        control[0] = 0x0;
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

void WaveTrack_ExecuteModifications(u8 commandID, u16 tempo, struct GBSTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u16 thisVelocity = 0;
    u16 thisPitch = 0;
    u16 activationValue = 0;
    u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);

    track->noteLength1 = (noteLength & 0xFF00) >> 8;
    track->noteLength2 = noteLength & 0xFF;

    if (commandID & 0xF0)
    {
        track->pitch = CalculatePitch((commandID & 0xF0) >> 4, track->keyShift, track->currentOctave, track->tone);
        thisVelocity = track->velocity << 13;
        thisPitch = track->pitch | 0x8000;
        activationValue = 0x80;
        
        if (!IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
        {
            vu8 *soundControl = SoundControl();
            u8 thisPan = soundInfo->cgbChans[track->trackID - 1].panMask;

            if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
                thisPan &= track->pan;
            soundControl[1] = (soundControl[1] & ~soundInfo->cgbChans[track->trackID - 1].panMask) | thisPan;

            vu16 *control = WaveTrackControl();
            control[0] = activationValue;
            control[1] = thisVelocity;
            control[2] = thisPitch;
        }
    }
    else if (!IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
    {
        WaveTrack_Reset();
    }
}

void WaveTrack_ModulateTrack(struct GBSTrack *track)
{
    if (track->statusFlags[PitchBendActivation])
    {
        track->pitch += track->pitchBendRate;
    }

    if (track->statusFlags[ModulationActivation])
    {
        if (track->modulationDelayCount > 0)
        {
            track->modulationDelayCount--;
        }
        else if (track->modulationDepth != 0)
        {
            if (track->modulationSpeedCount > 0)
            {
                track->modulationSpeedCount--;
            }
            else if (track->pitch != 0)
            {
                u16 modulatedPitch = GetModulationPitch(track);
                if (!IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
                {
                    vu16 *control = WaveTrackControl();
                    control[2] = (control[2] & 0x8000) | modulatedPitch;
                }
            }
        }
    }
}

bool16 WaveTrack_ProcessCommands(struct GBSTrack *track)
{
    u8 commandID = *track->nextInstruction++; // grab next byte and increment pointer

    switch (commandID)
    {
        case SetOctave7 ... SetOctave0:
            track->currentOctave = commandID & 7;
            break;
        case SetNoteAttributesAndLength:
        {
            u8 byte2 = *track->nextInstruction++;
            track->frameDelay = byte2;
            byte2 = *track->nextInstruction++;
            track->velocity = (byte2 & 0x70) >> 4;
            u8 newVoice = byte2 & 0xF;
            if (track->currentVoice != newVoice && !IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
            {
                WaveTrack_SwitchWavePattern(newVoice);
            }
            track->currentVoice = newVoice;
            break;
        }
        case SetNoteAttributes:
        {
            u8 byte2 = *track->nextInstruction++;
            u8 newVoice = byte2 & 0xF;
            track->velocity = (byte2 & 0x70) >> 4;
            if (track->currentVoice != newVoice && !IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
            {
                WaveTrack_SwitchWavePattern(newVoice);
            }
            track->currentVoice = newVoice;
            break;
        }
        case SetKeyShift:
            track->keyShift = *track->nextInstruction++;
            break;
        case SetDutyCycle:
            // Not used in wave track
            track->nextInstruction++;
        case SetDutyCyclePattern:
            // Not used in wave track
            track->nextInstruction++;
            break;
        case Arpeggiate:
            // Not implemented
            track->nextInstruction++;
            break;
        case PitchBend:
            // Not implemented
            track->nextInstruction += 2;
            break;
        case SetModulation:
        {
            u8 modulationDelay = *track->nextInstruction++;
            u8 theByte = *track->nextInstruction++;
            if (theByte != 0)
            {
                track->statusFlags[ModulationActivation] = TRUE;
                track->statusFlags[ModulationDir] = FALSE;
                track->modulationDelay = modulationDelay;
                track->modulationDelayCount = track->modulationDelay;
                track->modulationMode = 0;
                track->modulationDepth = (theByte & 0xF0) >> 4;
                track->modulationSpeed = theByte & 0xF;
                track->modulationSpeedCount = track->modulationSpeed;
            }
            else
            {
                track->statusFlags[ModulationActivation] = FALSE;
            }
            break;
        }
        case SetTone:
            track->tone = UShortEndianSwap(T1_READ_16(track->nextInstruction));
            track->nextInstruction += 2;
            break;
        case Pan:
            track->pan = *track->nextInstruction++;
            break;
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

bool16 WaveTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    bool16 result = TRUE;

    // The M4A sound effects can change the wave pattern.
    // We want to reload the correct wave pattern for this track when
    // control is returned to GBS from M4A.
    if (!IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
    {
        gWaveTrackShouldReloadPattern = TRUE;
    }
    else if (gWaveTrackShouldReloadPattern)
    {
        WaveTrack_SwitchWavePattern(track->currentVoice);
        gWaveTrackShouldReloadPattern = FALSE;
    }

    if (track->noteLength1 < 2)
    {
        u32 commandID = *track->nextInstruction;
        while (commandID >= SetOctave7)
        {
            commandID = WaveTrack_ProcessCommands(track);
            if (commandID == End && track->returnLocation == NULL)
            {
                WaveTrack_ExecuteModifications(0, info->gbsTempo, track);
                result = FALSE;
                break;
            }
        }
        if (commandID != End)
        {
            WaveTrack_ExecuteModifications(commandID, info->gbsTempo, track);
            track->nextInstruction++;
            track->modulationDelayCount = track->modulationDelay;
            WaveTrack_ModulateTrack(track);
        }
    }
    else
    {
        track->noteLength1--;
        WaveTrack_ModulateTrack(track);
    }

    return result;
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

u8 NoiseTrack_ProcessCommands(struct GBSTrack *track)
{
    u8 commandID = *track->nextInstruction++;

    switch (commandID)
    {
        case SetNoteAttributesAndLength:
            track->frameDelay = *track->nextInstruction++;
            break;
        case NoiseSet:
            track->currentVoice = *track->nextInstruction++;
            break;
        case Pan:
            track->pan = *track->nextInstruction++;
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

void NoiseTrack_WritePattern(struct GBSTrack *track)
{
    if (track->samplePointer[0] != 0xFF)
    {
        u16 value1 = (track->samplePointer[0] & 0xF);
        u16 value2 = (track->samplePointer[1] << 8) | 0x3F;
        u16 value3 = track->samplePointer[2] | 0x8000;
        track->noiseActive = TRUE;
        track->noiseFrameDelay = value1;
        track->samplePointer += 3;
        if (!IsM4AUsingCGBChannel(CGBCHANNEL_NOISE))
        {
            vu16 *control = NoiseTrackControl();
            control[0] = value2;
            control[2] = value3;
        }
    }
    else
    {
        track->noiseActive = 0;
        track->noiseFrameDelay = 0;
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

void NoiseTrack_ExecuteModifications(u8 commandID, u16 tempo, struct GBSTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);
    u8 thisPan = soundInfo->cgbChans[track->trackID - 1].panMask;
    
    track->noteLength1 = (noteLength & 0xFF00) >> 8;
    track->noteLength2 = noteLength & 0xFF;

    // Check if command is rest
    if (commandID & 0xF0)
    {
        u32 engineSet = track->currentVoice;
        const u8 *const *noiseGroup = sNoiseDataGroupTable[engineSet];
        const u8 *noiseData = NULL;
        
        noiseData = noiseGroup[(commandID & 0xF0) >> 4];
        track->samplePointer = noiseData;

        if (!IsM4AUsingCGBChannel(CGBCHANNEL_NOISE))
        {
            vu8 *soundControl = SoundControl();
            
            if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
                thisPan &= track->pan;
            soundControl[1] = (soundControl[1] & ~soundInfo->cgbChans[track->trackID - 1].panMask) | thisPan;
        }
        
        NoiseTrack_WritePattern(track);
    }
    else if (!IsM4AUsingCGBChannel(CGBCHANNEL_NOISE))
    {
        // If resting but we have control, clear the track
        NoiseTrack_Reset();
    }
}

bool16 NoiseTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    bool16 result = TRUE;

    if (track->noteLength1 < 2)
    {
        u32 commandID = *track->nextInstruction;
        while (commandID >= SetOctave7)
        {
            commandID = NoiseTrack_ProcessCommands(track);
            if (commandID == End && track->returnLocation == NULL)
            {
                NoiseTrack_ExecuteModifications(0, info->gbsTempo, track);
                result = FALSE;
                break;
            }
        }
        if (commandID != End)
        {
            NoiseTrack_ExecuteModifications(commandID, info->gbsTempo, track);
            track->nextInstruction++;
        }
        else
        {
            track->noiseActive = 0;
            track->noiseFrameDelay = 0;
        }
    }
    else
    {
        track->noteLength1--;
        if (track->noiseActive == 1)
        {
            if (track->noiseFrameDelay == 0)
            {
                NoiseTrack_WritePattern(track);
            }
            else
            {
                track->noiseFrameDelay--;
            }
        }
    }

    return result;
}

bool16 GBSTrack_Update(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    struct GBSTrack *gbsTrack = (struct GBSTrack *)track;
    bool16 success = FALSE;
    
    // Set bias level to 0 for less crunch
    // Always set here since m4a engine may have changed it
    // TODO: Use SWI instead
    REG_SOUNDBIAS = REG_SOUNDBIAS & 0xFC00;

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
        gUsedCGBChannels[gbChannel] = FALSE;
        
        switch (gbChannel)
        {
            case 0:
            case 1:
                ToneTrack_Reset(gbChannel);
                break;
            case 2:
                WaveTrack_Reset();
                WaveTrack_SwitchWavePattern(0);
                gWaveTrackShouldReloadPattern = FALSE;
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
