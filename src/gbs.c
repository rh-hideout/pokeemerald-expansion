/*
 * gbs.c
 *
 *  Created on: 21 May 2018
 *      Author: Jambo51
 *  Revised for M4A integration in: February 2020
 *      Author: huderlem
 *  Integration finalized in: August 2022
 *      Author: Sierraffinity
 */

#include "global.h"
#include "gba/m4a_internal.h"
#include "gbs.h"
#include "m4a.h"

static bool32 GBSTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track);
static void ApplyPitchBend(struct GBSTrack *track);
static void ApplyDutyCycle(struct GBSTrack *track);
static u16 ApplyPitchOffset(struct GBSTrack *track, u16 pitch);
static u16 ApplyModulation(struct GBSTrack *track, u16 pitch);
static void ApplyNoise(struct GBSTrack *track);
static u8 ProcessCommands(struct MusicPlayerInfo *info, struct GBSTrack *track);
static void ProcessNoteCommand(u8 commandID, u16 tempo, struct GBSTrack *track);
static void UpdateCGBChannel(struct GBSTrack *track, u16 pitch);
static void UpdateCGBTone1(struct GBSTrack *track, u16 pitch);
static void UpdateCGBTone2(struct GBSTrack *track, u16 pitch);
static void UpdateCGBWave(struct GBSTrack *track, u16 pitch);
static void UpdateCGBNoise(struct GBSTrack *track);
static void UpdateStereoPan(struct GBSTrack *track);
static void UpdateDutyEnvelopeVelocity(struct GBSTrack *track, vu8 *lengthDuty, vu8 *envelopeVelocity);
static void LoadWavePattern(struct GBSTrack *track, int patternID);
static inline bool32 IsM4AUsingCGBChannel(int channel);
static u32 GetMasterVolumeFromFade(u32 volX);
static u16 CalculateNoteLength(u8 noteUnitLength, u16 tempo, u8 length, u16 previousLeftover);
static u16 CalculatePitch(u8 note, s8 keyShift, u8 octave);
static void ClearCGBChannel(struct GBSTrack *track);

#include "data/gbs.h"

static bool32 GBSTrack_Update(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    bool32 trackActive = TRUE;
    u16 thisPitch = 0;

    // The M4A sound effects can change instrument data out from under us.
    // We want to reload the correct values for this track when
    // control is returned to GBS from M4A.
    if (IsM4AUsingCGBChannel(track->channelID - 1))
    {
        track->shouldReload = TRUE;
    }
    else if (track->shouldReload)
    {
        switch (track->channelID - 1)
        {
            case CGBCHANNEL_TONE1:
                track->notePitchSweep = TRUE;
                track->pitchSweep = 0;
                break;
            case CGBCHANNEL_WAVE:
                LoadWavePattern(track, track->envelope);
                break;
            default:
                break;
        }
        track->shouldReload = FALSE;
    }

    if (track->noteLength1 < 2)
    {
        trackActive = ProcessCommands(info, track);
    }
    else
    {
        track->noteLength1--;
    }

    if ((track->channelID - 1) == CGBCHANNEL_TONE1)
    {
        ApplyPitchBend(track);
    }

    thisPitch = track->pitch;

    ApplyDutyCycle(track);
    thisPitch = ApplyPitchOffset(track, thisPitch);
    thisPitch = ApplyModulation(track, thisPitch);
    ApplyNoise(track);

    // BGM tracks must yield hardware writes to any active SFX on the same channel.
    if (!track->isSFXChannel && (gGBSSFXActiveMask & (1 << (track->channelID - 1))))
    {
        return trackActive;
    }

    UpdateCGBChannel(track, thisPitch);

    return trackActive;
}

static void ApplyPitchBend(struct GBSTrack *track)
{
    if (track->pitchBendActivation)
    {
        u16 pitch = track->pitch;
        if (track->pitchBendDir)
        {
            u32 fractionAccumulator = track->pitchBendFractionAccumulator;
            pitch += track->pitchBendAmount;
            fractionAccumulator += track->pitchBendFraction;
            if (fractionAccumulator >= 0x100)
            {
                // rollover
                pitch++;
            }
            track->pitchBendFractionAccumulator = fractionAccumulator & 0xFF;
            if (pitch < track->pitchBendTarget)
            {
                track->pitch = pitch;
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
            pitch -= track->pitchBendAmount;
            fractionAccumulator *= 2;
            if (fractionAccumulator >= 0x100)
            {
                // rollover
                pitch--;
            }
            track->pitchBendFraction = fractionAccumulator & 0xFF;
            if (pitch > track->pitchBendTarget)
            {
                track->pitch = pitch;
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

static void ApplyDutyCycle(struct GBSTrack *track)
{
    if (track->dutyCycleLoop)
    {
        track->dutyCycle = (track->dutyCyclePattern & 0xC0) >> 6;
        track->dutyCyclePattern = (track->dutyCyclePattern << 2) | track->dutyCycle;
        track->noteDutyOverride = TRUE;
    }
}

static u16 ApplyPitchOffset(struct GBSTrack *track, u16 pitch)
{
    if (track->pitchOffset)
    {
        // Should tone be signed? (CrystalDust) - changed tone from u16 to s16 (HnS - Skeletonkey36)
        pitch += track->tone;
    }
    
    return pitch;
}

static u16 ApplyModulation(struct GBSTrack *track, u16 pitch)
{
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
                            pitch += (track->modulationDepth - halfValue);
                        }
                        else
                        {
                            pitch -= halfValue;
                        }
                        break;
                    }
                    case 1:
                        if (track->modulationDir)
                        {
                            pitch -= track->modulationDepth;
                        }
                        break;
                    case 2:
                        if (track->modulationDir)
                        {
                            pitch += track->modulationDepth;
                        }
                        break;
                }
                track->noteVibratoOverride = TRUE;
            }
        }
    }

    return pitch;
}

static void ApplyNoise(struct GBSTrack *track)
{
    if (track->noiseActive)
    {
        if (track->noiseSampleCountdown > 0)
        {
            track->noiseSampleCountdown--;
        }
        else if (track->noiseSamplePointer != NULL && track->noiseSamplePointer[0] != NOISE_DATA_END)
        {
            track->noiseSampleCountdown = (*track->noiseSamplePointer++ & 0xF) + 1;
            track->envelope = *track->noiseSamplePointer++;
            track->pitch = *track->noiseSamplePointer++;
            track->noteNoiseSampling = TRUE;
        }
    }
}

static u8 ProcessCommands(struct MusicPlayerInfo *info, struct GBSTrack *track)
{
    u8 commandID = *track->nextInstruction++; // grab next byte and increment pointer
    bool32 trackActive = TRUE;

    while (commandID >= SetOctave7)
    {
        switch (commandID)
        {
            case SetOctave7 ... SetOctave0:
                track->currentOctave = commandID & 7;
                break;
            case SetNoteUnitLengthAndEnvelope:
                track->noteUnitLength = *track->nextInstruction++;
                if ((track->channelID - 1) == CGBCHANNEL_NOISE)
                {
                    break;
                }
                // fallthrough
            case SetEnvelope:
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
                info->gbsTempo = T1_READ_16(track->nextInstruction);
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
            case ToggleSFX:
                // Toggle note-format mode only; isSFXChannel is reserved for hardware arbitration.
                track->useSFXNoteFormat = !track->useSFXNoteFormat;
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
                track->pitchBendTarget = CalculatePitch(byte2 & 0xF, track->keyShift, (byte2 & 0xF0) >> 4);
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
            case ToggleAndSetNoise:
            case SFXToggleNoise:
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
            case SetVolume:
                track->channelVolume = *track->nextInstruction++;
                track->volumeChange = TRUE;
                break;
            case SetTone:
                track->tone = T1_READ_16(track->nextInstruction);
                track->nextInstruction += 2;
                track->pitchOffset = TRUE;
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
                    trackActive = FALSE;
                    track->noteRest = TRUE;
                }
                else
                {
                    track->nextInstruction = track->returnLocation;
                    track->returnLocation = NULL;
                }
                break;
            case SFXPriorityOn:
                // Claim hardware priority on this channel for SFX use.
                gGBSSFXActiveMask |= (1 << (track->channelID - 1));
                break;
            case SFXPriorityOff:
                // Release hardware priority on this channel.
                gGBSSFXActiveMask &= ~(1 << (track->channelID - 1));
                break;
            default:
                break;
        }
        commandID = *track->nextInstruction++; 
    }

    if (trackActive)
    {
        if (track->useSFXNoteFormat)
        {
            // Crystal SFX use raw 60Hz frame-tick durations, not tempo-scaled lengths.
            // commandID IS the tick count; no CalculateNoteLength needed.
            u8 velocityEnvelope = *track->nextInstruction++;

            track->noteNoiseSampling = TRUE;

            // +1 because noteLength1 < 2 triggers immediately (need N+1 to hold for N ticks).
            track->noteLength1 = commandID + 1;
            track->noteLength2 = 0;

            track->velocity = (velocityEnvelope & 0xF0) >> 4;
            track->envelope = velocityEnvelope & 0xF;

            if ((track->channelID - 1) == CGBCHANNEL_NOISE)
            {
                track->pitch = (track->pitch & 0xFF00) | *track->nextInstruction++;
            }
            else
            {
                track->pitch = T1_READ_16(track->nextInstruction);
                track->nextInstruction += 2;
            }
        }
        else
        {
            ProcessNoteCommand(commandID, info->gbsTempo, track);
        }
    }

    track->modulationDelayCountdown = track->modulationDelay;
    return trackActive;
}

static void ProcessNoteCommand(u8 commandID, u16 tempo, struct GBSTrack *track)
{
    u16 noteLength = CalculateNoteLength(track->noteUnitLength, tempo, (commandID & 0xF), track->noteLength2);

    track->noteLength1 = (noteLength & 0xFF00) >> 8;
    track->noteLength2 = noteLength & 0xFF;

    if (track->noiseActive && ((track->channelID - 1) == CGBCHANNEL_NOISE))
    {
        if (commandID & 0xF0)
        {
            u32 engineSet = track->dutyCycle;
            const u8 *const *noiseGroup = sNoiseDataGroupTable[engineSet];
            const u8 *noiseData = NULL;
            
            noiseData = noiseGroup[(commandID & 0xF0) >> 4];
            track->noiseSamplePointer = noiseData;
            track->noiseSampleCountdown = 0;
        }
    }
    else
    {
        if (commandID & 0xF0)
        {
            track->pitch = CalculatePitch((commandID & 0xF0) >> 4, track->keyShift, track->currentOctave);
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
                    // BUG: If lower bytes carry, then upper bytes are miscalculated
                    s32 carryCheck = (s32)(track->pitchBendTarget & 0xFF) - (s32)(track->pitch & 0xFF);
                    if (carryCheck < 0)
                    {
                        distance = 0x200;
                    }
                    
                    distance += track->pitchBendTarget - track->pitch;
                    track->pitchBendDir = TRUE;
                }
                else
                {
                    // BUG: If lower bytes carry, then upper bytes are miscalculated
                    s32 carryCheck = (s32)(track->pitch & 0xFF) - (s32)(track->pitchBendTarget & 0xFF);
                    if (carryCheck < 0)
                    {
                        distance = 0x200;
                    }
                    
                    distance += track->pitch - track->pitchBendTarget;
                    track->pitchBendDir = FALSE;
                }

                // BUG: Division off by one?
                track->pitchBendAmount = (distance / track->pitchBendDuration) + 1;
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

static void UpdateCGBChannel(struct GBSTrack *track, u16 pitch)
{
    if (!IsM4AUsingCGBChannel(track->channelID - 1))
    {
        switch (track->channelID - 1)
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

static void UpdateCGBTone1(struct GBSTrack *track, u16 pitch)
{
    vu8 *sweep = (vu8 *)REG_ADDR_NR10;
    vu8 *lengthDuty = (vu8 *)REG_ADDR_NR11;
    vu8 *envelopeVelocity = (vu8 *)REG_ADDR_NR12;
    vu16 *frequencyControl = (vu16 *)REG_ADDR_NR13;

    if (track->notePitchSweep)
    {
        *sweep = track->pitchSweep;
    }

    if (track->noteRest)
    {
        ClearCGBChannel(track);
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        UpdateDutyEnvelopeVelocity(track, lengthDuty, envelopeVelocity);
        *frequencyControl = pitch | 0x8000;
    }
    else
    {
        if (track->noteFreqOverride)
        {
            *frequencyControl = pitch;
            track->noteDutyOverride = TRUE;
        }
        else if (track->noteVibratoOverride)
        {
            // Original engine chooses to clamp calculation at nearest multiple of 0x100
            // Because of this, it only writes the lower byte if noteVibratoOverride is set
            // Either we replicate both behaviors exactly or just store both bytes
            //*frequencyControl = (*frequencyControl & 0xFF00) | (pitch & 0xFF);

            *frequencyControl = pitch;
            track->noteDutyOverride = TRUE;
        }

        if (track->noteDutyOverride)
        {
            *lengthDuty = (*lengthDuty & 0x3F) | (track->dutyCycle << 6);
        }
    }
}

static void UpdateCGBTone2(struct GBSTrack *track, u16 pitch)
{
    vu8 *lengthDuty = (vu8 *)REG_ADDR_NR21;
    vu8 *envelopeVelocity = (vu8 *)REG_ADDR_NR22;
    vu16 *frequencyControl = (vu16 *)REG_ADDR_NR23;

    if (track->noteRest)
    {
        ClearCGBChannel(track);
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        UpdateDutyEnvelopeVelocity(track, lengthDuty, envelopeVelocity);
        *frequencyControl = pitch | 0x8000;
    }
    else
    {
        if (track->noteVibratoOverride)
        {
            // Original engine chooses to clamp calculation at nearest multiple of 0x100
            // Because of this, it only writes the lower byte if noteVibratoOverride is set
            // Either we replicate both behaviors exactly or just store both bytes
            //control[2] = (control[2] & 0xFF00) | (pitch & 0xFF);

            *frequencyControl = pitch;
            track->noteDutyOverride = TRUE;
        }

        if (track->noteDutyOverride)
        {
            *lengthDuty = (*lengthDuty & 0x3F) | (track->dutyCycle << 6);
        }
    }
}

static void UpdateCGBWave(struct GBSTrack *track, u16 pitch)
{
    vu16 *frequencyControl = (vu16 *)REG_ADDR_NR33;

    if (track->noteRest)
    {
        ClearCGBChannel(track);
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        LoadWavePattern(track, track->envelope);
        *frequencyControl = pitch | 0x8000;
    }
    else if (track->noteVibratoOverride)
    {
        // Original engine chooses to clamp calculation at nearest multiple of 0x100
        // Because of this, it only writes the lower byte if noteVibratoOverride is set
        // Either we replicate both behaviors exactly or just store both bytes
        //control[2] = (control[2] & 0xFF00) | (pitch & 0xFF);
        *frequencyControl = pitch;
    }
}

static void UpdateCGBNoise(struct GBSTrack *track)
{
    vu8 *length = (vu8 *)REG_ADDR_NR41;
    vu8 *envelopeVelocity = (vu8 *)REG_ADDR_NR42;
    vu8 *frequency = (vu8 *)REG_ADDR_NR43;
    vu8 *control = (vu8 *)REG_ADDR_NR44;

    if (track->noteRest)
    {
        ClearCGBChannel(track);
    }
    else if (track->noteNoiseSampling)
    {
        UpdateStereoPan(track);
        *length = 0x3F;
        *envelopeVelocity = track->envelope | track->velocity << 4;
        *frequency = track->pitch & 0xFF;
        *control = 0x80;
    }
}

static void UpdateStereoPan(struct GBSTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu8 *soundControl = (vu8 *)REG_ADDR_NR50;
    u8 thisPan = soundInfo->cgbChans[track->channelID - 1].panMask;

    if (gSaveBlock2Ptr->optionsSound == OPTIONS_SOUND_STEREO)
    {
        thisPan &= track->pan;
    }
    soundControl[1] = (soundControl[1] & ~soundInfo->cgbChans[track->channelID - 1].panMask) | thisPan;
}

static void LoadWavePattern(struct GBSTrack *track, int patternID)
{
    if (!IsM4AUsingCGBChannel(CGBCHANNEL_WAVE))
    {
        struct SoundInfo *soundInfo = SOUND_INFO_PTR;
        vu8 *control = (vu8 *)REG_ADDR_NR30;
        vu8 *length = (vu8 *)REG_ADDR_NR31;
        vu8 *velocity = (vu8 *)REG_ADDR_NR32;

        *length = 0x3F;
        *control = 0x40; // Stop channel and choose other wave bank so we can write into the first one

        if (patternID < ARRAY_COUNT(sWaveTrackPatterns) && soundInfo->cgbChans[CGBCHANNEL_WAVE].currentPointer != (u32*)sWaveTrackPatterns[patternID])
        {
            u32* mainPattern = (u32 *)(REG_ADDR_WAVE_RAM0);
            memcpy(mainPattern, sWaveTrackPatterns[patternID], sizeof(sWaveTrackPatterns[patternID]));
            soundInfo->cgbChans[CGBCHANNEL_WAVE].currentPointer = (u32*)sWaveTrackPatterns[patternID];
        }

        *velocity = track->velocity << 5;
        *control = 0x80; // Start channel and switch back to first wave bank
    }

    track->envelope = patternID;
    track->shouldReload = FALSE;
}

static void UpdateDutyEnvelopeVelocity(struct GBSTrack *track, vu8 *lengthDuty, vu8 *envelopeVelocity)
{
    *lengthDuty = 0x3F | (track->dutyCycle << 6);
    *envelopeVelocity = track->envelope | track->velocity << 4;
}

//
// Functions called from m4a engine
//

bool32 GBSMain(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    struct GBSTrack *gbsTrack = (struct GBSTrack *)track;
    vu8 *soundControl = (vu8 *)REG_ADDR_NR50;
    bool32 success = FALSE;
    u32 masterVolume = 0;
    
    // Set bias level to 0 for less crunch
    // Always set here since m4a engine may have changed it
    // Now I can't tell the difference, was there ever one...? (CrystalDust) - I don't believe this would benefit GBS (HnS - Skeletonkey36)
    //REG_SOUNDBIAS = REG_SOUNDBIAS & 0xFC00;

    // Reset all note flags
    gbsTrack->noteDutyOverride = FALSE;
	gbsTrack->noteFreqOverride = FALSE;
	gbsTrack->notePitchSweep = FALSE;
	gbsTrack->noteNoiseSampling = FALSE;
	gbsTrack->noteRest = FALSE;
	gbsTrack->noteVibratoOverride = FALSE;

    // Run unified GBS track update function
    success = GBSTrack_Update(info, gbsTrack);

    // If this SFX track just ended, release its hardware channel claim before
    // ply_fine zeroes the struct (and destroys channelID / isSFXChannel).
    if (!success && gbsTrack->isSFXChannel)
    {
        gGBSSFXActiveMask &= ~(1 << (gbsTrack->channelID - 1));
    }

    masterVolume = GetMasterVolumeFromFade(track->volX);
    // Ensure we're not stepping on m4a's toes by checking for default volume and channel usage
    if ((masterVolume == 0x77) && (gUsedCGBChannels == 0) && gbsTrack->volumeChange)
    {
        masterVolume = gbsTrack->channelVolume;
        gbsTrack->volumeChange = FALSE;
    }
    // Shift GBS master output down by 1 volume step (each nibble = one SO channel, 0-7)
    {
        u32 left  = (masterVolume >> 4) & 0x7;
        u32 right = masterVolume & 0x7;
        if (left  > 1) left  -= 2; else left  = 0;
        if (right > 1) right -= 2; else right = 0;
        masterVolume = (left << 4) | right;
    }
    soundControl[0] = masterVolume;

    return success;
}

void ply_gbs_switch(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u8 *cmdPtrBackup = track->cmdPtr;
    u8 gbChannel = *cmdPtrBackup++;

    if (gbChannel < 8)
    {
        struct GBSTrack *gbsTrack = (struct GBSTrack *)track;
        // Clear out all m4a data.
        memset(gbsTrack, 0, sizeof(*gbsTrack));

        // Set up track with new GBS data (and restore some important info).
        gbsTrack->channelID = (gbChannel % 4) + 1;
        if (gbChannel >= 4)
        {
            gbsTrack->isSFXChannel = TRUE;
            gbsTrack->useSFXNoteFormat = TRUE; // Crystal SFX data starts in raw format; toggle_sfx flips it to regular format.
            gGBSSFXActiveMask |= (1 << (gbChannel % 4));
        }
        gbsTrack->nextInstruction = cmdPtrBackup;
        gbsTrack->flags = MPT_FLG_EXIST;

        // Set engine defaults.
        gbsTrack->pan = 0xFF;
        gbsTrack->noteUnitLength = 1;

        // Disable m4a control of CGB channel.
        soundInfo->cgbChans[gbChannel % 4].statusFlags = 0;

        // Clear used bit.
        gUsedCGBChannels &= ~(1 << (gbChannel % 4));
        ClearCGBChannel(gbsTrack);
        // Figure out if this is needed when resetting (CrystalDust) - It's not, kept comment for reference (HnS - Skeletonkey36)
        //LoadWavePattern(gbsTrack, 0);
    }
}

void GBSTrack_Stop(struct MusicPlayerTrack *track)
{
    if (track->gbsIdentifier != 0)
    {
        struct GBSTrack *gbsTrack = (struct GBSTrack *)track;
        if (gbsTrack->isSFXChannel)
        {
            gGBSSFXActiveMask &= ~(1 << (gbsTrack->channelID - 1));
        }
        ClearCGBChannel(gbsTrack);
    }
}

//
// Helpers
//

static inline bool32 IsM4AUsingCGBChannel(int channel)
{
    // Check the actual M4A CGB channel status flags. gUsedCGBChannels is never
    // set by the M4A CGB handler; it manages ownership through cgbChans[].statusFlags.
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    return !!(soundInfo->cgbChans[channel].statusFlags & SOUND_CHANNEL_SF_ON);
}

static u32 GetMasterVolumeFromFade(u32 volX)
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

static u16 CalculateNoteLength(u8 noteUnitLength, u16 tempo, u8 length, u16 previousLeftover)
{
    return ((noteUnitLength * (length + 1)) * tempo) + previousLeftover;
}

static u16 CalculatePitch(u8 note, s8 keyShift, u8 octave)
{
    u8 octaveShifted = octave + ((keyShift & 0xF0) >> 4);
    u8 noteShifted = note + (keyShift & 0xF);
    return (sFrequencyTable[noteShifted] >> (7 - octaveShifted)) & 0x7FF;
}

static void ClearCGBChannel(struct GBSTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu16 *control = ((vu16 *)REG_ADDR_NR10) + ((track->channelID - 1) * 4);
    vu8 *soundControl = (vu8 *)REG_ADDR_NR50;

    soundControl[1] &= ~soundInfo->cgbChans[track->channelID - 1].panMask;

    control[0] = 0;
    control[1] = 0x800;
    control[2] = 0x8000;
}
