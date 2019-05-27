#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tv.h"
#include "bg.h"
#include "data.h"
#include "item.h"
#include "item_menu.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

// this file's functions
static void WallyHandleGetMonData(void);
static void WallyHandleGetRawMonData(void);
static void WallyHandleSetMonData(void);
static void WallyHandleSetRawMonData(void);
static void WallyHandleLoadMonSprite(void);
static void WallyHandleSwitchInAnim(void);
static void WallyHandleReturnMonToBall(void);
static void WallyHandleDrawTrainerPic(void);
static void WallyHandleTrainerSlide(void);
static void WallyHandleTrainerSlideBack(void);
static void WallyHandleFaintAnimation(void);
static void WallyHandlePaletteFade(void);
static void WallyHandleSuccessBallThrowAnim(void);
static void WallyHandleBallThrowAnim(void);
static void WallyHandlePause(void);
static void WallyHandleMoveAnimation(void);
static void WallyHandlePrintString(void);
static void WallyHandlePrintSelectionString(void);
static void WallyHandleChooseAction(void);
static void WallyHandleUnknownYesNoBox(void);
static void WallyHandleChooseMove(void);
static void WallyHandleChooseItem(void);
static void WallyHandleChoosePokemon(void);
static void WallyHandleCmd23(void);
static void WallyHandleHealthBarUpdate(void);
static void WallyHandleExpUpdate(void);
static void WallyHandleStatusIconUpdate(void);
static void WallyHandleStatusAnimation(void);
static void WallyHandleStatusXor(void);
static void WallyHandleDataTransfer(void);
static void WallyHandleDMA3Transfer(void);
static void WallyHandlePlayBGM(void);
static void WallyHandleCmd32(void);
static void WallyHandleTwoReturnValues(void);
static void WallyHandleChosenMonReturnValue(void);
static void WallyHandleOneReturnValue(void);
static void WallyHandleOneReturnValue_Duplicate(void);
static void WallyHandleCmd37(void);
static void WallyHandleCmd38(void);
static void WallyHandleCmd39(void);
static void WallyHandleCmd40(void);
static void WallyHandleHitAnimation(void);
static void WallyHandleCmd42(void);
static void WallyHandlePlaySE(void);
static void WallyHandlePlayFanfareOrBGM(void);
static void WallyHandleFaintingCry(void);
static void WallyHandleIntroSlide(void);
static void WallyHandleIntroTrainerBallThrow(void);
static void WallyHandleDrawPartyStatusSummary(void);
static void WallyHandleHidePartyStatusSummary(void);
static void WallyHandleEndBounceEffect(void);
static void WallyHandleSpriteInvisibility(void);
static void WallyHandleBattleAnimation(void);
static void WallyHandleLinkStandbyMsg(void);
static void WallyHandleResetActionMoveSelection(void);
static void WallyHandleCmd55(void);
static void WallyCmdEnd(void);

static void WallyBufferRunCommand(void);
static void WallyBufferExecCompleted(void);
static void CompleteOnChosenItem(void);
static void sub_8168818(void);
static u32 CopyWallyMonData(u8 monId, u8 *dst);
static void SetWallyMonData(u8 monId);
static void WallyDoMoveAnimation(void);
static void sub_816AC04(u8 taskId);

static void (*const sWallyBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    WallyHandleGetMonData,
    WallyHandleGetRawMonData,
    WallyHandleSetMonData,
    WallyHandleSetRawMonData,
    WallyHandleLoadMonSprite,
    WallyHandleSwitchInAnim,
    WallyHandleReturnMonToBall,
    WallyHandleDrawTrainerPic,
    WallyHandleTrainerSlide,
    WallyHandleTrainerSlideBack,
    WallyHandleFaintAnimation,
    WallyHandlePaletteFade,
    WallyHandleSuccessBallThrowAnim,
    WallyHandleBallThrowAnim,
    WallyHandlePause,
    WallyHandleMoveAnimation,
    WallyHandlePrintString,
    WallyHandlePrintSelectionString,
    WallyHandleChooseAction,
    WallyHandleUnknownYesNoBox,
    WallyHandleChooseMove,
    WallyHandleChooseItem,
    WallyHandleChoosePokemon,
    WallyHandleCmd23,
    WallyHandleHealthBarUpdate,
    WallyHandleExpUpdate,
    WallyHandleStatusIconUpdate,
    WallyHandleStatusAnimation,
    WallyHandleStatusXor,
    WallyHandleDataTransfer,
    WallyHandleDMA3Transfer,
    WallyHandlePlayBGM,
    WallyHandleCmd32,
    WallyHandleTwoReturnValues,
    WallyHandleChosenMonReturnValue,
    WallyHandleOneReturnValue,
    WallyHandleOneReturnValue_Duplicate,
    WallyHandleCmd37,
    WallyHandleCmd38,
    WallyHandleCmd39,
    WallyHandleCmd40,
    WallyHandleHitAnimation,
    WallyHandleCmd42,
    WallyHandlePlaySE,
    WallyHandlePlayFanfareOrBGM,
    WallyHandleFaintingCry,
    WallyHandleIntroSlide,
    WallyHandleChooseAction,
    WallyHandleDrawPartyStatusSummary,
    WallyHandleHidePartyStatusSummary,
    WallyHandleEndBounceEffect,
    WallyHandleSpriteInvisibility,
    WallyHandleBattleAnimation,
    WallyHandleLinkStandbyMsg,
    WallyHandleResetActionMoveSelection,
    WallyHandleCmd55,
    WallyCmdEnd
};

static void SpriteCB_Null7(void)
{
}

void SetControllerToWally(void)
{
    gBattlerControllerFuncs[gActiveBattler] = WallyBufferRunCommand;
    gBattleStruct->wallyBattleState = 0;
    gBattleStruct->wallyMovesState = 0;
    gBattleStruct->wallyWaitFrames = 0;
    gBattleStruct->wallyMoveFrames = 0;
}

static void WallyBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleBufferA[gActiveBattler][0] < ARRAY_COUNT(sWallyBufferCommands))
            sWallyBufferCommands[gBattleBufferA[gActiveBattler][0]]();
        else
            WallyBufferExecCompleted();
    }
}

static void WallyHandleActions(void)
{
    switch (gBattleStruct->wallyBattleState)
    {
    case 0:
        gBattleStruct->wallyWaitFrames = 64;
        gBattleStruct->wallyBattleState++;
    case 1:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(1, B_ACTION_USE_MOVE, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = 64;
        }
        break;
    case 2:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(1, B_ACTION_USE_MOVE, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = 64;
        }
        break;
    case 3:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            BtlController_EmitTwoReturnValues(1, B_ACTION_WALLY_THROW, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = 64;
        }
        break;
    case 4:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(0);
            ActionSelectionCreateCursorAt(1, 0);
            gBattleStruct->wallyWaitFrames = 64;
            gBattleStruct->wallyBattleState++;
        }
        break;
    case 5:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(1, B_ACTION_USE_ITEM, 0);
            WallyBufferExecCompleted();
        }
        break;
    }
}

static void CompleteOnBattlerSpriteCallbackDummy(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        WallyBufferExecCompleted();
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        WallyBufferExecCompleted();
}

static void CompleteOnFinishedAnimation(void)
{
    if (!gDoingBattleAnim)
        WallyBufferExecCompleted();
}

static void OpenBagAfterPaletteFade(void)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnChosenItem;
        nullsub_35();
        FreeAllWindowBuffers();
        DoWallyTutorialBagMenu();
    }
}

static void CompleteOnChosenItem(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(1, gSpecialVar_ItemId);
        WallyBufferExecCompleted();
    }
}

static void sub_816864C(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive)
        sub_8172EF0(gActiveBattler, &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]]);
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK].ballAnimActive)
        sub_8172EF0(gActiveBattler ^ BIT_FLANK, &gPlayerParty[gBattlerPartyIndexes[gActiveBattler ^ BIT_FLANK]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK].ballAnimActive
        && gSprites[gUnknown_03005D7C[gActiveBattler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBattler ^ BIT_FLANK]]);
            UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler ^ BIT_FLANK], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler ^ BIT_FLANK]], HEALTHBOX_ALL);
            sub_8076918(gActiveBattler ^ BIT_FLANK);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler ^ BIT_FLANK]);
        }
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBattler]]);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_ALL);
        sub_8076918(gActiveBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);

        gBattleSpritesDataPtr->animationData->field_9_x1 = 0;
        gBattlerControllerFuncs[gActiveBattler] = sub_8168818;
    }

}

static void sub_8168818(void)
{
    bool32 r4 = FALSE;

    if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        r4 = TRUE;

    if (r4 && gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].field_1_x1
        && gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK].field_1_x1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].field_1_x1 = 0;

        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK].field_1_x1 = 0;

        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);

        CreateTask(c3_0802FDF4, 10);
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);

        WallyBufferExecCompleted();
    }
}

static void CompleteOnHealthbarDone(void)
{
    s16 hpValue = MoveBattleBar(gActiveBattler, gHealthboxSpriteIds[gActiveBattler], HEALTH_BAR, 0);

    SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);

    if (hpValue != -1)
    {
        UpdateHpTextInHealthbox(gHealthboxSpriteIds[gActiveBattler], hpValue, HP_CURRENT);
    }
    else
    {
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
        WallyBufferExecCompleted();
    }
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBattlerSpriteIds[gActiveBattler];

    if (gSprites[spriteId].data[1] == 32)
    {
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = FALSE;
        gDoingBattleAnim = FALSE;
        WallyBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data[1] % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data[1]++;
    }
}

static void sub_8168A20(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        DestroySprite(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[gActiveBattler]);
        WallyBufferExecCompleted();
    }
}

static void CompleteOnBankSpriteCallbackDummy2(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        WallyBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animFromTableActive)
        WallyBufferExecCompleted();
}

static void WallyBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = WallyBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBattler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~gBitTable[gActiveBattler];
    }
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].statusAnimActive)
        WallyBufferExecCompleted();
}

static void WallyHandleGetMonData(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleGetRawMonData(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSetMonData(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSetRawMonData(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleLoadMonSprite(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSwitchInAnim(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleReturnMonToBall(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleDrawTrainerPic(void)
{
    DecompressTrainerBackPic(TRAINER_BACK_PIC_WALLY, gActiveBattler);
    SetMultiuseSpriteTemplateToTrainerBack(TRAINER_BACK_PIC_WALLY, GetBattlerPosition(gActiveBattler));
    gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate,
                                               80,
                                               80 + 4 * (8 - gTrainerBackPicCoords[TRAINER_BACK_PIC_WALLY].size),
                                               30);
    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
    gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = 240;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = -2;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = sub_805D7AC;
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnBattlerSpriteCallbackDummy;
}

static void WallyHandleTrainerSlide(void)
{
    DecompressTrainerBackPic(TRAINER_BACK_PIC_WALLY, gActiveBattler);
    SetMultiuseSpriteTemplateToTrainerBack(TRAINER_BACK_PIC_WALLY, GetBattlerPosition(gActiveBattler));
    gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate,
                                               80,
                                               80 + 4 * (8 - gTrainerBackPicCoords[TRAINER_BACK_PIC_WALLY].size),
                                               30);
    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
    gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = -96;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 2;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = sub_805D7AC;
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnBankSpriteCallbackDummy2;
}

static void WallyHandleTrainerSlideBack(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleFaintAnimation(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandlePaletteFade(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSuccessBallThrowAnim(void)
{
    gBattleSpritesDataPtr->animationData->ballThrowCaseId = BALL_3_SHAKES_SUCCESS;
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_SAFARI_BALL_THROW);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedAnimation;
}

static void WallyHandleBallThrowAnim(void)
{
    u8 ballThrowCaseId = gBattleBufferA[gActiveBattler][1];

    gBattleSpritesDataPtr->animationData->ballThrowCaseId = ballThrowCaseId;
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_SAFARI_BALL_THROW);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedAnimation;
}

static void WallyHandlePause(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleMoveAnimation(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16*)(&gBattleBufferA[gActiveBattler][2]);
    BufferStringBattle(*stringId);
    BattlePutTextOnWindow(gDisplayedStringBattle, 0);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnInactiveTextPrinter;
}

static void WallyHandlePrintSelectionString(void)
{
    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        WallyHandlePrintString();
    else
        WallyBufferExecCompleted();
}

static void HandleChooseActionAfterDma3(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 160;
        gBattlerControllerFuncs[gActiveBattler] = WallyHandleActions;
    }
}

static void WallyHandleChooseAction(void)
{
    s32 i;

    gBattlerControllerFuncs[gActiveBattler] = HandleChooseActionAfterDma3;
    BattlePutTextOnWindow(gText_BattleMenu, 2);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBattler], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillWallyDo);
    BattlePutTextOnWindow(gDisplayedStringBattle, 1);
}

static void WallyHandleUnknownYesNoBox(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleChooseMove(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleChooseItem(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[gActiveBattler] = OpenBagAfterPaletteFade;
    gBattlerInMenuId = gActiveBattler;
}

static void WallyHandleChoosePokemon(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd23(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleHealthBarUpdate(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleExpUpdate(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleStatusIconUpdate(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleStatusAnimation(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleStatusXor(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleDataTransfer(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleDMA3Transfer(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandlePlayBGM(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd32(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleTwoReturnValues(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleChosenMonReturnValue(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleOneReturnValue(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleOneReturnValue_Duplicate(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd37(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd38(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd39(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd40(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleHitAnimation(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd42(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandlePlaySE(void)
{
    PlaySE(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    WallyBufferExecCompleted();
}

static void WallyHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBattler][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    }

    WallyBufferExecCompleted();
}

static void WallyHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

    PlayCry1(species, 25);
    WallyBufferExecCompleted();
}

static void WallyHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBattler][1]);
    gIntroSlideFlags |= 1;
    WallyBufferExecCompleted();
}

static void WallyHandleIntroTrainerBallThrow(void)
{
    u8 paletteNum;
    u8 taskId;

    SetSpritePrimaryCoordsFromSecondaryCoords(&gSprites[gBattlerSpriteIds[gActiveBattler]]);

    gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 50;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[2] = -40;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[4] = gSprites[gBattlerSpriteIds[gActiveBattler]].pos1.y;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = StartAnimLinearTranslation;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[5] = gActiveBattler;

    StoreSpriteCallbackInData6(&gSprites[gBattlerSpriteIds[gActiveBattler]], sub_805CC00);
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[gActiveBattler]], 1);

    paletteNum = AllocSpritePalette(0xD6F8);
    LoadCompressedPalette(gTrainerBackPicPaletteTable[TRAINER_BACK_PIC_WALLY].data, 0x100 + paletteNum * 16, 32);
    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = paletteNum;

    taskId = CreateTask(sub_816AC04, 5);
    gTasks[taskId].data[0] = gActiveBattler;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusSummaryShown)
        gTasks[gBattlerStatusSummaryTaskId[gActiveBattler]].func = Task_HidePartyStatusSummary;

    gBattleSpritesDataPtr->animationData->field_9_x1 = 1;
    gBattlerControllerFuncs[gActiveBattler] = nullsub_21;
}

static void sub_816AA80(u8 battlerId)
{
    u16 species;

    gBattleSpritesDataPtr->battlerData[battlerId].transformSpecies = 0;
    gBattlerPartyIndexes[battlerId] = gBattleBufferA[battlerId][1];
    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
    gUnknown_03005D7C[battlerId] = CreateInvisibleSpriteWithCallback(sub_805D714);
    SetMultiuseSpriteTemplateToPokemon(species, GetBattlerPosition(battlerId));
    gBattlerSpriteIds[battlerId] = CreateSprite(&gMultiuseSpriteTemplate,
                                        GetBattlerSpriteCoord(battlerId, 2),
                                        GetBattlerSpriteDefault_Y(battlerId),
                                        GetBattlerSpriteSubpriority(battlerId));

    gSprites[gUnknown_03005D7C[battlerId]].data[1] = gBattlerSpriteIds[battlerId];
    gSprites[gUnknown_03005D7C[battlerId]].data[2] = battlerId;

    gSprites[gBattlerSpriteIds[battlerId]].data[0] = battlerId;
    gSprites[gBattlerSpriteIds[battlerId]].data[2] = species;
    gSprites[gBattlerSpriteIds[battlerId]].oam.paletteNum = battlerId;

    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerId]], gBattleMonForms[battlerId]);
    gSprites[gBattlerSpriteIds[battlerId]].invisible = TRUE;
    gSprites[gBattlerSpriteIds[battlerId]].callback = SpriteCallbackDummy;
    gSprites[gUnknown_03005D7C[battlerId]].data[0] = DoPokeballSendOutAnimation(0, POKEBALL_PLAYER_SENDOUT);
}

static void sub_816AC04(u8 taskId)
{
    if (gTasks[taskId].data[1] < 31)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        u8 savedActiveBank = gActiveBattler;

        gActiveBattler = gTasks[taskId].data[0];
        gBattleBufferA[gActiveBattler][1] = gBattlerPartyIndexes[gActiveBattler];
        sub_816AA80(gActiveBattler);
        gBattlerControllerFuncs[gActiveBattler] = sub_816864C;
        gActiveBattler = savedActiveBank;
        DestroyTask(taskId);
    }
}

static void WallyHandleDrawPartyStatusSummary(void)
{
    if (gBattleBufferA[gActiveBattler][1] != 0 && GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
    {
        WallyBufferExecCompleted();
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusSummaryShown = 1;
        gBattlerStatusSummaryTaskId[gActiveBattler] = CreatePartyStatusSummarySprites(gActiveBattler, (struct HpAndStatus *)&gBattleBufferA[gActiveBattler][4], gBattleBufferA[gActiveBattler][1], gBattleBufferA[gActiveBattler][2]);
        WallyBufferExecCompleted();
    }
}

static void WallyHandleHidePartyStatusSummary(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleEndBounceEffect(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSpriteInvisibility(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleBattleAnimation(void)
{
    u8 animationId = gBattleBufferA[gActiveBattler][1];
    u16 argument = gBattleBufferA[gActiveBattler][2] | (gBattleBufferA[gActiveBattler][3] << 8);

    if (TryHandleLaunchBattleTableAnimation(gActiveBattler, gActiveBattler, gActiveBattler, animationId, argument))
        WallyBufferExecCompleted();
    else
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedBattleAnimation;
}

static void WallyHandleLinkStandbyMsg(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleResetActionMoveSelection(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd55(void)
{
    gBattleOutcome = gBattleBufferA[gActiveBattler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    WallyBufferExecCompleted();

    if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER) && gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattlerControllerFuncs[gActiveBattler] = sub_80587B0;
}

static void WallyCmdEnd(void)
{
}
