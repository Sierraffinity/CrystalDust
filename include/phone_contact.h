#ifndef GUARD_PHONE_CONTACT_H
#define GUARD_PHONE_CONTACT_H

#include "constants/phone_contact.h"

struct PhoneContact;
typedef const u8 *(*PhoneContactSelectMessage)(const struct PhoneContact *phoneContact, bool8 isCallingPlayer);
u32 GetPhoneContactFromTrainerId(int trainerId);

#define DAY_ALWAYS 7
#define TIME_ALWAYS 7
#define DAY_NEVER 8
#define TIME_NEVER 8

struct PhoneContact
{
    const u8 *customDisplayName;
    const u8 *phoneScript;
    u8 mapNum;
    u8 mapGroup;
    u16 registeredFlag;
    u8 rematchTrainerId;
    u8 trainerId;
    u8 availability;
    u8 isPermanent;
};

extern const struct PhoneContact gPhoneContacts[PHONE_CONTACT_COUNT];

bool8 DummiedOut_IsPhoneContactAvailable(const struct PhoneContact *phoneContact, s8 dayOfWeek, s8 hour);
const u8 *BuildPhoneContactDisplayName(const struct PhoneContact *phoneContact, u8 *dest);
const u8 *BuildPhoneContactDisplayNameForCall(const struct PhoneContact *phoneContact, u8 *dest);
const bool8 FindPhoneContactNameFromFlag(void);
bool8 CanPhoneContactAcceptRematch(const struct PhoneContact *phoneContact, s8 dayOfWeek, s8 hour);

#endif //GUARD_PHONE_CONTACT_H
