#pragma once

#include <string>

namespace F122 {
    enum class SurfaceTypeId {
        TARMAC = 0,
        RUMBLE_STRIP = 1,
        CONCRETE = 2,
        ROCK = 3,
        GRAVEL = 4,
        MUD = 5,
        SAND = 6,
        GRASS = 7,
        WATER = 8,
        COBBLESTONE = 9,
        METAL = 10,
        RIDGED = 11,
    };

    std::string to_string(SurfaceTypeId id);
}
