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

    std::string to_string(SurfaceTypeId id) {
        switch (id) {
            case SurfaceTypeId::TARMAC:
                return "Tarmac";
            case SurfaceTypeId::RUMBLE_STRIP:
                return "Rumble strip";
            case SurfaceTypeId::CONCRETE:
                return "Concrete";
            case SurfaceTypeId::ROCK:
                return "Rock";
            case SurfaceTypeId::GRAVEL:
                return "Gravel";
            case SurfaceTypeId::MUD:
                return "Mud";
            case SurfaceTypeId::SAND:
                return "Sand";
            case SurfaceTypeId::GRASS:
                return "Grass";
            case SurfaceTypeId::WATER:
                return "Water";
            case SurfaceTypeId::COBBLESTONE:
                return "Cobblestone";
            case SurfaceTypeId::METAL:
                return "Metal";
            case SurfaceTypeId::RIDGED:
                return "Ridged";
        }
    }
}
