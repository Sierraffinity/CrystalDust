const struct Trainer gTrainers[] = {
    [TRAINER_NONE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = 0,
        .party = {.NoItemDefaultMoves = NULL},
    },

    [TRAINER_JOEY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joey1),
        .party = {.NoItemDefaultMoves = sParty_Joey1 }
    },

    [TRAINER_MIKEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("MIKEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Mikey),
        .party = {.NoItemDefaultMoves = sParty_Mikey }
    },

    [TRAINER_DON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Don),
        .party = {.NoItemDefaultMoves = sParty_Don }
    },

    [TRAINER_WADE_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wade1),
        .party = {.NoItemDefaultMoves = sParty_Wade1},
    },

    [TRAINER_CHOW] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("CHOW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chow),
        .party = {.NoItemDefaultMoves = sParty_Chow},
    },

    [TRAINER_NICO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("NICO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nico),
        .party = {.NoItemDefaultMoves = sParty_Nico},
    },

    [TRAINER_EDMOND] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("EDMOND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edmond),
        .party = {.NoItemDefaultMoves = sParty_Edmond},
    },

    [TRAINER_JIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("JIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jin),
        .party = {.NoItemDefaultMoves = sParty_Jin},
    },

    [TRAINER_TROY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("TROY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Troy),
        .party = {.NoItemDefaultMoves = sParty_Troy},
    },

    [TRAINER_NEAL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("NEAL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Neal),
        .party = {.NoItemDefaultMoves = sParty_Neal},
    },

    [TRAINER_LI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("LI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Li),
        .party = {.NoItemDefaultMoves = sParty_Li},
    },

    [TRAINER_ABE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ABE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Abe),
        .party = {.NoItemDefaultMoves = sParty_Abe},
    },

    [TRAINER_ROD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rod),
        .party = {.NoItemDefaultMoves = sParty_Rod},
    },

    [TRAINER_ALBERT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("ALBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Albert),
        .party = {.NoItemDefaultMoves = sParty_Albert},
    },

    [TRAINER_LIZ_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Liz),
        .party = {.NoItemDefaultMoves = sParty_Liz},
    },

    [TRAINER_ROLAND] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ROLAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Roland),
        .party = {.NoItemDefaultMoves = sParty_Roland},
    },

    [TRAINER_HENRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("HENRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Henry),
        .party = {.NoItemDefaultMoves = sParty_Henry},
    },

    [TRAINER_JUSTIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("JUSTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Justin),
        .party = {.NoItemDefaultMoves = sParty_Justin},
    },

    [TRAINER_RALPH_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ralph),
        .party = {.NoItemDefaultMoves = sParty_Ralph},
    },

    [TRAINER_GORDON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("GORDON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gordon),
        .party = {.NoItemDefaultMoves = sParty_Gordon},
    },

    [TRAINER_PETER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PETER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Peter),
        .party = {.NoItemDefaultMoves = sParty_Peter},
    },

    [TRAINER_DANIEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DANIEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Daniel),
        .party = {.NoItemDefaultMoves = sParty_Daniel},
    },

    [TRAINER_LARRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("LARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Larry),
        .party = {.NoItemDefaultMoves = sParty_Larry},
    },

    [TRAINER_RUSSELL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("RUSSELL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Russell),
        .party = {.NoItemDefaultMoves = sParty_Russell},
    },

    [TRAINER_RAY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("RAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ray),
        .party = {.NoItemDefaultMoves = sParty_Ray},
    },

    [TRAINER_BILL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("BILL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bill),
        .party = {.NoItemDefaultMoves = sParty_Bill},
    },

    [TRAINER_PHILLIP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PHILLIP"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Phillip),
        .party = {.NoItemDefaultMoves = sParty_Phillip},
    },

    [TRAINER_LEONARD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LEONARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Leonard),
        .party = {.NoItemDefaultMoves = sParty_Leonard},
    },

    [TRAINER_ANDREW] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ANDREW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andrew),
        .party = {.NoItemDefaultMoves = sParty_Andrew},
    },

    [TRAINER_CALVIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Calvin),
        .party = {.NoItemDefaultMoves = sParty_Calvin},
    },

    [TRAINER_NICK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("NICK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Nick),
        .party = {.NoItemCustomMoves = sParty_Nick},
    },

    [TRAINER_GWEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("GWEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gwen),
        .party = {.NoItemDefaultMoves = sParty_Gwen},
    },

    [TRAINER_EMMA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("EMMA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Emma),
        .party = {.NoItemDefaultMoves = sParty_Emma},
    },

    [TRAINER_ANTHONY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Anthony),
        .party = {.NoItemDefaultMoves = sParty_Anthony},
    },

    [TRAINER_WAYNE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WAYNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wayne),
        .party = {.NoItemDefaultMoves = sParty_Wayne},
    },

    [TRAINER_ROCKET_SLOWPOKE_WELL_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketSlowpokeWell1),
        .party = {.NoItemDefaultMoves = sParty_RocketSlowpokeWell1},
    },

    [TRAINER_ROCKET_SLOWPOKE_WELL_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketSlowpokeWell2),
        .party = {.NoItemDefaultMoves = sParty_RocketSlowpokeWell2},
    },

    [TRAINER_ROCKET_SLOWPOKE_WELL_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketSlowpokeWell3),
        .party = {.NoItemDefaultMoves = sParty_RocketSlowpokeWell3},
    },

    [TRAINER_AMY_AND_MAY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & MAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AmyAndMay),
        .party = {.NoItemDefaultMoves = sParty_AmyAndMay},
    },

    [TRAINER_BENNY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("BENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Benny),
        .party = {.NoItemDefaultMoves = sParty_Benny},
    },

    [TRAINER_AL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("AL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Al),
        .party = {.NoItemDefaultMoves = sParty_Al},
    },

    [TRAINER_JOSH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JOSH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Josh),
        .party = {.NoItemDefaultMoves = sParty_Josh},
    },

    [TRAINER_TODD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Todd),
        .party = {.NoItemDefaultMoves = sParty_Todd},
    },

    [TRAINER_SAMUEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("SAMUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Samuel),
        .party = {.NoItemDefaultMoves = sParty_Samuel},
    },

    [TRAINER_IAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("IAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ian),
        .party = {.NoItemDefaultMoves = sParty_Ian},
    },

    [TRAINER_GINA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gina),
        .party = {.NoItemDefaultMoves = sParty_Gina},
    },

    [TRAINER_KEITH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_OFFICER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_OFFICER,
        .trainerName = _("KEITH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Keith),
        .party = {.NoItemDefaultMoves = sParty_Keith},
    },

    [TRAINER_BRANDON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("BRANDON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brandon),
        .party = {.ItemDefaultMoves = sParty_Brandon},
    },

    [TRAINER_IRENE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("IRENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Irene),
        .party = {.NoItemDefaultMoves = sParty_Irene},
    },

    [TRAINER_JENN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JENN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jenn),
        .party = {.NoItemDefaultMoves = sParty_Jenn},
    },

    [TRAINER_KATE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("KATE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kate),
        .party = {.NoItemDefaultMoves = sParty_Kate},
    },

    [TRAINER_CARRIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("CARRIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Carrie),
        .party = {.NoItemCustomMoves = sParty_Carrie},
    },

    [TRAINER_BRIDGET] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("BRIDGET"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bridget),
        .party = {.NoItemDefaultMoves = sParty_Bridget},
    },

    [TRAINER_VICTORIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("VICTORIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Victoria),
        .party = {.NoItemDefaultMoves = sParty_Victoria},
    },

    [TRAINER_SAMANTHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SAMANTHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Samantha),
        .party = {.NoItemCustomMoves = sParty_Samantha},
    },

    [TRAINER_ERIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("ERIC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Eric),
        .party = {.NoItemDefaultMoves = sParty_Eric},
    },

    [TRAINER_TERU] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("TERU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Teru),
        .party = {.NoItemDefaultMoves = sParty_Teru},
    },

    [TRAINER_ISAAC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaac),
        .party = {.NoItemCustomMoves = sParty_Isaac},
    },

    [TRAINER_DONALD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("DONALD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Donald),
        .party = {.NoItemDefaultMoves = sParty_Donald},
    },

    [TRAINER_IVAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("IVAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ivan),
        .party = {.NoItemDefaultMoves = sParty_Ivan},
    },

    [TRAINER_ELLIOT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Elliot),
        .party = {.NoItemDefaultMoves = sParty_Elliot},
    },

    [TRAINER_BROOKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("BROOKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brooke),
        .party = {.NoItemCustomMoves = sParty_Brooke},
    },

    [TRAINER_KIM] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("KIM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kim),
        .party = {.NoItemDefaultMoves = sParty_Kim},
    },

    [TRAINER_BRYAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BRYAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bryan),
        .party = {.NoItemDefaultMoves = sParty_Bryan},
    },

    [TRAINER_WALT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("WALT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Walt),
        .party = {.NoItemDefaultMoves = sParty_Walt},
    },

    [TRAINER_ARNIE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Arnie),
        .party = {.NoItemDefaultMoves = sParty_Arnie},
    },

    [TRAINER_IRWIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("IRWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Irwin),
        .party = {.NoItemDefaultMoves = sParty_Irwin},
    },

    [TRAINER_DIRK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_OFFICER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_OFFICER,
        .trainerName = _("DIRK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dirk),
        .party = {.NoItemDefaultMoves = sParty_Dirk},
    },

    [TRAINER_JACK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jack),
        .party = {.NoItemDefaultMoves = sParty_Jack},
    },

    [TRAINER_BEVERLY] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BEVERLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Beverly),
        .party = {.ItemDefaultMoves = sParty_Beverly},
    },

    [TRAINER_WILLIAM] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("WILLIAM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_William),
        .party = {.ItemDefaultMoves = sParty_William},
    },

    [TRAINER_KRISE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("KRISE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Krise),
        .party = {.NoItemDefaultMoves = sParty_Krise},
    },

    [TRAINER_MARK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("MARK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Mark),
        .party = {.NoItemCustomMoves = sParty_Mark},
    },

    [TRAINER_ALAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alan),
        .party = {.NoItemDefaultMoves = sParty_Alan},
    },

    [TRAINER_ANN_AND_ANNE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("ANN & ANNE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AnnAndAnne),
        .party = {.NoItemCustomMoves = sParty_AnnAndAnne},
    },

    [TRAINER_GREG] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("GREG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Greg),
        .party = {.NoItemCustomMoves = sParty_Greg},
    },

    [TRAINER_NAOKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KIMONO_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_KIMONO,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("NAOKO"),
        .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Naoko),
        .party = {.NoItemDefaultMoves = sParty_Naoko},
    },

    [TRAINER_SAYO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KIMONO_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_KIMONO,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("SAYO"),
        .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sayo),
        .party = {.NoItemDefaultMoves = sParty_Sayo},
    },

    [TRAINER_ZUKI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KIMONO_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_KIMONO,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("ZUKI"),
        .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Zuki),
        .party = {.NoItemDefaultMoves = sParty_Zuki},
    },

    [TRAINER_KUNI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KIMONO_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_KIMONO,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("KUNI"),
        .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kuni),
        .party = {.NoItemDefaultMoves = sParty_Kuni},
    },

    [TRAINER_MIKI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KIMONO_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_KIMONO,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MIKI"),
        .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Miki),
        .party = {.NoItemDefaultMoves = sParty_Miki},
    },

    [TRAINER_GAKU] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("GAKU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Gaku),
        .party = {.NoItemDefaultMoves = sParty_Gaku},
    },

    [TRAINER_MASA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("MASA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Masa),
        .party = {.NoItemDefaultMoves = sParty_Masa},
    },

    [TRAINER_KOJI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Koji),
        .party = {.NoItemDefaultMoves = sParty_Koji},
    },

    [TRAINER_NED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("NED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ned),
        .party = {.NoItemDefaultMoves = sParty_Ned},
    },

    [TRAINER_DICK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("DICK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dick),
        .party = {.NoItemDefaultMoves = sParty_Dick},
    },

    [TRAINER_PING] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("PING"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Ping),
        .party = {.NoItemDefaultMoves = sParty_Ping},
    },

    [TRAINER_GRACE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MEDIUM,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("MARY"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Grace),
        .party = {.NoItemDefaultMoves = sParty_Grace},
    },

    [TRAINER_JEFFREY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jeffrey),
        .party = {.NoItemDefaultMoves = sParty_Jeffrey},
    },

    [TRAINER_MARTHA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MEDIUM,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JODY"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Martha),
        .party = {.NoItemDefaultMoves = sParty_Martha},
    },

    [TRAINER_HARRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Harry),
        .party = {.NoItemDefaultMoves = sParty_Harry},
    },

    [TRAINER_DANA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dana),
        .party = {.NoItemCustomMoves = sParty_Dana},
    },

    [TRAINER_VALERIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("VALERIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Valerie),
        .party = {.NoItemCustomMoves = sParty_Valerie},
    },

    [TRAINER_TOBY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("TOBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Toby),
        .party = {.NoItemDefaultMoves = sParty_Toby},
    },

    [TRAINER_CHAD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chad),
        .party = {.NoItemDefaultMoves = sParty_Chad},
    },

    [TRAINER_OLIVIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("OLIVIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Olivia),
        .party = {.NoItemDefaultMoves = sParty_Olivia},
    },

    [TRAINER_NORMAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("NORMAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Norman),
        .party = {.NoItemCustomMoves = sParty_Norman},
    },

    [TRAINER_DEREK] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("DEREK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Derek),
        .party = {.ItemDefaultMoves = sParty_Derek},
    },

    [TRAINER_RUTH] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("RUTH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ruth),
        .party = {.ItemDefaultMoves = sParty_Ruth},
    },

    [TRAINER_EUGENE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("EUGENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Eugene),
        .party = {.NoItemDefaultMoves = sParty_Eugene},
    },

    [TRAINER_JAIME] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("JAIME"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jaime),
        .party = {.ItemDefaultMoves = sParty_Jaime},
    },

    [TRAINER_ALFRED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("ALFRED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alfred),
        .party = {.NoItemDefaultMoves = sParty_Alfred},
    },

    [TRAINER_HUEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Huey),
        .party = {.NoItemDefaultMoves = sParty_Huey},
    },

    [TRAINER_THEO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("THEO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Theo),
        .party = {.NoItemDefaultMoves = sParty_Theo},
    },

    [TRAINER_PRESTON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("PRESTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Preston),
        .party = {.NoItemDefaultMoves = sParty_Preston},
    },

    [TRAINER_TERRELL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("TERRELL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Terrell),
        .party = {.NoItemDefaultMoves = sParty_Terrell},
    },

    [TRAINER_CONNIE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("CONNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Connie),
        .party = {.NoItemDefaultMoves = sParty_Connie},
    },

    [TRAINER_KENT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kent),
        .party = {.NoItemCustomMoves = sParty_Kent},
    },

    [TRAINER_DENIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("DENIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Denis),
        .party = {.NoItemDefaultMoves = sParty_Denis},
    },

    [TRAINER_ERNEST] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ernest),
        .party = {.NoItemDefaultMoves = sParty_Ernest},
    },

    [TRAINER_SIMON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SIMON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Simon),
        .party = {.NoItemDefaultMoves = sParty_Simon},
    },

    [TRAINER_ELAINE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("ELAINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Elaine),
        .party = {.NoItemDefaultMoves = sParty_Elaine},
    },

    [TRAINER_RANDALL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("RANDALL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Randall),
        .party = {.NoItemDefaultMoves = sParty_Randall},
    },

    [TRAINER_PAULA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("PAULA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Paula),
        .party = {.NoItemDefaultMoves = sParty_Paula},
    },

    [TRAINER_GEORGE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("GEORGE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_George),
        .party = {.NoItemDefaultMoves = sParty_George},
    },

    [TRAINER_KARA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KARA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kara),
        .party = {.NoItemDefaultMoves = sParty_Kara},
    },

    [TRAINER_MATHEW] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("MATHEW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Mathew),
        .party = {.NoItemDefaultMoves = sParty_Mathew},
    },

    [TRAINER_DENISE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DENISE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Denise),
        .party = {.NoItemDefaultMoves = sParty_Denise},
    },

    [TRAINER_KIRK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("KIRK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kirk),
        .party = {.NoItemDefaultMoves = sParty_Kirk},
    },

    [TRAINER_BERKE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("BERKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Berke),
        .party = {.NoItemDefaultMoves = sParty_Berke},
    },

    [TRAINER_CHARLIE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("CHARLIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Charlie),
        .party = {.NoItemDefaultMoves = sParty_Charlie},
    },

    [TRAINER_SUSIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SUSIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Susie),
        .party = {.NoItemCustomMoves = sParty_Susie},
    },

    [TRAINER_KAYLEE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KAYLEE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kaylee),
        .party = {.NoItemDefaultMoves = sParty_Kaylee},
    },

    [TRAINER_WENDY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("WENDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wendy),
        .party = {.NoItemCustomMoves = sParty_Wendy},
    },

    [TRAINER_YOSHI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("YOSHI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Yoshi),
        .party = {.NoItemCustomMoves = sParty_Yoshi},
    },

    [TRAINER_LAO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lao),
        .party = {.NoItemCustomMoves = sParty_Lao},
    },

    [TRAINER_NOB] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nob),
        .party = {.NoItemCustomMoves = sParty_Nob},
    },

    [TRAINER_LUNG] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("LUNG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lung),
        .party = {.NoItemDefaultMoves = sParty_Lung},
    },

    [TRAINER_TULLY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TULLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tully),
        .party = {.NoItemDefaultMoves = sParty_Tully},
    },

    [TRAINER_SHANE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("SHANE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Shane),
        .party = {.NoItemDefaultMoves = sParty_Shane},
    },

    [TRAINER_BENJAMIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Benjamin),
        .party = {.NoItemDefaultMoves = sParty_Benjamin},
    },

    [TRAINER_MILLER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("MILLER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Miller),
        .party = {.NoItemDefaultMoves = sParty_Miller},
    },

    [TRAINER_MARKUS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("MARKUS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Markus),
        .party = {.NoItemCustomMoves = sParty_Markus},
    },

    [TRAINER_HUGH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("HUGH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hugh),
        .party = {.NoItemCustomMoves = sParty_Hugh},
    },

    [TRAINER_KIYO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KIYO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kiyo),
        .party = {.NoItemDefaultMoves = sParty_Kiyo},
    },

    [TRAINER_SPENCER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("SPENCER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Spencer),
        .party = {.NoItemDefaultMoves = sParty_Spencer},
    },

    [TRAINER_TIFFANY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tiffany),
        .party = {.NoItemCustomMoves = sParty_Tiffany},
    },

    [TRAINER_MARVIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("MARVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Marvin),
        .party = {.NoItemDefaultMoves = sParty_Marvin},
    },

    [TRAINER_RON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("RON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ron),
        .party = {.NoItemDefaultMoves = sParty_Ron},
    },

    [TRAINER_BRENT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brent),
        .party = {.NoItemDefaultMoves = sParty_Brent},
    },

    [TRAINER_BEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ben),
        .party = {.NoItemDefaultMoves = sParty_Ben},
    },

    [TRAINER_AARON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("AARON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Aaron),
        .party = {.NoItemDefaultMoves = sParty_Aaron},
    },

    [TRAINER_RAYMOND] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RAYMOND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Raymond),
        .party = {.NoItemDefaultMoves = sParty_Raymond},
    },

    [TRAINER_ANDRE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ANDRE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andre),
        .party = {.NoItemDefaultMoves = sParty_Andre},
    },

    [TRAINER_LOIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("LOIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lois),
        .party = {.NoItemCustomMoves = sParty_Lois},
    },

    [TRAINER_MAHOGANY_GRUNT_B1F] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyB1F),
        .party = {.NoItemDefaultMoves = sParty_RocketMahoganyB1F},
    },

    [TRAINER_JED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("JED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jed),
        .party = {.NoItemDefaultMoves = sParty_Jed},
    },

    [TRAINER_MAHOGANY_ALARM_GRUNT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyAlarm1),
        .party = {.NoItemDefaultMoves = sParty_RocketMahoganyAlarm1},
    },

    [TRAINER_MAHOGANY_ALARM_GRUNT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyAlarm2),
        .party = {.NoItemDefaultMoves = sParty_RocketMahoganyAlarm2},
    },

    [TRAINER_MAHOGANY_GRUNT_B2F_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyB2F1),
        .party = {.NoItemDefaultMoves = sParty_RocketMahoganyB2F1},
    },

    [TRAINER_MAHOGANY_GRUNT_B2F_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyB2F2),
        .party = {.NoItemDefaultMoves = sParty_RocketMahoganyB2F2},
    },

    [TRAINER_MAHOGANY_GRUNT_B2F_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyB2F3),
        .party = {.NoItemDefaultMoves = sParty_RocketMahoganyB2F3},
    },

    [TRAINER_MAHOGANY_GRUNT_B3F_F] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyB3FF),
        .party = {.NoItemCustomMoves = sParty_RocketMahoganyB3FF},
    },

    [TRAINER_MAHOGANY_GRUNT_B3F_M] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketMahoganyB3FM),
        .party = {.NoItemDefaultMoves = sParty_RocketMahoganyB3FM},
    },

    [TRAINER_ROSS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("ROSS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ross),
        .party = {.NoItemDefaultMoves = sParty_Ross},
    },

    [TRAINER_MITCH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("MITCH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Mitch),
        .party = {.NoItemDefaultMoves = sParty_Mitch},
    },

    [TRAINER_ROXANNE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SKIER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SKIER,
        .trainerName = _("ROXANNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Roxanne),
        .party = {.NoItemDefaultMoves = sParty_Roxanne},
    },

    [TRAINER_RONALD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BOARDER,
        .trainerName = _("RONALD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ronald),
        .party = {.NoItemDefaultMoves = sParty_Ronald},
    },

    [TRAINER_CLARISSA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SKIER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SKIER,
        .trainerName = _("CLARISSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Clarissa),
        .party = {.NoItemDefaultMoves = sParty_Clarissa},
    },

    [TRAINER_BRAD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BOARDER,
        .trainerName = _("BRAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brad),
        .party = {.NoItemDefaultMoves = sParty_Brad},
    },

    [TRAINER_DOUGLAS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BOARDER,
        .trainerName = _("DOUGLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Douglas),
        .party = {.NoItemDefaultMoves = sParty_Douglas},
    },

    [TRAINER_RADIO_TOWER_1F_GRUNT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower1FRocket),
        .party = {.NoItemDefaultMoves = sParty_RadioTower1FRocket},
    },

    [TRAINER_RADIO_TOWER_2F_GRUNT_F] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower2FRocketF),
        .party = {.NoItemDefaultMoves = sParty_RadioTower2FRocketF},
    },

    [TRAINER_RADIO_TOWER_2F_GRUNT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower2FRocket1),
        .party = {.NoItemDefaultMoves = sParty_RadioTower2FRocket1},
    },

    [TRAINER_RADIO_TOWER_2F_GRUNT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower2FRocket2),
        .party = {.NoItemDefaultMoves = sParty_RadioTower2FRocket2},
    },

    [TRAINER_RADIO_TOWER_2F_GRUNT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower2FRocket3),
        .party = {.NoItemDefaultMoves = sParty_RadioTower2FRocket3},
    },

    [TRAINER_RADIO_TOWER_3F_GRUNT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower3FRocket1),
        .party = {.NoItemDefaultMoves = sParty_RadioTower3FRocket1},
    },

    [TRAINER_MARC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("MARC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Marc),
        .party = {.NoItemDefaultMoves = sParty_Marc},
    },

    [TRAINER_RADIO_TOWER_3F_GRUNT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower3FRocket2),
        .party = {.NoItemDefaultMoves = sParty_RadioTower3FRocket2},
    },

    [TRAINER_RADIO_TOWER_3F_GRUNT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower3FRocket3),
        .party = {.NoItemDefaultMoves = sParty_RadioTower3FRocket3},
    },

    [TRAINER_RADIO_TOWER_4F_GRUNT_M] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower4FRocketM),
        .party = {.NoItemDefaultMoves = sParty_RadioTower4FRocketM},
    },

    [TRAINER_RICH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("RICH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rich),
        .party = {.NoItemCustomMoves = sParty_Rich},
    },

    [TRAINER_RADIO_TOWER_4F_GRUNT_F] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower4FRocketF),
        .party = {.NoItemDefaultMoves = sParty_RadioTower4FRocketF},
    },

    [TRAINER_RADIO_TOWER_4F_EXECUTIVE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_EXECUTIVE_M,
        .trainerName = _("EXECUTIVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower4FExecutive),
        .party = {.NoItemCustomMoves = sParty_RadioTower4FExecutive},
    },

    [TRAINER_RADIO_TOWER_5F_EXECUTIVE_F] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_EXECUTIVE_F,
        .trainerName = _("EXECUTIVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower5FExecutiveF),
        .party = {.NoItemCustomMoves = sParty_RadioTower5FExecutiveF},
    },

    [TRAINER_UNDERGROUND_B2F_GRUNT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_UndergroundB2FRocket1),
        .party = {.NoItemDefaultMoves = sParty_UndergroundB2FRocket1},
    },

    [TRAINER_UNDERGROUND_B2F_GRUNT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_UndergroundB2FRocket2),
        .party = {.NoItemDefaultMoves = sParty_UndergroundB2FRocket2},
    },

    [TRAINER_UNDERGROUND_B2F_GRUNT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_UndergroundB2FRocket3),
        .party = {.NoItemDefaultMoves = sParty_UndergroundB2FRocket3},
    },

    [TRAINER_EDDIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("EDDIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Eddie),
        .party = {.NoItemCustomMoves = sParty_Eddie},
    },

    [TRAINER_DUNCAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("DUNCAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Duncan),
        .party = {.NoItemDefaultMoves = sParty_Duncan},
    },

    [TRAINER_UNDERGROUND_B2F_GRUNT_F] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_UndergroundB2FRocketF),
        .party = {.NoItemDefaultMoves = sParty_UndergroundB2FRocketF},
    },

    [TRAINER_WAREHOUSE_GRUNT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_WarehouseRocket1),
        .party = {.NoItemDefaultMoves = sParty_WarehouseRocket1},
    },

    [TRAINER_WAREHOUSE_GRUNT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_WarehouseRocket2),
        .party = {.NoItemDefaultMoves = sParty_WarehouseRocket2},
    },

    [TRAINER_WAREHOUSE_GRUNT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_WarehouseRocket3),
        .party = {.NoItemDefaultMoves = sParty_WarehouseRocket3},
    },

    [TRAINER_PHIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("PHIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Phil),
        .party = {.NoItemCustomMoves = sParty_Phil},
    },

    [TRAINER_EDGAR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("EDGAR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edgar),
        .party = {.NoItemCustomMoves = sParty_Edgar},
    },

    [TRAINER_CYBIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Cybil"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cybil),
        .party = {.NoItemCustomMoves = sParty_Cybil},
    },

    [TRAINER_ALLEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("ALLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Allen),
        .party = {.NoItemCustomMoves = sParty_Allen},
    },

    [TRAINER_ZACH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ZACH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Zach),
        .party = {.NoItemDefaultMoves = sParty_Zach},
    },

    [TRAINER_WILTON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wilton),
        .party = {.NoItemDefaultMoves = sParty_Wilton},
    },

    [TRAINER_VANCE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Vance),
        .party = {.NoItemDefaultMoves = sParty_Vance},
    },

    [TRAINER_PAUL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("PAUL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Paul),
        .party = {.NoItemDefaultMoves = sParty_Paul},
    },

    [TRAINER_FRAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("FRAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Fran),
        .party = {.NoItemDefaultMoves = sParty_Fran},
    },

    [TRAINER_CODY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("CODY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cody),
        .party = {.NoItemDefaultMoves = sParty_Cody},
    },

    [TRAINER_MIKE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("MIKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Mike),
        .party = {.NoItemDefaultMoves = sParty_Mike},
    },

    [TRAINER_LOLA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("LOLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Lola),
        .party = {.NoItemDefaultMoves = sParty_Lola},
    },

    [TRAINER_DARIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("DARIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Darin),
        .party = {.NoItemCustomMoves = sParty_Darin},
    },

    [TRAINER_CARA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CARA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cara),
        .party = {.NoItemCustomMoves = sParty_Cara},
    },

    [TRAINER_LEA_AND_PIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("LEA & PIA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LeaAndPia),
        .party = {.NoItemCustomMoves = sParty_LeaAndPia},
    },

    [TRAINER_ERIK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ERIK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Erik),
        .party = {.NoItemDefaultMoves = sParty_Erik},
    },

    [TRAINER_RYAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("RYAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Ryan),
        .party = {.NoItemCustomMoves = sParty_Ryan},
    },

    [TRAINER_KELLY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("KELLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Kelly),
        .party = {.NoItemDefaultMoves = sParty_Kelly},
    },

    [TRAINER_PARRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Parry),
        .party = {.NoItemDefaultMoves = sParty_Parry},
    },

    [TRAINER_KENJI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KENJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kenji),
        .party = {.NoItemDefaultMoves = sParty_Kenji},
    },

    [TRAINER_TIMOTHY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Timothy),
        .party = {.NoItemCustomMoves = sParty_Timothy},
    },

    [TRAINER_MICHAEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MICHAEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Michael),
        .party = {.NoItemDefaultMoves = sParty_Michael},
    },

    [TRAINER_QUENTIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("QUENTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Quentin),
        .party = {.NoItemDefaultMoves = sParty_Quentin},
    },

[TRAINER_BAILEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BAILEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bailey),
        .party = {.NoItemDefaultMoves = sParty_Bailey},
    },

    [TRAINER_TED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ted),
        .party = {.NoItemDefaultMoves = sParty_Ted},
    },

    [TRAINER_ERIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Erin),
        .party = {.NoItemDefaultMoves = sParty_Erin},
    },

    [TRAINER_MEGAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("MEGAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Megan),
        .party = {.NoItemCustomMoves = sParty_Megan},
    },

    [TRAINER_BLAKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("BLAKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Blake),
        .party = {.NoItemCustomMoves = sParty_Blake},
    },


    [TRAINER_JOSE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jose),
        .party = {.NoItemDefaultMoves = sParty_Jose},
    },

    [TRAINER_BRIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("BRIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Brian),
        .party = {.NoItemCustomMoves = sParty_Brian},
    },

    [TRAINER_GILBERT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("GILBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Gilbert),
        .party = {.NoItemDefaultMoves = sParty_Gilbert},
    },

    [TRAINER_REENA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("REENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Reena),
        .party = {.NoItemDefaultMoves = sParty_Reena},
    },

    [TRAINER_SCOTT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("SCOTT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Scott),
        .party = {.NoItemDefaultMoves = sParty_Scott},
    },

    [TRAINER_RICHARD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("RICHARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Richard),
        .party = {.NoItemDefaultMoves = sParty_Richard},
    },

    [TRAINER_JOYCE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JOYCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Joyce),
        .party = {.NoItemCustomMoves = sParty_Joyce},
    },

    [TRAINER_GAVEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Gaven),
        .party = {.NoItemCustomMoves = sParty_Gaven},
    },

    [TRAINER_JAKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("JAKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jake),
        .party = {.NoItemCustomMoves = sParty_Jake},
    },

    [TRAINER_BETH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Beth),
        .party = {.NoItemCustomMoves = sParty_Beth},
    },

    [TRAINER_JEFFREY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey3),
        .party = {.NoItemDefaultMoves = sParty_Jeffrey3},
    },

    [TRAINER_JEFFREY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey4),
        .party = {.NoItemDefaultMoves = sParty_Jeffrey4},
    },

    [TRAINER_JEFFREY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey5),
        .party = {.ItemDefaultMoves = sParty_Jeffrey5},
    },

    [TRAINER_EDWARD_OLD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("EDWARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edward_Old),
        .party = {.NoItemCustomMoves = sParty_Edward_Old},
    },

    [TRAINER_PRESTON_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("PRESTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Preston_Old),
        .party = {.NoItemDefaultMoves = sParty_Preston_Old},
    },

    [TRAINER_VIRGIL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("VIRGIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Virgil),
        .party = {.NoItemDefaultMoves = sParty_Virgil},
    },

    [TRAINER_BLAKE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("BLAKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Blake_Old),
        .party = {.NoItemDefaultMoves = sParty_Blake_Old},
    },

    [TRAINER_WILLIAM_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("WILLIAM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_WilliamOld),
        .party = {.NoItemDefaultMoves = sParty_WilliamOld},
    },

    [TRAINER_JOSHUA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("JOSHUA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joshua),
        .party = {.NoItemDefaultMoves = sParty_Joshua},
    },

    [TRAINER_CAMERON_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cameron1),
        .party = {.NoItemDefaultMoves = sParty_Cameron1},
    },

    [TRAINER_CAMERON_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cameron2),
        .party = {.NoItemDefaultMoves = sParty_Cameron2},
    },

    [TRAINER_CAMERON_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cameron3),
        .party = {.NoItemDefaultMoves = sParty_Cameron3},
    },

    [TRAINER_CAMERON_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cameron4),
        .party = {.NoItemDefaultMoves = sParty_Cameron4},
    },

    [TRAINER_CAMERON_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cameron5),
        .party = {.NoItemDefaultMoves = sParty_Cameron5},
    },

    [TRAINER_JACLYN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACLYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jaclyn),
        .party = {.NoItemCustomMoves = sParty_Jaclyn},
    },

    [TRAINER_HANNAH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("HANNAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hannah),
        .party = {.NoItemDefaultMoves = sParty_Hannah},
    },

    [TRAINER_SAMANTHA_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("SAMANTHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_SamanthaOld),
        .party = {.NoItemDefaultMoves = sParty_SamanthaOld},
    },

    [TRAINER_MAURA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MAURA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Maura),
        .party = {.NoItemDefaultMoves = sParty_Maura},
    },

    [TRAINER_KAYLA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("KAYLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kayla),
        .party = {.NoItemDefaultMoves = sParty_Kayla},
    },

    [TRAINER_ALEXIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("ALEXIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alexis),
        .party = {.NoItemDefaultMoves = sParty_Alexis},
    },

    [TRAINER_JACKI_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jacki1),
        .party = {.NoItemDefaultMoves = sParty_Jacki1},
    },

    [TRAINER_JACKI_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jacki2),
        .party = {.NoItemDefaultMoves = sParty_Jacki2},
    },

    [TRAINER_JACKI_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jacki3),
        .party = {.NoItemDefaultMoves = sParty_Jacki3},
    },

    [TRAINER_JACKI_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jacki4),
        .party = {.NoItemDefaultMoves = sParty_Jacki4},
    },

    [TRAINER_JACKI_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jacki5),
        .party = {.NoItemDefaultMoves = sParty_Jacki5},
    },

    [TRAINER_WALTER_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Walter1),
        .party = {.NoItemDefaultMoves = sParty_Walter1},
    },

    [TRAINER_MICAH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("MICAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Micah),
        .party = {.NoItemDefaultMoves = sParty_Micah},
    },

    [TRAINER_THOMAS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("THOMAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Thomas),
        .party = {.NoItemDefaultMoves = sParty_Thomas},
    },

    [TRAINER_WALTER_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Walter2),
        .party = {.NoItemDefaultMoves = sParty_Walter2},
    },

    [TRAINER_WALTER_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Walter3),
        .party = {.NoItemCustomMoves = sParty_Walter3},
    },

    [TRAINER_WALTER_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Walter4),
        .party = {.NoItemCustomMoves = sParty_Walter4},
    },

    [TRAINER_WALTER_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Walter5),
        .party = {.NoItemCustomMoves = sParty_Walter5},
    },

    [TRAINER_JERRY_OLD_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry_Old_1),
        .party = {.NoItemDefaultMoves = sParty_Jerry_Old_1},
    },

    [TRAINER_TED_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("TED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TedOld),
        .party = {.NoItemDefaultMoves = sParty_TedOld},
    },

    [TRAINER_PAUL_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("PAUL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Paul_Old),
        .party = {.NoItemDefaultMoves = sParty_Paul_Old},
    },

    [TRAINER_JERRY_OLD_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry_Old_2),
        .party = {.NoItemDefaultMoves = sParty_Jerry_Old_2},
    },

    [TRAINER_JERRY_OLD_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry_Old_3),
        .party = {.NoItemDefaultMoves = sParty_Jerry_Old_3},
    },

    [TRAINER_JERRY_OLD_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry_Old_4),
        .party = {.NoItemDefaultMoves = sParty_Jerry_Old_4},
    },

    [TRAINER_JERRY_OLD_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry_Old_5),
        .party = {.NoItemDefaultMoves = sParty_Jerry_Old_5},
    },

    [TRAINER_KAREN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Karen1),
        .party = {.NoItemDefaultMoves = sParty_Karen1},
    },

    [TRAINER_GEORGIA_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("GEORGIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Georgia_Old),
        .party = {.NoItemDefaultMoves = sParty_Georgia_Old},
    },

    [TRAINER_KAREN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Karen2),
        .party = {.NoItemDefaultMoves = sParty_Karen2},
    },

    [TRAINER_KAREN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Karen3),
        .party = {.NoItemDefaultMoves = sParty_Karen3},
    },

    [TRAINER_KAREN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Karen4),
        .party = {.NoItemDefaultMoves = sParty_Karen4},
    },

    [TRAINER_KAREN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Karen5),
        .party = {.NoItemDefaultMoves = sParty_Karen5},
    },

    [TRAINER_KATE_AND_JOY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("KATE & JOY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_KateAndJoy),
        .party = {.NoItemCustomMoves = sParty_KateAndJoy},
    },

    [TRAINER_ANNA_AND_MEG_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg1),
        .party = {.NoItemCustomMoves = sParty_AnnaAndMeg1},
    },

    [TRAINER_ANNA_AND_MEG_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg2),
        .party = {.NoItemCustomMoves = sParty_AnnaAndMeg2},
    },

    [TRAINER_ANNA_AND_MEG_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg3),
        .party = {.NoItemCustomMoves = sParty_AnnaAndMeg3},
    },

    [TRAINER_ANNA_AND_MEG_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg4),
        .party = {.NoItemCustomMoves = sParty_AnnaAndMeg4},
    },

    [TRAINER_ANNA_AND_MEG_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg5),
        .party = {.NoItemCustomMoves = sParty_AnnaAndMeg5},
    },

    [TRAINER_VICTOR] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("VICTOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Victor),
        .party = {.ItemDefaultMoves = sParty_Victor},
    },

    [TRAINER_MIGUEL_1] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Miguel1),
        .party = {.ItemDefaultMoves = sParty_Miguel1},
    },

    [TRAINER_COLTON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("COLTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Colton),
        .party = {.ItemCustomMoves = sParty_Colton},
    },

    [TRAINER_MIGUEL_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Miguel2),
        .party = {.ItemDefaultMoves = sParty_Miguel2},
    },

    [TRAINER_MIGUEL_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Miguel3),
        .party = {.ItemDefaultMoves = sParty_Miguel3},
    },

    [TRAINER_MIGUEL_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Miguel4),
        .party = {.ItemDefaultMoves = sParty_Miguel4},
    },

    [TRAINER_MIGUEL_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Miguel5),
        .party = {.ItemDefaultMoves = sParty_Miguel5},
    },

    [TRAINER_VICTORIA_OLD] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("VICTORIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_VictoriaOld),
        .party = {.ItemDefaultMoves = sParty_VictoriaOld},
    },

    [TRAINER_VANESSA] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("VANESSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Vanessa),
        .party = {.ItemDefaultMoves = sParty_Vanessa},
    },

    [TRAINER_BETHANY] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BETHANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bethany),
        .party = {.ItemDefaultMoves = sParty_Bethany},
    },

    [TRAINER_ISABEL_1] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isabel1),
        .party = {.ItemDefaultMoves = sParty_Isabel1},
    },

    [TRAINER_ISABEL_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isabel2),
        .party = {.ItemDefaultMoves = sParty_Isabel2},
    },

    [TRAINER_ISABEL_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isabel3),
        .party = {.ItemDefaultMoves = sParty_Isabel3},
    },

    [TRAINER_ISABEL_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isabel4),
        .party = {.ItemDefaultMoves = sParty_Isabel4},
    },

    [TRAINER_ISABEL_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isabel5),
        .party = {.ItemDefaultMoves = sParty_Isabel5},
    },

    [TRAINER_TIMOTHY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Timothy2),
        .party = {.NoItemCustomMoves = sParty_Timothy2},
    },

    [TRAINER_TIMOTHY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Timothy3),
        .party = {.NoItemCustomMoves = sParty_Timothy3},
    },

    [TRAINER_TIMOTHY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Timothy4),
        .party = {.NoItemCustomMoves = sParty_Timothy4},
    },

    [TRAINER_TIMOTHY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Timothy5),
        .party = {.NoItemCustomMoves = sParty_Timothy5},
    },

    [TRAINER_VICKY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("VICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Vicky),
        .party = {.NoItemCustomMoves = sParty_Vicky},
    },

    [TRAINER_SHELBY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Shelby1),
        .party = {.NoItemDefaultMoves = sParty_Shelby1},
    },

    [TRAINER_SHELBY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Shelby2),
        .party = {.NoItemDefaultMoves = sParty_Shelby2},
    },

    [TRAINER_SHELBY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Shelby3),
        .party = {.NoItemDefaultMoves = sParty_Shelby3},
    },

    [TRAINER_JERRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry),
        .party = {.NoItemDefaultMoves = sParty_Jerry},
    },

    [TRAINER_PARKER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("PARKER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Parker),
        .party = {.NoItemDefaultMoves = sParty_Parker},
    },

    [TRAINER_BRIANA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BRIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Briana),
        .party = {.NoItemDefaultMoves = sParty_Briana},
    },

    [TRAINER_DIANA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Diana),
        .party = {.NoItemDefaultMoves = sParty_Diana},
    },

    [TRAINER_HORTON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("HORTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Horton),
        .party = {.NoItemDefaultMoves = sParty_Horton},
    },

    [TRAINER_VINCENT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("VINCENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Vincent),
        .party = {.NoItemDefaultMoves = sParty_Vincent},
    },

    [TRAINER_GREGORY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("GREGORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gregory),
        .party = {.NoItemDefaultMoves = sParty_Gregory},
    },

    [TRAINER_JO_AND_ZOE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("JO & ZOE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_JoAndZoe),
        .party = {.NoItemDefaultMoves = sParty_JoAndZoe},
    },

    [TRAINER_TANYA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TANYA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tanya),
        .party = {.NoItemDefaultMoves = sParty_Tanya},
    },

    [TRAINER_MICHELLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("MICHELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Michelle),
        .party = {.NoItemDefaultMoves = sParty_Michelle},
    },

    [TRAINER_JULIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JULIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Julia),
        .party = {.NoItemDefaultMoves = sParty_Julia},
    },

    [TRAINER_LINDA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("LINDA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Linda),
        .party = {.NoItemDefaultMoves = sParty_Linda},
    },

    [TRAINER_CINDY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CINDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cindy),
        .party = {.NoItemDefaultMoves = sParty_Cindy},
    },

    [TRAINER_BARRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("BARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Barry),
        .party = {.NoItemDefaultMoves = sParty_Barry},
    },

    [TRAINER_ALICE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ALICE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alice),
        .party = {.NoItemDefaultMoves = sParty_Alice},
    },

    [TRAINER_REBECCA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MEDIUM,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("REBECCA"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Rebecca),
        .party = {.NoItemDefaultMoves = sParty_Rebecca},
    },

    [TRAINER_JARED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("JARED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jared),
        .party = {.NoItemDefaultMoves = sParty_Jared},
    },

    [TRAINER_DORIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MEDIUM,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("DORIS"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Doris),
        .party = {.NoItemDefaultMoves = sParty_Doris},
    },

    [TRAINER_FRANKLIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("FRANKLIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Franklin),
        .party = {.NoItemDefaultMoves = sParty_Franklin},
    },

    [TRAINER_ANDREW_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ANDREW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AndrewOld),
        .party = {.NoItemDefaultMoves = sParty_AndrewOld},
    },

    [TRAINER_IVAN_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("IVAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_IvanOld),
        .party = {.NoItemDefaultMoves = sParty_IvanOld},
    },

    [TRAINER_CLAUDE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CLAUDE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Claude),
        .party = {.NoItemDefaultMoves = sParty_Claude},
    },

    [TRAINER_ELLIOT_OLD_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Elliot1),
        .party = {.NoItemDefaultMoves = sParty_Elliot1},
    },

    [TRAINER_NED_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("NED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ned_Old),
        .party = {.NoItemDefaultMoves = sParty_Ned_Old},
    },

    [TRAINER_DALE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("DALE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dale),
        .party = {.NoItemDefaultMoves = sParty_Dale},
    },

    [TRAINER_NOLAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("NOLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nolan),
        .party = {.NoItemDefaultMoves = sParty_Nolan},
    },

    [TRAINER_BARNY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("BARNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Barny),
        .party = {.NoItemDefaultMoves = sParty_Barny},
    },

    [TRAINER_WADE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WADE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wade),
        .party = {.NoItemDefaultMoves = sParty_Wade},
    },

    [TRAINER_CARTER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CARTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Carter),
        .party = {.NoItemDefaultMoves = sParty_Carter},
    },

    [TRAINER_ELLIOT_OLD_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Elliot2),
        .party = {.NoItemDefaultMoves = sParty_Elliot2},
    },

    [TRAINER_ELLIOT_OLD_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Elliot3),
        .party = {.NoItemDefaultMoves = sParty_Elliot3},
    },

    [TRAINER_ELLIOT_OLD_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Elliot4),
        .party = {.NoItemDefaultMoves = sParty_Elliot4},
    },

    [TRAINER_ELLIOT_OLD_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Elliot5),
        .party = {.NoItemDefaultMoves = sParty_Elliot5},
    },

    [TRAINER_RONALD_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RONALD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ronald_Old),
        .party = {.NoItemDefaultMoves = sParty_Ronald_Old},
    },

    [TRAINER_JACOB] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("JACOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jacob),
        .party = {.NoItemDefaultMoves = sParty_Jacob},
    },

    [TRAINER_ANTHONY_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AnthonyOld),
        .party = {.NoItemDefaultMoves = sParty_AnthonyOld},
    },

    [TRAINER_BENJAMIN_OLD_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Benjamin1),
        .party = {.NoItemDefaultMoves = sParty_Benjamin1},
    },

    [TRAINER_BENJAMIN_OLD_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Benjamin2),
        .party = {.NoItemDefaultMoves = sParty_Benjamin2},
    },

    [TRAINER_BENJAMIN_OLD_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Benjamin3),
        .party = {.NoItemDefaultMoves = sParty_Benjamin3},
    },

    [TRAINER_BENJAMIN_OLD_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Benjamin4),
        .party = {.NoItemDefaultMoves = sParty_Benjamin4},
    },

    [TRAINER_BENJAMIN_OLD_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Benjamin5),
        .party = {.NoItemDefaultMoves = sParty_Benjamin5},
    },

    [TRAINER_ABIGAIL_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Abigail1),
        .party = {.NoItemDefaultMoves = sParty_Abigail1},
    },

    [TRAINER_JASMINE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("JASMINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jasmine_Old),
        .party = {.NoItemDefaultMoves = sParty_Jasmine_Old},
    },

    [TRAINER_ABIGAIL_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Abigail2),
        .party = {.NoItemDefaultMoves = sParty_Abigail2},
    },

    [TRAINER_ABIGAIL_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Abigail3),
        .party = {.NoItemDefaultMoves = sParty_Abigail3},
    },

    [TRAINER_ABIGAIL_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Abigail4),
        .party = {.NoItemDefaultMoves = sParty_Abigail4},
    },

    [TRAINER_ABIGAIL_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Abigail5),
        .party = {.NoItemDefaultMoves = sParty_Abigail5},
    },

    [TRAINER_DYLAN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dylan1),
        .party = {.NoItemDefaultMoves = sParty_Dylan1},
    },

    [TRAINER_DYLAN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dylan2),
        .party = {.NoItemDefaultMoves = sParty_Dylan2},
    },

    [TRAINER_DYLAN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dylan3),
        .party = {.NoItemDefaultMoves = sParty_Dylan3},
    },

    [TRAINER_DYLAN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dylan4),
        .party = {.NoItemDefaultMoves = sParty_Dylan4},
    },

    [TRAINER_DYLAN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dylan5),
        .party = {.NoItemDefaultMoves = sParty_Dylan5},
    },

    [TRAINER_MARIA_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Maria1),
        .party = {.NoItemDefaultMoves = sParty_Maria1},
    },

    [TRAINER_MARIA_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Maria2),
        .party = {.NoItemDefaultMoves = sParty_Maria2},
    },

    [TRAINER_MARIA_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Maria3),
        .party = {.NoItemDefaultMoves = sParty_Maria3},
    },

    [TRAINER_MARIA_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Maria4),
        .party = {.NoItemDefaultMoves = sParty_Maria4},
    },

    [TRAINER_MARIA_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Maria5),
        .party = {.NoItemDefaultMoves = sParty_Maria5},
    },

    [TRAINER_CAMDEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("CAMDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Camden),
        .party = {.NoItemDefaultMoves = sParty_Camden},
    },

    [TRAINER_DEMETRIUS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DEMETRIUS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Demetrius),
        .party = {.NoItemDefaultMoves = sParty_Demetrius},
    },

    [TRAINER_ISAIAH_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaiah1),
        .party = {.NoItemDefaultMoves = sParty_Isaiah1},
    },

    [TRAINER_PABLO_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pablo1),
        .party = {.NoItemDefaultMoves = sParty_Pablo1},
    },

    [TRAINER_CHASE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("CHASE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chase),
        .party = {.NoItemDefaultMoves = sParty_Chase},
    },

    [TRAINER_ISAIAH_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaiah2),
        .party = {.NoItemDefaultMoves = sParty_Isaiah2},
    },

    [TRAINER_ISAIAH_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaiah3),
        .party = {.NoItemDefaultMoves = sParty_Isaiah3},
    },

    [TRAINER_ISAIAH_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaiah4),
        .party = {.NoItemDefaultMoves = sParty_Isaiah4},
    },

    [TRAINER_ISAIAH_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaiah5),
        .party = {.NoItemDefaultMoves = sParty_Isaiah5},
    },

    [TRAINER_ISOBEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ISOBEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isobel),
        .party = {.NoItemDefaultMoves = sParty_Isobel},
    },

    [TRAINER_DONNY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("DONNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Donny),
        .party = {.NoItemDefaultMoves = sParty_Donny},
    },

    [TRAINER_TALIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("TALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Talia),
        .party = {.NoItemDefaultMoves = sParty_Talia},
    },

    [TRAINER_KATELYN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Katelyn1),
        .party = {.NoItemDefaultMoves = sParty_Katelyn1},
    },

    [TRAINER_ALLISON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ALLISON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Allison),
        .party = {.NoItemDefaultMoves = sParty_Allison},
    },

    [TRAINER_KATELYN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Katelyn2),
        .party = {.NoItemDefaultMoves = sParty_Katelyn2},
    },

    [TRAINER_KATELYN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Katelyn3),
        .party = {.NoItemDefaultMoves = sParty_Katelyn3},
    },

    [TRAINER_NOLAND] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("NOLAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Noland),
        .party = {.NoItemDefaultMoves = sParty_Noland},
    },

    [TRAINER_COLIN] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("COLIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Colin),
        .party = {.ItemDefaultMoves = sParty_Colin},
    },

    [TRAINER_MEG_AND_PEG] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("MEG & PEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_MegAndPeg),
        .party = {.NoItemDefaultMoves = sParty_MegAndPeg},
    },

    [TRAINER_LYLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("LYLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lyle),
        .party = {.NoItemDefaultMoves = sParty_Lyle},
    },

    [TRAINER_STANLY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("STANLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Stanly),
        .party = {.NoItemDefaultMoves = sParty_Stanly},
    },

    [TRAINER_FRITZ] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("FRITZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Fritz),
        .party = {.NoItemDefaultMoves = sParty_Fritz},
    },

    [TRAINER_JEFF] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("JEFF"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jeff),
        .party = {.NoItemDefaultMoves = sParty_Jeff},
    },

    [TRAINER_DEBRA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DEBRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Debra),
        .party = {.NoItemDefaultMoves = sParty_Debra},
    },

    [TRAINER_EDWARD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("EDWARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edward),
        .party = {.NoItemDefaultMoves = sParty_Edward},
    },

    [TRAINER_SEAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("SEAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Sean),
        .party = {.NoItemDefaultMoves = sParty_Sean},
    },

    [TRAINER_CAROL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CAROL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Carol),
        .party = {.NoItemDefaultMoves = sParty_Carol},
    },

    [TRAINER_SHAWN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("SHAWN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Shawn),
        .party = {.NoItemDefaultMoves = sParty_Shawn},
    },

    [TRAINER_RODNEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("RODNEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rodney),
        .party = {.NoItemDefaultMoves = sParty_Rodney},
    },

    [TRAINER_CASSIE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("CASSIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cassie),
        .party = {.NoItemDefaultMoves = sParty_Cassie},
    },

    [TRAINER_JONAH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("JONAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jonah),
        .party = {.NoItemDefaultMoves = sParty_Jonah},
    },

    [TRAINER_GARRETT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("GARRETT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Garrett),
        .party = {.NoItemDefaultMoves = sParty_Garrett},
    },

    [TRAINER_WAI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("WAI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wai),
        .party = {.NoItemDefaultMoves = sParty_Wai},
    },

    [TRAINER_COREY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("COREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Corey),
        .party = {.NoItemDefaultMoves = sParty_Corey},
    },

    [TRAINER_ETHAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ethan),
        .party = {.NoItemDefaultMoves = sParty_Ethan},
    },

    [TRAINER_KEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("KEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ken),
        .party = {.NoItemDefaultMoves = sParty_Ken }
    },

    [TRAINER_CLYDE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("CLYDE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Clyde),
        .party = {.NoItemDefaultMoves = sParty_Clyde},
    },

    [TRAINER_GEORGIA] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("GEORGIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Georgia),
        .party = {.ItemDefaultMoves = sParty_Georgia},
    },

    [TRAINER_JEREMY] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("JEREMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jeremy),
        .party = {.ItemDefaultMoves = sParty_Jeremy},
    },

    [TRAINER_KENNETH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KENNETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kenneth),
        .party = {.NoItemDefaultMoves = sParty_Kenneth},
    },

    [TRAINER_SHIRLEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEACHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_TEACHER,
        .trainerName = _("SHIRLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Shirley),
        .party = {.NoItemDefaultMoves = sParty_Shirley},
    },

    [TRAINER_NATE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("NATE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nate),
        .party = {.NoItemDefaultMoves = sParty_Nate},
    },

    [TRAINER_RICKY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("RICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ricky),
        .party = {.NoItemDefaultMoves = sParty_Ricky},
    },

     [TRAINER_RIVAL_CHERRYGROVE_CHIKORITA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalCherrygroveChikorita),
        .party = {.NoItemDefaultMoves = sParty_RivalCherrygroveChikorita }
    },

    [TRAINER_RIVAL_CHERRYGROVE_TOTODILE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalCherrygroveTotodile),
        .party = {.NoItemDefaultMoves = sParty_RivalCherrygroveTotodile }
    },

    [TRAINER_RIVAL_CHERRYGROVE_CYNDAQUIL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalCherrygroveCyndaquil),
        .party = {.NoItemDefaultMoves = sParty_RivalCherrygroveCyndaquil }
    },

    [TRAINER_RIVAL_AZALEA_CHIKORITA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalAzaleaChikorita),
        .party = {.NoItemDefaultMoves = sParty_RivalAzaleaChikorita},
    },

    [TRAINER_RIVAL_AZALEA_TOTODILE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalAzaleaTotodile),
        .party = {.NoItemDefaultMoves = sParty_RivalAzaleaTotodile},
    },

    [TRAINER_RIVAL_AZALEA_CYNDAQUIL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalAzaleaCyndaquil),
        .party = {.NoItemDefaultMoves = sParty_RivalAzaleaCyndaquil},
    },

    [TRAINER_RIVAL_BURNED_TOWER_CHIKORITA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalBurnedTowerChikorita),
        .party = {.NoItemCustomMoves = sParty_RivalBurnedTowerChikorita},
    },

    [TRAINER_RIVAL_BURNED_TOWER_TOTODILE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalBurnedTowerTotodile),
        .party = {.NoItemCustomMoves = sParty_RivalBurnedTowerTotodile},
    },

    [TRAINER_RIVAL_BURNED_TOWER_CYNDAQUIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalBurnedTowerCyndaquil),
        .party = {.NoItemCustomMoves = sParty_RivalBurnedTowerCyndaquil},
    },

    [TRAINER_RIVAL_GOLDENROD_TUNNEL_CHIKORITA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalGoldenrodChikorita),
        .party = {.NoItemCustomMoves = sParty_RivalGoldenrodChikorita},
    },

    [TRAINER_RIVAL_GOLDENROD_TUNNEL_TOTODILE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalGoldenrodTotodile),
        .party = {.NoItemCustomMoves = sParty_RivalGoldenrodTotodile},
    },

    [TRAINER_RIVAL_GOLDENROD_TUNNEL_CYNDAQUIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalGoldenrodCyndaquil),
        .party = {.NoItemCustomMoves = sParty_RivalGoldenrodCyndaquil},
    },

    [TRAINER_RIVAL_VICTORY_ROAD_CHIKORITA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalVictoryRoadChikorita),
        .party = {.NoItemCustomMoves = sParty_RivalVictoryRoadChikorita},
    },

    [TRAINER_RIVAL_VICTORY_ROAD_TOTODILE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalVictoryRoadTotodile),
        .party = {.NoItemCustomMoves = sParty_RivalVictoryRoadTotodile},
    },

    [TRAINER_RIVAL_VICTORY_ROAD_CYNDAQUIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalVictoryRoadCyndaquil),
        .party = {.NoItemCustomMoves = sParty_RivalVictoryRoadCyndaquil},
    },

    [TRAINER_RIVAL_MT_MOON_CHIKORITA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalMtMoonChikorita),
        .party = {.NoItemCustomMoves = sParty_RivalMtMoonChikorita},
    },

    [TRAINER_RIVAL_MT_MOON_TOTODILE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalMtMoonTotodile),
        .party = {.NoItemCustomMoves = sParty_RivalMtMoonTotodile},
    },

    [TRAINER_RIVAL_MT_MOON_CYNDAQUIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalMtMoonCyndaquil),
        .party = {.NoItemCustomMoves = sParty_RivalMtMoonCyndaquil},
    },

    [TRAINER_RIVAL_REMATCH_CHIKORITA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalRematchChikorita),
        .party = {.NoItemCustomMoves = sParty_RivalRematchChikorita},
    },

    [TRAINER_RIVAL_REMATCH_TOTODILE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalRematchTotodile),
        .party = {.NoItemCustomMoves = sParty_RivalRematchTotodile},
    },

    [TRAINER_RIVAL_REMATCH_CYNDAQUIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("SILVER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalRematchCyndaquil),
        .party = {.NoItemCustomMoves = sParty_RivalRematchCyndaquil},
    },

    [TRAINER_ROCKET_SLOWPOKE_WELL_BOSS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketSlowpokeWellBoss),
        .party = {.NoItemDefaultMoves = sParty_RocketSlowpokeWellBoss},
    },

    [TRAINER_MAHOGANY_EXECUTIVE_M] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_EXECUTIVE_M,
        .trainerName = _("EXECUTIVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_MahoganyExecutiveM),
        .party = {.NoItemDefaultMoves = sParty_MahoganyExecutiveM},
    },

    [TRAINER_MAHOGANY_EXECUTIVE_F] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_EXECUTIVE_F,
        .trainerName = _("EXECUTIVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_MahoganyExecutiveF),
        .party = {.NoItemCustomMoves = sParty_MahoganyExecutiveF},
    },

    [TRAINER_RADIO_TOWER_5F_EXECUTIVE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_EXECUTIVE_M,
        .trainerName = _("EXECUTIVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower5FExecutive1),
        .party = {.NoItemCustomMoves = sParty_RadioTower5FExecutive1},
    },

    [TRAINER_RADIO_TOWER_5F_EXECUTIVE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_EXECUTIVE_M,
        .trainerName = _("EXECUTIVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RadioTower5FExecutive2),
        .party = {.NoItemCustomMoves = sParty_RadioTower5FExecutive2},
    },

    [TRAINER_ROCKET_ROUTE24] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketRoute24),
        .party = {.NoItemDefaultMoves = sParty_RocketRoute24},
    },

    [TRAINER_EUSINE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_MYSTICALMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_EUSINE,
        .trainerName = _("EUSINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Eusine),
        .party = {.NoItemCustomMoves = sParty_Eusine},
    },

    [TRAINER_FALKNER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .trainerName = _("FALKNER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Falkner),
        .party = {.NoItemCustomMoves = sParty_Falkner},
    },

    [TRAINER_BUGSY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .trainerName = _("BUGSY"),
        .items = {ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Bugsy),
        .party = {.NoItemCustomMoves = sParty_Bugsy},
    },

    [TRAINER_WHITNEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .trainerName = _("WHITNEY"),
        .items = {ITEM_SUPER_POTION, ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Whitney),
        .party = {.NoItemCustomMoves = sParty_Whitney},
    },

    [TRAINER_MORTY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_LEADER_MORTY,
        .trainerName = _("MORTY"),
        .items = {ITEM_SUPER_POTION, ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Morty),
        .party = {.NoItemCustomMoves = sParty_Morty},
    },

    [TRAINER_CHUCK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_LEADER_CHUCK,
        .trainerName = _("CHUCK"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Chuck),
        .party = {.NoItemCustomMoves = sParty_Chuck},
    },

    [TRAINER_JASMINE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_JASMINE,
        .trainerName = _("JASMINE"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jasmine),
        .party = {.NoItemCustomMoves = sParty_Jasmine},
    },

    [TRAINER_PRYCE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_LEADER_PRYCE,
        .trainerName = _("PRYCE"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Pryce),
        .party = {.NoItemCustomMoves = sParty_Pryce},
    },

    [TRAINER_CLAIR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_CLAIR,
        .trainerName = _("CLAIR"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Clair),
        .party = {.NoItemCustomMoves = sParty_Clair},
    },

    [TRAINER_BROCK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("BROCK"),
        .items = {ITEM_HYPER_POTION , ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Brock),
        .party = {.NoItemCustomMoves = sParty_Brock},
    },

    [TRAINER_MISTY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("MISTY"),
        .items = {ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Misty),
        .party = {.NoItemCustomMoves = sParty_Misty},
    },

    [TRAINER_LT_SURGE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("LT. SURGE"),
        .items = {ITEM_HYPER_POTION , ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_LtSurge),
        .party = {.NoItemCustomMoves = sParty_LtSurge},
    },

    [TRAINER_ERIKA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("ERIKA"),
        .items = {ITEM_HYPER_POTION , ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Erika),
        .party = {.NoItemCustomMoves = sParty_Erika},
    },

    [TRAINER_JANINE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_JANINE,
        .trainerName = _("JANINE"),
        .items = {ITEM_DIRE_HIT, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Janine),
        .party = {.NoItemCustomMoves = sParty_Janine},
    },

    [TRAINER_SABRINA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("SABRINA"),
        .items = {ITEM_HYPER_POTION , ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Sabrina),
        .party = {.NoItemCustomMoves = sParty_Sabrina},
    },

    [TRAINER_BLAINE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("BLAINE"),
        .items = {ITEM_MAX_POTION , ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Blaine),
        .party = {.NoItemCustomMoves = sParty_Blaine},
    },

    [TRAINER_BLUE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("BLUE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Blue),
        .party = {.NoItemCustomMoves = sParty_Blue},
    },

    [TRAINER_WILL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_WILL,
        .trainerName = _("WILL"),
        .items = {ITEM_MAX_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Will),
        .party = {.NoItemCustomMoves = sParty_Will},
    },

    [TRAINER_KOGA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_KOGA,
        .trainerName = _("KOGA"),
        .items = {ITEM_FULL_HEAL, ITEM_MAX_POTION, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Koga),
        .party = {.NoItemCustomMoves = sParty_Koga},
    },

    [TRAINER_BRUNO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .trainerName = _("BRUNO"),
        .items = {ITEM_MAX_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Bruno),
        .party = {.NoItemCustomMoves = sParty_Bruno},
    },

    [TRAINER_KAREN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_KAREN,
        .trainerName = _("KAREN"),
        .items = {ITEM_FULL_HEAL, ITEM_MAX_POTION, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Karen),
        .party = {.NoItemCustomMoves = sParty_Karen},
    },

    [TRAINER_LANCE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_CHAMPION_LANCE,
        .trainerName = _("LANCE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Lance),
        .party = {.NoItemCustomMoves = sParty_Lance},
    },

    [TRAINER_CAL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_GOLD,
        .trainerName = _("CAL"),
        .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cal),
        .party = {.NoItemDefaultMoves = sParty_Cal},
    },

    [TRAINER_MT_SILVER_RED] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("RED"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MtSilverRed),
        .party = {.NoItemCustomMoves = sParty_MtSilverRed},
    },

    [TRAINER_RED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("RED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Red),
        .party = {.NoItemDefaultMoves = sParty_Red},
    },

    [TRAINER_LEAF] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEAF,
        .trainerName = _("LEAF"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Leaf),
        .party = {.NoItemDefaultMoves = sParty_Leaf},
    },

    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RS_BRENDAN,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_BrendanLinkPlaceholder),
        .party = {.NoItemDefaultMoves = sParty_BrendanLinkPlaceholder},
    },

    [TRAINER_MAY_PLACEHOLDER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RS_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_MayLinkPlaceholder),
        .party = {.NoItemDefaultMoves = sParty_MayLinkPlaceholder},
    },

    [TRAINER_ANABEL_FRONTIER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SALON_MAIDEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
        .trainerName = _("ANABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_AnabelFrontier),
        .party = {.NoItemDefaultMoves = sParty_AnabelFrontier},
    },

    [TRAINER_TUCKER_FRONTIER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DOME_ACE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_DOME_ACE_TUCKER,
        .trainerName = _("TUCKER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_TuckerFrontier),
        .party = {.NoItemDefaultMoves = sParty_TuckerFrontier},
    },

    [TRAINER_SPENSER_FRONTIER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PALACE_MAVEN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PALACE_MAVEN_SPENSER,
        .trainerName = _("SPENSER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_SpenserFrontier),
        .party = {.NoItemDefaultMoves = sParty_SpenserFrontier},
    },

    [TRAINER_GRETA_FRONTIER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_ARENA_TYCOON,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ARENA_TYCOON_GRETA,
        .trainerName = _("GRETA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_GretaFrontier),
        .party = {.NoItemDefaultMoves = sParty_GretaFrontier},
    },

    [TRAINER_NOLAND_FRONTIER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FACTORY_HEAD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FACTORY_HEAD_NOLAND,
        .trainerName = _("NOLAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_NolandFrontier),
        .party = {.NoItemDefaultMoves = sParty_NolandFrontier},
    },

    [TRAINER_LUCY_FRONTIER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PIKE_QUEEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PIKE_QUEEN_LUCY,
        .trainerName = _("LUCY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_LucyFrontier),
        .party = {.NoItemDefaultMoves = sParty_LucyFrontier},
    },

    [TRAINER_BRANDON_FRONTIER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PYRAMID_KING,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PYRAMID_KING_BRANDON,
        .trainerName = _("BRANDON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_BrandonFrontier),
        .party = {.NoItemDefaultMoves = sParty_BrandonFrontier},
    },
};
