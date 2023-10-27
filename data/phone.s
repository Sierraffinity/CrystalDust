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
	phone_initcall
	phone_callnativecontext SelectMessage_StandardMatchCallTrainer_Opening
	phone_message gStringVar4
	phone_waitbuttonpress
	phone_callnativecontext SelectMessage_StandardMatchCallTrainer
	phone_message gStringVar4
	phone_waitbuttonpress
	phone_callnativecontext SelectMessage_StandardMatchCallTrainer_Hangup
	phone_message gStringVar4
	phone_waitbuttonpress
	phone_hangup
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

PhoneScript_Buena::
	phone_callnativecontext isPlayerBeingCalled
	phone_compare VAR_RESULT, 0
	phone_goto_if_eq PhoneScript_Buena_Call
	phone_compare VAR_RESULT, 1
	phone_goto_if_eq PhoneScript_Buena_Caller

PhoneScript_Buena_Call:
	phone_initcall
	phone_end_if_not_available
	phone_goto_if_set FLAG_ROCKETS_IN_RADIO_TOWER, PhoneScript_Buena_Rocket
	phone_gettime
	phone_compare VAR_0x8000, 17
	phone_goto_if_gt PhoneScript_Buena_Midnight_Answer
	phone_compare VAR_0x8002, TIME_MORNING
	phone_call_if_eq PhoneScript_Buena_Morning_Answer
	phone_compare VAR_0x8002, TIME_DAY
	phone_call_if_eq PhoneScript_Buena_Day_Answer
	phone_compare VAR_0x8002, TIME_NIGHT
	phone_call_if_eq PhoneScript_Buena_Night_Answer
	phone_random 3
	phone_compare VAR_RESULT, 0
	phone_call_if_eq PhoneScript_Buena_Favorite_Slot_Machine
	phone_compare VAR_RESULT, 1
	phone_call_if_eq PhoneScript_Buena_Pokegear
	phone_compare VAR_RESULT, 2
	phone_call_if_eq PhoneScript_Buena_Cooped_Up
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Buena_Morning_Answer:
	phone_message BuenaPhoneMorningAnswerText
	phone_return

PhoneScript_Buena_Day_Answer:
	phone_message BuenaPhoneDayAnswerText
	phone_return

PhoneScript_Buena_Night_Answer:
	phone_message BuenaPhoneNiteAnswerText
	phone_return

PhoneScript_Buena_Midnight_Answer:
	phone_message BuenaPhoneMidnightAnswerText
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Buena_Favorite_Slot_Machine:
	phone_message BuenaPhoneFavoriteSlotMachineAnswerText
	phone_return

PhoneScript_Buena_Pokegear:
	phone_message BuenaPhonePokegearAnswerText
	phone_return

PhoneScript_Buena_Cooped_Up:
	phone_message BuenaPhoneCoopedUpInRadioTowerAnswerText
	phone_return

PhoneScript_Buena_Caller::
	phone_initcall
	phone_end_if_not_available
	phone_goto_if_set FLAG_ROCKETS_IN_RADIO_TOWER, PhoneScript_Buena_Rocket
	phone_gettime
	phone_compare VAR_0x8000, 17
	phone_goto_if_gt PhoneScript_Buena_Midnight_Call
	phone_compare VAR_0x8002, TIME_MORNING
	phone_call_if_eq PhoneScript_Buena_Morning_Call
	phone_compare VAR_0x8002, TIME_DAY
	phone_call_if_eq PhoneScript_Buena_Day_Call
	phone_compare VAR_0x8002, TIME_NIGHT
	phone_call_if_eq PhoneScript_Buena_Night_Call
	phone_call_if_set FLAG_IS_CHAMPION, PhoneScript_Buena_Random_14
	phone_call_if_unset FLAG_IS_CHAMPION, PhoneScript_Buena_Random_11
	phone_compare VAR_RESULT, 0
	phone_call_if_eq PhoneScript_Buena_Went_Out_With_Ben
	phone_compare VAR_RESULT, 1
	phone_call_if_eq PhoneScript_Buena_Receptionist
	phone_compare VAR_RESULT, 2
	phone_call_if_eq PhoneScript_Buena_Lucky_Number
	phone_compare VAR_RESULT, 3
	phone_call_if_eq PhoneScript_Buena_Stressed_From_Work
	phone_compare VAR_RESULT, 4
	phone_call_if_eq PhoneScript_Buena_Professor_Oak
	phone_compare VAR_RESULT, 5
	phone_call_if_eq PhoneScript_Buena_Cold
	phone_compare VAR_RESULT, 6
	phone_call_if_eq PhoneScript_Buena_Radio_Card_Questions
	phone_compare VAR_RESULT, 7
	phone_call_if_eq PhoneScript_Buena_Pikachu_Fan_Club
	phone_compare VAR_RESULT, 8
	phone_call_if_eq PhoneScript_Buena_Radio_Tower_Director
	phone_compare VAR_RESULT, 9
	phone_call_if_eq PhoneScript_Buena_When_Do_You_Relax
	phone_compare VAR_RESULT, 10
	phone_call_if_eq PhoneScript_Buena_Starter_Pokemon
	phone_compare VAR_RESULT, 11
	phone_call_if_eq PhoneScript_Buena_Company_Vacation
	phone_compare VAR_RESULT, 12
	phone_call_if_eq PhoneScript_Buena_Ben_And_Fern
	phone_compare VAR_RESULT, 13
	phone_call_if_eq PhoneScript_Buena_Going_Shopping
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Buena_Random_11:
	phone_random 11
	phone_return

PhoneScript_Buena_Random_14:
	phone_random 14
	phone_return

PhoneScript_Buena_Rocket:
	phone_message BuenaPhoneRocketText
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Buena_Morning_Call:
	phone_message BuenaPhoneMorningText
	phone_return

PhoneScript_Buena_Day_Call:
	phone_message BuenaPhoneDayText
	phone_return

PhoneScript_Buena_Night_Call:
	phone_message BuenaPhoneNiteText
	phone_return

PhoneScript_Buena_Midnight_Call:
	phone_message BuenaPhoneMidnightText
	phone_return

PhoneScript_Buena_Went_Out_With_Ben:
	phone_message BuenaPhoneWentOutWithBenText
	phone_return

PhoneScript_Buena_Receptionist:
	phone_message BuenaPhoneReceptionistText
	phone_return

PhoneScript_Buena_Lucky_Number:
	phone_message BuenaPhoneLuckyNumberShowText
	phone_return

PhoneScript_Buena_Stressed_From_Work:
	phone_message BuenaPhoneStressedFromWorkText
	phone_return

PhoneScript_Buena_Professor_Oak:
	phone_message BuenaPhoneProfessorOakText
	phone_return

PhoneScript_Buena_Cold:
	phone_message BuenaPhoneGotAColdText
	phone_return

PhoneScript_Buena_Radio_Card_Questions:
	phone_message BuenaPhoneRadioCardQuestionsText
	phone_return

PhoneScript_Buena_Pikachu_Fan_Club:
	phone_message BuenaPhonePikachuFanClubText
	phone_return

PhoneScript_Buena_Radio_Tower_Director:
	phone_message BuenaPhoneRadioTowerDirectorText
	phone_return

PhoneScript_Buena_When_Do_You_Relax:
	phone_message BuenaPhoneWhenDoYouRelaxText
	phone_return

PhoneScript_Buena_Starter_Pokemon:
	phone_message BuenaPhoneStarterPokemonText
	phone_return

PhoneScript_Buena_Company_Vacation:
	phone_message BuenaPhoneCompanyVacationText
	phone_return

PhoneScript_Buena_Ben_And_Fern:
	phone_message BuenaPhoneBenAndFernText
	phone_return

PhoneScript_Buena_Going_Shopping:
	phone_message BuenaPhoneGoingShoppingText
	phone_return

Text_Buena_RegularCall:
	.string "Hi, {PLAYER}!\n"
	.string "I'm BUENA!\p"
	.string "Bye-bye!$"

BuenaPhoneMorningAnswerText:
	.string "Hi, this is BUENA…\n"
	.string "Oh! Good morning, {PLAYER}!"
	.string "I'm kind of foggy in the morning…\p$"

BuenaPhoneDayAnswerText:
	.string "Hi, this is BUENA…\n"
	.string "Oh! Hi, {PLAYER}!\l"
	.string "Do you tune into BUENA's show?\p$"

BuenaPhoneMidnightAnswerText:
	.string "This is BUENA.\n"
	.string "I can't come to the phone right now.\l"
	.string "If you want to chat, tune into\l"
	.string "BUENA's PASSWORD on the radio and\l"
	.string "give me a call after midnight!$"

BuenaPhoneNiteAnswerText:
	.string "Hi, this is BUENA…\n"
	.string "Oh! Hi, {PLAYER}!\l"
	.string "I just got off work.\l"
	.string "Let me tell you, I'm exhausted!\p$"

BuenaPhoneMorningText:
	.string "{PLAYER}!\n"
	.string "Hi, it's BUENA!\l"
	.string "I got up early, so I decided to call!\p$"

BuenaPhoneDayText:
	.string "{PLAYER}!\n"
	.string "Hi, it's BUENA!\l"
	.string "I needed someone to chat with!\p$"

BuenaPhoneMidnightText:
	.string "{PLAYER}!\n"
	.string "Hi, it's BUENA!\l"
	.string "I'm just on my break.\p$"

BuenaPhoneNiteText:
	.string "{PLAYER}!\n"
	.string "Hi, it's BUENA!\l"
	.string "I couldn't sleep, so I called you.\p$"

BuenaPhoneRocketText:
	.string "Oh. Hi, {PLAYER}\n!"
	.string "You are how?\p"
	.string "Aiyee! This isn't the time for me to\n"
	.string "be cracking silly gag greetings!\l"
	.string "The RADIO TOWER is in deep trouble!\l"
	.string "{PLAYER}, you'd better be careful!$"

BuenaPhoneWentOutWithBenText:
	.string "The other day, I went out to eat\n"
	.string "with DJ BEN!\l"
	.string "Isn't it great?\l"
	.string "Not only that, he said the music on\l"
	.string "my program is cool!\l"
	.string "Oh, wow! Like, what should I do?\p"
	.string "…Oops, I have to get ready for my show!\n"
	.string "I'll catch you later!$"

BuenaPhoneReceptionistText:
	.string "You know the receptionist at the RADIO TOWER?\n"
	.string "'Welcome,' is all she ever says.\l"
	.string "But she's really the chattiest person\l"
	.string "at the RADIO TOWER.\l"
	.string "So she must be holding back.\l"
	.string "Isn't that fun to know?\l"
	.string "Catch you later!$"

BuenaPhoneLuckyNumberShowText:
	.string "Tell me, {PLAYER}.\n"
	.string "Have you ever won a prize on the\l"
	.string "LUCKY NUMBER SHOW?\l"
	.string "REED moans that he's never won,\l"
	.string "so he vows to keep the show on the\l"
	.string "air till he does.\l"
	.string "Let's chat again!$"

BuenaPhoneStressedFromWorkText:
	.string "You know, last night…\n"
	.string "I was so stressed out from work,\l"
	.string "I ate a ton of junk food!\l"
	.string "MARY and I have this deal about\l"
	.string "losing weight…\p"
	.string "This won't do…\p"
	.string "Huh? What's the weight?\n"
	.string "That has to be a total secret!\l"
	.string "MARY weighs…\p"
	.string "Aiyee! M-MARY!\p"
	.string "Uh… Um… I… Sorry-- wrong number!$"

BuenaPhoneProfessorOakText:
	.string "Yesterday, PROF. OAK was in the\n"
	.string "studio to tape his show.\l"
	.string "So I went over and introduced myself.\l"
	.string "Get this--he tunes in to my program!\l"
	.string "Oh! Here comes PROF.OAK again!\p"
	.string "I'm going to chat him up again!\n"
	.string "Catch you later!$"

BuenaPhoneGotAColdText:
	.string "…Cough, cough!\p"
	.string "Uhm sorry uh got uh code dite now.\n"
	.string "Buh uma pro so uh hav to cover id ub\l"
	.string "so no un notice while uhm on air.\p"
	.string "Uh fidz muh voice now.\p"
	.string "I'll catch you on the fly.\n"
	.string "This has been BUENA!$"

BuenaPhoneRadioCardQuestionsText:
	.string "Hey, {PLAYER}.\n"
	.string "You won that RADIO CARD by beating\l"
	.string "the quiz at the reception desk, didn't you?\p"
	.string "Guess what? I made up the questions!\n"
	.string "…Were they too easy for you?\l"
	.string "Well, let's chat again!$"

BuenaPhonePikachuFanClubText:
	.string "I'm elated that more people are\n"
	.string "taking part in my PASSWORD show.\l"
	.string "But when PIKACHU was the password,\l"
	.string "it was uh… whew… overwhelming.\p"
	.string "FAN CLUB people came out in droves,\n"
	.string "shouting 'PIKACHU!' over and over.\l"
	.string "I mean, they were loud.\p"
	.string "Anyone tuning in around then must\n"
	.string "have been shocked by the racket!\p"
	.string "Anyway, back to work for me!\n"
	.string "Let's chat again!$"

BuenaPhoneRadioTowerDirectorText:
	.string "Guess what?\n"
	.string "The RADIO TOWER's DIRECTOR is a big\l"
	.string "fan of TV!\p"
	.string "A while ago, a fashion show on TV\n"
	.string "said that black suits were in.\l"
	.string "Now all he wears are black suits.\l"
	.string "But it's a secret that our DIRECTOR\l"
	.string "is a TV fan, so if you see him,\l"
	.string "don't you dare mention it!\p"
	.string "Oh! The DIRECTOR will be here soon!\n"
	.string "Later! Tune into my show!$"

BuenaPhoneWhenDoYouRelaxText:
	.string "{PLAYER}, tell me.\n"
	.string "When do you relax the most?\l"
	.string "For me, it has to be in the studio\l"
	.string "right after my show, enjoying a\l"
	.string "nice cup of tea.\l"
	.string "It's so pleasant that it gradually\l"
	.string "makes me drowsy…\l"
	.string "… … …\l"
	.string "… … …Zzz\p"
	.string "Oops, I drifted off just thinking\n"
	.string "about it! How, uh… embarrassing!\l"
	.string "Please forget this happened! Later!$"

BuenaPhoneStarterPokemonText:
	.string "{PLAYER}, what was the first {POKEMON}\n"
	.string "you ever caught?\l"
	.string "…Oh, really?\l"
	.string "I've seen lots of {POKEMON} around,\l"
	.string "but I've never caught one.\p"
	.string "I should give it a try sometime.\p"
	.string "Did you know that the first {POKEMON}\n"
	.string "MARY caught was a DROWZEE?\l"
	.string "Isn't that so out of character?\l"
	.string "But MARY's DROWZEE kept making her\l"
	.string "fall asleep on the job, so she traded\l"
	.string "with a fan for a MEOWTH.\p"
	.string "Let's chat about {POKEMON} again!"
	.string "Bye-bye!$"

BuenaPhoneCompanyVacationText:
	.string "Guess what? All of us from\n"
	.string "the RADIO TOWER are going on\l"
	.string "a company vacation to the RADIO TOWER\l"
	.string "in LAVENDER.\p"
	.string "We're wasting our vacation on a trip\n"
	.string "to another RADIO TOWER?\p"
	.string "I'd much rather go to the beach!\n"
	.string "{PLAYER}, I hope you have enough fun\l"
	.string "fun for both of us on your journey!\l"
	.string "Bye-bye!$"

BuenaPhoneBenAndFernText:
	.string "Did you know…?\p"
	.string "BEN and FERN talk on the phone\n"
	.string "for hours about what {POKEMON} music\l"
	.string "should play on different days of the week.\p"
	.string "One time, FERN's rapping style\n"
	.string "kind of rubbed off on BEN weirdly.\p"
	.string "So we ended up enduring BEN's\n"
	.string "silly, chilly, a willy-nilly jive-\l"
	.string "talking shtick for a while.\l"
	.string "Let's chat again!$"

BuenaPhoneGoingShoppingText:
	.string "I'm going shopping with MARY and LILY soon.\p"
	.string "It'll be great if GOLDENROD DEPT.\n"
	.string "STORE has a sale on when we go…\l"
	.string "{PLAYER}, maybe we can hook up too!\l"
	.string "Catch you later!$"

BuenaPhoneFavoriteSlotMachineAnswerText:
	.string "I'm thinking of going\nto the GAME CORNER tomorrow.\l"
	.string "It's been a while.\l"
	.string "You see, I have my favorite machine…\l"
	.string "It pays out a lot, I kid you not!\l"
	.string "Huh? Nuh-uh, it's my secret!\l"
	.string "You have to find it yourself!\l"
	.string "Catch you later!$"

BuenaPhonePokegearAnswerText:
	.string "Hey, {PLAYER}. You use your {POKE}GEAR\n"
	.string "to listen to the radio, right?\l"
	.string "I heard that you can even display\l"
	.string "town maps with {POKE}GEAR.\p"
	.string "I have a bad sense of direction,\n"
	.string "so {POKE}GEAR would be handy…\p"
	.string "Anyway, thanks for calling! Later!$"

BuenaPhoneCoopedUpInRadioTowerAnswerText:
	.string "Is it sunny outside today?\n"
	.string "When you're cooped up in the\l"
	.string "RADIO TOWER as much as I am,\l"
	.string "you lose touch with the outside.\l"
	.string "It can be boring.\l"
	.string "Please call again!$"

PhoneScript_Kenji::
	phone_callnativecontext isPlayerBeingCalled
	phone_compare VAR_RESULT, 0
	phone_goto_if_eq PhoneScript_Kenji_Answer
	phone_compare VAR_RESULT, 1
	phone_goto_if_eq PhoneScript_Kenji_Calling_Greet

PhoneScript_Kenji_Call::
	phone_gettime
	phone_compare VAR_0x8000, 12
	phone_call_if_ge PhoneScript_Kenji_Check_For_Break
	phone_compare VAR_0x8002, TIME_MORNING
	phone_call_if_eq PhoneScript_Kenji_Call_Morning
	phone_compare VAR_0x8002, TIME_DAY
	phone_call_if_ge PhoneScript_Kenji_Another_Time
	phone_compare VAR_0x8002, TIME_NIGHT
	phone_call_if_eq PhoneScript_Kenji_Call_Night
	phone_message Matchcall_Kenji_Hangup
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Kenji_Check_For_Break:
	phone_gettime
	phone_compare VAR_0x8000, 13
	phone_goto_if_lt PhoneScript_Kenji_On_Break
	phone_return

PhoneScript_Kenji_Another_Time:
	phone_message Matchcall_Kenji_Another_Time
	phone_return

PhoneScript_Kenji_On_Break:
	phone_setflag FLAG_CALL_KENJI_GIFT
	phone_message Matchcall_Kenji_Gift
	phone_message Matchcall_Kenji_Hangup
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Kenji_Call_Morning:
	phone_message Matchcall_Kenji_Call_Morning
	phone_return

PhoneScript_Kenji_Call_Night:
	phone_message Matchcall_Kenji_Call_Night
	phone_return

PhoneScript_Kenji_Answer:
	phone_initcall
	phone_end_if_not_available
	phone_gettime
	phone_compare VAR_0x8002, TIME_MORNING
	phone_call_if_eq PhoneScript_Kenji_Morning_Answer
	phone_compare VAR_0x8002, TIME_DAY
	phone_call_if_eq PhoneScript_Kenji_Day_Answer
	phone_compare VAR_0x8002, TIME_NIGHT
	phone_call_if_eq PhoneScript_Kenji_Night_Answer
	phone_goto PhoneScript_Kenji_Call

PhoneScript_Kenji_Morning_Answer:
	phone_message Matchcall_Kenji_Answer_Morn
	phone_return

PhoneScript_Kenji_Day_Answer:
	phone_message Matchcall_Kenji_Answer_Day
	phone_return

PhoneScript_Kenji_Night_Answer:
	phone_message Matchcall_Kenji_Answer_Night
	phone_return

PhoneScript_Kenji_Calling_Greet:
	phone_initcall
	phone_end_if_not_available
	phone_message Matchcall_Kenji_Call
	phone_goto PhoneScript_Kenji_Caller

PhoneScript_Kenji_Caller:
	phone_message Matchcall_Kenji_Generic
	phone_message Matchcall_Kenji_Hangup
	phone_waitbuttonpress
	phone_hangup
	phone_end

Matchcall_Kenji_Answer_Morn::
	.string "KENJI here…\n"

	.string "{PLAYER}!\l"
	.string "Beautiful morning, hey?\p$"


Matchcall_Kenji_Answer_Day::
	.string "KENJI here…\n"


	.string "{PLAYER}!\l"
	.string "Beautiful weather, hey?\p$"


Matchcall_Kenji_Answer_Night::
	.string "KENJI here…\n"


	.string "{PLAYER}!\l"
	.string "Beautiful moonlight, hey?\p$"


Matchcall_Kenji_Call::
	.string  "Hey, {PLAYER}!\n"
	.string "This is KENJI!\p$"


Matchcall_Kenji_Hangup::
	.string  "Anyway, we'll chat again!$"


Matchcall_Kenji_Generic::
	.string  "Are you still on your journey?\n"

	.string "I remain dedicated to my training.\l"

	.string "Oooooaaarrrgh!\p$"


Matchcall_Kenji_Another_Time::
	.string  "I'm in training now.\n"

	.string "I apologize, but call me back\l"
	.string "another time.\l"

	.string "Oooooaaarrrgh!\p$"


Matchcall_Kenji_Chat_Tomorrow::
	.string  "I apologize, but I don't have time\n"

	.string "to chat while I am in training!\l"

	.string "I'll have time to chat tomorrow!\l"

	.string "Yiiihah!\p$"


Matchcall_Kenji_Call_Morning::
	.string  "I plan to take a lunch break,\n"
	.string "so come see me then!\l"
	.string "Ayiiiyah!\p$"


Matchcall_Kenji_Gift::
	.string  "I'm taking a break on ROUTE 45!\n"

	.string "Why not drop by if you are free?\p$"


Matchcall_Kenji_Call_Night::
	.string  "I rested up over my lunch break.\n"

	.string "Now it's time to resume training!\l"

	.string "Oooryaah!\p$"


PhoneScript_Irwin::
	phone_callnativecontext isPlayerBeingCalled
	phone_compare VAR_RESULT, 0
	phone_goto_if_eq PhoneScript_Irwin_Call
	phone_compare VAR_RESULT, 1
	phone_goto_if_eq PhoneScript_Irwin_Caller

PhoneScript_Irwin_Call:
	phone_initcall
	phone_end_if_not_available
	phone_gettime
	phone_compare VAR_0x8002, TIME_MORNING
	phone_call_if_eq PhoneScript_Irwin_Answer_Morn
	phone_compare VAR_0x8002, TIME_DAY
	phone_call_if_eq PhoneScript_Irwin_Answer_Day
	phone_compare VAR_0x8002, TIME_NIGHT
	phone_call_if_eq PhoneScript_Irwin_Answer_Night
	phone_call_if_set FLAG_ROCKETS_IN_RADIO_TOWER, PhoneScript_Irwin_Rocket_Takeover
	phone_call PhoneScript_Irwin_Random
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Irwin_Random:
	phone_random 3
	phone_compare VAR_RESULT, 0
	phone_call_if_eq PhoneScript_Irwin_So_Much_To_Chat_About
	phone_compare VAR_RESULT, 1
	phone_call_if_eq PhoneScript_Irwin_Escapades
	phone_compare VAR_RESULT, 2
	phone_call_if_eq PhoneScript_Irwin_Good_Match
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Hangup:
	phone_message Matchcall_Irwin_Hangup
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Irwin_Rocket_Takeover:
	phone_message Matchcall_Irwin_Rocket_Takeover
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_So_Much_To_Chat_About:
	phone_message Matchcall_Irwin_So_Much_To_Chat_About
	phone_return

PhoneScript_Irwin_Escapades:
	phone_message Matchcall_Irwin_Escapades
	phone_return

PhoneScript_Irwin_Good_Match:
	phone_message Matchcall_Irwin_Good_Match
	phone_return

PhoneScript_Irwin_Right_Away::
	phone_stdcall Matchcall_Irwin_Called_Right_Away
	phone_end

PhoneScript_Irwin_Caller:
	phone_initcall
	phone_end_if_not_available
	phone_gettime
	phone_compare VAR_0x8002, TIME_MORNING
	phone_call_if_eq PhoneScript_Irwin_Call_Morn
	phone_compare VAR_0x8002, TIME_DAY
	phone_call_if_eq PhoneScript_Irwin_Call_Day
	phone_compare VAR_0x8002, TIME_NIGHT
	phone_call_if_eq PhoneScript_Irwin_Call_Night
	phone_call_if_set FLAG_OPENED_MT_SILVER, PhoneScript_Irwin_Mt_Silver
	phone_call_if_set FLAG_FOUGHT_SNORLAX, PhoneScript_Irwin_Snorlax
	phone_call_if_set FLAG_RETURNED_MACHINE_PART, PhoneScript_Irwin_Magnet_Train
	phone_call_if_set FLAG_BADGE14_GET, PhoneScript_Irwin_Marsh_Badge
	phone_call_if_set FLAG_IS_CHAMPION, PhoneScript_Irwin_Elite_Four
	phone_call_if_set FLAG_BADGE08_GET, PhoneScript_Irwin_Rising_Badge
	phone_call_if_set FLAG_CLEARED_RADIO_TOWER, PhoneScript_Irwin_Radio_Tower
	phone_call_if_set FLAG_CLEARED_ROCKET_HIDEOUT, PhoneScript_Irwin_Rocket_Hideout
	phone_call_if_set FLAG_CURED_AMPHY, PhoneScript_Irwin_Jasmine_Returned
	phone_call_if_set FLAG_BADGE04_GET, PhoneScript_Irwin_Fog_Badge
	phone_call_if_set FLAG_BADGE03_GET, PhoneScript_Irwin_Plain_Badge
	phone_call PhoneScript_Irwin_Random
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Irwin_Called_Right_Away:
	phone_message Matchcall_Irwin_Called_Right_Away
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Plain_Badge:
	phone_message Matchcall_Irwin_Plain_Badge
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Fog_Badge:
	phone_message Matchcall_Irwin_Fog_Badge
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Jasmine_Returned:
	phone_message Matchcall_Irwin_Jasmine_Returned
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Rocket_Hideout:
	phone_message Matchcall_Irwin_Rocket_Hideout
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Radio_Tower:
	phone_message Matchcall_Irwin_Radio_Tower
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Rising_Badge:
	phone_message Matchcall_Irwin_Rising_Badge
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Elite_Four:
	phone_message Matchcall_Irwin_Elite_Four
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Marsh_Badge:
	phone_message Matchcall_Irwin_Marsh_Badge
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Magnet_Train:
	phone_message Matchcall_Irwin_Magnet_Train
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Snorlax:
	phone_message Matchcall_Irwin_Snorlax
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Mt_Silver:
	phone_message Matchcall_Irwin_Mt_Silver
	phone_call PhoneScript_Irwin_Hangup

PhoneScript_Irwin_Answer_Morn:
	phone_message Matchcall_Irwin_Answer_Morn
	phone_return

PhoneScript_Irwin_Answer_Day:
	phone_message Matchcall_Irwin_Answer_Day
	phone_return

PhoneScript_Irwin_Answer_Night:
	phone_message Matchcall_Irwin_Answer_Night
	phone_return

PhoneScript_Irwin_Call_Morn:
	phone_message Matchcall_Irwin_Call_Morn
	phone_return

PhoneScript_Irwin_Call_Day:
	phone_message Matchcall_Irwin_Call_Day
	phone_return

PhoneScript_Irwin_Call_Night:
	phone_message Matchcall_Irwin_Call_Night
	phone_return

Matchcall_Irwin_Answer_Morn::
	.string  "Hello? IRWIN here…\n"

	.string "Hey, {PLAYER}!\p$"


Matchcall_Irwin_Answer_Day::
	.string  "Hello? IRWIN here…\n"

	.string "Wow, {PLAYER}!\p$"


Matchcall_Irwin_Answer_Night::
	.string  "Hello? IRWIN here…\n"

	.string "Yippee, {PLAYER}!\p$"


Matchcall_Irwin_Call_Morn::
	.string  "Uh, hello. {PLAYER}?\n"

	.string "It's your pal, IRWIN!\p$"


Matchcall_Irwin_Call_Day::
	.string  "Uh, hello. {PLAYER}?\n"

	.string "It's your buddy IRWIN!\p$"


Matchcall_Irwin_Call_Night::
	.string  "Uh, hello. {PLAYER}?\n"

	.string "It's your sidekick IRWIN!\p$"


Matchcall_Irwin_Hangup::
	.string  "I hate having to hang up on you!\n"

	.string "Call you later!$"


Matchcall_Irwin_Rocket_Takeover::
	.string  "{PLAYER}, have you heard?\n"

	.string "GOLDENROD's RADIO TOWER has been\l"

	.string "taken over by TEAM ROCKET!\l"

	.string "…Um… What's TEAM ROCKET?\p$"


Matchcall_Irwin_Plain_Badge::
	.string  "{PLAYER}, I heard!\n"

	.string "You defeated that WHITNEY?\l"

	.string "It makes me proud to be your friend!\p$"


Matchcall_Irwin_Jasmine_Returned::
	.string  "Hey, I heard about you!\n"

	.string "You saved that {POKEMON} at the\l"

	.string "LIGHTHOUSE, didn't you?\l"

	.string "{PLAYER}, I wish you'd come see me\l"

	.string "when I'm sick in bed with a cold!\p$"


Matchcall_Irwin_Rocket_Hideout::
	.string  "I heard, I heard, I heard!\n"

	.string "You smashed TEAM ROCKET's hideout!\l"

	.string "You're like a movie hero, even!\l"

	.string "But um… What was TEAM ROCKET?\p$"


Matchcall_Irwin_Radio_Tower::
	.string  "I heard, I heard, I heard!\n"

	.string "About your heroic liberation of the\l"

	.string "RADIO TOWER!\l"
	.string "You rock so hard!\p$"


Matchcall_Irwin_Rising_Badge::
	.string  "I saw, I saw!\n"

	.string "I saw you go into the DRAGON'S DEN!\l"

	.string "I'm certain you passed!\l"
	.string "Aww, no need to be modest!\l"
	.string "You can't fail!\p$"


Matchcall_Irwin_Elite_Four::
	.string  "Yesterday, I went out to NEW BARK TOWN.\n"

	.string " There was a lady who looked a lot like you, {PLAYER}.\p"

	.string "What? That lady was your mom?\n"

	.string "Aww, I should've introduced myself!\l"

	.string "I bet your mom's really proud of all that you've\l"
	.string "accomplished.\p"

	.string "Heh, put it this way. I'd be proud if I were your\n"
	.string "mom, believe me!\p$"


Matchcall_Irwin_Vermillion::
	.string  "I saw, I saw, I saw!\n"

	.string "You striding onto a ship, {PLAYER}!\l"

	.string "I can't get over how good you look\l"

	.string "with the sea as your backdrop!\p$"


Matchcall_Irwin_Magnet_Train::
	.string  "I heard, I heard!\n"

	.string "You got a MAGNET TRAIN PASS!\l"

	.string "When I saw you departing on the ship, I felt sad\l"
	.string "that I wouldn't be able to see you for a while.\l"

	.string "But since you have that PASS, you can zip back anytime!\l"
	.string "That's reassuring!\l"

	.string "What? You can FLY back anytime?\l"

	.string "What do you mean by FLY?\p$"


Matchcall_Irwin_Snorlax::
	.string  "I saw, I saw!\n"

	.string "You waking up SNORLAX!\l"

	.string "I was watching you from afar, so I couldn't tell what\l"
	.string "you did exactly.\l"

	.string "Did you play a flute to wake it?\l"

	.string "Wow! That's like magic!\p$"


Matchcall_Irwin_Mt_Silver::
	.string  "I hear rumors about you all over the place.\n"

	.string "It just makes me sigh, {PLAYER}.\l"

	.string "How did you get so strong?\l"

	.string "Go for the world championship now!\l"

	.string "I'll always be cheering you on!\p$"


Matchcall_Irwin_Called_Right_Away::
	.string  "Hehe, I called right away!\n"

	.string "I think we can be good friends!$"


Matchcall_Irwin_Fog_Badge::
	.string  "I saw, I heard!\n"

	.string "You beat MORTY of ECRUTEAK GYM!\l"

	.string "Th-that's just incredible!\l"

	.string "I actually went to the GYM's entrance\l"

	.string "to cheer you on.\l"
	.string "Did you know that?\l"

	.string "But everyone was floating,\l"

	.string "and there were ghosts all over!\l"

	.string "So I chickened out and took off for home…\p$"


Matchcall_Irwin_Marsh_Badge::
	.string  "{PLAYER}, I heard!\n"

	.string "You're kicking up a mighty ruckus\l"

	.string "over in KANTO!\l"
	.string "What a glorious rampage it must be!\l"

	.string "You so rock!\p$"


Matchcall_Irwin_Escapades::
	.string  "Hearing about your escapades\n"
	.string "rocks my soul!\l"
	.string "It sure does!\p$"


Matchcall_Irwin_Good_Match::
	.string  "I'm so glad you called!\n"

	.string "I was just about to call you too!\l"

	.string "I guess we must be a good match!\p$"


Matchcall_Irwin_So_Much_To_Chat_About::
	.string  "How are you?\n"

	.string "What are you doing?\l"

	.string "Where are you?\l"

	.string "How many BADGES do you have now?\l"

	.string "How much money have you saved?\l"

	.string "How's your mom?\l"

	.string "Have you got lots of {POKEMON}?\l"

	.string "Is it going to be sunny tomorrow?\p"

	.string "Arrgh, there's so much I want to\n"

	.string "chat about!\l"
	.string "This is going nowhere!\p$"


PhoneScript_Wade_BugCatching_Contest::
	phone_stdcall Matchcall_Wade_BugCatching_Contest
	phone_end

PhoneScript_Derek_BugCatching_Contest::
	phone_stdcall Matchcall_Derek_Bug_Catching_Contest
	phone_end

Matchcall_Wade_BugCatching_Contest::
	.string  "The Bug-Catching Contest is at the\n"

	.string "NATIONAL PARK today.\l"

	.string "Are you going, {PLAYER}?\l"

	.string "I'm trying to make up my mind.$"

Matchcall_Derek_Bug_Catching_Contest::
	.string  "Did you remember?\n"
	.string "The Bug-Catching Contest is today.\l"

	.string "You're going to go, aren't you?\p"

	.string "I think I'll participate with\n"

	.string "PIKACHU to show off its cuteness.$"

PhoneScript_Todd_Goldenrod_Dept_Sale::
	phone_stdcall Matchcall_Todd_Goldenrod_Dept_Sale
	phone_setflag FLAG_DAILY_GOLDENROD_DEPT_STORE_SALE_HAPPENING
	phone_end

Matchcall_Todd_Goldenrod_Dept_Sale::
	.string "This is it--the one\n"
	.string "we've all been waiting for!\p"

	.string "GOLDENROD DEPT. STORE's bargain sale\n"
	.string "is on now!\l"

	.string "Want it cheap?\l"
	.string "Want it lots?\l"

	.string "Don't miss this GOLDENROD chance!\l"

	.string "Huh? I sound like a huckster?\l"

	.string "Well, yeah. I was mimicking them…\p"

	.string "Anyway, you've got to get there\n"
	.string	"as soon as you can!$"

PhoneScript_Gina::
	phone_goto_if_set FLAG_ROCKETS_IN_RADIO_TOWER, PhoneScript_Gina_Rocket_Tower
	phone_goto PhoneScript_StandardMatchCallTrainer

PhoneScript_Todd::
	phone_goto_if_set FLAG_DAILY_GOLDENROD_DEPT_STORE_SALE_HAPPENING, PhoneScript_Gina_Rocket_Tower
	phone_goto PhoneScript_StandardMatchCallTrainer

PhoneScript_Todd_Remind_Sale:
	phone_stdcall Matchcall_Todd_Remind_Goldenrod_Dept_Sale
	phone_end

Matchcall_Todd_Remind_Goldenrod_Dept_Sale::
	.string "Haven't you gone to GOLDENROD\n"
	.string "DEPT. STORE?\l"
	.string "I've scoped it out already!\l"

	.string "They had some real bargains.\l"

	.string "You should get there quickly.$"

PhoneScript_Gina_Rocket_Tower:
	phone_stdcall Matchcall_Gina_Rocket_Tower
	phone_end

Matchcall_Gina_Rocket_Tower::
	.string  "Have you heard about TEAM ROCKET?\n"

	.string "They've taken over the RADIO TOWER\l"
	.string "in GOLDENROD.\l"

	.string "Are the people inside safe?$"
