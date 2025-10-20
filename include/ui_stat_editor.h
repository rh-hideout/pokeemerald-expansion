
#ifndef GUARD_UI_STAT_EDIT_H
#define GUARD_UI_STAT_EDIT_H

#include "main.h"

void Task_OpenStatEditorFromStartMenu(u8 taskId);
void StatEditor_Init(MainCallback callback);

extern const struct SpeciesInfo gSpeciesInfo[];


#endif // GUARD_UI_MENU_H