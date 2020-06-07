#include "global.h"
#include "event_scripts.h"
#include "fldeff.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

static void FieldCallback_Headbutt(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_FldEffHeadbutt);
}

bool8 SetUpFieldMove_Headbutt(void)
{
    s16 x, y;
    u8 metatileBehavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (MetatileBehavior_IsHeadbuttTree(metatileBehavior))
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Headbutt;
        return TRUE;
    }
    return FALSE;
}

static void StartHeadbuttFieldEffect(void)
{
    PlaySE(SE_USSOKI);
    FieldEffectActiveListRemove(FLDEFF_USE_HEADBUTT);
    EnableBothScriptContexts();
}

bool8 FldEff_UseHeadbutt(void)
{
    u8 taskId = oei_task_add();
    gTasks[taskId].data[8] = (u32)StartHeadbuttFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartHeadbuttFieldEffect;
    return FALSE;
}
