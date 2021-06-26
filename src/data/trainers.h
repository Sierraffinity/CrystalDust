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

    [TRAINER_AUTUMN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("AUTUMN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Autumn),
        .party = {.NoItemDefaultMoves = sParty_Autumn},
    },

    [TRAINER_TRAVIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TRAVIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Travis),
        .party = {.NoItemDefaultMoves = sParty_Travis},
    },

    [TRAINER_ETHAN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ethan2),
        .party = {.NoItemDefaultMoves = sParty_Ethan2},
    },

    [TRAINER_ETHAN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ethan3),
        .party = {.NoItemDefaultMoves = sParty_Ethan3},
    },

    [TRAINER_ETHAN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ethan4),
        .party = {.NoItemDefaultMoves = sParty_Ethan4},
    },

    [TRAINER_ETHAN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ethan5),
        .party = {.NoItemDefaultMoves = sParty_Ethan5},
    },

    [TRAINER_BRENT_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("BRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brent_Old),
        .party = {.NoItemDefaultMoves = sParty_Brent_Old},
    },

    [TRAINER_DONALD_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DONALD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_DonaldOld),
        .party = {.NoItemDefaultMoves = sParty_DonaldOld},
    },

    [TRAINER_TAYLOR] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("TAYLOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Taylor),
        .party = {.NoItemDefaultMoves = sParty_Taylor},
    },

    [TRAINER_JEFFREY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey1),
        .party = {.NoItemDefaultMoves = sParty_Jeffrey1},
    },

    [TRAINER_DEREK_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DEREK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Derek_Old),
        .party = {.NoItemDefaultMoves = sParty_Derek_Old},
    },

    [TRAINER_JEFFREY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey2),
        .party = {.NoItemDefaultMoves = sParty_Jeffrey2},
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

    [TRAINER_EDWARD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("EDWARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edward),
        .party = {.NoItemCustomMoves = sParty_Edward},
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

    [TRAINER_BLAKE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("BLAKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Blake),
        .party = {.NoItemDefaultMoves = sParty_Blake},
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

    [TRAINER_SIDNEY] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_SIDNEY,
        .trainerName = _("SIDNEY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Sidney),
        .party = {.ItemCustomMoves = sParty_Sidney},
    },

    [TRAINER_PHOEBE] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_PHOEBE,
        .trainerName = _("PHOEBE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Phoebe),
        .party = {.ItemCustomMoves = sParty_Phoebe},
    },

    [TRAINER_GLACIA] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_GLACIA,
        .trainerName = _("GLACIA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Glacia),
        .party = {.ItemCustomMoves = sParty_Glacia},
    },

    [TRAINER_DRAKE] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_DRAKE,
        .trainerName = _("DRAKE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Drake),
        .party = {.ItemCustomMoves = sParty_Drake},
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
        .trainerPic = TRAINER_PIC_LEADER_JASMINE,
        .trainerName = _("CLAIR"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_HEAL, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Clair),
        .party = {.NoItemCustomMoves = sParty_Clair},
    },

    [TRAINER_JERRY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry1),
        .party = {.NoItemDefaultMoves = sParty_Jerry1},
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

    [TRAINER_JERRY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry2),
        .party = {.NoItemDefaultMoves = sParty_Jerry2},
    },

    [TRAINER_JERRY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry3),
        .party = {.NoItemDefaultMoves = sParty_Jerry3},
    },

    [TRAINER_JERRY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry4),
        .party = {.NoItemDefaultMoves = sParty_Jerry4},
    },

    [TRAINER_JERRY_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jerry5),
        .party = {.NoItemDefaultMoves = sParty_Jerry5},
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

    [TRAINER_GEORGIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("GEORGIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Georgia),
        .party = {.NoItemDefaultMoves = sParty_Georgia},
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

    [TRAINER_TIMOTHY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Timothy1),
        .party = {.NoItemDefaultMoves = sParty_Timothy1},
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

    [TRAINER_SHELBY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Shelby4),
        .party = {.NoItemDefaultMoves = sParty_Shelby4},
    },

    [TRAINER_SHELBY_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Shelby5),
        .party = {.NoItemDefaultMoves = sParty_Shelby5},
    },

    [TRAINER_CALVIN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Calvin1),
        .party = {.NoItemDefaultMoves = sParty_Calvin1},
    },

    [TRAINER_BILLY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("BILLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Billy),
        .party = {.NoItemDefaultMoves = sParty_Billy},
    },

    [TRAINER_JOSH_OLD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOSH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_JoshOld),
        .party = {.NoItemCustomMoves = sParty_JoshOld},
    },

    [TRAINER_TOMMY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("TOMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tommy),
        .party = {.NoItemDefaultMoves = sParty_Tommy},
    },

    [TRAINER_JOEYOLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_JoeyOld),
        .party = {.NoItemDefaultMoves = sParty_JoeyOld }
    },

    [TRAINER_BEN_OLD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("BEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ben_Old),
        .party = {.NoItemCustomMoves = sParty_Ben_Old},
    },

    [TRAINER_QUINCY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("QUINCY"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Quincy),
        .party = {.NoItemCustomMoves = sParty_Quincy},
    },

    [TRAINER_KATELYNN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("KATELYNN"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Katelynn),
        .party = {.NoItemCustomMoves = sParty_Katelynn},
    },

    [TRAINER_JAYLEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JAYLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jaylen),
        .party = {.NoItemDefaultMoves = sParty_Jaylen},
    },

    [TRAINER_DILLON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DILLON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dillon),
        .party = {.NoItemDefaultMoves = sParty_Dillon},
    },

    [TRAINER_CALVIN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Calvin2),
        .party = {.NoItemDefaultMoves = sParty_Calvin2},
    },

    [TRAINER_CALVIN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Calvin3),
        .party = {.NoItemDefaultMoves = sParty_Calvin3},
    },

    [TRAINER_CALVIN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Calvin4),
        .party = {.NoItemDefaultMoves = sParty_Calvin4},
    },

    [TRAINER_CALVIN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Calvin5),
        .party = {.NoItemDefaultMoves = sParty_Calvin5},
    },

    [TRAINER_EDDIE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("EDDIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Eddie_Old),
        .party = {.NoItemDefaultMoves = sParty_Eddie_Old},
    },

    [TRAINER_ALLEN_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("ALLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Allen_Old),
        .party = {.NoItemDefaultMoves = sParty_Allen_Old},
    },

    [TRAINER_TIMMY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("TIMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Timmy),
        .party = {.NoItemDefaultMoves = sParty_Timmy},
    },

    [TRAINER_WALLACE] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_WALLACE,
        .trainerName = _("WALLACE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Wallace),
        .party = {.ItemCustomMoves = sParty_Wallace},
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

    [TRAINER_KATELYN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Katelyn4),
        .party = {.NoItemDefaultMoves = sParty_Katelyn4},
    },

    [TRAINER_KATELYN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Katelyn5),
        .party = {.NoItemDefaultMoves = sParty_Katelyn5},
    },

    [TRAINER_NICOLAS_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nicolas1),
        .party = {.NoItemDefaultMoves = sParty_Nicolas1},
    },

    [TRAINER_NICOLAS_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nicolas2),
        .party = {.NoItemDefaultMoves = sParty_Nicolas2},
    },

    [TRAINER_NICOLAS_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nicolas3),
        .party = {.NoItemDefaultMoves = sParty_Nicolas3},
    },

    [TRAINER_NICOLAS_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nicolas4),
        .party = {.NoItemDefaultMoves = sParty_Nicolas4},
    },

    [TRAINER_NICOLAS_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nicolas5),
        .party = {.ItemDefaultMoves = sParty_Nicolas5},
    },

    [TRAINER_AARON_OLD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("AARON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Aaron_Old),
        .party = {.NoItemCustomMoves = sParty_Aaron_Old},
    },

    [TRAINER_PERRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Perry),
        .party = {.NoItemDefaultMoves = sParty_Perry},
    },

    [TRAINER_HUGH_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HUGH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hugh_Old),
        .party = {.NoItemDefaultMoves = sParty_Hugh_Old},
    },

    [TRAINER_PHIL_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PHIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Phil_Old),
        .party = {.NoItemDefaultMoves = sParty_Phil_Old},
    },

    [TRAINER_JARED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JARED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jared),
        .party = {.NoItemDefaultMoves = sParty_Jared},
    },

    [TRAINER_HUMBERTO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HUMBERTO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Humberto),
        .party = {.NoItemDefaultMoves = sParty_Humberto},
    },

    [TRAINER_PRESLEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PRESLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Presley),
        .party = {.NoItemDefaultMoves = sParty_Presley},
    },

    [TRAINER_EDWARDO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("EDWARDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edwardo),
        .party = {.NoItemDefaultMoves = sParty_Edwardo},
    },

    [TRAINER_COLIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("COLIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Colin),
        .party = {.NoItemDefaultMoves = sParty_Colin},
    },

    [TRAINER_ROBERT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Robert1),
        .party = {.NoItemDefaultMoves = sParty_Robert1},
    },

    [TRAINER_BENNY_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BennyOld),
        .party = {.NoItemDefaultMoves = sParty_BennyOld},
    },

    [TRAINER_CHESTER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("CHESTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chester),
        .party = {.NoItemDefaultMoves = sParty_Chester},
    },

    [TRAINER_ROBERT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Robert2),
        .party = {.NoItemDefaultMoves = sParty_Robert2},
    },

    [TRAINER_ROBERT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Robert3),
        .party = {.NoItemDefaultMoves = sParty_Robert3},
    },

    [TRAINER_ROBERT_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Robert4),
        .party = {.NoItemDefaultMoves = sParty_Robert4},
    },

    [TRAINER_ROBERT_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Robert5),
        .party = {.NoItemDefaultMoves = sParty_Robert5},
    },

    [TRAINER_ALEX] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ALEX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alex),
        .party = {.NoItemDefaultMoves = sParty_Alex},
    },

    [TRAINER_BECK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BECK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Beck),
        .party = {.NoItemDefaultMoves = sParty_Beck},
    },

    [TRAINER_YASU] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("YASU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Yasu),
        .party = {.NoItemDefaultMoves = sParty_Yasu},
    },

    [TRAINER_TAKASHI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("TAKASHI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Takashi),
        .party = {.NoItemDefaultMoves = sParty_Takashi},
    },

    [TRAINER_DIANNE] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("DIANNE"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Dianne),
        .party = {.ItemCustomMoves = sParty_Dianne},
    },

    [TRAINER_JANI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("JANI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Jani),
        .party = {.NoItemDefaultMoves = sParty_Jani},
    },

    [TRAINER_LAO_OLD_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Lao1),
        .party = {.NoItemCustomMoves = sParty_Lao1},
    },

    [TRAINER_LUNG_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LUNG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Lung_Old),
        .party = {.NoItemDefaultMoves = sParty_Lung_Old},
    },

    [TRAINER_LAO_OLD_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Lao2),
        .party = {.NoItemCustomMoves = sParty_Lao2},
    },

    [TRAINER_LAO_OLD_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Lao3),
        .party = {.NoItemCustomMoves = sParty_Lao3},
    },

    [TRAINER_LAO_OLD_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Lao4),
        .party = {.NoItemCustomMoves = sParty_Lao4},
    },

    [TRAINER_LAO_OLD_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Lao5),
        .party = {.ItemCustomMoves = sParty_Lao5},
    },

    [TRAINER_JOCELYN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("JOCELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jocelyn),
        .party = {.NoItemDefaultMoves = sParty_Jocelyn},
    },

    [TRAINER_LAURA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("LAURA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Laura),
        .party = {.NoItemDefaultMoves = sParty_Laura},
    },

    [TRAINER_CYNDY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cyndy1),
        .party = {.NoItemDefaultMoves = sParty_Cyndy1},
    },

    [TRAINER_CORA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CORA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cora),
        .party = {.NoItemDefaultMoves = sParty_Cora},
    },

    [TRAINER_PAULA_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("PAULA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Paula_Old),
        .party = {.NoItemDefaultMoves = sParty_Paula_Old},
    },

    [TRAINER_CYNDY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cyndy2),
        .party = {.NoItemDefaultMoves = sParty_Cyndy2},
    },

    [TRAINER_CYNDY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cyndy3),
        .party = {.NoItemDefaultMoves = sParty_Cyndy3},
    },

    [TRAINER_CYNDY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cyndy4),
        .party = {.NoItemDefaultMoves = sParty_Cyndy4},
    },

    [TRAINER_CYNDY_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cyndy5),
        .party = {.NoItemDefaultMoves = sParty_Cyndy5},
    },

    [TRAINER_MADELINE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Madeline1),
        .party = {.NoItemCustomMoves = sParty_Madeline1},
    },

    [TRAINER_CLARISSA_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("CLARISSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Clarissa_Old),
        .party = {.NoItemDefaultMoves = sParty_Clarissa_Old},
    },

    [TRAINER_ANGELICA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("ANGELICA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Angelica),
        .party = {.NoItemCustomMoves = sParty_Angelica},
    },

    [TRAINER_MADELINE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Madeline2),
        .party = {.NoItemCustomMoves = sParty_Madeline2},
    },

    [TRAINER_MADELINE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Madeline3),
        .party = {.NoItemCustomMoves = sParty_Madeline3},
    },

    [TRAINER_MADELINE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Madeline4),
        .party = {.NoItemCustomMoves = sParty_Madeline4},
    },

    [TRAINER_MADELINE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Madeline5),
        .party = {.NoItemCustomMoves = sParty_Madeline5},
    },

    [TRAINER_BEVERLY_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BEVERLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BeverlyOld),
        .party = {.NoItemDefaultMoves = sParty_BeverlyOld},
    },

    [TRAINER_IMANI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("IMANI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Imani),
        .party = {.NoItemDefaultMoves = sParty_Imani},
    },

    [TRAINER_KYLA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KYLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kyla),
        .party = {.NoItemDefaultMoves = sParty_Kyla},
    },

    [TRAINER_DENISE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DENISE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Denise_Old),
        .party = {.NoItemDefaultMoves = sParty_Denise_Old},
    },

    [TRAINER_BETH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Beth),
        .party = {.NoItemDefaultMoves = sParty_Beth},
    },

    [TRAINER_TARA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TARA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tara),
        .party = {.NoItemDefaultMoves = sParty_Tara},
    },

    [TRAINER_MISSY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("MISSY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Missy),
        .party = {.NoItemDefaultMoves = sParty_Missy},
    },

    [TRAINER_ALICE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("ALICE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alice),
        .party = {.NoItemDefaultMoves = sParty_Alice},
    },

    [TRAINER_JENNY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jenny1),
        .party = {.NoItemDefaultMoves = sParty_Jenny1},
    },

    [TRAINER_GRACE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("GRACE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Grace_Old),
        .party = {.NoItemDefaultMoves = sParty_Grace_Old},
    },

    [TRAINER_TANYA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TANYA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tanya),
        .party = {.NoItemDefaultMoves = sParty_Tanya},
    },

    [TRAINER_SHARON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SHARON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sharon),
        .party = {.NoItemDefaultMoves = sParty_Sharon},
    },

    [TRAINER_NIKKI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NIKKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nikki),
        .party = {.NoItemDefaultMoves = sParty_Nikki},
    },

    [TRAINER_BRENDA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BRENDA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brenda),
        .party = {.NoItemDefaultMoves = sParty_Brenda},
    },

    [TRAINER_KATIE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KATIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Katie),
        .party = {.NoItemDefaultMoves = sParty_Katie},
    },

    [TRAINER_SUSIE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SUSIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Susie_Old),
        .party = {.NoItemDefaultMoves = sParty_Susie_Old},
    },

    [TRAINER_KARA_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KARA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kara_Old),
        .party = {.NoItemDefaultMoves = sParty_Kara_Old},
    },

    [TRAINER_DANA_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dana_Old),
        .party = {.NoItemDefaultMoves = sParty_Dana_Old},
    },

    [TRAINER_SIENNA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SIENNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sienna),
        .party = {.NoItemDefaultMoves = sParty_Sienna},
    },

    [TRAINER_DEBRA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DEBRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Debra),
        .party = {.NoItemDefaultMoves = sParty_Debra},
    },

    [TRAINER_LINDA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("LINDA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Linda),
        .party = {.NoItemDefaultMoves = sParty_Linda},
    },

    [TRAINER_KAYLEE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KAYLEE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kaylee_Old),
        .party = {.NoItemDefaultMoves = sParty_Kaylee_Old},
    },

    [TRAINER_LAUREL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("LAUREL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Laurel),
        .party = {.NoItemDefaultMoves = sParty_Laurel},
    },

    [TRAINER_CARLEE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("CARLEE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Carlee),
        .party = {.NoItemDefaultMoves = sParty_Carlee},
    },

    [TRAINER_JENNY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jenny2),
        .party = {.NoItemDefaultMoves = sParty_Jenny2},
    },

    [TRAINER_JENNY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jenny3),
        .party = {.NoItemDefaultMoves = sParty_Jenny3},
    },

    [TRAINER_JENNY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jenny4),
        .party = {.NoItemDefaultMoves = sParty_Jenny4},
    },

    [TRAINER_JENNY_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jenny5),
        .party = {.NoItemDefaultMoves = sParty_Jenny5},
    },

    [TRAINER_HEIDI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("HEIDI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Heidi),
        .party = {.NoItemCustomMoves = sParty_Heidi},
    },

    [TRAINER_BECKY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("BECKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Becky),
        .party = {.NoItemCustomMoves = sParty_Becky},
    },

    [TRAINER_CAROL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CAROL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Carol),
        .party = {.NoItemDefaultMoves = sParty_Carol},
    },

    [TRAINER_NANCY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("NANCY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nancy),
        .party = {.NoItemDefaultMoves = sParty_Nancy},
    },

    [TRAINER_MARTHA_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("MARTHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Martha_Old),
        .party = {.NoItemDefaultMoves = sParty_Martha_Old},
    },

    [TRAINER_DIANA_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Diana1),
        .party = {.NoItemDefaultMoves = sParty_Diana1},
    },

    [TRAINER_CEDRIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CEDRIC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cedric),
        .party = {.NoItemCustomMoves = sParty_Cedric},
    },

    [TRAINER_IRENE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("IRENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_IreneOld),
        .party = {.NoItemDefaultMoves = sParty_IreneOld},
    },

    [TRAINER_DIANA_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Diana2),
        .party = {.NoItemDefaultMoves = sParty_Diana2},
    },

    [TRAINER_DIANA_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Diana3),
        .party = {.NoItemDefaultMoves = sParty_Diana3},
    },

    [TRAINER_DIANA_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Diana4),
        .party = {.NoItemDefaultMoves = sParty_Diana4},
    },

    [TRAINER_DIANA_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Diana5),
        .party = {.NoItemDefaultMoves = sParty_Diana5},
    },

    [TRAINER_AMY_AND_LIV_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv1),
        .party = {.NoItemDefaultMoves = sParty_AmyAndLiv1},
    },

    [TRAINER_AMY_AND_LIV_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv2),
        .party = {.NoItemDefaultMoves = sParty_AmyAndLiv2},
    },

    [TRAINER_GINA_AND_MIA_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("GINA & MIA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GinaAndMia1),
        .party = {.NoItemDefaultMoves = sParty_GinaAndMia1},
    },

    [TRAINER_MIU_AND_YUKI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("MIU & YUKI"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_MiuAndYuki),
        .party = {.NoItemDefaultMoves = sParty_MiuAndYuki},
    },

    [TRAINER_AMY_AND_LIV_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv3),
        .party = {.NoItemDefaultMoves = sParty_AmyAndLiv3},
    },

    [TRAINER_GINA_AND_MIA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("GINA & MIA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GinaAndMia2),
        .party = {.NoItemCustomMoves = sParty_GinaAndMia2},
    },

    [TRAINER_AMY_AND_LIV_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv4),
        .party = {.NoItemDefaultMoves = sParty_AmyAndLiv4},
    },

    [TRAINER_AMY_AND_LIV_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv5),
        .party = {.NoItemCustomMoves = sParty_AmyAndLiv5},
    },

    [TRAINER_AMY_AND_LIV_6] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv6),
        .party = {.NoItemCustomMoves = sParty_AmyAndLiv6},
    },

    [TRAINER_HUEY_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Huey_Old),
        .party = {.NoItemDefaultMoves = sParty_Huey_Old},
    },

    [TRAINER_EDMOND_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("EDMOND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edmond_Old),
        .party = {.NoItemDefaultMoves = sParty_Edmond_Old},
    },

    [TRAINER_ERNEST_OLD_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ernest1),
        .party = {.NoItemDefaultMoves = sParty_Ernest1},
    },

    [TRAINER_DWAYNE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("DWAYNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dwayne),
        .party = {.NoItemDefaultMoves = sParty_Dwayne},
    },

    [TRAINER_PHILLIP_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("PHILLIP"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_PhillipOld),
        .party = {.NoItemDefaultMoves = sParty_PhillipOld},
    },

    [TRAINER_LEONARD_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("LEONARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LeonardOld),
        .party = {.NoItemDefaultMoves = sParty_LeonardOld},
    },

    [TRAINER_DUNCAN_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("DUNCAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Duncan_Old),
        .party = {.NoItemDefaultMoves = sParty_Duncan_Old},
    },

    [TRAINER_ERNEST_OLD_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ernest2),
        .party = {.NoItemDefaultMoves = sParty_Ernest2},
    },

    [TRAINER_ERNEST_OLD_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ernest3),
        .party = {.NoItemDefaultMoves = sParty_Ernest3},
    },

    [TRAINER_ERNEST_OLD_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ernest4),
        .party = {.NoItemDefaultMoves = sParty_Ernest4},
    },

    [TRAINER_ERNEST_OLD_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ernest5),
        .party = {.NoItemDefaultMoves = sParty_Ernest5},
    },

    [TRAINER_ELI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ELI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Eli),
        .party = {.NoItemDefaultMoves = sParty_Eli},
    },

    [TRAINER_ANNIKA] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ANNIKA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Annika),
        .party = {.ItemCustomMoves = sParty_Annika},
    },

    [TRAINER_JAZMYN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER_2,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JAZMYN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jazmyn),
        .party = {.NoItemDefaultMoves = sParty_Jazmyn},
    },

    [TRAINER_JONAS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("JONAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jonas),
        .party = {.NoItemCustomMoves = sParty_Jonas},
    },

    [TRAINER_KAYLEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("KAYLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kayley),
        .party = {.NoItemCustomMoves = sParty_Kayley},
    },

    [TRAINER_AURON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("AURON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Auron),
        .party = {.NoItemDefaultMoves = sParty_Auron},
    },

    [TRAINER_KELVIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KELVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kelvin),
        .party = {.NoItemDefaultMoves = sParty_Kelvin},
    },

    [TRAINER_MARLEY] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("MARLEY"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Marley),
        .party = {.ItemCustomMoves = sParty_Marley},
    },

    [TRAINER_REYNA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("REYNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Reyna),
        .party = {.NoItemDefaultMoves = sParty_Reyna},
    },

    [TRAINER_HUDSON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUDSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hudson),
        .party = {.NoItemDefaultMoves = sParty_Hudson},
    },

    [TRAINER_CONOR] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("CONOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Conor),
        .party = {.NoItemDefaultMoves = sParty_Conor},
    },

    [TRAINER_EDWIN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edwin1),
        .party = {.NoItemDefaultMoves = sParty_Edwin1},
    },

    [TRAINER_HECTOR] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("HECTOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hector),
        .party = {.NoItemDefaultMoves = sParty_Hector},
    },

    [TRAINER_TABITHA_MOSSDEEP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .trainerName = _("TABITHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TabithaMossdeep),
        .party = {.NoItemDefaultMoves = sParty_TabithaMossdeep},
    },

    [TRAINER_EDWIN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edwin2),
        .party = {.NoItemDefaultMoves = sParty_Edwin2},
    },

    [TRAINER_EDWIN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edwin3),
        .party = {.NoItemDefaultMoves = sParty_Edwin3},
    },

    [TRAINER_EDWIN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edwin4),
        .party = {.NoItemDefaultMoves = sParty_Edwin4},
    },

    [TRAINER_EDWIN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAGE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SAGE,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Edwin5),
        .party = {.NoItemDefaultMoves = sParty_Edwin5},
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

    [TRAINER_MAY_ROUTE_119_MUDKIP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRoute119Mudkip),
        .party = {.NoItemDefaultMoves = sParty_MayRoute119Mudkip},
    },

    [TRAINER_MAY_ROUTE_103_TREECKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRoute103Treecko),
        .party = {.NoItemDefaultMoves = sParty_MayRoute103Treecko},
    },

    [TRAINER_MAY_ROUTE_110_TREECKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRoute110Treecko),
        .party = {.NoItemDefaultMoves = sParty_MayRoute110Treecko},
    },

    [TRAINER_MAY_ROUTE_119_TREECKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRoute119Treecko),
        .party = {.NoItemDefaultMoves = sParty_MayRoute119Treecko},
    },

    [TRAINER_MAY_ROUTE_103_TORCHIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRoute103Torchic),
        .party = {.NoItemDefaultMoves = sParty_MayRoute103Torchic},
    },

    [TRAINER_MAY_ROUTE_110_TORCHIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRoute110Torchic),
        .party = {.NoItemDefaultMoves = sParty_MayRoute110Torchic},
    },

    [TRAINER_MAY_ROUTE_119_TORCHIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRoute119Torchic),
        .party = {.NoItemDefaultMoves = sParty_MayRoute119Torchic},
    },

    [TRAINER_ISAAC_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaac1),
        .party = {.NoItemDefaultMoves = sParty_Isaac1},
    },

    [TRAINER_DAVIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DAVIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Davis),
        .party = {.NoItemDefaultMoves = sParty_Davis},
    },

    [TRAINER_MITCHELL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("MITCHELL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Mitchell),
        .party = {.NoItemCustomMoves = sParty_Mitchell},
    },

    [TRAINER_ISAAC_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaac2),
        .party = {.NoItemDefaultMoves = sParty_Isaac2},
    },

    [TRAINER_ISAAC_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaac3),
        .party = {.NoItemDefaultMoves = sParty_Isaac3},
    },

    [TRAINER_ISAAC_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaac4),
        .party = {.NoItemDefaultMoves = sParty_Isaac4},
    },

    [TRAINER_ISAAC_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isaac5),
        .party = {.NoItemDefaultMoves = sParty_Isaac5},
    },

    [TRAINER_LYDIA_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lydia1),
        .party = {.NoItemDefaultMoves = sParty_Lydia1},
    },

    [TRAINER_HALLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("HALLE"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Halle),
        .party = {.NoItemDefaultMoves = sParty_Halle},
    },

    [TRAINER_GARRISON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("GARRISON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Garrison),
        .party = {.NoItemDefaultMoves = sParty_Garrison},
    },

    [TRAINER_LYDIA_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lydia2),
        .party = {.NoItemDefaultMoves = sParty_Lydia2},
    },

    [TRAINER_LYDIA_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lydia3),
        .party = {.NoItemDefaultMoves = sParty_Lydia3},
    },

    [TRAINER_LYDIA_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lydia4),
        .party = {.NoItemDefaultMoves = sParty_Lydia4},
    },

    [TRAINER_LYDIA_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lydia5),
        .party = {.NoItemDefaultMoves = sParty_Lydia5},
    },

    [TRAINER_JACKSON_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jackson1),
        .party = {.NoItemDefaultMoves = sParty_Jackson1},
    },

    [TRAINER_LORENZO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("LORENZO"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Lorenzo),
        .party = {.NoItemDefaultMoves = sParty_Lorenzo},
    },

    [TRAINER_SEBASTIAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("SEBASTIAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Sebastian),
        .party = {.NoItemDefaultMoves = sParty_Sebastian},
    },

    [TRAINER_JACKSON_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Jackson2),
        .party = {.NoItemDefaultMoves = sParty_Jackson2},
    },

    [TRAINER_JACKSON_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jackson3),
        .party = {.NoItemDefaultMoves = sParty_Jackson3},
    },

    [TRAINER_JACKSON_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Jackson4),
        .party = {.NoItemDefaultMoves = sParty_Jackson4},
    },

    [TRAINER_JACKSON_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Jackson5),
        .party = {.NoItemDefaultMoves = sParty_Jackson5},
    },

    [TRAINER_CATHERINE_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Catherine1),
        .party = {.NoItemDefaultMoves = sParty_Catherine1},
    },

    [TRAINER_JENNA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("JENNA"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Jenna),
        .party = {.NoItemDefaultMoves = sParty_Jenna},
    },

    [TRAINER_SOPHIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("SOPHIA"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Sophia),
        .party = {.NoItemDefaultMoves = sParty_Sophia},
    },

    [TRAINER_CATHERINE_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Catherine2),
        .party = {.NoItemDefaultMoves = sParty_Catherine2},
    },

    [TRAINER_CATHERINE_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Catherine3),
        .party = {.NoItemDefaultMoves = sParty_Catherine3},
    },

    [TRAINER_CATHERINE_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Catherine4),
        .party = {.NoItemDefaultMoves = sParty_Catherine4},
    },

    [TRAINER_CATHERINE_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Catherine5),
        .party = {.NoItemDefaultMoves = sParty_Catherine5},
    },

    [TRAINER_JULIO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("JULIO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Julio),
        .party = {.NoItemDefaultMoves = sParty_Julio},
    },

    [TRAINER_GRUNT_SEAFLOOR_CAVERN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntSeafloorCavern5),
        .party = {.NoItemDefaultMoves = sParty_GruntSeafloorCavern5},
    },

    [TRAINER_GRUNT_UNUSED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntUnused),
        .party = {.NoItemDefaultMoves = sParty_GruntUnused},
    },

    [TRAINER_GRUNT_MT_PYRE_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMtPyre4),
        .party = {.NoItemDefaultMoves = sParty_GruntMtPyre4},
    },

    [TRAINER_GRUNT_JAGGED_PASS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntJaggedPass),
        .party = {.NoItemDefaultMoves = sParty_GruntJaggedPass},
    },

    [TRAINER_MARC_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MARC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Marc_Old),
        .party = {.NoItemDefaultMoves = sParty_Marc_Old},
    },

    [TRAINER_BRENDEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("BRENDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brenden),
        .party = {.NoItemDefaultMoves = sParty_Brenden},
    },

    [TRAINER_LILITH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("LILITH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lilith),
        .party = {.NoItemDefaultMoves = sParty_Lilith},
    },

    [TRAINER_CRISTIAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("CRISTIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cristian),
        .party = {.NoItemDefaultMoves = sParty_Cristian},
    },

    [TRAINER_SYLVIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("SYLVIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sylvia),
        .party = {.NoItemDefaultMoves = sParty_Sylvia},
    },

    [TRAINER_LEONARDO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("LEONARDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Leonardo),
        .party = {.NoItemDefaultMoves = sParty_Leonardo},
    },

    [TRAINER_ATHENA] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("ATHENA"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Athena),
        .party = {.ItemCustomMoves = sParty_Athena},
    },

    [TRAINER_HARRISON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("HARRISON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Harrison),
        .party = {.NoItemDefaultMoves = sParty_Harrison},
    },

    [TRAINER_GRUNT_MT_CHIMNEY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntSlowpokeWell_B1F2),
        .party = {.NoItemDefaultMoves = sParty_GruntSlowpokeWell_B1F2},
    },

    [TRAINER_CLARENCE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("CLARENCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Clarence),
        .party = {.NoItemDefaultMoves = sParty_Clarence},
    },

    [TRAINER_TERRY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Terry),
        .party = {.NoItemDefaultMoves = sParty_Terry},
    },

    [TRAINER_NATE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("NATE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nate),
        .party = {.NoItemDefaultMoves = sParty_Nate},
    },

    [TRAINER_KATHLEEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("KATHLEEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kathleen),
        .party = {.NoItemDefaultMoves = sParty_Kathleen},
    },

    [TRAINER_CLIFFORD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("CLIFFORD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Clifford),
        .party = {.NoItemDefaultMoves = sParty_Clifford},
    },

    [TRAINER_NICHOLAS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("NICHOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Nicholas),
        .party = {.NoItemDefaultMoves = sParty_Nicholas},
    },

    [TRAINER_GRUNT_SPACE_CENTER_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter3),
        .party = {.NoItemDefaultMoves = sParty_GruntSpaceCenter3},
    },

    [TRAINER_GRUNT_SPACE_CENTER_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter4),
        .party = {.NoItemDefaultMoves = sParty_GruntSpaceCenter4},
    },

    [TRAINER_GRUNT_SPACE_CENTER_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter5),
        .party = {.NoItemDefaultMoves = sParty_GruntSpaceCenter5},
    },

    [TRAINER_GRUNT_SPACE_CENTER_6] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter6),
        .party = {.NoItemDefaultMoves = sParty_GruntSpaceCenter6},
    },

    [TRAINER_GRUNT_SPACE_CENTER_7] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter7),
        .party = {.NoItemDefaultMoves = sParty_GruntSpaceCenter7},
    },

    [TRAINER_MACEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MACEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Macey),
        .party = {.NoItemDefaultMoves = sParty_Macey},
    },

    [TRAINER_BRENDAN_RUSTBORO_TREECKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_EM_BRENDAN,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BrendanRustboroTreecko),
        .party = {.NoItemDefaultMoves = sParty_BrendanRustboroTreecko},
    },

    [TRAINER_BRENDAN_RUSTBORO_MUDKIP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_EM_BRENDAN,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BrendanRustboroMudkip),
        .party = {.NoItemDefaultMoves = sParty_BrendanRustboroMudkip},
    },

    [TRAINER_PAXTON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_FIREBREATHER,
        .trainerName = _("PAXTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Paxton),
        .party = {.NoItemDefaultMoves = sParty_Paxton},
    },

    [TRAINER_ISABELLA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ISABELLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isabella),
        .party = {.NoItemDefaultMoves = sParty_Isabella},
    },

    [TRAINER_GRUNT_WEATHER_INST_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntWeatherInst5),
        .party = {.NoItemDefaultMoves = sParty_GruntWeatherInst5},
    },

    [TRAINER_TABITHA_MT_CHIMNEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .trainerName = _("TABITHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_TabithaSlowpokeWell_B1F),
        .party = {.NoItemDefaultMoves = sParty_TabithaSlowpokeWell_B1F},
    },

    [TRAINER_JONATHAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("JONATHAN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_Jonathan),
        .party = {.NoItemDefaultMoves = sParty_Jonathan},
    },

    [TRAINER_BRENDAN_RUSTBORO_TORCHIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_EM_BRENDAN,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_BrendanRustboroTorchic),
        .party = {.NoItemDefaultMoves = sParty_BrendanRustboroTorchic},
    },

    [TRAINER_MAY_RUSTBORO_MUDKIP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_MayRustboroMudkip),
        .party = {.NoItemDefaultMoves = sParty_MayRustboroMudkip},
    },

    [TRAINER_MAXIE_MAGMA_HIDEOUT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("MAXIE"),
        .items = {ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MaxieMagmaHideout),
        .party = {.NoItemDefaultMoves = sParty_MaxieMagmaHideout},
    },

    [TRAINER_MAXIE_MT_CHIMNEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("MAXIE"),
        .items = {ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MaxieSlowpokeWell_B1F),
        .party = {.NoItemDefaultMoves = sParty_MaxieSlowpokeWell_B1F},
    },

    [TRAINER_TIANA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("TIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tiana),
        .party = {.NoItemDefaultMoves = sParty_Tiana},
    },

    [TRAINER_HALEY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Haley1),
        .party = {.NoItemDefaultMoves = sParty_Haley1},
    },

    [TRAINER_JANICE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("JANICE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Janice),
        .party = {.NoItemDefaultMoves = sParty_Janice},
    },

    [TRAINER_VIVI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("VIVI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Vivi),
        .party = {.NoItemDefaultMoves = sParty_Vivi},
    },

    [TRAINER_HALEY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Haley2),
        .party = {.NoItemDefaultMoves = sParty_Haley2},
    },

    [TRAINER_HALEY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Haley3),
        .party = {.NoItemDefaultMoves = sParty_Haley3},
    },

    [TRAINER_HALEY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Haley4),
        .party = {.NoItemDefaultMoves = sParty_Haley4},
    },

    [TRAINER_HALEY_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Haley5),
        .party = {.NoItemDefaultMoves = sParty_Haley5},
    },

    [TRAINER_SALLY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("SALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sally),
        .party = {.NoItemDefaultMoves = sParty_Sally},
    },

    [TRAINER_ROBIN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ROBIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Robin),
        .party = {.NoItemDefaultMoves = sParty_Robin},
    },

    [TRAINER_ANDREA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ANDREA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andrea),
        .party = {.NoItemDefaultMoves = sParty_Andrea},
    },

    [TRAINER_CRISSY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("CRISSY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Crissy),
        .party = {.NoItemDefaultMoves = sParty_Crissy},
    },

    [TRAINER_RICK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("RICK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rick),
        .party = {.NoItemDefaultMoves = sParty_Rick},
    },

    [TRAINER_LYLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("LYLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lyle),
        .party = {.NoItemDefaultMoves = sParty_Lyle},
    },

    [TRAINER_JOSE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JOSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jose),
        .party = {.NoItemDefaultMoves = sParty_Jose},
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
        .party = {.NoItemDefaultMoves = sParty_Doug},
    },

    [TRAINER_GREG_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("GREG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Greg_Old),
        .party = {.NoItemDefaultMoves = sParty_Greg_Old},
    },

    [TRAINER_KENT_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("KENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kent_Old),
        .party = {.NoItemDefaultMoves = sParty_Kent_Old},
    },

    [TRAINER_JAMES_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_James1),
        .party = {.NoItemDefaultMoves = sParty_James1},
    },

    [TRAINER_JAMES_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_James2),
        .party = {.NoItemDefaultMoves = sParty_James2},
    },

    [TRAINER_JAMES_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_James3),
        .party = {.NoItemDefaultMoves = sParty_James3},
    },

    [TRAINER_JAMES_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_James4),
        .party = {.NoItemDefaultMoves = sParty_James4},
    },

    [TRAINER_JAMES_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_James5),
        .party = {.NoItemDefaultMoves = sParty_James5},
    },

    [TRAINER_BRICE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BRICE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brice),
        .party = {.NoItemDefaultMoves = sParty_Brice},
    },

    [TRAINER_TRENT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Trent1),
        .party = {.NoItemDefaultMoves = sParty_Trent1},
    },

    [TRAINER_LENNY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lenny),
        .party = {.NoItemDefaultMoves = sParty_Lenny},
    },

    [TRAINER_LUCAS_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LUCAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lucas1),
        .party = {.NoItemDefaultMoves = sParty_Lucas1},
    },

    [TRAINER_ALAN_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_AlanOld),
        .party = {.NoItemDefaultMoves = sParty_AlanOld},
    },

    [TRAINER_CLARK] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("CLARK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Clark),
        .party = {.NoItemDefaultMoves = sParty_Clark},
    },

    [TRAINER_ERIC_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ERIC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_EricOld),
        .party = {.NoItemDefaultMoves = sParty_EricOld},
    },

    [TRAINER_LUCAS_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LUCAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lucas2),
        .party = {.NoItemCustomMoves = sParty_Lucas2},
    },

    [TRAINER_MIKE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MIKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Mike1),
        .party = {.NoItemCustomMoves = sParty_Mike1},
    },

    [TRAINER_MIKE_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MIKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Mike2),
        .party = {.NoItemDefaultMoves = sParty_Mike2},
    },

    [TRAINER_TRENT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Trent2),
        .party = {.NoItemDefaultMoves = sParty_Trent2},
    },

    [TRAINER_TRENT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Trent3),
        .party = {.NoItemDefaultMoves = sParty_Trent3},
    },

    [TRAINER_TRENT_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Trent4),
        .party = {.NoItemDefaultMoves = sParty_Trent4},
    },

    [TRAINER_TRENT_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Trent5),
        .party = {.NoItemDefaultMoves = sParty_Trent5},
    },

    [TRAINER_DEZ_AND_LUKE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("DEZ & LUKE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_DezAndLuke),
        .party = {.NoItemDefaultMoves = sParty_DezAndLuke},
    },

    [TRAINER_LEA_AND_JED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("LEA & JED"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LeaAndJed),
        .party = {.NoItemDefaultMoves = sParty_LeaAndJed},
    },

    [TRAINER_KIRA_AND_DAN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan1),
        .party = {.NoItemDefaultMoves = sParty_KiraAndDan1},
    },

    [TRAINER_KIRA_AND_DAN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan2),
        .party = {.NoItemDefaultMoves = sParty_KiraAndDan2},
    },

    [TRAINER_KIRA_AND_DAN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan3),
        .party = {.NoItemDefaultMoves = sParty_KiraAndDan3},
    },

    [TRAINER_KIRA_AND_DAN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan4),
        .party = {.NoItemDefaultMoves = sParty_KiraAndDan4},
    },

    [TRAINER_KIRA_AND_DAN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan5),
        .party = {.NoItemDefaultMoves = sParty_KiraAndDan5},
    },

    [TRAINER_JOHANNA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JOHANNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Johanna),
        .party = {.NoItemDefaultMoves = sParty_Johanna},
    },

    [TRAINER_GERALD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GERALD"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Gerald),
        .party = {.NoItemCustomMoves = sParty_Gerald},
    },

    [TRAINER_VIVIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("VIVIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Vivian),
        .party = {.NoItemCustomMoves = sParty_Vivian},
    },

    [TRAINER_DANIELLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("DANIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Danielle),
        .party = {.NoItemCustomMoves = sParty_Danielle},
    },

    [TRAINER_HIDEO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("HIDEO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Hideo),
        .party = {.NoItemCustomMoves = sParty_Hideo},
    },

    [TRAINER_KEIGO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("KEIGO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Keigo),
        .party = {.NoItemCustomMoves = sParty_Keigo},
    },

    [TRAINER_RILEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("RILEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Riley),
        .party = {.NoItemCustomMoves = sParty_Riley},
    },

    [TRAINER_FLINT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("FLINT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Flint),
        .party = {.NoItemDefaultMoves = sParty_Flint},
    },

    [TRAINER_ASHLEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ASHLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Ashley),
        .party = {.NoItemDefaultMoves = sParty_Ashley},
    },

    [TRAINER_WALLY_MAUVILLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("WALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_WallyMauville),
        .party = {.NoItemDefaultMoves = sParty_WallyMauville},
    },

    [TRAINER_WALLY_VR_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("WALLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_WallyVR2),
        .party = {.NoItemCustomMoves = sParty_WallyVR2},
    },

    [TRAINER_WALLY_VR_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("WALLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_WallyVR3),
        .party = {.NoItemCustomMoves = sParty_WallyVR3},
    },

    [TRAINER_WALLY_VR_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("WALLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_WallyVR4),
        .party = {.NoItemCustomMoves = sParty_WallyVR4},
    },

    [TRAINER_WALLY_VR_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL,
        .trainerName = _("WALLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_WallyVR5),
        .party = {.NoItemCustomMoves = sParty_WallyVR5},
    },

    [TRAINER_BRENDAN_LILYCOVE_MUDKIP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_EM_BRENDAN,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_BrendanLilycoveMudkip),
        .party = {.NoItemDefaultMoves = sParty_BrendanLilycoveMudkip},
    },

    [TRAINER_BRENDAN_LILYCOVE_TREECKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_EM_BRENDAN,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_BrendanLilycoveTreecko),
        .party = {.NoItemDefaultMoves = sParty_BrendanLilycoveTreecko},
    },

    [TRAINER_BRENDAN_LILYCOVE_TORCHIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_EM_BRENDAN,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_BrendanLilycoveTorchic),
        .party = {.NoItemDefaultMoves = sParty_BrendanLilycoveTorchic},
    },

    [TRAINER_MAY_LILYCOVE_MUDKIP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayLilycoveMudkip),
        .party = {.NoItemDefaultMoves = sParty_MayLilycoveMudkip},
    },

    [TRAINER_MAY_LILYCOVE_TREECKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayLilycoveTreecko),
        .party = {.NoItemDefaultMoves = sParty_MayLilycoveTreecko},
    },

    [TRAINER_MAY_LILYCOVE_TORCHIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayLilycoveTorchic),
        .party = {.NoItemDefaultMoves = sParty_MayLilycoveTorchic},
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

    [TRAINER_HENRY_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("HENRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_HenryOld),
        .party = {.NoItemDefaultMoves = sParty_HenryOld},
    },

    [TRAINER_ROGER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ROGER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Roger),
        .party = {.NoItemDefaultMoves = sParty_Roger},
    },

    [TRAINER_ALEXA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("ALEXA"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Alexa),
        .party = {.NoItemDefaultMoves = sParty_Alexa},
    },

    [TRAINER_RUBEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("RUBEN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Ruben),
        .party = {.NoItemDefaultMoves = sParty_Ruben},
    },

    [TRAINER_KOJI_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Koji1),
        .party = {.NoItemDefaultMoves = sParty_Koji1},
    },

    [TRAINER_WAYNE_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WAYNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_WayneOld),
        .party = {.NoItemDefaultMoves = sParty_WayneOld},
    },

    [TRAINER_AIDAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("AIDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Aidan),
        .party = {.NoItemDefaultMoves = sParty_Aidan},
    },

    [TRAINER_REED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("REED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Reed),
        .party = {.NoItemDefaultMoves = sParty_Reed},
    },

    [TRAINER_TISHA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TISHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tisha),
        .party = {.NoItemDefaultMoves = sParty_Tisha},
    },

    [TRAINER_TORI_AND_TIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("TORI & TIA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_ToriAndTia),
        .party = {.NoItemDefaultMoves = sParty_ToriAndTia},
    },

    [TRAINER_KIM_AND_IRIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("KIM & IRIS"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_KimAndIris),
        .party = {.NoItemCustomMoves = sParty_KimAndIris},
    },

    [TRAINER_TYRA_AND_IVY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("TYRA & IVY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TyraAndIvy),
        .party = {.NoItemCustomMoves = sParty_TyraAndIvy},
    },

    [TRAINER_MEL_AND_PAUL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("MEL & PAUL"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_MelAndPaul),
        .party = {.NoItemCustomMoves = sParty_MelAndPaul},
    },

    [TRAINER_JOHN_AND_JAY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay1),
        .party = {.NoItemCustomMoves = sParty_JohnAndJay1},
    },

    [TRAINER_JOHN_AND_JAY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay2),
        .party = {.NoItemCustomMoves = sParty_JohnAndJay2},
    },

    [TRAINER_JOHN_AND_JAY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay3),
        .party = {.NoItemCustomMoves = sParty_JohnAndJay3},
    },

    [TRAINER_JOHN_AND_JAY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_SETUP_FIRST_TURN,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay4),
        .party = {.NoItemCustomMoves = sParty_JohnAndJay4},
    },

    [TRAINER_JOHN_AND_JAY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay5),
        .party = {.NoItemCustomMoves = sParty_JohnAndJay5},
    },

    [TRAINER_RELI_AND_IAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("RELI & IAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_ReliAndIan),
        .party = {.NoItemDefaultMoves = sParty_ReliAndIan},
    },

    [TRAINER_LILA_AND_ROY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy1),
        .party = {.NoItemDefaultMoves = sParty_LilaAndRoy1},
    },

    [TRAINER_LILA_AND_ROY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy2),
        .party = {.NoItemDefaultMoves = sParty_LilaAndRoy2},
    },

    [TRAINER_LILA_AND_ROY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy3),
        .party = {.NoItemDefaultMoves = sParty_LilaAndRoy3},
    },

    [TRAINER_LILA_AND_ROY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy4),
        .party = {.NoItemDefaultMoves = sParty_LilaAndRoy4},
    },

    [TRAINER_LILA_AND_ROY_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy5),
        .party = {.NoItemDefaultMoves = sParty_LilaAndRoy5},
    },

    [TRAINER_LISA_AND_RAY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LISA & RAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LisaAndRay),
        .party = {.NoItemDefaultMoves = sParty_LisaAndRay},
    },

    [TRAINER_CHRIS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CHRIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chris),
        .party = {.NoItemDefaultMoves = sParty_Chris},
    },

    [TRAINER_DAWSON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("DAWSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dawson),
        .party = {.ItemDefaultMoves = sParty_Dawson},
    },

    [TRAINER_SARAH] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("SARAH"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sarah),
        .party = {.ItemDefaultMoves = sParty_Sarah},
    },

    [TRAINER_DARIAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("DARIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Darian),
        .party = {.NoItemDefaultMoves = sParty_Darian},
    },

    [TRAINER_HAILEY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("HAILEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hailey),
        .party = {.NoItemDefaultMoves = sParty_Hailey},
    },

    [TRAINER_CHANDLER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("CHANDLER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Chandler),
        .party = {.NoItemDefaultMoves = sParty_Chandler},
    },

    [TRAINER_KALEB] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("KALEB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kaleb),
        .party = {.ItemDefaultMoves = sParty_Kaleb},
    },

    [TRAINER_JOSEPH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("JOSEPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Joseph),
        .party = {.NoItemDefaultMoves = sParty_Joseph},
    },

    [TRAINER_ALYSSA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ALYSSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alyssa),
        .party = {.NoItemDefaultMoves = sParty_Alyssa},
    },

    [TRAINER_MARCOS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("MARCOS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Marcos),
        .party = {.NoItemDefaultMoves = sParty_Marcos},
    },

    [TRAINER_RHETT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("RHETT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rhett),
        .party = {.NoItemDefaultMoves = sParty_Rhett},
    },

    [TRAINER_TYRON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TYRON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Tyron),
        .party = {.NoItemDefaultMoves = sParty_Tyron},
    },

    [TRAINER_CELINA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("CELINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Celina),
        .party = {.NoItemDefaultMoves = sParty_Celina},
    },

    [TRAINER_BIANCA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("BIANCA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bianca),
        .party = {.NoItemDefaultMoves = sParty_Bianca},
    },

    [TRAINER_HAYDEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("HAYDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Hayden),
        .party = {.NoItemDefaultMoves = sParty_Hayden},
    },

    [TRAINER_SOPHIE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("SOPHIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Sophie),
        .party = {.NoItemDefaultMoves = sParty_Sophie},
    },

    [TRAINER_COBY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("COBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Coby),
        .party = {.NoItemDefaultMoves = sParty_Coby},
    },

    [TRAINER_LAWRENCE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("LAWRENCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Lawrence),
        .party = {.NoItemDefaultMoves = sParty_Lawrence},
    },

    [TRAINER_WYATT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("WYATT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Wyatt),
        .party = {.NoItemDefaultMoves = sParty_Wyatt},
    },

    [TRAINER_ANGELINA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ANGELINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Angelina),
        .party = {.NoItemDefaultMoves = sParty_Angelina},
    },

    [TRAINER_KAI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("KAI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kai),
        .party = {.NoItemDefaultMoves = sParty_Kai},
    },

    [TRAINER_CHARLOTTE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CHARLOTTE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Charlotte),
        .party = {.NoItemDefaultMoves = sParty_Charlotte},
    },

    [TRAINER_DEANDRE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DEANDRE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Deandre),
        .party = {.NoItemDefaultMoves = sParty_Deandre},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout1),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout1},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout2),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout2},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout3),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout3},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout4),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout4},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout5),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout5},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_6] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout6),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout6},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_7] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout7),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout7},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_8] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout8),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout8},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_9] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout9),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout9},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_10] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout10),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout10},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_11] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout11),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout11},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_12] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout12),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout12},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_13] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout13),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout13},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_14] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout14),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout14},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_15] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout15),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout15},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_16] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout16),
        .party = {.NoItemDefaultMoves = sParty_GruntMagmaHideout16},
    },

    [TRAINER_TABITHA_MAGMA_HIDEOUT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .trainerName = _("TABITHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TabithaMagmaHideout),
        .party = {.NoItemDefaultMoves = sParty_TabithaMagmaHideout},
    },

    [TRAINER_DARCY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("DARCY"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Darcy),
        .party = {.NoItemDefaultMoves = sParty_Darcy},
    },

    [TRAINER_MAXIE_MOSSDEEP] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("MAXIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MaxieMossdeep),
        .party = {.NoItemDefaultMoves = sParty_MaxieMossdeep},
    },

    [TRAINER_PETE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("PETE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pete),
        .party = {.NoItemDefaultMoves = sParty_Pete},
    },

    [TRAINER_ISABELLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("ISABELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Isabelle),
        .party = {.NoItemDefaultMoves = sParty_Isabelle},
    },

    [TRAINER_ANDRES_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andres1),
        .party = {.NoItemDefaultMoves = sParty_Andres1},
    },

    [TRAINER_JOSUE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSUE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Josue),
        .party = {.NoItemDefaultMoves = sParty_Josue},
    },

    [TRAINER_CAMRON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("CAMRON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Camron),
        .party = {.NoItemDefaultMoves = sParty_Camron},
    },

    [TRAINER_CORY_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cory1),
        .party = {.NoItemDefaultMoves = sParty_Cory1},
    },

    [TRAINER_CAROLINA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CAROLINA"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Carolina),
        .party = {.NoItemDefaultMoves = sParty_Carolina},
    },

    [TRAINER_ELIJAH] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ELIJAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Elijah),
        .party = {.NoItemDefaultMoves = sParty_Elijah},
    },

    [TRAINER_CELIA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_LASS,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CELIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Celia),
        .party = {.NoItemDefaultMoves = sParty_Celia},
    },

    [TRAINER_BRYAN_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("BRYAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BryanOld),
        .party = {.NoItemDefaultMoves = sParty_BryanOld},
    },

    [TRAINER_BRANDEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("BRANDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Branden),
        .party = {.NoItemDefaultMoves = sParty_Branden},
    },

    [TRAINER_BRYANT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("BRYANT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Bryant),
        .party = {.NoItemDefaultMoves = sParty_Bryant},
    },

    [TRAINER_SHAYLA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("SHAYLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Shayla),
        .party = {.NoItemDefaultMoves = sParty_Shayla},
    },

    [TRAINER_KYRA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("KYRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Kyra),
        .party = {.NoItemDefaultMoves = sParty_Kyra},
    },

    [TRAINER_JAIDEN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("JAIDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Jaiden),
        .party = {.NoItemDefaultMoves = sParty_Jaiden},
    },

    [TRAINER_ALIX] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("ALIX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Alix),
        .party = {.NoItemDefaultMoves = sParty_Alix},
    },

    [TRAINER_HELENE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("HELENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Helene),
        .party = {.NoItemDefaultMoves = sParty_Helene},
    },

    [TRAINER_MARLENE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MARLENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Marlene),
        .party = {.NoItemDefaultMoves = sParty_Marlene},
    },

    [TRAINER_DEVAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DEVAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Devan),
        .party = {.NoItemDefaultMoves = sParty_Devan},
    },

    [TRAINER_JOHNSON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOHNSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Johnson),
        .party = {.NoItemDefaultMoves = sParty_Johnson},
    },

    [TRAINER_MELINA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MELINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Melina),
        .party = {.NoItemDefaultMoves = sParty_Melina},
    },

    [TRAINER_BRANDI] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("BRANDI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Brandi),
        .party = {.NoItemDefaultMoves = sParty_Brandi},
    },

    [TRAINER_AISHA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("AISHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Aisha),
        .party = {.NoItemDefaultMoves = sParty_Aisha},
    },

    [TRAINER_MAKAYLA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FIREBREATHER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("MAKAYLA"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Makayla),
        .party = {.NoItemDefaultMoves = sParty_Makayla},
    },

    [TRAINER_FABIAN] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FABIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Fabian),
        .party = {.NoItemDefaultMoves = sParty_Fabian},
    },

    [TRAINER_DAYTON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("DAYTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Dayton),
        .party = {.NoItemDefaultMoves = sParty_Dayton},
    },

    [TRAINER_RACHEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("RACHEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Rachel),
        .party = {.NoItemDefaultMoves = sParty_Rachel},
    },

    [TRAINER_LEONEL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("LEONEL"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Leonel),
        .party = {.NoItemCustomMoves = sParty_Leonel},
    },

    [TRAINER_CALLIE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CALLIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Callie),
        .party = {.NoItemDefaultMoves = sParty_Callie},
    },

    [TRAINER_CALE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("CALE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cale),
        .party = {.NoItemDefaultMoves = sParty_Cale},
    },

    [TRAINER_MYLES] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("MYLES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Myles),
        .party = {.NoItemDefaultMoves = sParty_Myles},
    },

    [TRAINER_PAT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("PAT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pat),
        .party = {.NoItemDefaultMoves = sParty_Pat},
    },

    [TRAINER_CRISTIN_1] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cristin1),
        .party = {.NoItemDefaultMoves = sParty_Cristin1},
    },

    [TRAINER_MAY_RUSTBORO_TREECKO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRustboroTreecko),
        .party = {.NoItemDefaultMoves = sParty_MayRustboroTreecko},
    },

    [TRAINER_MAY_RUSTBORO_TORCHIC] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_EM_MAY,
        .trainerName = _("MAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_MayRustboroTorchic),
        .party = {.NoItemDefaultMoves = sParty_MayRustboroTorchic},
    },

    [TRAINER_ROXANNE_OLD_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .trainerName = _("ROXANNE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Roxanne2),
        .party = {.ItemCustomMoves = sParty_Roxanne2},
    },

    [TRAINER_ROXANNE_OLD_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .trainerName = _("ROXANNE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Roxanne3),
        .party = {.ItemCustomMoves = sParty_Roxanne3},
    },

    [TRAINER_ROXANNE_OLD_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .trainerName = _("ROXANNE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Roxanne4),
        .party = {.ItemCustomMoves = sParty_Roxanne4},
    },

    [TRAINER_ROXANNE_OLD_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FALKNER,
        .trainerName = _("ROXANNE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Roxanne5),
        .party = {.ItemCustomMoves = sParty_Roxanne5},
    },

    [TRAINER_BRAWLY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .trainerName = _("BRAWLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Brawly2),
        .party = {.ItemCustomMoves = sParty_Brawly2},
    },

    [TRAINER_BRAWLY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .trainerName = _("BRAWLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Brawly3),
        .party = {.ItemCustomMoves = sParty_Brawly3},
    },

    [TRAINER_BRAWLY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .trainerName = _("BRAWLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Brawly4),
        .party = {.ItemCustomMoves = sParty_Brawly4},
    },

    [TRAINER_BRAWLY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BUGSY,
        .trainerName = _("BRAWLY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Brawly5),
        .party = {.ItemCustomMoves = sParty_Brawly5},
    },

    [TRAINER_WATTSON_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .trainerName = _("WATTSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Wattson2),
        .party = {.ItemCustomMoves = sParty_Wattson2},
    },

    [TRAINER_WATTSON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .trainerName = _("WATTSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Wattson3),
        .party = {.ItemCustomMoves = sParty_Wattson3},
    },

    [TRAINER_WATTSON_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .trainerName = _("WATTSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Wattson4),
        .party = {.ItemCustomMoves = sParty_Wattson4},
    },

    [TRAINER_WATTSON_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WHITNEY,
        .trainerName = _("WATTSON"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Wattson5),
        .party = {.ItemCustomMoves = sParty_Wattson5},
    },

    [TRAINER_FLANNERY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .trainerName = _("FLANNERY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Flannery2),
        .party = {.ItemCustomMoves = sParty_Flannery2},
    },

    [TRAINER_FLANNERY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .trainerName = _("FLANNERY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Flannery3),
        .party = {.ItemCustomMoves = sParty_Flannery3},
    },

    [TRAINER_FLANNERY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .trainerName = _("FLANNERY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Flannery4),
        .party = {.ItemCustomMoves = sParty_Flannery4},
    },

    [TRAINER_FLANNERY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .trainerName = _("FLANNERY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Flannery5),
        .party = {.ItemCustomMoves = sParty_Flannery5},
    },

    [TRAINER_NORMAN_OLD_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Norman2),
        .party = {.ItemCustomMoves = sParty_Norman2},
    },

    [TRAINER_NORMAN_OLD_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Norman3),
        .party = {.ItemCustomMoves = sParty_Norman3},
    },

    [TRAINER_NORMAN_OLD_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Norman4),
        .party = {.ItemCustomMoves = sParty_Norman4},
    },

    [TRAINER_NORMAN_OLD_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Norman5),
        .party = {.ItemCustomMoves = sParty_Norman5},
    },

    [TRAINER_WINONA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .trainerName = _("WINONA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_RISKY,
        .partySize = ARRAY_COUNT(sParty_Winona2),
        .party = {.ItemCustomMoves = sParty_Winona2},
    },

    [TRAINER_WINONA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .trainerName = _("WINONA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_RISKY,
        .partySize = ARRAY_COUNT(sParty_Winona3),
        .party = {.ItemCustomMoves = sParty_Winona3},
    },

    [TRAINER_WINONA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .trainerName = _("WINONA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_RISKY,
        .partySize = ARRAY_COUNT(sParty_Winona4),
        .party = {.ItemCustomMoves = sParty_Winona4},
    },

    [TRAINER_WINONA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .trainerName = _("WINONA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_RISKY,
        .partySize = ARRAY_COUNT(sParty_Winona5),
        .party = {.ItemCustomMoves = sParty_Winona5},
    },

    [TRAINER_TATE_AND_LIZA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza2),
        .party = {.ItemCustomMoves = sParty_TateAndLiza2},
    },

    [TRAINER_TATE_AND_LIZA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza3),
        .party = {.ItemCustomMoves = sParty_TateAndLiza3},
    },

    [TRAINER_TATE_AND_LIZA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza4),
        .party = {.ItemCustomMoves = sParty_TateAndLiza4},
    },

    [TRAINER_TATE_AND_LIZA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza5),
        .party = {.ItemCustomMoves = sParty_TateAndLiza5},
    },

    [TRAINER_JUAN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .trainerName = _("JUAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Juan2),
        .party = {.ItemCustomMoves = sParty_Juan2},
    },

    [TRAINER_JUAN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .trainerName = _("JUAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Juan3),
        .party = {.ItemCustomMoves = sParty_Juan3},
    },

    [TRAINER_JUAN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .trainerName = _("JUAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Juan4),
        .party = {.ItemCustomMoves = sParty_Juan4},
    },

    [TRAINER_JUAN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .trainerName = _("JUAN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Juan5),
        .party = {.ItemCustomMoves = sParty_Juan5},
    },

    [TRAINER_ANGELO] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("ANGELO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Angelo),
        .party = {.ItemCustomMoves = sParty_Angelo},
    },

    [TRAINER_DARIUS] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("DARIUS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Darius),
        .party = {.NoItemDefaultMoves = sParty_Darius},
    },

    [TRAINER_STEVEN] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_STEVEN,
        .trainerName = _("STEVEN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Steven),
        .party = {.ItemCustomMoves = sParty_Steven},
    },

    [TRAINER_ANABEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SALON_MAIDEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
        .trainerName = _("ANABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Anabel),
        .party = {.NoItemDefaultMoves = sParty_Anabel},
    },

    [TRAINER_TUCKER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DOME_ACE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_DOME_ACE_TUCKER,
        .trainerName = _("TUCKER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Tucker),
        .party = {.NoItemDefaultMoves = sParty_Tucker},
    },

    [TRAINER_SPENSER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PALACE_MAVEN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PALACE_MAVEN_SPENSER,
        .trainerName = _("SPENSER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Spenser),
        .party = {.NoItemDefaultMoves = sParty_Spenser},
    },

    [TRAINER_GRETA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_ARENA_TYCOON,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ARENA_TYCOON_GRETA,
        .trainerName = _("GRETA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Greta),
        .party = {.NoItemDefaultMoves = sParty_Greta},
    },

    [TRAINER_NOLAND] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FACTORY_HEAD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FACTORY_HEAD_NOLAND,
        .trainerName = _("NOLAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Noland),
        .party = {.NoItemDefaultMoves = sParty_Noland},
    },

    [TRAINER_LUCY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PIKE_QUEEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PIKE_QUEEN_LUCY,
        .trainerName = _("LUCY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Lucy),
        .party = {.NoItemDefaultMoves = sParty_Lucy},
    },

    [TRAINER_BRANDON_OLD] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PYRAMID_KING,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PYRAMID_KING_BRANDON,
        .trainerName = _("BRANDON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_BrandonOld),
        .party = {.NoItemDefaultMoves = sParty_BrandonOld},
    },

    [TRAINER_ANDRES_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andres2),
        .party = {.NoItemDefaultMoves = sParty_Andres2},
    },

    [TRAINER_ANDRES_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andres3),
        .party = {.NoItemDefaultMoves = sParty_Andres3},
    },

    [TRAINER_ANDRES_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andres4),
        .party = {.NoItemDefaultMoves = sParty_Andres4},
    },

    [TRAINER_ANDRES_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Andres5),
        .party = {.NoItemDefaultMoves = sParty_Andres5},
    },

    [TRAINER_CORY_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cory2),
        .party = {.NoItemDefaultMoves = sParty_Cory2},
    },

    [TRAINER_CORY_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cory3),
        .party = {.NoItemDefaultMoves = sParty_Cory3},
    },

    [TRAINER_CORY_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cory4),
        .party = {.NoItemDefaultMoves = sParty_Cory4},
    },

    [TRAINER_CORY_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Cory5),
        .party = {.NoItemDefaultMoves = sParty_Cory5},
    },

    [TRAINER_PABLO_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pablo2),
        .party = {.NoItemDefaultMoves = sParty_Pablo2},
    },

    [TRAINER_PABLO_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pablo3),
        .party = {.NoItemDefaultMoves = sParty_Pablo3},
    },

    [TRAINER_PABLO_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pablo4),
        .party = {.NoItemDefaultMoves = sParty_Pablo4},
    },

    [TRAINER_PABLO_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Pablo5),
        .party = {.NoItemDefaultMoves = sParty_Pablo5},
    },

    [TRAINER_KOJI_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Koji2),
        .party = {.NoItemDefaultMoves = sParty_Koji2},
    },

    [TRAINER_KOJI_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Koji3),
        .party = {.NoItemDefaultMoves = sParty_Koji3},
    },

    [TRAINER_KOJI_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Koji4),
        .party = {.NoItemDefaultMoves = sParty_Koji4},
    },

    [TRAINER_KOJI_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Koji5),
        .party = {.NoItemDefaultMoves = sParty_Koji5},
    },

    [TRAINER_CRISTIN_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cristin2),
        .party = {.NoItemDefaultMoves = sParty_Cristin2},
    },

    [TRAINER_CRISTIN_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cristin3),
        .party = {.NoItemDefaultMoves = sParty_Cristin3},
    },

    [TRAINER_CRISTIN_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cristin4),
        .party = {.NoItemDefaultMoves = sParty_Cristin4},
    },

    [TRAINER_CRISTIN_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_OFFICER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Cristin5),
        .party = {.NoItemDefaultMoves = sParty_Cristin5},
    },

    [TRAINER_FERNANDO_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Fernando2),
        .party = {.NoItemDefaultMoves = sParty_Fernando2},
    },

    [TRAINER_FERNANDO_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Fernando3),
        .party = {.NoItemDefaultMoves = sParty_Fernando3},
    },

    [TRAINER_FERNANDO_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Fernando4),
        .party = {.NoItemDefaultMoves = sParty_Fernando4},
    },

    [TRAINER_FERNANDO_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Fernando5),
        .party = {.NoItemDefaultMoves = sParty_Fernando5},
    },

    [TRAINER_SAWYER_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Sawyer2),
        .party = {.NoItemDefaultMoves = sParty_Sawyer2},
    },

    [TRAINER_SAWYER_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Sawyer3),
        .party = {.NoItemDefaultMoves = sParty_Sawyer3},
    },

    [TRAINER_SAWYER_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Sawyer4),
        .party = {.NoItemDefaultMoves = sParty_Sawyer4},
    },

    [TRAINER_SAWYER_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FISHERMAN,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Sawyer5),
        .party = {.NoItemDefaultMoves = sParty_Sawyer5},
    },

    [TRAINER_GABRIELLE_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle2),
        .party = {.NoItemDefaultMoves = sParty_Gabrielle2},
    },

    [TRAINER_GABRIELLE_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle3),
        .party = {.NoItemDefaultMoves = sParty_Gabrielle3},
    },

    [TRAINER_GABRIELLE_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle4),
        .party = {.NoItemDefaultMoves = sParty_Gabrielle4},
    },

    [TRAINER_GABRIELLE_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle5),
        .party = {.NoItemDefaultMoves = sParty_Gabrielle5},
    },

    [TRAINER_THALIA_2] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Thalia2),
        .party = {.NoItemDefaultMoves = sParty_Thalia2},
    },

    [TRAINER_THALIA_3] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Thalia3),
        .party = {.NoItemDefaultMoves = sParty_Thalia3},
    },

    [TRAINER_THALIA_4] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Thalia4),
        .party = {.NoItemDefaultMoves = sParty_Thalia4},
    },

    [TRAINER_THALIA_5] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_Thalia5),
        .party = {.NoItemDefaultMoves = sParty_Thalia5},
    },

    [TRAINER_MARIELA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MARIELA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Mariela),
        .party = {.NoItemDefaultMoves = sParty_Mariela},
    },

    [TRAINER_ALVARO] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SAGE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("ALVARO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Alvaro),
        .party = {.NoItemDefaultMoves = sParty_Alvaro},
    },

    [TRAINER_EVERETT] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("EVERETT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Everett),
        .party = {.NoItemDefaultMoves = sParty_Everett},
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
};
