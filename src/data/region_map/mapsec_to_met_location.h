#ifndef GUARD_DATA_REGION_MAP_MAPSEC_TO_MET_LOCATION_H
#define GUARD_DATA_REGION_MAP_MAPSEC_TO_MET_LOCATION_H

#include "region_map.h"
#include "constants/region_map_sections.h"

#define METLOC_NEW_BARK_TOWN                0xD5  // METLOC_WHIRL_ISLAND with padding bit set
#define METLOC_CHERRYGROVE_CITY             0xD6  // METLOC_SILVER_CAVE with padding bit set
#define METLOC_VIOLET_CITY                  0xD7  // METLOC_TOHJO_FALLS with padding bit set
#define METLOC_AZALEA_TOWN                  0xD8  // METLOC_FAST_SHIP with padding bit set
#define METLOC_GOLDENROD_CITY               0xD9  // METLOC_LIGHTHOUSE with padding bit set
#define METLOC_ECRUTEAK_CITY                0xDA  // METLOC_ICE_PATH with padding bit set
#define METLOC_OLIVINE_CITY                 0xDB  // METLOC_DRAGONS_DEN with padding bit set
#define METLOC_CIANWOOD_CITY                0xDC  // METLOC_DARK_CAVE with padding bit set
#define METLOC_MAHOGANY_TOWN                0xDD  // METLOC_RADIO_TOWER with padding bit set
#define METLOC_BLACKTHORN_CITY              0xDE  // METLOC_MT_MORTAR with padding bit set
#define METLOC_ROUTE_26                     0xDF  // METLOC_LAKE_OF_RAGE with padding bit set
#define METLOC_ROUTE_27                     0xE0  // METLOC_LAVENDER_RADIO_TOWER with padding bit set
#define METLOC_ROUTE_28                     0xE1
#define METLOC_ROUTE_29                     0xE2
#define METLOC_ROUTE_30                     0xE3
#define METLOC_ROUTE_31                     0xE4
#define METLOC_ROUTE_32                     0xE5
#define METLOC_ROUTE_33                     0xE6
#define METLOC_ROUTE_34                     0xE7
#define METLOC_ROUTE_35                     0xE8
#define METLOC_ROUTE_36                     0xE9
#define METLOC_ROUTE_37                     0xEA
#define METLOC_ROUTE_38                     0xEB
#define METLOC_ROUTE_39                     0xEC
#define METLOC_ROUTE_40                     0xED
#define METLOC_ROUTE_41                     0xEE
#define METLOC_ROUTE_42                     0xEF
#define METLOC_ROUTE_43                     0xF0
#define METLOC_ROUTE_44                     0xF1
#define METLOC_ROUTE_45                     0xF2
#define METLOC_ROUTE_46                     0xF3
#define METLOC_SPROUT_TOWER                 0xF4
#define METLOC_RUINS_OF_ALPH                0xF5
#define METLOC_UNION_CAVE                   0xF6
#define METLOC_SLOWPOKE_WELL                0xF7
#define METLOC_ILEX_FOREST                  0xF8
#define METLOC_NATIONAL_PARK                0xF9
#define METLOC_TIN_TOWER                    0xFA
#define METLOC_BURNED_TOWER                 0xFB
// These are only to grab the names in gRegionMapNames_Johto
#define METLOC_WHIRL_ISLAND                 0xFC
#define METLOC_SILVER_CAVE                  0xFD
#define METLOC_TOHJO_FALLS                  0xFE
#define METLOC_FAST_SHIP                    0xFF
#define METLOC_LIGHTHOUSE                   0x100
#define METLOC_ICE_PATH                     0x101
#define METLOC_DRAGONS_DEN                  0x102
#define METLOC_DARK_CAVE                    0x103
#define METLOC_RADIO_TOWER                  0x104
#define METLOC_MT_MORTAR                    0x105
#define METLOC_LAKE_OF_RAGE                 0x106
#define METLOC_LAVENDER_RADIO_TOWER         0x107

#define METLOC_START METLOC_NEW_BARK_TOWN

// Whatever MAPSEC is not in this list returns 0.

static const u8 sMapSecToMetLoc[] = {
    [MAPSEC_NEW_BARK_TOWN]             = METLOC_NEW_BARK_TOWN,
    [MAPSEC_CHERRYGROVE_CITY]          = METLOC_CHERRYGROVE_CITY,
    [MAPSEC_AZALEA_TOWN]               = METLOC_AZALEA_TOWN,
    [MAPSEC_CIANWOOD_CITY]             = METLOC_CIANWOOD_CITY,
    [MAPSEC_MAHOGANY_TOWN]             = METLOC_MAHOGANY_TOWN,
    [MAPSEC_VIOLET_CITY]               = METLOC_VIOLET_CITY,
    [MAPSEC_ECRUTEAK_CITY]             = METLOC_ECRUTEAK_CITY,
    [MAPSEC_OLIVINE_CITY]              = METLOC_OLIVINE_CITY,
    [MAPSEC_GOLDENROD_CITY]            = METLOC_GOLDENROD_CITY,
    [MAPSEC_BLACKTHORN_CITY]           = METLOC_BLACKTHORN_CITY,
    [MAPSEC_BURNED_TOWER]              = METLOC_BURNED_TOWER,
    [MAPSEC_TOHJO_FALLS]               = METLOC_VIOLET_CITY,      
    [MAPSEC_FAST_SHIP]                 = METLOC_AZALEA_TOWN,      
    [MAPSEC_ROUTE_29]                  = METLOC_ROUTE_29,
    [MAPSEC_ROUTE_30]                  = METLOC_ROUTE_30,
    [MAPSEC_ROUTE_31]                  = METLOC_ROUTE_31,
    [MAPSEC_ROUTE_32]                  = METLOC_ROUTE_32,
    [MAPSEC_ROUTE_33]                  = METLOC_ROUTE_33,
    [MAPSEC_ROUTE_34]                  = METLOC_ROUTE_34,
    [MAPSEC_ROUTE_35]                  = METLOC_ROUTE_35,
    [MAPSEC_ROUTE_36]                  = METLOC_ROUTE_36,
    [MAPSEC_ROUTE_37]                  = METLOC_ROUTE_37,
    [MAPSEC_ROUTE_38]                  = METLOC_ROUTE_38,
    [MAPSEC_ROUTE_39]                  = METLOC_ROUTE_39,
    [MAPSEC_ROUTE_40]                  = METLOC_ROUTE_40,
    [MAPSEC_ROUTE_41]                  = METLOC_ROUTE_41,
    [MAPSEC_ROUTE_42]                  = METLOC_ROUTE_42,
    [MAPSEC_ROUTE_43]                  = METLOC_ROUTE_43,
    [MAPSEC_ROUTE_44]                  = METLOC_ROUTE_44,
    [MAPSEC_ROUTE_45]                  = METLOC_ROUTE_45,
    [MAPSEC_ROUTE_46]                  = METLOC_ROUTE_46,
    [MAPSEC_ROUTE_26]                  = METLOC_ROUTE_26,
    [MAPSEC_ROUTE_27]                  = METLOC_ROUTE_27,
    [MAPSEC_ROUTE_28]                  = METLOC_ROUTE_28,
    [MAPSEC_ROUTE_32_FLYDUP]           = METLOC_ROUTE_32,
    [MAPSEC_DARK_CAVE]                 = METLOC_CIANWOOD_CITY,    
    [MAPSEC_SLOWPOKE_WELL]             = METLOC_SLOWPOKE_WELL,
    [MAPSEC_ILEX_FOREST]               = METLOC_ILEX_FOREST,
    [MAPSEC_UNION_CAVE]                = METLOC_UNION_CAVE,
    [MAPSEC_SPROUT_TOWER]              = METLOC_SPROUT_TOWER,
    [MAPSEC_RUINS_OF_ALPH]             = METLOC_RUINS_OF_ALPH,
    [MAPSEC_RADIO_TOWER]               = METLOC_MAHOGANY_TOWN,    
    [MAPSEC_ALPH_CHAMBERS]             = METLOC_RUINS_OF_ALPH,
    [MAPSEC_MT_MORTAR]                 = METLOC_BLACKTHORN_CITY,  
    [MAPSEC_LIGHTHOUSE]                = METLOC_GOLDENROD_CITY,   
    [MAPSEC_DRAGONS_DEN]               = METLOC_OLIVINE_CITY,     
    [MAPSEC_LAKE_OF_RAGE]              = METLOC_ROUTE_26,         
    [MAPSEC_NATIONAL_PARK]             = METLOC_NATIONAL_PARK,
    [MAPSEC_ICE_PATH]                  = METLOC_ECRUTEAK_CITY,    
    [MAPSEC_SILVER_CAVE]               = METLOC_CHERRYGROVE_CITY, 
    [MAPSEC_WHIRL_ISLANDS]             = METLOC_NEW_BARK_TOWN,    
    [MAPSEC_TIN_TOWER]                 = METLOC_TIN_TOWER,
    [MAPSEC_LAVENDER_RADIO_TOWER]      = METLOC_ROUTE_27
};

#endif //GUARD_DATA_REGION_MAP_MAPSEC_TO_MET_LOCATION_H
