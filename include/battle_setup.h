#ifndef GUARD_BATTLE_SETUP_H
#define GUARD_BATTLE_SETUP_H

#define REMATCHES_COUNT 5

enum {
	REMATCH_TRAINER_ROSE,
	REMATCH_TRAINER_ANDRES,
	REMATCH_TRAINER_DUSTY,
	REMATCH_TRAINER_LOLA,
	REMATCH_TRAINER_RICKY,
	REMATCH_TRAINER_LILA_AND_ROY,
	REMATCH_TRAINER_CRISTIN,
	REMATCH_TRAINER_BROOKE,
	REMATCH_TRAINER_WILTON,
	REMATCH_TRAINER_VALERIE,
	REMATCH_TRAINER_CINDY,
	REMATCH_TRAINER_THALIA,
	REMATCH_TRAINER_JESSICA,
	REMATCH_TRAINER_WINSTON,
	REMATCH_TRAINER_STEVE,
	REMATCH_TRAINER_TONY,
	REMATCH_TRAINER_NOB,
	REMATCH_TRAINER_KOJI,
	REMATCH_TRAINER_FERNANDO,
	REMATCH_TRAINER_DALTON,
	REMATCH_TRAINER_BERNIE,
	REMATCH_TRAINER_ETHAN,
	REMATCH_TRAINER_JOHN_AND_JAY,
	REMATCH_TRAINER_JEFFREY,
	REMATCH_TRAINER_CAMERON,
	REMATCH_TRAINER_JACKI,
	REMATCH_TRAINER_WALTER,
	REMATCH_TRAINER_KAREN,
	REMATCH_TRAINER_JERRY,
	REMATCH_TRAINER_ANNA_AND_MEG,
	REMATCH_TRAINER_ISABEL,
	REMATCH_TRAINER_MIGUEL,
	REMATCH_TRAINER_TIMOTHY,
	REMATCH_TRAINER_SHELBY,
	REMATCH_TRAINER_CALVIN,
	REMATCH_TRAINER_ELLIOT,
	REMATCH_TRAINER_ISAIAH,
	REMATCH_TRAINER_MARIA,
	REMATCH_TRAINER_ABIGAIL,
	REMATCH_TRAINER_DYLAN,
	REMATCH_TRAINER_KATELYN,
	REMATCH_TRAINER_BENJAMIN,
	REMATCH_TRAINER_PABLO,
	REMATCH_TRAINER_NICOLAS,
	REMATCH_TRAINER_ROBERT,
	REMATCH_TRAINER_LAO,
	REMATCH_TRAINER_CYNDY,
	REMATCH_TRAINER_MADELINE,
	REMATCH_TRAINER_JENNY,
	REMATCH_TRAINER_DIANA,
	REMATCH_TRAINER_AMY_AND_LIV,
	REMATCH_TRAINER_ERNEST,
	REMATCH_TRAINER_CORY,
	REMATCH_TRAINER_EDWIN,
	REMATCH_TRAINER_LYDIA,
	REMATCH_TRAINER_ISAAC,
	REMATCH_TRAINER_GABRIELLE,
	REMATCH_TRAINER_CATHERINE,
	REMATCH_TRAINER_JACKSON,
	REMATCH_TRAINER_HALEY,
	REMATCH_TRAINER_JAMES,
	REMATCH_TRAINER_TRENT,
	REMATCH_TRAINER_SAWYER,
	REMATCH_TRAINER_KIRA_AND_DAN,
	REMATCH_TRAINER_WALLY,
	REMATCH_TRAINER_ROXANNE,
	REMATCH_TRAINER_BRAWLY,
	REMATCH_TRAINER_WATTSON,
	REMATCH_TRAINER_FLANNERY,
	REMATCH_TRAINER_NORMAN,
	REMATCH_TRAINER_WINONA,
	REMATCH_TRAINER_TATE_AND_LIZA,
	REMATCH_TRAINER_JUAN,
	REMATCH_TRAINER_SIDNEY,
	REMATCH_TRAINER_PHOEBE,
	REMATCH_TRAINER_GLACIA,
	REMATCH_TRAINER_DRAKE,
	REMATCH_TRAINER_WALLACE,
	REMATCH_TABLE_ENTRIES,
};

struct RematchTrainer
{
    u16 trainerIds[REMATCHES_COUNT];
    u16 mapGroup;
    u16 mapNum;
    u8 phoneContactId;
};

extern const struct RematchTrainer gRematchTable[REMATCH_TABLE_ENTRIES];

extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern u16 gPartnerTrainerId;

void BattleSetup_StartWildBattle(void);
void BattleSetup_StartBattlePikeWildBattle(void);
void BattleSetup_StartRoamerBattle(void);
void StartWallyTutorialBattle(void);
void BattleSetup_StartScriptedWildBattle(void);
void BattleSetup_StartLatiBattle(void);
void BattleSetup_StartLegendaryBattle(void);
void StartGroudonKyogreBattle(void);
void StartRegiBattle(void);
u8 BattleSetup_GetTerrainId(void);
u8 sub_80B100C(s32 arg0);
void ChooseStarter(void);
void ResetTrainerOpponentIds(void);
void SetMapVarsToTrainer(void);
const u8 *BattleSetup_ConfigureTrainerBattle(const u8 *data);
void ConfigureAndSetUpOneTrainerBattle(u8 trainerEventObjId, const u8 *trainerScript);
void ConfigureTwoTrainersBattle(u8 trainerEventObjId, const u8 *trainerScript);
void SetUpTwoTrainersBattle(void);
bool32 GetTrainerFlagFromScriptPointer(const u8 *data);
void SetUpTrainerMovement(void);
u8 GetTrainerBattleMode(void);
bool8 GetTrainerFlag(void);
bool8 HasTrainerBeenFought(u16 trainerId);
void SetTrainerFlag(u16 trainerId);
void ClearTrainerFlag(u16 trainerId);
void BattleSetup_StartTrainerBattle(void);
void BattleSetup_StartRematchBattle(void);
void ShowTrainerIntroSpeech(void);
const u8 *BattleSetup_GetScriptAddrAfterBattle(void);
const u8 *BattleSetup_GetTrainerPostBattleScript(void);
void ShowTrainerCantBattleSpeech(void);
void SetUpTrainerEncounterMusic(void);
const u8 *GetTrainerALoseText(void);
const u8 *GetTrainerBLoseText(void);
const u8 *GetTrainerWonSpeech(void);
void UpdateRematchIfDefeated(s32 rematchTableId);
void IncrementRematchStepCounter(void);
void TryUpdateRandomTrainerRematches(u16 mapGroup, u16 mapNum);
bool32 DoesSomeoneWantRematchIn(u16 mapGroup, u16 mapNum);
bool32 IsRematchTrainerIn(u16 mapGroup, u16 mapNum);
u16 GetLastBeatenRematchTrainerId(u16 trainerId);
bool8 ShouldTryRematchBattle(void);
bool8 IsTrainerReadyForRematch(void);
void ShouldTryGetTrainerScript(void);
u16 CountBattledRematchTeams(u16 trainerId);

#endif // GUARD_BATTLE_SETUP_H
