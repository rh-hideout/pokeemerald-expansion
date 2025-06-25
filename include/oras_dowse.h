#ifndef GUARD_ORAS_DOWSE_H
#define GUARD_ORAS_DOWSE_H

// States for ORAS Dowsing
enum
{
    ORASD_WIGGLE_NONE,
    ORASD_WIGGLE_SLOW,
    ORASD_WIGGLE_NORMAL,
    ORASD_WIGGLE_FAST,
    ORASD_WIGGLE_FASTER
};

extern const u16 gFieldEffectPal_ORASDowsing[];

void Task_UseORASDowsingMachine(u8 taskId);
void ResumeORASDowseFieldEffect(void);
void UpdateDowseState(struct Sprite *sprite);
void UpdateDowsingAnimDirection(struct Sprite *sprite, struct ObjectEvent *playerObj);
void EndORASDowsing(void);

#endif // GUARD_ORAS_DOWSE_H
