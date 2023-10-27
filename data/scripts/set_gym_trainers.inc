Common_EventScript_SetGymTrainers::
	switch VAR_0x8008
	case 1, VioletCity_Gym_SetGymTrainers
	case 2, AzaleaTown_Gym_SetGymTrainers
	case 3, GoldenrodCity_Gym_SetGymTrainers
	case 4, EcruteakCity_Gym_SetGymTrainers
	case 5, CianwoodCity_Gym_SetGymTrainers
	case 6, OlivineCity_Gym_SetGymTrainers
	case 7, MahoganyTown_Gym_SetGymTrainers
	case 8, BlackthornCity_Gym_SetGymTrainers
	case 9, PewterCity_Gym_SetGymTrainers
	case 10, CeruleanCity_Gym_SetGymTrainers
	case 11, VermilionCity_Gym_SetGymTrainers
	case 12, CeladonCity_Gym_SetGymTrainers
	case 13, FuchsiaCity_Gym_SetGymTrainers
	case 14, SaffronCity_Gym_SetGymTrainers
	case 15, SeafoamIslands_Gym_SetGymTrainers
	case 16, ViridianCity_Gym_SetGymTrainers
	end

VioletCity_Gym_SetGymTrainers:: @ 8271FA1
	settrainerflag TRAINER_ABE
	settrainerflag TRAINER_ROD
	return

AzaleaTown_Gym_SetGymTrainers:: @ 8271FAB
	settrainerflag TRAINER_BENNY
	settrainerflag TRAINER_AL
	settrainerflag TRAINER_JOSH
	settrainerflag TRAINER_AMY_AND_MAY
	return

GoldenrodCity_Gym_SetGymTrainers:: @ 8271FBE
	settrainerflag TRAINER_CARRIE
	settrainerflag TRAINER_BRIDGET
	settrainerflag TRAINER_VICTORIA
	settrainerflag TRAINER_SAMANTHA
	return

EcruteakCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_PING
	settrainerflag TRAINER_GRACE
	settrainerflag TRAINER_JEFFREY
	settrainerflag TRAINER_MARTHA
	return

CianwoodCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_YOSHI
	settrainerflag TRAINER_LAO
	settrainerflag TRAINER_NOB
	settrainerflag TRAINER_LUNG
	return

MahoganyTown_Gym_SetGymTrainers::
	settrainerflag TRAINER_ROXANNE
	settrainerflag TRAINER_RONALD
	settrainerflag TRAINER_CLARISSA
	settrainerflag TRAINER_BRAD
	settrainerflag TRAINER_DOUGLAS
	return

BlackthornCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_PAUL
	settrainerflag TRAINER_FRAN
	settrainerflag TRAINER_CODY
	settrainerflag TRAINER_MIKE
	settrainerflag TRAINER_LOLA
	return

PewterCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_JERRY
	return

CeruleanCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_PARKER
	settrainerflag TRAINER_BRIANA
	settrainerflag TRAINER_DIANA
	return
	
VermilionCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_HORTON
	settrainerflag TRAINER_VINCENT
	settrainerflag TRAINER_GREGORY
	return
	
CeladonCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_JO_AND_ZOE
	settrainerflag TRAINER_TANYA
	settrainerflag TRAINER_MICHELLE
	settrainerflag TRAINER_JULIA
	return
	
FuchsiaCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_LINDA
	settrainerflag TRAINER_CINDY
	settrainerflag TRAINER_BARRY
	settrainerflag TRAINER_ALICE
	return
	
SaffronCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_REBECCA
	settrainerflag TRAINER_JARED
	settrainerflag TRAINER_DORIS
	settrainerflag TRAINER_FRANKLIN
	return

OlivineCity_Gym_SetGymTrainers::	
SeafoamIslands_Gym_SetGymTrainers::
ViridianCity_Gym_SetGymTrainers::
	return

Common_EventScript_ActivateSixthBadgeRockets::
	clearflag(FLAG_HIDE_GOLDENROD_CITY_ROCKET_TAKEOVER)
	callnative CountBadges
	compare VAR_RESULT, 7
	goto_if_eq Common_EventScript_ActivateRadioTowerTakeover
	return

Common_EventScript_ActivateRadioTowerTakeover::
	clearflag(FLAG_HIDE_RADIO_TOWER_ROCKET_TAKEOVER)
	setflag(FLAG_HIDE_GOLDENROD_CITY_CIVILIANS)
	setflag(FLAG_ROCKETS_IN_RADIO_TOWER)
	setflag(FLAG_FORCED_CALL_RADIO_TOWER_TAKEOVER)
	return
