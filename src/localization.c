#include "global.h"
#include "dynamic_placeholder_text_util.h"
#include "localization.h"

u8 *StringFormat(u8 *dst, const u8 *format, const u8 *arg0, const u8 *arg1, const u8 *arg2, const u8 *arg3)
{
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, arg0);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, arg1);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, arg2);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, arg3);
    return DynamicPlaceholderTextUtil_ExpandPlaceholders(dst, format);
}
