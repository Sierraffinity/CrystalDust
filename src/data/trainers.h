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
        .party = {.NoItemDefaultMoves = sParty_Joey1}
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
        .party = {.NoItemDefaultMoves = sParty_Mikey}
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
        .party = {.NoItemDefaultMoves = sParty_Don}
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
        .partySize = ARRAY_COUNT(sParty_Liz1),
        .party = {.NoItemDefaultMoves = sParty_Liz1},
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
        .partySize = ARRAY_COUNT(sParty_Ralph1),
        .party = {.NoItemDefaultMoves = sParty_Ralph1},
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
        .partySize = ARRAY_COUNT(sParty_Anthony1),
        .party = {.NoItemDefaultMoves = sParty_Anthony1},
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

    [TRAINER_TODD_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Todd1),
        .party = {.NoItemDefaultMoves = sParty_Todd1},
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

    [TRAINER_GINA_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gina1),
        .party = {.NoItemDefaultMoves = sParty_Gina1},
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

    [TRAINER_ARNIE_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Arnie1),
        .party = {.NoItemDefaultMoves = sParty_Arnie1},
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

    [TRAINER_JACK_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jack1),
        .party = {.NoItemDefaultMoves = sParty_Jack1},
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

    [TRAINER_ALAN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alan1),
        .party = {.NoItemDefaultMoves = sParty_Alan1},
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
        .trainerPic = TRAINER_PIC_KIMONO_GIRL_FLAREON,
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
        .trainerPic = TRAINER_PIC_KIMONO_GIRL_ESPEON,
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
        .trainerPic = TRAINER_PIC_KIMONO_GIRL_UMBREON,
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
        .trainerPic = TRAINER_PIC_KIMONO_GIRL_VAPOREON,
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
        .trainerPic = TRAINER_PIC_KIMONO_GIRL_JOLTEON,
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
        .trainerPic = TRAINER_PIC_MEDIUM,
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
        .trainerPic = TRAINER_PIC_MEDIUM,
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

    [TRAINER_DANA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dana1),
        .party = {.NoItemCustomMoves = sParty_Dana1},
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

    [TRAINER_CHAD_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chad1),
        .party = {.NoItemDefaultMoves = sParty_Chad1},
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

    [TRAINER_HUEY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Huey1),
        .party = {.NoItemDefaultMoves = sParty_Huey1},
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

    [TRAINER_TULLY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TULLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tully1),
        .party = {.NoItemDefaultMoves = sParty_Tully1},
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

    [TRAINER_TIFFANY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tiffany1),
        .party = {.NoItemCustomMoves = sParty_Tiffany1},
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

    [TRAINER_BRENT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brent1),
        .party = {.NoItemDefaultMoves = sParty_Brent1},
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
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET_EXECUTIVE,
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
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET_EXECUTIVE,
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

    [TRAINER_WILTON_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wilton1),
        .party = {.NoItemDefaultMoves = sParty_Wilton1},
    },

    [TRAINER_VANCE_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Vance1),
        .party = {.NoItemDefaultMoves = sParty_Vance1},
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

    [TRAINER_PARRY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Parry1),
        .party = {.NoItemDefaultMoves = sParty_Parry1},
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

    [TRAINER_ERIN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Erin1),
        .party = {.NoItemDefaultMoves = sParty_Erin1},
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


    [TRAINER_JOSE_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jose1),
        .party = {.NoItemDefaultMoves = sParty_Jose1},
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

    [TRAINER_REENA_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("REENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Reena1),
        .party = {.NoItemDefaultMoves = sParty_Reena1},
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

    [TRAINER_GAVEN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Gaven1),
        .party = {.NoItemCustomMoves = sParty_Gaven1},
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

    [TRAINER_BETH_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Beth1),
        .party = {.NoItemCustomMoves = sParty_Beth1},
    },

    [TRAINER_DANNY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("DANNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Danny),
        .party = {.NoItemDefaultMoves = sParty_Danny},
    },

    [TRAINER_QUINN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("QUINN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Quinn),
        .party = {.NoItemDefaultMoves = sParty_Quinn},
    },

    [TRAINER_ROB] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ROB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rob),
        .party = {.NoItemDefaultMoves = sParty_Rob}
    },

    [TRAINER_DOUG] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DOUG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Doug),
        .party = {.NoItemDefaultMoves = sParty_Doug}
    },

    [TRAINER_ED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ed),
        .party = {.NoItemDefaultMoves = sParty_Ed}
    },

    [TRAINER_WARREN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("WARREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Warren),
        .party = {.NoItemDefaultMoves = sParty_Warren}
    },

    [TRAINER_JIMMY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JIMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jimmy),
        .party = {.NoItemDefaultMoves = sParty_Jimmy}
    },

    [TRAINER_OTIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("OTIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Otis),
        .party = {.NoItemDefaultMoves = sParty_Otis},
    },

    [TRAINER_BURT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("BURT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Burt),
        .party = {.NoItemDefaultMoves = sParty_Burt},
    },

    [TRAINER_HOPE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("HOPE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hope),
        .party = {.NoItemDefaultMoves = sParty_Hope},
    },

    [TRAINER_HANK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HANK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hank),
        .party = {.NoItemDefaultMoves = sParty_Hank},
    },

    [TRAINER_SHARON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("SHARON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sharon),
        .party = {.NoItemDefaultMoves = sParty_Sharon},
    },

    [TRAINER_REX] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("REX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rex),
        .party = {.ItemDefaultMoves = sParty_Rex},
    },

    [TRAINER_ALLAN] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("ALLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Allan),
        .party = {.ItemDefaultMoves = sParty_Allan},
    },

    [TRAINER_DWAYNE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("DWAYNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dwayne),
        .party = {.NoItemDefaultMoves = sParty_Dwayne},
    },

    [TRAINER_HARRIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("HARRIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Harris),
        .party = {.NoItemDefaultMoves = sParty_Harris},
    },

    [TRAINER_ZEKE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("ZEKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Zeke),
        .party = {.NoItemDefaultMoves = sParty_Zeke},
    },

    [TRAINER_SAM] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("SAM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sam),
        .party = {.NoItemDefaultMoves = sParty_Sam},
    },

    [TRAINER_TOM] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("TOM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tom),
        .party = {.NoItemDefaultMoves = sParty_Tom},
    },

    [TRAINER_EDNA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("EDNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edna),
        .party = {.NoItemDefaultMoves = sParty_Edna},
    },

    [TRAINER_SID] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("SID"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sid),
        .party = {.NoItemDefaultMoves = sParty_Sid},
    },

    [TRAINER_DEAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("DEAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dean),
        .party = {.NoItemDefaultMoves = sParty_Dean},
    },

    [TRAINER_TIM] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TIM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tim),
        .party = {.NoItemDefaultMoves = sParty_Tim},
    },

    [TRAINER_HEIDI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("HEIDI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Heidi),
        .party = {.NoItemDefaultMoves = sParty_Heidi},
    },

    [TRAINER_SIDNEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SIDNEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sidney),
        .party = {.NoItemDefaultMoves = sParty_Sidney},
    },

    [TRAINER_ROBERT] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Robert),
        .party = {.ItemDefaultMoves = sParty_Robert},
    },

    [TRAINER_JIM] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("JIM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jim),
        .party = {.NoItemDefaultMoves = sParty_Jim},
    },

    [TRAINER_FIDEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("FIDEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Fidel),
        .party = {.NoItemDefaultMoves = sParty_Fidel},
    },

    [TRAINER_JASON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JASON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jason),
        .party = {.NoItemDefaultMoves = sParty_Jason}
    },

    [TRAINER_OWEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("OWEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Owen),
        .party = {.NoItemDefaultMoves = sParty_Owen}
    },

    [TRAINER_HERMAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("HERMAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Herman),
        .party = {.NoItemDefaultMoves = sParty_Herman},
    },

    [TRAINER_KYLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("KYLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kyle),
        .party = {.NoItemDefaultMoves = sParty_Kyle},
    },

    [TRAINER_MARTIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("MARTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Martin),
        .party = {.NoItemDefaultMoves = sParty_Martin},
    },

    [TRAINER_STEPHEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("STEPHEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Stephen),
        .party = {.NoItemDefaultMoves = sParty_Stephen},
    },

    [TRAINER_BARNEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("BARNEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Barney),
        .party = {.NoItemDefaultMoves = sParty_Barney},
    },

    [TRAINER_BRET] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BRET"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bret),
        .party = {.NoItemDefaultMoves = sParty_Bret},
    },

    [TRAINER_PERRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Perry),
        .party = {.NoItemDefaultMoves = sParty_Perry},
    },

    [TRAINER_JOSHUA] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("JOSHUA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joshua),
        .party = {.ItemDefaultMoves = sParty_Joshua},
    },

    [TRAINER_ALEX] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("ALEX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alex),
        .party = {.ItemDefaultMoves = sParty_Alex},
    },

    [TRAINER_KENNY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("KENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kenny),
        .party = {.NoItemDefaultMoves = sParty_Kenny},
    },

    [TRAINER_ROY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Roy),
        .party = {.NoItemDefaultMoves = sParty_Roy},
    },

    [TRAINER_CARTER] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("CARTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Carter),
        .party = {.ItemDefaultMoves = sParty_Carter},
    },

    [TRAINER_TREVOR] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("TREVOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Trevor),
        .party = {.ItemDefaultMoves = sParty_Trevor},
    },

    [TRAINER_KIPP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("KIPP"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kipp),
        .party = {.NoItemDefaultMoves = sParty_Kipp},
    },

    [TRAINER_TOMMY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("TOMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tommy),
        .party = {.NoItemDefaultMoves = sParty_Tommy},
    },

    [TRAINER_HILLARY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEACHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_TEACHER,
        .trainerName = _("HILLARY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hillary),
        .party = {.NoItemDefaultMoves = sParty_Hillary},
    },

    [TRAINER_BILLY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("BILLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Billy),
        .party = {.NoItemDefaultMoves = sParty_Billy},
    },

    [TRAINER_COLETTE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEACHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_TEACHER,
        .trainerName = _("COLETTE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Colette),
        .party = {.NoItemDefaultMoves = sParty_Colette},
    },

    [TRAINER_JOHNNY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JOHNNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Johnny),
        .party = {.NoItemDefaultMoves = sParty_Johnny},
    },

    [TRAINER_RILEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("RILEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Riley),
        .party = {.NoItemDefaultMoves = sParty_Riley},
    },

    [TRAINER_GLENN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("GLENN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Glenn),
        .party = {.NoItemDefaultMoves = sParty_Glenn},
    },

    [TRAINER_JOEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("JOEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joel),
        .party = {.NoItemDefaultMoves = sParty_Joel},
    },

    [TRAINER_CHARLES] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("CHARLES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Charles),
        .party = {.NoItemDefaultMoves = sParty_Charles},
    },

    [TRAINER_BOB] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bob),
        .party = {.NoItemDefaultMoves = sParty_Bob},
    },

    [TRAINER_BORIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BORIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Boris),
        .party = {.NoItemDefaultMoves = sParty_Boris},
    },

    [TRAINER_HAROLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("HAROLD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Harold),
        .party = {.NoItemDefaultMoves = sParty_Harold},
    },

    [TRAINER_TUCKER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("TUCKER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tucker),
        .party = {.NoItemDefaultMoves = sParty_Tucker},
    },

    [TRAINER_DAWN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DAWN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dawn),
        .party = {.NoItemDefaultMoves = sParty_Dawn},
    },

    [TRAINER_JEROME] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("JEROME"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerome),
        .party = {.NoItemDefaultMoves = sParty_Jerome},
    },

    [TRAINER_CAMERON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cameron),
        .party = {.NoItemDefaultMoves = sParty_Cameron},
    },

    [TRAINER_LORI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("LORI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lori),
        .party = {.NoItemDefaultMoves = sParty_Lori},
    },

    [TRAINER_NICOLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NICOLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nicole),
        .party = {.NoItemDefaultMoves = sParty_Nicole},
    },

    [TRAINER_NIKKI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NIKKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nikki),
        .party = {.NoItemDefaultMoves = sParty_Nikki},
    },

    [TRAINER_ARNOLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ARNOLD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Arnold),
        .party = {.NoItemDefaultMoves = sParty_Arnold},
    },

    [TRAINER_SETH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Seth),
        .party = {.NoItemDefaultMoves = sParty_Seth},
    },

    [TRAINER_DUDLEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("DUDLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dudley),
        .party = {.NoItemDefaultMoves = sParty_Dudley},
    },

    [TRAINER_ELLEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ELLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ellen),
        .party = {.NoItemDefaultMoves = sParty_Ellen},
    },

    [TRAINER_JOE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JOE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joe),
        .party = {.NoItemDefaultMoves = sParty_Joe},
    },

    [TRAINER_LAURA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("LAURA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Laura),
        .party = {.NoItemDefaultMoves = sParty_Laura},
    },

    [TRAINER_LLOYD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("LLOYD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lloyd),
        .party = {.NoItemDefaultMoves = sParty_Lloyd},
    },

    [TRAINER_SHANNON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("SHANNON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Shannon),
        .party = {.NoItemDefaultMoves = sParty_Shannon},
    },

    [TRAINER_PAT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("PAT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pat),
        .party = {.NoItemDefaultMoves = sParty_Pat},
    },

    [TRAINER_KEVIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("KEVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Kevin),
        .party = {.NoItemDefaultMoves = sParty_Kevin},
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
        .trainerPic = TRAINER_PIC_MEDIUM,
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
        .trainerPic = TRAINER_PIC_MEDIUM,
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

    [TRAINER_JOEY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joey2),
        .party = {.NoItemDefaultMoves = sParty_Joey2}
    },

    [TRAINER_JOEY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joey3),
        .party = {.NoItemCustomMoves = sParty_Joey3}
    },

    [TRAINER_JOEY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joey4),
        .party = {.NoItemCustomMoves = sParty_Joey4}
    },

    [TRAINER_JOEY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joey5),
        .party = {.NoItemCustomMoves = sParty_Joey5}
    },

    [TRAINER_WADE_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wade2),
        .party = {.NoItemDefaultMoves = sParty_Wade2},
    },

    [TRAINER_WADE_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wade3),
        .party = {.NoItemDefaultMoves = sParty_Wade3},
    },

    [TRAINER_WADE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wade4),
        .party = {.NoItemCustomMoves = sParty_Wade4},
    },

    [TRAINER_WADE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wade5),
        .party = {.NoItemCustomMoves = sParty_Wade5},
    },

    [TRAINER_LIZ_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Liz2),
        .party = {.NoItemDefaultMoves = sParty_Liz2},
    },

    [TRAINER_LIZ_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Liz3),
        .party = {.NoItemDefaultMoves = sParty_Liz3},
    },

    [TRAINER_LIZ_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Liz4),
        .party = {.NoItemDefaultMoves = sParty_Liz4},
    },

    [TRAINER_LIZ_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Liz5),
        .party = {.NoItemCustomMoves = sParty_Liz5},
    },

    [TRAINER_RALPH_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ralph2),
        .party = {.NoItemDefaultMoves = sParty_Ralph2},
    },

    [TRAINER_RALPH_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ralph3),
        .party = {.NoItemDefaultMoves = sParty_Ralph3},
    },

    [TRAINER_RALPH_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ralph4),
        .party = {.NoItemDefaultMoves = sParty_Ralph4},
    },

    [TRAINER_RALPH_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ralph5),
        .party = {.NoItemCustomMoves = sParty_Ralph5},
    },

    [TRAINER_ANTHONY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Anthony2),
        .party = {.NoItemDefaultMoves = sParty_Anthony2},
    },

    [TRAINER_ANTHONY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Anthony3),
        .party = {.NoItemDefaultMoves = sParty_Anthony3},
    },

    [TRAINER_ANTHONY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Anthony4),
        .party = {.NoItemDefaultMoves = sParty_Anthony4},
    },

    [TRAINER_ANTHONY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Anthony5),
        .party = {.NoItemCustomMoves = sParty_Anthony5},
    },

    [TRAINER_TODD_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Todd2),
        .party = {.NoItemDefaultMoves = sParty_Todd2},
    },

    [TRAINER_TODD_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Todd3),
        .party = {.NoItemDefaultMoves = sParty_Todd3},
    },

    [TRAINER_TODD_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Todd4),
        .party = {.NoItemDefaultMoves = sParty_Todd4},
    },

    [TRAINER_TODD_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Todd5),
        .party = {.NoItemCustomMoves = sParty_Todd5},
    },

    [TRAINER_GINA_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gina2),
        .party = {.NoItemDefaultMoves = sParty_Gina2},
    },

    [TRAINER_GINA_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gina3),
        .party = {.NoItemDefaultMoves = sParty_Gina3},
    },

    [TRAINER_GINA_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gina4),
        .party = {.NoItemDefaultMoves = sParty_Gina4},
    },

    [TRAINER_GINA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gina5),
        .party = {.NoItemCustomMoves = sParty_Gina5},
    },

    [TRAINER_ARNIE_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Arnie2),
        .party = {.NoItemDefaultMoves = sParty_Arnie2},
    },

    [TRAINER_ARNIE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Arnie3),
        .party = {.NoItemCustomMoves = sParty_Arnie3},
    },

    [TRAINER_ARNIE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Arnie4),
        .party = {.NoItemCustomMoves = sParty_Arnie4},
    },

    [TRAINER_ARNIE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Arnie5),
        .party = {.NoItemCustomMoves = sParty_Arnie5},
    },

    [TRAINER_JACK_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jack2),
        .party = {.NoItemDefaultMoves = sParty_Jack2},
    },

    [TRAINER_JACK_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jack3),
        .party = {.NoItemDefaultMoves = sParty_Jack3},
    },

    [TRAINER_JACK_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jack4),
        .party = {.NoItemDefaultMoves = sParty_Jack4},
    },

    [TRAINER_JACK_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jack5),
        .party = {.NoItemCustomMoves = sParty_Jack5},
    },

    [TRAINER_ALAN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alan2),
        .party = {.NoItemDefaultMoves = sParty_Alan2},
    },

    [TRAINER_ALAN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alan3),
        .party = {.NoItemDefaultMoves = sParty_Alan3},
    },

    [TRAINER_ALAN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alan4),
        .party = {.NoItemDefaultMoves = sParty_Alan4},
    },

    [TRAINER_ALAN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alan5),
        .party = {.NoItemCustomMoves = sParty_Alan5},
    },

    [TRAINER_DANA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dana2),
        .party = {.NoItemCustomMoves = sParty_Dana2},
    },

    [TRAINER_DANA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dana3),
        .party = {.NoItemCustomMoves = sParty_Dana3},
    },

    [TRAINER_DANA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dana4),
        .party = {.NoItemCustomMoves = sParty_Dana4},
    },

    [TRAINER_DANA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dana5),
        .party = {.NoItemCustomMoves = sParty_Dana5},
    },

    [TRAINER_CHAD_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chad2),
        .party = {.NoItemDefaultMoves = sParty_Chad2},
    },

    [TRAINER_CHAD_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chad3),
        .party = {.NoItemDefaultMoves = sParty_Chad3},
    },

    [TRAINER_CHAD_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chad4),
        .party = {.NoItemDefaultMoves = sParty_Chad4},
    },

    [TRAINER_CHAD_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chad5),
        .party = {.NoItemCustomMoves = sParty_Chad5},
    },

    [TRAINER_HUEY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Huey2),
        .party = {.NoItemDefaultMoves = sParty_Huey2},
    },

    [TRAINER_HUEY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Huey3),
        .party = {.NoItemDefaultMoves = sParty_Huey3},
    },

    [TRAINER_HUEY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Huey4),
        .party = {.NoItemCustomMoves = sParty_Huey4},
    },

    [TRAINER_TULLY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TULLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tully2),
        .party = {.NoItemDefaultMoves = sParty_Tully2},
    },

    [TRAINER_TULLY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TULLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tully3),
        .party = {.NoItemDefaultMoves = sParty_Tully3},
    },

    [TRAINER_TULLY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TULLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tully4),
        .party = {.NoItemCustomMoves = sParty_Tully4},
    },

    [TRAINER_TIFFANY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tiffany2),
        .party = {.NoItemCustomMoves = sParty_Tiffany2},
    },

    [TRAINER_TIFFANY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tiffany3),
        .party = {.NoItemCustomMoves = sParty_Tiffany3},
    },

    [TRAINER_TIFFANY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tiffany4),
        .party = {.NoItemCustomMoves = sParty_Tiffany4},
    },

    [TRAINER_BRENT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brent2),
        .party = {.NoItemDefaultMoves = sParty_Brent2},
    },

    [TRAINER_BRENT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brent3),
        .party = {.NoItemDefaultMoves = sParty_Brent3},
    },

    [TRAINER_BRENT_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brent4),
        .party = {.NoItemCustomMoves = sParty_Brent4},
    },

    [TRAINER_WILTON_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wilton2),
        .party = {.NoItemDefaultMoves = sParty_Wilton2},
    },

    [TRAINER_WILTON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wilton3),
        .party = {.NoItemCustomMoves = sParty_Wilton3},
    },

    [TRAINER_VANCE_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Vance2),
        .party = {.NoItemDefaultMoves = sParty_Vance2},
    },

    [TRAINER_VANCE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Vance3),
        .party = {.NoItemCustomMoves = sParty_Vance3},
    },

    [TRAINER_PARRY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Parry2),
        .party = {.NoItemDefaultMoves = sParty_Parry2},
    },

    [TRAINER_PARRY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Parry3),
        .party = {.NoItemCustomMoves = sParty_Parry3},
    },

    [TRAINER_ERIN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Erin2),
        .party = {.NoItemDefaultMoves = sParty_Erin2},
    },

    [TRAINER_ERIN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Erin3),
        .party = {.NoItemCustomMoves = sParty_Erin3},
    },

    [TRAINER_JOSE_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jose2),
        .party = {.NoItemDefaultMoves = sParty_Jose2},
    },

    [TRAINER_JOSE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jose3),
        .party = {.NoItemCustomMoves = sParty_Jose3},
    },

    [TRAINER_REENA_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("REENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Reena2),
        .party = {.NoItemDefaultMoves = sParty_Reena2},
    },

    [TRAINER_REENA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("REENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Reena3),
        .party = {.ItemCustomMoves = sParty_Reena3},
    },

    [TRAINER_GAVEN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Gaven2),
        .party = {.NoItemCustomMoves = sParty_Gaven2},
    },

    [TRAINER_GAVEN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Gaven3),
        .party = {.ItemCustomMoves = sParty_Gaven3},
    },

    [TRAINER_BETH_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Beth2),
        .party = {.NoItemCustomMoves = sParty_Beth2},
    },

    [TRAINER_BETH_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Beth3),
        .party = {.ItemCustomMoves = sParty_Beth3},
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
        .party = {.NoItemDefaultMoves = sParty_Ken}
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
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
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
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
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
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL1,
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
        .trainerClass = TRAINER_CLASS_RIVAL2,
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
        .trainerClass = TRAINER_CLASS_RIVAL2,
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
        .trainerClass = TRAINER_CLASS_RIVAL2,
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
        .trainerClass = TRAINER_CLASS_RIVAL2,
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
        .trainerClass = TRAINER_CLASS_RIVAL2,
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
        .trainerClass = TRAINER_CLASS_RIVAL2,
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
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET_EXECUTIVE,
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
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET_EXECUTIVE,
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
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET_EXECUTIVE,
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
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET_EXECUTIVE,
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
        .trainerPic = TRAINER_PIC_LEADER_BLUE,
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
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_2,
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
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("RED"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MtSilverRed),
        .party = {.NoItemCustomMoves = sParty_MtSilverRed},
    },

    [TRAINER_NATHAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("NATHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nathan),
        .party = {.NoItemDefaultMoves = sParty_Nathan},
    },

    [TRAINER_ROCKET_EXEC_PARTNER] = 
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RocketExecPartner),
        .party = {.NoItemDefaultMoves = sParty_RocketExecPartner},
    },

    [TRAINER_DANE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DANE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dane),
        .party = {.NoItemDefaultMoves = sParty_Dane}
    },

    [TRAINER_DION] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DION"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dion),
        .party = {.NoItemDefaultMoves = sParty_Dion}
    },

    [TRAINER_STACEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("STACEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Stacey),
        .party = {.NoItemDefaultMoves = sParty_Stacey}
    },

    [TRAINER_ELLIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ELLIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ellis),
        .party = {.NoItemDefaultMoves = sParty_Ellis}
    },

    [TRAINER_ABNER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ABNER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Abner),
        .party = {.NoItemDefaultMoves = sParty_Abner}
    },

    [TRAINER_REGIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("REGIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Regis),
        .party = {.NoItemDefaultMoves = sParty_Regis}
    },

    [TRAINER_ZAC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("ZAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Zac),
        .party = {.NoItemDefaultMoves = sParty_Zac},
    },

    [TRAINER_JEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jen),
        .party = {.NoItemDefaultMoves = sParty_Jen},
    },

    [TRAINER_BRUCE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BRUCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bruce),
        .party = {.NoItemDefaultMoves = sParty_Bruce},
    },

    [TRAINER_MANFORD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("MANFORD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Manford),
        .party = {.NoItemDefaultMoves = sParty_Manford},
    },

    [TRAINER_ANDER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("ANDER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ander),
        .party = {.NoItemDefaultMoves = sParty_Ander},
    },

    [TRAINER_DWIGHT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DWIGHT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dwight),
        .party = {.NoItemDefaultMoves = sParty_Dwight},
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

    [TRAINER_PETEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("PETEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Petey),
        .party = {.NoItemDefaultMoves = sParty_Petey},
    },

    [TRAINER_EDD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("EDD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edd),
        .party = {.NoItemDefaultMoves = sParty_Edd},
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
