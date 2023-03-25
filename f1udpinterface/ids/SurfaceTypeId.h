#pragma once

#include <string>
#include <ostream>

namespace F122 {
    enum class SurfaceTypeId {
        // @formatter:off
        TARMAC       = 0,
        RUMBLE_STRIP = 1,
        CONCRETE     = 2,
        ROCK         = 3,
        GRAVEL       = 4,
        MUD          = 5,
        SAND         = 6,
        GRASS        = 7,
        WATER        = 8,
        COBBLESTONE  = 9,
        METAL        = 10,
        RIDGED       = 11,
        // @formatter:on
    };

    std::string to_string(SurfaceTypeId id);

    std::ostream& operator<<(std::ostream& os, const SurfaceTypeId& id);
}
