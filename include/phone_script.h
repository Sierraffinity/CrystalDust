#ifndef GUARD_PHONE_SCRIPT_H
#define GUARD_PHONE_SCRIPT_H

#include "phone_contact.h"

enum
{
    PHONE_SCRIPT_NONE,
    PHONE_SCRIPT_POKEGEAR,
    PHONE_SCRIPT_OVERWORLD,
};

enum
{
    PHONE_CALL_SUCCESS,
    PHONE_CALL_FAIL,
    PHONE_CALL_FAIL_SILENT,
};

extern u16 gPhoneCallWindowId;
extern u16 gPhoneCallerNameWindowId;
extern u8 gPhoneCallSpriteId;

void PhoneScriptContext_SetupPhoneScript(const struct PhoneContact *contact, u32 callContext);
void PhoneScriptContext_SetupCustomPhoneScript(const u8 *script, u32 callContext);
bool8 PhoneScriptContext_RunScript(void);
void PhoneScriptContext_Enable(void);
void PhoneScriptContext_Disable(void);
bool8 PhoneScriptContext_IsEnabled(void);

#endif //GUARD_PHONE_SCRIPT_H
