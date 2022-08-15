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

bool8 gWaveTrackShouldReloadPattern;

static inline u32 LoadUInt(u8 *source, u32 offset)
{
    return *(source + offset) | (*(source + offset + 1) << 8) | (*(source + offset + 2) << 16) | (*(source + offset + 3) << 24);
}

static inline u8 *LoadUIntPointer(u8 *source, u32 offset)
{
    return (u8 *)LoadUInt(source, offset);
}

static inline u16 LoadUShortNumber(u8 *source, u32 offset)
{
    return *(source + offset) | (*(source + offset + 1) << 8);
}

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

// Is m4a engine using GB channel? If so, don't render
static inline bool32 ShouldRenderSound(int trackID)
{
    return gUsedGBChannels[trackID] == FALSE;
}

static inline bool32 ShouldRenderWaveChannel()
{
    return ShouldRenderSound(2);
}

static inline bool32 ShouldRenderNoiseChannel()
{
    return ShouldRenderSound(3);
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
    s16 freq = (sFrequencyTable[noteShifted] >> (octaveShifted)) & 0x7FF;
    return freq + tone;
}

void ToneTrack_Reset(int trackID)
{
    vu16 *control = ToneTrackControl() + (trackID * 4);
    vu8 *soundControl = SoundControl();

    soundControl[1] &= ~gCgbChans[trackID].panMask;

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

void ToneTrack_ExecuteModifications(u8 commandID, u16 tempo, struct ToneTrack *track)
{
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
        
        if (ShouldRenderSound(track->trackID - 1))
        {
            vu16 *control = ToneTrackControl() + ((track->trackID - 1) * 4);
            vu8 *soundControl = SoundControl();
            u8 thisPan = gCgbChans[track->trackID - 1].panMask;

            if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
                thisPan &= track->pan;
            soundControl[1] = (soundControl[1] & ~gCgbChans[track->trackID - 1].panMask) | thisPan;

            if (track->trackID == 2)
                control[0] = thisVoiceVolVelocity;
            else
                control[1] = thisVoiceVolVelocity;

            control[2] = thisPitch;
        }
    }
    else if (ShouldRenderSound(track->trackID - 1))
    {
        ToneTrack_Reset(track->trackID - 1);
    }
}

u8 ToneTrack_ExecuteCommands(u8 commandID, struct MusicPlayerInfo *info, struct ToneTrack *track)
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
                track->keyShift = track->nextInstruction[1];
                commandLength = 2;
                break;
            }
            case SetTempo:
                if (track->trackID == 1)
                {
                    info->gbsTempo = UShortEndianSwap(LoadUShortNumber(track->nextInstruction, 1));
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
                track->portamentoTarget = CalculatePitch((track->nextInstruction[3] & 0xF0) >> 4, track->keyShift, track->currentOctave, track->tone);
                commandLength = 4;
                break;
            case SetModulation:
            {
                byte2 = track->nextInstruction[2];
                if (byte2 != 0)
                {
                    track->statusFlags[ModulationActivation] = TRUE;
                    track->statusFlags[ModulationStatus] = FALSE;
                    //track->modulationDelay = track->nextInstruction[1] & 0x3F;
                    //track->modulationMode = (track->nextInstruction[1] & 0xC0) >> 6;
                    track->modulationDelay = track->nextInstruction[1];
                    track->modulationMode = 0;
                    track->modulationDepth = (byte2 & 0xF0) >> 4;
                    track->modulationSpeed = byte2 & 0xF;
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
                        vu8 *control = SoundControl();
                        control[0] = track->channelVolume;
                    }
                }
                commandLength = 2;
                break;
            case SetTone:
                track->tone = UShortEndianSwap(LoadUShortNumber(track->nextInstruction, 1));
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
                if (track->returnLocation == NULL)
                {
                    return 0xFF;
                }
                else
                {
                    track->nextInstruction = track->returnLocation;
                    track->returnLocation = NULL;
                }
                break;
        }
    }
    track->nextInstruction += commandLength;
    return track->nextInstruction[0];
}

u16 ToneTrack_GetModulationPitch(struct ToneTrack *track)
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

void ToneTrack_ModulateTrack(struct ToneTrack *track)
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
            if (track->modulationSpeedDelay == 0 && track->pitch != 0)
            {
                u16 modulatedPitch = ToneTrack_GetModulationPitch(track);
                if (ShouldRenderSound(track->trackID - 1))
                {
                    vu16 *control = ToneTrackControl();
                    u16 location = ((track->trackID - 1) * 4) + 2;
                    control[location] = (control[location] & 0x8000) | modulatedPitch;
                }
            }
            else
            {
                track->modulationSpeedDelay--;
            }
        }
    }
}

void ToneTrack_ResetModulationArpeggiationCounters(struct ToneTrack *track)
{
    track->modulationCountdown = track->modulationDelay;
    track->statusFlags[ModulationStatus] = FALSE;
    track->modulationSpeedDelay = track->modulationSpeed;
    if (track->modulationCountdown == 0)
    {
        ToneTrack_ModulateTrack(track);
    }
    track->arpeggiationCountdown = (track->statusFlags[ArpeggiationActivation]) ? track->arpeggiationDelayCount : 0;
    track->statusFlags[ArpeggiationStatus] = FALSE;
    track->statusFlags[PortamentoActivation] = FALSE;
    track->statusFlags[PitchBendActivation] = FALSE;
}

void ToneTrack_ArpeggiateTrack(struct ToneTrack *track)
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

bool16 ToneTrack_Update(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    struct ToneTrack *toneTrack = (struct ToneTrack *)track;
    bool16 result = TRUE;

    if (toneTrack->noteLength1 < 2)
    {
        u32 commandID = *track->cmdPtr;
        while (commandID >= 0xD0)
        {
            commandID = ToneTrack_ExecuteCommands(commandID, info, toneTrack);
            if (commandID == 0xFF && toneTrack->returnLocation == 0)
            {
                ToneTrack_ExecuteModifications(0, info->gbsTempo, toneTrack);
                result = FALSE;
                break;
            }
        }
        if (commandID != 0xFF)
        {
            ToneTrack_ExecuteModifications(commandID, info->gbsTempo, toneTrack);
            toneTrack->nextInstruction++;
            ToneTrack_ResetModulationArpeggiationCounters(toneTrack);
        }
    }
    else
    {
        toneTrack->noteLength1--;
        // Modulation and arpeggiation may need to run regardless
        // of note over
        ToneTrack_ModulateTrack(toneTrack);
        ToneTrack_ArpeggiateTrack(toneTrack);
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
    vu16* control = WaveTrackControl();
    if (patternID < ARRAY_COUNT(sWaveTrackPatterns) && gCgbChans[2].cp != (u32)sWaveTrackPatterns[patternID])
    {
        u32* mainPattern = (u32 *)(REG_ADDR_WAVE_RAM0);
        control[0] = 0x40;
        for (i = 0; i < 4; i++)
            mainPattern[i] = sWaveTrackPatterns[patternID][i];
        gCgbChans[2].cp = (u32)sWaveTrackPatterns[patternID];
        control[0] = 0x0;
    }
}

void WaveTrack_Reset()
{
    vu16 *control = WaveTrackControl();
    vu8 *soundControl = SoundControl();

    soundControl[1] &= ~gCgbChans[2].panMask;

    control[0] = 0;
    control[1] = 0x800;
    control[2] = 0x8000;
}

void WaveTrack_ExecuteModifications(u8 commandID, u16 tempo, struct WaveTrack *track)
{
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
        
        if (ShouldRenderWaveChannel())
        {
            vu8 *soundControl = SoundControl();
            u8 thisPan = gCgbChans[track->gbsIdentifier - 1].panMask;

            if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
                thisPan &= track->pan;
            soundControl[1] = (soundControl[1] & ~gCgbChans[track->gbsIdentifier - 1].panMask) | thisPan;

            vu16 *control = WaveTrackControl();
            control[0] = activationValue;
            control[1] = thisVelocity;
            control[2] = thisPitch;
        }
    }
    else if (ShouldRenderWaveChannel())
    {
        WaveTrack_Reset();
    }
}

void WaveTrack_ModulateTrack(struct WaveTrack *track)
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
                // TODO: Merge with ToneTrack_GetModulationPitch
                u16 outPitch = track->pitch;
                track->statusFlags[ModulationStatus] = !track->statusFlags[ModulationStatus];
                track->modulationSpeedDelay = track->modulationSpeed;
                switch (track->modulationMode)
                {
                    case 0:
                    {
                        u8 halfValue = track->modulationDepth >> 1;
                        if (track->statusFlags[ModulationStatus])
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
                        if (track->statusFlags[ModulationStatus])
                        {
                            outPitch -= track->modulationDepth;
                        }
                        break;
                    case 2:
                        if (track->statusFlags[ModulationStatus])
                        {
                            outPitch += track->modulationDepth;
                        }
                        break;
                }
                if (ShouldRenderWaveChannel())
                {
                    vu16 *control = WaveTrackControl();
                    control[2] = (control[2] & 0x8000) | outPitch;
                }
            }
            else
            {
                track->modulationSpeedDelay--;
            }
        }
    }
}

bool16 WaveTrack_ExecuteCommands(u8 commandID, struct WaveTrack *track)
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
            case SetNoteAttributesAndLength:
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
                    WaveTrack_SwitchWavePattern(newVoice);
                }
                track->currentVoice = newVoice;
                commandLength = 3;
                break;
            }
            case SetKeyShift:
            {
                track->keyShift = track->nextInstruction[1];
                commandLength = 2;
                break;
            }
            case SetDutyCycle:
            case SetDutyCycle2:
                track->currentVoice = track->nextInstruction[1];
                commandLength = 2;
                break;
            case SetNoteAttributes:
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
                    WaveTrack_SwitchWavePattern(newVoice);
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
            case PitchBend:
                commandLength = 3;
                break;
            case SetModulation:
            {
                u8 theByte = track->nextInstruction[2];
                if (theByte != 0)
                {
                    track->statusFlags[ModulationActivation] = TRUE;
                    track->statusFlags[ModulationStatus] = FALSE;
                    //track->modulationDelay = track->nextInstruction[1] & 0x3F;
                    //track->modulationMode = (track->nextInstruction[1] & 0xC0) >> 6;
                    track->modulationDelay = track->nextInstruction[1];
                    track->modulationMode = 0;
                    track->modulationDepth = (theByte & 0xF0) >> 4;
                    track->modulationSpeed = theByte & 0xF;
                }
                else
                {
                    track->statusFlags[ModulationActivation] = FALSE;
                }
                commandLength = 3;
                break;
            }
            case SetTone:
                track->tone = UShortEndianSwap(LoadUShortNumber(track->nextInstruction, 1));
                commandLength = 3;
                break;
            case Pan:
            {
                u8 byte = track->nextInstruction[1];
                track->pan = (byte == 0) ? 0xFF : byte;
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

bool16 WaveTrack_Update(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    struct WaveTrack *waveTrack = (struct WaveTrack *)track;
    bool16 result = TRUE;

    // The M4A sound effects can change the wave pattern.
    // We want to reload the correct wave pattern for this track when
    // control is returned to GBS from M4A.
    if (!ShouldRenderWaveChannel())
    {
        gWaveTrackShouldReloadPattern = TRUE;
    }
    else if (gWaveTrackShouldReloadPattern)
    {
        WaveTrack_SwitchWavePattern(waveTrack->currentVoice);
        gWaveTrackShouldReloadPattern = FALSE;
    }

    if (waveTrack->noteLength1 < 2)
    {
        u32 commandID = waveTrack->nextInstruction[0];
        while (commandID >= 0xD0)
        {
            commandID = WaveTrack_ExecuteCommands(commandID, waveTrack);
            if (commandID == 0xFF && waveTrack->returnLocation == 0)
            {
                WaveTrack_ExecuteModifications(0, info->gbsTempo, waveTrack);
                result = FALSE;
                break;
            }
        }
        if (commandID != 0xFF)
        {
            WaveTrack_ExecuteModifications(commandID, info->gbsTempo, waveTrack);
            waveTrack->nextInstruction++;
            waveTrack->modulationCountdown = waveTrack->modulationDelay;
            waveTrack->statusFlags[ModulationStatus] = FALSE;
            waveTrack->modulationSpeedDelay = waveTrack->modulationSpeed;
            WaveTrack_ModulateTrack(waveTrack);
        }
    }
    else
    {
        waveTrack->noteLength1--;
        WaveTrack_ModulateTrack(waveTrack);
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

u8 NoiseTrack_ExecuteCommands(u8 commandID, struct NoiseTrack *track)
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

void NoiseTrack_WritePattern(struct NoiseTrack *track)
{
    if (track->samplePointer[0] != 0xFF)
    {
        u16 value1 = (track->samplePointer[0] & 0xF);
        u16 value2 = (track->samplePointer[1] << 8) | 0x3F;
        u16 value3 = track->samplePointer[2] | 0x8000;
        track->noiseActive = TRUE;
        track->noiseFrameDelay = value1;
        track->samplePointer += 3;
        if (ShouldRenderNoiseChannel())
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
    vu16 *control = NoiseTrackControl();
    vu8 *soundControl = SoundControl();

    soundControl[1] &= ~gCgbChans[3].panMask;

    control[0] = 0x800;
    control[2] = 0x8000;
}

void NoiseTrack_ExecuteModifications(u8 commandID, u16 tempo, struct NoiseTrack *track)
{
    u16 noteLength = CalculateLength(track->frameDelay, tempo, (commandID & 0xF), track->noteLength2);
    u8 thisPan = gCgbChans[track->gbsIdentifier - 1].panMask;
    
    track->noteLength1 = (noteLength & 0xFF00) >> 8;
    track->noteLength2 = noteLength & 0xFF;

    // Check if command is rest
    if (commandID & 0xF0)
    {
        u32 engineSet = track->noiseSet;
        const u8 *const *noiseGroup = sNoiseDataGroupTable[engineSet];
        const u8 *noiseData = NULL;
        
        noiseData = noiseGroup[(commandID & 0xF0) >> 4];
        track->samplePointer = noiseData;

        if (ShouldRenderNoiseChannel())
        {
            vu8 *soundControl = SoundControl();
            
            if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
                thisPan &= track->pan;
            soundControl[1] = (soundControl[1] & ~gCgbChans[track->gbsIdentifier - 1].panMask) | thisPan;
        }
        
        // NoiseTrack_WritePattern has its own check for ShouldRenderNoiseChannel, but also updates other stuff, so run it
        NoiseTrack_WritePattern(track);
    }
    else if (ShouldRenderNoiseChannel())
    {
        // If resting but we have control, clear the track
        NoiseTrack_Reset();
    }
}

bool16 NoiseTrack_Update(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    struct NoiseTrack *noiseTrack = (struct NoiseTrack *)track;
    bool16 result = TRUE;

    if (noiseTrack->noteLength1 < 2)
    {
        u32 commandID = noiseTrack->nextInstruction[0];
        while (commandID >= 0xD0)
        {
            commandID = NoiseTrack_ExecuteCommands(commandID, noiseTrack);
            if (commandID == 0xFF && noiseTrack->returnLocation == 0)
            {
                NoiseTrack_ExecuteModifications(0, info->gbsTempo, noiseTrack);
                result = FALSE;
                break;
            }
        }
        if (commandID != 0xFF)
        {
            NoiseTrack_ExecuteModifications(commandID, info->gbsTempo, noiseTrack);
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
            if (noiseTrack->noiseFrameDelay == 0)
            {
                NoiseTrack_WritePattern(noiseTrack);
            }
            else
            {
                noiseTrack->noiseFrameDelay--;
            }
        }
    }

    return result;
}

bool16 GBSTrack_Update(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    bool16 success = FALSE;
    
    // Set bias level to 0 for less crunch
    // Always set here since m4a engine may have changed it
    // TODO: Use SWI instead
    REG_SOUNDBIAS = REG_SOUNDBIAS & 0xFC00;

    switch (track->gbsIdentifier - 1)
    {
        case 2:
            // Wave Track Update
            success = WaveTrack_Update(info, track);
            break;
        case 3:
            // Noise Track Update
            success = NoiseTrack_Update(info, track);
            break;
        default:
            // Tone Track Update
            success = ToneTrack_Update(info, track);
            break;
    }

    return success;
}

void ply_gbs_switch(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 *cmdPtrBackup = track->cmdPtr;
    u8 gbChannel = *cmdPtrBackup++;

    if (gbChannel < 4)
    {
        memset(track, 0, sizeof(*track));
        track->gbsIdentifier = gbChannel + 1;
        track->cmdPtr = cmdPtrBackup;
        track->pan = 0xFF;
        track->flags = MPT_FLG_EXIST;

        // Clear used bit from previous song.
        gUsedGBChannels[gbChannel] = FALSE;
        
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
