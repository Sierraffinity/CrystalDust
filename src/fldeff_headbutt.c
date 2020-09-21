#include "global.h"
#include "event_scripts.h"
#include "fldeff.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "metatile_behavior.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

// TODO: This is the exact formula from GSC. Should this be tweaked?
u32 HeadbuttTreeScoreCalc(void)
{
    u32 treeIndex, pivot;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    treeIndex = (((gPlayerFacingPosition.x * gPlayerFacingPosition.y) + (gPlayerFacingPosition.x + gPlayerFacingPosition.y)) / 5) % 10;
    pivot = GetPlayerTrainerIdOnesDigit();
    treeIndex = (10 + treeIndex - pivot) % 10;

    if (treeIndex == 0)
    {
        return TREEMON_SCORE_RARE;
    }
    else if (treeIndex < 5)
    {
        return TREEMON_SCORE_GOOD;
    }
    else
    {
        return TREEMON_SCORE_BAD;
    }
}

static void FieldCallback_Headbutt(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_UseHeadbutt);
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
    PlaySE(SE_SUDOWOODO_SHAKE);
    FieldEffectActiveListRemove(FLDEFF_USE_HEADBUTT);
    EnableBothScriptContexts();
}

bool8 FldEff_UseHeadbutt(void)
{
    u8 taskId = CreateFieldMoveTask();
    gTasks[taskId].data[8] = (u32)StartHeadbuttFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartHeadbuttFieldEffect;
    return FALSE;
}
