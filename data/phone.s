#include "constants/global.h"
#include "constants/battle_frontier.h"
#include "constants/battle_setup.h"
#include "constants/day_night.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/fruit_trees.h"
#include "constants/decorations.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/map_scripts.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/radio.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/text.h"
#include "constants/vars.h"
#include "constants/weather.h"
#include "constants/trainer_hill.h"
#include "constants/battle.h"
#include "constants/metatile_labels.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.include "data/phone_script_cmd_table.inc"

PhoneScript_Mom::
	phone_goto_if_set FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST, PhoneScript_Mom_RegularCall
	phone_goto_if_set FLAG_DUDE_TALKED_TO_YOU, PhoneScript_Mom_BeginPhoneBanking
	phone_goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, PhoneScript_Mom_GaveEggToElm
	phone_goto_if_set FLAG_SYS_POKEMON_GET, PhoneScript_Mom_GotMon
	phone_stdcall Text_Pokegear_Mom_Start
	phone_end

PhoneScript_Mom_RegularCall:
	phone_initcall
	phone_end_if_not_available
	phone_message Text_Pokegear_Mom_RegularCall_WorkingHard
	phone_getmapinfo
	phone_buffermapsecname 0, VAR_0x8005
	phone_compare VAR_0x8004, MAP_TYPE_TOWN
	phone_goto_if_eq PhoneScript_Mom_CityOrTown
	phone_compare VAR_0x8004, MAP_TYPE_CITY
	phone_goto_if_eq PhoneScript_Mom_CityOrTown
	phone_compare VAR_0x8004, MAP_TYPE_ROUTE
	phone_goto_if_eq PhoneScript_Mom_Route
	phone_compare VAR_0x8004, MAP_TYPE_OCEAN_ROUTE
	phone_goto_if_eq PhoneScript_Mom_Route
	phone_message Text_Pokegear_Mom_RegularCall_Determined
PhoneScript_Mom_PostLocationBanking:
	phone_checkbankedmoney 1 @ Check to see if the bank has at least a dollar
	phone_compare VAR_RESULT, TRUE
	phone_goto_if_eq PhoneScript_MomBank_HasMoney
	phone_goto_if_set FLAG_SYS_MOM_BANKING_ENABLED, PhoneScript_MomBank_HasNoMoneySavingEnabled
	phone_message Text_Pokegear_MomBank_HasNoMoneySavingDisabled
	phone_yesnobox
	phone_compare VAR_RESULT, FALSE
	phone_goto_if_eq PhoneScript_MomBank_WontSave
	phone_goto PhoneScript_MomBank_WillSave

PhoneScript_MomBank_HasNoMoneySavingEnabled:
	phone_message Text_Pokegear_MomBank_HasNoMoneySavingEnabled
	phone_yesnobox
	phone_compare VAR_RESULT, FALSE
	phone_goto_if_eq PhoneScript_MomBank_WontSave
	phone_goto PhoneScript_MomBank_WillSave

PhoneScript_MomBank_HasMoney:
	phone_bufferbankedmoney 0
	phone_goto_if_set FLAG_SYS_MOM_BANKING_ENABLED, PhoneScript_MomBank_HasMoneySavingEnabled
	phone_message Text_Pokegear_MomBank_HasMoneySavingDisabled
	phone_yesnobox
	phone_compare VAR_RESULT, FALSE
	phone_goto_if_eq PhoneScript_MomBank_WontSave
	phone_goto PhoneScript_MomBank_WillSave

PhoneScript_MomBank_HasMoneySavingEnabled:
	phone_message Text_Pokegear_MomBank_HasMoneySavingEnabled
	phone_yesnobox
	phone_compare VAR_RESULT, FALSE
	phone_goto_if_eq PhoneScript_MomBank_WontSave
	@ fallthrough

PhoneScript_MomBank_WillSave:
	phone_setflag FLAG_SYS_MOM_BANKING_ENABLED
	phone_message Text_Pokegear_MomBank_EnableSaving
	phone_goto PhoneScript_Mom_PostBanking

PhoneScript_MomBank_WontSave:
	phone_clearflag FLAG_SYS_MOM_BANKING_ENABLED
	phone_message Text_Pokegear_MomBank_DisableSaving
	@ fallthrough

PhoneScript_Mom_PostBanking:
	phone_message Text_Pokegear_Mom_RootingForYou
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Mom_CityOrTown:
	phone_compare VAR_0x8005, MAPSEC_NEW_BARK_TOWN
	phone_goto_if_eq PhoneScript_Mom_NewBark
	phone_compare VAR_0x8005, MAPSEC_CHERRYGROVE_CITY
	phone_goto_if_eq PhoneScript_Mom_Cherrygrove
	phone_compare VAR_0x8005, MAPSEC_VIOLET_CITY
	phone_goto_if_eq PhoneScript_Mom_Violet
	phone_compare VAR_0x8005, MAPSEC_AZALEA_TOWN
	phone_goto_if_eq PhoneScript_Mom_Azalea
	phone_compare VAR_0x8005, MAPSEC_GOLDENROD_CITY
	phone_goto_if_eq PhoneScript_Mom_Goldenrod
	phone_message Text_Pokegear_Mom_RegularCall_NeverGoneThere
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_NewBark:
	phone_message Text_Pokegear_Mom_RegularCall_NewBark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Cherrygrove:
	phone_message Text_Pokegear_Mom_RegularCall_Cherrygrove
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Violet:
	phone_buffermapsecname 1, MAPSEC_SPROUT_TOWER
	phone_message Text_Pokegear_Mom_RegularCall_Landmark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Azalea:
	phone_buffermapsecname 1, MAPSEC_SLOWPOKE_WELL
	phone_message Text_Pokegear_Mom_RegularCall_Landmark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Goldenrod:
	phone_buffermapsecname 1, MAPSEC_RADIO_TOWER
	phone_message Text_Pokegear_Mom_RegularCall_Landmark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Route:
	phone_message Text_Pokegear_Mom_RegularCall_Route
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_BeginPhoneBanking:
	phone_initcall
	phone_end_if_not_available
	phone_setflag FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST
	phone_message Text_Pokegear_Mom_PhoneBanking_Question
	phone_yesnobox
	phone_compare VAR_RESULT, 0
	phone_goto_if_eq PhoneScript_Mom_NoPhoneBanking
	phone_setflag FLAG_SYS_MOM_BANKING_ENABLED
	phone_message Text_Pokegear_MomBank_EnableSaving
	phone_goto PhoneScript_Mom_PostBanking

PhoneScript_Mom_NoPhoneBanking:
	phone_clearflag FLAG_SYS_MOM_BANKING_ENABLED
	phone_message Text_Pokegear_MomBank_DisableSaving
	phone_goto PhoneScript_Mom_PostBanking

PhoneScript_Mom_GaveEggToElm:
	phone_stdcall Text_Pokegear_Mom_GaveEggToElm
	phone_end

PhoneScript_Mom_GotMon:
	phone_stdcall Text_Pokegear_Mom_GotMon
	phone_end

Text_Pokegear_Mom_Start:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}!\p"
	.string "Wasn't PROF. ELM waiting for you?$"

Text_Pokegear_Mom_GotMon:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}!\p"
	.string "You're on a big mission for PROF. ELM?\n"
	.string "Be good!$"

Text_Pokegear_Mom_GaveEggToElm:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}!\p"
	.string "If you're done with your errand,\n"
	.string "come on home, dear.$"

Text_Pokegear_Mom_PhoneBanking_Question:
	.string "Hello?\n"
	.string "…… {PLAYER}?\p"
	.string "I heard from PROF. ELM that you\n"
	.string "went on a long trip.\p"
	.string "I wish you would have told me…\p"
	.string "What about money?\n"
	.string "Do you want me to save it?$"

Text_Pokegear_Mom_RegularCall_WorkingHard:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}! Working hard?\p$"

Text_Pokegear_Mom_RegularCall_NeverGoneThere:
	.string "Really, you're in {STR_VAR_1}?\p"
	.string "I've never gone there.\n"
	.string "That's kind of neat, {PLAYER}.\p$"

Text_Pokegear_Mom_RegularCall_NewBark:
	.string "What? You're in {STR_VAR_1}?\n"
	.string "Come see your MOM sometime!\p$"

Text_Pokegear_Mom_RegularCall_Cherrygrove:
	.string "You're visiting {STR_VAR_1}?\n"
	.string "How about coming home for a bit?\p$"

Text_Pokegear_Mom_RegularCall_Landmark:
	.string "Oh, so you're in {STR_VAR_1}?\p"
	.string "Isn't that where {STR_VAR_2}\n"
	.string "is? Did you go take a look?\p$"

Text_Pokegear_Mom_RegularCall_Route:
	.string "Wow, you're in {STR_VAR_1}?\n"
	.string "Good luck on your {POKEMON} quest!\p$"

Text_Pokegear_Mom_RegularCall_Determined:
	.string "That sounds really tough.\p"
	.string "But, {PLAYER}, I know you're really\n"
	.string "determined. You'll be okay, right?\p$"

Text_Pokegear_MomBank_HasNoMoneySavingDisabled:
	.string "Oh, {PLAYER}, you're not saving any\n"
	.string "money. Would you like to start saving?$"

Text_Pokegear_MomBank_HasNoMoneySavingEnabled:
	.string "It's important to save your money.\n"
	.string "Do you want to keep on saving?$"

Text_Pokegear_MomBank_HasMoneySavingDisabled:
	.string "By the way, you've saved up ¥{STR_VAR_1}.\n"
	.string "Want to start saving again?$"

Text_Pokegear_MomBank_HasMoneySavingEnabled:
	.string "By the way, you've saved up ¥{STR_VAR_1}.\n"
	.string "Do you want to keep on saving?$"

Text_Pokegear_MomBank_EnableSaving:
	.string "Okay, I'll save your money.\p$"

Text_Pokegear_MomBank_DisableSaving:
	.string "Okay, I won't save your money.\p$"

Text_Pokegear_Mom_RootingForYou:
	.string "{PLAYER}, keep it up!\n"
	.string "I'm rooting for you, baby!$"

PhoneScript_Elm::
	phone_goto_if_set FLAG_SHOWED_TOGEPI_TO_ELM, PhoneScript_Elm_Discovery
	phone_goto_if_unset FLAG_GOT_ELMS_EGG, PhoneScript_Elm_SkipEggCheck
	phone_goto_if_set FLAG_HATCHED_ELMS_EGG, PhoneScript_Elm_EggHatched
PhoneScript_Elm_SkipEggCheck:
	phone_goto_if_set FLAG_GOT_ELMS_EGG, PhoneScript_Elm_EggUnhatched
	phone_goto_if_set FLAG_ELM_CALLED_ABOUT_ASSISTANT_IN_VIOLET, PhoneScript_Elm_SeeAssistant
	phone_goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, PhoneScript_Elm_CheckingEgg
	phone_goto_if_set FLAG_ELM_CALLED_ABOUT_STOLEN_MON, PhoneScript_Elm_MonWasStolen
	phone_goto_if_set FLAG_RECEIVED_MYSTERY_EGG, PhoneScript_Elm_SawMrPokemon
	phone_stdcall Text_Pokegear_Elm_Start
	phone_end

PhoneScript_Elm_Discovery::
	phone_random 2
	phone_compare VAR_RESULT, 0
	phone_goto_if_eq PhoneScript_Elm_Discovery2
	phone_stdcall Text_Pokegear_Elm_Discovery1
	phone_end

PhoneScript_Elm_Discovery2:
	phone_stdcall Text_Pokegear_Elm_Discovery2
	phone_end

PhoneScript_Elm_EggHatched::
	phone_stdcall Text_Pokegear_Elm_EggHatched
	phone_setflag FLAG_CALLED_ELM_ABOUT_HATCHED_EGG
	phone_end

PhoneScript_Elm_EggUnhatched::
	phone_stdcall Text_Pokegear_Elm_EggUnhatched
	phone_end

PhoneScript_Elm_SeeAssistant::
	phone_stdcall Text_Pokegear_Elm_SeeAssistant
	phone_end

PhoneScript_Elm_CheckingEgg::
	phone_stdcall Text_Pokegear_Elm_CheckingEgg
	phone_end

PhoneScript_Elm_MonWasStolen::
	phone_stdcall Text_Pokegear_Elm_MonWasStolen
	phone_end

PhoneScript_Elm_SawMrPokemon::
	phone_stdcall Text_Pokegear_Elm_SawMrPokemon
	phone_end

Text_Pokegear_Elm_Start::
	.string "Hello, {PLAYER}?\n"
	.string "Try not to overdo it.\p"
	.string "Be sure to heal your {POKEMON} if\n"
	.string "they are hurt.$"

Text_Pokegear_Elm_SawMrPokemon::
	.string "Hello, {PLAYER}?\n"
	.string "Did you meet MR. {POKEMON}?\p"
	.string "Great!\n"
	.string "Come back safely!$"

Text_Pokegear_Elm_MonWasStolen::
	.string "{PLAYER}?\n"
	.string "I'm very upset right now.\p"
	.string "We had a {POKEMON} stolen from here.\n"
	.string "How could anyone do that?$"

Text_Pokegear_Elm_CheckingEgg::
	.string "Hello, {PLAYER}?\n"
	.string "We're checking the EGG now.\p"
	.string "It does appear to be a {POKEMON}\n"
	.string "EGG.$"

Text_Pokegear_Elm_SeeAssistant::
	.string "Hello, {PLAYER}?\n"
	.string "Did you see my assistant?\p"
	.string "He's at the {POKEMON} CENTER in\n"
	.string "VIOLET CITY.$"

Text_Pokegear_Elm_EggUnhatched::
	.string "Hello, {PLAYER}?\n"
	.string "How's the EGG?\l"
	.string "Has anything changed?\p"
	.string "If anything happens, please call.$"

Text_Pokegear_Elm_EggHatched::
	.string "Hello, {PLAYER}?\n"
	.string "How is the EGG?\p"
	.string "What? It hatched?\n"
	.string "Wow! What kind of {POKEMON} is it?\p"
	.string "Please come show me now!$"

Text_Pokegear_Elm_Discovery1::
	.string "Hello, {PLAYER}?\n"
	.string "I just made a new discovery.\p"
	.string "The time it takes for an EGG to\n"
	.string "hatch depends on the {POKEMON}.$"

Text_Pokegear_Elm_Discovery2::
	.string "Hello, {PLAYER}?\p"
	.string "It's still a mystery what kinds\n"
	.string "of moves hatched {POKEMON} have.\l"
	.string "We're investigating that now.$"

Route30_PhoneScript_ElmCall::
	phone_stdcall Route30_Text_ElmCall
	phone_setflag FLAG_ELM_CALLED_ABOUT_STOLEN_MON
	phone_end

Route30_Text_ElmCall:
	.string "H-hello? {PLAYER}?\n"
	.string "It's a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do?\n"
	.string "It… Oh, no…\p"
	.string "Please get back here now!$"

VioletCity_PhoneScript_ElmCall::
	phone_stdcall VioletCity_Text_ElmCall
	phone_setflag FLAG_ELM_CALLED_ABOUT_ASSISTANT_IN_VIOLET
	phone_setflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_AIDE
	phone_clearflag FLAG_HIDE_VIOLET_CITY_POKEMON_CENTER_1F_ELMS_AIDE
	phone_end

VioletCity_Text_ElmCall:
	.string "Hello, {PLAYER}?\n"
	.string "We discovered something about\l"
	.string "the EGG!\p"
	.string "My assistant is at the {POKEMON}\n"
	.string "CENTER in VIOLET CITY.\l"
	.string "Could you talk to him?$"

PhoneScript_BikeShop::
	phone_stdcall Text_BikeShopOwnerCall
	phone_clearflag FLAG_BIKE_SHOP_LOAN_ACTIVE
	phone_end

Text_BikeShopOwnerCall:
	.string "Hi, {PLAYER}! Our BICYCLE sales\n"
	.string "have gone through the roof!\p"
	.string "We owe it all to your advertising\n"
	.string "by riding around on our BICYCLE.\p"
	.string "As our way of saying thanks, please\n"
	.string "keep that BICYCLE.\p"
	.string "Thanks again!$"

PhoneScript_Bill::
	phone_initcall
	phone_end_if_not_available
	phone_gettime
	phone_compare VAR_0x8002, TIME_MORNING
	phone_call_if_eq PhoneScript_Bill_Greeting_Morning
	phone_compare VAR_0x8002, TIME_DAY
	phone_call_if_eq PhoneScript_Bill_Greeting_Day
	phone_compare VAR_0x8002, TIME_NIGHT
	phone_call_if_eq PhoneScript_Bill_Greeting_Night
	phone_message Text_Bill_WhosCalling
	phone_callnativecontext Special_GetFreePokemonStorageSpace
	phone_copyvar VAR_0x8000, VAR_RESULT
	phone_compare VAR_0x8000, 0
	phone_goto_if_eq PhoneScript_Bill_NoSpace
	phone_bufferboxname 0, VAR_PC_BOX_TO_SEND_MON
	phone_random 3
	phone_compare VAR_RESULT, 0
	phone_call_if_eq PhoneScript_Bill_StartingOnThisBox_Variant1
	phone_compare VAR_RESULT, 1
	phone_call_if_eq PhoneScript_Bill_StartingOnThisBox_Variant2
	phone_compare VAR_RESULT, 2
	phone_call_if_eq PhoneScript_Bill_StartingOnThisBox_Variant3
	phone_buffernumberstring 1, VAR_0x8000
	phone_compare VAR_0x8000, 6
	phone_goto_if_lt PhoneScript_Bill_LittleSpace
	phone_message Text_Bill_RoomRemaining
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Bill_Greeting_Morning:
	phone_message Text_Bill_Greeting_Morning
	phone_return

PhoneScript_Bill_Greeting_Day:
	phone_message Text_Bill_Greeting_Day
	phone_return

PhoneScript_Bill_Greeting_Night:
	phone_message Text_Bill_Greeting_Night
	phone_return

PhoneScript_Bill_StartingOnThisBox_Variant1:
	phone_message Text_Bill_StartingOnThisBox_Variant1
	phone_return

PhoneScript_Bill_StartingOnThisBox_Variant2:
	phone_message Text_Bill_StartingOnThisBox_Variant2
	phone_return

PhoneScript_Bill_StartingOnThisBox_Variant3:
	phone_message Text_Bill_StartingOnThisBox_Variant3
	phone_return

PhoneScript_Bill_LittleSpace:
	phone_message Text_Bill_LittleRoomRemaining
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Bill_NoSpace:
	phone_message Text_Bill_NoRoomRemaining
	phone_waitbuttonpress
	phone_hangup
	phone_end

Text_Bill_Greeting_Morning:
	.string "Good morning!\p"
	.string "This is the {POKEMON} STORAGE SYSTEM\n"
	.string "ADMINISTRATION SERVICE.\p$"

Text_Bill_Greeting_Day:
	.string "Good day!\p"
	.string "This is the {POKEMON} STORAGE SYSTEM\n"
	.string "ADMINISTRATION SERVICE.\p$"

Text_Bill_Greeting_Night:
	.string "Good evening!\p"
	.string "This is the {POKEMON} STORAGE SYSTEM\n"
	.string "ADMINISTRATION SERVICE.\p$"

Text_Bill_WhosCalling:
	.string "Who's calling?\p"
	.string "{PLAYER}, is it?\n"
	.string "Hang on a sec…\p"
	.string "…\n"
	.string "…\p$"

Text_Bill_StartingOnThisBox_Variant1:
	.string "Thanks for waiting!\p"
	.string "{PLAYER}, you're starting on the BOX\n"
	.string "named “{STR_VAR_1}” right now.\l"
	.string "Great name, by the way.\p$"

Text_Bill_StartingOnThisBox_Variant2:
	.string "Thanks for waiting!\p"
	.string "Right now, {PLAYER}, you're using the\n"
	.string "BOX named “{STR_VAR_1},” right?\l"
	.string "That's a good name right there.\p$"

Text_Bill_StartingOnThisBox_Variant3:
	.string "Thanks for waiting!\p"
	.string "So, {PLAYER}, your BOX is called\n"
	.string "“{STR_VAR_1},” right?\l"
	.string "Not just anyone would use that name.\p$"

Text_Bill_RoomRemaining:
	.string "Okay, including the space left in\n"
	.string "“{STR_VAR_1},” you have room for {STR_VAR_2}\l"
	.string "more {POKEMON} in the PC.\p"
	.string "Get out there and keep collecting!$"

Text_Bill_LittleRoomRemaining:
	.string "Okay, including the space left in\n"
	.string "“{STR_VAR_1},” you only have room for\l"
	.string "{STR_VAR_2} more {POKEMON} in the PC.\p"
	.string "Soon, you'll have to release some\n"
	.string "{POKEMON} if you want to catch more.$"

Text_Bill_NoRoomRemaining:
	.string "Thanks for waiting!\p"
	.string "{PLAYER}, your PC BOXES are chock-\n"
	.string "full of {POKEMON}!\p"
	.string "You'll have to release some {POKEMON}\n"
	.string "if you want to catch more.\p"
	.string "Bye now!$"

Text_Bill_JustRanOutOfRoom:
	.string "Hi, {PLAYER}? It's me, BILL!\n"
	.string "Thanks for using my STORAGE SYSTEM.\p"
	.string "That last {POKEMON} you sent filled\n"
	.string "your PC BOXES up! Wow!\p"
	.string "Seriously, I know a stellar collection\n"
	.string "when I see it! Well done!\p"
	.string "However, if you want to catch more\n"
	.string "{POKEMON}, you'll have to release some…\p"
	.string "I just don't have the storage capacity\n"
	.string "to hold any more {POKEMON} for you!\p"
	.string "Though, I know a girl named BRIGETTE\n"
	.string "who might have some extra space…\l"
	.string "Well, for now, you're full up!\p"
	.string "Bye now!$"

PhoneScript_Bill_JustRanOutOfRoom::
	phone_stdcall Text_Bill_JustRanOutOfRoom
	phone_end

PhoneScript_StandardMatchCallTrainer::
	phone_callnativecontext SelectMessage_StandardMatchCallTrainer
	phone_stdcall gStringVar4
	phone_end

RadioTower_PhoneScript_ElmCall::
	phone_stdcall RadioTower_Text_ElmCall
	phone_end

RadioTower_Text_ElmCall:
	.string "{PLAYER}, how are things going?\p"
	.string "I called because something weird is\n"
	.string "happening with the radio broadcasts.\p"
	.string "They were talking about TEAM ROCKET.\p"
	.string "Maybe TEAM ROCKET has returned.\n"
	.string "No, that just can't be true.\p"
	.string "Sorry to bug you.\n"
	.string "Take care!$"

MasterBall_PhoneScript_ElmCall::
	phone_stdcall MasterBall_Text_ElmCall
	phone_end

MasterBall_Text_ElmCall:
	.string "Hello, {PLAYER}?\p"
	.string "I have something here for you.\n"
	.string "Could you swing by my LAB?\p"
	.string "See you later!$"

InviteToSevii_Text_BillCall:
	.string "Hi, {PLAYER}? It's me, BILL!\n"
	.string "Thanks for using my STORAGE SYSTEM.\p"
	.string "I have a favor to ask…\p"
	.string "You know how the volcano in CINNABAR\n"
	.string "erupted and destroyed the town?\p"
	.string "Fortunately, everyone was evacuated\n"
	.string "in time and no one was hurt…\p"
	.string "Well, CINNABAR's volcano is part of\n"
	.string "a volcanic system that stretches to\l"
	.string "this little island far to the south.\p"
	.string "What island? ONE ISLAND, of course!\n"
	.string "It's down in the SEVII ISLANDS.\p"
	.string "MT. EMBER there erupted first, giving\n"
	.string "us a warning that CINNABAR was next.\p"
	.string "The damage was pretty bad in the SEVII\n"
	.string "ISLANDS, and they're still recovering.\p"
	.string "A friend invited me to THREE ISLAND.\n"
	.string "Well, in truth, he asked for my help…\p"
	.string "The last time I went to SEVII, I\n"
	.string "brought a strong TRAINER with me.\p"
	.string "This time I think it's even more vital\n"
	.string "to bring someone like that along.\p"
	.string "When you're not busy, would you\n"
	.string "please meet me on CINNABAR ISLAND?\p"
	.string "I'll be waiting for you in the\n"
	.string "{POKEMON} CENTER there.\p"
	.string "Thanks, {PLAYER}!\n"
	.string "See you soon!$"


PhoneScript_Bill_InviteToSevii::
	phone_stdcall InviteToSevii_Text_BillCall
	phone_end

PhoneScript_Mom_BoughtItem::
	phone_compare VAR_0x8004, 1
	phone_goto_if_eq PhoneScript_Mom_BoughtDoll
	phone_stdcall BoughtItem_Text_MomCall
	phone_end

PhoneScript_Mom_BoughtDoll::
	phone_stdcall BoughtDoll_Text_MomCall
	phone_end

BoughtItem_Text_MomCall:
	.string "Hi, {PLAYER}!\n"
	.string "How are you?\p"
	.string "I found a useful item shopping, so\n"
	.string "I bought it with your money. Sorry!\p"
	.string "It's in your PC.\n"
	.string "You'll like it!$"

BoughtDoll_Text_MomCall:
	.string "Hi, {PLAYER}!\n"
	.string "How are you?\p"
	.string "While shopping today, I saw this\n"
	.string "adorable doll, so I bought it with\l"
	.string "your money. Sorry!\p"
	.string "It's in your room.\n"
	.string "You'll love it!$"
