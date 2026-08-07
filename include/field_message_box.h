#ifndef GUARD_FIELD_MESSAGE_BOX_H
#define GUARD_FIELD_MESSAGE_BOX_H

#include "constants/dialogue_styles.h"

enum
{
    FIELD_MESSAGE_BOX_HIDDEN,
    FIELD_MESSAGE_BOX_UNUSED,
    FIELD_MESSAGE_BOX_NORMAL,
    FIELD_MESSAGE_BOX_AUTO_SCROLL,
};

bool8 ShowFieldMessage(const u8 *str);
bool8 ShowPokenavFieldMessage(const u8 *str);
bool8 ShowFieldMessageFromBuffer(void);
bool8 ShowFieldAutoScrollMessage(const u8 *str);
void HideFieldMessageBox(void);
bool8 IsFieldMessageBoxHidden(void);
u8 GetFieldMessageBoxMode(void);
void StopFieldMessage(void);
void InitFieldMessageBox(void);
void SetFieldMessageDialogueStyle(u8 style);
void ClearFieldMessageDialogueStyle(void);
u8 GetFieldMessageDialogueStyle(void);
u32 GetFieldMessageTextSpeedDelay(void);
u32 GetFieldMessageTextSpeedModifier(void);
u32 GetFieldMessageTextScrollSpeed(void);
u32 GetFieldMessageTextScrollDelay(void);
bool32 IsFieldMessageTextSpeedInstant(void);
void ApplyFieldMessageTextPrinterProfile(void);

extern u8 gWalkAwayFromSignpostTimer;

#endif // GUARD_FIELD_MESSAGE_BOX_H
