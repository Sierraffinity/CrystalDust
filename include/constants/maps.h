#ifndef GUARD_CONSTANTS_MAPS_H
#define GUARD_CONSTANTS_MAPS_H

#include "map_groups.h"

#define MAP_NONE (0x7F | (0x7F << 8))
#define MAP_UNDEFINED (0xFF | (0xFF << 8))

#define MAP_GROUP(map) (MAP_##map >> 8)
#define MAP_NUM(map) (MAP_##map & 0xFF)

// These groups are used by pokedex_area_screen.c to find wild
// pokemon locations.
#define MAP_GROUP_OVERWORLD_MONS MAP_GROUP(VIOLET_CITY)
#define MAP_GROUP_SPECIAL_MONS_1 MAP_GROUP(UNION_CAVE_1F)
#define MAP_GROUP_SPECIAL_MONS_2 MAP_GROUP(BATTLE_FRONTIER_OUTSIDE_EAST)

#endif  // GUARD_CONSTANTS_MAPS_H
