#include "global.h"
#include "event_data.h"
#include "constants/region_map_sections.h"

struct Landmark
{
    const u8 *name;
    u16 flag;
};

struct LandmarkList
{
    u8 mapSection;
    u8 id;
    const struct Landmark *const *landmarks;
};

static const u8 LandmarkName_FlowerShop[] = _("FLOWER SHOP");
static const u8 LandmarkName_IlexForest[] = _("PETALBURG WOODS");
static const u8 LandmarkName_MrBrineysCottage[] = _("MR. BRINEY'S COTTAGE");
static const u8 LandmarkName_SproutTower[] = _("ABANDONED SHIP");
static const u8 LandmarkName_SeashoreHouse[] = _("SEASHORE HOUSE");
static const u8 LandmarkName_SlateportBeach[] = _("SLATEPORT BEACH");
static const u8 LandmarkName_CyclingRoad[] = _("CYCLING ROAD");
static const u8 LandmarkName_NewMauville[] = _("NEW MAUVILLE");
static const u8 LandmarkName_TrickHouse[] = _("TRICK HOUSE");
static const u8 LandmarkName_OldLadysRestShop[] = _("OLD LADY'S REST STOP");
static const u8 LandmarkName_Desert[] = _("DESERT");
static const u8 LandmarkName_WinstrateFamily[] = _("THE WINSTRATE FAMILY");
static const u8 LandmarkName_CableCar[] = _("CABLE CAR");
static const u8 LandmarkName_GlassWorkshop[] = _("GLASS WORKSHOP");
static const u8 LandmarkName_WeatherInstitute[] = _("WEATHER INSTITUTE");
static const u8 LandmarkName_MeteorFalls[] = _("METEOR FALLS");
static const u8 LandmarkName_TunnelersRestHouse[] = _("TUNNELER'S RESTHOUSE");
static const u8 LandmarkName_UnionCave[] = _("UNION CAVE");
static const u8 LandmarkName_PokemonDayCare[] = _("POKéMON DAY CARE");
static const u8 LandmarkName_SafariZoneEntrance[] = _("SAFARI ZONE ENTRANCE");
static const u8 LandmarkName_MtPyre[] = _("MT. PYRE");
static const u8 LandmarkName_ShoalCave[] = _("SHOAL CAVE");
static const u8 LandmarkName_SeafloorCavern[] = _("SEAFLOOR CAVERN");
static const u8 LandmarkName_DarkCave[] = _("GRANITE CAVE");
static const u8 LandmarkName_OceanCurrent[] = _("OCEAN CURRENT");
static const u8 LandmarkName_LanettesHouse[] = _("LANETTE'S HOUSE");
static const u8 LandmarkName_FieryPath[] = _("FIERY PATH");
static const u8 LandmarkName_JaggedPass[] = _("JAGGED PASS");
static const u8 LandmarkName_SkyPillar[] = _("SKY PILLAR");
static const u8 LandmarkName_BerryMastersHouse[] = _("BERRY MASTER'S HOUSE");
static const u8 LandmarkName_IslandCave[] = _("ISLAND CAVE");
static const u8 LandmarkName_DesertRuins[] = _("DESERT RUINS");
static const u8 LandmarkName_ScorchedSlab[] = _("SCORCHED SLAB");
static const u8 LandmarkName_AncientTomb[] = _("ANCIENT TOMB");
static const u8 LandmarkName_SealedChamber[] = _("SEALED CHAMBER");
static const u8 LandmarkName_FossilManiacsHouse[] = _("FOSSIL MANIAC'S HOUSE");
static const u8 LandmarkName_HuntersHouse[] = _("HUNTER'S HOUSE");
static const u8 LandmarkName_MagmaHideout[] = _("MAGMA HIDEOUT");
static const u8 LandmarkName_MirageTower[] = _("MIRAGE TOWER");
static const u8 LandmarkName_AlteringCave[] = _("ALTERING CAVE");
static const u8 LandmarkName_DesertUnderpass[] = _("DESERT UNDERPASS");
static const u8 LandmarkName_TrainerHill[] = _("TRAINER HILL");

static const struct Landmark Landmark_FlowerShop = {LandmarkName_FlowerShop, FLAG_LANDMARK_DARK_CAVE};
static const struct Landmark Landmark_IlexForest = {LandmarkName_IlexForest, -1};
static const struct Landmark Landmark_MrBrineysCottage = {LandmarkName_MrBrineysCottage, FLAG_LANDMARK_SPROUT_TOWER};
static const struct Landmark Landmark_SproutTower = {LandmarkName_SproutTower, FLAG_LANDMARK_ALPH_CHAMBERS};
static const struct Landmark Landmark_SeashoreHouse = {LandmarkName_SeashoreHouse, FLAG_LANDMARK_UNION_CAVE};
static const struct Landmark Landmark_SlateportBeach = {LandmarkName_SlateportBeach, -1};
static const struct Landmark Landmark_CyclingRoad = {LandmarkName_CyclingRoad, -1};
static const struct Landmark Landmark_NewMauville = {LandmarkName_NewMauville, FLAG_LANDMARK_ROUTE_32_POKEMON_CENTER};
static const struct Landmark Landmark_TrickHouse = {LandmarkName_TrickHouse, FLAG_LANDMARK_SLOWPOKE_WELL};
static const struct Landmark Landmark_OldLadysRestShop = {LandmarkName_OldLadysRestShop, FLAG_LANDMARK_ILEX_FOREST};
static const struct Landmark Landmark_Desert = {LandmarkName_Desert, -1};
static const struct Landmark Landmark_WinstrateFamily = {LandmarkName_WinstrateFamily, FLAG_LANDMARK_RADIO_TOWER};
static const struct Landmark Landmark_CableCar = {LandmarkName_CableCar, -1};
static const struct Landmark Landmark_GlassWorkshop = {LandmarkName_GlassWorkshop, FLAG_LANDMARK_NATIONAL_PARK};
static const struct Landmark Landmark_WeatherInstitute = {LandmarkName_WeatherInstitute, -1};
static const struct Landmark Landmark_MeteorFalls = {LandmarkName_MeteorFalls, -1};
static const struct Landmark Landmark_TunnelersRestHouse = {LandmarkName_TunnelersRestHouse, -1};
static const struct Landmark Landmark_UnionCave = {LandmarkName_UnionCave, -1};
static const struct Landmark Landmark_PokemonDayCare = {LandmarkName_PokemonDayCare, FLAG_LANDMARK_LIGHTHOUSE};
static const struct Landmark Landmark_SafariZoneEntrance = {LandmarkName_SafariZoneEntrance, -1};
static const struct Landmark Landmark_MtPyre = {LandmarkName_MtPyre, -1};
static const struct Landmark Landmark_ShoalCave = {LandmarkName_ShoalCave, -1};
static const struct Landmark Landmark_SeafloorCavern = {LandmarkName_SeafloorCavern, -1};
static const struct Landmark Landmark_DarkCave = {LandmarkName_DarkCave, -1};
static const struct Landmark Landmark_OceanCurrent = {LandmarkName_OceanCurrent, -1};
static const struct Landmark Landmark_LanettesHouse = {LandmarkName_LanettesHouse, -1};
static const struct Landmark Landmark_FieryPath = {LandmarkName_FieryPath, -1};
static const struct Landmark Landmark_JaggedPass = {LandmarkName_JaggedPass, -1};
static const struct Landmark Landmark_IslandCave = {LandmarkName_IslandCave, -1};
static const struct Landmark Landmark_DesertRuins = {LandmarkName_DesertRuins, -1};
static const struct Landmark Landmark_ScorchedSlab = {LandmarkName_ScorchedSlab, -1};
static const struct Landmark Landmark_AncientTomb = {LandmarkName_AncientTomb, -1};
static const struct Landmark Landmark_SealedChamber = {LandmarkName_SealedChamber, -1};
static const struct Landmark Landmark_FossilManiacsHouse = {LandmarkName_FossilManiacsHouse, -1};
static const struct Landmark Landmark_HuntersHouse = {LandmarkName_HuntersHouse, -1};
static const struct Landmark Landmark_SkyPillar = {LandmarkName_SkyPillar, -1};
static const struct Landmark Landmark_MirageTower = {LandmarkName_MirageTower, -1};
static const struct Landmark Landmark_AlteringCave = {LandmarkName_AlteringCave, -1};
static const struct Landmark Landmark_DesertUnderpass = {LandmarkName_DesertUnderpass, -1};
static const struct Landmark Landmark_TrainerHill = {LandmarkName_TrainerHill, -1};

static const struct Landmark *const Landmarks_Route31_2[]  =
{
    &Landmark_AlteringCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route32_0[]  =
{
    &Landmark_FlowerShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route32_1[]  =
{
    &Landmark_IlexForest,
    &Landmark_MrBrineysCottage,
    NULL,
};

static const struct Landmark *const Landmarks_Route33_0[]  =
{
    &Landmark_IslandCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route34_1[]  =
{
    &Landmark_DarkCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route36_0[]  =
{
    &Landmark_SproutTower,
    NULL,
};

static const struct Landmark *const Landmarks_Route109_0[]  =
{
    &Landmark_SeashoreHouse,
    &Landmark_SlateportBeach,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_0[]  =
{
    &Landmark_CyclingRoad,
    &Landmark_NewMauville,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_1[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_2[]  =
{
    &Landmark_CyclingRoad,
    &Landmark_TrickHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_0[]  =
{
    &Landmark_OldLadysRestShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_1[]  =
{
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_2[]  =
{
    &Landmark_MirageTower,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_3[]  =
{
    &Landmark_DesertRuins,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_4[]  =
{
    &Landmark_TrainerHill,
    &Landmark_WinstrateFamily,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_0[]  =
{
    &Landmark_FieryPath,
    &Landmark_JaggedPass,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_1[]  =
{
    &Landmark_CableCar,
    &Landmark_FieryPath,
    NULL,
};

static const struct Landmark *const Landmarks_Route113_1[]  =
{
    &Landmark_GlassWorkshop,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_1[]  =
{
    &Landmark_DesertUnderpass,
    &Landmark_FossilManiacsHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_2[]  =
{
    &Landmark_LanettesHouse,
    NULL,
};

static const struct Landmark *const Landmarks_MeteorFalls[]  =
{
    &Landmark_MeteorFalls,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_1[]  =
{
    &Landmark_TunnelersRestHouse,
    &Landmark_UnionCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_2[]  =
{
    &Landmark_UnionCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route45_2[]  =
{
    &Landmark_PokemonDayCare,
    NULL,
};

static const struct Landmark *const Landmarks_Route119_1[]  =
{
    &Landmark_WeatherInstitute,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_0[]  =
{
    &Landmark_ScorchedSlab,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_2[]  =
{
    &Landmark_AncientTomb,
    NULL,
};

static const struct Landmark *const Landmarks_Route121_2[]  =
{
    &Landmark_SafariZoneEntrance,
    NULL,
};

static const struct Landmark *const Landmarks_Route122_0[]  =
{
    &Landmark_MtPyre,
    NULL,
};

static const struct Landmark *const Landmarks_Route123_0[]  =
{
    NULL,
};

static const struct Landmark *const Landmarks_Route124_7[]  =
{
    &Landmark_HuntersHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route125_2[]  =
{
    &Landmark_ShoalCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route128_1[]  =
{
    &Landmark_SeafloorCavern,
    NULL,
};

static const struct Landmark *const Landmarks_Route131_1[]  =
{
    &Landmark_SkyPillar,
    NULL,
};

static const struct Landmark *const Landmarks_OceanCurrent[]  =
{
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_Route134_2[]  =
{
    &Landmark_SealedChamber,
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_SlowpokeWell_B1F_2[]  =
{
    &Landmark_CableCar,
    &Landmark_JaggedPass,
    NULL,
};

static const struct LandmarkList gLandmarkLists[] =
{
    {MAPSEC_ROUTE_31, 2, Landmarks_Route31_2},
    {MAPSEC_ROUTE_32, 0, Landmarks_Route32_0},
    {MAPSEC_ROUTE_32, 1, Landmarks_Route32_1},
    {MAPSEC_ROUTE_33, 0, Landmarks_Route33_0},
    {MAPSEC_ROUTE_34, 1, Landmarks_Route34_1},
    {MAPSEC_ROUTE_36, 0, Landmarks_Route36_0},
    {MAPSEC_ROUTE_37, 0, Landmarks_Route109_0},
    {MAPSEC_ROUTE_38, 0, Landmarks_Route110_0},
    {MAPSEC_ROUTE_38, 1, Landmarks_Route110_1},
    {MAPSEC_ROUTE_38, 2, Landmarks_Route110_2},
    {MAPSEC_ROUTE_39, 0, Landmarks_Route111_0},
    {MAPSEC_ROUTE_39, 1, Landmarks_Route111_1},
    {MAPSEC_ROUTE_39, 2, Landmarks_Route111_2},
    {MAPSEC_ROUTE_39, 3, Landmarks_Route111_3},
    {MAPSEC_ROUTE_39, 4, Landmarks_Route111_4},
    {MAPSEC_ROUTE_40, 0, Landmarks_Route112_0},
    {MAPSEC_ROUTE_40, 1, Landmarks_Route112_1},
    {MAPSEC_ROUTE_41, 1, Landmarks_Route113_1},
    {MAPSEC_ROUTE_42, 1, Landmarks_Route114_1},
    {MAPSEC_ROUTE_42, 2, Landmarks_Route114_2},
    {MAPSEC_ROUTE_42, 3, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_43, 0, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_43, 1, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_44, 1, Landmarks_Route116_1},
    {MAPSEC_ROUTE_44, 2, Landmarks_Route116_2},
    {MAPSEC_ROUTE_45, 2, Landmarks_Route45_2},
    {MAPSEC_ROUTE_26, 1, Landmarks_Route119_1},
    {MAPSEC_ROUTE_27, 0, Landmarks_Route120_0},
    {MAPSEC_ROUTE_27, 2, Landmarks_Route120_2},
    {MAPSEC_ROUTE_28, 2, Landmarks_Route121_2},
    {MAPSEC_ROUTE_32_FLYDUP, 0, Landmarks_Route122_0},
    {MAPSEC_ROUTE_123, 0, Landmarks_Route123_0},
    {MAPSEC_ROUTE_32_FLYDUP, 1, Landmarks_Route122_0},
    {MAPSEC_ROUTE_124, 7, Landmarks_Route124_7},
    {MAPSEC_ROUTE_125, 2, Landmarks_Route125_2},
    {MAPSEC_ROUTE_128, 1, Landmarks_Route128_1},
    {MAPSEC_ROUTE_131, 1, Landmarks_Route131_1},
    {MAPSEC_ROUTE_132, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_132, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 2, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 2, Landmarks_Route134_2},
    {MAPSEC_SLOWPOKE_WELL, 2, Landmarks_SlowpokeWell_B1F_2},
    {MAPSEC_NONE, 0, NULL},
};

static const struct Landmark *const *GetLandmarks(u8 mapSection, u8 id);

const u8 *GetLandmarkName(u8 mapSection, u8 id, u8 count)
{
    const struct Landmark *const *landmarks = GetLandmarks(mapSection, id);

    if (!landmarks)
        return NULL;

    while (1)
    {
        const struct Landmark *landmark = *landmarks;

        if (landmark->flag == 0xFFFF || FlagGet(landmark->flag) == TRUE)
        {
            if (count == 0)
                break;
            else
                count--;
        }

        landmarks++;
        if (!*landmarks)
            return NULL;
    }

    return (*landmarks)->name;
}

static const struct Landmark *const *GetLandmarks(u8 mapSection, u8 id)
{
    u16 i = 0;

    for (; gLandmarkLists[i].mapSection != MAPSEC_NONE; i++)
    {
        if (gLandmarkLists[i].mapSection > mapSection)
            return NULL;
        if (gLandmarkLists[i].mapSection == mapSection)
            break;
    }

    if (gLandmarkLists[i].mapSection == MAPSEC_NONE)
        return NULL;

    for (; gLandmarkLists[i].mapSection == mapSection; i++)
    {
        if (gLandmarkLists[i].id == id)
            return gLandmarkLists[i].landmarks;
    }

    return NULL;
}
