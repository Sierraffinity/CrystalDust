#include "constants/battle.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattlescriptsForBallThrow:: @ 82DBD08
	.4byte BattleScript_BallThrow        @ BALL_NONE
	.4byte BattleScript_BallThrow        @ BALL_MASTER
	.4byte BattleScript_BallThrow        @ BALL_ULTRA
	.4byte BattleScript_BallThrow        @ BALL_GREAT
	.4byte BattleScript_BallThrow        @ BALL_POKE
	.4byte BattleScript_SafariBallThrow  @ BALL_SAFARI
	.4byte BattleScript_BallThrow        @ BALL_NET
	.4byte BattleScript_BallThrow        @ BALL_DIVE
	.4byte BattleScript_BallThrow        @ BALL_NEST
	.4byte BattleScript_BallThrow        @ BALL_REPEAT
	.4byte BattleScript_BallThrow        @ BALL_TIMER
	.4byte BattleScript_BallThrow        @ BALL_LUXURY
	.4byte BattleScript_BallThrow        @ BALL_PREMIER
	.4byte BattleScript_BallThrow        @ BALL_LEVEL
	.4byte BattleScript_BallThrow        @ BALL_LURE
	.4byte BattleScript_BallThrow        @ BALL_MOON
	.4byte BattleScript_BallThrow        @ BALL_FRIEND
	.4byte BattleScript_BallThrow        @ BALL_FAST
	.4byte BattleScript_BallThrow        @ BALL_HEAVY
	.4byte BattleScript_BallThrow        @ BALL_LOVE
	.4byte BattleScript_ParkBallThrow    @ BALL_PARK

	.align 2
gBattlescriptsForUsingItem:: @ 82DBD3C
	.4byte BattleScript_PlayerUsesItem
	.4byte BattleScript_OpponentUsesHealItem        @ AI_ITEM_FULL_RESTORE
	.4byte BattleScript_OpponentUsesHealItem        @ AI_ITEM_HEAL_HP
	.4byte BattleScript_OpponentUsesStatusCureItem  @ AI_ITEM_CURE_CONDITION
	.4byte BattleScript_OpponentUsesXItem           @ AI_ITEM_X_STAT
	.4byte BattleScript_OpponentUsesGuardSpecs      @ AI_ITEM_GUARD_SPECS

	.align 2
gBattlescriptsForRunningByItem:: @ 82DBD54
	.4byte BattleScript_RunByUsingItem

	.align 2
gBattlescriptsForSafariActions:: @ 82DBD58
	.4byte BattleScript_ActionWatchesCarefully
	.4byte BattleScript_ActionGetNear
	.4byte BattleScript_ActionThrowPokeblock
	.4byte BattleScript_ActionWallyThrow

BattleScript_BallThrow::
	jumpifword CMP_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_DUDE_TUTORIAL, BattleScript_BallThrowByDude
	printstring STRINGID_PLAYERUSEDITEM
	handleballthrow

BattleScript_BallThrowByDude::
	printstring STRINGID_DUDEUSEDITEM
	handleballthrow

BattleScript_SafariBallThrow::
	printstring STRINGID_PLAYERUSEDITEM
	updatestatusicon BS_ATTACKER
	handleballthrow

BattleScript_ParkBallThrow::
	printstring STRINGID_PLAYERUSEDITEM
	updatestatusicon BS_ATTACKER
	handleballthrow

BattleScript_SuccessBallThrow::
	jumpifhalfword CMP_EQUAL, gLastUsedItem, ITEM_SAFARI_BALL, BattleScript_PrintCaughtMonInfo
	incrementgamestat GAME_STAT_POKEMON_CAPTURES
BattleScript_PrintCaughtMonInfo::
	printstring STRINGID_GOTCHAPKMNCAUGHT
	trysetcaughtmondexflags BattleScript_SuccessBallThrow_CheckBugCatchingContest
	printstring STRINGID_PKMNDATAADDEDTODEX
	waitstate
	setbyte gBattleCommunication, 0x0
	displaydexinfo
BattleScript_SuccessBallThrow_CheckBugCatchingContest::
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_BUG_CATCHING_CONTEST, BattleScript_TryNicknameCaughtMon
	jumpifbyte CMP_EQUAL, gBugCatchingContestStatus, 2, BattleScript_SwapBugContestMon
	setcaughtbugcatchingcontestmon
	goto BattleScript_SuccessBallThrowEnd

BattleScript_SwapBugContestMon::
	setbyte gBattleCommunication, 0
	swapbugcatchingcontestmon
	goto BattleScript_SuccessBallThrowEnd

BattleScript_TryNicknameCaughtMon::
	printstring STRINGID_GIVENICKNAMECAPTURED
	waitstate
	setbyte gBattleCommunication, 0x0
	trygivecaughtmonnick BattleScript_GiveCaughtMonEnd
	givecaughtmon
	printfromtable gCaughtMonStringIds
	waitmessage 0x40
	goto BattleScript_SuccessBallThrowEnd
BattleScript_GiveCaughtMonEnd::
	givecaughtmon
BattleScript_SuccessBallThrowEnd::
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_WallyBallThrow::
	printstring STRINGID_GOTCHAPKMNCAUGHT2
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_ShakeBallThrow::
	printfromtable gBallEscapeStringIds
	waitmessage 0x40
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_SAFARI, BattleScript_ShakeBallThrow_CheckParkBalls
	jumpifbyte CMP_NOT_EQUAL, gNumSafariBalls, 0x0, BattleScript_ShakeBallThrowEnd
	printstring STRINGID_OUTOFSAFARIBALLS
	waitmessage 0x40
	setbyte gBattleOutcome, B_OUTCOME_NO_SAFARI_BALLS
	goto BattleScript_ShakeBallThrowEnd
BattleScript_ShakeBallThrow_CheckParkBalls::
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_BUG_CATCHING_CONTEST, BattleScript_ShakeBallThrowEnd
	jumpifbyte CMP_NOT_EQUAL, gNumParkBalls, 0x0, BattleScript_ShakeBallThrowEnd
	printstring STRINGID_OUTOFPARKBALLS
	waitmessage 0x40
	setbyte gBattleOutcome, B_OUTCOME_NO_PARK_BALLS
BattleScript_ShakeBallThrowEnd::
	finishaction

BattleScript_TrainerBallBlock::
	waitmessage 0x40
	printstring STRINGID_TRAINERBLOCKEDBALL
	waitmessage 0x40
	printstring STRINGID_DONTBEATHIEF
	waitmessage 0x40
	finishaction

BattleScript_PlayerUsesItem::
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	end

BattleScript_OpponentUsesHealItem::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_OpponentUsesStatusCureItem::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable gTrainerItemCuredStatusStringIds
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_OpponentUsesXItem::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable gStatUpStringIds
	waitmessage 0x40
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_OpponentUsesGuardSpecs::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse SE_USE_ITEM
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable gMistUsedStringIds
	waitmessage 0x40
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_RunByUsingItem::
	playse SE_FLEE
	setbyte gBattleOutcome, B_OUTCOME_RAN
	finishturn

BattleScript_ActionWatchesCarefully:
	printstring STRINGID_PKMNWATCHINGCAREFULLY
	waitmessage 0x40
	end2

BattleScript_ActionGetNear:
	printfromtable gSafariGetNearStringIds
	waitmessage 0x40
	end2

BattleScript_ActionThrowPokeblock:
	printstring STRINGID_THREWPOKEBLOCKATPKMN
	waitmessage 0x40
	playanimation BS_ATTACKER, B_ANIM_POKEBLOCK_THROW, NULL
	printfromtable gSafariPokeblockResultStringIds
	waitmessage 0x40
	end2

BattleScript_ActionWallyThrow:
	printstring STRINGID_RETURNMON
	waitmessage 0x40
	returnatktoball
	waitstate
	trainerslidein BS_TARGET
	waitstate
	printstring STRINGID_YOUTHROWABALLNOWRIGHT
	waitmessage 0x40
	end2
